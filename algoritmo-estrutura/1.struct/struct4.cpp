#include <iostream>
#include <string.h>

using namespace std;

struct pessoa
{
    char nome[30];
    int idade;
    char endereco[50];
};

void exibindoInformacoes(const pessoa &p)
{
    cout << "\n-----Informacoes-----\n";
    cout << "Nome: " << p.nome << endl;
    cout << "Idade: " << p.idade << endl;
    cout << "Endereco: " << p.endereco << endl;
}

int main()
{
    int tamanho = 0;
    string resposta;
    string buscarNome;

    cout << "\nInforme a quantidade de pessoas (limite 10): ";
    cin >> tamanho;

    if (tamanho > 10)
    {
        cout << "Limite de pessoas excedido. Apenas 10 pessoas podem ser cadastradas.";
    }
    else
    {

        struct pessoa vPessoas[tamanho];

        for (int i = 0; i < tamanho; i++)
        {
            cout << "\n-----Informe as informacoes da pessoa-----\n";

            cout << "\nInforme o nome: ";
            cin.ignore(); // Limpar o buffer antes de ler uma linha
            cin.getline(vPessoas[i].nome, 30);

            cout << "Informe a idade (anos): ";
            cin >> vPessoas[i].idade;

            cout << "Informe o endereco: ";
            cin.ignore(); // Limpar o buffer antes de ler uma linha
            cin.getline(vPessoas[i].endereco, 50);
        }

        for (int i = 0; i < tamanho; i++)
        {
            exibindoInformacoes(vPessoas[i]);
        }

        cout << "\nDeseja atualizar as informacoes (y/n): ";
        cin >> resposta;

        if (resposta == "y")
        {
            cout << "\nInforme o nome da pessoa: ";
            cin >> buscarNome;

            bool encontrado = false;

            for (int i = 0; i < tamanho; i++)
            {
                if (strcmp(buscarNome, vPessoas[i].nome) == 0)
                {
                    cout << "\n-----Atualizar informacoes-----\n";

                    cout << "\nNome: ";
                    gets(vPessoas[i].nome);

                    cout << "Idadde (anos): ";
                    cin >> vPessoas[i].idade;

                    cout << "Endereco: ";
                    gets(vPessoas[i].endereco);

                    exibindoInformacoes(vPessoas[i]);
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                cout << "\nPessoa nao cadastrada. Nao e possivel atualizar as informacoes.";
            }
        }
    }

    return 0;
}