# 1 "cola.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v6.05/packs/Microchip/PIC18F-K_DFP/1.7.134/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "cola.c" 2
# 1 "./cola.h" 1




typedef unsigned char DATOCOLA;
# 14 "./cola.h"
typedef struct eCola {
   DATOCOLA data[15];
   int entrada;
   int salida;
   int peso;
} eCola;


void inicie_cola(eCola* c);

char cola_add(eCola* c,DATOCOLA dato);

DATOCOLA cola_get(eCola* c);

int tam_cola(eCola* c);

int cola_llena(eCola* c);

int cola_vacia(eCola* c);
# 1 "cola.c" 2


void inicie_cola(eCola* c)
{
    c->entrada=0;
    c->salida=0;
    c->peso=0;
}
# 18 "cola.c"
char cola_add(eCola* c,DATOCOLA dato)
{




    if(!cola_llena(c)){
        c->data[c->entrada]=dato;
        c->entrada++;
        c->peso++;
    }
    else
    {
        return 1;
    }


    if (c->entrada >=15)
        c->entrada=0;
    return 0;



}

DATOCOLA cola_get(eCola* c)
{



    DATOCOLA temp;
    if(!cola_vacia(c)){
        temp=c->data[c->salida];
        c->salida++;
        c->peso--;
    }
    else
    {
        return 1;
    }


    if (c->salida >=15)
        c->salida=0;
    return temp;





}

int tam_cola(eCola* c){
    return (c->peso);
}


int cola_llena(eCola* c){
    if (c->peso>=15){
        return 1;
    }
    else{
        return 0;
    }
}


int cola_vacia(eCola* c)
{
    if (c->peso<=0){
        return 1;
    }
    else{
        return 0;
    }
}
