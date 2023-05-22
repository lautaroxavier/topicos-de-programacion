#ifndef HIGHER-ORDER_H_INCLUDED
#define HIGHER-ORDER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void * forEach(void * vec, size_t ce, size_t tam, void (f)(void*));

void * reduce(void * vec, void * acum, size_t ce, size_t tam, void (accion)(void* elem, void* acum));

int filter(void * vec, size_t ce, size_t tam, int (*comp)(void * a));

#endif // HIGHER-ORDER_H_INCLUDED
