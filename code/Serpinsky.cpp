#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

int main()
{
    /*
    git add . 
    git comit -m "nameOfProject"
    git push (Make sure in folder)
    */

    //Creates a video mode object
    VideoMode vm(1920, 1080);

    //Creates an open window
    RenderWindow window(vm, "Chaos Game", Style::Default);

    Vector2f v = {20,10};
    RectangleShape rect(v);

    vector<Vector2f> vertices; //Push back stuff into us! First 3 points
    vector<Vector2f> points;   //push_back 4th point into here
    Vector2f clicked;

    while(window.isOpen())
    {
        //Handles Player Input

        Event event;
        while(window.pollEvent(event))
        {

            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }

            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    cout << "The left button was pressed" << endl;
                    cout << "Mouse x: " << event.mouseButton.x << endl;
                    cout << "Mouse y: " << event.mouseButton.y << endl;

                    clicked.x = event.mouseButton.x;
                    clicked.y = event.mouseButton.y;
                }
            }

        }
            
            /*
            ****************************************
                        Update the scene
            ****************************************
            */

            rect.setPosition(clicked.x, clicked.y);

            /*
            ****************************************
                        Draw the scene
            ****************************************
            */
            
            //loop through vectors and draw each coordinate
            //Clear everything from the last run frame
            window.clear();
            //Draw our game scene here
            window.draw(rect);
            window.display();

        
       
    }
    return 0;
}