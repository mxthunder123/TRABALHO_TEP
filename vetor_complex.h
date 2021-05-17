#ifndef VETOR_COMPLEX_H
#define VETOR_COMPLEX_H

typedef struct TYPE_NAME_(VETOR_Vector_st) * TYPE_NAME_VETOR_(Vector_pt);


TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Ajusta_Vetor)(TYPE_NAME_VETOR_(Vector_pt) a);


TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Cria_Vetor)(int n);


void TYPE_NAME_VETOR_(Destroi_Vector)(TYPE_NAME_VETOR_(Vector_pt) s);


void TYPE_NAME_VETOR_(Apaga_Vetor)(TYPE_NAME_VETOR_(Vector_pt) v);


TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Copia_Vector)(TYPE_NAME_VETOR_(Vector_pt) a,TYPE_NAME_VETOR_(Vector_pt) b);


TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Copia_Novo)(TYPE_NAME_VETOR_(Vector_pt) a);


int TYPE_NAME_VETOR_(Numero_ElementosA)(TYPE_NAME_VETOR_(Vector_pt) a);


int TYPE_NAME_VETOR_(Numero_ElementosN)(TYPE_NAME_VETOR_(Vector_pt a));


int TYPE_NAME_VETOR_(Numero_ElementoI)(TYPE_NAME_VETOR_(Vector_pt) a);


DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Primeiro)(TYPE_NAME_VETOR_(Vector_pt) a);


DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Ultimo)(TYPE_NAME_VETOR_(Vector_pt) a);


DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Proximo)(TYPE_NAME_VETOR_(Vector_pt) a);


DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Anterior)(TYPE_NAME_VETOR_(Vector_pt) a);


DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Retorna_Enesima)(TYPE_NAME_VETOR_(Vector_pt) a, int pos);


void TYPE_NAME_VETOR_(Atribui_Valor)(TYPE_NAME_VETOR_(Vector_pt) a, DATA_TYPE_VETOR_ v,int pos);


void TYPE_NAME_VETOR_(Atribui_ValrF)(TYPE_NAME_VETOR_(Vector_pt) a, DATA_TYPE_VETOR_ v);


TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Elimina_Elemento)(TYPE_NAME_VETOR_(Vector_pt) a, int pos);


DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Maior_Valor)(TYPE_NAME_VETOR_(Vector_pt) v);


DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Menor_Valor)(TYPE_NAME_VETOR_(Vector_pt) v);

int comparador2(const void *a, const void *b) ;

void  TYPE_NAME_VETOR_(OrdernarVetor)(TYPE_NAME_VETOR_(Vector_pt) v);

int TYPE_NAME_VETOR_(Valores_Iguais)(TYPE_NAME_VETOR_(Vector_pt) a,DATA_TYPE_VETOR_ val);

int * TYPE_NAME_VETOR_(Retorna_VetorI)(TYPE_NAME_VETOR_(Vector_pt) v,DATA_TYPE_VETOR_ val);

TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Soma_Vetores)(TYPE_NAME_VETOR_(Vector_pt) a,TYPE_NAME_VETOR_(Vector_pt) b);

DATA_TYPE_VETOR_ Produto_Interno(TYPE_NAME_VETOR_(Vector_pt) a, TYPE_NAME_VETOR_(Vector_pt) b);

TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Subtrae_Vetores)(TYPE_NAME_VETOR_(Vector_pt) a,TYPE_NAME_VETOR_(Vector_pt) b);

TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Multiplica_Escalar)(TYPE_NAME_VETOR_(Vector_pt) a, DATA_TYPE_VETOR_ k);

TYPE_NAME_VETOR_(Vector_pt) TYPE_NAME_VETOR_(Acumula_Soma)(TYPE_NAME_VETOR_(Vector_pt) a, TYPE_NAME_VETOR_(Vector_pt) b);

DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Media)(TYPE_NAME_VETOR_(Vector_pt) a);

DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Variancia)(TYPE_NAME_VETOR_(Vector_pt) a);

DATA_TYPE_VETOR_ TYPE_NAME_VETOR_(Desvio_Padrao)(TYPE_NAME_VETOR_(Vector_pt) a);

double TYPE_NAME_VETOR_(MEDIANA) (TYPE_NAME_VETOR_(Vetor_pt) v);

#endif