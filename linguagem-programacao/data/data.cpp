#include <iostream>
#include "data.h"

using namespace std;

int main() {
    Data date1(11, 6, 2002);
    date1.imprimir();

    Data date2(19, 5, 2007);
    date2.imprimir();

    Data date3(1, 4, 1946);
    date3.imprimir();

    Data date4(6, 4, 1978);
    date4.imprimir();

    date4.setAno(2027);
    date4.imprimir();

    return 0;
}