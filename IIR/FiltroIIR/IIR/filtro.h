/* 
 * File:   filtro.h
 * Author: aulasingenieria
 *
 * Created on 4 de abril de 2023, 10:08 AM
 */

#if !defined(FILTRO_H)
#define FILTRO_H

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

#endif	/* FILTRO_H */

