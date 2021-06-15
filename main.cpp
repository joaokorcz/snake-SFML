#include <SFML/Graphics.hpp>
#include <time.h>
#include "Fila.h"
#include "Fruit.h"
#include "Snake.h"
using namespace sf;

int N=60,M=40;
int size=16;
int w = size*N;
int h = size*M;

void gerarComida(Snake* cobra, Fruit* fruta){
    int fx;
    int fy;
    bool comum;
    NodePtr Paux;
    do{
        fx = rand()%N;
        fy = rand()%M;
        comum = false;
        Paux = cobra->getPrimeiro();
        while(Paux != NULL){
            if(Paux->getX()==fx && Paux->getY()==fy){
                comum = true;
            }
            Paux = Paux->getDir();
        }
    } while(comum);
    fruta->setX(fx);
    fruta->setY(fy);
}

void Tick(Snake* cobra, Fruit *fruta, int dir){

    if(cobra->estaViva()){
        cobra->atualizaCorpo();        
        cobra->mudarDirecao(dir, N, M);
        if (cobra->encontrouFruta(fruta)){
            cobra->crescer(N+1, M+1);
            gerarComida(cobra, fruta);
        }
        cobra->gameOver();
    } 
    
 }

int main(){  
    srand(time(0));
    int dir = 1;

    Snake cobra = Snake();
    cobra.crescer(10,10);
    cobra.crescer(10,11);
    
    RenderWindow window(VideoMode(w, h), "Jogo Snake AED!");

    Texture t1,t2, t3, t4;
    t1.loadFromFile("images/fundo.png");
    t2.loadFromFile("images/cobra.png");
    t3.loadFromFile("images/fruta.png");
    //t4.loadFromFile("images/green.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);
    //Sprite sprite4(t4);

    Clock clock;
    float timer=0, delay=0.1;

    Fruit fruta = Fruit(13, 13);
    
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
            Tick(&cobra, &fruta, dir);
        }

        window.clear();

        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){ 
                sprite1.setPosition(i*size, j*size);
                window.draw(sprite1); 
            }
        }

        NodePtr Primeiro = cobra.getPrimeiro();
        /*
        P/ ter a cabeca diferente
        sprite4.setPosition(Primeiro->getX()*size, Primeiro->getY()*size);
        window.draw(sprite4);
        Primeiro = Primeiro->getDir();
        */
        while(Primeiro != NULL){
            sprite2.setPosition(Primeiro->getX()*size, Primeiro->getY()*size);
            window.draw(sprite2);
            Primeiro = Primeiro->getDir();
        }
   
        sprite3.setPosition(fruta.getX()*size, fruta.getY()*size);
        window.draw(sprite3);    

        window.display();
    }

    return 0;
}
