#include <iostream>

using namespace std;

struct carro //definindo de forma global para usar como TIPO para função
{
    char marca[15];
    char modelo[15];
    char chassi[15];
    int ano;
    float preco;
    int km;
};

void funcao(struct carro parametros)
{
    cout << parametros.marca << endl;
    cout << parametros.km << endl;
}

int main()
{
    struct carro meuCarro, carroDele, carroEmpresa;

    cin >> meuCarro.marca;
    cin >> carroEmpresa.marca;

    cout << meuCarro.marca << endl;
    cout << carroDele.marca << endl;
    cout << carroEmpresa.marca << endl;

    meuCarro.km = 0;
    cout << meuCarro.km << endl;
    cout << meuCarro.preco << endl;

    funcao(carroEmpresa);

    return 0;
}