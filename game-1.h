#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include"shunting.h"

class Game{
public:

    Game(Queue<Token *> Input);
    void Draw();
    void run();
    void processEvents();
    void render();
    void DrawPlanes();
    void DrawPoints();
    void Graph();

    private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;
    sf::RectangleShape sideBar;
    //System system;
    int command;
    sf::Text myTextLabel;
    bool mouseIn;
   // Sidebar sidebar;

    sf::RectangleShape xplane;
    sf::RectangleShape yplane;

    sf::RectangleShape point;

    string User_Input;

    double SCALE_X=100;
    double SCALE_Y=100;

    bool done;
    Queue<Token*> Q;
};

#endif // GAME_H
