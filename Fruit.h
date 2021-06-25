#ifndef FRUIT_H
#define FRUIT_H

class Fruit{
    private:
        int x;
        int y;

    public:
        Fruit(int _x, int _y);
        ~Fruit();

        int getX();
        int getY();

        void setX(int _x);
        void setY(int _y);
};

Fruit::Fruit(int _x, int _y){
    this->x = _x;
    this->y = _y;
}

Fruit::~Fruit(){

}

int Fruit::getX(){
    return this->x;
}

int Fruit::getY(){
    return this->y;
}

void Fruit::setX(int _x){
    this->x = _x;
}

void Fruit::setY(int _y){
    this->y = _y;
}

#endif
