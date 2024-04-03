//Sistema.cpp
#include <iostream>
using namespace std;
#include "Tipo.h"
#include "Pessoa.h"
#include "PessoaAgr.h"

int main() {
    Tipo tipo1;
    tipo1.imprimir();

    Tipo tipo2(2, "Professor");
    tipo2.imprimir();

    tipo1.setId(1);
    tipo1.setDescricao("Aluno");
    tipo1.imprimir();

    Pessoa pessoa1;
    pessoa1.imprimir();

    //pessoa1.Tipo::id = 10; //infringe encapuslamento

    pessoa1.setId(10);
    pessoa1.setDescricao("Funcionario");
    pessoa1.imprimir();

    Pessoa pessoa2(12, "Mirelle", 20, Tipo(14, "Cliente"));
    pessoa2.imprimir();

    Pessoa pessoa3(15, "Gabriel", 20, tipo1);

    Pessoa pessoa4(16, "Gustavo", 19, 30, "Programador");
    pessoa4.imprimir();

    PessoaAgr pesagr1;
    pesagr1.imprimir();

    PessoaAgr pesAgr2(15, "Gabriel", 20, Tipo(10, "Aluno"));
    pesAgr2.imprimir();

    Tipo tipo4(26, "Bombeiro");
    PessoaAgr pesAgr3(20, "Mirelle", 19, tipo4);
    pesAgr3.imprimir();

    cout << "\nA pessoa " << pesAgr3.getNome() << " e "
         << pesAgr3.getTipo().getDescricao() << endl;

    pesAgr3.setTipo(Tipo(30, "Dentista"));
    pesAgr3.imprimir();

    Tipo tipo5(40, "Programador");
    pesAgr3.setTipo(tipo5);
    cout << "\nA pessoa " << pesAgr3.getNome() << " e "
         << pesAgr3.getTipo().getDescricao() << endl;


}

