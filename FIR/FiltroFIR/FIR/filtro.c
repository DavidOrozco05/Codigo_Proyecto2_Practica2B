#include "filtro.h"
/*
#define BL 8
const unsigned char B[8] = {
     0,   -3,    1,   66,   66,    1,   -3,    0
};
 */
//
//#define BL 12
//const unsigned char B[12] = {
//      0,    1,    5,   19,   42,   62,   62,   42,   19,    5,    1,    0
//};
 

/*
#define BL 18
const char B[18] = {
      0,    0,   -1,   -2,   -2,    5,   22,   45,   63,   63,   45,   22,
      5,   -2,   -2,   -1,    0,    0
};*/



// #define BL 31
//const unsigned char B[31] = {
//      4,    5,    1,   -5,   -7,   -3,    5,   10,    6,   -5,  -15,  -14,
//      5,   36,   65,   77,   65,   36,    5,  -14,  -15,   -5,    6,   10,
//      5,   -3,   -7,   -5,    1,    5,    4
//}; 


volatile int x[BL];
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
  // mucho cuidado con el tamaño de los apuntadores DEBE COINCIDIR CON EL DEL ARREGLO o no va a funcionar.
  
  long y = 0;
  for (i = 0; i < (int)(BL/2); ++i) {
    y += (long)(*apuntadorcoef) * ((long)(*apuntadorarrc) + (long)(*apuntadorinv));// verifique que para su filtro no exista overflow.
    apuntadorcoef++;
    if (inx != 0) {
      apuntadorarrc--;
      inx--;
    }
    else {
      apuntadorarrc = &x[BL - 1];
      inx = BL - 1;
    }
    if (anx != BL -1){
        apuntadorinv++;
        anx++;
    }
    else{
    apuntadorinv = &x[0];
    anx = 0;
    }
  }
  if(BL % 2 == 1){
      y += (long)(*apuntadorcoef) * ((long)(*apuntadorarrc));
  }
  k++;
  q++;
  k = (k >= BL) ? 0 : k;
  q = (q >= BL) ? 0 : q;
  return y>>8; //si no es multiplo de 2^n divida por el factor de normalización adecuado a su filtro.
}
