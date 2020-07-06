#include <stdlib.h> ///Biblioteca a incluir para gerar nœmeros aleatórios
#include <time.h>   ///Biblioteca a incluir para gerar nœmeros aleatórios
#include <iostream>
using namespace std;

int main(){

    int numero;

    srand((unsigned)time(NULL) ); ///Comando obrigatório antes de gerar nœmeros aleatórios

    ///gerando numero aleatório
    //numero = rand()%10-5;  ///o comando rand() gera o numero aleatório o mod delimita o intervalo, neste caso de 0 a 9. O +1 no final garante a geração de 1 a 10
    //cout << numero << endl;

    ///gerando novo numero
    numero = rand()%10-5;
    cout << numero << endl;

    return 0;
}
