#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 6

unsigned long long int factorial(int n)
{
    unsigned long long fact = 1;
    for(int i = 1; i <=n; i++)
    {
        fact *= i;
    }
    return fact;
}

unsigned long long int combinatorio(unsigned long long int m, unsigned long long int n){
    return factorial(m)/(factorial(n)*factorial(m-n));
}

double eToXAprox(int exp, double tol){
    double result = 1;
    double termino = 0;
    int i = 1;
    do{
        termino = pow(exp,i)/factorial(i);
        result += termino;
        i++;
    }while(termino > tol);
    return result;
}

double raizCuadradaBabilonico(double num, double tol){
    double anterior = 1;
    double actual = 1;
    do{
        anterior = actual;
        actual = 0.5*(anterior + (num/anterior));
    }while(fabs(anterior - actual) > tol);
    return actual;
}

double seno(double angulo, double tol){
    double result = angulo;
    int i = 3;
    int signo = -1;
    double termino = 0;
    do{
        termino = signo * (pow(angulo,i)/factorial(i));
        result += termino;
        i += 2;
        signo *= -1;
    }while(fabs(termino) > tol);
    return result;
}



int main()
{
    return 0;
}
