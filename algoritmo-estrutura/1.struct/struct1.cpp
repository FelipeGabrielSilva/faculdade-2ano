#include <iostream>

using namespace std;

int main()
{
    struct carro
    {
        char marca[15];
        char modelo[15];
        char chassi[15];
        int ano;
        float preco;
        int km;
    } meuCarro, carroDele, carroEmpresa;

    cin >> meuCarro.marca;     // lendo a marca do meu carro
    cin >> carroEmpresa.marca; // lendo a marca do carro da empresa

    cout << meuCarro.marca << endl;     // imprimindo a marca do meu carro
    cout << carroDele.marca << endl;    // imprimindo a marca do carro de outra pessoa
    cout << carroEmpresa.marca << endl; // imprimindo a marca do carro da empresa

    meuCarro.km = 0; // zerando o km do meu carro

    cout << meuCarro.km << endl;    // imprimindo o km do meu carro
    cout << meuCarro.preco << endl; // imprimindo o valor do meu carro

    return 0;
}