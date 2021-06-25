#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class MainMenu {
    private:
        int selectedItem;
        Font font;
        Font font2;
        Text menu[2];
        Text info[2];

    public:
        MainMenu(int w, int h);
        ~MainMenu();

        void draw(RenderWindow &window);
        void moveUp();
        void moveDown();
        int select();
        void gameOver(int w, int h, int t);

};

MainMenu::MainMenu(int w, int h){
    if(!font.loadFromFile("snake.ttf") || !font2.loadFromFile("arial.ttf") ){
        // erro pq nao achou fonte
    }
    this->menu[0].setFont(font);
    this->menu[0].setFillColor(Color::Green);
    this->menu[0].setString("Jogar");
    this->menu[0].setPosition(Vector2f(w/2 -30, h/4));

    this->menu[1].setFont(font);
    this->menu[1].setFillColor(Color::White);
    this->menu[1].setString("Sair");
    this->menu[1].setPosition(Vector2f(w/2 -30, h/4 * 2));

    this->info[0].setFont(font2);
    this->info[0].setFillColor(Color::White);
    this->info[0].setString("Feito por:\nAntonio Maldonado\nCaue Trevisan\nJoao Otavio Martini Korczovei\n");
    this->info[0].setPosition(Vector2f(w-420, h-150));

    this->info[1].setFont(font);
    this->info[1].setFillColor(Color::White);
    this->info[1].setString("Snake Game");
    this->info[1].setCharacterSize(50);
    this->info[1].setPosition(Vector2f(w/2 -175, 10));

    this->selectedItem = 0;
}

MainMenu::~MainMenu(){
}

void MainMenu::draw(RenderWindow &window){
    window.draw(menu[0]);
    window.draw(menu[1]);
    window.draw(info[0]);
    window.draw(info[1]);
}

void MainMenu::moveUp(){
    if(this->selectedItem == 1){
        this->menu[0].setFillColor(Color::Green);
        this->menu[1].setFillColor(Color::White);
        this->selectedItem = 0;
    }
}

void MainMenu::moveDown(){
    if(this->selectedItem == 0){
        this->menu[0].setFillColor(Color::White);
        this->menu[1].setFillColor(Color::Green);
        this->selectedItem = 1;
    }
}

int MainMenu::select(){
    return this->selectedItem;
}

void MainMenu::gameOver(int w, int h, int t){
    string str = to_string(t);
    this->info[1].setString("Ooops, voce morreu\nSeu tamanho era: "+str);
    this->info[1].setPosition(Vector2f(w/2 -285, 10));
    this->info[1].setCharacterSize(45);

    this->menu[0].setString("Jogar novamente");
    this->menu[0].setPosition(Vector2f(w/2 -160, h/4));
}

#endif
