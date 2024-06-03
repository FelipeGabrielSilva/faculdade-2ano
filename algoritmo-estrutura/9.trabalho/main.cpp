#include <iostream>
#include <stdlib.h>
#include <string.h>

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
    int cod_especialidade;
    string endereco;
    string telefone;
    int cod_cidade;
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

struct Paciente
{
    int cpf;
    string nome;
    string endereco;
    int cod_cidade;
};

struct Consulta
{
    int cod_paciente;
    int cod_medico;
    string data;
    string horario;
    int cod_cidade;
    int cod_medicamento;
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

int buscarCidadePorId(const Cidade cidades[], int tamanho, int idProcurado)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (cidades[meio].id == idProcurado)
        {
            return meio;
        }

        if (cidades[meio].id < idProcurado)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1;
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

int buscarEspecialidadePorId(const Especialidade especialidades[], int tamanho, int idProcurado)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (especialidades[meio].id == idProcurado)
        {
            return meio;
        }

        if (especialidades[meio].id < idProcurado)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1;
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

int buscarCIDPorId(const CID cids[], int tamanho, int idProcurado)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (cids[meio].id == idProcurado)
        {
            return meio;
        }

        if (cids[meio].id < idProcurado)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1;
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

bool consultarMedicamento(struct Medicamento v[], int tamanho)
{
    int consulta;
    cout << "\nInforme o ID para consultar: ";
    cin >> consulta;

    for (int i = 0; i < tamanho; i++)
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

            return true;
        }
    }

    cout << "\nMEDICAMENTO NAO ENCONTRADO";
    return false;
}

void consultarEstoque(struct Medicamento v[], int tamanho)
{
    bool encontrouProdutoAbaixoDoMinimo = false;

    cout << "\nPRODUTOS COM ESTOQUE ABAIXO DO MINIMO: ";
    for (int i = 0; i < tamanho; i++)
    {
        if (v[i].qtdEstoque < v[i].estoqueMinimo)
        {
            encontrouProdutoAbaixoDoMinimo = true;
            int diferenca = v[i].estoqueMaximo - v[i].qtdEstoque;

            cout << "\nID: " << v[i].id;
            cout << "\nDESCRICAO: " << v[i].descricao;
            cout << "\nESTOQUE: " << v[i].qtdEstoque;
            cout << "\nESTOQUE MAXIMO: " << v[i].estoqueMaximo;
            cout << "\nQUANTIDADE A SER COMPRADA: " << diferenca;
            cout << "\nVALOR DA COMPRA: R$" << v[i].precoUnitario * diferenca << endl;
        }
    }

    if (!encontrouProdutoAbaixoDoMinimo)
    {
        cout << "\nNENHUM PRODUTO COM ESTOQUE ABAIXO DO MINIMO";
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
    cout << "\n7. Cadastrar médico";
    cout << "\n8. Cadastrar paciente";
    cout << "\n9. Cadastrar consulta";
    cout << "\n0. SAIR";
    cout << "\n\nOPERACAO: ";
}

void incluirCidade(struct Cidade cidades[], int &tamanho)
{
    if (tamanho < 10)
    {
        cout << "\nInforme os dados para a cidade:\n";

        // Validação do ID (assumindo que IDs devem ser positivos e únicos)
        int novoId;
        do
        {
            cout << "ID: ";
            cin >> novoId;
            cin.ignore();

            if (novoId <= 0)
            {
                cout << "ID inválido. O ID deve ser um número positivo.\n";
            }
            else
            {
                // Verifica se o ID já existe
                bool idExistente = false;
                for (int i = 0; i < tamanho; ++i)
                {
                    if (cidades[i].id == novoId)
                    {
                        cout << "ID já cadastrado. Informe um ID único.\n";
                        idExistente = true;
                        break;
                    }
                }
                if (!idExistente)
                {
                    break; // Sai do loop se o ID for válido e único
                }
            }
        } while (true);

        cidades[tamanho].id = novoId;

        // Validação do Nome (não permite nome vazio)
        do
        {
            cout << "Nome: ";
            getline(cin, cidades[tamanho].nome);

            if (cidades[tamanho].nome.empty())
            {
                cout << "Nome inválido. O nome da cidade não pode ser vazio.\n";
            }
            else
            {
                break; // Sai do loop se o nome for válido
            }
        } while (true);

        // Validação da UF (assumindo UF com 2 caracteres)
        do
        {
            cout << "UF: ";
            cin >> cidades[tamanho].uf;
            cin.ignore(); // Limpa o buffer do cin

            if (cidades[tamanho].uf.length() != 2)
            {
                cout << "UF inválida. A UF deve ter 2 caracteres.\n";
            }
            else
            {
                break; // Sai do loop se a UF for válida
            }
        } while (true);

        tamanho++;
        cout << "\nCidade cadastrada com sucesso!\n";
    }
    else
    {
        cout << "\nLimite máximo de cidades atingido.\n";
    }
}

void incluirEspecialidade(struct Especialidade especialidades[], int &tamanho)
{
    if (tamanho < 10)
    {
        cout << "\nInforme os dados para a especialidade:\n";

        cout << "ID: ";
        cin >> especialidades[tamanho].id;
        cin.ignore();

        cout << "Especializacao: ";
        getline(cin, especialidades[tamanho].especializacao);

        tamanho++;
        cout << "\nEspecialidade cadastrada com sucesso!\n";
    }
    else
    {
        cout << "\nLimite máximo de especialidades atingido.\n";
    }
}

void incluirCID(struct CID cids[], int &tamanho)
{
    if (tamanho < 10)
    {
        cout << "\nInforme os dados para o CID:\n";

        cout << "ID: ";
        cin >> cids[tamanho].id;
        cin.ignore();

        cout << "Descricao: ";
        getline(cin, cids[tamanho].descricao);

        tamanho++;
        cout << "\nCID cadastrado com sucesso!\n";
    }
    else
    {
        cout << "\nLimite máximo de CIDs atingido.\n";
    }
}

void incluirMedicamento(struct Medicamento medicamentos[], int &tamanho)
{
    if (tamanho < 10)
    {
        cout << "\nInforme os dados para o medicamento:\n";

        cout << "ID: ";
        cin >> medicamentos[tamanho].id;
        cin.ignore();

        cout << "Descricao: ";
        getline(cin, medicamentos[tamanho].descricao);

        cout << "Quantidade em estoque: ";
        cin >> medicamentos[tamanho].qtdEstoque;

        cout << "Estoque minimo: ";
        cin >> medicamentos[tamanho].estoqueMinimo;

        cout << "Estoque maximo: ";
        cin >> medicamentos[tamanho].estoqueMaximo;

        cout << "Preco unitario: R$";
        cin >> medicamentos[tamanho].precoUnitario;

        tamanho++;
        cout << "\nMedicamento cadastrado com sucesso!\n";
    }
    else
    {
        cout << "\nLimite máximo de medicamentos atingido.\n";
    }
}

void incluirMedico(struct Medico medicos[], int &tamanhoMedicos, const Cidade cidades[], int tamanhoCidades, const Especialidade especialidades[], int tamanhoEspecialidades)
{
    if (tamanhoMedicos < 10)
    {
        cout << "\nInforme os dados para o médico:\n";

        cout << "ID: ";
        cin >> medicos[tamanhoMedicos].id;
        cin.ignore();

        cout << "Nome: ";
        getline(cin, medicos[tamanhoMedicos].nome);

        cout << "Código da Especialidade: ";
        cin >> medicos[tamanhoMedicos].cod_especialidade;
        cin.ignore();

        // Validação da especialidade
        bool especialidadeValida = false;
        for (int i = 0; i < tamanhoEspecialidades; ++i)
        {
            if (especialidades[i].id == medicos[tamanhoMedicos].cod_especialidade)
            {
                especialidadeValida = true;
                break;
            }
        }
        if (!especialidadeValida)
        {
            cout << "Especialidade inválida.\n";
            return;
        }

        cout << "Endereco: ";
        getline(cin, medicos[tamanhoMedicos].endereco);

        cout << "Telefone: ";
        getline(cin, medicos[tamanhoMedicos].telefone);

        cout << "Código da Cidade: ";
        cin >> medicos[tamanhoMedicos].cod_cidade;
        cin.ignore();

        // Validação da cidade
        bool cidadeValida = false;
        for (int i = 0; i < tamanhoCidades; ++i)
        {
            if (cidades[i].id == medicos[tamanhoMedicos].cod_cidade)
            {
                cidadeValida = true;
                break;
            }
        }
        if (!cidadeValida)
        {
            cout << "Cidade inválida.\n";
            return;
        }

        tamanhoMedicos++;
        cout << "\nMédico cadastrado com sucesso!\n";
    }
    else
    {
        cout << "\nLimite máximo de médicos atingido.\n";
    }
}

void incluirPaciente(struct Paciente pacientes[], int &tamanhoPacientes, const Cidade cidades[], int tamanhoCidades)
{
    if (tamanhoPacientes < 10)
    {
        cout << "\nInforme os dados para o paciente:\n";

        cout << "CPF: ";
        cin >> pacientes[tamanhoPacientes].cpf;
        cin.ignore();

        cout << "Nome: ";
        getline(cin, pacientes[tamanhoPacientes].nome);

        cout << "Endereco: ";
        getline(cin, pacientes[tamanhoPacientes].endereco);

        cout << "Código da Cidade: ";
        cin >> pacientes[tamanhoPacientes].cod_cidade;
        cin.ignore();

        // Validação da cidade
        bool cidadeValida = false;
        for (int i = 0; i < tamanhoCidades; ++i)
        {
            if (cidades[i].id == pacientes[tamanhoPacientes].cod_cidade)
            {
                cidadeValida = true;
                break;
            }
        }
        if (!cidadeValida)
        {
            cout << "Cidade inválida.\n";
            return;
        }

        tamanhoPacientes++;
        cout << "\nPaciente cadastrado com sucesso!\n";
    }
    else
    {
        cout << "\nLimite máximo de pacientes atingido.\n";
    }
}

void incluirConsulta(struct Consulta consultas[], int &tamanhoConsultas,
                     const Paciente pacientes[], int tamanhoPacientes,
                     const Medico medicos[], int tamanhoMedicos,
                     const Cidade cidades[], int tamanhoCidades,
                     const Medicamento medicamentos[], int tamanhoMedicamentos)
{
    if (tamanhoConsultas < 10)
    {
        cout << "\nInforme os dados para a consulta:\n";

        cout << "CPF do paciente: ";
        cin >> consultas[tamanhoConsultas].cod_paciente;
        cin.ignore();

        cout << "ID do médico: ";
        cin >> consultas[tamanhoConsultas].cod_medico;
        cin.ignore();

        cout << "Data (AAAA-MM-DD): ";
        getline(cin, consultas[tamanhoConsultas].data);

        cout << "Horario (HH:MM): ";
        getline(cin, consultas[tamanhoConsultas].horario);

        cout << "Código da Cidade: ";
        cin >> consultas[tamanhoConsultas].cod_cidade;
        cin.ignore();

        cout << "ID do Medicamento: ";
        cin >> consultas[tamanhoConsultas].cod_medicamento;
        cin.ignore();

        cout << "Quantidade do Medicamento: ";
        cin >> consultas[tamanhoConsultas].qtd_medicamento;
        cin.ignore();

        // Validações (paciente, médico, cidade, medicamento)
        // ... (implemente as validações aqui)

        tamanhoConsultas++;
        cout << "\nConsulta cadastrada com sucesso!\n";
    }
    else
    {
        cout << "\nLimite máximo de consultas atingido.\n";
    }
}

int main()
{
    int tamanho = 10;
    Cidade cidades[tamanho];
    int tamanhoCidades = 5;

    cidades[0] = {1, "Assis", "SP"};
    cidades[1] = {2, "Candido Mota", "SP"};
    cidades[2] = {3, "Taruma", "SP"};
    cidades[3] = {4, "Marilia", "SP"};
    cidades[4] = {5, "Botucatu", "SP"};

    Especialidade especialidades[tamanho];
    int tamanhoEspecialidades = 5;

    especialidades[0] = {1, "Clinico geral"};
    especialidades[1] = {2, "Pediatria"};
    especialidades[2] = {3, "Ginecologia"};
    especialidades[3] = {4, "Cardiologia"};
    especialidades[4] = {5, "Ortopedia"};

    CID cids[tamanho];
    int tamanhoCids = 5;

    cids[0] = {1, "Diabetes"};
    cids[1] = {2, "Hipertensao arterial"};
    cids[2] = {3, "Doenca cardiaca"};
    cids[3] = {4, "Cancer"};
    cids[4] = {5, "Doenca pulmonar"};

    Medicamento medicamentos[tamanho];
    int tamanhoMedicamentos = 5;
    medicamentos[0] = {1, "Paracetamol", 178, 250, 1000, 0.99};
    medicamentos[1] = {2, "Ibuprofeno", 256, 250, 1000, 1.25};
    medicamentos[2] = {3, "Omeprazol", 982, 250, 1000, 0.66};
    medicamentos[3] = {4, "Amoxicilina", 745, 250, 1000, 0.78};
    medicamentos[4] = {5, "Aspirina", 357, 250, 1000, 0.25};

    Medico medicos[tamanho];
    int tamanhoMedicos = 5;

    medicos[0] = {1, "Felipe Gabriel", 1, "Rua amado batista 202", "(18)99614-9436", 1};
    medicos[1] = {2, "Andrei Gabriel", 2, "Rua amado batista 202", "(18)99614-9436", 2};
    medicos[2] = {3, "Ricardo Gabriel", 3, "Rua amado batista 202", "(18)99614-9436", 3};
    medicos[3] = {4, "Antonio Gabriel", 4, "Rua amado batista 202", "(18)99614-9436", 4};
    medicos[4] = {5, "Lucas Gabriel", 5, "Rua amado batista 202", "(18)99614-9436", 5};

    Paciente pacientes[tamanho];
    int tamanhoPacientes = 0;

    Consulta consultas[tamanho];
    int tamanhoConsultas = 0;

    int codigo;

    while (codigo != 0)
    {
        menu();
        cin >> codigo;

        switch (codigo)
        {
        case 1:
            incluirCidade(cidades, tamanhoCidades);
            system("cls");
            break;

        case 2:
            incluirEspecialidade(especialidades, tamanhoEspecialidades);
            system("cls");
            break;

        case 3:
            incluirCID(cids, tamanhoCids);
            system("cls");
            break;

        case 4:
            incluirMedicamento(medicamentos, tamanhoMedicamentos);
            system("cls");
            break;

        case 5:
            consultarMedicamento(medicamentos, tamanhoMedicamentos);
            break;

        case 6:
            consultarEstoque(medicamentos, tamanhoMedicamentos);
            break;

        case 7:
            incluirMedico(medicos, tamanhoMedicos, cidades, tamanhoCidades, especialidades, tamanhoEspecialidades);
            system("cls");
            break;

        case 8:
            incluirPaciente(pacientes, tamanhoPacientes, cidades, tamanhoCidades);
            system("cls");
            break;

        case 9:
            incluirConsulta(consultas, tamanhoConsultas, pacientes, tamanhoPacientes,
                            medicos, tamanhoMedicos, cidades, tamanhoCidades,
                            medicamentos, tamanhoMedicamentos);
            system("cls");
            break;
        }
    }

    return 0;
}
