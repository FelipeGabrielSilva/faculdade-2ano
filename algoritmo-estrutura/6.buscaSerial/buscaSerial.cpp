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
    int buscarID, amzI, amzID;
    cout << "\nInforme o ID para busca: ";
    cin >> buscarID;

    //for(int i=0; i < tam; i++)
    for(int i=0; i < tam && buscarID > x[i].id< i++ )
        if(buscarID == x[i].id ){
            amzID = x[i].id;
            amzI = i;
        }
    } 

    if(buscarID == amzID){
        cout << "\nID encontradado: " << x[amzI].id;
        cout << "\nNome: " << x[amzI].nome;
        cout << "\nEndereco: " << x[amzI].endereco;
        cout << "\nCidade: " << x[amzI].cidade;
        cout << "\nUF: " << x[amzI].uf;
        } else {
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