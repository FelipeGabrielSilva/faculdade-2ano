//Produto.h
class Produto:public Medida{
    //atributos
    private:
        int id;
        string descricao;
        float qtde;
        float valor;

    //métodos
    public:
        Produto();
        Produto(int, string, float, float, int, string);

        //gets
        int getId() {return this->id;}
        string getDescricao() {return this->descricao;}
        float getQtde() {return this->qtde;}
        float getValor() {return this->valor;}

        //sets
        void setId(int id) {this->id = id;}
        void setDescricao(string descricao){ this->descricao = descricao;}
        void setQtde(float qtde){this->qtde = qtde;}
        void setValor(float valor){this->valor = valor;}

        //polimorfismo de sobrecarga - overload
        void aumento() {this->valor = this->valor * 1.1;}
        void aumento(int perc) {this->valor = this->valor + this->valor*perc/100;}

        void imprimir();
};

Produto::Produto(){
    this->id = 0;
    this->descricao = "";
    this->qtde = 0;
    this->valor = 0;
    this->Medida::id = 0;
    this->Medida::descricao = "";
}

Produto::Produto(int idPro, string descPro, float qtde, float valor, int idMed, string descMed){
    this->id = idPro;
    this->descricao = descPro;
    this->qtde = qtde;
    this->valor = valor;
    this->Medida::id = idMed;
    this->Medida::descricao = descMed;
}


void Produto::imprimir(){ //sobreposição (override) método imprimir de Medida
    cout << "\nImprimir Produto\n";
    cout << "ID: " << this->id << endl;
    cout << "Descricao: " << this->descricao << endl;
    cout << "Quantidade: " << this->qtde << endl;
    cout << "Valor: " << this->valor << endl;
    cout << "Id Medida: " << Medida::id << endl;
    cout << "Descricao Medida: " << Medida::descricao << endl;




}
