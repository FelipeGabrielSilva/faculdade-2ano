#include <iostream>
#include <locale.h>

using namespace std;

void somaMedia(int &x, int &y)
{
    x = x + y;
    y = x / 2;
}

int main()
{
    setlocale(LC_ALL, "");
    int a, b;

    cout << "Informe dois valores: ";
    cin >> a >> b;

    somaMedia(a, b);

    cout << "\nO resultado da soma dos valores eh: " << a;
    cout << "\nO resultado da media dos valores eh: " << b;

    return 0;
}