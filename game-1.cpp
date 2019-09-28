#include "game.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"
#include "shunting.h"
#include"interface.h"

Game::Game(Queue<Token*> Input)
{
    done=false;

    Q=shuntingchanges(Input);

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");

    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    mouseIn = true;

    // creating x & y axis
    yplane.setFillColor((sf::Color::Green));
    yplane.setSize(sf::Vector2f(SCREEN_WIDTH,1));
    yplane.setPosition(0,SCREEN_HEIGHT/2);

    xplane.setFillColor((sf::Color::Green));
    xplane.setSize(sf::Vector2f(1,SCREEN_HEIGHT));
    xplane.setPosition(SCREEN_WIDTH/2,0);

    //1 Point :
    point.setFillColor((sf::Color::Magenta));
    point.setSize(sf::Vector2f(2,2));
    point.setPosition(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);

}
void Game::DrawPlanes()//draw the x & y axis
{
    window.draw(xplane);//x-axis
    window.draw(yplane);//y-axis
}
void Game::Draw(){
    //Look at the data and based on the data, draw shapes on window object

    if (mouseIn){
        window.draw(mousePoint);
    }
    DrawPlanes();
    Graph();
}
void Game::render(){
    window.clear();

    Draw();
    window.display();
}

void Game::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event)){

        // check the type of the event...
        switch (event.type)
        {

        case sf::Event::KeyPressed:
            switch(event.key.code){

            case sf::Keyboard::Left:
                command = 4;
                break;

            case sf::Keyboard::Right:
                command = 6;
                break;

            case sf::Keyboard::Escape: //closes window, then user will be able to enter a new function if they'd like.
                window.close();
                break;

            }
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;

            break;

        case sf::Event::MouseButtonReleased:

            if (event.mouseButton.button == sf::Mouse::Left)//zooms in
            {

                SCALE_X=SCALE_X*2;
                SCALE_Y=SCALE_Y*2;

            }

            else{//zooms out

               // std::cout <<"("<< event.mouseButton.x << ", "
                 //         << event.mouseButton.y << ")"<<std::endl;

                SCALE_X=SCALE_X/2;
                SCALE_Y=SCALE_Y/2;


            }

            break;

        default:
            break;
        }
    }
}
void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        render(); //clear/draw/display
    }
}
void Game::Graph( ){// Generates the points

    Queue<Token*>MyQueue = Q;
    double x;
    double y;
    double MinX=-1*SCREEN_WIDTH/SCALE_X;
    double MaxX=SCREEN_WIDTH / SCALE_X;

    double increment= (MaxX-MinX)/SCREEN_WIDTH;

    x=MinX;

    for(int i = SCREEN_WIDTH/-2; i<SCREEN_WIDTH/2;i++){

        y=RPN(MyQueue,x);// calls evaluate

        point.setPosition(i+SCREEN_WIDTH/2,SCREEN_HEIGHT/2-y*SCALE_Y);// sets position with x and y cordinates that are converted to pixels
        window.draw(point);// draws the points at specific coordinates

        x+=increment;
    }
}
