#!/bin/bash
# 
# compile sample for Linux by clang

usage_exit() {
  echo "Usage: $0 [source] [libsansi]" 1>&2
  echo "  [source]:   compiling source file, default is 'main.sample.c' "      1>&2
  echo "  [libsansi]: path for linking 'libsansi….o', default is found it in cwd automatically " 1>&2
  exit 1
}

while getopts "h" OPT; do
case "$OPT" in
  h) usage_exit
esac
done

if [ ${@:$OPTIND+1:1} ]; then
  libsansi=${@:$OPTIND+1:1}
else
  libsansi=`ls libsansi*.o`
fi

if [ ${@:$OPTIND:1} ]; then
  sfile=${@:$OPTIND:1}
else
  sfile="main.simple.c"
fi

echo "source   =" $sfile
echo "libsansi =" $libsansi
echo "compiling…"

#
# compile by clang with your sansi library
#
clang -o sansi $libsansi $sfile -L . -lssl -lcrypto -lpthread -ldl -lm

echo "done."

# @author Dr. Takeyuki UEDA
# @copyright Copyright© Atelier UEDA 2020 - All rights reserved.