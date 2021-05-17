#ifndef RACIONAL_H
#define RACIONAL_H
#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define GUESS 10
#define PI 3.141592654


typedef struct Racional_st *Racional_pt;

void *xmalloc(size_t n);

Racional_pt Cria_racional(long int n, long int d);

long int Euclides_recursivo (long int a, long int b);

Racional_pt Simplifica_racional(Racional_pt r);

Racional_pt Copia_Racional(Racional_pt a, Racional_pt res);

int Compara_Racional(Racional_pt a, Racional_pt b);

Racional_pt Soma_racional(Racional_pt a, Racional_pt b, Racional_pt res);

Racional_pt Subtrai_racional(Racional_pt a, Racional_pt b, Racional_pt res);

Racional_pt Dividi_racional(Racional_pt a, Racional_pt b, Racional_pt res);

Racional_pt Multiplica_racional(Racional_pt a, Racional_pt b, Racional_pt res);

Racional_pt Quadrado(Racional_pt a, Racional_pt res);

Racional_pt AcumulaSoma_racional(Racional_pt a, Racional_pt b);

Racional_pt AcumulaMulti_racional(Racional_pt a, Racional_pt b);

double ConverteDouble_racional(Racional_pt r);

double RaizD_newton(Racional_pt a);

int Equivalentes(Racional_pt a, Racional_pt b);

int Den_nulo(long int denominador);

int Num_nulo(long int numerador);

int Racional_nulo(Racional_pt r);

int gcfFinder(int a, int b);

int shortform(long int* a, long int* b);

Racional_pt ConverteR_double(double a, Racional_pt res);

void Destroi_racional(Racional_pt r);

void Escreve_Racional(FILE *saida, Racional_pt r);

Racional_pt Ler_Racional(FILE *entrada, Racional_pt r);
#endif