#include "utils.h"

int javaByteArrayToInt (char *bytes) {
  char temp = bytes[0];
  bytes[0] = bytes[3];
  bytes[3] = temp;
  temp = bytes[1];
  bytes[1] = bytes[2];
  bytes[2] = temp;
  int x = *((int *)bytes);
  return x;
}

char javaByteArrayToChar (char *bytes) {
   return bytes[1];
}

void* intToVoidPointer (int x) {
   void *p = &x;
   return p;
}