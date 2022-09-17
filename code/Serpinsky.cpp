#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
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
 

    Vector2f v = {2,2};
    RectangleShape rect(v);

    vector<Vector2f> vertices; //Push back stuff into us! First 3 points
    vector<Vector2f> points;   //push_back 4th point into here


    int mid_point_x, mid_point_y;
    int factor = 2;
   
    

    
    
    
    while (window.isOpen())
    {
        
        int select_vert = rand() % 3;
        
        //Handles Player Input
        
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
            
            if (event.type == Event::MouseButtonReleased)
            {

                if (event.mouseButton.button == Mouse::Left)
                {
                    
                    if (vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    
                    else if (points.size() == 0)
                    {
                        points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                }
            }
            
        }

        // Creating the game text and setting up text/font objects
        Text messageText;
        Font font;

        //font.loadFromFile("fonts/KOMIKAP_.ttf");
        font.loadFromFile("fonts/OldSchoolAdventures-42j9.ttf");
        //font.loadFromFile("fonts/Minecraft.ttf");

        messageText.setFont(font);

        messageText.setString("Click the mouse 3 times anywhere to set 3 points "
            "for a triangle, the 4th click starts the game!\n"
            "Press escape to exit the game, or close out the game.");

        messageText.setCharacterSize(25);
        messageText.setFillColor(Color::White);
        messageText.setPosition(10, 10);



        /*
        ****************************************
                    Update the scene
        ****************************************
        */
        
        if (points.size() > 0)
        {
            
            mid_point_x = (points[points.size() - 1].x + vertices[select_vert].x) / factor;
            mid_point_y = (points[points.size() - 1].y + vertices[select_vert].y) / factor;
            
            points.push_back(Vector2f(mid_point_x, mid_point_y));

            rect.setPosition(mid_point_x, mid_point_y);
            
            sleep(milliseconds(10));
        }


        
        rect.setFillColor(Color::White);
        /*
        ****************************************
                    Draw the scene
        ****************************************
        */


        //Loop through vectors and draw each coordinate 
        
        for (int i = 0; i < vertices.size(); i++)
        {
            rect.setPosition(vertices.at(i).x, vertices.at(i).y);
            window.draw(rect);
        }

        for (int i = 0; i < points.size(); i++)
        {
            rect.setPosition(points.at(i).x, points.at(i).y);
            window.draw(rect);

        }


        //Draw our game scene here
        
        window.draw(messageText);

        window.display();

        
       
    }
    return 0;
}