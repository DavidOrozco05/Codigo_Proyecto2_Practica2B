#include "filtro.h"

void inicializar_IIR(float*num, float*den, float*w, float k, struct_filtro* ir)
{
  for (int i = 0; i < 3; i++) {
    ir->num[i] = num[i];
    ir->den[i] = den[i];
    ir->w[i] = w[i];
    ir->k = k;
  }  
}

    float filtrar_dato(struct_filtro* ir, float in)
{
  ir->w[0] = (ir->den[0]*in*ir->k) - (ir->den[1]*ir->w[1]) - (ir->den[2] * ir->w[2]);
  //ir->w[0] = ( (1/(ir->den[0])) * ( (in*(ir->k)) - ((ir->den[1]) * (ir->w[1])) - ((ir->den[2]) * (ir->w[2])) ) ); // OJO QUE EL MENOS YA ESTA EN LA ECUACION ver en  la ayuda de filterDesign en "show filter structure" si esta es o no la ecuación que implementan en ese software
  ir -> y = ((ir->num[0] * ir->w[0]) + (ir->num[1] * ir->w[1]) + (ir->num[2] * ir->w[2]));
  ir->w[2] = ir->w[1];//debe ser primero este
  ir->w[1] = ir->w[0];// y luego este para no sobreescribir
  return ir ->y;    
}//si no es multiplo de 2^n divida por el factor de normalización adecuado a su filtro.

