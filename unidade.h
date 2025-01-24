#ifndef UNIDADE_H
#define UNIDADE_H

#define tam_max 50;

class unidade
{
    public:

    unidade (); //construtor da unidade objeto
    int getBombas(); //"passa" para o externo o valor da variavel bomba, que é privada
    void setBombas(); //"setta" para o externo o valor da variavel bomba, que é privada
    int getDescoberto(); //"passa" para o externo o valor da variavel unidades descobertas, que é privada
    void setDescoberto(); //"setta" para o externo o valor da variavel unidades descobertas, que é privada
    int getBandeira(); //"passa" para o externo o valor da variavel bandeiras, que é privada
    void setBandeira(); //"setta" para o externo o valor da variavel bandeiras, que é privada

    private:
    
    bool isBomb; //variavel que define se a unidade é uma bomba ou não
    bool descoberto; //variavel que define se a unidade foi descoberta ou não
    bool bandeira; //variavel que define se a unidade tem bandeira ou não

};

#endif // UNIDADE_H