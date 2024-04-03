#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char nome[] = "Felipe Gabriel da Silva";
    char nomeCp[24];

    cout << "\nO nome do primeiro veotor: " << nome << endl;
    cout << "\nO nome do segundo vetor: " << strcpy(nomeCp, nome) << endl;
    return 0;
}