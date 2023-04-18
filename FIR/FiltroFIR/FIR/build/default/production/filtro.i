# 1 "filtro.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v6.05/packs/Microchip/PIC18F-K_DFP/1.7.134/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "filtro.c" 2
# 1 "./filtro.h" 1
# 11 "./filtro.h"
int filtrar_dato(long in);
# 1 "filtro.c" 2
# 32 "filtro.c"
 const char B[31] = {
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       6, 26, 58, 76, 58, 26, 6, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0
 };



volatile int x[31];
volatile int k=0;
volatile int q = 1;

int filtrar_dato(long in)
{
  int i = 0;
  x[k] = in;
  int inx = k;
  int anx = q;
  char *apuntadorcoef = &B[0];
  int *apuntadorarrc = &x[inx];
  int *apuntadorinv = &x[anx];


  long y = 0;
  for (i = 0; i < (int)(31/2); ++i) {
    y += (long)(*apuntadorcoef) * ((long)(*apuntadorarrc) + (long)(*apuntadorinv));
    apuntadorcoef++;
    if (inx != 0) {
      apuntadorarrc--;
      inx--;
    }
    else {
      apuntadorarrc = &x[31 - 1];
      inx = 31 - 1;
    }
    if (anx != 31 -1){
        apuntadorinv++;
        anx++;
    }
    else{
    apuntadorinv = &x[0];
    anx = 0;
    }
  }
  if(31 % 2 == 1){
      y += (long)(*apuntadorcoef) * ((long)(*apuntadorarrc));
  }
  k++;
  q++;
  k = (k >= 31) ? 0 : k;
  q = (q >= 31) ? 0 : q;
  return y>>8;
}
