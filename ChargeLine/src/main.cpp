#include <SFML\Graphics.hpp>
#include <math.h>
#include "../vc2017project/testSFML/testSFML/MaterialPoint.h"
#include <vector>
#include "../vc2017project/testSFML/testSFML/Ball.h"
#define N 10
#define X0 900
#define Y0 900
#define n 20
#define mul 1

int main()
{

    std::vector<Ball> particles;
    Ball p;
    Vector2 e;
    std::vector<sf::RectangleShape> chargeLines;

    sf::RenderWindow window(sf::VideoMode(900, 900), "My window");
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
        window.clear(sf::Color::Black);

        sf::Time time = clock.getElapsedTime();
        int j = 0;
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (j == 0)) {
            p.position = Vector2(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            p.velocity = Vector2(0, 0);
            p.mass = 1.0f;
            p.radius = 10;
            p.circle.setRadius(p.radius);
            p.circle.setOrigin(10, 10);
            p.circle.setFillColor(sf::Color(255, 0, 0));
            p.circle.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            particles.push_back(p);
            j++;
        }
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Right)) && (j == 0)) {
            p.position = Vector2(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            p.velocity = Vector2(0, 0);
            p.mass = -1.0f;
            p.radius = 10;
            p.circle.setRadius(p.radius);
            p.circle.setOrigin(10, 10);
            p.circle.setFillColor(sf::Color(0, 0, 255));
            p.circle.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            particles.push_back(p);
            j++;
        }
        
        if (particles.size() != 0) {
            for (int i = 0; i < X0 / n; i++) {
                for (int j = 0; j < Y0 / n; j++) {
                    e = (0, 0);
                    for (int k = 0; k < particles.size(); k++) {
                        e = e + (Vector2(i * n, j * n) - particles[k].position)/ ((Vector2(i * n, j * n) - particles[k].position).squareLen() * (Vector2(i * n, j * n) - particles[k].position).len()) * particles[k].mass;
                        
                    }
                    sf::RectangleShape line(sf::Vector2f(n, 1));
                    if (e.y < 0)
                    {
                        
                        line.rotate(-acos(e.norm() * Vector2(1, 0)) * 180 / M_PI);
                    }
                    else {
                        line.rotate(acos(e.norm() * Vector2(1, 0)) * 180 / M_PI);
                    }
                    line.setPosition(i * n, j * n);
                    window.draw(line);

                }
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
