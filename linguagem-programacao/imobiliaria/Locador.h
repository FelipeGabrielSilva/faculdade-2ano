#include <iostream>
#include <string>

#ifndef PROFISSAO_H
#include "Profissao.h"
#endif

#ifndef LOCADOR_H
#define LOCADOR_H
#endif

class Locador : public Profissao
{
    // atributos (agregados)
private:
    int id;
    string nome;
    string cidade;
    string estado;
    int idade;
    float salario;
    Profissao idP;
    Profissao descP;

    // construtores e métodos
public:
    Locador();
    Locador(int, string, string, string, int, float, Profissao);
    Locador(int, string, string, string, int, float, int, string);

    int getID() { return this->id; }
    string getNome() { return this->nome; }
    string getCidade() { return this->cidade; }
    string getEstado() { return this->estado; }
    int getIdade() { return this->idade; }
    float getSalario() { return this->salario; }

    void setID(int id) { this->id = id; }
    void setNome(string nome) { this->nome = nome; }
    void setCidade(string cidade) { this->cidade = cidade; }
    void setEstado(string estado) { this->estado = estado; }
    void setIdade(int idade) { this->idade = idade; }
    void setSalario(float salario) { this->salario = salario; }

    void imprimir();
    void leitura();
};

Locador::Locador()
{
    this->id = 0;
    this->nome = "";
    this->cidade = "";
    this->estado = "";
    this->idade = 0;
    this->salario = 0;
}

Locador::Locador(int id, string nome, string cidade, string estado, int idade, float salario, Profissao tipo)
{
    this->id = id;
    this->nome = nome;
    this->cidade = cidade;
    this->estado = estado;
    this->idade = idade;
    this->salario = salario;
    this->idP = tipo;
    this->descP = tipo;
}

Locador::Locador(int id, string nome, string cidade, string estado, int idade, float salario, int idP, string descP)
{
    this->id = id;
    this->nome = nome;
    this->cidade = cidade;
    this->estado = estado;
    this->idade = idade;
    this->salario = salario;
    this->idP.setID(idP);
    this->descP.setDescricao(descP);
}

void Locador::imprimir()
{
    cout << "\n\nINFORMACOES DO LOCADOR:";
    cout << "\nID: " << this->id;
    cout << "\nNOME: " << this->nome;
    cout << "\nCIDADE: " << this->cidade;
    cout << "\nESTADO: " << this->estado;
    cout << "\nIDADE: " << this->idade;
    cout << "\nSALARIO: " << this->salario;
    cout << "\nID PROFISSAO: " << idP.getID();
    cout << "\nDESCRICAO: " << descP.getDescricao();
}

void Locador::leitura()
{
    cout << "\n\nInforme o ID: ";
    cin >> this->id;

    cout << "\nNOME: ";
    cin >> this->nome;

    cout << "\nCIDADE: ";
    cin >> this->cidade;

    cout << "\nESTADO: ";
    cin >> this->estado;

    cout << "\nIDADE: ";
    cin >> this->idade;

    cout << "\nSALARIO: ";
    cin >> this->salario;
}