#include "Racional.h"

typedef struct Racional_st
{ long int num;
  long int den;
} Racional_t;

typedef struct Racional_st Racional_t;

void *xmalloc(size_t n)
{
   void *p = malloc(n);
   if(!p) {
      perror("malloc");
      exit(EXIT_FAILURE);
   }
   return p;
}

Racional_pt Cria_racional(long int n, long int d)
{
  Racional_t *r = xmalloc(sizeof(r));
  if((Den_nulo(d))==1) d=1;
  r->num = n;
  r->den = d;
  

  return r;
}


long int Euclides_recursivo (long int a, long int b)
{
  if(a<0) a*=-1;
  if(b<0) b*=-1;
  if (b == 0) return a;
  else return Euclides_recursivo(b, a % b);
}


Racional_pt Simplifica_racional(Racional_pt r)
{
   int MDC = Euclides_recursivo(r->num, r->den);

   r->num /= MDC;
   r->den /= MDC;

  
   return r;
}


Racional_pt Copia_Racional(Racional_pt a,Racional_pt res){
  
  res -> num = a->num;
  res -> den = a-> den;

  return res;
}

bool E_Igual(double a, double b)
{
 
  double eps =  0.00001;
  double diff = a - b;
  return (diff < eps) && (-diff < eps);
}


bool Maior_Que(double a,double b)
{
  
  double eps =  0.00001;
  return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * eps);
}

bool Menor_que(double a, double b)
{
  
  double eps =  0.00001;
  return (a - b) < ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * eps);
}


int Diferenca_Numero (Racional_pt a,Racional_pt b){
  double result_a = (double)a->num/a->den;
  double result_b = (double)b->num/b->den;
  //double eps = 5.96e-08;
  
  double eps =  0.00001;

  if(E_Igual(result_a,result_b)) return 0;
  else if(Maior_Que(result_a,result_b)) return 1;
  else return -1;


}

Racional_pt Soma_racional(Racional_pt a, Racional_pt b, Racional_pt res)
{


  res->num = (a->num * b->den) + (b->num * a->den);
  res->den = a->den* b->den;

  return Simplifica_racional(res);
}

Racional_pt Subtrai_racional(Racional_pt a, Racional_pt b, Racional_pt res)
{
   

  res->num = (a->num * b->den) - (b->num * a->den);
  res->den = a->den * b->den;

  return Simplifica_racional(res);
}

Racional_pt Dividi_racional(Racional_pt a, Racional_pt b, Racional_pt res)
{
   

  res->num = a->num * b->den;
  res->den = a->den * b->num;
   

  return Simplifica_racional(res);
}


Racional_pt Multiplica_racional(Racional_pt a, Racional_pt b, Racional_pt res)
{
   

  res->num = a->num * b->num;
  res->den = a->den * b->den;

  return Simplifica_racional(res);
}


Racional_pt Quadrado(Racional_pt a, Racional_pt res){


  res -> num = a -> num * a -> num;
  res-> den = a -> den * a -> den;

  return Simplifica_racional(res);

}


Racional_pt AcumulaSoma_racional(Racional_pt a, Racional_pt b){
  

   a->num = (a->num * b->den) + (b->num * a->den);
   a->den = a->den* b->den;

   return Simplifica_racional(a);
}

Racional_pt AcumulaMulti_racional(Racional_pt a, Racional_pt b){

  a->num = a->num * b->num;
  a->den = a->den * b->den;

  return Simplifica_racional(a);
}

double ConverteDouble_racional(Racional_pt r){
  double result = (double)r->num/r->den;
  return result;
}

double RaizD_newton(Racional_pt a) {
  double resultado = ConverteDouble_racional(a);
  double y = GUESS;  
  if(Num_nulo(a->num)==1){
    return 0;
  }
  else{
    for (int x = 1; x <= 10; x++)    {        
     y = y - ((y*y - resultado) / (2.0 * y));    
    } 
  
    return y;
  }
   
}

int Equivalentes(Racional_pt a, Racional_pt b){
  a = Simplifica_racional(a);
  b = Simplifica_racional(b);

  if((a -> num == b -> num) && (a -> den == b -> den)) return 1;

  return 0;
}

int Den_nulo(long int denominador){

  if(denominador == 0)  return 1;
   
  return 0;
}

int Num_nulo(long int numerador){

  if(numerador == 0)  return 1;
   
  return 0;
}

int Racional_nulo(Racional_pt r){
  if(Den_nulo(r -> den)==0 && Num_nulo(r -> num) == 0) return 1;

  return 0;
}


int gcfFinder(int a, int b)
{ 
    int gcf = 1;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcf = i;
        }
    }
    return gcf;
}


int shortform(long int* a, long int* b)
{
    for (int i = 2; i <= *a && i <= *b; i++)
    {
        if (*a % i == 0 && *b % i == 0)
        {
            *a = *a / i;
            *b = *b / i;
        }
    }
    return 0;
}

Racional_pt ConverteR_double(double a, Racional_pt res){
 
    long int c = 1000;
    double b = (a - floor(a)) * c;
    long int d = (int)floor(a) * c + (int)(b + .5f);
 
    while (1)
    {
        if (d % 10 == 0)
        {
            d = d / 10;
            c = c / 10;
        }
        else
            break;
    }
    long int* i = &d;
    long int* j = &c;
    int t = 0;
    while (t != 1)
    {
        int gcf = Euclides_recursivo(d, c);
        if (gcf == 1)
        {
            
            t = 1;
        }
        else
        {
            shortform(i, j);
        }
    }
  
  res->num=d;
  res->den=c;
  return res;
    
}


void Destroi_racional(Racional_pt r){
  free(r);
}


void Escreve_Racional(FILE *saida, Racional_pt r){
	if(saida==NULL){
		puts("Ponteiro Nulo");
		exit(1);
	}
	int close=0;
	if(saida==NULL){
		saida = fopen("./racional.txt", "w");
		close=1;
	}
	fprintf(saida, "%ld,%ld,", r->num, r->den);
	if(close){
		fclose(saida);
	}
}

Racional_pt Ler_Racional(FILE *entrada, Racional_pt r){
	if(r==NULL){
		puts("Racional Nulo");
		exit(1);
	}
	if(entrada==NULL){
		puts("Ponteiro Nulo");
		exit(1);
	}
	long int num, den;
	char blank[10];
	fscanf(entrada, "%ld%[^0-9+-]s", &num, blank);
	fscanf(entrada, "%ld,", &den);
	if(!den){
		if(!num){
			return r;
		}
		else
			den=1;
	}
	r->num = num;
  r-> den = den;
	return r;
}
 