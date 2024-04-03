//principal.cpp
#include <iostream>
using namespace std;

#ifndef IFIGURA_H
    #include "IFigura.h"
#endif

#ifndef QUADRADO_H
    #include "Quadrado.h"
#endif

#ifndef RETANGULO_H
    #include "Retangulo.h"
#endif

#ifndef CIRCULO_H
    #include "Circulo.h"
#endif

int main() {
    Quadrado ql(5);
    cout << "\nArea do quadrado: " << ql.area();
    cout << "\nTamanho do quadrado: " << ql.getTamanho();
    cout << "\nPerimetro do quadrado: " << ql.perimetro();

    Retangulo r1(4, 5);
    cout << "\nArea do retangulo: " << r1.area();
    cout << "\n\nBase do retangulo: " << r1.getBase();
    cout << "\nAltura do retangulo: " << r1.getAltura();
    cout << "\nPerimetro do retangulo: " << r1.perimetro();

    Circulo c1(5);
    cout << "\n\nArea do circulo: " << c1.area();
    cout << "\nPerimetro do circulo:  " << c1.perimetro();

    return 0;
}