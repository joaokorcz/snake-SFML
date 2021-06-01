#ifndef NODE_H
#define NODE_H

using namespace std;

/*
  Aluno: João Otavio Martini Korczovei
  RA: 790913
  Disciplina: AED
  Implementacao dos nodes
*/

class Node{
    private:
        // Atributos:
        // x e y: informacao armazenada das posicoes
        // next: proximo node
        int x, y;
        Node* Dir;
        Node* Esq;

    public:
        Node();

        ~Node();

        void setX(int _x);
        void setY(int _y);

        void setDir(Node* _node);
        void setEsq(Node* _node);

        int getX();
        int getY();
        Node* getDir();
        Node* getEsq();

};

typedef Node* NodePtr;

// Construtor
Node::Node(){
}

// Destrutor
Node::~Node(){
    delete this->Dir;
    delete this->Esq;
    this->Dir = NULL;
    this->Esq = NULL;
}

// Setter de info
void Node::setX(int _x){
    this->x = _x;
}

void Node::setY(int _y){
    this->y = _y;
}

// Setter do proximo node
void Node::setDir(NodePtr _node){
    this->Dir = _node;
}

// Setter do proximo node
void Node::setEsq(NodePtr _node){
    this->Esq = _node;
}

// Getter de info
int Node::getX(){
    return this->x;
}

int Node::getY(){
    return this->y;
}

// Getter do proximo node
NodePtr Node::getDir(){
    return this->Dir;
}

NodePtr Node::getEsq(){
    return this->Esq;
}

#endif