/* wolf_server.c
 *
 * Copyright (C) 2006-2020 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */
#include <stdio.h>
#include <string.h>
#include <wolfssl/ssl.h>
#include <wolfssl/wolfcrypt/settings.h>

#include "r_t4_itcpip.h"
#include "r_ether_rx_if.h"
#include "r_sys_time_rx_if.h"
#include "dhcp_client.h"
#include "r_t4_rx_config.h"

#include "wolfssl/certs_test.h"
#include "wolf_demo.h"

static int my_IORecv(WOLFSSL* ssl, char* buff, int sz, void* ctx)
{
    int ret;
    ID  cepid;
printf("my_IORecv\n");
    if(ctx != NULL)cepid = *(ID *)ctx;
    else return WOLFSSL_CBIO_ERR_GENERAL;

    ret = tcp_rcv_dat(cepid, buff, sz, TMO_FEVR);
    if(ret == sz)return ret;
    else         return WOLFSSL_CBIO_ERR_GENERAL;
}

static int my_IOSend(WOLFSSL* ssl, char* buff, int sz, void* ctx)
{
    int ret;
    ID  cepid;
    printf("my_IOSend sz %d\n",sz);

    if(ctx != NULL) {
        printf("my_IOSend cepid OK \n");

    	cepid = *(ID *)ctx;
    }
    else return WOLFSSL_CBIO_ERR_GENERAL;
if(sz >= 1200) {
	ret = 0;
}
	ret = tcp_snd_dat(cepid, buff, sz, TMO_FEVR);

    if(ret == sz) {
        printf("my_IOSend OK \n");

    	return ret;
    }
    else    {
        printf("my_IOSend NG \n");

    	return WOLFSSL_CBIO_ERR_GENERAL;
    }
}


WOLFSSL_CTX *wolfSSL_TLS_server_init()
{

	int ret;
    WOLFSSL_CTX* ctx;

    #ifndef NO_FILESYSTEM
        #ifdef USE_ECC_CERT
        char *cert       = "./certs/server-ecc-cert.pem";
        char *key        = "./certs/server-ecc-key.pem";
        #else
        char *cert       = "./certs/server-cert.pem";
        char *key        = "./certs/server-key.pem";
        #endif
    #else
        #ifdef USE_ECC_CERT
        char *cert       = serv_ecc_der_256;
        int  sizeof_cert = sizeof_serv_ecc_der_256;
        char *cert       = serv_ecc_key_der_256;
        int  sizeof_key  = sizeof_serv_ecc_key_der_256;
        #else
        const unsigned char *cert       = server_cert_der_2048;
        #define sizeof_cert sizeof_server_cert_der_2048
        const unsigned char *key        = server_key_der_2048;
        #define  sizeof_key sizeof_server_key_der_2048
        #endif
    #endif


    #ifdef DEBUG_WOLFSSL
	    wolfSSL_Debugging_ON();
	#endif

	/* Create and initialize WOLFSSL_CTX */
	if ((ctx = wolfSSL_CTX_new(wolfSSLv23_server_method_ex((void *)NULL))) == NULL) {
		printf("ERROR: failed to create WOLFSSL_CTX\n");
		return NULL;
	}

    #if !defined(NO_FILESYSTEM)
        ret = wolfSSL_CTX_use_certificate_file(ctx, cert, 0);
    #else
        ret = wolfSSL_CTX_use_certificate_buffer(ctx, cert, sizeof_cert, SSL_FILETYPE_ASN1);
    #endif
        if (ret != SSL_SUCCESS) {
            printf("Error %d loading server-cert!\n", ret);
	    return NULL;

        }

        /* Load server key into WOLFSSL_CTX */
    #if !defined(NO_FILESYSTEM)
        ret = wolfSSL_CTX_use_PrivateKey_file(ctx, key, 0);
    #else
        ret = wolfSSL_CTX_use_PrivateKey_buffer(ctx, key, sizeof_key, SSL_FILETYPE_ASN1);
    #endif
        if (ret != SSL_SUCCESS) {
            printf("Error %d loading server-key!\n", ret);
	    return NULL;
        }

	/* Register callbacks */
	wolfSSL_SetIORecv(ctx, my_IORecv);
	wolfSSL_SetIOSend(ctx, my_IOSend);
	return ctx;

}
#define BUFF_SIZE 256
char buff[BUFF_SIZE];
void wolfSSL_TLS_server2()
{
    ID cepid = 1;
    ID repid = 1;
    ER ercd;

    T_IPV4EP dst_addr = {0, 0};
    if((ercd = tcp_acp_cep(cepid, repid, &dst_addr, TMO_FEVR)) != E_OK) {
         printf("ERROR TCP Accept: %d\n", ercd);
         return;
     }

    ercd = 0;
}

void wolfSSL_TLS_server(void *v_ctx, func_args *args)
{
    ID cepid = 1;
    ID repid = 1;
    ER ercd;
    WOLFSSL_CTX *ctx = (WOLFSSL_CTX *)v_ctx;
    (void) args;

    WOLFSSL *ssl;
    int len;
    T_IPV4EP dst_addr = {0, 0};

    if((ercd = tcp_acp_cep(cepid, repid, &dst_addr, TMO_FEVR)) != E_OK) {
        printf("ERROR TCP Accept: %d\n", ercd);
        return;
    }

    if((ssl = wolfSSL_new(ctx)) == NULL) {
        printf("ERROR: failed wolfSSL_new\n");
        return;
    }

    wolfSSL_SetIOReadCtx(ssl, (void *)&cepid);
    wolfSSL_SetIOWriteCtx(ssl, (void *)&cepid);
    printf("SSL Accept\n");

    if (wolfSSL_accept(ssl) < 0) {
        printf("ERROR: SSL Accept(%d)\n", wolfSSL_get_error(ssl, 0));
        return;
    }
printf("SSL Accept\n");
    if ((len = wolfSSL_read(ssl, buff, sizeof(buff) - 1)) < 0) {
        printf("ERROR: SSL Read(%d)\n", wolfSSL_get_error(ssl, 0));
        return;
    }
    printf("SSL Read\n");

    buff[len] = '\0';
    printf("Received: %s\n", buff);

    if (wolfSSL_write(ssl, buff, len) != len) {
        printf("ERROR: SSL Write(%d)\n", wolfSSL_get_error(ssl, 0));
        return;
    }

    wolfSSL_free(ssl);
    tcp_sht_cep(cepid);
    ercd = tcp_cls_cep(cepid, TMO_FEVR);
    if(ercd != E_OK) {
    	printf("tcp_cls_cep error %d\n",ercd);
    }

}
