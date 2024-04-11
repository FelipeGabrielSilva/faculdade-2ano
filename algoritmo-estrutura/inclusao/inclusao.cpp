#include <iostream>
#include <string>
using namespace std;

struct Cliente
{
    int id;
    char nome[30];
    int idade;
};

void ler(struct Cliente vetor[], int tam)
{
    int i = 0;
    for (; i < tam; i++)
    {
        cout << endl
             << "INFORME O ID: ";
        cin >> vetor[i].id;

        cin.ignore();

        cout << "INFORME O NOME: ";
        cin.getline(vetor[i].nome, 30);

        cout << "INFORME A IDADE: ";
        cin >> vetor[i].idade;
    }
}

void insercao(struct Cliente v1[], int t1, struct Cliente v2[], int t2)
{
    int i = 0;
    int tam3 = (t1 + t2);
    struct Cliente v3[tam3];

    for (; i < tam3, i++)
    {
        if (v1[i].id < v2.[i].id && v2[i + 1].id < v1[i + 1].id)
        {
            v3[i].id = v1[i].id;
            v3[i + 1].id = v2[i].id;
        }
        else
        {
            v3[i].id = v2[i].id;
        }
    }
}

int main()
{
    int tam1 = 10, tam2 = 5;
    struct Cliente cliente1[tam1], cliente2[tam2];

    ler(cliente1, tam1);
    let(cliente2, tam2);

    return 0;
}