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

    Vector2f v = {5,5};
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

        
            // Creating the game text and setting up text/font objects
            Text messageText;
            Font font;

            font.loadFromFile("fonts/KOMIKAP_.ttf");

            messageText.setFont(font);

            messageText.setString("Click the mouse 3 times anywhere to set 3 points\n" 
                                  "for a triangle, the 4th click starts the game!\n"
                                  "Press escape to exit the game, or close out the game.");

            messageText.setCharacterSize(15);
            messageText.setFillColor(Color::White);
            messageText.setPosition(20, 20);


            
            /*
            ****************************************
                        Update the scene
            ****************************************
            */

            rect.setPosition(clicked.x, clicked.y);
            rect.setFillColor(Color::White);
            /*
            ****************************************
                        Draw the scene
            ****************************************
            */
            

            //For loop to reposition the vertices by 1/2 
            /*for (int i = 0; i < vertices.size(); i++)
            {
                rect.setPosition(vertices.at(i).x / 2, vertices.at(i).y / 2);
                window.draw(rect);
            }*/



            //loop through vectors and draw each coordinate
            //Clear everything from the last run frame
            window.clear();
            //Draw our game scene here
            window.draw(messageText);
            window.draw(rect);
            window.display();

        
       
    }
    return 0;
}