#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char x [] = "Feliz aniversario para voce";
    char y[28], z[18], w[28];

    cout << "A string do vetor x = " << x << endl;
    cout << "\nA string do vetor y = " << strcpy(y, x) << endl;

    strncpy(z, x, 17);
    z[17] = '\0'; //inserindo a condição de parada no vetor copiado

    cout << "\nA string do vetor z = " << z << endl;

    strncpy(w, x, 17);
    cout << "\nA string do vetor w = " << w << endl;

    w[17] = '\0'; //inserindo a condição de parada no vetor copiado
    cout << "\nA string do vetor w apos caractere null = " << w << endl;

    return 0;
}

/* strcpy(A, B) 
essa função tem como finalidade 
copiar os elementos do vetor B 
para o vetor A, não copia '\0' 
que é a condição de parada
*/

/* strncpy(A, B, 10)
essa função tem como finalidade copiar os elementos 
do vetor B para o vetor A, porém com uma quantidade 
limite do que se pode copiar porém não copia '\0' 
que é a condição de parada */