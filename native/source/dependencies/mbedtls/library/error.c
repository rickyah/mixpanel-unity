/*
 *  Error message information
 *
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */

#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_ERROR_C) || defined(MBEDTLS_ERROR_STRERROR_DUMMY)
#include "mbedtls/error.h"
#include <string.h>
#endif

#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#define mixpanel_mbedtls_snprintf snprintf
#endif

#if defined(MBEDTLS_ERROR_C)

#include <stdio.h>

#if defined(MBEDTLS_AES_C)
#include "mbedtls/aes.h"
#endif

#if defined(MBEDTLS_BASE64_C)
#include "mbedtls/base64.h"
#endif

#if defined(MBEDTLS_BIGNUM_C)
#include "mbedtls/bignum.h"
#endif

#if defined(MBEDTLS_BLOWFISH_C)
#include "mbedtls/blowfish.h"
#endif

#if defined(MBEDTLS_CAMELLIA_C)
#include "mbedtls/camellia.h"
#endif

#if defined(MBEDTLS_CCM_C)
#include "mbedtls/ccm.h"
#endif

#if defined(MBEDTLS_CIPHER_C)
#include "mbedtls/cipher.h"
#endif

#if defined(MBEDTLS_CTR_DRBG_C)
#include "mbedtls/ctr_drbg.h"
#endif

#if defined(MBEDTLS_DES_C)
#include "mbedtls/des.h"
#endif

#if defined(MBEDTLS_DHM_C)
#include "mbedtls/dhm.h"
#endif

#if defined(MBEDTLS_ECP_C)
#include "mbedtls/ecp.h"
#endif

#if defined(MBEDTLS_ENTROPY_C)
#include "mbedtls/entropy.h"
#endif

#if defined(MBEDTLS_GCM_C)
#include "mbedtls/gcm.h"
#endif

#if defined(MBEDTLS_HMAC_DRBG_C)
#include "mbedtls/hmac_drbg.h"
#endif

#if defined(MBEDTLS_MD_C)
#include "mbedtls/md.h"
#endif

#if defined(MBEDTLS_NET_C)
#include "mbedtls/net.h"
#endif

#if defined(MBEDTLS_OID_C)
#include "mbedtls/oid.h"
#endif

#if defined(MBEDTLS_PADLOCK_C)
#include "mbedtls/padlock.h"
#endif

#if defined(MBEDTLS_PEM_PARSE_C) || defined(MBEDTLS_PEM_WRITE_C)
#include "mbedtls/pem.h"
#endif

#if defined(MBEDTLS_PK_C)
#include "mbedtls/pk.h"
#endif

#if defined(MBEDTLS_PKCS12_C)
#include "mbedtls/pkcs12.h"
#endif

#if defined(MBEDTLS_PKCS5_C)
#include "mbedtls/pkcs5.h"
#endif

#if defined(MBEDTLS_RSA_C)
#include "mbedtls/rsa.h"
#endif

#if defined(MBEDTLS_SSL_TLS_C)
#include "mbedtls/ssl.h"
#endif

#if defined(MBEDTLS_THREADING_C)
#include "mbedtls/threading.h"
#endif

#if defined(MBEDTLS_X509_USE_C) || defined(MBEDTLS_X509_CREATE_C)
#include "mbedtls/x509.h"
#endif

#if defined(MBEDTLS_XTEA_C)
#include "mbedtls/xtea.h"
#endif


void mixpanel_mbedtls_strerror( int ret, char *buf, size_t buflen )
{
    size_t len;
    int use_ret;

    if( buflen == 0 )
        return;

    memset( buf, 0x00, buflen );

    if( ret < 0 )
        ret = -ret;

    if( ret & 0xFF80 )
    {
        use_ret = ret & 0xFF80;

        // High level error codes
        //
        // BEGIN generated code
#if defined(MBEDTLS_CIPHER_C)
        if( use_ret == -(MBEDTLS_ERR_CIPHER_FEATURE_UNAVAILABLE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "CIPHER - The selected feature is not available" );
        if( use_ret == -(MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "CIPHER - Bad input parameters to function" );
        if( use_ret == -(MBEDTLS_ERR_CIPHER_ALLOC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "CIPHER - Failed to allocate memory" );
        if( use_ret == -(MBEDTLS_ERR_CIPHER_INVALID_PADDING) )
            mixpanel_mbedtls_snprintf( buf, buflen, "CIPHER - Input data contains invalid padding and is rejected" );
        if( use_ret == -(MBEDTLS_ERR_CIPHER_FULL_BLOCK_EXPECTED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "CIPHER - Decryption of block requires a full block" );
        if( use_ret == -(MBEDTLS_ERR_CIPHER_AUTH_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "CIPHER - Authentication failed (for AEAD modes)" );
#endif /* MBEDTLS_CIPHER_C */

#if defined(MBEDTLS_DHM_C)
        if( use_ret == -(MBEDTLS_ERR_DHM_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "DHM - Bad input parameters to function" );
        if( use_ret == -(MBEDTLS_ERR_DHM_READ_PARAMS_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "DHM - Reading of the DHM parameters failed" );
        if( use_ret == -(MBEDTLS_ERR_DHM_MAKE_PARAMS_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "DHM - Making of the DHM parameters failed" );
        if( use_ret == -(MBEDTLS_ERR_DHM_READ_PUBLIC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "DHM - Reading of the public values failed" );
        if( use_ret == -(MBEDTLS_ERR_DHM_MAKE_PUBLIC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "DHM - Making of the public value failed" );
        if( use_ret == -(MBEDTLS_ERR_DHM_CALC_SECRET_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "DHM - Calculation of the DHM secret failed" );
        if( use_ret == -(MBEDTLS_ERR_DHM_INVALID_FORMAT) )
            mixpanel_mbedtls_snprintf( buf, buflen, "DHM - The ASN.1 data is not formatted correctly" );
        if( use_ret == -(MBEDTLS_ERR_DHM_ALLOC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "DHM - Allocation of memory failed" );
        if( use_ret == -(MBEDTLS_ERR_DHM_FILE_IO_ERROR) )
            mixpanel_mbedtls_snprintf( buf, buflen, "DHM - Read/write of file failed" );
#endif /* MBEDTLS_DHM_C */

#if defined(MBEDTLS_ECP_C)
        if( use_ret == -(MBEDTLS_ERR_ECP_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "ECP - Bad input parameters to function" );
        if( use_ret == -(MBEDTLS_ERR_ECP_BUFFER_TOO_SMALL) )
            mixpanel_mbedtls_snprintf( buf, buflen, "ECP - The buffer is too small to write to" );
        if( use_ret == -(MBEDTLS_ERR_ECP_FEATURE_UNAVAILABLE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "ECP - Requested curve not available" );
        if( use_ret == -(MBEDTLS_ERR_ECP_VERIFY_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "ECP - The signature is not valid" );
        if( use_ret == -(MBEDTLS_ERR_ECP_ALLOC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "ECP - Memory allocation failed" );
        if( use_ret == -(MBEDTLS_ERR_ECP_RANDOM_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "ECP - Generation of random value, such as (ephemeral) key, failed" );
        if( use_ret == -(MBEDTLS_ERR_ECP_INVALID_KEY) )
            mixpanel_mbedtls_snprintf( buf, buflen, "ECP - Invalid private or public key" );
        if( use_ret == -(MBEDTLS_ERR_ECP_SIG_LEN_MISMATCH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "ECP - Signature is valid but shorter than the user-supplied length" );
#endif /* MBEDTLS_ECP_C */

#if defined(MBEDTLS_MD_C)
        if( use_ret == -(MBEDTLS_ERR_MD_FEATURE_UNAVAILABLE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "MD - The selected feature is not available" );
        if( use_ret == -(MBEDTLS_ERR_MD_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "MD - Bad input parameters to function" );
        if( use_ret == -(MBEDTLS_ERR_MD_ALLOC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "MD - Failed to allocate memory" );
        if( use_ret == -(MBEDTLS_ERR_MD_FILE_IO_ERROR) )
            mixpanel_mbedtls_snprintf( buf, buflen, "MD - Opening or reading of file failed" );
#endif /* MBEDTLS_MD_C */

#if defined(MBEDTLS_PEM_PARSE_C) || defined(MBEDTLS_PEM_WRITE_C)
        if( use_ret == -(MBEDTLS_ERR_PEM_NO_HEADER_FOOTER_PRESENT) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PEM - No PEM header or footer found" );
        if( use_ret == -(MBEDTLS_ERR_PEM_INVALID_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PEM - PEM string is not as expected" );
        if( use_ret == -(MBEDTLS_ERR_PEM_ALLOC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PEM - Failed to allocate memory" );
        if( use_ret == -(MBEDTLS_ERR_PEM_INVALID_ENC_IV) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PEM - RSA IV is not in hex-format" );
        if( use_ret == -(MBEDTLS_ERR_PEM_UNKNOWN_ENC_ALG) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PEM - Unsupported key encryption algorithm" );
        if( use_ret == -(MBEDTLS_ERR_PEM_PASSWORD_REQUIRED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PEM - Private key password can't be empty" );
        if( use_ret == -(MBEDTLS_ERR_PEM_PASSWORD_MISMATCH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PEM - Given private key password does not allow for correct decryption" );
        if( use_ret == -(MBEDTLS_ERR_PEM_FEATURE_UNAVAILABLE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PEM - Unavailable feature, e.g. hashing/encryption combination" );
        if( use_ret == -(MBEDTLS_ERR_PEM_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PEM - Bad input parameters to function" );
#endif /* MBEDTLS_PEM_PARSE_C || MBEDTLS_PEM_WRITE_C */

#if defined(MBEDTLS_PK_C)
        if( use_ret == -(MBEDTLS_ERR_PK_ALLOC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Memory allocation failed" );
        if( use_ret == -(MBEDTLS_ERR_PK_TYPE_MISMATCH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Type mismatch, eg attempt to encrypt with an ECDSA key" );
        if( use_ret == -(MBEDTLS_ERR_PK_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Bad input parameters to function" );
        if( use_ret == -(MBEDTLS_ERR_PK_FILE_IO_ERROR) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Read/write of file failed" );
        if( use_ret == -(MBEDTLS_ERR_PK_KEY_INVALID_VERSION) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Unsupported key version" );
        if( use_ret == -(MBEDTLS_ERR_PK_KEY_INVALID_FORMAT) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Invalid key tag or value" );
        if( use_ret == -(MBEDTLS_ERR_PK_UNKNOWN_PK_ALG) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Key algorithm is unsupported (only RSA and EC are supported)" );
        if( use_ret == -(MBEDTLS_ERR_PK_PASSWORD_REQUIRED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Private key password can't be empty" );
        if( use_ret == -(MBEDTLS_ERR_PK_PASSWORD_MISMATCH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Given private key password does not allow for correct decryption" );
        if( use_ret == -(MBEDTLS_ERR_PK_INVALID_PUBKEY) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - The pubkey tag or value is invalid (only RSA and EC are supported)" );
        if( use_ret == -(MBEDTLS_ERR_PK_INVALID_ALG) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - The algorithm tag or value is invalid" );
        if( use_ret == -(MBEDTLS_ERR_PK_UNKNOWN_NAMED_CURVE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Elliptic curve is unsupported (only NIST curves are supported)" );
        if( use_ret == -(MBEDTLS_ERR_PK_FEATURE_UNAVAILABLE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - Unavailable feature, e.g. RSA disabled for RSA key" );
        if( use_ret == -(MBEDTLS_ERR_PK_SIG_LEN_MISMATCH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PK - The signature is valid but its length is less than expected" );
#endif /* MBEDTLS_PK_C */

#if defined(MBEDTLS_PKCS12_C)
        if( use_ret == -(MBEDTLS_ERR_PKCS12_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PKCS12 - Bad input parameters to function" );
        if( use_ret == -(MBEDTLS_ERR_PKCS12_FEATURE_UNAVAILABLE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PKCS12 - Feature not available, e.g. unsupported encryption scheme" );
        if( use_ret == -(MBEDTLS_ERR_PKCS12_PBE_INVALID_FORMAT) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PKCS12 - PBE ASN.1 data not as expected" );
        if( use_ret == -(MBEDTLS_ERR_PKCS12_PASSWORD_MISMATCH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PKCS12 - Given private key password does not allow for correct decryption" );
#endif /* MBEDTLS_PKCS12_C */

#if defined(MBEDTLS_PKCS5_C)
        if( use_ret == -(MBEDTLS_ERR_PKCS5_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PKCS5 - Bad input parameters to function" );
        if( use_ret == -(MBEDTLS_ERR_PKCS5_INVALID_FORMAT) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PKCS5 - Unexpected ASN.1 data" );
        if( use_ret == -(MBEDTLS_ERR_PKCS5_FEATURE_UNAVAILABLE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PKCS5 - Requested encryption or digest alg not available" );
        if( use_ret == -(MBEDTLS_ERR_PKCS5_PASSWORD_MISMATCH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "PKCS5 - Given private key password does not allow for correct decryption" );
#endif /* MBEDTLS_PKCS5_C */

#if defined(MBEDTLS_RSA_C)
        if( use_ret == -(MBEDTLS_ERR_RSA_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "RSA - Bad input parameters to function" );
        if( use_ret == -(MBEDTLS_ERR_RSA_INVALID_PADDING) )
            mixpanel_mbedtls_snprintf( buf, buflen, "RSA - Input data contains invalid padding and is rejected" );
        if( use_ret == -(MBEDTLS_ERR_RSA_KEY_GEN_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "RSA - Something failed during generation of a key" );
        if( use_ret == -(MBEDTLS_ERR_RSA_KEY_CHECK_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "RSA - Key failed to pass the library's validity check" );
        if( use_ret == -(MBEDTLS_ERR_RSA_PUBLIC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "RSA - The public key operation failed" );
        if( use_ret == -(MBEDTLS_ERR_RSA_PRIVATE_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "RSA - The private key operation failed" );
        if( use_ret == -(MBEDTLS_ERR_RSA_VERIFY_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "RSA - The PKCS#1 verification failed" );
        if( use_ret == -(MBEDTLS_ERR_RSA_OUTPUT_TOO_LARGE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "RSA - The output buffer for decryption is not large enough" );
        if( use_ret == -(MBEDTLS_ERR_RSA_RNG_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "RSA - The random generator failed to generate non-zeros" );
#endif /* MBEDTLS_RSA_C */

#if defined(MBEDTLS_SSL_TLS_C)
        if( use_ret == -(MBEDTLS_ERR_SSL_FEATURE_UNAVAILABLE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - The requested feature is not available" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Bad input parameters to function" );
        if( use_ret == -(MBEDTLS_ERR_SSL_INVALID_MAC) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Verification of the message MAC failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_INVALID_RECORD) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - An invalid SSL record was received" );
        if( use_ret == -(MBEDTLS_ERR_SSL_CONN_EOF) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - The connection indicated an EOF" );
        if( use_ret == -(MBEDTLS_ERR_SSL_UNKNOWN_CIPHER) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - An unknown cipher was received" );
        if( use_ret == -(MBEDTLS_ERR_SSL_NO_CIPHER_CHOSEN) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - The server has no ciphersuites in common with the client" );
        if( use_ret == -(MBEDTLS_ERR_SSL_NO_RNG) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - No RNG was provided to the SSL module" );
        if( use_ret == -(MBEDTLS_ERR_SSL_NO_CLIENT_CERTIFICATE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - No client certification received from the client, but required by the authentication mode" );
        if( use_ret == -(MBEDTLS_ERR_SSL_CERTIFICATE_TOO_LARGE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Our own certificate(s) is/are too large to send in an SSL message" );
        if( use_ret == -(MBEDTLS_ERR_SSL_CERTIFICATE_REQUIRED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - The own certificate is not set, but needed by the server" );
        if( use_ret == -(MBEDTLS_ERR_SSL_PRIVATE_KEY_REQUIRED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - The own private key or pre-shared key is not set, but needed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_CA_CHAIN_REQUIRED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - No CA Chain is set, but required to operate" );
        if( use_ret == -(MBEDTLS_ERR_SSL_UNEXPECTED_MESSAGE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - An unexpected message was received from our peer" );
        if( use_ret == -(MBEDTLS_ERR_SSL_FATAL_ALERT_MESSAGE) )
        {
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - A fatal alert message was received from our peer" );
            return;
        }
        if( use_ret == -(MBEDTLS_ERR_SSL_PEER_VERIFY_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Verification of our peer failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_PEER_CLOSE_NOTIFY) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - The peer notified us that the connection is going to be closed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_CLIENT_HELLO) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the ClientHello handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_SERVER_HELLO) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the ServerHello handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_CERTIFICATE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the Certificate handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_CERTIFICATE_REQUEST) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the CertificateRequest handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_SERVER_KEY_EXCHANGE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the ServerKeyExchange handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_SERVER_HELLO_DONE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the ServerHelloDone handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_CLIENT_KEY_EXCHANGE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the ClientKeyExchange handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_CLIENT_KEY_EXCHANGE_RP) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the ClientKeyExchange handshake message failed in DHM / ECDH Read Public" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_CLIENT_KEY_EXCHANGE_CS) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the ClientKeyExchange handshake message failed in DHM / ECDH Calculate Secret" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_CERTIFICATE_VERIFY) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the CertificateVerify handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_CHANGE_CIPHER_SPEC) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the ChangeCipherSpec handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_FINISHED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the Finished handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_ALLOC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Memory allocation failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_HW_ACCEL_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Hardware acceleration function returned with error" );
        if( use_ret == -(MBEDTLS_ERR_SSL_HW_ACCEL_FALLTHROUGH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Hardware acceleration function skipped / left alone data" );
        if( use_ret == -(MBEDTLS_ERR_SSL_COMPRESSION_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the compression / decompression failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_PROTOCOL_VERSION) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Handshake protocol not within min/max boundaries" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BAD_HS_NEW_SESSION_TICKET) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Processing of the NewSessionTicket handshake message failed" );
        if( use_ret == -(MBEDTLS_ERR_SSL_SESSION_TICKET_EXPIRED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Session ticket has expired" );
        if( use_ret == -(MBEDTLS_ERR_SSL_PK_TYPE_MISMATCH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Public key type mismatch (eg, asked for RSA key exchange and presented EC key)" );
        if( use_ret == -(MBEDTLS_ERR_SSL_UNKNOWN_IDENTITY) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Unknown identity received (eg, PSK identity)" );
        if( use_ret == -(MBEDTLS_ERR_SSL_INTERNAL_ERROR) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Internal error (eg, unexpected failure in lower-level module)" );
        if( use_ret == -(MBEDTLS_ERR_SSL_COUNTER_WRAPPING) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - A counter would wrap (eg, too many messages exchanged)" );
        if( use_ret == -(MBEDTLS_ERR_SSL_WAITING_SERVER_HELLO_RENEGO) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Unexpected message at ServerHello in renegotiation" );
        if( use_ret == -(MBEDTLS_ERR_SSL_HELLO_VERIFY_REQUIRED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - DTLS client must retry for hello verification" );
        if( use_ret == -(MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - A buffer is too small to receive or write a message" );
        if( use_ret == -(MBEDTLS_ERR_SSL_NO_USABLE_CIPHERSUITE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - None of the common ciphersuites is usable (eg, no suitable certificate, see debug messages)" );
        if( use_ret == -(MBEDTLS_ERR_SSL_WANT_READ) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Connection requires a read call" );
        if( use_ret == -(MBEDTLS_ERR_SSL_WANT_WRITE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - Connection requires a write call" );
        if( use_ret == -(MBEDTLS_ERR_SSL_TIMEOUT) )
            mixpanel_mbedtls_snprintf( buf, buflen, "SSL - The operation timed out" );
#endif /* MBEDTLS_SSL_TLS_C */

#if defined(MBEDTLS_X509_USE_C) || defined(MBEDTLS_X509_CREATE_C)
        if( use_ret == -(MBEDTLS_ERR_X509_FEATURE_UNAVAILABLE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Unavailable feature, e.g. RSA hashing/encryption combination" );
        if( use_ret == -(MBEDTLS_ERR_X509_UNKNOWN_OID) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Requested OID is unknown" );
        if( use_ret == -(MBEDTLS_ERR_X509_INVALID_FORMAT) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - The CRT/CRL/CSR format is invalid, e.g. different type expected" );
        if( use_ret == -(MBEDTLS_ERR_X509_INVALID_VERSION) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - The CRT/CRL/CSR version element is invalid" );
        if( use_ret == -(MBEDTLS_ERR_X509_INVALID_SERIAL) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - The serial tag or value is invalid" );
        if( use_ret == -(MBEDTLS_ERR_X509_INVALID_ALG) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - The algorithm tag or value is invalid" );
        if( use_ret == -(MBEDTLS_ERR_X509_INVALID_NAME) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - The name tag or value is invalid" );
        if( use_ret == -(MBEDTLS_ERR_X509_INVALID_DATE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - The date tag or value is invalid" );
        if( use_ret == -(MBEDTLS_ERR_X509_INVALID_SIGNATURE) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - The signature tag or value invalid" );
        if( use_ret == -(MBEDTLS_ERR_X509_INVALID_EXTENSIONS) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - The extension tag or value is invalid" );
        if( use_ret == -(MBEDTLS_ERR_X509_UNKNOWN_VERSION) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - CRT/CRL/CSR has an unsupported version number" );
        if( use_ret == -(MBEDTLS_ERR_X509_UNKNOWN_SIG_ALG) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Signature algorithm (oid) is unsupported" );
        if( use_ret == -(MBEDTLS_ERR_X509_SIG_MISMATCH) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Signature algorithms do not match. (see \\c ::mixpanel_mbedtls_x509_crt sig_oid)" );
        if( use_ret == -(MBEDTLS_ERR_X509_CERT_VERIFY_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Certificate verification failed, e.g. CRL, CA or signature check failed" );
        if( use_ret == -(MBEDTLS_ERR_X509_CERT_UNKNOWN_FORMAT) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Format not recognized as DER or PEM" );
        if( use_ret == -(MBEDTLS_ERR_X509_BAD_INPUT_DATA) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Input invalid" );
        if( use_ret == -(MBEDTLS_ERR_X509_ALLOC_FAILED) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Allocation of memory failed" );
        if( use_ret == -(MBEDTLS_ERR_X509_FILE_IO_ERROR) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Read/write of file failed" );
        if( use_ret == -(MBEDTLS_ERR_X509_BUFFER_TOO_SMALL) )
            mixpanel_mbedtls_snprintf( buf, buflen, "X509 - Destination buffer is too small" );
#endif /* MBEDTLS_X509_USE_C || MBEDTLS_X509_CREATE_C */
        // END generated code

        if( strlen( buf ) == 0 )
            mixpanel_mbedtls_snprintf( buf, buflen, "UNKNOWN ERROR CODE (%04X)", use_ret );
    }

    use_ret = ret & ~0xFF80;

    if( use_ret == 0 )
        return;

    // If high level code is present, make a concatenation between both
    // error strings.
    //
    len = strlen( buf );

    if( len > 0 )
    {
        if( buflen - len < 5 )
            return;

        mixpanel_mbedtls_snprintf( buf + len, buflen - len, " : " );

        buf += len + 3;
        buflen -= len + 3;
    }

    // Low level error codes
    //
    // BEGIN generated code
#if defined(MBEDTLS_AES_C)
    if( use_ret == -(MBEDTLS_ERR_AES_INVALID_KEY_LENGTH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "AES - Invalid key length" );
    if( use_ret == -(MBEDTLS_ERR_AES_INVALID_INPUT_LENGTH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "AES - Invalid data input length" );
#endif /* MBEDTLS_AES_C */

#if defined(MBEDTLS_ASN1_PARSE_C)
    if( use_ret == -(MBEDTLS_ERR_ASN1_OUT_OF_DATA) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ASN1 - Out of data when parsing an ASN1 data structure" );
    if( use_ret == -(MBEDTLS_ERR_ASN1_UNEXPECTED_TAG) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ASN1 - ASN1 tag was of an unexpected value" );
    if( use_ret == -(MBEDTLS_ERR_ASN1_INVALID_LENGTH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ASN1 - Error when trying to determine the length or invalid length" );
    if( use_ret == -(MBEDTLS_ERR_ASN1_LENGTH_MISMATCH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ASN1 - Actual length differs from expected length" );
    if( use_ret == -(MBEDTLS_ERR_ASN1_INVALID_DATA) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ASN1 - Data is invalid. (not used)" );
    if( use_ret == -(MBEDTLS_ERR_ASN1_ALLOC_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ASN1 - Memory allocation failed" );
    if( use_ret == -(MBEDTLS_ERR_ASN1_BUF_TOO_SMALL) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ASN1 - Buffer too small when writing ASN.1 data structure" );
#endif /* MBEDTLS_ASN1_PARSE_C */

#if defined(MBEDTLS_BASE64_C)
    if( use_ret == -(MBEDTLS_ERR_BASE64_BUFFER_TOO_SMALL) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BASE64 - Output buffer too small" );
    if( use_ret == -(MBEDTLS_ERR_BASE64_INVALID_CHARACTER) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BASE64 - Invalid character in input" );
#endif /* MBEDTLS_BASE64_C */

#if defined(MBEDTLS_BIGNUM_C)
    if( use_ret == -(MBEDTLS_ERR_MPI_FILE_IO_ERROR) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BIGNUM - An error occurred while reading from or writing to a file" );
    if( use_ret == -(MBEDTLS_ERR_MPI_BAD_INPUT_DATA) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BIGNUM - Bad input parameters to function" );
    if( use_ret == -(MBEDTLS_ERR_MPI_INVALID_CHARACTER) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BIGNUM - There is an invalid character in the digit string" );
    if( use_ret == -(MBEDTLS_ERR_MPI_BUFFER_TOO_SMALL) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BIGNUM - The buffer is too small to write to" );
    if( use_ret == -(MBEDTLS_ERR_MPI_NEGATIVE_VALUE) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BIGNUM - The input arguments are negative or result in illegal output" );
    if( use_ret == -(MBEDTLS_ERR_MPI_DIVISION_BY_ZERO) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BIGNUM - The input argument for division is zero, which is not allowed" );
    if( use_ret == -(MBEDTLS_ERR_MPI_NOT_ACCEPTABLE) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BIGNUM - The input arguments are not acceptable" );
    if( use_ret == -(MBEDTLS_ERR_MPI_ALLOC_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BIGNUM - Memory allocation failed" );
#endif /* MBEDTLS_BIGNUM_C */

#if defined(MBEDTLS_BLOWFISH_C)
    if( use_ret == -(MBEDTLS_ERR_BLOWFISH_INVALID_KEY_LENGTH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BLOWFISH - Invalid key length" );
    if( use_ret == -(MBEDTLS_ERR_BLOWFISH_INVALID_INPUT_LENGTH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "BLOWFISH - Invalid data input length" );
#endif /* MBEDTLS_BLOWFISH_C */

#if defined(MBEDTLS_CAMELLIA_C)
    if( use_ret == -(MBEDTLS_ERR_CAMELLIA_INVALID_KEY_LENGTH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "CAMELLIA - Invalid key length" );
    if( use_ret == -(MBEDTLS_ERR_CAMELLIA_INVALID_INPUT_LENGTH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "CAMELLIA - Invalid data input length" );
#endif /* MBEDTLS_CAMELLIA_C */

#if defined(MBEDTLS_CCM_C)
    if( use_ret == -(MBEDTLS_ERR_CCM_BAD_INPUT) )
        mixpanel_mbedtls_snprintf( buf, buflen, "CCM - Bad input parameters to function" );
    if( use_ret == -(MBEDTLS_ERR_CCM_AUTH_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "CCM - Authenticated decryption failed" );
#endif /* MBEDTLS_CCM_C */

#if defined(MBEDTLS_CTR_DRBG_C)
    if( use_ret == -(MBEDTLS_ERR_CTR_DRBG_ENTROPY_SOURCE_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "CTR_DRBG - The entropy source failed" );
    if( use_ret == -(MBEDTLS_ERR_CTR_DRBG_REQUEST_TOO_BIG) )
        mixpanel_mbedtls_snprintf( buf, buflen, "CTR_DRBG - Too many random requested in single call" );
    if( use_ret == -(MBEDTLS_ERR_CTR_DRBG_INPUT_TOO_BIG) )
        mixpanel_mbedtls_snprintf( buf, buflen, "CTR_DRBG - Input too large (Entropy + additional)" );
    if( use_ret == -(MBEDTLS_ERR_CTR_DRBG_FILE_IO_ERROR) )
        mixpanel_mbedtls_snprintf( buf, buflen, "CTR_DRBG - Read/write error in file" );
#endif /* MBEDTLS_CTR_DRBG_C */

#if defined(MBEDTLS_DES_C)
    if( use_ret == -(MBEDTLS_ERR_DES_INVALID_INPUT_LENGTH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "DES - The data input has an invalid length" );
#endif /* MBEDTLS_DES_C */

#if defined(MBEDTLS_ENTROPY_C)
    if( use_ret == -(MBEDTLS_ERR_ENTROPY_SOURCE_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ENTROPY - Critical entropy source failure" );
    if( use_ret == -(MBEDTLS_ERR_ENTROPY_MAX_SOURCES) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ENTROPY - No more sources can be added" );
    if( use_ret == -(MBEDTLS_ERR_ENTROPY_NO_SOURCES_DEFINED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ENTROPY - No sources have been added to poll" );
    if( use_ret == -(MBEDTLS_ERR_ENTROPY_NO_STRONG_SOURCE) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ENTROPY - No strong sources have been added to poll" );
    if( use_ret == -(MBEDTLS_ERR_ENTROPY_FILE_IO_ERROR) )
        mixpanel_mbedtls_snprintf( buf, buflen, "ENTROPY - Read/write error in file" );
#endif /* MBEDTLS_ENTROPY_C */

#if defined(MBEDTLS_GCM_C)
    if( use_ret == -(MBEDTLS_ERR_GCM_AUTH_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "GCM - Authenticated decryption failed" );
    if( use_ret == -(MBEDTLS_ERR_GCM_BAD_INPUT) )
        mixpanel_mbedtls_snprintf( buf, buflen, "GCM - Bad input parameters to function" );
#endif /* MBEDTLS_GCM_C */

#if defined(MBEDTLS_HMAC_DRBG_C)
    if( use_ret == -(MBEDTLS_ERR_HMAC_DRBG_REQUEST_TOO_BIG) )
        mixpanel_mbedtls_snprintf( buf, buflen, "HMAC_DRBG - Too many random requested in single call" );
    if( use_ret == -(MBEDTLS_ERR_HMAC_DRBG_INPUT_TOO_BIG) )
        mixpanel_mbedtls_snprintf( buf, buflen, "HMAC_DRBG - Input too large (Entropy + additional)" );
    if( use_ret == -(MBEDTLS_ERR_HMAC_DRBG_FILE_IO_ERROR) )
        mixpanel_mbedtls_snprintf( buf, buflen, "HMAC_DRBG - Read/write error in file" );
    if( use_ret == -(MBEDTLS_ERR_HMAC_DRBG_ENTROPY_SOURCE_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "HMAC_DRBG - The entropy source failed" );
#endif /* MBEDTLS_HMAC_DRBG_C */

#if defined(MBEDTLS_NET_C)
    if( use_ret == -(MBEDTLS_ERR_NET_SOCKET_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - Failed to open a socket" );
    if( use_ret == -(MBEDTLS_ERR_NET_CONNECT_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - The connection to the given server / port failed" );
    if( use_ret == -(MBEDTLS_ERR_NET_BIND_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - Binding of the socket failed" );
    if( use_ret == -(MBEDTLS_ERR_NET_LISTEN_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - Could not listen on the socket" );
    if( use_ret == -(MBEDTLS_ERR_NET_ACCEPT_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - Could not accept the incoming connection" );
    if( use_ret == -(MBEDTLS_ERR_NET_RECV_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - Reading information from the socket failed" );
    if( use_ret == -(MBEDTLS_ERR_NET_SEND_FAILED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - Sending information through the socket failed" );
    if( use_ret == -(MBEDTLS_ERR_NET_CONN_RESET) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - Connection was reset by peer" );
    if( use_ret == -(MBEDTLS_ERR_NET_UNKNOWN_HOST) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - Failed to get an IP address for the given hostname" );
    if( use_ret == -(MBEDTLS_ERR_NET_BUFFER_TOO_SMALL) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - Buffer is too small to hold the data" );
    if( use_ret == -(MBEDTLS_ERR_NET_INVALID_CONTEXT) )
        mixpanel_mbedtls_snprintf( buf, buflen, "NET - The context is invalid, eg because it was free()ed" );
#endif /* MBEDTLS_NET_C */

#if defined(MBEDTLS_OID_C)
    if( use_ret == -(MBEDTLS_ERR_OID_NOT_FOUND) )
        mixpanel_mbedtls_snprintf( buf, buflen, "OID - OID is not found" );
    if( use_ret == -(MBEDTLS_ERR_OID_BUF_TOO_SMALL) )
        mixpanel_mbedtls_snprintf( buf, buflen, "OID - output buffer is too small" );
#endif /* MBEDTLS_OID_C */

#if defined(MBEDTLS_PADLOCK_C)
    if( use_ret == -(MBEDTLS_ERR_PADLOCK_DATA_MISALIGNED) )
        mixpanel_mbedtls_snprintf( buf, buflen, "PADLOCK - Input data should be aligned" );
#endif /* MBEDTLS_PADLOCK_C */

#if defined(MBEDTLS_THREADING_C)
    if( use_ret == -(MBEDTLS_ERR_THREADING_FEATURE_UNAVAILABLE) )
        mixpanel_mbedtls_snprintf( buf, buflen, "THREADING - The selected feature is not available" );
    if( use_ret == -(MBEDTLS_ERR_THREADING_BAD_INPUT_DATA) )
        mixpanel_mbedtls_snprintf( buf, buflen, "THREADING - Bad input parameters to function" );
    if( use_ret == -(MBEDTLS_ERR_THREADING_MUTEX_ERROR) )
        mixpanel_mbedtls_snprintf( buf, buflen, "THREADING - Locking / unlocking / free failed with error code" );
#endif /* MBEDTLS_THREADING_C */

#if defined(MBEDTLS_XTEA_C)
    if( use_ret == -(MBEDTLS_ERR_XTEA_INVALID_INPUT_LENGTH) )
        mixpanel_mbedtls_snprintf( buf, buflen, "XTEA - The data input has an invalid length" );
#endif /* MBEDTLS_XTEA_C */
    // END generated code

    if( strlen( buf ) != 0 )
        return;

    mixpanel_mbedtls_snprintf( buf, buflen, "UNKNOWN ERROR CODE (%04X)", use_ret );
}

#else /* MBEDTLS_ERROR_C */

#if defined(MBEDTLS_ERROR_STRERROR_DUMMY)

/*
 * Provide an non-function in case MBEDTLS_ERROR_C is not defined
 */
void mixpanel_mbedtls_strerror( int ret, char *buf, size_t buflen )
{
    ((void) ret);

    if( buflen > 0 )
        buf[0] = '\0';
}

#endif /* MBEDTLS_ERROR_STRERROR_DUMMY */

#endif /* MBEDTLS_ERROR_C */
