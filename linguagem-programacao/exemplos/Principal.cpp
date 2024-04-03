//Principal.cpp
#include <iostream>
using namespace std;
#include "Data.h"

int main(){
    Data data1(32, 12, -3434);
    data1.imprimir();

    cout << "dia: " << data1.getDia() << endl;
    data1.setDia(23);
    cout << "dia: " << data1.getDia() << endl;
}
