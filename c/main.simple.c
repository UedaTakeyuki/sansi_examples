/*
* 10 second countdown, copy guarded by sansi
* 
* @author Dr. Takeyuki UEDA
* @copyright Copyright© Atelier UEDA 2020 - All rights reserved.
*/

#include "sansi.h"  // for sansi libraries

#include <stdio.h>  // for printf
#include <unistd.h> // for seep
void tenseccount();

int main(){

  if (ok_confirmed == confirm(NULL, NULL, NULL)){
    printf("OK\n");
  } else {
    printf("NG\n");
    return -1;
  }

  tenseccount();
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
