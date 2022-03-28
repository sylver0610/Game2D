#include "devGame.h"


int main()
{
    devGame game;
   /* sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/

    while (game.isRunning())
    {
        game.update();
        
        game.render();
    }
            

        return 0;
}
