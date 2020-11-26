openssl aes-128-cbc -e -in bind_id.txt -out licensefile -pass file:./password.txt -nosalt
