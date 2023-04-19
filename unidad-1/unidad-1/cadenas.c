#include "cadenas.h"

char myIsAlpha(char c){
    if(((c >= 65) && (c <= 90)) ||
       ((c >= 97) && (c <= 122))){
       return 1;
    }
    return 0;
}

char myToLower(char c){
    if(c >= 65 && c <= 90){
        return (c + 32);
    }
    return c;
}

char myToUpper(char c){
    if(c >= 97 && c <= 122){
        return (c - 32);
    }
    return c;
}

int myStrlen(const char * c){
    int result = 0;
    while(*c){
        c++;
        result++;
    }
    return result;
}

char *myStrcpy(char * s1, const char * s2){
    char * res = s1;
    while(*s2){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = *s2;
    return res;
}

int myStrcmp(const char * s1, const char * s2){
    int cmp = 0;
    while(*s1){
        int cmp = *s1 - *s2;
        if(cmp != 0){
            return cmp;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int myStrcmpi(const char * s1, const char * s2){
    int cmp = 0;
    while(*s1){
        int cmp = myToLower(*s1) - myToLower(*s2);
        if(cmp != 0){
            return cmp;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}




