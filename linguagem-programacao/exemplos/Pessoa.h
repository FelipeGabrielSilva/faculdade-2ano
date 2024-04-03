//Pessoa.h

class Pessoa: public Tipo{
    //atributo
    private:
      int id;
      string nome;
      int idade;
    //metodos
    public:
        //sobrecarga (overload dos construtores)
      Pessoa();
      Pessoa(int, string, int, Tipo); //recebe um objeto do tipo Tipo
      Pessoa(int, string, int, int, string); //recebe os atributos de pessoa + os atributos de Tipo

     void imprimir();

};

Pessoa::Pessoa(){
    this->id = 0;
    this->nome = "";
    this->idade = 0;
    //this->Tipo::setId(0);
    this->Tipo::id = 0;
    this->Tipo::descricao = "";
}

Pessoa::Pessoa(int id, string nome, int idade, Tipo tipo){
    this->id = id;
    this->nome = nome;
    this->idade = idade;
    this->Tipo::setId(tipo.getId());
    //this->Tipo::id = tipo.getId();
    this->Tipo::descricao = tipo.getDescricao();
}

Pessoa::Pessoa(int id, string nome, int idade, int idTipo, string descricao){
    this->id = id;
    this->nome = nome;
    this->idade = idade;
    this->Tipo::id = idTipo;
    this->Tipo::descricao = descricao;
}


void Pessoa::imprimir(){
    cout << "\nImprimir Pessoa\n";
    cout << "Id de Pessoa: " << this->id << endl;
    cout << "Nome: " << this->nome << endl;
    cout << "Idade: " << this->idade << endl;
    cout << "ID de Tipo: " << this->Tipo::id << endl;
    //cout << "Descricao: " << this->Tipo::descricao << endl;
    cout << "Descricao: " << this->Tipo::getDescricao() << endl;
}
