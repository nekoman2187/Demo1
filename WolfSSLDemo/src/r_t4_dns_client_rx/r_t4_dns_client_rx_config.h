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
* Copyright (C) 2014-2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_t4_dns_client_rx_config.h
* Description  : Configuration options for the r_t4_dns_client_rx module.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 04.04.2011 1.00    First Release
*         : 09.05.2014 1.01    Corresponded to FIT Modules
*         : 01.07.2014 1.02    Clean up source code
*         : 01.04.2016 1.03    XML file update
*         : 01.03.2017 1.04    Change API function name
***********************************************************************************************************************/
#ifndef R_T4_DNS_CLIENT_RX_CONFIG_H
#define R_T4_DNS_CLIENT_RX_CONFIG_H

/***********************************************************************************************************************
Configuration Options
***********************************************************************************************************************/
#define DNS_CFG_TIMEOUT   5       /* DNS timeout 50msec(5 * 10ms) */
#define DNS_CFG_NAME_SIZE   256       /* DNS limit of name */

#define DNS_CFG_UDP_CEP_ID  1       /* UDP communication end point ID for DNS in file config_tcpudp.c */
#endif /* R_T4_DNS_CLIENT_RX_CONFIG_H */


