export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/opt/openssl/lib/
sansi=`ls libsansi*.o`
ln -fs $sansi libsansi.o
go build -o sansi main.go
./sansi
