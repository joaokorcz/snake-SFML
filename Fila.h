#ifndef FILA_H
#define FILA_H

#include "Node.h"

using namespace std;

class Fila{
    public:
        Fila();
        ~Fila();

        bool filaVazia();
        bool filaCheia();

        NodePtr getPrimeiro();
        NodePtr getUltimo();
        
        void Insere(int _x, int _y);
        bool Retira();

        void RetiraTodos();
    private:
        NodePtr Primeiro;
        NodePtr Ultimo;
};

//Método construtor de objetos.
Fila::Fila(){
    this->Primeiro = NULL;
    this->Ultimo = NULL;
}

//Método destrutor de objetos.
Fila::~Fila(){
    delete this->Primeiro;
    delete this->Ultimo;
    this->Primeiro = NULL;
    this->Ultimo = NULL;
}

//Método que retorna o primeiro elemento da fila.
NodePtr Fila::getPrimeiro(){
    return this->Primeiro;
}

NodePtr Fila::getUltimo(){
    return this->Ultimo;
}

//Método que verifica se a fila está vazia.
bool Fila::filaVazia(){
    return (this->Primeiro == NULL);
}

//Método que insere um elemento ao final da fila.
void Fila::Insere(int _x, int _y){
    NodePtr Paux = new Node;
    Paux->setX(_x);
    Paux->setY(_y);
    Paux->setDir(NULL);
    if (this->filaVazia()){ //Caso da fila vazia.
        this->Primeiro = Paux;
        this->Primeiro->setEsq(NULL);
        this->Ultimo = this->Primeiro;
    } else {
        Paux->setEsq(this->Ultimo);
        this->Ultimo->setDir(Paux);
        this->Ultimo = Paux;
    }
}

//Método para retirar o primeiro elemento da fila.
bool Fila::Retira(){
    if(!this->filaVazia()){
        NodePtr NRemovido = this->Primeiro;
        this->Primeiro = this->getPrimeiro()->getDir();
        this->Primeiro->setEsq(NULL);
        delete NRemovido;
        NRemovido = NULL;
        return true;
    }
    return false;
}

//Método para retirar todos os elementos da fila.
void Fila::RetiraTodos(){
    bool retirando = true;
    while(retirando){
        retirando = this->Retira();
    }  
}

#endif