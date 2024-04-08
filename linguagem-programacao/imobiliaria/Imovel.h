#include <iostream>
#include <string>

#ifndef IMOVEL_H
#define IMOVEL_H
#endif

#ifndef TIPOIMOVEL_H
#include "TipoImovel.h"
#endif

class Imovel : public TipoImovel
{
    // Atributos 
private:
    int id;
    string rua;
    string bairro;
    string cidade;
    bool ocupado;
    TipoImovel tipo;
    
    // Construtores e métodos
public:
    Imovel();
    Imovel(int, string, string, string, bool, TipoImovel);

    int getID() { return this->id; }
    string getRua() { return this->rua; }
    string getBairro() { return this->bairro; }
    string getCidade() { return this->cidade; }
    bool getOcupado() { return this->ocupado; }

    void setID(int id) { this->id = id; }
    void setRua(string rua) { this->rua = rua; }
    void setBairro(string bairro) { this->bairro = bairro; }
    void setCidade(string cidade) { this->cidade = cidade; }
    void setOcupado(bool ocupado) { this->ocupado = ocupado; }

    void imprimir();
    void leitura();
};

Imovel::Imovel()
{
    this->id = 0;
    this->rua = "";
    this->bairro = "";
    this->cidade = "";
    this->ocupado = false;
}

Imovel::Imovel(int id, string rua, string bairro, string cidade, bool ocupado, TipoImovel tipo)
{
    this->id = id;
    this->rua = rua;
    this->bairro = bairro;
    this->cidade = cidade;
    this->ocupado = ocupado;
    this->tipo = tipo;
}

void Imovel::imprimir()
{
    cout << "\n\nINFORMACOES DO IMOVEL";
    cout << "\nID: " << this->id;
    cout << "\nRUA: " << this->rua;
    cout << "\nBAIRRO: " << this->bairro;
    cout << "\nCIDADE: " << this->cidade;
    cout << "\nOCUPADO: " << (this->ocupado ? "Sim" : "Nao");
    cout << "\nID TIPO: " << tipo.getID();
    cout << "\nDESCRICAO IMOVEL: " << tipo.getDescricao();
}

void Imovel::leitura()
{
    cout << "\n\nInforme o ID: ";
    cin >> this->id;

    cout << "Rua: ";
    cin >> this->rua;

    cout << "Bairro: ";
    cin >> this->bairro;

    cout << "Cidade: ";
    cin >> this->cidade;

    cout << "Ocupado (sim = true / nao = false): ";
    cin >> this->ocupado;
}