#include <iostream>

using namespace std;

class Carro
{
    // atributos
private:
    int id;
    string modelo;
    int ano;
    string cor;
    float valor;

    // protótipos dos metódos
public:
    void ler();
    void imprimir();

    string getModelo();
};

// métodos
void Carro::ler()
{
    cout << "INFORMACOES DO CARRO\n";

    cout << "ID: ";
    cin >> id;

    cout << "Modelo: ";
    cin >> modelo;

    cout << "Ano: ";
    cin >> ano;

    cout << "Cor: ";
    cin >> cor;

    cout << "Valor R$:";
    cin >> valor;
}

void Carro::imprimir()
{
    cout << "\nEXIBINDO INFORMACOES DO CARRO\n";
    cout << "ID: " << id << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Ano: " << ano << endl;
    cout << "Cor: " << cor << endl;
    cout << "Valor: " << valor << endl;
}

string Carro::getModelo()
{
    return modelo;
}