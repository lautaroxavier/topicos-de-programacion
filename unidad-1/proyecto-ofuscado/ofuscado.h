#ifndef OFUSCADO_INCLUDED
#define OFUSCADO_INCLUDED

char* __desofuscar(char* linea);
char despChr(char c, char* dic, int cant);
char* proximaPalabra(const char* cad, char** ini, char** fin);
void imprimirFragmento(char* ini, char* fin);
size_t obtenerLineaOfuscada(char* linea);
char* desofuscar(char* linea);

#endif // OFUSCADO_INCLUDED
