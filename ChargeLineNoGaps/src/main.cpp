#include <SFML\Graphics.hpp>
#include <math.h>
#include "../vc2017project/testSFML/testSFML/MaterialPoint.h"
#include <vector>
#include "../vc2017project/testSFML/testSFML/Ball.h"
#define numb 100
#define X0 900
#define Y0 900
#define numbOfLines 20
#define length 10

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
            for (int k = 0; k < particles.size(); k++) {
                if (particles[k].mass >= 0) {
                    for (int i = 0; i < numbOfLines; i++) {
                        Vector2 rVectH = Vector2(particles[k].radius, 0).rotate(i * 360 / numbOfLines) + particles[k].position;
                        for (int h = 0; h < numb; h++) {
                            int ifPointIsInCharge = 0;
                            if (ifPointIsInCharge == 0) {
                                sf::RectangleShape line(sf::Vector2f(length, 1));
                                e = (0, 0);
                                for (int j = 0; j < particles.size(); j++) {
                                    e += (rVectH - particles[j].position) / ((rVectH - particles[j].position).squareLen() * (rVectH - particles[j].position).len()) * particles[j].mass;
                                    if ((rVectH - particles[j].position).len() < particles[j].radius) {
                                        ifPointIsInCharge = 1;
                                    }
                                }
                                line.setPosition(rVectH.x, rVectH.y);
                                if (e.y >= 0) {
                                    rVectH += Vector2(length, 0).rotate(acos(e.norm() * Vector2(1, 0)) * 180 / M_PI);
                                    line.rotate(acos(e.norm() * Vector2(1, 0)) * 180 / M_PI);
                                }
                                else {
                                    rVectH += Vector2(length, 0).rotate(-acos(e.norm() * Vector2(1, 0)) * 180 / M_PI);
                                    line.rotate(-acos(e.norm() * Vector2(1, 0)) * 180 / M_PI);
                                }
                                window.draw(line);
                            }
                        }
                    }
                }
                else {
                    for (int i = 0; i < numbOfLines; i++) {
                        Vector2 rVectH = Vector2(particles[k].radius, 0).rotate(i * 360 / numbOfLines) + particles[k].position;
                        for (int h = 0; h < numb; h++) {
                            int ifPointIsInCharge = 0;
                            if (ifPointIsInCharge == 0) {
                                sf::RectangleShape line(sf::Vector2f(length, 1));
                                e = (0, 0);
                                for (int j = 0; j < particles.size(); j++) {
                                    e += (rVectH - particles[j].position) / ((rVectH - particles[j].position).squareLen() * (rVectH - particles[j].position).len()) * particles[j].mass;
                                    if ((rVectH - particles[j].position).len() < particles[j].radius) {
                                        ifPointIsInCharge = 1;
                                    }
                                }
                                line.setPosition(rVectH.x, rVectH.y);
                                if (e.y >= 0) {
                                    rVectH += Vector2(length, 0).rotate(acos(e.norm() * Vector2(1, 0)) * 180 / M_PI + 180);
                                    line.rotate(acos(e.norm() * Vector2(1, 0)) * 180 / M_PI + 180);
                                }
                                else {
                                    rVectH += Vector2(length, 0).rotate(-acos(e.norm() * Vector2(1, 0)) * 180 / M_PI + 180);
                                    line.rotate(-acos(e.norm() * Vector2(1, 0)) * 180 / M_PI + 180);
                                }
                                window.draw(line);
                            }
                        }
                    }
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
