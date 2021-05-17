
#ifndef COMPLEXO_H

#define COMPLEXO_H


typedef struct TYPE_NAME_(Complexo_st) *TYPE_NAME_(Complexo_pt);


TYPE_NAME_(Complexo_pt) TYPE_NAME_(Cria_Complexo) (DATA_TYPE_ r, DATA_TYPE_ i);


void TYPE_NAME_(Destroi_Complexo)(TYPE_NAME_(Complexo_pt) r);


TYPE_NAME_(Complexo_pt) TYPE_NAME_(Atribui_Complexo) (TYPE_NAME_(Complexo_pt) a,TYPE_NAME_(Complexo_pt) b);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(AtribuiNovo_Complexo) (TYPE_NAME_(Complexo_pt) a);

int TYPE_NAME_ (Compara_ImagN) (TYPE_NAME_(Complexo_pt) c);

int TYPE_NAME_(Compara_RealN) (TYPE_NAME_(Complexo_pt) c);

int TYPE_NAME_ (Compara_RealN) (TYPE_NAME_(Complexo_pt) c);


double TYPE_NAME_ (Calcula_Modulo) (TYPE_NAME_(Complexo_pt) r);

double TYPE_NAME_ (Angulo) (TYPE_NAME_(Complexo_pt) c);

int TYPE_NAME_ (Compara_ModuloN) (TYPE_NAME_(Complexo_pt) c);

int TYPE_NAME_ (Diferenca_Modulo) (TYPE_NAME_(Complexo_pt) a, TYPE_NAME_(Complexo_pt) b);

int TYPE_NAME_ (Diferenca_Angulo) (TYPE_NAME_(Complexo_pt) a, TYPE_NAME_(Complexo_pt) b);

DATA_TYPE_ TYPE_NAME_(Retorna_Real)(TYPE_NAME_(Complexo_pt) c);

DATA_TYPE_ TYPE_NAME_(Retorna_Imag)(TYPE_NAME_(Complexo_pt) c);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(Troca_Real)(TYPE_NAME_(Complexo_pt) c, DATA_TYPE_ n);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(Troca_Imag)(TYPE_NAME_(Complexo_pt) c, DATA_TYPE_ n);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(Soma_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(Subtrae_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2,TYPE_NAME_(Complexo_pt) res);


TYPE_NAME_(Complexo_pt) TYPE_NAME_(Multiplica_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(Divide_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(SomaA_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(MultiplicaA_Complexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, TYPE_NAME_(Complexo_pt) res);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(OperacaoComplexoComplexo)(TYPE_NAME_(Complexo_pt) num1, TYPE_NAME_(Complexo_pt) num2, char *oper);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(Conjugado)(TYPE_NAME_(Complexo_pt) c, TYPE_NAME_(Complexo_pt) res);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(Modificar_Angulo)(TYPE_NAME_(Complexo_pt) a, double angulo);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(Modificar_Modulo)(TYPE_NAME_(Complexo_pt) a, double modulo);


void TYPE_NAME_(Escrever_Complexo)(TYPE_NAME_(Complexo_pt) v, FILE* saida);

TYPE_NAME_(Complexo_pt) TYPE_NAME_(Ler_Complexo)(TYPE_NAME_(Complexo_pt) v, FILE* saida);

#undef COMPLEXO_H

#endif
