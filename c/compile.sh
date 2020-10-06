#
# get your sansi library file name, remove "lib" prefix and ".a" postfix for linker 
#
libsansi=`ls libsansi*.o`
# echo $libsansi

#
# compile by clang with your sansi library
#
#clang -o sansi main.c -L . -lssl -lcrypto -lpthread -ldl -lm -l${libsansi}

#
# compile by gcc with your sansi library
# for -no-pie refer https://stackoverflow.com/a/49353245/11073131
gcc -o sansi $libsansi main.c -L . -lssl -lcrypto -lpthread -ldl -lm
