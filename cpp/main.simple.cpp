#include <iostream>

extern "C"{
  #include "sansi.h"
}

#include <stdio.h>  // for printf
#include <unistd.h> // for seep
void tenseccount();

int main(){
  if (ok_confirmed == confirm(nullptr, nullptr, nullptr)){
    std::cout << "OK\n";
  } else {
    std::cout << "NG\n";
    return -1;
  }

  tenseccount();
  return 0;
}//

void tenseccount(){
  int i;
  printf("start 10 second countdown\n");
  for (i=10; i>0; i--){
    printf("%d\n",i);
    sleep(1);
  }
  printf("0!\n");
}
