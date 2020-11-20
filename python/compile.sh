gcc -I/usr/include/python2.7/ -o sansiWrapper.o -c sansiWrapper.c
gcc -shared libsansi_XMdvaoLeqDKn_arm_v1.1.o sansiWrapper.o -o sansimodule.so  -lssl -lcrypto -lpthread -ldl -lm

# for nuitka setting up, refer http://www.nuitka.net/pages/download.html
python -m nuitka --follow-imports --include-plugin-directory --plugin-enable=pylint-warnings main.py
