#include <iostream>

using namespace std;

void exibirNome( char vetorNome[]){
    for(int i = 0; vetorNome[i] != '\0'; i++){
        cout << "Caractere do vetor: " << vetorNome[i] << endl;
    }
}

int main(){
    char vetorNome[] = "Felipe Gabriel da Silva";

    exibirNome(vetorNome);

    return 0;
}