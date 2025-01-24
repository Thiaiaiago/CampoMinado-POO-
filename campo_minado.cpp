/*
Artur Ritzel e Thiago Godoy, 4311. Novembro de 2022.



AO UTILIZAR: compilar o codigo corretamente e executar sem a cpp adicionada no codeblocks
(ou compilar e abrir o executavel gerado)



prototipo:
campo minado funcional definindo tamanho do mapa e quantidade de bombas.

TODO:
- grava��o e leitura de maiores pontua��es (utilizando arquivos txt ou semelhantes)
- utilizar caracteres da tabela ascii para deixar a interface mais amig�vel ao usu�rio
*/

#include "campo_minado.h"
#include "unidade.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/// construtores


    //necessária essa criação de ponteiros para que depois se possam criar vetores (não é possivel criar matriz, mas com lógicas AND de dois vetores representando as dimensões, podemos "simular" uma)
    unidade *ux;
    unidade *uy;

campo_minado::campo_minado(int tamanho_vertical, int tamanho_horizontal, int total_bombas){

    //criação dos objetos unidade
    for (int i=0;i<tamanho_vertical;i++)
    {
        uy = new unidade[i];
        for (int j=0;j<tamanho_horizontal;j++)
        {
            ux = new unidade[j];
        }
    }
    
    QtdNaoDescobertos = tamanho_vertical * tamanho_horizontal; // total de celulas nao descobertas no campo
    qtdBombas=total_bombas;
    
    //declarações de variáveis utilizadas no sorteio das bombas
    int posxBomb;
    int posyBomb;
    int BombasSetadas=0;
    
    //sorteio das bombas
    while (total_bombas>BombasSetadas)
    {
        srand(time(0)); // seed pra rand

        posxBomb=rand()%total_bombas;
        posyBomb=rand()%total_bombas;

        for (int y=0;y<tamanho_vertical;y++)
        {
            for (int x=0;x<tamanho_horizontal;x++)
            {
                if (posxBomb==x&&posyBomb==y&&ux[x].getBombas()==false&&uy[y].getBombas()==false)
                {
                    ux[x].setBombas();
                    uy[y].setBombas();
                    BombasSetadas++;
                }
            }
        }
    }
}


void campo_minado::display(){
    cout << "Legenda:" << endl
         << "'B': bomba" << endl
         << "'P': bandeira" << endl
         << "'-': celula nao descoberta" << endl
         << "num: quantidade de bombas proximas" << endl;

    cout << "    ";

    for(int j = 0; j < tamanho_y; j++){ // legenda das colunas
        if(j+1 < 10) cout << "0";
            cout << j+1 << "  ";
    }

    cout << endl;

    for(int i = 0; i < tamanho_x; i++){
        if(i+1 < 10) cout << "0";
        cout << i+1 << " "; // legenda das linhas

        for(int j = 0; j < tamanho_y; j++){ // printando o valor de cada celula
            cout << "[";

            if(ux[i].getDescoberto()&&uy[j].getDescoberto()){ // caso seja descoberto
                if((ux[i].getBombas()&&uy[j].getBombas())>8) cout << "B"; // caso tenha bomba
                else if (getBombaVizinha(i, j) == 0) cout << char(32);
                    else cout << getBombaVizinha(i, j); // quantidade de bombas vizinhas 
            }
            else{
                if(ux[i].getBandeira()&&uy[j].getBandeira()) cout << "P"; // caso tenha bandeira
                else cout << "-"; // caso nao tenha sido descoberto nem tenha bandeira
            }
            cout << "] ";
        }
        cout << endl;
    }
}

bool campo_minado::apertar(int x, int y){ // aperta na celula xy
    //cout << "apertou " << x << " " << y << endl; // para debug

    if((ux[x].getDescoberto()&&uy[y].getDescoberto())==false&&(ux[x].getBandeira()&&uy[y].getBandeira())==false){ // caso nao tenha sido descoberto
        ux[x].setDescoberto(); // descobre
        uy[y].setDescoberto();
        QtdNaoDescobertos--;
    }

    getBombaVizinha(x, y); // descobre qtd de bombas proximas
    GAME_OVER(false);
}

void campo_minado::alteraBandeira(int x, int y){ // altera se tem ou nao bandeira na celula
    
    if((ux[x].getDescoberto()&&uy[y].getDescoberto())==false&&(ux[x].getBandeira()&&uy[y].getBandeira())==false){ // caso nao tenha sido descoberto
        ux[x].setBandeira(); // coloca bandeira
        uy[y].setBandeira();
    }
}

int campo_minado::getBombaVizinha(int x, int y){

int qtdBombasVizinhas=0;

    for (int i=(x-1);i<(x+1);i++)
    {
        for (int j=(y-1);j<(y+1);j++)
        {
            if((ux[i].getBombas()==true)&&(uy[j].getBombas()==true)) qtdBombasVizinhas++;
        }
    }

    if (qtdBombasVizinhas==0)
    {
        for (int i=(x-1);i<(x+1);i++)
        {
            for (int j=(y-1);j<(y+1);j++)
            {
                apertar(i, j);
            }
        }
    }

    if (qtdBombasVizinhas>8) GAME_OVER(true);

    return qtdBombasVizinhas;
}

bool campo_minado::GAME_OVER(bool perdeu){ // verifica se o jogador venceu

    cout << "bombas: " << qtdBombas << " // ";
    cout << "celulas restantes: " << QtdNaoDescobertos << endl;

    if(QtdNaoDescobertos == qtdBombas) return true;
    //  vence caso a quantidade de celulas nao descobertas seja igual a quantidade de bombas
    // (nao pode descobrir bombas)
    if(perdeu==true) return false;
    else return false;
}

