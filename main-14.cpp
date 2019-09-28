#include <iostream>
#include "game.h"
#include "MyVector.h"
#include "random.h"
#include "shunting.h"
#include <fstream>

using namespace std;

int main()
{
    //To enter a new function press esc button

    while(1>0){

        string s;
        cout<<"Function : ";

        cin>>s;

        Queue<Token*> MyQ= Input(s);

        Game game(MyQ);
        game.run();
    }
    return 0;
}
