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

#include <iostream>
#include <windows.h>
#include "campo_minado.h"
#include "campo_minado.cpp"

using namespace std;


int main()
{
    
    int tamx, tamy, qtdb; // tamanho x, tamanho y, quantidade bomba

    cout << "qtd de bomba: "; cin >> qtdb;
    cout << "(max 50) tamanho vertical: "; cin >> tamy; // entrada das variaveis para criacao do campo
    cout << "(max 50) tamanho horizontal: "; cin >> tamx;

    if(qtdb > tamx*tamy){ // testa se o mapa � possivel
        cout << "qtd de bombas maior q tamanho do mapa." << endl;
        return 0;
    }

    campo_minado campo(tamy, tamx, qtdb); // cria um campo

    bool perdeu = false; // define a variavel perdeu
    while(!perdeu){ // enquanto perdeu == false (n�o perdeu)
        int jogada[2]; // variaveis para entrada da jogada
        char aux;

        system("cls"); // limpa o terminal
        campo.display(); // mostra o tabuleiro


        if(campo.GAME_OVER(false)){ // verifica se o jogador venceu
            cout << "voce venceu!" << endl;
            return 0;
                system("pause");
        }

        do{ // entrada do tipo de jogada
            cout << endl
                 << "Digite 1 para revelar uma celula ou 2 para posicionar uma bandeira." << endl
                 << "Entrada: ";
            cin >> aux; cout << endl;

            if(aux != '1' && aux != '2')
                cout << "Certifique-se de que a entrada eh 1 ou 2" << endl;

        } while(aux != '1' && aux != '2');

        do{ // entrada da coordenada X
            cout << "Digite a coordenada X da jogada: ";
            cin >> jogada[0];

            if(jogada[0] < 1 || int(jogada[0]) > tamx)
                cout << "coordenada incoerente" << endl;

        } while(jogada[0] < 1 || int(jogada[0]) > tamx);

        do{ // entrada da coordenada Y
            cout << "Digite a coordenada Y da jogada: ";
            cin >> jogada[1];

            if(jogada[1] < 1 || int(jogada[1]) > tamy)
                cout << "coordenada incoerente" << endl;

        } while(jogada[1] < 1 || int(jogada[1]) > tamy);

        if(aux == '1') // aperta na coordenada caso a escolha de jogada seja apertar
            perdeu = campo.apertar(jogada[1]-1, jogada[0]-1);

        if(aux == '2') // altera bandeira na coordenada caso a escolha de jogada seja alterar bandeira
            campo.alteraBandeira(jogada[1]-1, jogada[0]-1);
    }

    campo.display(); // display do campo
    cout << endl << "ops. meio q vc perdeu!" << endl;
    Sleep(2000);
    //system("cls");
    return 1;
    exit(0);
}
