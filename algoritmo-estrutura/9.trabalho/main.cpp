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

// BUSCA BINÁRIA DE CIDADE
int buscarCidadePorId(Cidade cidades[], int tamanho, int idProcurado)
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

// BUSCA BINÁRIA DE ESPECIALIDADE
int buscarEspecialidadePorId(Especialidade especialidades[], int tamanho, int idProcurado)
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

// BUSCA BINÁRIA DE CID
int buscarCIDPorId(CID cids[], int tamanho, int idProcurado)
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

// BUSCA BINÁRIA DE MEDICAMENTO
int buscarMedicamentoPorId(Medicamento medicamentos[], int tamanho, int idProcurado)
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

// BUSCA BINÁRIA DE MÉDICO
int buscarMedicoPorId(Medico medicos[], int tamanho, int idProcurado)
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

// FUNÇÃO PARA CONSULTAR MEDICAMENTO
void consultarMedicamento(struct Medicamento v[], int tamanho)
{
    bool encontrado = false;
    int consulta;
    cout << "\nInforme o ID para consultar: ";
    cin >> consulta;

    // BUSCA LINEAR PARA ENCONTRAR O MEDICAMENTO
    for (int i = 0; i < tamanho; i++)
    {
        if (v[i].id == consulta)
        {
            encontrado = true;

            cout << "\nID: " << v[i].id;
            cout << "\nDescricao: " << v[i].descricao;
            cout << "\nEstoque: " << v[i].qtdEstoque;
            cout << "\nEstoque minimo: " << v[i].estoqueMinimo;
            cout << "\nEstoque maximo: " << v[i].estoqueMaximo;
            cout << "\nPreco unitario: " << v[i].precoUnitario;
            cout << "\nPreco total: R$" << v[i].qtdEstoque * v[i].precoUnitario << endl;
        }
    }

    if (!encontrado)
    {
        cout << "\nMedicamento nao encontrado!\n";
    }
}

// FUNÇÃO PARA CONSULTAR ESTOQUE DE MEDICAMENTOS
void consultarEstoque(struct Medicamento v[], int tamanho)
{
    bool abaixoMinimo = false;
    cout << "\nProdutos com estoque abaixo do minimo: ";

    // BUSCA LINEAR PARA CONSULTAR MEDICAMENTOS ABAIXO DO ESTOQUE MINIMO
    for (int i = 0; i < tamanho; i++)
    {
        if (v[i].qtdEstoque < v[i].estoqueMinimo)
        {
            abaixoMinimo = true;
            int diferenca = v[i].estoqueMaximo - v[i].qtdEstoque;

            cout << "\nID: " << v[i].id;
            cout << "\nDescricao: " << v[i].descricao;
            cout << "\nEstoque: " << v[i].qtdEstoque;
            cout << "\nEstoque maximo: " << v[i].estoqueMaximo;
            cout << "\nQuantidade a ser comprada: " << diferenca;
            cout << "\nValor da compra: R$" << v[i].precoUnitario * diferenca << endl;
        }
    }

    if (!abaixoMinimo)
    {
        cout << "\nNenhum medicamento com estoque abaixo do minimo\n";
    }
}

// FUNÇÃO PARA LEITURA DE NOVAS CIDADES
void lerCidade(struct Cidade cidades[], int &tamanhoCidades, int &tMaximo)
{
    int novoId;

    if (tamanhoCidades < tMaximo)
    {
        do
        {
            cout << "\nInforme os dados para a cidade:\n";

            cout << "ID: ";
            cin >> novoId;
            cin.ignore();

            // VERIFICANDO SE O NOVO ID É VÁLIDO
            if (novoId <= 0)
            {
                cout << "ID invalido. O ID deve ser um numero positivo.\n";
            }
            else
            {

                int indice = buscarCidadePorId(cidades, tamanhoCidades, novoId);

                if (indice != -1)
                {
                    cout << "\nCidade com esse ID  ja existe!\n";
                }
                else
                {
                    break;
                }
            }
        } while (true);

        cidades[tamanhoCidades].id = novoId;

        do
        {
            cout << "Nome: ";
            getline(cin, cidades[tamanhoCidades].nome);

            if (cidades[tamanhoCidades].nome.empty())
            {
                cout << "Nome invalido. O nome da cidade nao pode ser vazio.\n";
            }
            else
            {
                break;
            }
        } while (true);

        do
        {
            cout << "UF: ";
            cin >> cidades[tamanhoCidades].uf;
            cin.ignore();

            if (cidades[tamanhoCidades].uf.length() != 2)
            {
                cout << "UF invalida. A UF deve ter 2 caracteres.\n";
            }
            else
            {
                break;
            }
        } while (true);

        tamanhoCidades++;
        cout << "\nCidade cadastrada com sucesso!\n";
    }
    else
    {
        cout << "\nLimite maximo de cidades atingido.\n";
    }
}

// FUNÇÃO PARA LEITURA (INLCUSÃO) DE NOVAS ESPECIALIDADES
void lerEspecialidade(struct Especialidade especialidades[], int &tamanhoEspecialidades, int tMaximo)
{
    int novoId;

    if (tamanhoEspecialidades < tMaximo)
    {
        do
        {
            cout << "\nInforme os dados para a especialidade:\n";

            cout << "ID: ";
            cin >> novoId;
            cin.ignore();

            // VERIFICANDO SE O NOVO ID É VÁLIDO
            if (novoId <= 0)
            {
                cout << "ID invalido. O ID deve ser um numero positivo.\n";
            }
            else
            {

                int indice = buscarEspecialidadePorId(especialidades, tamanhoEspecialidades, novoId);

                if (indice != -1)
                {
                    cout << "\nEspecialidade com esse ID  ja existe!\n";
                }
                else
                {
                    break;
                }
            }
        } while (true);

        especialidades[tamanhoEspecialidades].id = novoId;

        do
        {
            cout << "Especializacao: ";
            getline(cin, especialidades[tamanhoEspecialidades].especializacao);

            if (especialidades[tamanhoEspecialidades].especializacao.empty())
            {
                cout << "Especializacao invalido. A especializacao nao pode ser vazio.\n";
            }
            else
            {
                break;
            }
        } while (true);

        tamanhoEspecialidades++;
        cout << "\nEspecialidade cadastrada com sucesso!\n";
    }
    else
    {
        cout << "\nLimite maximo de especialidades atingido.\n";
    }
}

// FUNÇÃO PARA LEITURA (INLCUSÃO) DE NOVAS CIDS
void lerCid(struct CID cids[], int &tamanhoCids, int &tMaximo)
{
    int novoId;

    if (tamanhoCids < tMaximo)
    {
        do
        {
            cout << "\nInforme os dados para a CID:\n";

            cout << "ID: ";
            cin >> novoId;
            cin.ignore();

            // VERIFICANDO SE O NOVO ID É VÁLIDO
            if (novoId <= 0)
            {
                cout << "ID invalido. O ID deve ser um numero positivo.\n";
            }
            else
            {
                int indice = buscarCIDPorId(cids, tamanhoCids, novoId);

                if (indice != -1)
                {
                    cout << "\nCID com esse ID  ja existe!\n";
                }
                else
                {
                    break;
                }
            }
        } while (true);

        cids[tamanhoCids].id = novoId;

        do
        {
            cout << "descricao: ";
            getline(cin, cids[tamanhoCids].descricao);

            if (cids[tamanhoCids].descricao.empty())
            {
                cout << "Descricao invalido. A descricao nao pode ser vazia.\n";
            }
            else
            {
                break;
            }
        } while (true);

        tamanhoCids++;
        cout << "\nCID cadastrado com sucesso!\n";
    }
    else
    {
        cout << "\nLimite maximo de CIDs atingido.\n";
    };
}

// FUNÇÃO PARA LEITURA (INLCUSÃO) DE NOVAS MEDICAMENTOS
void lerMedicamento(struct Medicamento medicamentos[], int &tamanhoMedicamentos, int &tMaximo)
{
    int novoId;

    if (tamanhoMedicamentos < tMaximo)
    {
        do
        {
            cout << "\nInforme os dados para o medicamento:\n";
            cout << "ID: ";
            cin >> novoId;
            cin.ignore();

            // VERIFICANDO SE O NOVO ID É VÁLIDO
            if (novoId <= 0)
            {
                cout << "ID invalido. O ID deve ser um numero positivo.\n";
            }
            else
            {
                int indice = buscarMedicamentoPorId(medicamentos, tamanhoMedicamentos, novoId);

                if (indice != -1)
                {
                    cout << "\nMedicamento com esse ID  ja existe!\n";
                }
                else
                {
                    break;
                }
            }
        } while (true);

        medicamentos[tamanhoMedicamentos].id = novoId;

        cout << "Descricao: ";
        getline(cin, medicamentos[tamanhoMedicamentos].descricao);

        cout << "Quantidade em estoque: ";
        cin >> medicamentos[tamanhoMedicamentos].qtdEstoque;

        cout << "Estoque minimo: ";
        cin >> medicamentos[tamanhoMedicamentos].estoqueMinimo;

        cout << "Estoque maximo: ";
        cin >> medicamentos[tamanhoMedicamentos].estoqueMaximo;

        cout << "Preco unitario: R$";
        cin >> medicamentos[tamanhoMedicamentos].precoUnitario;

        tamanhoMedicamentos++;
        cout << "\nMedicamento cadastrado com sucesso!\n";
    }
    else
    {
        cout << "\nLimite maximo de medicamentos atingido.\n";
    }
}

// FUNÇÃO PARA LEITURA (INLCUSÃO) DE NOVOS MÉDICOS
void incluirMedico(struct Medico medicos[], int &tamanhoMedicos,
                   Cidade cidades[], int tamanhoCidades,
                   Especialidade especialidades[], int tamanhoEspecialidades,
                   int tamanho)
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

            // VERIFICANDO SE O NOVO ID É VÁLIDO
            if (novoId <= 0)
            {
                cout << "ID invalido. O ID deve ser um numero positivo.\n";
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
                break;
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
                cout << "Especialidade invalida.\n";
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

        cin.ignore();

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
                break;
            }

        } while (true);

        cin.ignore();

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
                cout << "Cidade invalida.\n";
            }

        } while (true);

        tamanhoMedicos++;
        cout << "\nMedico cadastrado com sucesso!\n"
             << endl;
    }
    else
    {
        cout << "\nLimite maximo de medicos atingido!\n";
    }
}

// FUNÇÃO PARA LEITURA (INLCUSÃO) DE NOVOS PACIENTES
void incluirPaciente(struct Paciente pacientes[], int &tamanhoPacientes,
                     Cidade cidades[], int tamanhoCidades,
                     int tMaximo)
{
    int novoCpf;
    if (tamanhoPacientes < tMaximo)
    {
        do
        {
            cout << "\nInforme os dados para o paciente:\n";

            cout << "CPF: ";
            cin >> novoCpf;

            // VERIFICANDO SE O CPF JÁ ESTÁ CADASTRADO
            bool cpfEncontrado = false;

            for (int i = 0; i < tamanhoPacientes; i++)
            {
                if (pacientes[i].cpf == novoCpf)
                {
                    cpfEncontrado = true;
                    break;
                }
            }

            if (cpfEncontrado)
            {
                cout << "\nPaciente com o CPF ja cadastrado!";
            }
            else
            {
                break;
            }
        } while (true);

        pacientes[tamanhoPacientes].cpf = novoCpf;
        cin.ignore();

        do
        {
            cout << "Nome: ";
            getline(cin, pacientes[tamanhoPacientes].nome);

            if (pacientes[tamanhoPacientes].nome.empty())
            {
                cout << "Nome invalido. O nome do paciente nao pode ser vazio.\n";
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

        tamanhoPacientes++;
        cout << "\nPaciente cadastrado com sucesso!\n";
    }
    else
    {
        cout << "\nLimite maximo de pacientes atingido.\n";
    }
}

// FUNÇÃO DE EXCLUSÃO LÓGICA DE PACIENTES
void excluirPaciente(Paciente pacientes[], int &tamanhoPacientes)
{
    if (tamanhoPacientes == 0)
    {
        cout << "\nnao ha pacientes cadastrados!\n";
        return;
    }

    int cpfProcurado;
    cout << "\nInforme o CPF do paciente a ser excluido: ";
    cin >> cpfProcurado;

    // VERIFICANDO SE O CPF JÁ ESTÁ CADASTRADO
    bool cpfEncontrado = false;
    int i = 0;

    for (; i < tamanhoPacientes; i++)
    {
        if (pacientes[i].cpf == cpfProcurado)
        {
            cpfEncontrado = true;
            break;
        }
    }

    if (cpfEncontrado)
    {
        for (; i < tamanhoPacientes; i++)
        {
            pacientes[i] = pacientes[i + 1];
        }

        cout << "\nPaciente excluido com sucesso!\n";
    }
    else
    {
        cout << "\nPaciente nao encontrado!\n";
    }

    tamanhoPacientes--;
}

void imprimirCidade(Cidade cidade)
{
    cout << "Cidade: " << cidade.nome << " (" << cidade.uf << ")" << endl;
}

void imprimirEspecialidade(Especialidade especialidade)
{
    cout << "Especialidade: " << especialidade.especializacao << endl;
}

void imprimirCID(CID cid)
{
    cout << "CID: " << cid.descricao << endl;
}

void imprimirMedicamento(Medicamento medicamento)
{
    cout << "\nMedicamento: " << medicamento.descricao << endl;
    cout << "Quantidade em estoque: " << medicamento.qtdEstoque << endl;
    cout << "Estoque minimo: " << medicamento.estoqueMinimo << endl;
    cout << "Estoque maximo: " << medicamento.estoqueMaximo << endl;
    cout << "Preco unitario: R$ " << medicamento.precoUnitario << endl;
}

void imprimirMedico(Medico medico, Cidade cidades[], int tamanhoCidades, Especialidade especialidades[], int tamanhoEspecialidades)
{
    cout << "\nNome: " << medico.nome << endl;

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

    int posicaoCidade = buscarCidadePorId(cidades, tamanhoCidades, medico.cod_cidade);
    if (posicaoCidade != -1)
    {
        imprimirCidade(cidades[posicaoCidade]);
    }
    else
    {
        cout << "Cidade nao encontrada!" << endl;
    }
}

void imprimirPaciente(Paciente paciente, Cidade cidades[], int tamanhoCidades)
{
    cout << "\nCPF: " << paciente.cpf << endl;
    cout << "Nome: " << paciente.nome << endl;
    cout << "Endereco: " << paciente.endereco << endl;

    int posicaoCidade = buscarCidadePorId(cidades, tamanhoCidades, paciente.cod_cidade);
    if (posicaoCidade != -1)
    {
        imprimirCidade(cidades[posicaoCidade]);
    }
    else
    {
        cout << "Cidade nao encontrada!" << endl;
    }
}

void imprimirConsulta(Consulta consulta,
                      Paciente pacientes[], int tamanhoPacientes,
                      Medico medicos[], int tamanhoMedicos,
                      Cidade cidades[], int tamanhoCidades,
                      Medicamento medicamentos[], int tamanhoMedicamentos,
                      Especialidade especialidades[], int tamanhoEspecialidades)
{
    cout << "\nData: " << consulta.data << endl;
    cout << "Horario: " << consulta.horario << endl;

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
        cout << "- Paciente: ";
        imprimirPaciente(pacientes[posicaoPaciente], cidades, tamanhoCidades);
    }
    else
    {
        cout << "Paciente nao encontrado!" << endl;
    }

    int posicaoMedico = buscarMedicoPorId(medicos, tamanhoMedicos, consulta.cod_medico);
    if (posicaoMedico != -1)
    {
        cout << "- Medico: ";
        imprimirMedico(medicos[posicaoMedico], cidades, tamanhoCidades,
                       especialidades, tamanhoEspecialidades);
    }
    else
    {
        cout << "Medico nao encontrado!" << endl;
    }

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
    cout << "\n9. Agendar consulta";
    cout << "\n10. Imprimir cidade";
    cout << "\n11. Imprimir especialidade";
    cout << "\n12. Imprimir cid";
    cout << "\n13. Imprimir medicamento";
    cout << "\n14. Imprimir medico";
    cout << "\n15. Imprimir paciente";
    cout << "\n16. Imprimir consulta";
    cout << "\n17. Excluir paciente";
    cout << "\n18. Valor total de consultas";
    cout << "\n0. Sair";
    cout << "\n\nOperacao: ";
}

void agendarConsulta(struct Consulta consultas[], int &tamanhoConsultas,
                     Paciente pacientes[], int tamanhoPacientes,
                     Medico medicos[], int tamanhoMedicos,
                     Cidade cidades[], int tamanhoCidades,
                     Medicamento medicamentos[], int tamanhoMedicamentos,
                     Especialidade especialidades[], int tamanhoEspecialidades, CID cids[], int tamanhoCids)
{
    if (tamanhoConsultas < 10)
    {
        int cpfPaciente;
        cout << "\nInforme o CPF do paciente: ";
        cin >> cpfPaciente;
        cin.ignore();

        int posicaoPaciente = -1;
        for (int i = 0; i < tamanhoPacientes; ++i)
        {
            if (pacientes[i].cpf == cpfPaciente)
            {
                posicaoPaciente = i;
                break;
            }
        }

        if (posicaoPaciente != -1)
        {
            cout << "\nPaciente encontrado:" << endl;
            cout << "Nome: " << pacientes[posicaoPaciente].nome << endl;
            cout << "Cidade: " << cidades[buscarCidadePorId(cidades, tamanhoCidades, pacientes[posicaoPaciente].cod_cidade)].nome << endl;
            cout << "UF: " << cidades[buscarCidadePorId(cidades, tamanhoCidades, pacientes[posicaoPaciente].cod_cidade)].uf << endl;

            int codMedico;
            cout << "\nInforme o codigo do medico: ";
            cin >> codMedico;
            cin.ignore();

            int posicaoMedico = buscarMedicoPorId(medicos, tamanhoMedicos, codMedico);
            if (posicaoMedico != -1)
            {
                cout << "\nMedico encontrado:" << endl;
                cout << "Nome: " << medicos[posicaoMedico].nome << endl;
                cout << "Especialidade: " << especialidades[buscarEspecialidadePorId(especialidades, tamanhoEspecialidades, medicos[posicaoMedico].cod_especialidade)].especializacao << endl;

                string data;
                cout << "\nInforme a data (DD/MM/AAAA): ";
                cin >> data;

                string hora;
                cout << "\nInforme a hora (HH:MM): ";
                cin >> hora;

                int codCid;
                cout << "\nInforme o codigo do CID: ";
                cin >> codCid;
                cin.ignore();

                int posicaoCid = buscarCIDPorId(cids, tamanhoCids, codCid);
                if (posicaoCid != -1)
                {
                    cout << "\nCID encontrado:" << endl;
                    cout << "Descricao: " << cids[posicaoCid].descricao << endl;

                    int codMedicamento;
                    cout << "\nInforme o codigo do medicamento: ";
                    cin >> codMedicamento;
                    cin.ignore();

                    int posicaoMedicamento = buscarMedicamentoPorId(medicamentos, tamanhoMedicamentos, codMedicamento);
                    if (posicaoMedicamento != -1)
                    {
                        cout << "\nMedicamento encontrado:" << endl;
                        cout << "Descricao: " << medicamentos[posicaoMedicamento].descricao << endl;

                        int qtdeMedicamento;
                        cout << "\nInforme a quantidade do medicamento: ";
                        cin >> qtdeMedicamento;
                        cin.ignore();

                        if (qtdeMedicamento <= medicamentos[posicaoMedicamento].qtdEstoque)
                        {
                            medicamentos[posicaoMedicamento].qtdEstoque -= qtdeMedicamento;

                            consultas[tamanhoConsultas].cod_paciente = cpfPaciente;
                            consultas[tamanhoConsultas].cod_medico = codMedico;
                            consultas[tamanhoConsultas].data = data;
                            consultas[tamanhoConsultas].horario = hora;
                            consultas[tamanhoConsultas].cod_medicamento = codMedicamento;
                            consultas[tamanhoConsultas].qtd_medicamento = qtdeMedicamento;

                            tamanhoConsultas++;
                            cout << "\nConsulta agendada com sucesso!\n";
                        }
                        else
                        {
                            cout << "\nQuantidade em estoque insuficiente!\n";
                        }
                    }
                    else
                    {
                        cout << "\nMedicamento nao encontrado!\n";
                    }
                }
                else
                {
                    cout << "\nCID nao encontrado!\n";
                }
            }
            else
            {
                cout << "\nMedico nao encontrado!\n";
            }
        }
        else
        {
            cout << "\nPaciente nao encontrado!\n";
        }
    }
    else
    {
        cout << "\nLimite maximo de consultas atingido.\n";
    }
}

void calcularValorTotalArrecadado(Consulta consultas[], int tamanhoConsultas, Medicamento medicamentos[], int tamanhoMedicamentos)
{
    float valorTotal = 0;
    for (int i = 0; i < tamanhoConsultas; i++)
    {
        valorTotal += 100;

        int posicaoMedicamento = buscarMedicamentoPorId(medicamentos, tamanhoMedicamentos, consultas[i].cod_medicamento);
        if (posicaoMedicamento != -1)
        {
            valorTotal += consultas[i].qtd_medicamento * medicamentos[posicaoMedicamento].precoUnitario;
        }
    }
    cout << "\nValor total arrecadado: R$" << valorTotal << endl;
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

    medicos[0] = {1, "Felipe Gabriel", 1, "Rua amado batista 202", "18996607060", 1};
    medicos[1] = {2, "Andrei Gabriel", 2, "Rua amado batista 203", "18996607060", 2};
    medicos[2] = {3, "Ricardo Gabriel", 3, "Rua amado batista 204", "18996607060", 3};
    medicos[3] = {4, "Antonio Gabriel", 4, "Rua amado batista 205", "18996607060", 4};
    medicos[4] = {5, "Lucas Gabriel", 5, "Rua amado batista 206", "18996607060", 5};

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
            agendarConsulta(consultas, tamanhoConsultas, pacientes, tamanhoPacientes,
                            medicos, tamanhoMedicos, cidades, tamanhoCidades,
                            medicamentos, tamanhoMedicamentos, especialidades, tamanhoEspecialidades, cids, tamanhoCids);
            break;

        case 10:

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

        case 15:

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

        case 16:
            if (tamanhoConsultas > 0)
            {
                cout << "\nImprimindo consultas:\n";
                for (int i = 0; i < tamanhoConsultas; ++i)
                {
                    imprimirConsulta(consultas[i],
                                     pacientes, tamanhoPacientes,
                                     medicos, tamanhoMedicos,
                                     cidades, tamanhoCidades,
                                     medicamentos, tamanhoMedicamentos,
                                     especialidades, tamanhoEspecialidades);
                }
            }
            else
            {
                cout << "\nNenhuma consulta cadastrada.\n";
            }
            break;

        case 17:
            if (tamanhoPacientes > 0)
            {
                excluirPaciente(pacientes, tamanhoPacientes);
            }
            else
            {
                cout << "\nNenhum paciente cadastrado.\n";
            }
            break;

        case 18:
            calcularValorTotalArrecadado(consultas, tamanhoConsultas, medicamentos, tamanhoMedicamentos);
            break;

        default:
            cout << "\nFim do programa!\n";
            break;
        }
    }

    return 0;
}