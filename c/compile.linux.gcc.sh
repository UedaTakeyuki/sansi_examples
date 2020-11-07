#
# get your sansi library file name, remove "lib" prefix and ".a" postfix for linker 
#
libsansi=`ls libsansi*.o`
# echo $libsansi


#
# compile by gcc with your sansi library
gcc -o sansi $libsansi main.c -L . -lssl -lcrypto -lpthread -ldl -lm
