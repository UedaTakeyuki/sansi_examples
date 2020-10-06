package main

/*
#cgo LDFLAGS: libsansi_BLpXZoWArNWy_mac_v1.1.o -L. -lssl -lcrypto -lpthread -ldl -lm
#include <sansi.h>
#include <stdbool.h>
*/
import "C"

import (
	"log"
)

func main() {
	if C.confirm(nil, nil, nil) {
		log.Println("OK!")
	} else {
		log.Println("NG!")
	}
}
