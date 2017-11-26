#ifndef LIST2_0_DOTLIB_H
#define LIST2_0_DOTLIB_H

#include <cstdio>
#include "ListLib.h"

int DotListElLabel(FILE* , ListEl*);
int DotListElCon(FILE* , ListEl* out , ListEl* in);

int DotDumpList(List*);

#endif //LIST2_0_DOTLIB_H
