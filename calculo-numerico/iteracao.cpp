#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{

    cout << fixed << setprecision(4);

    int a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    float beta1, beta2, beta3, betaMax, x0, y0, z0, erro;

    char opcao;
    cout << "Deseja preencher as vari�veis manualmente? (S/N): ";
    cin >> opcao;

    if (opcao == 'S' || opcao == 's')
    {
        cout << "\nInforme os valores de a1, b1, c1, d1: \n";
        cin >> a1 >> b1 >> c1 >> d1;
        cout << "\nInforme os valores de a2, b2, c2, d2: \n";
        cin >> a2 >> b2 >> c2 >> d2;
        cout << "\nInforme os valores de a3, b3, c3, d3: \n";
        cin >> a3 >> b3 >> c3 >> d3;
    }
    else
    {
        a1 = 5;
        b1 = 1;
        c1 = 1;
        d1 = 5;
        a2 = 3;
        b2 = 4;
        c2 = 1;
        d2 = 6;
        a3 = 1;
        b3 = 1;
        c3 = 2;
        d3 = 0;
    }

    // Resultados das variaveis BETAS
    beta1 = fabs((b1 + c1) / static_cast<float>(a1));
    beta2 = fabs(((a2 * beta1) + c2) / static_cast<float>(b2));
    beta3 = fabs(((a3 * beta1) + (b3 * beta2)) / static_cast<float>(c3));
    betaMax = max({beta1, beta2, beta3});

    cout << "BetaMax: " << betaMax << endl;

    if (betaMax < 1)
    {
        cout << "\nConverge!(" << betaMax << " < 1)\n";
    }
    else
    {
        cout << "\nNao converge!(" << betaMax << " > 1)\n";
        return 0;
    }

    // Solucao inicial
    x0 = d1 / static_cast<float>(a1);
    y0 = d2 / static_cast<float>(b2);
    z0 = d3 / static_cast<float>(c3);

    cout << "\nSolucao inicial: \n";
    cout << "\nx0: " << x0 << endl;
    cout << "y0: " << y0 << endl;
    cout << "z0: " << z0 << endl;

    // Informando a tolerancia de erro
    cout << "\nInforme o erro: ";
    cin >> erro;

    // Iteracoes
    int iteracao = 0;
    float x, y, z;
    float erro_atual;
    do
    {
        iteracao++;
        x = (d1 - b1 * y0 - c1 * z0) / static_cast<float>(a1);
        y = (d2 - a2 * x - c2 * z0) / static_cast<float>(b2);
        z = (d3 - a3 * x - b3 * y) / static_cast<float>(c3);

        cout << "\nIteracao " << iteracao << ":\n";
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;

        erro_atual = max({fabs(x - x0), fabs(y - y0), fabs(z - z0)});
        x0 = x;
        y0 = y;
        z0 = z;

    } while (erro_atual > erro);

    cout << "\nSolucao aproximada:\n";
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
    cout << "\nEr " << erro_atual << " < " << erro << " E" << endl;

    return 0;
}
