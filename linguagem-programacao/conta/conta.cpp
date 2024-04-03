#include <iostream>
#include "conta.h";

using namespace std;

int main()
{
    Conta c1;

    c1.imprimir();

    Conta c2(15, "Nubank", 23443, 1000);
    c2.imprimir();

    /* acesso a valor de atributo de forma direta
    infringe regra de encapsulamento
    c1.id = 123;
    c1.banco = "Baralho Bank";
    c1.numeroConta = 120397;
    c1.saldo = 0; */

    cout << "Informacao da conta - BANCO: " << c1.getbanco();
    cout << "Informacao da conta - BANCO: " << c1.getbanco();

    return 0;
}