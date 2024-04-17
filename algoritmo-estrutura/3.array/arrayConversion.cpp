#include <iostream>

using namespace std;

void converter (char *sptr){
    while(*sptr != '\0') {
        if(*sptr >= 'a' && *sptr <= 'z'){
            *sptr = toupper(*sptr);
        }
         sptr++;
    }
}

int main(){
    char string[] = "caracteres e valor $32.98";

    cout << "A string antes da conversao: " << string;
    converter(string);
    cout << "\nA string depois de convertida: " << string << endl;

    return 0;
}