#include <iostream>
#include <string.h>

using namespace std;

string copia(char nome1[], char nome2[]){
    strcpy(nome2, nome1);
    return nome2;
}

int main() {
    int tam = 45;
    char nome1[tam];
    char nome2[tam];

    cout << "\nInforme o seu nome: ";
    gets(nome1);

    copia(nome1, nome2);
    cout << "\nCopiando nome para o segundo vetor!\n";

    cout << "\nNome do segundo vetor: " << nome2 << endl;

    return 0;
}