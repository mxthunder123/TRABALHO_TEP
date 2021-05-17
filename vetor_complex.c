#ifdef DATA_TYPE_VETOR_ 
#ifdef TYPE_NAME_VETOR_ 
#ifdef DATA_TYPE_  
#ifdef TYPE_NAME_ 
#ifdef IO_FORMAT_


#define eps 0.00001

struct TYPE_NAME_VETOR_(Vector_st){
  int n;
  int N;
  int i;
  DATA_TYPE_VETOR_ *vector;
};

typedef struct TYPE_NAME_VETOR_(Vector_st) TYPE_NAME_VETOR_(Vector_t);

//Funcao para ajustar os parametros da struct
TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Ajusta_Vetor)(TYPE_NAME_VETOR_(Vector_pt) a)
{
	if (a->n >= a->N) 
	{
		a->N *= 2;
	}
	if (a->n < (a->N)/4) 
	{
		a->N /= 2; 
	}

	a->vector = (DATA_TYPE_VETOR_ *) realloc(a->vector, a->N * sizeof(DATA_TYPE_VETOR_)); 
}

// Funcao para criar vetor
TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Cria_Vetor)(int n){
  TYPE_NAME_VETOR_(Vector_pt) s = (TYPE_NAME_VETOR_(Vector_pt)) malloc(sizeof(TYPE_NAME_VETOR_(Vector_t)));
  s->N = (DATA_TYPE_VETOR_*) malloc(100 * sizeof(DATA_TYPE_VETOR));
  s->n = n;
  s->i = 0;
  for(int i=0;i<n;i++){
    *(s->vector+i) = NULL;

  }

  

  return s;
}

//Funcao para destruir, dar free, no vetor
void TYPE_NAME_VETOR_(Destroi_Vector)(TYPE_NAME_VETOR_(Vector_pt) s){

  for(int i = 0; i < vetor->n; i++){
    TYPE_NAME_(Destroi_Complexo)(*(s->vector+i));
    (*s->vector + i) = NULL;
  }
  free(s);
}

// Funcao que apagar todos os elementos do vetor
void TYPE_NAME_VETOR_(Apaga_Vetor)(TYPE_NAME_VETOR_(Vector_pt) v)
{
	for (int i = 0; i <= v->n; i++) 
	{
		TYPE_NAME_(Destroi_Complexo)(v->vector[i]);
    v-> vector[i] = NULL;
	}
	v->n = 2;

	TYPE_NAME_VETOR_(Ajusta_Vetor(v));
}

//Funcao que copia um vetor para outro vetor já existente
TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Copia_Vector)(TYPE_NAME_VETOR_(Vector_pt) a,TYPE_NAME_VETOR_(Vector_pt) b){
  
  a->n = b->n; 
	a->N = b->N;
	a->i = b->i;
	a->vector = (DATA_TYPE_ *) realloc(a->vector, a->N * sizeof(DATA_TYPE_));

	for (int i = 0; i < b->N; i++)
	{
		*(a->vector + i) = *(b->vector + i); 
	}
  for(int c = 0; c < vetor1->n; c++){
    TYPE_NAME_(Troca_Real)(a->vector[i], TYPE_NAME_(Retorna_Real)(b->vector[i]));
    TYPE_NAME_(Troca_Imag)(a->vector[i], TYPE_NAME_(Retorna_Imag)(b->vector[i]));
  }
  

  return TYPE_NAME_VETOR_(Ajusta_Vetor(a));
}



//Funcao que copia um vetor para outro vetor que ainda será criado
TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Copia_Novo)(TYPE_NAME_VETOR_(Vector_pt) a){

  TYPE_NAME_VETOR_(Vector_pt) v = (TYPE_NAME_VETOR_(Vector_t*)) malloc(sizeof(TYPE_NAME_VETOR_(Vector_t)));
	v->n = a->n; 
	v->N = a->N;
	v->i = a->i;
	v->vector = (DATA_TYPE_VETOR_ *) realloc(v->vector, v->N * sizeof(DATA_TYPE_VETOR_));

	for (int i = 0; i < v->N; i++)
	{
		TYPE_NAME_(Atribui_Complexo)(v->vector[i], a->vector[i]); 
	}



	return   TYPE_NAME_VETOR_(Ajusta_Vetor(v));
}

// Funcao que retorna o numero de elemntos do vetor
int TYPE_NAME_VETOR_(Numero_ElementosA)(TYPE_NAME_VETOR_(Vector_pt) a){
  return a->n;
}

// Funcao retorna o numero maximoo de elementos que aquele vetor pode ter no momento
int TYPE_NAME_VETOR_(Numero_ElementosN)(TYPE_NAME_VETOR_(Vector_pt a){
  return a->N;
}

//Funcao retorna o indice daquele vetor naquele momento
int TYPE_NAME_VETOR_(Numero_ElementoI)(TYPE_NAME_VETOR_(Vector_pt) a){
  return a->i;
}

// Funcao retorna o primeiro elemento do vetor
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Primeiro)(TYPE_NAME_VETOR_(Vector_pt) a){
  a->i=0;
  return *(a->vector + (a->i));
}

// Funcao retorna o ultimo elemento do vetor
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Ultimo)(TYPE_NAME_VETOR_(Vector_pt) a){
  a->i = (a->n)-1;
  return *(a->vector + (a->i));

}

// Funcao retorna o  elemento sucessor
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Proximo)(TYPE_NAME_VETOR_(Vector_pt) a){
  a->i+=1;

  return *(a->vector + (a->i));
}

// Funcao retorna o  elemento antecessor
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Anterior)(TYPE_NAME_VETOR_(Vector_pt) a){
  a->i-=1;

  return*(a->vector + (a->i));
}

// Funcao que retorna o enesimo termo
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Enesima)(TYPE_NAME_VETOR_(Vector_pt) a, int pos){

  if(pos<1){
    a->i=0;
    return *(a->vector + (a->i));
  }if(pos>a->n-1){
    a->i=a->n-1;
    return *(a->vector + (a->i));
  }
  a->i=pos;
  
  return*(a->vector + (a->i));
}

// Funcao atribui um novo valor ao vetor em uma determinada posicao
void TYPE_NAME_VETOR_(Atribui_Valor)(TYPE_NAME_VETOR_(Vector_pt) a, DATA_TYPE_VETOR_ v,int pos){
  if(pos<1){
    a->i=0;
  }if(pos>a->n-1){
    a->i=a->n-1;
  }
  a->i=pos;
  TYPE_NAME_(Atribui_Complexo)(a->vector[a->i],v);
  TYPE_NAME_VETOR_(Ajusta_Vetor)(a);
}

// Funcao atribui um novo valor ao final do vetor
void TYPE_NAME_VETOR_(Atribui_ValrF)(TYPE_NAME_VETOR_(Vector_pt) a, DATA_TYPE_VETOR_ v){
  a->n+=1;
  a->i=(a->n) - 1;
  TYPE_NAME_(Atribui_Complexo)(a->vector[a->i],v);
  TYPE_NAME_VETOR_(Ajusta_Vetor)(a);
}

// Funcao elimina um elemento do vetor
TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Elimina_Elemento)(TYPE_NAME_VETOR_(Vector_pt) a, int pos){

  int j;
  for (j = pos; j < a->n; j++){
    
    *(a->vector + j)= *(a->vector + (j+1));
  } 
  a->n -= 1;
  
  return TYPE_NAME_VETOR(Ajusta_Vetor)(a);

}

// Funcao retorna o maior valor absoluto do vetor
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Maior_Valor)(TYPE_NAME_VETOR_(Vector_pt) v){
  DATA_TYPE_VETOR_ Maior_Valor = TYPE_NAME_VETOR_(Retorna_Primeiro)(v);

	for (int i = 0; i < v -> n + 1 ; i++) {
    
    DATA_TYPE_VETOR_ elementoA = TYPE_NAME_VETOR_(Retorna_Enesima)(v, i);

    if (elementoA == NULL) {
      continue;
    }

    double moduloA = TYPE_NAME_(Calcula_Modulo)(elementoA);

		if (moduloA > TYPE_NAME_(Calcula_Modulo)(Maior_Valor)) {
      Maior_Valor = v->vector[i];
			v -> i = i;
		}
	}

	return Maior_Valor;
}

// Funcao retorna o menor valor absoluto do vetor
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Menor_Valor)(TYPE_NAME_VETOR_(Vector_pt) v){
  DATA_TYPE_VETOR_ Menor_Valor = TYPE_NAME_VETOR_(Retorna_Primeiro)(v);

	for (int i = 0; i < v -> n + 1 ; i++) {

    DATA_TYPE_VETOR_ elementoA = TYPE_NAME_VETOR_(Retorna_Enesima)(v, i);

    if (elementoA == NULL) {
      continue;
    }

    double moduloA = TYPE_NAME_(Calcula_Modulo)(elementoA);

		if (moduloA < TYPE_NAME_(Calcula_Modulo)(Menor_Valor)) {
      Menor_Valor = v->vector[i];
			v -> i = i;
		}
	}

	return Menor_Valor;
}


//funcao que compara dois valores
int comparador2(const void *a, const void *b) {
   if (TYPE_NAME_(Diferenca_Modulo)(a,b) == 1) {
      return 1;
   } else if (TYPE_NAME_(Diferenca_Modulo)(a,b) == -1) {
      return -1;
   } else {
      return 0;
   }
}


// funcao para ordenar vetor
void  TYPE_NAME_VETOR_(OrdernarVetor)(TYPE_NAME_VETOR_(Vector_pt) v)
{
  
  qsort(v->vector, v->n, sizeof(TYPE_NAME_VETOR_),comparador2);
    
}


// funcao que retorna a quantidade de elementos iguais no vetor
int TYPE_NAME_VETOR_(Valores_Iguais)(TYPE_NAME_VETOR_(Vector_pt) a,DATA_TYPE_VETOR_ val){
  int somv = 0;

	for (int i = 0; i < v->n + 1; i++) {
    DATA_TYPE_VETOR_ valor = a->vector[i];

    if (valor == NULL) {
      continue;
    }

    if (TYPE_NAME_(Diferença_Modulo)(valor, val) == 0) {
      somv++;
    }
	}

  return somv;
}

// Funcao que retorna um vetor com os indices dos elementos repetidos
int * TYPE_NAME_VETOR_(Retorna_VetorI)(TYPE_NAME_VETOR_(Vector_pt) v,DATA_TYPE_VETOR val){
  int *indices;
  int j=0;
  for(int i=0;i<v->n;i++){
    
    if(TYPE_NAME_(Diferenca_Modulo)(v->vector[i],val) == 0){
      indices[i] = i;
      j++;
    }
    
  }
  
  return indices;
}

// funcao para somar vetores
TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Soma_Vetores)(TYPE_NAME_VETOR_(Vector_pt) a,TYPE_NAME_VETOR_(Vector_pt) b){
	int n1 = a->n;
	int n2 = b->n;

	if (n1!= n2)
	{
		printf("Esses vetores não podem ser somados");
		exit(1);
	}

	TYPE_NAME_VETOR_(Vector_pt)  Vetor_Soma = (TYPE_NAME_VETOR_(Vector_pt)) malloc(sizeof(TYPE_NAME_VETOR_(Vector_t)));
  Vetor_Soma->n= n1;
  Vetor_Soma->N = 100;
  Vetor_Soma -> vector = (DATA_TYPE_VETOR_ *) malloc(a->n * sizeof(DATA_TYPE_VETOR_));

	for (int i = 0; i < n1; i++)
	{
		DATA_TYPE_VETOR_ elementoA = TYPE_NAME_VETOR_(Retorna_Enesima)(a, i);
    DATA_TYPE_VETOR_ elementoB = TYPE_NAME_VETOR_(Retorna_Enesima)(b, i);

     DATA_TYPE_VETOR_ soma =  TYPE_NAME_(Soma_Complexo)(elementoA, elementoB, soma);


		TYPE_NAME_VETOR_(Atribui_Valor)(Vetor_Soma, soma, i);
    TYPE_NAME_(Destroi_Complexo)(elementoA);
    TYPE_NAME_(Destroi_Complexo)(elementoB);
    TYPE_NAME_(Destroi_Complexo)(soma);
	}

  return Vetor_Soma;
 
}

// funcao para realizar o Produto Interno
DATA_TYPE_VETOR_ Produto_Interno(TYPE_NAME_VETOR_(Vector_pt) a, TYPE_NAME_VETOR_(Vector_pt) b){
  int nElementosA = a->n; 
  int nElementosB = b->n;

  DATA_TYPE_VETOR_ Produto_Interno = TYPE_NAME_(Cria_Complexo)(0, 0);
  for (int i = 0; i < a->n; i++) {
    
    if (a->vector[i] != NULL && b->vector[i] != NULL) {
      
      DATA_TYPE_VETOR_ conjugado = TYPE_NAME_(Conjugado)(a->vector[i]);
     
      DATA_TYPE_VETOR_ multiplica = TYPE_NAME_(Multiplica_Complexo)(conjugado, b->vector[i],multiplica);
      
      TYPE_NAME_(SomaA_Complexo)(Produto_Interno, multiplica);

      TYPE_NAME_(Destroi_Complexo)(conjugado);
      TYPE_NAME_(Destroi_Complexo)(multiplica);
    }
  }

  return Produto_Interno;


}

// funcao para subtrair vetores
TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Subtrae_Vetores)(TYPE_NAME_VETOR_(Vector_pt) a,TYPE_NAME_VETOR_(Vector_pt) b){
  int n1 = a->n;
	int n2 = b->n;

	if (n1!= n2)
	{
		printf("Esses vetores não podem ser somados");
		exit(1);
	}

	TYPE_NAME_VETOR_(Vector_pt)  Vetor_Subtrae = (TYPE_NAME_VETOR_(Vector_pt)) malloc(sizeof(TYPE_NAME_VETOR_(Vector_t)));
  Vetor_Subtrae->n= n1;
  Vetor_Subtrae->N = 100;
  Vetor_Subtrae -> vector = (DATA_TYPE_VETOR_ *) malloc(a->n * sizeof(DATA_TYPE_VETOR_));

	for (int i = 0; i < n1; i++)
	{
		DATA_TYPE_VETOR_ elementoA = TYPE_NAME_VETOR_(Retorna_Enesima)(a, i);
    DATA_TYPE_VETOR_ elementoB = TYPE_NAME_VETOR_(Retorna_Enesima)(b, i);

     DATA_TYPE_VETOR_ subtrae =  TYPE_NAME_(Subtrae_Complexo)(elementoA, elementoB, subtrae);


		TYPE_NAME_VETOR_(Atribui_Valor)(Vetor_Subtrae, subtrae, i);
    TYPE_NAME_(Destroi_Complexo)(elementoA);
    TYPE_NAME_(Destroi_Complexo)(elementoB);
    TYPE_NAME_(Destroi_Complexo)(subtrae);
   
	}

  return Vetor_Subtrae;
 
}

// funcao para multiplicar o vetor por um escalar
TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Multiplica_Escalar)(TYPE_NAME_VETOR_(Vector_pt) a, DATA_TYPE_VETOR_ k){
  for (int i = 0; i < a->n; i++) {
   
    DATA_TYPE_VECTOR elementoA = TYPE_NAME_VETOR_(Retorna_Enesima)(a, i);

    if (elementoA == NULL) {
      continue;
    }

    
    DATA_TYPE_VETOR_ multiplica = TYPE_NAME_(Multiplica_Complexo)(elementoA,k, multiplica);

    
    TYPE_NAME_VETOR_(Atribui_Valor)(a, multiplica, i);

    TYPE_NAME_(Destroi_Complexo)(multi);
    TYPE_NAME_(Destroi_Comlexo)(elementoA);
  }
}

// funcao para realizar soma acumulativa de vetores
TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Acumula_Soma)(TYPE_NAME_VETOR_(Vector_pt) a, TYPE_NAME_VETOR_(Vector_pt) b){

  int ElementosA = a->n;
  int ElementosB = b->n;

  if (a->n!= b->n) {
    printf("A  soma não pode ser realizada!");
    exit(1);
  }

  for (int i = 0; i < a->n; i++) {
    
    if (a->vector[i] == NULL || a->vector[i] == NULL) {
      continue;
    }

    a = TYPE_NAME_(SomaA_Complexo)(a,b,a);
  }

  return a;
}

// funcao para calcular a media dos valores de um vetor
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Media)(TYPE_NAME_VETOR_(Vector_pt) a){
  int qtd = 0;
  double somaReal = 0;
  double somaImag = 0;

	for (int i = 0; i < a->n ; i++) {
    DATA_TYPE_VECTOR elemento = a->vector[i];

    if (element == NULL) {
      continue;
    }

    somaReal += TYPE_NAME_(Retorna_Real)(elemento);
    somaImag += TYPE_NAME_(Retorna_Imag)(elemento);
    qtd++;
	}


 
  somaReal /= qtd;
  somaImag /= qtd;

  return TYPE_NAME_(Cria_Complexo)(somaReal, somaImag);
}

// funcao para calcular a variancia
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Variancia)(TYPE_NAME_VETOR_(Vector_pt) a){
  DATA_TYPE_VECTOR_ media = TYPE_NAME_VECTOR(Media)(a);
  DATA_TYPE_ realM = TYPE_NAME_(Retorna_Real)(media);
  DATA_TYPE_ imagM = TYPE_NAME_(Retorna_Imag)(media);
  
  double Real = 0;
  double Imag = 0;

  int elementos = a->n;

	for (int i = 0; i < elementos; i++) {
    DATA_TYPE_VETOR_ numeroA = a->vector[i];

 
    if (numeroA == NULL) {
      continue;
    }

    Real += pow((TYPE_NAME_(Retorna_Real)(numeroA) - realM), 2);
    Imag += pow((TYPE_NAME_(Retorna_Imag)(numeroA) - imagM), 2);
	}

  Real = Real / (elementos - 1);
  Imag = Imag / (elementos - 1);


  TYPE_NAME_(Destroi_Complexo)(media);

  return TYPE_NAME_(Cria_Complexo)(Real,Imag);

}


// funcao para calcular o desvio padrao
DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Desvio_Padrao)(TYPE_NAME_VETOR_(Vector_pt) a){
  DATA_TYPE_VETOR_ variancia = TYPE_NAME_VETOR_(Variancia)(a);
  DATA_TYPE_ real = TYPE_NAME_(Retorna_Real)(variancia);
  DATA_TYPE_ imag = TYPE_NAME_(Retrona_Imag)(variance);

 
  TYPE_NAME_(Destroi_Complexo)(variancia);


  real = sqrt(real);
  imag = sqrt(imag);
  

  return TYPE_NAME_(Cria_Complexo)(real, imag);

}
// funcao para calcular a mediana
double TYPE_NAME_VETOR_(MEDIANA) (TYPE_NAME_VETOR_(Vetor_pt) v){
  TYPE_NAME_VETOR_(OrdenarVetor)(v);
  int elementos = v->n;
  int meio = elementos/2;
  double mediana = TYPE_NAME_(Cria_Complexo)(1,1);
  if (n%2 == 0){
    mediana = ((TYPE_NAME_(Calcula_Modulo)(TYPE_NAME_VETOR_(Retorna_Enesima)(v, meio))) + (TYPE_NAME_(Calcula_Modulo)(TYPE_NAME_VETOR_(Retorna_Enesima)(v, meio-1))))/2;
  }
  else{
    
    mediana = TYPE_NAME_(Calcula_Modulo)(TYPE_NAME_VETOR_(Retorna_Enesima)(v, meio));
  }
  return mediana;
}



#endif
#endif
#endif
#endif
#endif