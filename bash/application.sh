#!/bin/bash
#
#
#

# If the file "a" does not exist, it is regarded as tampering, exited.
if [ ! -f ./a  ] ; then
  echo "NG: exit"
  exit 1
fi

# If the return value of "a" is not 1, exited
if [ `./a` -ne 1 ]; then
  echo "NG: exit"
  exit 1
fi

echo "OK:running"
# The process you want continues below…
