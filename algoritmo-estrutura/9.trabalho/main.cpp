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
int buscarMedicamentoPorId(const Medicamento medicamentos[], int tamanho, int idProcurado)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (medicamentos[meio].id == idProcurado)
        {
            return meio;
        }

        if (medicamentos[meio].id < idProcurado)
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

int buscarMedicoPorId(const Medico medicos[], int tamanho, int idProcurado)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (medicos[meio].id == idProcurado)
        {
            return meio;
        }

        if (medicos[meio].id < idProcurado)
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

int buscarPaciente(const Paciente pacientes[], int tamanhoPacientes, int cpfProcurado)
{
    if (tamanhoPacientes == 0)
    {
        cout << "Não há pacientes cadastrados!" << endl;
        return -1; // Retorna -1 para indicar que o paciente não foi encontrado
    }
    else
    {
        for (int i = 0; i < tamanhoPacientes; i++)
        { // Itera até o tamanho real do array
            if (pacientes[i].cpf == cpfProcurado)
            {
                return i; // Retorna o índice do paciente encontrado
            }
        }
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

void lerCidade(struct Cidade cidades[], int &tamanho, int &tMaximo)
{
    int novoId;

    if (tamanho < tMaximo)
    {
        do
        {
            cout << "\nInforme os dados para a cidade:\n";

            cout << "ID: ";
            cin >> novoId;
            cin.ignore();

            if (novoId <= 0)
            {
                cout << "ID inválido. O ID deve ser um número positivo.\n";
            }
            else
            {
                // Utiliza a função de busca para verificar se o ID  ja existe
                int indice = buscarCidadePorId(cidades, tamanho, novoId);

                // Se o índice for válido, significa que o ID  ja existe
                if (indice != -1)
                {
                    cout << "\nCidade com esse ID  ja existe!\n";
                }
                else
                {
                    // Se o ID é válido e não existe, sai do loop
                    break;
                }
            }
        } while (true);

        cidades[tamanho].id = novoId;

        // Validação do Nome (nao permite nome vazio)
        do
        {
            cout << "Nome: ";
            getline(cin, cidades[tamanho].nome);

            if (cidades[tamanho].nome.empty())
            {
                cout << "Nome inválido. O nome da cidade nao pode ser vazio.\n";
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

void lerEspecialidade(struct Especialidade especialidades[], int &tamanho, int tMaximo)
{
    int novoId;

    if (tamanho < tMaximo)
    {
        do
        {
            cout << "\nInforme os dados para a especialidade:\n";

            cout << "ID: ";
            cin >> novoId;
            cin.ignore();

            if (novoId <= 0)
            {
                cout << "ID inválido. O ID deve ser um número positivo.\n";
            }
            else
            {
                // Utiliza a função de busca para verificar se o ID  ja existe
                int indice = buscarEspecialidadePorId(especialidades, tamanho, novoId);

                // Se o índice for válido, significa que o ID  ja existe
                if (indice != -1)
                {
                    cout << "\nEspecialidade com esse ID  ja existe!\n";
                    break;
                }
                else
                {
                    break;
                }
            }
        } while (true);

        especialidades[tamanho].id = novoId;

        // Validação do Especialidade (nao permite nome vazio)
        do
        {
            cout << "Especializacao: ";
            getline(cin, especialidades[tamanho].especializacao);

            if (especialidades[tamanho].especializacao.empty())
            {
                cout << "Especializacao invalido. A especializacao nao pode ser vazio.\n";
            }
            else
            {
                break; // Sai do loop se o nome for válido
            }
        } while (true);

        tamanho++;
        cout << "\nEspecialidade cadastrada com sucesso!\n";
    }
    else
    {
        cout << "\nLimite maximo de especialidades atingido.\n";
    }
}

void lerCid(struct CID cids[], int &tamanho, int &tMaximo)
{
    if (tamanho < tMaximo)
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

void lerMedicamento(struct Medicamento medicamentos[], int &tamanho, int &tMaximo)
{
    if (tamanho < tMaximo)
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

void incluirMedico(struct Medico medicos[], int &tamanhoMedicos, const Cidade cidades[], int tamanhoCidades, const Especialidade especialidades[], int tamanhoEspecialidades, int tamanho)
{
    int novoId;

    if (tamanhoMedicos < tamanho)
    {
        do
        {
            cout << "\nInforme os dados para o medico:\n";
            cout << "ID: ";
            cin >> novoId;
            cin.ignore();

            if (novoId <= 0)
            {
                cout << "ID inválido. O ID deve ser um número positivo.\n";
            }
            else
            {
                int indice = buscarMedicoPorId(medicos, tamanhoMedicos, novoId);

                if (indice != -1)
                {
                    cout << "\nMedico com esse ID ja existe!\n";
                }
                else
                {
                    break;
                }
            }
        } while (true);

        medicos[tamanhoMedicos].id = novoId;

        do
        {
            cout << "Nome: ";
            getline(cin, medicos[tamanhoMedicos].nome);
            if (medicos[tamanhoMedicos].nome.empty())
            {
                cout << "Nome invalido. O nome nao pode ser vazio.\n";
            }
            else
            {
                break; // Sai do loop se o nome for válido
            }

        } while (true);

        do
        {
            cout << "Codigo especialidade: ";
            cin >> medicos[tamanhoMedicos].cod_especialidade;

            int indice = buscarEspecialidadePorId(especialidades, tamanhoEspecialidades, medicos[tamanhoMedicos].cod_especialidade);
            if (indice != -1)
            {
                cout << "Descricao: " << especialidades[indice].especializacao << endl;
                break;
            }
            else
            {
                cout << "Especialidade invalida.";
            }

        } while (true);
        cin.ignore();

        do
        {
            cout << "Endereco: ";
            getline(cin, medicos[tamanhoMedicos].endereco);

            if (medicos[tamanhoMedicos].endereco.empty())
            {
                cout << "Endereco invalido. O endereco nao pode ser vazio.\n";
            }
            else
            {
                break;
            }

        } while (true);

        do
        {
            cout << "Telefone: ";
            getline(cin, medicos[tamanhoMedicos].telefone);
            if (medicos[tamanhoMedicos].telefone.empty())
            {
                cout << "Telefone invalido. O telefone nao pode ser vazio.\n";
            }
            else
            {
                break; // Sai do loop se o nome for válido
            }

        } while (true);

        do
        {
            cout << "Codigo cidade: ";
            cin >> medicos[tamanhoMedicos].cod_cidade;

            int indice = buscarCidadePorId(cidades, tamanhoCidades, medicos[tamanhoMedicos].cod_cidade);
            if (indice != -1)
            {
                cout << "Cidade: " << cidades[indice].nome << endl;
                break;
            }
            else
            {
                cout << "Cidade invalida.";
            }

        } while (true);

        tamanhoMedicos++;
        cout << "\nMedico cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "\nLimite maximo de medicos atingido!";
    }
}

void incluirPaciente(struct Paciente pacientes[], int &tamanhoPacientes, const Cidade cidades[], int tamanhoCidades, int tMaximo)
{
    int novoCpf;
    if (tamanhoPacientes < tMaximo)
    {
        do
        {
            cout << "\nInforme os dados para o paciente:\n";

            cout << "CPF: ";
            cin >> novoCpf;
            cin.ignore();

            int indice = buscarPaciente(pacientes, tamanhoPacientes, tMaximo, novoCpf);

            if (indice != -1)
            {
                cout << "\nPaciente com o CPF ja cadastrado!";
            }
            else
            {
                break;
            }
        } while (true);

        pacientes[tamanhoPacientes].cpf = novoCpf;

        do
        {
            cout << "Nome: ";
            getline(cin, pacientes[tamanhoPacientes].nome);

            if (pacientes[tamanhoPacientes].nome.empty())
            {
                cout << "Nome inválido. O nome do paciente nao pode ser vazio.\n";
            }
            else
            {
                break;
            }
        } while (true);

        do
        {
            cout << "Endereco: ";
            getline(cin, pacientes[tamanhoPacientes].endereco);

            if (pacientes[tamanhoPacientes].endereco.empty())
            {
                cout << "Endereco invalido. O endereco nao pode ser vazio.\n";
            }
            else
            {
                break;
            }
        } while (true);

        do
        {
            cout << "Codigo cidade: ";
            cin >> pacientes[tamanhoPacientes].cod_cidade;

            int indice = buscarCidadePorId(cidades, tamanhoCidades, pacientes[tamanhoPacientes].cod_cidade);
            if (indice != -1)
            {
                cout << "Cidade: " << cidades[indice].nome << endl;
                break;
            }
            else
            {
                cout << "Cidade invalida.";
            }

        } while (true);

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

        cout << "ID do medico: ";
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

        // Validações (paciente, medico, cidade, medicamento)
        // ... (implemente as validações aqui)

        tamanhoConsultas++;
        cout << "\nConsulta cadastrada com sucesso!\n";
    }
    else
    {
        cout << "\nLimite máximo de consultas atingido.\n";
    }
}

void imprimirCidade(const Cidade cidade)
{
    cout << "Cidade: " << cidade.nome << " (" << cidade.uf << ")" << endl;
}

void imprimirEspecialidade(const Especialidade especialidade)
{
    cout << "Especialidade: " << especialidade.especializacao << endl;
}

void imprimirCID(const CID cid)
{
    cout << "CID: " << cid.descricao << endl;
}

void imprimirMedicamento(const Medicamento medicamento)
{
    cout << "Medicamento: " << medicamento.descricao << endl;
    cout << "Quantidade em Estoque: " << medicamento.qtdEstoque << endl;
    cout << "Estoque Mínimo: " << medicamento.estoqueMinimo << endl;
    cout << "Estoque Máximo: " << medicamento.estoqueMaximo << endl;
    cout << "Preço Unitário: R$ " << medicamento.precoUnitario << endl;
}

void imprimirMedico(const Medico medico, const Cidade cidades[], int tamanhoCidades, Especialidade especialidades[], int tamanhoEspecialidades)
{
    cout << "\nNome: " << medico.nome << endl;
    cout << "Especialidade: ";

    // Busca a especialidade do medico
    int posicaoEspecialidade = buscarEspecialidadePorId(especialidades, tamanhoEspecialidades, medico.cod_especialidade);
    if (posicaoEspecialidade != -1)
    {
        imprimirEspecialidade(especialidades[posicaoEspecialidade]);
    }
    else
    {
        cout << "Especialidade nao encontrada!" << endl;
    }

    cout << "Endereco: " << medico.endereco << endl;
    cout << "Telefone: " << medico.telefone << endl;

    // Busca a cidade do medico
    int posicaoCidade = buscarCidadePorId(cidades, tamanhoCidades, medico.cod_cidade);
    if (posicaoCidade != -1)
    {
        cout << "Cidade: ";
        imprimirCidade(cidades[posicaoCidade]);
    }
    else
    {
        cout << "Cidade nao encontrada!" << endl;
    }
}

void imprimirPaciente(const Paciente paciente, const Cidade cidades[], int tamanhoCidades)
{
    cout << "\nCPF: " << paciente.cpf << endl;
    cout << "Nome: " << paciente.nome << endl;
    cout << "Endereco: " << paciente.endereco << endl;

    // Busca a cidade do paciente
    int posicaoCidade = buscarCidadePorId(cidades, tamanhoCidades, paciente.cod_cidade);
    if (posicaoCidade != -1)
    {
        cout << "Cidade: ";
        imprimirCidade(cidades[posicaoCidade]);
    }
    else
    {
        cout << "Cidade nao encontrada!" << endl;
    }
}

// Função para imprimir dados da consulta
void imprimirConsulta(const Consulta consulta, const Paciente pacientes[], int tamanhoPacientes,
                      const Medico medicos[], int tamanhoMedicos,
                      const Cidade cidades[], int tamanhoCidades,
                      const Medicamento medicamentos[], int tamanhoMedicamentos, Especialidade especialidades[], int tamanhoEspecialidades)
{
    cout << "\nData: " << consulta.data << endl;
    cout << "Horario: " << consulta.horario << endl;

    // Busca o paciente da consulta
    int posicaoPaciente = -1;
    for (int i = 0; i < tamanhoPacientes; ++i)
    {
        if (pacientes[i].cpf == consulta.cod_paciente)
        {
            posicaoPaciente = i;
            break;
        }
    }
    if (posicaoPaciente != -1)
    {
        cout << "Paciente: ";
        imprimirPaciente(pacientes[posicaoPaciente], cidades, tamanhoCidades);
    }
    else
    {
        cout << "Paciente nao encontrado!" << endl;
    }

    // Busca o médico da consulta
    int posicaoMedico = buscarMedicoPorId(medicos, tamanhoMedicos, consulta.cod_medico);
    if (posicaoMedico != -1)
    {
        cout << "Medico: ";
        imprimirMedico(medicos[posicaoMedico], cidades, tamanhoCidades,
                       especialidades, tamanhoEspecialidades);
    }
    else
    {
        cout << "Medico nao encontrado!" << endl;
    }

    // Busca a cidade da consulta
    int posicaoCidade = buscarCidadePorId(cidades, tamanhoCidades, consulta.cod_cidade);
    if (posicaoCidade != -1)
    {
        cout << "Cidade: ";
        imprimirCidade(cidades[posicaoCidade]);
    }
    else
    {
        cout << "Cidade nao encontrada!" << endl;
    }

    // Busca o medicamento da consulta
    int posicaoMedicamento = buscarMedicamentoPorId(medicamentos, tamanhoMedicamentos, consulta.cod_medicamento);
    if (posicaoMedicamento != -1)
    {
        cout << "Medicamento: " << medicamentos[posicaoMedicamento].descricao << endl;
        cout << "Quantidade: " << consulta.qtd_medicamento << endl;
    }
    else
    {
        cout << "Medicamento nao encontrado!" << endl;
    }
}

void menu()
{
    cout << "\n1. Leitura cidade";
    cout << "\n2. Leitura especialidade";
    cout << "\n3. Leitura CID";
    cout << "\n4. Leitura medicamento";
    cout << "\n5. Consultar medicamento";
    cout << "\n6. Consultar estoque";
    cout << "\n7. Cadastrar medico";
    cout << "\n8. Cadastrar paciente";
    cout << "\n9. Cadastrar consulta";
    cout << "\n10. Imprimir cidade";
    cout << "\n11. Imprimir especialidade";
    cout << "\n12. Imprimir cid";
    cout << "\n13. Imprimir medicamento";
    cout << "\n14. Imprimir medico";
    cout << "\n15. Imprimir paciente";
    cout << "\n16. Imprimir consulta";
    cout << "\n0. SAIR";
    cout << "\n\nOPERACAO: ";
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

    medicos[0] = {1, "Felipe Gabriel", 1, "Rua amado batista 202", "18996149436", 1};
    medicos[1] = {2, "Andrei Gabriel", 2, "Rua amado batista 202", "18996149436", 2};
    medicos[2] = {3, "Ricardo Gabriel", 3, "Rua amado batista 202", "18996149436", 3};
    medicos[3] = {4, "Antonio Gabriel", 4, "Rua amado batista 202", "18996149436", 4};
    medicos[4] = {5, "Lucas Gabriel", 5, "Rua amado batista 202", "18996149436", 5};

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
            lerCidade(cidades, tamanhoCidades, tamanho);

            break;

        case 2:
            lerEspecialidade(especialidades, tamanhoEspecialidades, tamanho);

            break;

        case 3:
            lerCid(cids, tamanhoCids, tamanho);

            break;

        case 4:
            lerMedicamento(medicamentos, tamanhoMedicamentos, tamanho);

            break;

        case 5:
            consultarMedicamento(medicamentos, tamanhoMedicamentos);
            break;

        case 6:
            consultarEstoque(medicamentos, tamanhoMedicamentos);
            break;

        case 7:
            incluirMedico(medicos, tamanhoMedicos, cidades, tamanhoCidades, especialidades, tamanhoEspecialidades, tamanho);

            break;

        case 8:
            incluirPaciente(pacientes, tamanhoPacientes, cidades, tamanhoCidades, tamanho);

            break;

        case 9:
            incluirConsulta(consultas, tamanhoConsultas, pacientes, tamanhoPacientes,
                            medicos, tamanhoMedicos, cidades, tamanhoCidades,
                            medicamentos, tamanhoMedicamentos);

            break;

        case 10:
            // Imprimir cidade
            if (tamanhoCidades > 0)
            {
                cout << "\nImprimindo cidades:\n";
                for (int i = 0; i < tamanhoCidades; ++i)
                {
                    imprimirCidade(cidades[i]);
                }
            }
            else
            {
                cout << "\nNenhuma cidade cadastrada.\n";
            }
            break;

        case 11:
            // Imprimir especialidade
            if (tamanhoEspecialidades > 0)
            {
                cout << "\nImprimindo especialidades:\n";
                for (int i = 0; i < tamanhoEspecialidades; ++i)
                {
                    imprimirEspecialidade(especialidades[i]);
                }
            }
            else
            {
                cout << "\nNenhuma especialidade cadastrada.\n";
            }
            break;

        case 12:
            // Imprimir cid
            if (tamanhoCids > 0)
            {
                cout << "\nImprimindo CIDs:\n";
                for (int i = 0; i < tamanhoCids; ++i)
                {
                    imprimirCID(cids[i]);
                }
            }
            else
            {
                cout << "\nNenhum CID cadastrado.\n";
            }
            break;

        case 13:
            // Imprimir medicamento
            if (tamanhoMedicamentos > 0)
            {
                cout << "\nImprimindo medicamentos:\n";
                for (int i = 0; i < tamanhoMedicamentos; ++i)
                {
                    imprimirMedicamento(medicamentos[i]);
                }
            }
            else
            {
                cout << "\nNenhum medicamento cadastrado.\n";
            }
            break;

        case 14:
            // Imprimir medico
            if (tamanhoMedicos > 0)
            {
                cout << "\nImprimindo medicos:\n";
                for (int i = 0; i < tamanhoMedicos; ++i)
                {
                    imprimirMedico(medicos[i], cidades, tamanhoCidades, especialidades, tamanhoEspecialidades);
                }
            }
            else
            {
                cout << "\nNenhum medico cadastrado.\n";
            }
            break;

            // Imprimir paciente
        case 15:
            // Imprimir paciente
            if (tamanhoPacientes > 0)
            {
                cout << "\nImprimindo pacientes:\n";
                for (int i = 0; i < tamanhoPacientes; ++i)
                {
                    imprimirPaciente(pacientes[i], cidades, tamanhoCidades);
                }
            }
            else
            {
                cout << "\nNenhum paciente cadastrado.\n";
            }
            break;

        // Imprimir consulta
        case 16:
            // Imprimir consulta
            if (tamanhoConsultas > 0)
            {
                cout << "\nImprimindo consultas:\n";
                for (int i = 0; i < tamanhoConsultas; ++i)
                {
                    imprimirConsulta(consultas[i], pacientes, tamanhoPacientes,
                                     medicos, tamanhoMedicos, cidades, tamanhoCidades,
                                     medicamentos, tamanhoMedicamentos, especialidades, tamanhoEspecialidades);
                }
            }
            else
            {
                cout << "\nNenhuma consulta cadastrada.\n";
            }
            break;

        default:
            cout << "\nOpcao invalida!\n";
            break;
        }
    }

    return 0;
}