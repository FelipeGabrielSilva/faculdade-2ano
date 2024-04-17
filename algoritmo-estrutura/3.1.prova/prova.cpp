#include <iostream>
using namespace std;

struct Cliente
{
    string nome;
    int telefone;
    int qtdPessoa;
    int restAlimentar;
};

void lerReserva(int tam, struct Cliente vetor[])
{
    for (int i = 0; i < tam; i++)
    {
        cout << "\nNome da reserva: ";
        cin >> vetor[i].nome;

        cout << "\nTelefone: ";
        cin >> vetor[i].telefone;

        cout << "\nQuantidade de pessoas: ";
        cin >> vetor[i].qtdPessoa;

        cout << "\nRestricao alimentar: \n1-Normal \n2-Sem gluten \n3-Diabetico";
        cin >> vetor[i].restAlimentar;
    }
};

int infoReserva(int tam, struct Cliente vetor[], int restr2, int contRt2, int restr3, int contRt3, int qtdTotal)
{
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i].restAlimentar == 2)
        {
            cout << "Informe a quantidade de pessoas com a restricao sem gluten: ";
            cin >> restr2;
            contRt2 += restr2;
        }
        else if (vetor[i].restAlimentar == 3)
        {
            cout << "Informe a quantidade de pessoas com a restricao diabetico: ";
            cin >> restr3;
            contRt3 += restr3;
        }

        qtdTotal += vetor[i].qtdPessoa;
    }

    cout << "Quantidade de pessoas com dieta sem gluten: " << contRt2;
    cout << "Quantidade de pessoas com dieta diabetica: " << contRt3;
    cout << "Total quantidade de pessoas: " << qtdTotal;
};

int main()
{
    int tam = 2;
    int qtdSG = 0;
    int contSG = 0;
    int qtdDb = 0;
    int contDb = 0;
    int qtdTotal = 0;

    struct Cliente vetorReserva[tam];
    lerReserva(tam, vetorReserva);
    infoReserva(tam, vetorReserva, qtdSG, contSG, qtdDb, contDb, qtdTotal);
}