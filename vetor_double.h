#ifndef VETOR_DOUBLE_H
#define VETOR_DOUBLE_H

#undef VETOR_H
#undef DATA_TYPE_
#undef TYPE_NAME_ 
#undef IO_FORMAT_

// Definicao do tipo do vetor nativo da linguagem 
#define DATA_TYPE_ double
#define TYPE_NAME_(SOMETHING) D_ ## SOMETHING
#define TYPE_NAME_ "%lf"

#include "vetor.h"

#endif