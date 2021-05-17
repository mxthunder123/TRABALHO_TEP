
#ifdef DATA_TYPE_ 
#ifdef TYPE_NAME_
#ifdef IO_FORMAT_

#define PI 3.141592654
#define GUESS 10
 

struct TYPE_NAME_(Complexo_st){
  DATA_TYPE_ * real;
  DATA_TYPE_ * imag;
};

typedef struct TYPE_NAME_(Complexo_st) TYPE_NAME_(Complexo_t);


//Funcao para criar um complexo
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Cria_Complexo)(DATA_TYPE_ r, DATA_TYPE_ i){
  TYPE_NAME_(Complexo_pt) a = (TYPE_NAME_(Complexo_pt)) malloc(sizeof(TYPE_NAME_(Complexo_t)));
  
  a->real =(DATA_TYPE_ *) malloc(sizeof(DATA_TYPE_));
  a->imag = (DATA_TYPE_ *) malloc(sizeof(DATA_TYPE_));
  *a->real=r;
  *a->imag=i;


  return a;
}

// Funcao para destruir complexo
void TYPE_NAME_ (Destroi_Complexo) (TYPE_NAME_(Complexo_pt) r){
  free(r->imag);
  free(r->real);
  free(r);
}

//Funcao para atribuir um complexo a um outro já existente
TYPE_NAME_(Complexo_pt) TYPE_NAME_ (Atribui_Complexo) (TYPE_NAME_(Complexo_pt) a,TYPE_NAME_(Complexo_pt) b){
  memcpy(a->real,b->real,sizeof(*b));
  memcpy(a->imag,b->imag,sizeof(*b));
  
  return a;
}

// Funcao para atribuir um complexo para um outro complexo que ainda será criado
TYPE_NAME_(Complexo_pt) TYPE_NAME_(AtribuiNovo_Complexo) (TYPE_NAME_(Complexo_pt) a){
  TYPE_NAME_(Complexo_pt) res = (TYPE_NAME_(Complexo_pt)) malloc(sizeof(TYPE_NAME_(Complexo_t)));
  memcpy(res->real,a->real,sizeof(*a));
  memcpy(res->imag,a->imag,sizeof(*a));
  
  return res;
}
// Funcao que determina se parte imaginaria e nula
int TYPE_NAME_ (Compara_ImagN) (TYPE_NAME_(Complexo_pt) c){
  double eps =  5.96e-08;
  return fabs(*c->imag/eps) < eps;
}

//Funcao que determina se parte real e nula
int TYPE_NAME_ (Compara_RealN) (TYPE_NAME_(Complexo_pt) c){
  double eps =  5.96e-08;
  return fabs(*c->real/eps) < eps;
}

//Funcao para calcular o modulo do complexo
double TYPE_NAME_ (Calcula_Modulo) (TYPE_NAME_(Complexo_pt) r){
  double modulo;
  double y= GUESS;
 
  modulo=(pow(*r->real, 2) + pow(*r->imag,2));
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

// Funcao para calcular o Angulo do complexo
double TYPE_NAME_ (Angulo) (TYPE_NAME_(Complexo_pt) c){
  double ang,div;
  ang = atan2(*c->imag,*c->real);
  ang = ang * 180 / PI;
  return ang;
}

// Funcao determina se modulo do complexo é nulo
int TYPE_NAME_ (Compara_ModuloN) (TYPE_NAME_(Complexo_pt) c){
  double modulo;

  double eps =  5.96e-08;
  modulo = TYPE_NAME_(Calcula_Modulo)(c);
 
  return fabs(modulo/eps) < eps;
  
  
}

// Funcao para comparar se dois valores sao iguais
int E_Eh_Igual(double a, double b){
  double diff;
  
  diff=a-b;
 
  double eps =  0.00001;
  
  return (diff < eps) && (-diff < eps);
  
}

// funcao para determianr se valor a e maior do que o valor b
int E_Eh_Maior(double a, double b){
  
  double eps =  0.00001;
  return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * eps);

}

// funcao para determinar se valor a e menor do que valor b
int E_Eh_Menor(double a,double b){
  
  double eps =  0.00001;
  
  return (a - b) < ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * eps);

}

// Funcao para determinar se modulo do oomplexo a e igual, menor ou maior que o modulo do complexo b
int TYPE_NAME_ (Diferenca_Modulo) (TYPE_NAME_(Complexo_pt) a, TYPE_NAME_(Complexo_pt) b){
  double m1,m2;
  m1 = TYPE_NAME_(Calcula_Modulo)(a);
  m2 =  TYPE_NAME_(Calcula_Modulo)(b);
  

  if(E_Eh_Igual(m1,m2)) return 0;
  else if(E_Eh_Maior(m1,m2)) return 1;
  else return -1;
}

// // Funcao para determinar se angulo do oomplexo a e igual, menor ou maior que o angulo do complexo b
int TYPE_NAME_ (Diferenca_Angulo) (TYPE_NAME_(Complexo_pt) a, TYPE_NAME_(Complexo_pt) b){
  double a1,a2;
  a1 = TYPE_NAME_(Angulo)(a);
  a2 =  TYPE_NAME_(Angulo)(b);
  

  if(E_Eh_Igual(a1,a2)) return 0;
  else if(E_Eh_Maior(a1,a2)) return 1;
  else return -1;

}
// Retorna a parte real de um complexo
DATA_TYPE_ TYPE_NAME_(Retorna_Real)(TYPE_NAME_(Complexo_pt) c){
  return *c->real;
}

//Retorna a parte imaginaria de um complexo
DATA_TYPE_ TYPE_NAME_(Retorna_Imag)(TYPE_NAME_(Complexo_pt) c){
  return *c->imag;
}

// Troca a parte real de um complexo
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Troca_Real)(TYPE_NAME_(Complexo_pt) c, DATA_TYPE_ n){
  *c->real=n;
  return c;
}

// Troca a parte imaginaria de um complexo
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Troca_Imag)(TYPE_NAME_(Complexo_pt) c, DATA_TYPE_ n){
  *c->imag=n;
  return c;
}

// Soma dois complexos
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Soma_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res){
  *res->real = *num1->real + *num2->real;
  *res->imag = *num1->imag + *num2->imag;

  return res; 
}

//Subtrae dois complexos
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Subtrae_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res){
  *res->real = *num1->real - *num2->real;
  *res->imag = *num1->imag - *num2->imag;                        
  return res; 
}


// Multiplica dois complexos
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Multiplica_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res){
  *res->real = *num1->real * *num2->real - *num1->imag * *num2->imag;
  *res->imag =  *num1->real * *num2->imag + *num1->imag * *num2->real;

  return num1; 
}

// Divide dois complexos
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Divide_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res){

  *res->real=(((*num1->real)*(*num2->real))+((*num1->imag)*(*num2->imag)))/(pow(*num2->real,2)+pow(*num2->imag,2));
  *res->imag=(((*num2->real)*(*num1->imag))-((*num1->real)*(*num2->imag)))/(pow(*num2->real,2)+pow(*num2->imag,2));
  if((*res-> real <=0)){
    *res->real = 0 ;
 
  }if(*res->imag <=0){
    *res->imag=0;
   
  }
  return res;
}

// Soma acumulativa de complexos
TYPE_NAME_(Complexo_pt) TYPE_NAME_(SomaA_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res){
  *num1->real += *num2->real;
  *num1->imag += *num2->imag;
  memcpy(res->real, num1->real,sizeof(*res));
  memcpy(res->imag, num1->imag,sizeof(*res));
     
  
  return res;
}

// Multiplicacao acumulativa de complexos
TYPE_NAME_(Complexo_pt) TYPE_NAME_(MultiplicaA_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res){
  DATA_TYPE_ real, imag;
  real = *num1->real;
  imag=*num1->imag;
  *num1->real = real * *num2->real - imag * *num2->imag;
 
  *num1->imag =  ((real) * (*num2->imag)) + ((imag) * (*num2->real));
  *res->real = *num1->real;
  *res->imag = *num1->imag;

  
  return res; 
}

// Funcao para realizar varias operacoes com complexos
TYPE_NAME_(Complexo_pt) TYPE_NAME_(OperacaoComplexoComplexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, char *oper){
  TYPE_NAME_(Complexo_pt) res = TYPE_NAME_(Cria_Complexo)(0,0);

  if(oper[0]== '+' && oper[1] == '='){
      
       res = TYPE_NAME_(SomaA_Complexo)(num1,num2,res);
      
       
      
    }else if(oper[0] == '*' && oper[1] == '=') {
     
       res = TYPE_NAME_(MultiplicaA_Complexo)(num1,num2,res);
       
    }else{
      switch (*oper){
    case '+':
      res = TYPE_NAME_(Soma_Complexo)(num1, num2,res);
    
    break;
    case '-':
      res = TYPE_NAME_(Subtrae_Complexo)(num1, num2,res);
    break;
    case '*':
      res =  TYPE_NAME_(Multiplica_Complexo)(num1,num2,res);
    break;
    case '/':
      res = TYPE_NAME_(Divide_Complexo)(num1,num2,res);
    break;
    }
    }


  
  return res;
   
}

//Calcula o Conjugado de um complexo
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Conjugado)(TYPE_NAME_(Complexo_pt) c, TYPE_NAME_(Complexo_pt) res){
  *res->imag = *c->imag * -1;
  *res -> real = *c->real;

  return res;
}

// Modifica o angulo de um complexo sem alterar o seu modulo
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Modificar_Angulo)(TYPE_NAME_(Complexo_pt) a, double angulo){
  double moduloI = TYPE_NAME_(Calcula_Modulo)(a);
  TYPE_NAME_(Complexo_pt) d = (TYPE_NAME_(Complexo_pt)) malloc(sizeof(TYPE_NAME_(Complexo_t)));
  d->imag = (DATA_TYPE_ *) malloc(sizeof(DATA_TYPE_));
  d->real = (DATA_TYPE_ *) malloc(sizeof(DATA_TYPE_));
  
  *d->imag = moduloI*sin(angulo);
  *d->real = moduloI*cos(angulo);
  
  return d;

}

// Modifica o modulo de um complexo sem alterar o seu angulo
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Modificar_Modulo)(TYPE_NAME_(Complexo_pt) a, double modulo){
  double FaseI = TYPE_NAME_(Angulo)(a);
  TYPE_NAME_(Complexo_pt) d =  (TYPE_NAME_(Complexo_pt)) malloc(sizeof(TYPE_NAME_(Complexo_t)));
  d->imag = (DATA_TYPE_ *) malloc(sizeof(DATA_TYPE_));
  d->real = (DATA_TYPE_ *) malloc(sizeof(DATA_TYPE_));
  
  *d->imag=modulo*sin(FaseI);
  *d->real=modulo*cos(FaseI);
  
  return d;

}

//Escreve um complexo em um arquivo
void TYPE_NAME_(Escrever_Complexo)(TYPE_NAME_(Complexo_pt) v, FILE* saida){
	if(v==NULL){
		puts("Ponteiro Nulo");
		exit(1);
	}
	int close=0;
	if(saida==NULL){
		saida = fopen("./complexo.txt", "w");
		close=1;
	}
	char* str = (char*) malloc(sizeof(char)*15);
	strcpy(str, IO_FORMAT_);
	strcat(str, "+");
	strcat(str, IO_FORMAT_);
	strcat(str, "i,	");
	fprintf(saida, str, TYPE_NAME_(Retorna_Real)(v), TYPE_NAME_(Retorna_Imag)(v));
	if(close){
		fclose(saida);
	}
	free(str);
}
// Ler um complexo de um arquivo
TYPE_NAME_(Complexo_pt) TYPE_NAME_(Ler_Complexo)(TYPE_NAME_(Complexo_pt) v, FILE* entrada){
	if(v==NULL){
		puts("Ponteiro Nulo");
		return NULL;
	}
	if(entrada == NULL){
		return v;
	}
	char* str = (char*) malloc(sizeof(char)*10);
	if(str==NULL){
		puts("Memoria insuficiente!");
		return NULL;
	}
	Ler_Racional(entrada, TYPE_NAME_(Retorna_Real)(v)); 
	fscanf(entrada, "%[^0-9]s", str);	
	lerRacional(entrada, TYPE_NAME_(Retorna_Imag)(v));
	fscanf(entrada, "%[^0-9]s", str);
	free(str);
	return v;
}


#endif
#endif
#endif
