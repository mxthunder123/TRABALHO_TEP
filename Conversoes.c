#include "Conversoes.h"


// struct de complexos de inteiros
typedef struct I_Complexo_st
{
long int * real;
long int * imag;
}I_Complexo_t;



// struct de complexos de double
typedef struct D_Complexo_st
{
double * real;
double * imag;
}D_Complexo_t;



// struct de complexos de racionais
typedef struct R_Complexo_st
{
Racional_pt  real;
Racional_pt  imag;
}R_Complexo_t;



// Funcao que converte complexo de inteiro em complexo de double
D_Complexo_pt I_Converte_D(I_Complexo_pt c, D_Complexo_pt res){

  double a,b,*pta,*ptb;
  a=(double)*c->real;
  b=(double)*c->imag;
  pta=xmalloc(a);
  ptb=xmalloc(b);
  *pta=a;
  *ptb=b;

  *res->imag=*ptb;
  *res->real=*pta;
  free(pta);
  free(ptb);

  return res;
}

// Funcao que converte complexo de double em complexo de inteiro
I_Complexo_pt D_Converte_I(D_Complexo_pt c, I_Complexo_pt res){

  double a,b;
  long int *pta,*ptb;
  a = *c->real;
  b = *c ->imag;
  
  if(a - (int)*c->real >=0.5) a = ceil(a);
  else a = floor(a);
  if(b - (int)*c->imag >=0.5) b = ceil(b);
  else b = floor(b);
 
  pta=xmalloc(a);
  ptb=xmalloc(b);
  *pta=a;
  *ptb=b;
 
  *res->real=*pta;
  *res -> imag = *ptb;
  free(pta);
  free(ptb);
  return res; 
}

// funcao que converte Complexo de racional em complexo de double
D_Complexo_pt R_Converte_D(R_Complexo_pt r){
  D_Complexo_t *b = xmalloc(sizeof(b));
  b->real=xmalloc(sizeof(b->real));
  b -> imag =xmalloc(sizeof(b->imag));

  double *result1, *result2;
  *result1 = ConverteDouble_racional(r->real);
  *result2 = ConverteDouble_racional(r->imag);

  memcpy(b->real,result1, sizeof(*b));
  memcpy(b->imag, result2, sizeof(*b));


 return b;
}

// funcao que converte complexo de double em complexo de racional
R_Complexo_pt D_Converte_R(D_Complexo_pt a ){
  R_Complexo_t *b = xmalloc(sizeof(b));
  b->real=xmalloc(sizeof(b->real));
  b -> imag =xmalloc(sizeof(b->imag));
 
  memcpy(b->real, ConverteR_double(*a->real,b->real), sizeof(*b));
  memcpy(b->imag, ConverteR_double(*a->imag,b->imag), sizeof(*b));

  return b;
}

// funcao que converte comlexo de racional em complexo de inteiro
I_Complexo_pt R_Converte_I(R_Complexo_pt r){
  double *result1,*result2,a,b;
  long int *pta,*ptb;

  result1=xmalloc(sizeof(result1));
  result2=xmalloc(sizeof(result2));
  *result1 = ConverteDouble_racional(r->real);
  *result2 =  ConverteDouble_racional(r->imag);
  a = *result1;
  b = *result2;
  if(a - (int)*result1 >=0.5) a = ceil(a);
  else a = floor(a);
  if(*result2 - (int)*result2 >=0.5) b = ceil(*result2);
  else b = floor(*result2);
  pta=xmalloc(sizeof(a));
  ptb=xmalloc(sizeof(b));
  *pta = a;
  *ptb = b;
  I_Complexo_t *i = xmalloc(sizeof(i));
  i->real= xmalloc(sizeof(i->real));
  i -> imag = xmalloc(sizeof(i->imag));
  memcpy(i->real,pta, sizeof(*i));
  memcpy(i->imag, ptb, sizeof(*i));
  free(result1);
  free(result2);
  free(pta);
  free(ptb);
  return i;
}


//funcao que converte complexo de inteiro em complexo de racional
R_Complexo_pt I_Converte_R(I_Complexo_pt i){
  
  R_Complexo_pt res = xmalloc(sizeof(res));
  res->imag = xmalloc(sizeof(res->imag));
  res->real = xmalloc(sizeof(res->real));
  Racional_pt r1=Cria_racional(*i->real, 1);
  Racional_pt r2 = Cria_racional(*i->imag,1);
  memcpy(res->real,r1, sizeof(*res));
  memcpy(res->imag,r2, sizeof(*res));

  Destroi_racional(r1);
  Destroi_racional(r2);
  
  return res;
    
}

// funcao para modificar o angulo de um complexo de racional
R_Complexo_pt Modificar_Angulo(R_Complexo_pt a,double angulo){
  double moduloI = R_Calcula_Modulo(a);
  D_Complexo_pt d = xmalloc(sizeof(d));
  d->imag=xmalloc(sizeof(d->imag));
  d->real = xmalloc(sizeof(d->real));
  double *pta,*ptb;
  
  *pta = moduloI*sin(angulo);
  *ptb = moduloI*cos(angulo);

  *d->imag=*ptb;
  *d->real=*pta;
  a = D_Converte_R(d);
 
  
  return a;


  
}

// funcao para modificar o modulo de um complexo de racionais
R_Complexo_pt Modificar_Modulo(R_Complexo_pt a, double modulo){
  double FaseI = R_Angulo(a);
  D_Complexo_pt d = xmalloc(sizeof(d));
  d->imag=xmalloc(sizeof(d->imag));
  d->real = xmalloc(sizeof(d->real));
  double *pta,*ptb;
  
  *pta = modulo*sin(FaseI);
  *ptb = modulo*cos(FaseI);
 
  *d->imag=*ptb;
  *d->real=*pta;
  a = D_Converte_R(d);

  return a;


  
}