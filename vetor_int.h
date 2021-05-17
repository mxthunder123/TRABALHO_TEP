#ifndef VETOR_INT_H
#define VETOR_INT_H

#undef VETOR_H
#undef DATA_TYPE_
#undef TYPE_NAME_
#undef IO_FORMAT_

/* Definicao do tipo de vetor nativo da linguagem*/ 
#define DATA_TYPE_ long int
#define TYPE_NAME_(SOMETHING) I_ ## SOMETHING
#define IO_FORMAT_ "%ld"

#include "vetor.h"

#endif