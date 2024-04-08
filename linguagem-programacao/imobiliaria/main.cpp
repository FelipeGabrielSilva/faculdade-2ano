#include <iostream>
#include <stdlib.h>
using namespace std;

#ifndef TIPOIMOVEL_H
#include "TipoImovel.h"
#endif

#ifndef IMOVEL_H
#include "Imovel.h"
#endif

#ifndef PROFISSAO_H
#include "Profissao.h"
#endif

#ifndef LOCADOR_H
#include "Locador.h"
#endif

#ifndef LOCACAO_H
#include "Locacao.h"
#endif

void limpar(int &x)
{
    cout << "\n\nPressione a tecla x para avancar: ";
    cin >> x;
    system("cls");
}

int main()
{
    int x;
    // Definindo um tipo imovel
    TipoImovel tipo1(1, "Casa");
    tipo1.imprimir();

    // Alterando as informações do tipo imóvel
    tipo1.setID(22);
    tipo1.setDescricao("Apartamento");
    tipo1.imprimir();

    // Definindo um imóvel
    Imovel imovel1(1, "joaquim", "pamanho", "assis", true, tipo1);
    imovel1.imprimir();

    // Atualizando o imóvel e imprimindo
    imovel1.setRua("jose");
    imovel1.setBairro("novamerica");
    imovel1.setCidade("taruma");
    imovel1.setOcupado(false);
    imovel1.imprimir();
    limpar(x);

    // Definindo uma profissão
    Profissao profissao1(1, "Dev");
    profissao1.imprimir();

    // Atualizando as inforamções da profissão
    profissao1.setID(54);
    profissao1.setDescricao("Cozinheiro");
    profissao1.imprimir();

    // Definindo um locador
    Locador locador1(1, "felipe", "assis", "sp", 21, 3490.75, profissao1);
    locador1.imprimir();
    limpar(x);

    // Definindo uma locação
    Locacao loca1(1, imovel1, locador1, "11/06/2002", 50000.99);
    loca1.imprimir();

    return 0;
}