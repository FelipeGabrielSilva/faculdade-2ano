//Tipo.h
class Tipo{
   //atributos
   protected:
       int id;
       string descricao;
   public:
       //construtores
       Tipo(): id(0), descricao(""){}
       Tipo(int id, string descricao): id(id), descricao(descricao){}

       //métodos de acesso - gets
       int getId() {return this->id;}
       string getDescricao() {return this->descricao;}

       //métodos modificadores - sets
       void setId(int id) {this->id = id;}
       void setDescricao(string descricao) {this->descricao = descricao;}

       void imprimir () {cout << "\nTipo: " << this->id << "-" << this->descricao << endl;}

};
