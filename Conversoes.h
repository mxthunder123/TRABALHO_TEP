#ifndef CONVERSOES_H
#define CONVERSOES_H

#include "Racional.h"
#include "Racional_Complexo.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct I_Complexo_st I_Complexo_t;
typedef struct D_Complexo_st D_Complexo_t;
typedef struct R_Complexo_st R_Complexo_t;
typedef struct R_Complexo_st *R_Complexo_pt;
typedef struct I_Complexo_st *I_Complexo_pt;
typedef struct D_Complexo_st *D_Complexo_pt;


D_Complexo_pt I_Converte_D(I_Complexo_pt c, D_Complexo_pt res);


I_Complexo_pt D_Converte_I(D_Complexo_pt c, I_Complexo_pt res);

D_Complexo_pt R_Converte_D(R_Complexo_pt r);

R_Complexo_pt D_Converte_R(D_Complexo_pt a ;

I_Complexo_pt R_Converte_I(R_Complexo_pt r);

R_Complexo_pt I_Converte_R(I_Complexo_pt i);

R_Complexo_pt Modificar_Angulo(R_Complexo_pt a,double angulo);

R_Complexo_pt Modificar_Modulo(R_Complexo_pt a, double modulo);

#endif