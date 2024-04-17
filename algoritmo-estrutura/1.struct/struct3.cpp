#include <iostream>

using namespace std;

struct produto // definindo de forma global para usar como TIPO para função
{
    int codigo;
    char descricao[30];
    int qtd;
    float preco;
};

void exibirMenor50(const produto &p)
{
    // Exibindo as informações do produto
    cout << "\n-----Produto com estoque abaixo de 50------\n";

    cout << "Codigo: " << p.codigo << endl;

    cout << "Descricao do produto: " << p.descricao << endl;

    cout << "Quantidade em estoque: " << p.qtd << endl;

    cout << "Preco: R$" << p.preco << endl;
}

int main()
{
    int tamanho = 0;
    cout << "Informe a quantidade de produtos a serem cadastradas: ";
    cin >> tamanho;

    struct produto vProdutos[tamanho];

    // Lendo as informações do produto
    for (int i = 0; i < tamanho; i++)
    {
        cout << "\n-----Informe as informacoes do produto------\n";

        cout << "Informe o codigo: ";
        cin >> vProdutos[i].codigo;

        cout << "Informe a descricao do produto: ";
        cin >> vProdutos[i].descricao;

        cout << "Infrome a quantidade em estoque: ";
        cin >> vProdutos[i].qtd;

        cout << "Informe o preco: R$";
        cin >> vProdutos[i].preco;
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (vProdutos[i].qtd < 50)
        {
            exibirMenor50(vProdutos[i]);
        }
    }

    return 0;
}