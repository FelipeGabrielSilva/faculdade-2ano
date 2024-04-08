#include <iostream>
#include <string>

#ifndef IMOVEL_H
#include "Imovel.h"
#endif

#ifndef LOCADOR_H
#include "Locador.h"
#endif

#ifndef LOCACAO_H
#define LOCACAO_H
#endif

class Locacao
{
    // atributos
private:
    int id;
    Imovel imovel;
    Locador locador;
    string data;
    float valor;

public:
    Locacao();
    Locacao(int, Imovel, Locador, string, float);

    int getID() { return this->id; }
    Imovel getImovel() { return this->imovel; }
    string getData() { return this->data; }
    float getValor() { return this->valor; }

    void setID(int id) { this->id = id; }
    void setData(string data) { this->data = data; }
    void setValor(float valor) { this->valor = valor; }

    void imprimir();
};

Locacao::Locacao()
{
    this->id = 0;
    this->data = "";
    this->valor = 0;
}

Locacao::Locacao(int id, Imovel imovel, Locador locador, string data, float valor)
{
    this->id = id;
    this->imovel = imovel;
    this->locador = locador;
    this->data = data;
    this->valor = valor;
}

void Locacao::imprimir()
{
    cout << "\n\nINFORMACOES DA LOCACAO";
    cout << "\nID: " << this->id;
    cout << "\nDATA: " << this->data;
    cout << "\nVALOR: " << this->valor;
    imovel.imprimir();
    locador.imprimir();
}