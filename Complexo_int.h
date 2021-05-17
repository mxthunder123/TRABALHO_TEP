#ifndef COMPLEXO_INT_H
#define COMPLEXO_INT_H

#undef COMPLEXO_H
#undef DATA_TYPE_
#undef TYPE_NAME_
#undef IO_FORMAT_

#define DATA_TYPE_ long int
#define TYPE_NAME_(SOMETHING) I_ ## SOMETHING
#define IO_FORMAT_ "%ld "
#include "complexo.h"

#endif