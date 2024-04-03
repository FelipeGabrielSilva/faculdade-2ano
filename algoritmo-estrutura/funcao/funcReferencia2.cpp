#include <iostream>

using namespace std;

int soma(int x, int y, int &z)
{
    int s = (x + y + z);
    z = (x - y - z);
    return s;
}

int main()
{
    int a, b, c;

    cout << "Informe tres valores: ";
    cin >> a >> b >> c;

    cout << "\nA soma dos tres valores eh: " << soma(a, b, c) << endl;
    cout << "\nA subtracao dos tres valores eh: " << c;

    return 0;
}