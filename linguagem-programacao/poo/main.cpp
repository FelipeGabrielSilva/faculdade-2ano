#include <iostream>
#include "carro.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Carro car1;
    car1.ler();
    car1.imprimir();

    return 0;
}
