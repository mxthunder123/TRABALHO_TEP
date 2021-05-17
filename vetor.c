#ifdef DATA_TYPE_
#ifdef TYPE_NAME_
#ifdef IO_FORMAT_

#define eps 0.00001


struct TYPE_NAME_(Vector_st){
  int n;
  int N;
  int i;
  DATA_TYPE_ *vector;
};

typedef struct TYPE_NAME_(Vector_st) TYPE_NAME_(Vector_t);

//Funcao para ajustar os parametros da struct
TYPE_NAME_(Vector_pt) TYPE_NAME_(Ajusta_Vetor)(TYPE_NAME_(Vector_pt) a)
{
	if (a->n >= a->N) 
	{
		a->N *= 2; 
	}
	if (a->n < (a->N)/4) 
	{
		a->N /= 2; 
	}

	a->vector = (DATA_TYPE_ *) realloc(a->vector, a->N * sizeof(a->vector)); 
}

// Funcao para criar vetor
TYPE_NAME_(Vector_pt) TYPE_NAME_(Cria_Vetor)(int n){
  TYPE_NAME_(Vector_pt) s = (TYPE_NAME_(Vector_pt)) malloc(sizeof(TYPE_NAME_(Vector_t)));
  s->N = (DATA_TYPE_*) malloc(100 * sizeof(DATA_TYPE_));
  s->n = n;
  s->i = 0;
  for(int i=0;i<n;i++){
    *(s->vector+i) = NULL;

  }


  return s;
}

//Funcao para destruir, dar free, no vetor
void TYPE_NAME_(Destroi_Vector)(TYPE_NAME(Vector_pt) s){

  free(s->vector);
 
  free(s);
}

// Funcao que apagar todos os elementos do vetor
void TYPE_NAME_(Apaga_Vetor)(TYPE_NAME_(Vector_pt) v)
{
	for (int i = 0; i <= v->n; i++) 
	{
		*(v->vector + i) = 0; 
	}
	v->n = 2;

	TYPE_NAME_(Ajusta_Vetor(v));
}


//Funcao que copia um vetor para outro vetor já existente
TYPE_NAME_(Vector_pt) TYPE_NAME_(Copia_Vector)(TYPE_NAME(Vector_pt) a,TYPE_NAME_(Vector_pt) b){
  
  a->n = b->n; 
	a->N = b->N;
	a->i = b->i;
	a->vector = (DATA_TYPE_ *) realloc(a->vector, a->N * sizeof(DATA_TYPE_));

	for (int i = 0; i < b->N; i++)
	{
		*(a->vector + i) = *(b->vector + i); 
	}

  

  return TYPE_NAME_(Ajusta_Vetor(a));
}

//Funcao que copia um vetor para outro vetor que ainda será criado
TYPE_NAME_(Vector_pt) TYPE_NAME(Copia_Novo)(TYPE_NAME_(Vector_pt) a){

  TYPE_NAME_(Vector_pt) v = (TYPE_NAME_(Vector_t*)) malloc(sizeof(TYPE_NAME_(Vector_t)));
	v->n = a->n; 
	v->N = a->N;
	v->i = a->i;
	v->vector = (DATA_TYPE_ *) realloc(v->vector, v->N * sizeof(DATA_TYPE));

	for (int i = 0; i < v->N; i++)
	{
		*(v->vector + i) = *(a->vector + i); 
	}



	return   TYPE_NAME_(Ajusta_Vetor(v));
}

// Funcao que retorna o numero de elemntos do vetor
int TYPE_NAME_(Numero_ElementosA)(TYPE_NAME_(Vector_pt) a){
  return a->n;
}

// Funcao retorna o numero maximoo de elementos que aquele vetor pode ter no momento
int TYPE_NAME_(Numero_ElementosN)(TYPE_NAME_(Vector_pt a){
  return a->N;
}

//Funcao retorna o indice daquele vetor naquele momento
int TYPE_NAME_(Numero_ElementoI)(TYPE_NAME_(Vector_pt) a){
  return a->i;
}

// Funcao retorna o primeiro elemento do vetor
DATA_TYPE_ TYPE_NAME_(Retorna_Primeiro)(TYPE_NAME_(Vector_pt) a){
  a->i=0;
  return *(a->vector + a->i);
}

// Funcao retorna o ultimo elemento do vetor
DATA_TYPE_ TYPE_NAME_(Retorna_Ultimo)(TYPE_NAME_(Vector_pt) a){
  a->i = (a->n)-1;
  return *(a->vector + a->i);
  
}

// Funcao retorna o  elemento sucessor
DATA_TYPE_ TYPE_NAME_(Retorna_Proximo)(TYPE_NAME_(Vector_pt) a){
  a->i+=1;

  return *(a->vector + a->i);
}

// Funcao retorna o  elemento antecessor
DATA_TYPE_ TYPE_NAME_(Retorna_Anterior)(TYPE_NAME_(Vector_pt) a){
  a->i-=1;

  return*(a->vector + a->i);
}

// Funcao que retorna o enesimo termo
DATA_TYPE_ TYPE_NAME_(Retorna_Enesima)(TYPE_NAME_(Vector_pt) a, int pos){
  
  if(pos<1){
    a->i=0;
    return *(a->vector + a->i);
  }if(pos>a->n-1){
    a->i=a->n-1;
    return *(a->vector + a->i);
  }
  a->i=pos;
  
  return*(a->vector + a->i);
}

// Funcao atribui um novo valor ao vetor em uma determinada posicao
void TYPE_NAME_(Atribui_Valor)(TYPE_NAME_(Vector_pt) a, DATA_TYPE_ v,int pos){
  if(pos<1){
    a->i=0;
  }if(pos>a->n-1){
    a->i=a->n-1;
  }
  a->i=pos;
  *(a->vector + a->i) = v;
  TYPE_NAME_(Ajusta_Vetor(a));
}

// Funcao atribui um novo valor ao final do vetor
void TYPE_NAME_(Atribui_ValrF)(TYPE_NAME_(Vector_pt) a, DATA_TYPE_ v){
  a->n+=1;
  a->i=(a->n) - 1;
  *(a->vector + a->i) = v;
  TYPE_NAME_(Ajusta_Vetor(a));
}

// Funcao elimina um elemento do vetor
TYPE_NAME_(Vector_pt) TYPE_NAME_(Elimina_Elemento)(TYPE_NAME_(Vector_pt) a, int pos){
  int j;
  
  
  for (j = pos; j < a->n; j++){
    *(a->vector + j)= *(a->vector + (j+1));
  } 
  a->n -= 1;
  
  return TYPE_NAME_(Ajusta_Vetor(a));
  
}


// Funcao retorna o maior valor absoluto do vetor
DATA_TYPE_ TYPE_NAME_(Maior_Valor)(TYPE_NAME(Vector_pt) v){
  DATA_TYPE_ maior=0,a=0;
  for (int i=0;i<v->n;i++){
      
      if(*(v->vector + i)<0){
        a = *(v->vector + i);
        
        *(v->vector + i) *= -1;
        
        if(i==0){maior=*(v->vector + i);}
        if(*(v->vector + i)>maior){
          maior=*(v->vector + i);
          v->i=i;
        }
        *(v->vector + i)*=-1;
      }else{
        if(i==0){maior=*(v->vector + i);}
        if(*(v->vector + i)>maior){
          maior=*(v->vector + i);
          v->i=i;
          a=0;
        }
      }
      
  }
  
  if(a!=0) return a;
  return maior;
}

// Funcao retorna o menor valor absoluto do vetor
DATA_TYPE_ TYPE_NAME_(Menor_Valor)(TYPE_NAME_(Vector_pt) v){
  DATA_TYPE_ menor=0,a=0;
  for (int i=0;i<v->n;i++){
      
      if(*(v->vector+ i)<0){
        a = *(v->vector+ 1);
        *(v->vector + i)*=-1;
        if(i==0){menor=*(v->vector + i);}
        if(*(v->vector +i)<menor){
          menor=*(v->vector+ i);
          v->i=i;
        }
        *(v->vector + i)*=-1;
      }else{
        if(i==0){menor=v->vector[i];}
        if(v->vector[i]<menor){
          menor=v->vector[i];
          v->i=i;
          a=0;
        }
      }
      
  }
  if(a!=0) return a;
  return menor;
}


//funcao que compara dois valores
int comparador2(const void *a, const void *b) {
   if (*(int*)a > *(int*)b) {
      return 1;
   } else if (*(int*)a < *(int*)b) {
      return -1;
   } else {
      return 0;
   }
}


// funcao para ordenar vetor
void  TYPE_NAME_(OrdernarVetor)(TYPE_NAME_(Vector_pt) v)
{

  qsort(v->vector, v->n, sizeof(v->vector),comparador2);
}

// funcao para intercalar vetores
TYPE_NAME_(Vector_pt) TYPE_NAME_(intercala)(TYPE_NAME_(Vector_pt) a, TYPE_NAME_(Vector_pt) b){
    int i = 0, j = 0;
    TYPE_NAME_(Vector_pt) c = (TYPE_NAME_(Vector_pt)) malloc(sizeof(TYPE_NAME_(Vector_t)));
    c->n= a->n+b->n;
    c->N=100;
    c->vector=(DATA_TYPE_*)malloc((a->n + b->n)*sizeof(DATA_TYPE_));
  
    int k = 0;
    while((i + j) < (a->n + b->n)){
      if(i >= a->n){
          for (; j < b->n; j++, k++){
            *(c->vector + k) = *(b->vector + j);
          }
          break;
      }
      else if(j >= b->n){
            for (; i < a->n; i++, k++){
              *(c->vector + k) = *(a->vector + i);
            }
            break;
        }
        if (*(a->vector + i) < *(b->vector + j))
            *(c->vector + k) = *(a->vector+(i++));

        else 
            *(c->vector + k) = *(b->vector + (j++));

        k++;
    } 
    return c;
}




// funcao que retorna a quantidade de elementos iguais no vetor
int TYPE_NAME_(Valores_Iguais)(TYPE_NAME_(Vector_pt) a,DATA_TYPE_ val){
  int somv=0;
  DATA_TYPE_ diff;
  double eps =  0.00001;
  for(int i = 0; i<a->n;i++){
    diff = *(a->vector + i)-val;
    if((diff < eps) && (-diff < eps)){
      somv+=1;
    }
  }

  return somv;
}

// Funcao que retorna um vetor com os indices dos elementos repetidos
TYPE_NAME_(Vector_pt) TYPE_NAME_(Retorna_VetorI)(TYPE_NAME(Vector_pt) v,DATA_TYPE_ val){
  TYPE_NAME_(Vector_pt) veti = (TYPE_NAME_(Vector_pt)) malloc(sizeof(TYPE_NAME_(Vector_t)));

  veti->n=TYPE_NAME_(Valores_Iguais)(v, val);
  veti->N=100;
  veti -> i=0;
  veti->vector= (DATA_TYPE_ *) malloc(veti->n * sizeof(DATA_TYPE_));
  
  DATA_TYPE_ diff;
  int j=0;
  double eps=0.0001;
  for(int i=0;i<v->n;i++){
    
    diff = *(v->vector + i)-val;
    if((diff < eps) && (-diff < eps)){
      *(veti->vector + j) = i;
      j++;
    }
    
  }
  
  return veti;
}

// funcao para somar vetores
TYPE_NAME_(Vector_pt) TYPE_NAME_(Soma_Vetores)(TYPE_NAME_(Vector_pt) a,TYPE_NAME_(Vector_pt) b){

  DATA_TYPE_ sum = 0;
	int n1 = a->n;
	int n2 = b->n;

	if (n1!= n2)
	{
		printf("Esses vetores não podem ser somados");
		exit(1);
	}

	TYPE_NAME_(Vector_pt)  sumVector = (TYPE_NAME_(Vector_pt)) malloc(sizeof(TYPE_NAME_(Vector_t)));
  sumVector->n= n1;
  sumVector->N = 100;
  sumVector -> vector = (DATA_TYPE_ *) malloc(a->n * sizeof(DATA_TYPE_));

	for (int i = 0; i < n1; i++)
	{
		sum =  *(a->vector +i) + *(b->vector + i);
		TYPE_NAME_(Atribui_Valor)(sumVector, sum, i);
	}


	return TYPE_NAME_(Ajusta_Vetor)(sumVector);

}

// funcao para realizar o Produto Interno
DATA_TYPE_ TYPE_NAME_(Produto_Interno)(TYPE_NAME_(Vector_pt) a, TYPE_NAME_(Vector_pt) b){
  DATA_TYPE_ produto=0;

  for(int i=0;i<a->n;i++){
    produto+=*(a->vector + i) * *(b->vector + i);
  }

  return produto;
}

// funcao para subtrair vetores
TYPE_NAME_(Vector_pt) TYPE_NAME_(Subtrae_Vetores)(TYPE_NAME_(Vector_pt) a,TYPE_NAME_(Vector_pt) b){
  DATA_TYPE_ sub= 0;
	int n1 = a->n;
	int n2 = b->n;

	if (n1!= n2)
	{
		printf("Esses vetores não podem ser subtraidos");
		exit(1);
	}

	TYPE_NAME_(Vector_pt)  subVector = (TYPE_NAME_(Vector_pt)) malloc(sizeof(TYPE_NAME_(Vetor_t)));
  subVector->n= n1;
  subVector->N = 100;
  subVector -> vector = (DATA_TYPE_ *) malloc(a->n * sizeof(DATA_TYPE_));

	for (int i = 0; i < n1; i++)
	{
		sub =  *(a->vector +i) - *(b->vector + i);
		TYPE_NAME_(Atribui_Valor)(subVector, sub, i);
	}


	return TYPE_NAME_(Ajusta_Vetor)(subVector);

 
}

// funcao para multiplicar o vetor por um escalar
TYPE_NAME_(Vector_pt) TYPE_NAME_(Multiplica_Escalar)(TYPE_NAME_(Vector_pt) a, DATA_TYPE_ k){
  for(int i=0;i<a->n;i++){
    *(a->vector + i) *= k;
  }

  return a;
}

// funcao para realizar soma acumulativa de vetores
TYPE_NAME_(Vector_pt) TYPE_NAME_(Acumula_Soma)(TYPE_NAME_(Vector_pt) a, TYPE_NAME_(Vector_pt) b){

  DATA_TYPE_ acc = 0;
  DATA_TYPE_ som=0;
  int n1 = a->n;
	int n2 = a->n;

	if (n1!= n2)
	{
		printf("Os vetores não podem ser somados");
		exit(1);
	}

	for (int i = 0; i < n1; i++)
	{

		acc = *(a-> vector +i)+=*(b->vector + i);
    TYPE_NAME_(Atribui_Valor)(a, acc, i);
	}

	return Ajusta_Vetor(a);


}

// funcao para calcular a media dos valores de um vetor
double TYPE_NAME_(Media)(TYPE_NAME_(Vector_pt) a){
  DATA_TYPE_ soma;
  double media;

  for(int i=0;i<a->n;i++){
    soma+=*(a->vector + i);
  }
  media=soma/a->n;

  return media;
}

// funcao para calcular a variancia
double TYPE_NAME_(Variancia)(TYPE_NAME_(Vector_pt) a){
  double media = TYPE_NAME_(Media)(a);

   double variacoes = 0;
    for (int i = 0; i < a->n; i++) {
        double v = *(a->vector + i) - media;
        variacoes += v * v;
    }
    double variacoesN = variacoes/a->n;

    return variacoesN;
    

}


// funcao para calcular o desvio padrao
double TYPE_NAME_(Desvio_Padrao)(TYPE_NAME_(Vector_pt) a){
  double variancia= TYPE_NAME_(Variancia)(a);
  if(variancia < 0){
    variancia *= -1;
  }

  double desvio=sqrt(variancia);

  return desvio;

}

// funcao para calcular a mediana
double TYPE_NAME_(MEDIANA) (TYPE_NAME_(Vector_pt) a)
{
  register int i; 

  DATA_TYPE_ m1, m2;

  
  TYPE_NAME_(OrdernarVetor)(a); 
  
  
  switch (a->n % 2) .
  {
    case 0: 
      m1 = a->vector[a-> n/ 2 - 1];
      m2 = a->vector[a->n / 2];     
      m1 += m2;
      return  (m1 / 2); 
    
    case 1: 
      m1 = a->vector[ (a->n - 1) / 2 ];
      return m1;
  }

}
// OUTRAS MANEIRAS PARA CALCULAR A MEDIANA
//função auxiliar para realizar as trocas de elementos
void TYPE_NAME_(swap)(TYPE_NAME_(Vector_pt) a, int i, int j){
    int temp = a->vector[i];
    *(a->vector + i) = *(a->vector + j);
    *(a->vector + j) = temp;
}

double TYPE_NAME_(partition)(TYPE_NAME_(Vector_pt) v, int inicio, int fim) {
    //procura a mediana entre inicio, meio e fim
    int meio = (inicio + fim) / 2;
    int a = -v->vector[inicio];
    int b = v->vector[meio];
    int c = v->vector[fim];
    int medianaIndice; //índice da mediana
    //A sequência de if...else a seguir verifica qual é a mediana
    if (a < b) {
        if (b < c) {
            //a < b && b < c
            medianaIndice = meio;
        } else {
            if (a < c) {
                //a < c && c <= b
                medianaIndice = fim;
            } else {
                //c <= a && a < b
                medianaIndice = inicio;
            }
        }
    } else {
        if (c < b) {
            //c < b && b <= a
            medianaIndice = meio;
        } else {
            if (c < a) {
                //b <= c && c < a
                medianaIndice = fim;
            } else {
                //b <= a && a <= c
                medianaIndice = inicio;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
    swap(v, medianaIndice, fim);
        
    //*******************ALGORITMO DE PARTIÇÃO DE CORMEN*********************
    //o pivo é o elemento final
    int pivo = v->vector[fim];
    int i = inicio - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.         
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (v->vector[j] <= pivo) {
            i = i + 1;
            swap(v, i, j);
        }
    }
    //coloca o pivô na posição de ordenação
    swap(v, i + 1, fim);
    return i + 1; //retorna a posição do pivô
}

double TYPE_NAME_(torben)(TYPE_NAME_(Vector_pt) v, int n)
{
    int         i, less, greater, equal;
    double  min, max, guess, maxltguess, mingtguess;

    min = max = v->vector[0] ;
    for (i=1 ; i<n ; i++) {
        if (v->vector[i]<min) min=v->vector[i];
        if (v->vector[i]>max) max=v->vector[i];
    }

    while (1) {
        guess = (min+max)/2;
        less = 0; greater = 0; equal = 0;
        maxltguess = min ;
        mingtguess = max ;
        for (i=0; i<n; i++) {
            if (v->vector[i]<guess) {
                less++;
                if (v->vector[i]>maxltguess) maxltguess = v->vector[i] ;
            } else if (v->vector[i]>guess) {
                greater++;
                if (v->vector[i]<mingtguess) mingtguess = v->vector[i] ;
            } else equal++;
        }
        if (less <= (n+1)/2 && greater <= (n+1)/2) break ; 
        else if (less>greater) max = maxltguess ;
        else min = mingtguess;
    }
    if (less >= (n+1)/2) return maxltguess;
    else if (less+equal >= (n+1)/2) return guess ;
    else return mingtguess;
}




#endif
#endif
#endif