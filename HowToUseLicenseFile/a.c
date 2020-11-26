#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/err.h>

int main(){
    int  encripted_bind_id_len;
    unsigned char encripted_bind_id[33];
    unsigned char *key = "0x8E9916C5340C43FA003FE2DD54CD4E30";
    unsigned char *iv  = "0x27AFFBFC0D631E4CD858F64EC09FA9ED";
    unsigned char plaintext[18];
    int plaintext_len;
    EVP_CIPHER_CTX *ctx = NULL;


    ctx = EVP_CIPHER_CTX_new();
    FILE* fp = fopen( "licensefile", "rb" );
    if( fp == NULL ){
        fputs( "Open Failed\n", stderr );
        exit( EXIT_FAILURE );
    }
    encripted_bind_id_len = fread( encripted_bind_id, sizeof(encripted_bind_id[0]), sizeof(encripted_bind_id), fp );
    encripted_bind_id[encripted_bind_id_len] = '\0';

    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, (unsigned char*)key, iv);
    EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, encripted_bind_id, encripted_bind_id_len);
    EVP_DecryptFinal_ex(ctx, (plaintext + plaintext_len), &plaintext_len);
    EVP_CIPHER_CTX_cleanup(ctx);
//    plaintext[plaintext_len] = '\0';

    printf("encripted_bind_id_len: %d\n",encripted_bind_id_len);
    printf("plaintext_len: %d\n",plaintext_len);
    printf("bind_id: %s\n",plaintext);
}