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
        cmp = *s1 - *s2;
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
        cmp = myToLower(*s1) - myToLower(*s2);
        if(cmp != 0){
            return cmp;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int myStrncmp(const char *s1, const char *s2, int n){
    int cmp = 0;
    while(*s1 && n > 0){
        int cmp = myToLower(*s1) - myToLower(*s2);
        if(cmp != 0){
            return cmp;
        }
        s1++;
        s2++;
        n--;
    }
    return cmp;
}

char * myStrcat(char * s, const char *ct){
    char * writePos = s;
    const char * readPos = ct;
    while(*writePos){
        writePos++;
    }
    while(*readPos){
        *writePos = *readPos;
        writePos++;
        readPos++;
    }
    *writePos = *readPos;
    return s;
}

char * myStrchr(const char * cs, char c){
    const char * readPos = cs;
    while(*readPos){
        if(*readPos == c){
            return (char*)readPos;
        }
        readPos++;
    }
    return (char*)readPos;
}

char * myStrrchr(const char * cs, char c){
    const char * readPos = cs;
    char * res = '\0';
    while(*readPos){
        if(*readPos == c){
            res = (char*)readPos;
        }
        readPos++;
    }
    return res;
}

char * myStrstr(const char * cs, const char * ct){
    while(*cs){
        if(*cs == *ct){
            const char * p1 = cs;
            const char * p2 = ct;
            while(*p2 && *p1 == *p2){
                p1++;
                p2++;
            }
            if(!(*p2)){
                return (char*)cs;
            }
        }
        cs++;
    }
    return 0;
}

int esPalindromo(const char * s1){
    const char * p1 = s1;
    const char * p2 = s1 + myStrlen(s1) - 1;
    while(p1 < p2){
        while(p1 < p2 && !myIsAlpha(*p1)){
            p1++;
        }
        while(p1 < p2 && !myIsAlpha(*p2)){
            p2--;
        }
        if(myToLower(*p1) != myToLower(*p2)){
            return 0;
        }
        p1++;
        p2--;
    }
    return 1;
}

int contarSubcadenas(const char * s1, const char * s2){
    int cantSubcadenas = 0;
    while(*s1){
        if(*s1 == *s2){
            const char * p1 = s1;
            const char * p2 = s2;
            while(*p2 && *p1 == *p2){
                p1++;
                p2++;
            }
            if(!(*p2)){
                cantSubcadenas++;
            }
        }
        s1++;
    }
    return cantSubcadenas;
}

char * proximaPalabra(const char * s1, const char ** start, const char ** ending){
    while(*s1){
        if(myIsAlpha(*s1)){
            const char * pStart = s1;
            const char * pEnd = s1;
            while(myIsAlpha(*pEnd)){
                pEnd++;
            }
            *start = pStart;
            *ending = pEnd - 1;
            return (char *)s1;
        }
        s1++;
    }
    *start = 0;
    return (char *)s1;
}
