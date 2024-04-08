#include <iostream>
#include <string>

#ifndef TIPOIMOVEL_H
#define TIPOIMOVEL_H
#endif

class TipoImovel
{
    // Atributos
private:
    int id;
    string descricao;

    // Construtores e métodos
public:
    TipoImovel() : id(0), descricao(""){};
    TipoImovel(int, string);

    int getID() { return this->id; };
    string getDescricao() { return this->descricao; };

    void setID(int id) { this->id = id; };
    void setDescricao(string desc) { this->descricao = desc; }

    void imprimir();
    void leitura(int, string);
};

TipoImovel::TipoImovel(int id, string desc)
{
    this->id = id;
    this->descricao = desc;
}

void TipoImovel::imprimir()
{
    cout << "\n\nTIPO DE IMOVEL:" << endl;
    cout << "ID: " << this->id << endl;
    cout << "DESCRICAO: " << this->descricao;
}

void TipoImovel::leitura(int id, string desc)
{
    cout << "\n\nInforme o ID: ";
    cin >> id;

    cout << "Descricao: ";
    cin >> desc;
}