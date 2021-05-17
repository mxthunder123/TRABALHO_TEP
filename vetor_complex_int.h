#ifndef VETOR_COMPLEX_INT_H
#define VETOR_COMPLEX_INT_H

#undef VETOR_COMPLEX_H
#undef TYPE_NAME_VETOR_
#undef DATA_TYPE_VETOR_
#undef DATA_TYPE_ 
#undef TYPE_NAME_
#undef IO_FORMAT_

#include "Complexo_int.h"

#define DATA_TYPE_VETOR_ I_Complexo_pt
#define TYPE_NAME_VETOR_(SOMETHING) I_Complex_ ## SOMETHING

#define DATA_TYPE long int
#define TYPE_NAME_ (SOMETHING) I_ ## SOMETHING
#define IO_FORMAT_ "%ld"



#include "vetor_complex.h"

#endif