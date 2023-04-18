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
typedef struct struct_filtro{
    float w[3];
    float den[3];
    float num[3];
    float k;
    float in;
    float y;
    char termino_conversion;
}struct_filtro;

void inicializar_IIR(float*num,float*den,float*w,float k, struct_filtro* ir);
float filtrar_dato(struct_filtro*, float in);
# 1 "filtro.c" 2


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

  ir -> y = ((ir->num[0] * ir->w[0]) + (ir->num[1] * ir->w[1]) + (ir->num[2] * ir->w[2]));
  ir->w[2] = ir->w[1];
  ir->w[1] = ir->w[0];
  return ir ->y;
}
