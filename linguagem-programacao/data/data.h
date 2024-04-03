#include <iostream>

using namespace std;

class Data {
    //atributos
    private:
        int dia;
        int mes;
        int ano;

    //métodos
    public:
        Data();
        //Data(int dia, int mes, int ano);
        Data(int dia, int mes, int ano): dia(dia), mes(mes), ano(ano) {} //construtor parametrizado inline
        ~Data();

        void imprimir();

        //acessores
        int getDia() {return this->dia;};
        int getMes() {return this->mes;};
        int getAno() {return this->ano;};

        //modificadores
        int setDia(int dia);
        int setMes(int mes);
        int setAno(int ano);
};

Data::~Data(){
    cout << "\nPassei pelo destrutor de fata...\n\n";
}

Data::Data(){
    this->dia = 1;
    this->mes = 1;
    this->ano = 1990;
}

int Data::setDia(int dia) {
    if(dia >= 1 && dia <= 31) return this->dia = dia;
    else return this->ano = 1990;
}
int Data::setMes(int mes) {
    if(mes >= 1 && mes <= 12 ) return this->mes = mes;
    else return this->ano = 1990;
}
int Data::setAno(int ano){
    if(ano >=1990 && ano <= 2100) return this->ano = ano;
    else return this->ano = 1990;
}

/* Data::Data(int dia, int mes, int ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
} */

void Data::imprimir(){
    cout <<"\n-----Exibindo informacoes da data-----\n";
    cout <<"Data: " << this->dia << "/" << this->mes << "/" << this->ano << endl;
}