package main

/*
//#cgo LDFLAGS: -L. -lssl -lcrypto -lpthread -ldl -lm -lsansi_ZbPdGoGyrNkQ
#cgo LDFLAGS: -L. -lssl -lcrypto -lpthread -ldl -lm -lsansi
#include <sansi.h>
#include <stdbool.h>
*/
import "C"

import (
	"log"
)

func main() {
	if C.confirm() {
		log.Println("OK!")
	} else {
		log.Println("NG!")
	}
}
