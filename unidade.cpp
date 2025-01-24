#include "campo_minado.h"
#include "unidade.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define tam_max 50;

using namespace std;

unidade::unidade (){

    //"zera" a unidade
    isBomb=false;
    descoberto=false;
    bandeira=false;
}

int unidade::getBombas(){

    return isBomb;
}

void unidade::setBombas(){

    isBomb=true;
}

int unidade::getDescoberto(){

    return descoberto;
}

void unidade::setDescoberto(){
    
    descoberto=true;
}

int unidade::getBandeira(){

    return bandeira;
}

void unidade::setBandeira(){
    
    bandeira=true;
}