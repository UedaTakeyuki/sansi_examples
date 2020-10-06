# use openssl
export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/opt/openssl/lib/

#
# get your sansi library file name, remove "lib" prefix and ".a" postfix for linker 
#
original_libsansi=`ls libsansi*.a`
end_removed=${original_libsansi%.a}
libsansi=${end_removed#*lib}
# echo $libsansi

#
# compile by clang with your sansi library
#
#clang -o sansi main.c -L . -L /usr/local/opt/openssl/lib -lssl -lcrypto -lpthread -ldl -lm -l${libsansi}
clang -o sansi main.c libsansi*.o -L . -L /usr/local/opt/openssl/lib -lssl -lcrypto -lpthread -ldl -lm

#
# compile by gcc with your sansi library
#gcc -o sansi main.c -L . -lssl -lcrypto -lpthread -ldl -lm -l${libsansi}
