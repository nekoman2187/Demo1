/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_socket_rx_if.h
* Version      : 1.31
* Description  : Functions for using sockets for M3S-T4-Tiny with callback functions.
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*         : 17.09.2012 1.00    First Release (With RSKRX62N support)
*         : 31.01.2015 1.20    Support 2nd Ether channel.
*         : 31.01.2015 1.30    Support select() function.
*         : 01.10.2016 1.31    Deleted USE_BSD_NON_BLOCKING macro. 
*         :                    Added SOCKET_TCP_WINSIZE macro.
*         :                    Changed R_SOCKET_Init() API name to R_SOCKET_Open().
*         :                    Added R_SOCKET_Close().
*         :                    Omitted Ether-2 channels support.
***********************************************************************************************************************/

#ifndef R_SOCKET_RX_IF_H
#define R_SOCKET_RX_IF_H

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* for size_t */
#include <stddef.h>
#include "r_t4_itcpip.h"
#include "r_socket_rx_config.h"

#include "platform.h"
#include "r_t4_rx_config.h"

#include "r_errno_sock.h"


/***********************************************************************************************************************
Macro definitions
******************************************************************************/

#define SOMAXCONN               20  /* maximum socket connection,  default 20*/
#define INVALID_TCP_PORT        (0L)
#define IP_ADDR_ANY             0

/* Socket Protocol Types (TCP/UDP/RAW) - Standard */
#define SOCK_STREAM     1  /* stream socket */
#define SOCK_DGRAM      2  /* datagram socket */
#define SOCK_RAW        3  /* raw-protocol interface */
#define SOCK_RDM        4  /* reliably-delivered message */
#define SOCK_SEQPACKET  5  /* sequenced packet stream */

/* Level number for (get/set)sockopt() to apply to socket itself.*/
#define SOL_SOCKET 0xffff  /* options for socket level */

/* Address families.  - Standard */
#define AF_UNSPEC          0        /* unspecified */
#define AF_LOCAL           1        /* local to host (pipes, portals) */
#define AF_UNIX            AF_LOCAL /* backward compatibility */
#define AF_INET            2        /* internetwork: UDP, TCP, etc. */
#define AF_IMPLINK         3        /* arpanet imp addresses */
#define AF_PUP             4        /* pup protocols: e.g. BSP */
#define AF_CHAOS           5        /* mit CHAOS protocols */
#define AF_NS              6        /* XEROX NS protocols */
#define AF_ISO             7        /* ISO protocols */
#define AF_OSI             AF_ISO
#define AF_ECMA            8        /* European computer manufacturers */
#define AF_DATAKIT         9        /* datakit protocols */
#define AF_CCITT           10       /* CCITT protocols, X.25 etc */
#define AF_SNA             11       /* IBM SNA */
#define AF_DECnet          12       /* DECnet */
#define AF_DLI             13       /* DEC Direct data link interface */
#define AF_LAT             14       /* LAT */
#define AF_HYLINK          15       /* NSC Hyperchannel */
#define AF_APPLETALK       16       /* Apple Talk */
#define AF_ROUTE           17       /* Internal Routing Protocol */
#define AF_LINK            18       /* Link layer interface */
#define pseudo_AF_XTP      19       /* eXpress Transfer Protocol (no AF) */
#define AF_COIP            20       /* connection-oriented IP, aka ST II */
#define AF_CNT             21       /* Computer Network Technology */
#define pseudo_AF_RTIP     22       /* Help Identify RTIP packets */
#define AF_IPX             23       /* Novell Internet Protocol */
#define AF_SIP             24       /* Simple Internet Protocol */
#define pseudo_AF_PIP      25       /* Help Identify PIP packets */
#define AF_ISDN            26       /* Integrated Services Digital Network*/
#define AF_E164            AF_ISDN  /* CCITT E.164 recommendation */
#define pseudo_AF_KEY      27       /* Internal key-management function */
#define AF_INET6           28       /* IPv6 */
#define AF_NATM            29       /* native ATM access */
#define AF_ATM             30       /* ATM */
#define pseudo_AF_HDRCMPLT 31 /* Used by BPF to not rewrite headers in interface output routine */

#define AF_NET2     (AF_INET+32)/* To indicate next channel */

#define PF_INET         AF_INET
#define PF_UNSPEC       AF_UNSPEC

#define MSG_PEEK        0x2    /* peek at incoming message */
#define MSG_DONTROUTE   0x4    /* send without using routing tables */
#define MSG_EOR         0x8    /* data completes record */
#define MSG_TRUNC       0x10   /* data discarded before delivery */
#define MSG_CTRUNC      0x20   /* control data lost before delivery */
#define MSG_WAITALL     0x40   /* wait for full request or error */
#define MSG_DONTWAIT    0x80   /* this message should be nonblocking */
#define MSG_EOF         0x100  /* data completes connection */
#define MSG_COMPAT      0x8000 /* used in sendit() */

/* options for socket level */
#define SOL_SOCKET      0xffff

/*Additional options, not kept in so_options.*/
#define SO_SNDBUF    0x1001     /* Unimplemented: send buffer size */
#define SO_RCVBUF    0x1002     /* receive buffer size */
#define SO_SNDLOWAT  0x1003     /* Unimplemented: send low-water mark */
#define SO_RCVLOWAT  0x1004     /* Unimplemented: receive low-water mark */
#define SO_SNDTIMEO  0x1005     /* Unimplemented: send timeout */
#define SO_RCVTIMEO  0x1006     /* receive timeout */
#define SO_ERROR     0x1007     /* get error status and clear */
#define SO_TYPE      0x1008     /* get socket type */
#define SO_CONTIMEO  0x1009     /* Unimplemented: connect timeout */
#define SO_NO_CHECK  0x100a     /* don't create UDP checksum */

#define AF_INET          2   /* Internet Address Family - UDP, TCP, etc. */
#define IPPROTO_TCP      6   /* tcp */
#define IPPROTO_UDP      17  /* user datagram protocol */

#define IP_ADDR_ANY        0
#define IP_ADDR_BROADCAST  0xffffffffu

#define INADDR_ANY              0x00000000
#define INADDR_LOOPBACK         0x7f000001
#define INADDR_BROADCAST        0xffffffff
#define INADDR_NONE             0xffffffff
#define ADDR_ANY                INADDR_ANY

#define INVALID_SOCK            (-1)
#define INVALID_SOCKET          (-1)
#define SOCKET_ERROR            (-1)
#define SOCKET_BFR_ALLOC_ERROR  (-2)
#define SOCKET_HOST_NO_ROUTE    (-3)
#define SOCKET_MAX_LEN_ERROR    (-4)
#define SOCKET_NOT_READY        (-5)
#define SOCKET_TX_NOT_READY     (-5)
#define SOCKET_CNXN_IN_PROGRESS (-6)

/* commands for fnctl */
#define F_GETFL 3
#define F_SETFL 4

/* File status flags and file access modes for fnctl,these are bits in an int. */
#define O_NONBLOCK  1 /* nonblocking I/O */
#define O_BLOCK     2 /* blocking I/O */
#define O_RDONLY    0
#define O_WRONLY    1

#ifndef socklen_t
#define socklen_t int
#endif


enum
{
    SHUT_RD = 0,          /* No more receptions.  */
//#define SHUT_RD         SHUT_RD
    SHUT_WR,              /* No more transmissions.  */
//#define SHUT_WR         SHUT_WR
    SHUT_RDWR             /* No more receptions or transmissions.  */
#define SHUT_RDWR       SHUT_RDWR
};

/*Error Code */
#ifndef E_OK
#define E_OK            0x0000
#endif
#ifndef E_OBJ
#define E_OBJ          -0x003f
#endif
#ifndef E_QOVR
#define E_QOVR         -0x0049
#endif
#ifndef E_TMOUT
#define E_TMOUT        -0x0055
#endif
#ifndef E_RLWAI
#define E_RLWAI        -0x0056
#endif
#ifndef E_NOMEM
#define E_NOMEM        -0x000a
#endif

/* whence values for lseek(2) */
#ifndef SEEK_SET
#define SEEK_SET 0 /* set file offset to offset */
#define SEEK_CUR 1 /* set file offset to current plus offset */
#define SEEK_END 2 /* set file offset to EOF plus offset */
#endif

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef int SOCKET;

#if !defined(__ITRON_DATA_TYPE)
# if defined(__R8C__)  || defined(__H8__)\
  ||  defined(__M16C__) || defined(__M16C80__) || defined(__M32C80__)\
  || defined(__SH2__) || defined(__SH2A__) || defined(__SH4__) || defined(__RX600__)

#if defined(__RX600__)
#include <stdint.h>
#else
typedef signed char    int8_t;
typedef signed short   int16_t;
typedef signed long    int32_t;
typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long  uint32_t;
#endif

typedef int8_t       B;
typedef int16_t      H;
typedef int32_t      W;
typedef uint8_t      UB;
typedef uint16_t     UH;
typedef uint32_t     UW;
typedef int8_t       VB;
typedef int16_t      VH;
typedef int32_t      VW;
typedef void _far *  VP;
typedef void         (*FP)();
typedef H            ID;
typedef H            PRI;
typedef H            TMO;
typedef H            HNO;
typedef W            ER;
typedef UH           ATR;
#else
typedef W            FN;
#endif
#endif

/* Data types. */
enum _SOCKET_EVENT
{
    SOCKET_CRE_REP,   /* Create TCP reception point      */
    SOCKET_DEL_REP,   /* Delete TCP reception point      */
    SOCKET_CRE_CEP,   /* Create TCP/UDP communication end point   */
    SOCKET_DEL_CEP,   /* Delete TCP/UDP communication end point   */
    SOCKET_ACP_CEP,   /* Wait for TCP connection request     */
    SOCKET_CON_CEP,   /* TCP connection request(active open)    */
    SOCKET_SHT_CEP,   /* TCP data transmission end      */
    SOCKET_CLS_CEP,   /* TCP communication end point close    */
    SOCKET_SND_DAT,   /* Transmission of TCP/UDP data      */
    SOCKET_RCV_DAT,   /* Reception of TCP/UDP data      */
    SOCKET_GET_BUF,   /* TCP Transmission buffer retrieval    */
    SOCKET_SND_BUF,   /* Transmission of data in TCP buffer    */
    SOCKET_RCV_BUF,   /* Get TCP reception data in the buffer    */
    SOCKET_REL_BUF,   /* TCP Reception buffer release      */
    SOCKET_SND_OOB,   /* Transmission of urgent TCP data     */
    SOCKET_RCV_OOB,   /* Reception of urgent TCP data      */
    SOCKET_CAN_CEP,   /* Cancel pending TCP/UDP operation     */
    SOCKET_SET_OPT,   /* Set TCP/UDP communication end point option  */
    SOCKET_GET_OPT,   /* Read TCP/UDP communication end point option  */
    SOCKET_ERR_CEP,   /* Socket Error          */
    SOCKET_ALL,
};

typedef enum _tag_SOCK_ERR
{
    ERR_NONE,       /* No error */
    ERR_RLWAI_ACP,  /* Indicate that accept() has just been canceled */
    ERR_RLWAI_CON,  /* Indicate that connect() has just been canceled */
    ERR_RLWAI_SHT,  /* Indicate that shutdown() has just been canceled*/
    ERR_RLWAI_CLS,  /* Indicate that closesocket () has just been canceled */
    ERR_RLWAI_SND,  /* Indicate that send()/sendto has just been canceled */
    ERR_RLWAI_RCV,  /* Indicate that recv()/recvfrom() has just been canceled */
    ERR_RLWAI_RCV_TEV,  /* Indicate that recvfrom() has just been canceled */
    ERR_OTHERS,     /* Other errors */
    ERR_CLEAR,      /* Clear the existing error */

} SOCK_ERR;

struct in_addr
{
    union
    {
        struct
        {
            unsigned char s_b1, s_b2, s_b3, s_b4;
        } S_un_b;
        struct
        {
            unsigned short s_w1, s_w2;
        } S_un_w;
        unsigned long S_addr;
    } S_un;

#define s_addr  S_un.S_addr        /* can be used for most tcp & ip code */
#define s_host  S_un.S_un_b.s_b2   /* host on imp */
#define s_net   S_un.S_un_b.s_b1   /* network */
#define s_imp   S_un.S_un_w.s_w2   /* imp */
#define s_impno S_un.S_un_b.s_b4   /* imp # */
#define s_lh    S_un.S_un_b.s_b3   /* logical host */
};

struct sockaddr
{
    unsigned short  sa_family;              /* address family */
    char    sa_data[14];                    /* up to 14 bytes of direct address */
};

struct sockaddr_in
{
    short sin_family;
    unsigned short sin_port;
    struct  in_addr sin_addr;
    char    sin_zero[8];
};
#if BSP_CFG_RTOS_USED == 6
struct addrinfo {
	int	ai_flags;	/* AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST */
	int	ai_family;	/* PF_xxx */
	int	ai_socktype;	/* SOCK_xxx */
	int	ai_protocol;	/* 0 or IPPROTO_xxx for IPv4 and IPv6 */
	size_t	ai_addrlen;	/* length of ai_addr */
	char	*ai_canonname;	/* canonical name for hostname */
	struct	sockaddr *ai_addr;	/* binary address */
	struct	addrinfo *ai_next;	/* next structure in linked list */
};
#endif
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr_in *PSOCKADDR_IN;
typedef struct sockaddr_in *LPSOCKADDR_IN;

typedef struct sockaddr SOCKADDR;
typedef struct sockaddr *PSOCKADDR;
typedef struct sockaddr *LPSOCKADDR;


#define T4_CLOSED      0  /* T4 status */
#define T4_ACCEPT      1
#define T4_ESTABLISHED 2
#define T4_CLOSE_WAIT  3
#define T4_LAST_ACK    4
#define T4_FIN_WAIT1   5
#define T4_TIME_WAIT   6
#define T4_ERROR_CLOSE 7



#define T4_PROC_CLS_END         0x2000
#define T4_PROC_CLS_START       0x1000
#define T4_PROC_CAN_END         0x0800
#define T4_PROC_CAN_START       0x0400
#define T4_PROC_SND_END         0x0080
#define T4_PROC_SND_START       0x0040
#define T4_PROC_RCV_END         0x0020
#define T4_PROC_RCV_START       0x0010
#define T4_PROC_CON             0x0004
#define T4_PROC_ACP             0x0001

#define SOCKET_PROC_CLS_END     0x8000
#define SOCKET_PROC_CLS_START   0x4000
#define SOCKET_PROC_SND         0x0200
#define SOCKET_PROC_RCV         0x0100

/* MACRO should be place before Typedef */

typedef enum _tag_BSD_STATE
{
    BSD_CLOSED,     // 0 Inactive socket
    BSD_CREATED,    // 1 Comm resources allocated
    BSD_BOUND,      // 2 Comm bound to IP / port
    BSD_LISTENING,  // 3 Server is listening
    BSD_CONNECTING, // 4 Client is seeking connection
    BSD_CLOSING,    // 5 Either side intiate a tear-down
    // While closing, you shouldnt do anything to it. guard against
    //  check < BSD_BOUND, dont do something.
    BSD_CONNECTED,  // 6 Both end up being connected
    BSD_FATALERROR = -1,  // -1 Fatal Error
} BSD_STATE;

typedef struct _tag_BSDSocket
{
    BSD_STATE   state;       /* BSD socket states */
    uint32_t    T4status;    /* T4 current status */
    int         event;       /* T4 event occuring in callback */
    ID          socket_type; /* SOCK_STREAM or SOCK_DGRAM */
    ID          backlog;     /* No Used */
    T_IPV4EP    dstaddr;     /* Partners Address */
    TMO         tmout;       /* Time out */
    uint32_t    create_id;          /* Socket Create ID */
    UB          rcv_buf[BSD_RCV_BUFSZ];
    uint32_t    rcvLen;      /* received until [0..rcvLen-1,...BSD_RCV_BUFSZ-1] */
    uint32_t    rcvin_offset;      /* received until [0..rcvLen-1,...BSD_RCV_BUFSZ-1] */
    uint32_t    rcvout_offset;
    uint32_t    rcvcnt;
    UB          snd_buf[BSD_SND_BUFSZ];
    uint32_t    sndLen;      /* send upto here [0..sndLen-1, ...sndSz-1] */
    uint32_t    sndSz;       /* size of data to sent */
    SOCK_ERR    err_type;    /* Determine the type of socket's error */
    int         peer_socket; /* child socket allocated while listening */
    int         socket_proc;
    uint32_t    pending_rcvlen;
    uint32_t    pending_sndlen;
    uint32_t    T4proc;      /* T4 current status */
    volatile uint8_t    finrcv;
} BSDSocket;

#if BSP_CFG_RTOS_USED != 6
#define FD_SETSIZE  32UL
#endif
#ifndef _BITS_BYTE
#define _BITS_BYTE  8UL
#endif
#if BSP_CFG_RTOS_USED != 6
typedef int32_t __fd_mask;
#define __NFDBITS ((unsigned)(sizeof(__fd_mask) * _BITS_BYTE)) /* bits per mask */
#endif
#define __NFDBITS   32UL
#define __howmany(x, y) (((x) + ((y) - 1)) / (y))
#if BSP_CFG_RTOS_USED != 6
typedef struct _tagfd_set
{
    __fd_mask fds_bits[__howmany(FD_SETSIZE, __NFDBITS)];
} fd_set;

#define FD_SET(n, p) \
    ((p)->fds_bits[(unsigned)(n) / __NFDBITS] |= (1 << ((unsigned)(n) % __NFDBITS)))
#define FD_CLR(n, p) \
    ((p)->fds_bits[(unsigned)(n) / __NFDBITS] &= ~(1UL << ((unsigned)(n) % __NFDBITS)))
#define FD_ISSET(n, p) \
    ((p)->fds_bits[(unsigned)(n) / __NFDBITS] & (1 << ((unsigned)(n) % __NFDBITS)))
#define FD_COPY(f, t)   memcpy(t, f, sizeof(*(f)))
#define FD_ZERO(p)      memset(p, 0, sizeof(*(p)))
#endif
#if FD_SETSIZE  <= 32
#define FD_ISZERO(p)    \
    ((p)->fds_bits[0] == 0)
#elif FD_SETSIZE <= (32*2)
#define FD_ISZERO(p)    \
    (((p)->fds_bits[0] == 0) && ((p)->fds_bits[1] == 0))
#elif FD_SETSIZE <= (32*3)
#define FD_ISZERO(p)    \
    (((p)->fds_bits[0] == 0) && ((p)->fds_bits[1] == 0) && \
     ((p)->fds_bits[2] == 0))
#else
#define FD_ISZERO(p)    \
    (((p)->fds_bits[0] == 0) && ((p)->fds_bits[1] == 0) && \
     (((p)->fds_bits[2] == 0) && ((p)->fds_bits[3] == 0))
#endif      /* FD_SETSIZE */

#define T4_TCP_CLS_CEP_TMOUT (10)
#if BSP_CFG_RTOS_USED != 6
struct timeval wata
{
    long tv_sec;
    long tv_usec;
};
#endif
/******************************************************************************
Public Functions
******************************************************************************/
void R_SOCKET_Open( void );
void R_SOCKET_Close( void );

int  socket( int domain, int type, int protocol );
int  bind( int sock, const struct sockaddr * name, int namelen );
int  listen( int sock, int backlog );
int  connect( int sock, struct sockaddr * name, int namelen );
int  accept( int sock, struct sockaddr * address, int * address_len );
int  sendto( int sock,  const void * buffer, size_t length, int flags,
             const struct sockaddr * to, int tolen );
int  send( int sock,  const char * buffer, size_t length, int flags );
int  recvfrom( int sock, void * buffer, size_t length, int flags,
               struct sockaddr * from, int * fromlen );
int  recv( int sock, void * buffer, size_t length, int flags );
int  getpeername(int sock, struct sockaddr *address, int *address_len);
int  setsockopt( int sock, int level, int option_name, const void * optval,
                 int option_len );
int  closesocket( int sock );
int  fcntl ( int sock, int command, int flags );
int  select ( int nfds, fd_set *p_readfds, fd_set *p_writefds, fd_set *p_errorfds,
              struct timeval *timeout );

void r_socket_task_switch(int sock);
void r_socket_task_switch_select(void);
int r_socket_sem_lock(void);
int r_socket_sem_release(void);



uint16_t htons(uint16_t n);
uint16_t ntohs(uint16_t n);
uint32_t htonl(uint32_t n);
uint32_t ntohl(uint32_t n);

#endif /* R_SOCKET_IF_H */
