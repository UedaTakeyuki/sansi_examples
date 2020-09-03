#include <stdio.h>
#include "sansi.h"

int main(){

  if (confirm()){
    printf("OK\n");
  } else {
    printf("NG\n");
  }
  return 0;
}
