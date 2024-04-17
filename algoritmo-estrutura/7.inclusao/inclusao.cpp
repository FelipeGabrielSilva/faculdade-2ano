#include <iostream>
#include <string>
using namespace std;

struct Cliente
{
    int id;
    string nome;
};

void ler(struct Cliente vetor[], int tam)
{
    int i = 0;
    for (; i < tam; i++)
    {
        cout << endl
             << "INFORME O ID: ";
        cin >> vetor[i].id;

        cout << "INFORME O NOME: ";
        cin >> vetor[i].nome;
    }
}

void insercao(struct Cliente v1[], int t1, struct Cliente v2[], int t2, struct Cliente v3[], int t3)
{
    int cont = 0;

        for (int i = 0; i < t3; i++)
    {
        cout << endl
             << "EXIBINDO AS INFORMACOES ORGANIZADAS:" << endl;
        cout << "ID: " << v3[i].id << endl;
        cout << "NOME: " << v3[i].nome << endl;
    }
}

int main()
{
    int tam1 = 5, tam2 = 2, tam3 = (tam1 + tam2);
    struct Cliente cliente1[tam1], cliente2[tam2], cliente3[tam3];

    ler(cliente1, tam1);
    ler(cliente2, tam2);
    insercao(cliente1, tam1, cliente2, tam2, cliente3, tam3);

    return 0;
}