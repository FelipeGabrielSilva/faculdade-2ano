#include <iostream>
#include <locale.h>

using namespace std;

void func(int &x, int &y, int &z)
{
    int maior = x, menor = x;

    if (menor > y)
    {
        menor = y;
    }
    else if (menor > z)
    {
        menor = z;
    }

    y = menor;

    if (maior < y)
    {
        maior = y;
    }
    else if (maior < z)
    {
        maior = z;
    }

    x = (x + y + z) / 2;

    z = maior;
}

int main()
{
    setlocale(LC_ALL, "");
    int a, b, c;

    cout << "Informe tres valores: ";
    cin >> a >> b >> c;

    func(a, b, c);

    cout << "\nO menor entre os tres: " << b;
    cout << "\nO Maior valor entre os tres: " << c;
    cout << "\nO resultado da media entre os tres valores: " << a;

    return 0;
}