#ifndef VETOR_H
#define VETOR_H


typedef struct TYPE_NAME_(Vector_st) * TYPE_NAME_(Vector_pt);

TYPE_NAME_(Vector_pt) TYPE_NAME_(Ajusta_Vetor)(TYPE_NAME_(Vector_pt) a);

TYPE_NAME_(Vector_pt) TYPE_NAME_(Cria_Vetor)(int n);

void TYPE_NAME_(Destroi_Vector)(TYPE_NAME_(Vector_pt) s);

void TYPE_NAME_(Apaga_Vetor)(TYPE_NAME_(Vector_pt) v);

TYPE_NAME_(Vector_pt) TYPE_NAME_(Copia_Vector)(TYPE_NAME(Vector_pt) a,TYPE_NAME_(Vector_pt) b);

TYPE_NAME_(Vector_pt) TYPE_NAME_(Copia_Novo)(TYPE_NAME_(Vector_pt) a);

int TYPE_NAME_(Numero_ElementosA)(TYPE_NAME_(Vector_pt) a);

int TYPE_NAME_(Numero_ElementosN)(TYPE_NAME_(Vector_pt a);

int TYPE_NAME_(Numero_ElementoI)(TYPE_NAME_(Vector_pt) a);

DATA_TYPE_ TYPE_NAME_(Retorna_Primeiro)(TYPE_NAME_(Vector_pt) a);

DATA_TYPE_ TYPE_NAME_(Retorna_Ultimo)(TYPE_NAME_(Vector_pt) a);

DATA_TYPE_ TYPE_NAME_(Retorna_Proximo)(TYPE_NAME_(Vector_pt) a);

DATA_TYPE_ TYPE_NAME_(Retorna_Anterior)(TYPE_NAME_(Vector_pt) a);

DATA_TYPE_ TYPE_NAME_(Retorna_Enesima)(TYPE_NAME_(Vector_pt) a, int pos);

void TYPE_NAME_(Atribui_Valor)(TYPE_NAME_(Vector_pt) a, DATA_TYPE_ v,int pos);

void TYPE_NAME_(Atribui_ValrF)(TYPE_NAME_(Vector_pt) a, DATA_TYPE_ v);

TYPE_NAME_(Vector_pt) TYPE_NAME_(Elimina_Elemento)(TYPE_NAME_(Vector_pt) a, int pos);

DATA_TYPE_ TYPE_NAME_(Maior_Valor)(TYPE_NAME_(Vector_pt) v);

DATA_TYPE_ TYPE_NAME_(Menor_Valor)(TYPE_NAME_(Vector_pt) v);

int comparador2(const void *a, const void *b);


void  TYPE_NAME_(OrdernarVetor)(TYPE_NAME_(Vector_pt) v);

TYPE_NAME_(Vector_pt) TYPE_NAME_(intercala)(TYPE_NAME_(Vector_pt) a, TYPE_NAME_(Vector_pt) b);

int TYPE_NAME_(Valores_Iguais)(TYPE_NAME_(Vector_pt) a,DATA_TYPE_ val);

TYPE_NAME_(Vector_pt) TYPE_NAME_(Retorna_VetorI)(TYPE_NAME(Vector_pt) v,DATA_TYPE_ val);

TYPE_NAME_(Vector_pt) TYPE_NAME_(Soma_Vetores)(TYPE_NAME_(Vector_pt) a,TYPE_NAME_(Vector_pt) b);

DATA_TYPE_ Produto_Interno(TYPE_NAME_(Vector_pt) a, TYPE_NAME_(Vector_pt) b);

TYPE_NAME_(Vector_pt) Subtrae_Vetores(TYPE_NAME_(Vector_pt) a,TYPE_NAME_(Vector_pt) b);

TYPE_NAME_(Vector_pt) TYPE_NAME_(Multiplica_Escalar)(TYPE_NAME_(Vector_pt) a, DATA_TYPE_ k);

TYPE_NAME_(Vector_pt) TYPE_NAME_(Acumula_Soma)(TYPE_NAME_(Vector_pt) a, TYPE_NAME_(Vector_pt) b);

double TYPE_NAME_(Media)(TYPE_NAME_(Vector_pt) a);

double TYPE_NAME_(Variancia)(TYPE_NAME_(Vector_pt) a);

double TYPE_NAME_(Desvio_Padrao)(TYPE_NAME_(Vector_pt) a);

double TYPE_NAME_(MEDIANA) (TYPE_NAME_(Vector_pt) a);

void TYPE_NAME_(swap)(TYPE_NAME_(Vector_pt) a, int i, int j);

double TYPE_NAME_(partition)(TYPE_NAME_(Vector_pt) v, int inicio, int fim);

double TYPE_NAME_(torben)(TYPE_NAME_(Vector_pt) v, int n);

void TYPE_NAME_(quicksortMedianaDeTres)(TYPE_NAME_(Vector_pt) v, int inicio,int fim);


#endif
