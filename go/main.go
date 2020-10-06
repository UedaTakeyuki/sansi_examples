package main

/*
#cgo LDFLAGS: libsansi.o -L. -lssl -lcrypto -lpthread -ldl -lm
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
