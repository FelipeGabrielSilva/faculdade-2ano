//Data.h
class Data{
   //atributos
   private:
     int dia;
     int mes;
     int ano;

   //métodos
   public:
      //Data();  //construtor padrão
      Data(): dia(1), mes(1), ano(2024){} // construtor padrão inline
      //construtor parametrizado
      Data(int, int, int);
     //Data(int dia, int mes, int ano): dia(dia), mes(mes), ano(ano){ }

      //métodos acessores - gets
      int getDia(); //métodos get implementado no corpo da classe
      int getMes() {return this->mes;} //métodos get implementado inline
      int getAno() {return this->ano;}

      //métodos modificadores - sets
      //void setDia(int dia) {this->dia = dia;} //inline
      void setDia(int);
      void setMes(int mes) {this->mes = (mes>0 && mes<13) ?mes :1;}
      //void setAno(int); // no corpo da classe
      void setAno(int ano){this->ano = (ano>=1900 && ano<=2100) ?ano :2025;}

      //outros métods
      void imprimir();
};

/*
Data::Data(){
    dia = 1;
    mes = 1;
    ano = 1900;
}
*/

Data::Data(int aDia, int aMes, int aAno){
    //this->dia = aDia;
    //this->mes = aMes;
    //this->ano = aAno;
    setAno(aAno);
    setMes(aMes);
    setDia(aDia);
}

int Data::getDia(){
   return dia;
}

void Data::setDia(int dia){
   if (this->mes==2){ //mês de fevereiro
      if (this->ano%4==0) // ano bissexto 29 dias
        if (dia>0&&dia<30)
           this->dia = dia;
        else this->dia = 1;
      else  if (dia>0 && dia<29) // ano normal 28 dias
           this->dia = dia;
        else this->dia = 1;
   }
   else if (mes==4 || mes==6||mes==9 || mes==11){ //mes com 30 dias
            if (dia>0 && dia<31)
                this->dia=dia;
           else this->dia =1;
        }
        else { //mês com 31 dias
            if (dia>0 && dia <32)
                this->dia=dia;
            else this->dia =1;
        }

}

/*
void Data::setAno(int ano){
  //if(ano>=1900 && ano<=2100)
  //   this->ano = ano;
 // else this->ano = 2025;

  this->ano = (ano>=1900 && ano<=2100) ?ano :2025;
}*/


void Data::imprimir(){
    cout << "\nData: " << this->dia
         << "/" << this->mes << "/"
         << this->ano << endl;
}



