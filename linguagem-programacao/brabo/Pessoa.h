// Pessoa.h
// #include "Tipo.h"

class Pessoa : public Tipo
{
private:
  int id;
  string nome;
  int idade;

  // métodos
public:
  // construtores
  Pessoa() : Tipo(), id(0), nome(""), idade(0) {}
  Pessoa(int, string, int, Tipo);
  void imprimir();

  // metodos gets
  int getId() { return this->id; }
  string getNome() { return this->nome; }
  int getIdade() { return this->idade; }

  // métodos sets
  void setId(int id) { this->id = id; }
  void setNome(string nome) { this->nome = nome; }
  void setIdade(int idade) { this->idade = idade; }
};

Pessoa::Pessoa(int id, string nome, int idade, Tipo tipo)
{
  this->id = id;
  this->nome = nome;
  this->idade = idade;
  this->Tipo::id = tipo.getId();
  this->Tipo::descricao = tipo.getDescricao();
}

void Pessoa::imprimir()
{
  cout << "\nID: " << this->id << endl;
  cout << "Nome: " << this->nome << endl;
  cout << "Idade: " << this->idade << endl;
  cout << "Tipo: " << Tipo::getId() << " - " << Tipo::descricao << endl;
}
