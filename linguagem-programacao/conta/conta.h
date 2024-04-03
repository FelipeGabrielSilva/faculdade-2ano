#include <iostream>
// Conta báncaria

using namespace std;

class Conta
{
    // atributos
private:
    int id;
    string banco;
    int numeroConta;
    float saldo;

    // Métodos
public:
    Conta();
    Conta(int, string, int, float);
    Conta(int, string, int);

    // Métodos get para acesso
    int getID() { return this->id; }
    string getbanco() { return this->banco; }
    int getNumeroConta() { return this->numeroConta; }
    float getSaldo() { return this->saldo; }

    // Métodos set para modificações
    int setID(int);
    string setBanco(string);
    int setNumeroConta(int);
    float setSaldo(float);

    void imprimir();
};

Conta::Conta()
{
    this->id = 0;
    this->banco = "";
    this->numeroConta = 0;
    this->saldo = 0;
}

Conta::Conta(int id, string banco, int numeroConta, float saldo)
{
    this->id = id;
    this->banco = banco;
    this->numeroConta = numeroConta;
    this->saldo = saldo;
}

int Conta::setID(int id)
{
    return this->id = id;
}

string Conta::setBanco(string banco)
{
    return this->banco = banco;
}

int Conta::setNumeroConta(int numeroConta)
{
    return this->numeroConta = numeroConta;
}

float Conta::setSaldo(float saldo)
{
    return this->saldo = saldo;
}

void Conta::imprimir()
{
    cout << "\nImprimir conta\n";
    cout << "\nID: " << id << endl;
    cout << "Banco: " << banco << endl;
    cout << "Numero da conta: " << numeroConta << endl;
    cout << "Saldo: R$" << saldo << endl;
}