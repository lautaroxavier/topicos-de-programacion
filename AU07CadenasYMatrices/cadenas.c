int __esAnagrama(const char* cad1, const char* cad2){
    int ocurrenciasLetras[26] = {0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0};
    int * pOcurrencias = ocurrenciasLetras;
    // contar apariciones de cada letra en la primera cadena
    while(*cad1){
        if(isalpha(*cad1)){
            *(ocurrenciasLetras + tolower(*cad1) - 'a') += 1;
        }
        cad1++;
    }
    while(*cad2){
        if(isalpha(*cad2)){
            *(ocurrenciasLetras + tolower(*cad2) - 'a') -= 1;
        }
        cad2++;
    }
    for(int i = 0; i < 26; i++){
        if(*pOcurrencias != 0){
            return 0;
        }
        pOcurrencias++;
    }
    return 1;
}
