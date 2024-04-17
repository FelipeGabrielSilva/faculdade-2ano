#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Arquivo
{
    int id;
    char nome[30];
    char end[30];
    char cidade[30];
    char uf[2];
};

void infoAquivo(struct Arquivo x[], int y)
{
    for (int i = 0; i < y; i++)
    {
        x[i].id = (i+1);

        cout<< endl << "Informe o nome: ";
        cin.getline(x[i].nome, 30);

        cout << "Informe o endereco: ";
       cin.getline(x[i].end, 30);
       

        cout << "Informe a cidade: ";
        cin.getline(x[i].cidade, 30);

        cout << "Informe o estado (UF): ";
        cin.getline(x[i].uf, 3);
    }

    char prox;
    cout << "\nPressione x para prosseguir: ";
    cin >> prox;

    if (prox == 'x')
    {
        system("cls");
    }
}

void exibirArquivo(struct Arquivo x[], int y)
{
    for (int i = 0; i < y; i++)
    {
        cout << "ID: " << x[i].id << endl;
        cout << "Nome: " << x[i].nome << endl;
        cout << "Endereco: " << x[i].end << endl;
        cout << "Cidade: " << x[i].cidade << endl;
        cout << "Estado (UF): " << x[i].uf << endl;
    }

    char prox;
    cout << endl << "Pressione 0 para finalizar: ";
    cin >> prox;

    if (prox == '0')
    {
        system("cls");
    }
}

int main()
{
    int tam = 1;
    struct Arquivo registro[tam];

    infoAquivo(registro, tam);
    exibirArquivo(registro, tam);

    return 0;
}