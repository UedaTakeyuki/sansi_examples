#include <stdio.h>
#include "sansi.h"

int main(){

  version();
  if (confirm()){
    printf("OK\n");
  } else {
    printf("NG\n");
  }
  return 0;
}
