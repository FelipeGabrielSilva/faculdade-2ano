#ifndef IFIGURA_H
    #include "IFigura.h"
#endif

#ifndef RETANGULO_H
    #define RETANGULO_H
#endif

class Retangulo: public IFigura {
    private:
        float base;
        float altura;

    public:
        Retangulo(): base(0), altura(0){}
        Retangulo(float base, float altura): base(base), altura(altura){}

        float getBase() const {return this->base;}
        float getAltura() const {return this->altura;}

        void setBase(float base) {this->base = base;}
        void setAltura(float altura) {this->altura = altura;}

        float area() {return this->base * this->altura;}
        float perimetro() {return (this->base * 2) +(this->altura * 2);}
};