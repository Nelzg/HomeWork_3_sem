#include <SFML\Graphics.hpp>
#include <math.h>
#include "../vc2017project/testSFML/testSFML/MaterialPoint.h"
#include <vector>
#include "../vc2017project/testSFML/testSFML/Ball.h"

int main()
{

    std::vector<Ball> particles;
    Ball p;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Clock clock;

    sf::Texture texture;
    texture.loadFromFile("D:/PROJECTS_INFA/HomeWork_3_sem/Game Project/bin/icon_test.png");
    sf::Sprite circle1(texture);
    circle1.setScale(4, 4);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Red);

        sf::Time time = clock.getElapsedTime();
        /*
        sf::CircleShape circle2(50/(2*tan(360/40)));

        circle2.setPosition(200 + 5 * time.asSeconds(), 200);

        circle2.setFillColor(sf::Color(150, 50, 250));
        circle2.setOutlineThickness(3);
        circle2.setOutlineColor(sf::Color(300, 100, 100));
        window.draw(circle2);
        */


        //circle1.setPosition(100, 100);

        //circle1.setFillColor(sf::Color(150, 50, 250));
        

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            p.position = Vector2(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            p.velocity = Vector2(1, 1);
            p.mass = 1.0f;
            p.radius = 10;
            p.circle.setRadius(p.radius);
            p.circle.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            particles.push_back(p);
        }

        for (int i = 0; i < particles.size()/2 + 1; i++) {
            for (int j = 0; j < particles.size()/2 + 1; j++) {
               // if ((particles[i].radius + particles[j].radius) == (particles[i].position - particles[j].position).len()) {
                    
                //}
            }
        }

        for (int i = 0; i < particles.size(); i++) {
            particles[i].UpdatePosition(1);
            particles[i].circle.setPosition(particles[i].position.x, particles[i].position.y);
            window.draw(particles[i].circle);
        }
        
        
        window.display();
    }

  return 0;
}
