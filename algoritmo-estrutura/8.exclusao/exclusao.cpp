#include <iostream>
#include <string.h>
using namespace std;

struct Pessoa
{
    int id;
    char nome[30];
};

void ler(struct Pessoa v[], int &tam)
{
    int i = 0;
    for (; i < tam; i++)
    {
        cout << "\nDigite o codigo: ";
        cin >> v[i].id;

        cout << "Digite o nome: ";
        cin >> v[i].nome;
    }
}

void exibir(struct Pessoa v[], int &tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << "\nCodigo: " << v[i].id << endl;
        cout << "Nome: " << v[i].nome << endl;
    }
}

int exclusao(struct Pessoa v1[], int &tam1, struct Pessoa v2[], int &tam2, struct Pessoa v3[])
{
    int i = 0, j = 0, k = 0;

    for (; j < tam2; k++)
    {
        if (v1[i].id == v2[j].id)
        {
            i++;
            j++;
        }
        else if (v1[i].id < v2[j].id)
        {
            v3[k].id = v1[i].id;
            strcpy(v3[k].nome, v1[i].nome);
            i++;
            k++;
        }
        else
        {
            v3[k].id = v2[j].id;
            strcpy(v3[k].nome, v2[j].nome);
            j++;
        }
    }

    while (i < tam1)
    {
        v3[k].id = v1[i].id;
        strcpy(v3[k].nome, v1[i].nome);
        k++;
        i++;
    }
}

int main()
{
    int tam1 = 4, tam2 = 2, tam3 = (tam1 - tam2);
    struct Pessoa vPessoa1[tam1], vPessoa2[tam2], vPessoa3[tam3];

    cout << "Insira as informacoes da primeira lista: ";
    ler(vPessoa1, tam1);

    cout << "\nInformacao a ser excluida: ";
    ler(vPessoa2, tam2);

    cout << "\nLista com elementos excluidos: ";
    exclusao(vPessoa1, tam1, vPessoa2, tam2, vPessoa3, tam3);
    exibir(vPessoa3, tam3);

    return 0;
}