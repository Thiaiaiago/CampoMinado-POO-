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

#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H

#define tamanho_max 50 // tamanho maximo absoluto do mapa

class campo_minado
{
    public:
        /*
            no nosso jogo, nao existe um metodo para definir bombas ou dificuldades, j� que o tamanho
            do mapa e a quantidade de bombas sao definidas pelo usuario a partir da interface no inicio
            do c�digo.
        */
        campo_minado(int tamanho_horizontal, int tamanho_vertical, int total_bombas); // gera mapa definindo tamanho vertical e horizontal, e qtd de bomba
        //campo_minado(int tamanho, int total_bombas); // gera definindo tamanho quadrado e qtd de bomba
        //campo_minado(int qtd_bomba); // gera definindo qtd de bomba em um tamanho padrao (10x10?)
        //campo_minado(); // gera com um tamanho padrao e qtd de bomba predefinido (10x10 com 10 bombas?)

        void display(); // mostra o tabuleiro

        bool apertar(int x, int y); // aperta no quadradinho; retorna true se tem bomba ou false se nao tem
        // nesse metodo, � revelado o quadradinho e, caso a quantidade de bombas em volta dele seja igual a 0, ele
        // automaticamente revela os quadradinhos a sua volta

        void alteraBandeira(int x, int y); // coloca ou tira bandeira alterando a variavel temBandeira (apenas para visual)

        int getBombaVizinha(int x, int y);

        bool GAME_OVER(bool perdeu);

    private:
        int qtdBombas;
        int QtdNaoDescobertos;
        int tamanho_x, tamanho_y; // para facilitar o codigo ao verificar o estado das posicoes dos quadradinhos
};

#endif // CAMPO_MINADO_H
