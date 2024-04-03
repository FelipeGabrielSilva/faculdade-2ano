//Loja.cpp
#include <iostream>
using namespace std;
#include "Medida.h"
#include "Produto.h"


int main(){
    Medida medida;
    medida.imprimir();

    Medida medida1(12, "pacote");
    medida1.imprimir();

    Produto prod1;
    prod1.Medida::setId(10);
    prod1.Medida::setDescricao("Kilo");
    prod1.imprimir();

    Produto prod2(12, "Banana", 10, 8.9, 20, "kg");
    prod2.imprimir();



}
