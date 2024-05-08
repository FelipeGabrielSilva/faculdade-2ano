#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Cidade
{
    int id;
    char nome[26];
    char uf[3];
};

struct Especialidade
{
    int id;
    char especializacao[30];
};

struct Medico
{
    int id;
    char nome[30];
    char endereco[30];
    char telefone[14];
};

struct Paciente
{
    int cpf;
    char nome[30];
    char enderco[30];
};

struct CID
{
    int id;
    char descricao[30];
};

struct Medicamento
{
    int id;
    char descricao[30];
    int qtdEstoque;
    int estoqueMinimo;
    int estoqueMaximo;
    int precoUnitario;
};

struct Consulta
{
    char data[10];
    char horario[5];
};

void lerCidade(struct Cidade city[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nInforme os dados para cidade" << endl;

        cout << "ID: ";
        cin >> city[i].id;

        cin.ignore();

        cout << "Nome: ";
        cin.getline(city[i].nome, 26);

        cout << "UF: ";
        cin.getline(city[i].uf, 3);
    }
}

void lerEspecialidade(struct Especialidade speciality[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nInforme os dados para especialidade" << endl;

        cout << "ID: ";
        cin >> speciality[i].id;

        cin.ignore();

        cout << "Descricao: ";
        cin.getline(speciality[i].especializacao, 30);
    }
}

void lerCID(struct CID sick[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nInforme os dados para CID (Codigo Internacional de Doencas)" << endl;

        cout << "ID: ";
        cin >> sick[i].id;

        cin.ignore();

        cout << "Descricao: ";
        cin.getline(sick[i].descricao, 30);
    }
}

void lerMedicamento(struct Medicamento medice[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nInforme os dados para medicamento" << endl;

        cout << "ID: ";
        cin >> medice[i].id;

        cin.ignore();

        cout << "Descricao: ";
        cin.getline(medice[i].descricao, 30);

        cout << "Quantidade estoque: ";
        cin >> medice[i].qtdEstoque;

        cout << "Estoque minimo: ";
        cin >> medice[i].estoqueMinimo;

        cout << "Estoque maximo: ";
        cin >> medice[i].estoqueMaximo;

        cout << "Preco unitario: R$";
        cin >> medice[i].precoUnitario;
    }
}

Medico insercaoMedico(int $size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "ID: ";
        cin >> lista[i].id;

        cout << "Nome: ";
        cin.getline(lista[i].nome);

        cout << "EnderecO: ";
        cin.getline(lista[i].endereco, 30);

        cout << "Telefone: ";
        cin.getline(lista[i].telefone, 14);
    }

    return lista;
}

int main()
{
    int tamCidade = 2, tamMedico = 2;
    struct Cidade cidades[tamCidade];
    struct Medico medicos[tamMedico];

    lerCidade(cidades, tamCidade);
    return 0;
}