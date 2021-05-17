#ifndef RACIONAL_COMPLEXO_H
#define RACIONAL_COMPLEXO_H

#include "Racional.h"



typedef struct R_Complexo_st *R_Complexo_pt;


R_Complexo_pt R_Cria_Racional(long int real1, long int imag1,long int real2,long int imag2);

void R_Destroi_Complexo(R_Complexo_pt r);

R_Complexo_pt  R_Atribui_Complexo(R_Complexo_pt a,R_Complexo_pt b);

R_Complexo_pt R_AtribuiN_Complexo(R_Complexo_pt b );

int Eh_Igual(double a, double b);

int Eh_Maior(double a, double b);

int Eh_Menor(double a,double b);

int R_Modulo (R_Complexo_pt a,R_Complexo_pt b);

int R_Angulo_D (R_Complexo_pt a,R_Complexo_pt b);

double R_Calcula_Modulo(R_Complexo_pt r,...);

int R_Compara_ModuloN(R_Complexo_pt r);

int R_Compara_ImagNu(R_Complexo_pt r);

int R_Compara_Modulo(R_Complexo_pt r);

int R_Compara_RealN(R_Complexo_pt r);

double R_Angulo(R_Complexo_pt r);

R_Complexo_pt R_Calcula_Conjugado(R_Complexo_pt r);

R_Complexo_pt R_Soma(R_Complexo_pt a, R_Complexo_pt b);

R_Complexo_pt R_SomaA(R_Complexo_pt a, R_Complexo_pt b);

R_Complexo_pt R_Subtrae(R_Complexo_pt a, R_Complexo_pt b);

R_Complexo_pt R_Multiplica(R_Complexo_pt a, R_Complexo_pt b);

R_Complexo_pt R_MultiplicaA(R_Complexo_pt a, R_Complexo_pt b);

R_Complexo_pt R_Divide(R_Complexo_pt dividendo, R_Complexo_pt divisor, R_Complexo_pt quociente);

R_Complexo_pt R_OperacaoComplexo(R_Complexo_pt num1, R_Complexo_pt num2, char * oper);


#endif