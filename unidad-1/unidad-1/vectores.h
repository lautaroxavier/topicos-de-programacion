#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

void mostrarVector(int*, int);

int insertarEnPos(int * v, int pos, int ce, int elem, int tam);

int insertarOrdenado(int*, int, int, int);

int eliminarPos(int * v, int pos, int ce);

int eliminarElem(int * v, int ce, int elem);

int eliminarTodosElem(int * v, int ce, int elem);

#endif // VECTORES_H_INCLUDED
