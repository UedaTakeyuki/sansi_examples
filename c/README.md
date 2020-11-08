# A C version sample of how to protect your application from copying

This is a C version sample project of how to  protect your application with **sansi** from copying.
The sansi is a license manager library for Linux (x86 and ARM) and Mac, it provides an out-of-the-box copy protection feature to your application running on these.
The sansi embedded in your application can be operated through the Koshinto Service. You can download the Sansi library from your account of Koshinto, and perform all operations such as setting and changing keys from your mobile device through Koshinto's web interface.

## How to use.

1. Download a sansi library file **libsansi_[bind_id]_[target arch]_[version].o** from your account of koshinto to here.
2. build main.simple.c as follows:
  - Linux with gcc: ```./compile.sh -g```
  - Linux with clang: ```./compile.sh -c```
  - mac: ```./compile.sh -m```
  - show usage ```./compile.sh -h```
3. run built **sansi** file.
