//PessoaAgr.h

class PessoaAgr{
    //atributos
    private:
        int id;
        string nome;
        int idade;
        Tipo tipo;

    //métodos
    public:
        PessoaAgr();
        PessoaAgr(int, string, int, Tipo);

        //gets
        int getId() {return this->id;}
        string getNome() {return this->nome;}
        int getIdade() {return this->idade;}
        Tipo getTipo() {return this->tipo;}

        //sets
        void setId(int id) {this->id = id;}
        void setNome(string nome) {this->nome = nome;}
        void setIdade(int idade) {this->idade = idade;}
        void setTipo(Tipo tipo) {this->tipo = tipo;}

        void imprimir();
};

PessoaAgr::PessoaAgr(){
    this->id = 0;
    this->nome = "";
    this->idade = 0;
    //this->tipo.setId(0);
    //this->tipo.setDescricao("");
    this->tipo = Tipo();
}

PessoaAgr::PessoaAgr(int id, string nome, int idade, Tipo tipo){
    this->id = id;
    this->nome = nome;
    this->idade = idade;
    //this->tipo.setId(tipo.getId());
    //this->tipo.setDescricao(tipo.getDescricao());
    this->tipo = tipo;

}

void PessoaAgr::imprimir(){
    cout << "\nImprimir Pessoa com agregação\n";
    cout << "ID: " << this->id << endl;
    cout << "Nome: " << this->nome << endl;
    cout << "Idade: " << this->idade << endl;
    cout << "ID de Tipo: " << this->tipo.getId() << endl;
    cout << "Descricao: " << this->tipo.getDescricao() << endl;

}
