#ifndef COMPLEXO_DOUBLE_H
#define COMPLEXO_DOUBLE_H

#undef COMPLEXO_H
#undef DATA_TYPE_
#undef TYPE_NAME_
#undef IO_FORMAT_

#define DATA_TYPE_ double
#define TYPE_NAME_(SOMETHING) D_ ## SOMETHING
#define IO_FORMAT_ "%lf "
#include "complexo.h"

#endif
