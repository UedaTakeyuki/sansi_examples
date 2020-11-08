/*
* Header file for sansi
* 
* @author Dr. Takeyuki UEDA
* @copyright Copyright© Atelier UEDA 2020 - All rights reserved.
*/
#ifndef _SANSI_H_
#define _SANSI_H_

void version();
int confirm(char *substitutebid, char *secretstring, char *safekeepedkey);

typedef enum {
  ng_comfirmed   = 0,
  ok_confirmed   = 1,
  error_network  = -1,
  error_internal = -2,

} error_cause;

#endif
