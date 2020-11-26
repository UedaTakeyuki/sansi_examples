//https://blanktar.jp/blog/2014/10/c_language-aes-with-openssl
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/err.h>

int main(){
    int  encripted_bind_id_len;
    unsigned char encripted_bind_id[33];
    unsigned char *key = "0x8E9916C5340C43FA003FE2DD54CD4E30";
    unsigned char *bind_id = "ZbPdGoGyrNkQ";
    unsigned char plaintext[18];
    int len;
    int plaintext_len;
    unsigned char cipher_text[18];
    int cipher_text_len;

    EVP_CIPHER_CTX *ctx = NULL;
    FILE *fp;


    ctx = EVP_CIPHER_CTX_new();

    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL);
    EVP_EncryptUpdate(ctx, cipher_text, &cipher_text_len, bind_id, 12);
    EVP_EncryptFinal_ex(ctx, cipher_text + cipher_text_len, &len);
    cipher_text_len += len;
    EVP_CIPHER_CTX_free(ctx);

    fp = fopen("licensefile","wb");
    fwrite(&cipher_text,cipher_text_len,1,fp);
    fclose(fp);
    
    fp = fopen( "licensefile", "rb" );
    if( fp == NULL ){
        fputs( "Open Failed\n", stderr );
        exit( EXIT_FAILURE );
    }

    encripted_bind_id_len = fread( encripted_bind_id, sizeof(encripted_bind_id[0]), sizeof(encripted_bind_id), fp );
    encripted_bind_id[encripted_bind_id_len] = '\0';

    ctx = EVP_CIPHER_CTX_new();

    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, (unsigned char*)key, NULL);
//    EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, cipher_text, cipher_text_len);
    EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, encripted_bind_id, encripted_bind_id_len);
    EVP_DecryptFinal_ex(ctx, (plaintext + plaintext_len), &len);
    plaintext_len += len;
    EVP_CIPHER_CTX_cleanup(ctx);
    plaintext[plaintext_len] = '\0';

    printf("cipher_text_len: %d\n",cipher_text_len);
    printf("plaintext_len: %d\n",plaintext_len);
    printf("bind_id: %s\n",plaintext);
}