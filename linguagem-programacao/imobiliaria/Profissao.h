#include <iostream>
#include <string>

#ifndef PROFISSAO_H
#define PROFISSAO_H
#endif

class Profissao
{
    // Atributos
private:
    int id;
    string descricao;

    // Construtores e métodos
public:
    Profissao() : id(0), descricao("") {}
    Profissao(int, string);

    int getID() { return this->id; }
    string getDescricao() { return this->descricao; }

    void setID(int id) { this->id = id; }
    void setDescricao(string desc) { this->descricao = desc; }

    void imprimir();
    void leitura();
};

Profissao::Profissao(int id, string descricao)
{
    this->id = id;
    this->descricao = descricao;
}

void Profissao::imprimir()
{
    cout << "\n\nINFORMACOES DA PROFISSAO";
    cout << "\nID: " << this->id;
    cout << "\nDESCRICAO: " << this->descricao;
}

void Profissao::leitura()
{
    cout << "\n\nInforme o ID: ";
    cin >> this->id;

    cout << "Descricao: ";
    cin >> this->descricao;
}