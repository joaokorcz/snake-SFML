#include <SFML/Graphics.hpp>
#include <time.h>
#include "Fila.h"
using namespace sf;

int N=30,M=20;
int size=16;
int w = size*N;
int h = size*M;

int dir, num=4;

struct Fruit{
    int x,y;
} f;

void Tick(Fila* Snake){
    //FAZER UM METODO PRA ISSO
    NodePtr Primeiro = Snake->getPrimeiro();
    NodePtr Ultimo = Snake->getUltimo();

    if(Primeiro != NULL && Ultimo != NULL){
        while(Ultimo->getEsq() != NULL){
            Ultimo->setX(Ultimo->getEsq()->getX());
            Ultimo->setY(Ultimo->getEsq()->getY());
            Ultimo = Ultimo->getEsq();
        }
        
        if (dir==0) Primeiro->setY(Primeiro->getY()+1);
        if (dir==1) Primeiro->setX(Primeiro->getX()-1);       
        if (dir==2) Primeiro->setX(Primeiro->getX()+1);        
        if (dir==3) Primeiro->setY(Primeiro->getY()-1);

        if ((Primeiro->getX()==f.x) && (Primeiro->getY()==f.y)){
            Snake->Insere(N+1, M+1);
            int fx;
            int fy;
            bool comum;
            NodePtr Paux;
            do{
                fx = rand()%N;
                fy = rand()%M;
                comum = false;
                Paux = Primeiro;
                while(Paux != NULL){
                    if(Paux->getX()==fx && Paux->getY()==fy){
                        comum = true;
                    }
                    Paux = Paux->getDir();
                }
            } while(comum);
            f.x = fx;
            f.y = fy;
        }

        if(Primeiro->getX()>N-1){
            Primeiro->setX(0);
        } 
        if(Primeiro->getX()<0){
            Primeiro->setX(N);
        } 
        
        if(Primeiro->getY()>M-1){
            Primeiro->setY(0);
        } 
        if(Primeiro->getY()<0){
            Primeiro->setY(M);
        }

    }
    
 
    /*
    for (int i=1;i<num;i++){
        if (s[0].x==s[i].x && s[0].y==s[i].y){
            num=i;
        }             
    }
    */
 }

int main(){  
    srand(time(0));

    Fila Snake = Fila();
    Snake.Insere(10,10);
    Snake.Insere(10,11);
    
    RenderWindow window(VideoMode(w, h), "Snake Game!");

    Texture t1,t2, t3;
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/green.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);

    Clock clock;
    float timer=0, delay=0.1;

    f.x=13;
    f.y=13; 
    
    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time; 

        Event e;
        while (window.pollEvent(e)){
            if (e.type == Event::Closed){    
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left) && dir!=2) dir=1;   
        if (Keyboard::isKeyPressed(Keyboard::Right) && dir!=1) dir=2;    
        if (Keyboard::isKeyPressed(Keyboard::Up) && dir!=0) dir=3;
        if (Keyboard::isKeyPressed(Keyboard::Down) && dir!=3) dir=0;

        if (timer>delay){
            timer=0;
            Tick(&Snake);
        }

        ////// draw  ///////
        window.clear();

        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){ 
                sprite1.setPosition(i*size, j*size);
                window.draw(sprite1); 
            }
        }

        NodePtr Primeiro = Snake.getPrimeiro();
        while(Primeiro != NULL){
            sprite2.setPosition(Primeiro->getX()*size, Primeiro->getY()*size);
            window.draw(sprite2);
            Primeiro = Primeiro->getDir();
        }
   
        sprite3.setPosition(f.x*size, f.y*size);
        window.draw(sprite3);    

        window.display();
    }

    return 0;
}
