#include <iostream>

using namespace std;

void soma(int x, int y, int z, int &adicao, int &subtracao)
{
    adicao = x + y + z;
    subtracao = x - y - z;
}

int main()
{
    int num1, num2, num3, adic, subt;

    cout << "Informe um valor para o 1: ";
    cin >> num1;

    cout << "Informe um valor para o 2: ";
    cin >> num2;

    cout << "Informe um valor para o 3: ";
    cin >> num3;

    soma(num1, num2, num3, adic, subt);
    cout << "\nResultado da soma " << num1 << " + " << num2 << " eh: " << adic;
    cout << "\nResultado da subtracao " << num1 << " - " << num2 << " eh: " << subt;

    return 0;
}