#include "sansi.h"  // for sansi libraries

#include <stdio.h>  // for printf
#include <unistd.h> // for seep
void tenseccount();

int main(){

  if (ok_confirmed == confirm(NULL, NULL, NULL)){
    printf("OK\n");
    tenseccount();
  } else {
    printf("NG\n");
  }
  return 0;
}

void tenseccount(){
  int i;
  printf("start 10 second countdown\n");
  for (i=10; i>0; i--){
    printf("%d\n",i);
    sleep(1);
  }
  printf("0!\n");
}
