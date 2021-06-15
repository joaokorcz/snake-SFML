#ifndef SNAKE_H
#define SNAKE_H

class Snake : public Fila{
    private:
        int tamanho;

    public:
        Snake();
        ~Snake();

        void atualizaCorpo();
        void mudarDirecao(int dir, int n, int m);
        bool encontrouFruta(Fruit* f);
        void crescer(int n, int m);
        bool estaViva();
        void gameOver();

};

Snake::Snake() : Fila(){
    this->tamanho = 0;
}

Snake::~Snake(){
}

void Snake::atualizaCorpo(){
    NodePtr Ultimo = this->getUltimo();
    
    while(Ultimo->getEsq() != NULL){
        Ultimo->setX(Ultimo->getEsq()->getX());
        Ultimo->setY(Ultimo->getEsq()->getY());
        Ultimo = Ultimo->getEsq();
    }
}

void Snake::mudarDirecao(int dir, int n, int m){
    switch (dir){
        case 0:
            this->getPrimeiro()->setY(this->getPrimeiro()->getY()+1);
            break;
        case 1:
            this->getPrimeiro()->setX(this->getPrimeiro()->getX()-1);
            break;
        case 2:
            this->getPrimeiro()->setX(this->getPrimeiro()->getX()+1);
            break;
        case 3:
            this->getPrimeiro()->setY(this->getPrimeiro()->getY()-1);
            break;
    }

    if(this->getPrimeiro()->getX()>n-1){
        this->getPrimeiro()->setX(0);
    } 
    if(this->getPrimeiro()->getX()<0){
        this->getPrimeiro()->setX(n);
    } 
        
    if(this->getPrimeiro()->getY()>m-1){
        this->getPrimeiro()->setY(0);
    } 
    if(this->getPrimeiro()->getY()<0){
        this->getPrimeiro()->setY(m);
    }
}

bool Snake::encontrouFruta(Fruit *f){
    return (this->getPrimeiro()->getX()==f->getX()) && (this->getPrimeiro()->getY()==f->getY());
}

void Snake::crescer(int n, int m){
    tamanho++;
    this->Insere(n, m);
}

bool Snake::estaViva(){
    return (this->getPrimeiro() != NULL && this->getUltimo() != NULL);
}

void Snake::gameOver(){
    NodePtr Cabeca = this->getPrimeiro();
    NodePtr Corpo = this->getPrimeiro()->getDir();
    bool morreu = false;
    
    while(Corpo->getDir() != NULL){
        if(Cabeca->getX()==Corpo->getX() && Cabeca->getY()==Corpo->getY()){
            morreu = true;
        }
        Corpo = Corpo->getDir();
    }
    if(morreu){
        this->Reset();
    }
    
}

#endif