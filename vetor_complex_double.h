#ifndef VETOR_COMPLEX_INT_H
#define VETOR_COMPLEX_INT_H

#undef VETOR_COMPLEX_H
#undef TYPE_NAME_VETOR_
#undef DATA_TYPE_VETOR_ 
#undef DATA_TYPE_
#undef TYPE_NAME_
#undef IO_FORMAT_

#include "Complexo_double.h"

#define DATA_TYPE_VETOR_ D_Complexo_pt
#define TYPE_NAME_VETOR_(SOMETHING) D_Complex_ ## SOMETHING

#define DATA_TYPE_ double
#define TYPE_NAME_(SOMETHING) D_ ## SOMETHING
#define IO_FORMAT_ "%lf"



#include "vetor_complex.h"

#endif