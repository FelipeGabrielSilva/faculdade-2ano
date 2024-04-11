#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Pessoa
{
    int id;
    char nome[30];
    char endereco[30];
    char cidade[20];
    char uf[2];
};

void lerInformacao(int tam, struct Pessoa x[])
{
    for (int i = 0; i < tam; i++)
    {
        cout << "\nDigite o ID: ";
        cin >> x[i].id;

        cin.ignore();

        cout << "Digite o nome: ";
        cin.getline(x[i].nome, 30);

        cout << "Digite o endereco: ";
        cin.getline(x[i].endereco, 30);

        cout << "Digite o cidade: ";
        cin.getline(x[i].cidade, 20);

        cout << "Digite o UF: ";
        cin.getline(x[i].uf, 3);
    }
}

void buscarInformacao(int tam, struct Pessoa x[])
{
    int buscarID;
    cout << "\nInforme o ID para buscar: ";
    cin >> buscarID;
    int i = 0, f = tam;
    int m = (i + f) / 2;

    for (; f > i && buscarID != x[m].id; m = (i + f) / 2)
    {
        if (buscarID > x[m].id)
            i = m + 1;
        else
            f = m - 1;
    }

    if (buscarID == x[m].id)
    {
        cout << "\nPESSOA ENCONTRADA: ";
        cout << "\nID: " << x[m].id;
        cout << "\nNOME: " << x[m].nome;
        cout << "\nENDERECO: " << x[m].endereco;
        cout << "\nCIDADE: " << x[m].cidade;
        cout << "\nUF: " << x[m].uf;
    }
    else
    {
        cout << "\nPESSOA NAO ENCOTRADA. USUARIO NAO EXISTE.";
    }
}

int main()
{
    int tam = 12;
    struct Pessoa vPessoas[tam];

    lerInformacao(tam, vPessoas);
    buscarInformacao(tam, vPessoas);

    return 0;
}