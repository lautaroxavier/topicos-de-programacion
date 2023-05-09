#include <stdlib.h>
#include <string.h>
#include "ofuscado.h"
char* __desofuscar(char* linea){
    char* start = linea;
    char* end;
    int i;
    char* dicc = "abcdghijkoqtuv";
    proximaPalabra(start,&start,&end);
    do{
        // recorrer palabra
        i = 1;
        while(start != end+1){
            *start = despChr(*start, dicc, i);
            start++;
            i++;
        }
        // avanzar al siguiente caracter despues de la palabra
        start++;
        proximaPalabra(start,&start,&end);
    }while(start);
    return linea;
}
