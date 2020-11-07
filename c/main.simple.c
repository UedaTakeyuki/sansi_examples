#include <stdio.h>
#include "sansi.h"

int main(){

  if (ok_confirmed == confirm(NULL, NULL, NULL)){
    printf("OK\n");
  } else {
    printf("NG\n");
  }
  return 0;
}
