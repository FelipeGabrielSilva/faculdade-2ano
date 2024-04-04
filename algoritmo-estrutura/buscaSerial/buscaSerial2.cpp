#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Pessoa {
    int id;
    char nome[30];
    char endereco[30];
    char cidade[20];
    char uf[2];
};

void lerInformacao(int tam, struct Pessoa x[]){
    for(int i=0; i < tam; i++){
        cout << "\nDigite o ID: ";
        cin >> x[i].id;

        cin.ignore();

        cout << "Digite o nome: ";
        cin.getline(x[i].nome, 30);

        cout << "Digite o endereco: ";
         cin.getline(x[i].endereco, 30);

        cout << "Digite o cidade: ";
         cin.getline(x[i].cidade, 20);

        cout << "Digite o UF: ";
         cin.getline(x[i].uf, 3);
    }
}

void buscarInformacao(int tam, struct Pessoa x[]){
    int buscarID;
    int i=0;
    cout << "\nInforme o ID para busca: ";
    cin >> buscarID;

    //int i fora do for por conta dele ser necesssário depois
    for(; i < tam && buscarID > x[i].id; i++ );
    if(buscarID == x[i].id){
        cout << "\nID encontradado!";
        cout << "\nNome: " << x[i].nome;
        cout << "\nEndereco: " << x[i].endereco;
        cout << "\nCidade: " << x[i].cidade;
        cout << "\nUF: " << x[i].uf;
    } 
    else {
        cout << "\nID nao encontrado!";
    }
}

int main(){ 
    int tam = 1;
    struct Pessoa vPessoas[tam];

    lerInformacao(tam, vPessoas);
    buscarInformacao(tam, vPessoas);

    return 0;
}