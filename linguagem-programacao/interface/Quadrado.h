#ifndef IFIGURA_H
    #include "IFigura.h"
#endif

#ifndef QUADRADO_H
    #define QUADRADO_H
#endif

class Quadrado: public IFigura {
    private:
        float tamanho;
    public:
        Quadrado(): tamanho(0){}
        Quadrado(int tamanho): tamanho(tamanho){}

        float getTamanho() const {return this->tamanho;}
        void setTamanho(float tamanho) {this->tamanho = tamanho;} 

        float area() {
            float calc = this->tamanho * this->tamanho;
            return calc;
        }

        float perimetro() { return this->tamanho * 4;}
};
