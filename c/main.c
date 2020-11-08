/*
* example how to use sansi
* 
* @author Dr. Takeyuki UEDA
* @copyright Copyright© Atelier UEDA 2020 - All rights reserved.
*/

#include <stdio.h>
#include "sansi.h"

int main(){

  version(); /* sho version of sansi */
  if (ok_confirmed == confirm(NULL, NULL, NULL)){
    printf("OK\n");
  } else {
    printf("NG\n");
  }
  return 0;
}
