#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Cidade
{
    int id;
    string nome;
    string uf;
};

struct Especialidade
{
    int id;
    string especializacao;
};

struct Medico
{
    int id;
    string nome;
    int cod_esp;
    string endereco;
    string telefone;
    int cod_cidade;
};

struct Paciente
{
    int cpf;
    string nome;
    string enderco;
    int cidade_cod;
};

struct CID
{
    int id;
    string descricao;
};

struct Medicamento
{
    int id;
    string descricao;
    int qtdEstoque;
    int estoqueMinimo;
    int estoqueMaximo;
    float precoUnitario;
};

struct Consulta
{
    int paciente_cod;
    int cod_medico;
    string data;
    string horario;
    int cid_cod;
    int medicamento_cod;
    int qtd_medicamento;
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
        cin >> city[i].nome;

        cout << "UF: ";
        cin >> city[i].uf;
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
        cin >> speciality[i].especializacao;
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
        cin >> sick[i].descricao;
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
        cin >> medice[i].descricao;

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
    int tamanho = 10;

    Cidade cidades[tamanho];

    cidades[0] = {1, "Assis", "SP"};
    cidades[1] = {2, "Candido Mota", "SP"};
    cidades[2] = {3, "Taruma", "SP"};
    cidades[3] = {4, "Marilia", "SP"};
    cidades[4] = {5, "Botucatu", "SP"};

    Especialidade especialidades[tamanho];

    especialidades[0] = {1, "Clinico geral"};
    especialidades[1] = {2, "Pediatria"};
    especialidades[2] = {3, "Ginecologia"};
    especialidades[3] = {4, "Cardiologia"};
    especialidades[4] = {5, "Ortopedia"};

    CID cids[tamanho];

    cids[0] = {1, "Diabetes"};
    cids[1] = {2, "Hipertensao arterial"};
    cids[2] = {3, "Doenca cardiaca"};
    cids[3] = {4, "Cancer"};
    cids[4] = {5, "Doenca pulmonar"};

    Medicamento medicamentos[tamanho];

    medicamentos[0] = {1, "Paracetamol", 178, 250, 1000, 0.99};
    medicamentos[1] = {2, "Ibuprofeno", 256, 250, 1000, 1.25};
    medicamentos[2] = {3, "Omeprazol", 982, 250, 1000, 0.66};
    medicamentos[3] = {4, "Amoxicilina", 745, 250, 1000, 0.78};
    medicamentos[4] = {5, "Aspirina", 357, 250, 1000, 0.25};

    Medico medicos[tamanho];

    medicos[0] = {1, "Felipe Gabriel", 1, "Rua amado batista 202", "(18)99614-9436", 1};
    medicos[1] = {2, "Andrei Gabriel", 2, "Rua amado batista 202", "(18)99614-9436", 2};
    medicos[2] = {3, "Ricardo Gabriel", 3, "Rua amado batista 202", "(18)99614-9436", 3};
    medicos[3] = {4, "Antonio Gabriel", 4, "Rua amado batista 202", "(18)99614-9436", 4};
    medicos[4] = {5, "Lucas Gabriel", 5, "Rua amado batista 202", "(18)99614-9436", 5};

    for (int i = 0; i < 5; i++)
    {
        cout << endl
             << medicos[i].id;
        cout << medicos[i].nome;
        cout << medicos[i].Especialidade;
        cout << medicos[i].endereco;
        cout << medicos[i].telefone;
        cout << medicos[i].Cidade;
    }

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
            break;

        case 6:
            consultarEstoque(medicamentos);
            break;
        }
    }

    return 0;
}