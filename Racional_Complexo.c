#include "Racional_Complexo.h"


#define PI 3.141592654

typedef struct R_Complexo_st
{
Racional_pt  real;
Racional_pt  imag;
} R_Complexo_t;

typedef struct R_Complexo_st  R_Complexo_t;

// Funcao para criar um complexo de racional recebendo parametros 
R_Complexo_pt R_Cria_Racional(long int real1,long int imag1,long int real2,  long int imag2){
  R_Complexo_t *r = xmalloc(sizeof(r));
  Racional_pt a,b;
  a= Cria_racional(real1, imag1);
  b = Cria_racional(real2,imag2);
  r->real = a;
  r->imag = b;

  return r;
}

// Funcao para criar complexo de racional recebendo 2 parametros
R_Complexo_pt R_Cria_Racional_2(Racional_pt real, Racional_pt imag){
  R_Complexo_t *r = xmalloc(sizeof(r));
  r->real = real;
  r->imag = imag;

  return r;
}
// funcao para destruir complexo de racional
void R_Destroi_Complexo(R_Complexo_pt r){
  free(r->real);
  free(r->imag);
  free(r);
}

// funcao para Atribuir uum complexo a um complexo já existente
R_Complexo_pt  R_Atribui_Complexo(R_Complexo_pt a,R_Complexo_pt b){
  memcpy(a->real, b->real, sizeof(*b));
  memcpy(a->imag, b->imag, sizeof(*b));
  return a;
}

// funcao para atribuir um complexo a um complexo ainda não criado
R_Complexo_pt R_AtribuiN_Complexo(R_Complexo_pt b){
  R_Complexo_t *r = R_Cria_Racional(0, 0, 0, 0);
  memcpy(r->real, b->real, sizeof(*b));
  memcpy(r->imag, b->imag, sizeof(*b));
  
 
  return r;
}

// funcao para avaliar se a e igual a b
int Eh_Igual(double a, double b){
  double diff;
  
  diff=a-b;

  double eps =  0.00001;
  
  return (diff < eps) && (-diff < eps);

}

// funcao para avaliar se a e maior que b
int Eh_Maior(double a, double b){

  double eps =  0.00001;
  return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * eps);

}

// funcao para determinar se a e menor que b
int Eh_Menor(double a,double b){
  
  double eps =  0.00001;
  
  return (a - b) < ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * eps);

}

// funcao para determinar modulo de a e maior , igual ou menor que modulo de b
int R_Modulo (R_Complexo_pt a,R_Complexo_pt b){
  double m1,m2;
  m1 = R_Calcula_Modulo(a);
  m2 =  R_Calcula_Modulo(b);
  
  double eps =  0.00001;

  if(Eh_Igual(m1,m2)) return 0;
  else if(Eh_Maior(m1,m2)) return 1;
  else return -1;


}
// funcao para determinar se angulo de A e maior, igual, ou menor que angulo de b
int R_D_Angulo (R_Complexo_pt a,R_Complexo_pt b){
  double a1,a2;
  a1 = R_Angulo(a);
  a2 =  R_Angulo(b);
  
  double eps =  0.00001;

  if(Eh_Igual(a1,a2)) return 0;
  else if(Eh_Maior(a1,a2)) return 1;
  else return -1;


}



// funcao para calcular modulo
double R_Calcula_Modulo(R_Complexo_pt r,...){
  double modulo,real,imag;
  real = ConverteDouble_racional(r->real);
  imag = ConverteDouble_racional(r->imag);
  double y= GUESS;
  double eps =  5.96e-08;
  modulo=(pow(real, 2) + pow(imag,2));
  if(modulo==0.0000){
    return 0;
  }
  else{
    for (int x = 1; x <= 10; x++)    {        
     y = y - ((y*y - modulo) / (2.0 * y));    
    }

    return y;
  } 
}

// funcao para determinar se modulo e nulo
int R_Compara_ModuloN(R_Complexo_pt r){
  double y;
  double eps =  5.96e-08;
  y = R_Calcula_Modulo(r);

  return fabs(y/eps) < eps;
}

// funcao para deterniamr se parte imaginaria e nula
int R_Compara_ImagN(R_Complexo_pt r){
  double eps =  5.96e-08;
  double imag,real;
   imag = ConverteDouble_racional(r->imag);

  return fabs(imag/eps) < eps;
}


int R_Compara_Modulo(R_Complexo_pt r){
  double modulo = R_Calcula_Modulo(r);
  double eps =  5.96e-08;

  return fabs(modulo/eps) <eps;
}


// funcao para determinar se parte real e nula
int R_Compara_RealN(R_Complexo_pt r){
  double eps =  5.96e-08;
  double imag,real;

  real= ConverteDouble_racional(r->real);
  return fabs(real/eps) < eps;
}


// funcao para calcular o angulo
double R_Angulo(R_Complexo_pt r){

  double ang,div;
  double imag,real;
  imag = ConverteDouble_racional(r->imag);
  real= ConverteDouble_racional(r->real);
  ang = atan2(imag,real);
  ang = ang * 180 / PI;
  return ang;
}


// funcao que retorna a parte imaginaria 
Racional_pt R_Retorna_Imag(R_Complexo_pt r){
  return r->imag;
}

// funcao que retorna a parte real
Racional_pt R_Retorna_Real(R_Complexo_pt r){
  return r->real;
}

//funcao para atribuir um novo valor a parte imaginaria
R_Complexo_pt R_Atribui_ImagN(R_Complexo_pt r, long int a, long int b){
  Racional_pt  res = Cria_racional(a, b);
  memcpy(r->imag, res, sizeof(*r));
  Destroi_racional(res);
  return r;
}

// funcao para atrivuir um novo valor a parte real
R_Complexo_pt R_Atribui_RealN(R_Complexo_pt r, long int a, long int b){
  Racional_pt  res = Cria_racional(a, b);
  memcpy(r->real, res, sizeof(*r));
  Destroi_racional(res);
  return r;
}



// funcao para calcular o conjugado
R_Complexo_pt R_Calcula_Conjugado(R_Complexo_pt r){
  
  Racional_pt res = Cria_racional(-1, 1);
  
  memcpy(r->imag, Soma_racional(r->imag, res,r->imag), sizeof(*r));
  Destroi_racional(res);

  return r;
  
}

// funcao para somar dois complexos racionais
R_Complexo_pt R_Soma(R_Complexo_pt a, R_Complexo_pt b){
  R_Complexo_t *res = xmalloc(sizeof(res));
  res -> imag=xmalloc(sizeof(res->imag));
  res -> real=xmalloc(sizeof(res->real));
  memcpy(res->real, Soma_racional(a->real,b->real,res->real), sizeof(*res));
  memcpy(res->imag, Soma_racional(a->imag,b->imag,res->imag), sizeof(*res));

  return res;
}

// soma acumulativa de complexos racionais
R_Complexo_pt R_SomaA(R_Complexo_pt a, R_Complexo_pt b){
  memcpy(a->real, AcumulaSoma_racional(a->real,b->real), sizeof(*a));
  memcpy(a->imag, AcumulaSoma_racional(a->imag,b->imag), sizeof(*a));

  return a;

}

// subtracao de dois complexos racionais
R_Complexo_pt R_Subtrae(R_Complexo_pt a, R_Complexo_pt b){
  R_Complexo_t *res = xmalloc(sizeof(res));
  res -> imag=xmalloc(sizeof(res->imag));
  res -> real=xmalloc(sizeof(res->real));
  memcpy(res->real, Subtrai_racional(a->real,b->real,res->real), sizeof(*res));
  memcpy(res->imag, Subtrai_racional(a->imag,b->imag,res->imag), sizeof(*res));

  return res;
}

// multiplicacao de dois complexos racionais
R_Complexo_pt R_Multiplica(R_Complexo_pt a, R_Complexo_pt b){
  R_Complexo_t *res = xmalloc(sizeof(res));
  res -> imag=xmalloc(sizeof(res->imag));
  res -> real=xmalloc(sizeof(res->real));

  R_Complexo_t *resI = xmalloc(sizeof(resI));
  resI -> imag=xmalloc(sizeof(resI->imag));
  resI -> real=xmalloc(sizeof(res->real));

  memcpy(res ->real,Subtrai_racional( Multiplica_racional(a->real,b->real,resI->real), Multiplica_racional(a->imag,b->imag,resI->imag) ,res->real),sizeof(*res));
  R_Destroi_Complexo(resI);

  R_Complexo_t *resI2 = xmalloc(sizeof(resI2));
  resI2 -> imag=xmalloc(sizeof(resI2->imag));
  resI2 -> real=xmalloc(sizeof(resI2->real));

  memcpy(res ->imag,Soma_racional( Multiplica_racional(a->real,b->imag,resI2->real), Multiplica_racional(a->imag,b->real,resI2->imag) ,res->imag),sizeof(*res));

  R_Destroi_Complexo(resI2);

  return res;



}
// multiplicacao acumulativa de compexos racionais
R_Complexo_pt R_MultiplicaA(R_Complexo_pt a, R_Complexo_pt b){

  R_Complexo_t *resI = xmalloc(sizeof(resI));
  resI -> imag=xmalloc(sizeof(resI->imag));
  resI -> real=xmalloc(sizeof(resI->real));

  R_Complexo_t *resII = xmalloc(sizeof(resII));
  resII -> imag=xmalloc(sizeof(resII->imag));
  resII -> real=xmalloc(sizeof(resII->real));
  memcpy( resII -> imag, a->imag,sizeof(*resII));
  memcpy( resII -> real, a->real,sizeof(*resII));

  memcpy(a->real, Subtrai_racional(Multiplica_racional(a->real,b->real,resI->real), Multiplica_racional(a->imag,b->imag,resI->imag),a->real), sizeof(*a));

  

  R_Complexo_t *resI2 = xmalloc(sizeof(resI2));
  resI2 -> imag=xmalloc(sizeof(resI2->imag));
  resI2 -> real=xmalloc(sizeof(resI2->real));
  

  memcpy(a->imag, Soma_racional(Multiplica_racional(resII->real,b->imag,resI2->imag), Multiplica_racional(resII->imag,b->real,resI2->real),resII->imag), sizeof(*a));
  R_Destroi_Complexo(resI);
  R_Destroi_Complexo(resI2);
  R_Destroi_Complexo(resII);

  return a;
}

// divisao de complexos racioanais
R_Complexo_pt R_Divide(R_Complexo_pt dividendo, R_Complexo_pt divisor, R_Complexo_pt quociente){
  Racional_pt real = Cria_racional(1, 1);
  Racional_pt imag = Cria_racional(1, 1);
	R_Complexo_pt conjugado = R_Cria_Racional(1, 1, 1, 1), resultado_temp = R_Cria_Racional(1, 1, 1, 1), escalar = R_Cria_Racional(1, 1, 1, 1);
	//armazenando conjugado do divisor
	conjugado = R_Calcula_Conjugado(divisor);
	resultado_temp = R_Multiplica(dividendo, conjugado); //multiplicando numerador por conjugado
	escalar = R_Multiplica(divisor, conjugado);	//multiplicando denominador por conjugado (obtendo assim um escalar)
	//dividindo os componentes do numerador pelo escalar (denominador)
	Dividi_racional(R_Retorna_Real(resultado_temp), R_Retorna_Real(escalar),real);		//lembrete: o escalar apresenta parte real ja que é fruto da multiplicacao de um complexo pelo seu conjugado
	Dividi_racional(R_Retorna_Imag(resultado_temp), R_Retorna_Real(escalar), imag);
	//modificando variavel do resultado
	quociente = R_Cria_Racional_2(real, imag);
  
	//Destruindo variaveis temporarias/auxiliares
	Destroi_racional(real);	
	Destroi_racional(imag);
	R_Destroi_Complexo(conjugado);
	R_Destroi_Complexo(resultado_temp);
	R_Destroi_Complexo(escalar);
	return quociente;
}


// funcao para realizar varias opeacoes com complexos racionais
R_Complexo_pt R_OperacaoComplexo(R_Complexo_pt num1, R_Complexo_pt num2, char * oper){

    R_Complexo_t *res = R_Cria_Racional(0,0,0,0);

   if(oper[0]== '+' && oper[1] == '='){
       
       res = R_SomaA(num1,num2);
       
       
      
    }else if(oper[0] == '*' && oper[1] == '=') {
  
       res = R_MultiplicaA(num1,num2);
       
    }else{
      switch (*oper){
    case '+':
      res = R_Soma(num1, num2);
    break;
    case '-':
      res = R_Subtrae(num1, num2);
    break;
    case '*':
      res =  R_Multiplica(num1,num2);
    break;
    case '/':
      res = R_Divide(num1,num2,res);
  
    }
    }
  return res;
   
}

