#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

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
    Especialidade esp_cod;
    char endereco[30];
    char telefone[14];
    Cidade cidade_cod;
};

struct Paciente
{
    int cpf;
    char nome[30];
    char enderco[30];
    cidade cidade_cod;
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
    float precoUnitario;
};

struct Consulta
{
    Paciente paciene_cod;
    Medico medico_cod;
    char data[10];
    char horario[5];
    CID cid_cod;
    Medicamento medicamento_cod;
    Medicamento qtd_medicamento;
};

void lerCidade(struct Cidade city[])
{
    for (int i = 0; i < 2; i++)
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

void lerEspecialidade(struct Especialidade speciality[])
{
    for (int i = 0; i < 2; i++)
    {
        cout << "\nInforme os dados para especialidade" << endl;

        cout << "ID: ";
        cin >> speciality[i].id;

        cin.ignore();

        cout << "Descricao: ";
        cin.getline(speciality[i].especializacao, 30);
    }
}

void lerCID(struct CID sick[])
{
    for (int i = 0; i < 2; i++)
    {
        cout << "\nInforme os dados para CID (Codigo Internacional de Doencas)" << endl;

        cout << "ID: ";
        cin >> sick[i].id;

        cin.ignore();

        cout << "Descricao: ";
        cin.getline(sick[i].descricao, 30);
    }
}

void lerMedicamento(struct Medicamento medice[])
{
    for (int i = 0; i < 2; i++)
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

void consultarMedicamento(struct Medicamento v[])
{
    int consulta;
    cout << "\nInforme o ID para consultar: ";
    cin >> consulta;

    for (int i = 0; i < 2; i++)
    {
        if (v[i].id == consulta)
        {
            cout << "\nID: " << v[i].id;
            cout << "\nDESCRICAO: " << v[i].descricao;
            cout << "\nESTOQUE: " << v[i].qtdEstoque;
            cout << "\nESTOQUE MINIMO: " << v[i].estoqueMinimo;
            cout << "\nESTOQUE MAXIMO: " << v[i].estoqueMaximo;
            cout << "\nPRECO UNITARIO: " << v[i].precoUnitario;
            cout << "\nPRECO TOTAL: R$" << v[i].qtdEstoque * v[i].precoUnitario << endl;
        }
    }
}

void consultarEstoque(struct Medicamento v[])
{
    cout << "\nPRODUTOS COM ESTOQUE ABAIXO DO MINIMO: ";
    for (int i = 0; i < 2; i++)
    {
        if (v[i].qtdEstoque < v[i].estoqueMinimo)
        {
            int diferenca = v[i].estoqueMaximo - v[i].qtdEstoque;

            cout << "\nID: " << v[i].id;
            cout << "\nDESCRICAO: " << v[i].descricao;
            cout << "\nESTOQUE: " << v[i].qtdEstoque;
            cout << "\nESTOQUE MAXIMO: " << v[i].estoqueMaximo;
            cout << "\nQUANTIDADE A SER COMPRADA: " << diferenca;
            cout << "\nVALOR DA COMPRA: R$" << v[i].precoUnitario * diferenca << endl;
        }
    }
}

void agendamento(){
    cout << "\nAGENDAR UMA CONSULTA: ";
    cout << "\n"
}

void menu()
{
    cout << "\n1. Cadastrar cidade";
    cout << "\n2. Cadastrar especialidade";
    cout << "\n3. Cadastrar CID";
    cout << "\n4. Cadastrar medicamento";
    cout << "\n5. Consultar medicamento";
    cout << "\n6. Consultar estoque";
    cout << "\n0. SAIR";
    cout << "\n\nOPERACAO: ";
}

int main()
{
    struct Cidade cidades[2];
    struct Especialidade especialidades[2];
    struct CID cids[2];
    struct Medicamento medicamentos[2];

    int codigo;

    while (codigo != 0)
    {
        menu();
        cin >> codigo;

        switch (codigo)
        {
        case 1:
            lerCidade(cidades);
            system("cls");
            break;

        case 2:
            lerEspecialidade(especialidades);
            system("cls");
            break;

        case 3:
            lerCID(cids);
            system("cls");
            break;

        case 4:
            lerMedicamento(medicamentos);
            system("cls");
            break;

        case 5:
            consultarMedicamento(medicamentos);

        case 6:
            consultarEstoque(medicamentos);
        }
    }

    return 0;
}