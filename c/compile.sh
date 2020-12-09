#!/bin/bash
# 
# compile sample for Linux by clang
#
usage_exit() {
  echo "Usage: $0 [-h][-c][-d][-g][-i][-m][-o obj] [source] [libsansi]" 1>&2
  echo "  [source]:   compiling source file, default is 'main.sample.c' "      1>&2
  echo "  [libsansi]: path for linking 'libsansi….o', default is found it in cwd automatically " 1>&2
  echo "  [-h]: show this usage and exit" 1>&2

  echo "  [-c]: compile for linux by clang" 1>&2
  echo "  [-d]: compile for linux by clang++ with standard c++11" 1>&2
  echo "  [-g]: compile for linux by gcc, this is default" 1>&2
  echo "  [-i]: compile for linux by g++ with standard c++11" 1>&2
  echo "  [-m]: compile for mac by clang" 1>&2

  echo "  [-o obj] set compiled object file name, default is a.out" 1>&2
  exit 1
}

compiler="gcc"
obj="a.out"
std=""

while getopts "hcdgimo:" OPT; do
case "$OPT" in
  h) usage_exit
     ;;
  c) compiler="clang"
     ;;
  d) compiler="clang++"
     std="-std=c++11"
     ;;
  g) compiler="gcc"
     ;;
  i) compiler="g++"
     std="-std=c++11"
     ;;
  m) compiler="clang"
     # use openssl
     export LIBRARY_PATH=$LIBRARY_PATH:/usr/local/opt/openssl/lib/
     ;;
  o) obj="$OPTARG"
     ;;
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
echo "compiler =" $compiler
echo "obj      =" $obj
echo "std      =" $std
echo "compiling…"

#
# compile by clang with your sansi library
#
$compiler $std -o $obj $libsansi $sfile -L . -lssl -lcrypto -lpthread -ldl -lm

#
# strip
#
strip $obj

# @author Dr. Takeyuki UEDA
# @copyright Copyright© Atelier UEDA 2020 - All rights reserved.
