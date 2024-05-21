#include <iostream>

using namespace std;

int main()
{

    float dado, TC_TK, TK_TC, TC_TF, TF_TC, TK_TF, TF_TK;
    int selecao;
    char sair = 'n';

    while (sair != 's')
    {
        cout << "Selecione uma opção abaixo: \n";
        cout << "1) - Celcius para Kelvin: " << endl;
        cout << "2) - Kelvin para Celcius: " << endl;
        cout << "3) - Celcius para Fahrenheit: " << endl;
        cout << "4) - Fahrenheit para Celcius: " << endl;
        cout << "5) - Kelvin para Fahrenheit: " << endl;
        cout << "6) - Fahrenheit para Kelvin: " << endl;
        cin >> selecao;

        switch (selecao)
        {
        case 1:
            cout << "\nSelecionado Celcius para Kelvin. \n";
            cout << "\nInforme a temperatura em Celcius: \n";
            cin >> dado;
            TC_TK = dado + 273.15;
            cout << TC_TK << " K" << endl;
            break;
        case 2:
            cout << "\nSelecionado Kelvin para Celcius. \n";
            cout << "\nInforme a temperatura em Kelvin: \n";
            cin >> dado;
            TK_TC = dado - 273.15;
            cout << TK_TC << "° C" << endl;
            break;
        case 3:
            cout << "\nSelecionado Celcius para Fahrenheit. \n";
            cout << "\nInforme a temperatura em Celcius: \n";
            cin >> dado;
            TC_TF = dado * 9 / 5 + 32;
            cout << TC_TF << "° F" << endl;
            break;
        case 4:
            cout << "\nSelecionado Fahrenheit para Celcius. \n";
            cout << "\nInforme a temperatura em Fahrenheit: \n";
            cin >> dado;
            TF_TC = (dado - 32) * 5 / 9;
            cout << TF_TC << "° C" << endl;
            break;
        case 5:
            cout << "\nSelecionado Kelvin para Fahrenheit. \n";
            cout << "\nInforme a temperatura em Kelvin: \n";
            cin >> dado;
            TK_TF = (dado - 273.15) * 9 / 5 + 32;
            cout << TK_TF << "° F" << endl;
            break;
        case 6:
            cout << "\nSelecionado Fahrenheit para Kelvin. \n";
            cout << "\nInforme a temperatura em Fahrenheit: \n";
            cin >> dado;
            TF_TK = (dado - 32) * 5 / 9 + 273.15;
            cout << TF_TK << " K" << endl;
            break;
        default:
            cout << "\nInforme uma opção válida!";
            break;
        }

        cout << "\nDeseja sair? (s/n): ";
        cin >> sair;
    }

    return 0;
}
