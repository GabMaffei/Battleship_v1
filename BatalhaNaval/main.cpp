#include <stdlib.h> ///Biblioteca a incluir para gerar nœmeros aleatórios
#include <time.h>   ///Biblioteca a incluir para gerar nœmeros aleatórios
#include <locale.h> ///Biblioteca para inserir texto acentuado
#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese"); ///Comando para selecionar idioma português
    srand((unsigned)time(NULL) ); ///Comando obrigatório antes de gerar nœmeros aleatórios

    int pa1x, pa1y, pa5x, pa5y; ///Posição inicial e final do porta-aviões no eixo x e no no eixo y -Gabriel Maffei
    int paOrient; ///Orientação do porta-aviões (0 = vertical; 1 = horizontal)
    int pa2x, pa3x, pa4x, pa2y, pa3y, pa4y; ///DEBUG (verificar engine de colisão)
    do {
    pa1x = rand()%9 - 4; ///Randomização das posições
    pa1y = rand()%9 - 4;
    paOrient = rand()%2;
    if (paOrient == 0){ ///Verifica orientação
        pa5y = pa1y - 4; ///Verifica se posição é válida na vertical
        pa5x = pa1x;
        pa2x = pa1x;
        pa3x = pa1x;
        pa4x = pa1x;
        pa2y = pa1y - 1;
        pa3y = pa1y - 2;
        pa4y = pa1y - 3;
        if (!(pa5y <= -5)){
            break;
        }
    } else {
        pa5x = pa1x + 4; ///Verifica se posição é válida na horizontal
        pa5y = pa1y;
        pa2y = pa1y;
        pa3y = pa1y;
        pa4y = pa1y;
        pa2x = pa1x + 1;
        pa3x = pa1x + 2;
        pa4x = pa1x + 3;
        if (!(pa5x >= 5)) {
            break;
        }
    }
    } while (true);

    int nt1x, nt1y, nt4x, nt4y; ///Posição inicial do navio-tanque
    int nt2x, nt3x, nt2y, nt3y; ///DEBUG (verificar engine de colisão)
    int ntOrient; ///Orientação do navio-tanque
    bool veriPos, veriPos2, veriPos3; ///Verificador de posição válida
    do {
    nt1x = rand()%9 - 4; ///Randomização das posições
    nt1y = rand()%9 - 4;
    ntOrient = rand()%2;
    if (ntOrient == 0){
        nt4y = nt1y - 3; ///Na vertical
        nt4x = nt1x;
        nt2x = nt1x; ///DEBUG
        nt3x = nt1x;
        nt2y = nt1y - 1;
        nt3y = nt1y - 2;
        if (nt4y <= -5){     ///Verifica se está dentro do mapa
            veriPos = true;
        } else {
            if (paOrient == 0){ ///Porta-aviôes na vertical
                if (nt1x == pa1x){ ///Mesmo eixo x
                    if ((nt1y <= pa1y && nt1y >= pa5y) || (nt4y <= pa1y && nt4y >= pa5y)){
                        veriPos = true;
                    } else {
                        veriPos = false; ///Não estão nas mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos = false;
                }
            } else { ///Porta-aviões na horizontal
                if ((nt1x >= pa1x) && (nt1x <= pa5x)){ ///Mesmo eixo x
                    if (pa1y <= nt1y && pa1y >= nt4y){
                        veriPos = true; ///Mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos = false;
                }
            }
        }
    } else { ///Na horizontal
        nt4x = nt1x + 3;
        nt4y = nt1y;
        nt2y = nt1y;
        nt3y = nt1y;
        nt2x = nt1x + 1;
        nt3x = nt1x + 2;
        if (nt4x >= 5) {    ///Verifica se está dentro do mapa
            veriPos = true;
        } else {
            if (paOrient == 0){ ///Porta-aviões está na vertical
                if (pa1x >= nt1x && pa1x <= nt4x){ ///Mesmo eixo x
                    if((nt1y <= pa1y) && (nt1y >= pa5y)){ ///Mesma posição
                        veriPos = true;
                    } else {
                        veriPos = false; ///Posição é diferente
                    }
                } else {
                    veriPos = false; ///Eixo x diferente
                }
            } else { ///Porta-aviões está na horizontal
                if (nt1y == pa1y){ ///Mesmo eixo y
                    if ((nt1x >= pa1x && nt1x <= pa5x) || (nt4x >= pa1x && nt4x <= pa5x)){ ///Mesma posição
                        veriPos = true;
                    } else {
                        veriPos = false; ///Posição diferente
                    }
                } else {
                    veriPos = false;
                }
            }
        }
    }
    } while (veriPos == true);

    int ct1x, ct1y, ct3x, ct3y; ///Posição inicial do contratorpedeiro
    int ct2x, ct2y; ///DEBUG (verificar engine de colisão)
    int ctOrient; ///Orientação do contratorpedeiro
    do {
    ct1x = rand()%9 - 4; ///Randomização das posições
    ct1y = rand()%9 - 4;
    ctOrient = rand()%2; ///Orientação do contratorpedeiro
    if (ctOrient == 0){
        ct3y = ct1y - 2; ///Na vertical
        ct3x = ct1x;
        ct2x = ct1x; ///DEBUG
        ct2y = ct1y - 1;
        if (ct3y <= -5){     ///Verifica se está dentro do mapa
            veriPos = true;
        } else {
            if (paOrient == 0){ ///Porta-aviôes na vertical
                if (ct1x == pa1x){ ///Mesmo eixo x
                    if ((ct1y <= pa1y && ct1y >= pa5y) || (ct3y <= pa1y && ct3y >= pa5y)){
                        veriPos = true;
                    } else {
                        veriPos = false; ///Não estão nas mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos = false;
                }
            } else { ///Porta-aviões na horizontal
                if ((ct1x >= pa1x) && (ct1x <= pa5x)){ ///Mesmo eixo x
                    if (pa1y <= ct1y && pa1y >= ct3y){
                        veriPos = true; ///Mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos = false;
                }
            }
        }
    } else { ///Na horizontal
        ct3x = ct1x + 2;
        ct3y = ct1y;
        ct2y = ct1y; ///DEBUG
        ct2x = ct1x + 1;
        if (ct3x >= 5) {    ///Verifica se está dentro do mapa
            veriPos = true;
        } else {
            if (paOrient == 0){ ///Porta-aviões está na vertical
                if (pa1x >= ct1x && pa1x <= ct3x){ ///Mesmo eixo x
                    if((ct1y <= pa1y) && (ct1y >= pa5y)){ ///Mesma posição
                        veriPos = true;
                    } else {
                        veriPos = false; ///Posição é diferente
                    }
                } else {
                    veriPos = false; ///Eixo x diferente
                }
            } else { ///Porta-aviões está na horizontal
                if (ct1y == pa1y){ ///Mesmo eixo y
                    if ((ct1x >= pa1x && ct1x <= pa5x) || (ct3x >= pa1x && ct3x <= pa5x)){ ///Mesma posição
                        veriPos = true;
                    } else {
                        veriPos = false; ///Posição diferente
                    }
                } else {
                    veriPos = false;
                }
            }
        }
    }

        if (ctOrient == 0){
                if (ntOrient == 0){ ///Navio-tanque na vertical
                if (ct1x == nt1x){ ///Mesmo eixo x
                    if ((ct1y <= nt1y && ct1y >= nt4y) || (ct3y <= nt1y && ct3y >= nt4y)){
                        veriPos2 = true;
                    } else {
                        veriPos2 = false; ///Não estão nas mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos2 = false;
                }
            } else { ///Navio-tanque na horizontal
                if ((ct1x >= nt1x) && (ct1x <= nt4x)){ ///Mesmo eixo x
                    if (nt1y <= ct1y && nt1y >= ct3y){
                        veriPos2 = true; ///Mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos2 = false;
                }
            }
    } else { ///Na horizontal
            if (ntOrient == 0){ ///Navio-tanque está na vertical
                if (nt1x >= ct1x && nt1x <= ct3x){ ///Mesmo eixo x
                    if((ct1y <= nt1y) && (ct1y >= nt4y)){ ///Mesma posição
                        veriPos2 = true;
                    } else {
                        veriPos2 = false; ///Posição é diferente
                    }
                } else {
                    veriPos2 = false; ///Eixo x diferente
                }
            } else { ///Navio-tanque está na horizontal
                if (ct1y == nt1y){ ///Mesmo eixo y
                    if ((ct1x >= nt1x && ct1x <= nt4x) || (ct3x >= nt1x && ct3x <= nt4x)){ ///Mesma posição
                        veriPos2 = true;
                    } else {
                        veriPos2 = false; ///Posição diferente
                    }
                } else {
                    veriPos2 = false;
                }
            }
    }
    } while ((veriPos == true) || (veriPos2 == true));

    int sb1x, sb1y, sb2x, sb2y; ///Posição inicial do submarino
    int sbOrient; ///Orientação do submarino
    do {
    sb1x = rand()%9 - 4; ///Randomização das posições
    sb1y = rand()%9 - 4;
    sbOrient = rand()%2; ///Orientação do contratorpedeiro
    if (sbOrient == 0){
        sb2y = sb1y - 1; ///Na vertical
        sb2x = sb1x;
        if (sb2y <= -5){     ///Verifica se está dentro do mapa
            veriPos = true;
        } else {
            if (paOrient == 0){ ///Porta-aviôes na vertical
                if (sb1x == pa1x){ ///Mesmo eixo x
                    if ((sb1y <= pa1y && sb1y >= pa5y) || (sb2y <= pa1y && sb2y >= pa5y)){
                        veriPos = true;
                    } else {
                        veriPos = false; ///Não estão nas mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos = false;
                }
            } else { ///Porta-aviões na horizontal
                if ((sb1x >= pa1x) && (sb1x <= pa5x)){ ///Mesmo eixo x
                    if (pa1y <= sb1y && pa1y >= sb2y){
                        veriPos = true; ///Mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos = false;
                }
            }
        }
    } else { ///Na horizontal
        sb2x = sb1x + 1;
        sb2y = sb1y;
        if (sb2x >= 5) {    ///Verifica se está dentro do mapa
            veriPos = true;
        } else {
            if (paOrient == 0){ ///Porta-aviões está na vertical
                if (pa1x >= sb1x && pa1x <= sb2x){ ///Mesmo eixo x
                    if((sb1y <= pa1y) && (sb1y >= pa5y)){ ///Mesma posição
                        veriPos = true;
                    } else {
                        veriPos = false; ///Posição é diferente
                    }
                } else {
                    veriPos = false; ///Eixo x diferente
                }
            } else { ///Porta-aviões está na horizontal
                if (sb1y == pa1y){ ///Mesmo eixo y
                    if ((sb1x >= pa1x && sb1x <= pa5x) || (sb2x >= pa1x && sb2x <= pa5x)){ ///Mesma posição
                        veriPos = true;
                    } else {
                        veriPos = false; ///Posição diferente
                    }
                } else {
                    veriPos = false;
                }
            }
        }
    }

        if (sbOrient == 0){
                if (ntOrient == 0){ ///Navio-tanque na vertical
                if (sb1x == nt1x){ ///Mesmo eixo x
                    if ((sb1y <= nt1y && sb1y >= nt4y) || (sb2y <= nt1y && sb2y >= nt4y)){
                        veriPos2 = true;
                    } else {
                        veriPos2 = false; ///Não estão nas mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos2 = false;
                }
            } else { ///Navio-tanque na horizontal
                if ((sb1x >= nt1x) && (sb1x <= nt4x)){ ///Mesmo eixo x
                    if (nt1y <= sb1y && nt1y >= sb2y){
                        veriPos2 = true; ///Mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos2 = false;
                }
            }
    } else { ///Na horizontal
            if (ntOrient == 0){ ///Navio-tanque está na vertical
                if (nt1x >= sb1x && nt1x <= sb2x){ ///Mesmo eixo x
                    if((sb1y <= nt1y) && (sb1y >= nt4y)){ ///Mesma posição
                        veriPos2 = true;
                    } else {
                        veriPos2 = false; ///Posição é diferente
                    }
                } else {
                    veriPos2 = false; ///Eixo x diferente
                }
            } else { ///Navio-tanque está na horizontal
                if (sb1y == nt1y){ ///Mesmo eixo y
                    if ((sb1x >= nt1x && sb1x <= nt4x) || (sb2x >= nt1x && sb2x <= nt4x)){ ///Mesma posição
                        veriPos2 = true;
                    } else {
                        veriPos2 = false; ///Posição diferente
                    }
                } else {
                    veriPos2 = false;
                }
            }
    }

            if (sbOrient == 0){
                if (ctOrient == 0){ ///Contratorpedeiro na vertical
                if (sb1x == ct1x){ ///Mesmo eixo x
                    if ((sb1y <= ct1y && sb1y >= ct3y) || (sb2y <= ct1y && sb2y >= ct3y)){
                        veriPos3 = true;
                    } else {
                        veriPos3 = false; ///Não estão nas mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos3 = false;
                }
            } else { ///Contratorpedeiro na horizontal
                if ((sb1x >= ct1x) && (sb1x <= ct3x)){ ///Mesmo eixo x
                    if (ct1y <= sb1y && ct1y >= sb2y){
                        veriPos3 = true; ///Mesmas posições
                    }
                } else { ///Outro eixo x
                    veriPos3 = false;
                }
            }
    } else { ///Na horizontal
            if (ctOrient == 0){ ///Contratorpedeiro está na vertical
                if (ct1x >= sb1x && ct1x <= sb2x){ ///Mesmo eixo x
                    if((sb1y <= ct1y) && (sb1y >= ct3y)){ ///Mesma posição
                        veriPos3 = true;
                    } else {
                        veriPos3 = false; ///Posição é diferente
                    }
                } else {
                    veriPos3 = false; ///Eixo x diferente
                }
            } else { ///Contratorpedeiro está na horizontal
                if (sb1y == ct1y){ ///Mesmo eixo y
                    if ((sb1x >= ct1x && sb1x <= ct3x) || (sb2x >= ct1x && sb2x <= ct3x)){ ///Mesma posição
                        veriPos3 = true;
                    } else {
                        veriPos3 = false; ///Posição diferente
                    }
                } else {
                    veriPos3 = false;
                }
            }
    }
    } while ((veriPos == true) || (veriPos2 == true) || (veriPos3 == true));

    int usrX, usrY; ///x e y inseridos pelo usuário
    int torpedos = 0, paScore = 0, ntScore = 0, ctScore = 0, sbScore = 0; ///Acumuladores de torpedos e quantidade de acertos em cada navio
    bool save1 = false, save2 = false, save3 = false, save4 = false, save5 = false, save6 = false, save7 = false, save8 = false, save9 = false, save10 = false, save11 = false, save12 = false, save13 = false, save14 = false; ///Salvar locais já atirados
    bool rep = true; ///Variável para indicar entrada inválida e término do jogo
    cout << "Seja bem-vindo a Batalha-Naval em C++\nPara jogar digite primeiro o ponto x (valores de -4 a 4) e depois o ponto y (também valores de -4 a 4)\nBoa sorte!" << endl;
    do{
        cout << "Digite uma cordenada:";
        cin >> usrX >> usrY;
        if ((usrX == 17) && (usrY == 17)){ ///Modo de depuração
                cout << "=== DEBUG MODE ===" << endl;
                cout << "PA(" << pa1x << ", " << pa1y << ")" << endl;
                cout << "PA(" << pa2x << ", " << pa2y << ")" << endl;
                cout << "PA(" << pa3x << ", " << pa3y << ")" << endl;
                cout << "PA(" << pa4x << ", " << pa4y << ")" << endl;
                cout << "PA(" << pa5x << ", " << pa5y << ")" << endl;

                cout << "NT(" << nt1x << ", " << nt1y << ")" << endl;
                cout << "NT(" << nt2x << ", " << nt2y << ")" << endl;
                cout << "NT(" << nt3x << ", " << nt3y << ")" << endl;
                cout << "NT(" << nt4x << ", " << nt4y << ")" << endl;

                cout << "CT(" << ct1x << ", " << ct1y << ")" << endl;
                cout << "CT(" << ct2x << ", " << ct2y << ")" << endl;
                cout << "CT(" << ct3x << ", " << ct3y << ")" << endl;

                cout << "SB(" << sb1x << ", " << sb1y << ")" << endl;
                cout << "SB(" << sb2x << ", " << sb2y << ")" << endl;
        } else if (usrX >= 5 || usrX <= -5 || usrY >= 5 || usrY <= -5){ ///Validação da entrada
            cout << "Cordenadas inválidas, por favor digite um valor entre -4 e 4 para jogar" << endl;
            rep = true;
        } else {
            torpedos++; ///Acumula número de torpedos utilizados
            if (usrY == pa1y && usrX == pa1x){ ///Inicio da verificação de colisão ou acerto do Porta-Aviões
                if (save1 == true){
                    cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                    cout << "Alvo atingido." << endl;
                    paScore++;
                    save1 = true;
                }
            } else if (usrY == pa2y && usrX == pa2x){
                if (save2 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                paScore++;
                save2 = true;
                }
            } else if(usrY == pa3y && usrX == pa3x){
                if (save3 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                paScore++;
                save3 = true;
                }
            } else if(usrY == pa4y && usrX == pa4x){
                if (save4 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                paScore++;
                save4 = true;
                }
            } else if(usrY == pa5y && usrX == pa5x){
                if (save5 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                paScore++;
                save5 = true;
                }
            }  else if(usrY == nt1y && usrX == nt1x){ ///Inicio da verificação de colisão ou acerto do Navio-tanque
                if (save6 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                ntScore++;
                save6 = true;
                }
            }  else if(usrY == nt2y && usrX == nt2x){
                if (save7 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                ntScore++;
                save7 = true;
                }
            }  else if(usrY == nt3y && usrX == nt3x){
                if (save8 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                ntScore++;
                save8 = true;
                }
            }  else if(usrY == nt4y && usrX == nt4x){
                if (save9 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                ntScore++;
                save9 = true;
                }
            }  else if(usrY == ct1y && usrX == ct1x){ ///Inicio da verificação do Contratorpedeiro
                if (save10 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                ctScore++;
                save10 = true;
                }
            }  else if(usrY == ct2y && usrX == ct2x){
                if (save11 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                ctScore++;
                save11 = true;
                }
            }  else if(usrY == ct3y && usrX == ct3x){
                if (save12 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                ctScore++;
                save12 = true;
                }
            }  else if(usrY == sb1y && usrX == sb1x){ ///Inicio da verificação do Submarino
                if (save13 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                sbScore++;
                save13 = true;
                }
            }  else if(usrY == sb2y && usrX == sb2x){
                if (save14 == true){
                cout << "Local já disparado em uma rodada anterior. Torpedo desperdiçado." << endl;
                } else {
                cout << "Alvo atingido." << endl;
                sbScore++;
                save14 = true;
                }
            } else {
                cout << "Você errou o alvo. Torpedo desperdiçado." << endl;
            }
        }

        if (paScore == 5){ ///Verificação do navio afundado e parada da repetição
            rep = false;
            cout << "Parabéns, você afundou o Porta-Aviões!" << "\nVocê utilizou " << torpedos << " torpedos." << endl;
            cout << "Ele estava localizado em: " << endl;
            cout << "(" << pa1x << ", " << pa1y << ")" << endl;
            cout << "(" << pa2x << ", " << pa2y << ")" << endl;
            cout << "(" << pa3x << ", " << pa3y << ")" << endl;
            cout << "(" << pa4x << ", " << pa4y << ")" << endl;
            cout << "(" << pa5x << ", " << pa5y << ")";
        } else if (ntScore == 4){
            rep = false;
            cout << "Parabéns, você afundou o Navio-Tanque!" << "\nVocê utilizou " << torpedos << " torpedos." << endl;
            cout << "Ele estava localizado em: " << endl;
            cout << "(" << nt1x << ", " << nt1y << ")" << endl;
            cout << "(" << nt2x << ", " << nt2y << ")" << endl;
            cout << "(" << nt3x << ", " << nt3y << ")" << endl;
            cout << "(" << nt4x << ", " << nt4y << ")";
        } else if (ctScore == 3){
            rep = false;
            cout << "Parabéns, você afundou o Contratorpedeiro!" << "\nVocê utilizou " << torpedos << " torpedos." << endl;
            cout << "Ele estava localizado em: " << endl;
            cout << "(" << ct1x << ", " << ct1y << ")" << endl;
            cout << "(" << ct2x << ", " << ct2y << ")" << endl;
            cout << "(" << ct3x << ", " << ct3y << ")";
        } else if (sbScore == 2) {
            rep = false;
            cout << "Parabéns, você afundou o Submarino!" << "\nVocê utilizou " << torpedos << " torpedos." << endl;
            cout << "Ele estava localizado em: " << endl;
            cout << "(" << sb1x << ", " << sb1y << ")" << endl;
            cout << "(" << sb2x << ", " << sb2y << ")";
        }
    } while (rep);
    return 0;
}
