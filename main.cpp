#include <stdlib.h> ///Biblioteca a incluir para gerar n�meros aleat�rios
#include <time.h>   ///Biblioteca a incluir para gerar n�meros aleat�rios
#include <iostream>
using namespace std;

int main(){

    int numero;

    srand((unsigned)time(NULL) ); ///Comando obrigat�rio antes de gerar n�meros aleat�rios

    ///gerando numero aleat�rio
    //numero = rand()%10-5;  ///o comando rand() gera o numero aleat�rio o mod delimita o intervalo, neste caso de 0 a 9. O +1 no final garante a gera��o de 1 a 10
    //cout << numero << endl;

    ///gerando novo numero
    numero = rand()%10-5;
    cout << numero << endl;

    return 0;
}
