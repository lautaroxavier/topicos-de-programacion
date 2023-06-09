#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

char myIsAlpha(char); // retorna cero si no es una letra

char myToLower(char);

char myToUpper(char);

int myStrlen(const char *);

char * myStrcpy(char *, const char *);

int myStrcmp(const char *, const char *);

int myStrcmpi(const char *, const char *);

int myStrncmp(const char *, const char *, int n);

char * myStrcat(char * s, const char *ct);

char * myStrchr(const char * cs, char c);

char * myStrrchr(const char * cs, char c);

char * myStrstr(const char *, const char *);

int esPalindromo(const char * s1);

int contarSubcadenas(const char * s1, const char * s2);

char * proximaPalabra(const char * s1, const char ** start, const char ** ending);

#endif // CADENAS_H_INCLUDED
