#define _GNU_SOURCE
#include <openssl/ssl.h>
#include <openssl/x509_vfy.h>
#include <stdio.h>
#include <dlfcn.h> 

long SSL_get_verify_result(const SSL *ssl) {
    return X509_V_OK;
}


int ignore_verify_callback(int preverify_ok, X509_STORE_CTX *x509_ctx) {
    return 1;
}


void SSL_CTX_set_verify(SSL_CTX *ctx, int mode, SSL_verify_cb callback) {
    static void (*real_SSL_CTX_set_verify)(SSL_CTX *, int, SSL_verify_cb) = NULL;
    if (!real_SSL_CTX_set_verify) {
        real_SSL_CTX_set_verify = dlsym(RTLD_NEXT, "SSL_CTX_set_verify");
    }
    real_SSL_CTX_set_verify(ctx, mode, ignore_verify_callback);
}
