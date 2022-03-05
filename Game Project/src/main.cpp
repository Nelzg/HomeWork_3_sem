#include <SFML\Graphics.hpp>
#include <math.h>
#include "Vector2.h"
#include <vector>
#include "../vc2017project/testSFML/testSFML/Ball.h"
#include "../vc2017project/testSFML/testSFML/LaserBeam.h"

int main()
{
  std::vector<Ball> particles;
  std::vector<LaserBeam> lasers;
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
    
    int prevX = circle1.getPosition().x;
    int prevY = circle1.getPosition().y;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        circle1.move(-1 * time.asSeconds()/20, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        circle1.move(1 * time.asSeconds()/20, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        circle1.move(0, -1 * time.asSeconds()/20);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        circle1.move(0, 1 * time.asSeconds()/20);
    }
    if ((circle1.getPosition().x > 500)||(circle1.getPosition().x < 0)|| (circle1.getPosition().y > 500)|| (circle1.getPosition().y < 0)) {
        circle1.setPosition(prevX, prevY);
    }
    window.draw(circle1);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        p.position = Vector2(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        p.velocity = Vector2(p.position.x - circle1.getPosition().x, p.position.y - circle1.getPosition().y).norm();
        p.position = Vector2(circle1.getPosition().x, circle1.getPosition().y);
        p.mass = 1.0f;
        p.radius = 10;
        p.circle.setRadius(p.radius);
        p.circle.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        particles.push_back(p);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        LaserBeam l;
        l.velocity = Vector2(sf::Mouse::getPosition(window).x - circle1.getPosition().x, sf::Mouse::getPosition(window).y - circle1.getPosition().y).norm();
        l.position = Vector2(circle1.getPosition().x, circle1.getPosition().y);
        l.mass = 1.0f;
        l.rectangle.setSize(sf::Vector2f(140, 2));
        if ((sf::Mouse::getPosition(window).y - l.position.y) >= 0) {
            l.rectangle.rotate(acos((Vector2(1, 0) * l.velocity) / l.velocity.len()) * 180 / M_PI);
        }
        else {
            l.rectangle.rotate(360-acos((Vector2(1, 0) * l.velocity) / l.velocity.len()) * 180 / M_PI);
        }
        
        l.rectangle.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        lasers.push_back(l);
    }

    for (int i = 0; i < lasers.size(); i++) {
        lasers[i].UpdatePosition(1);
        lasers[i].rectangle.setPosition(lasers[i].position.x, lasers[i].position.y);
        window.draw(lasers[i].rectangle);
        if ((500 < lasers[i].position.x) || (lasers[i].position.x < 0)||(lasers[i].position.y < 0)||(lasers[i].position.y > 500)) {
            lasers.erase(lasers.begin() + i);
        }
    }
    
    for (int i = 0; i < particles.size(); i++) {
        particles[i].UpdatePosition(1);
        particles[i].circle.setPosition(particles[i].position.x, particles[i].position.y);
        window.draw(particles[i].circle);
        if ((500 < particles[i].position.x)||(particles[i].position.x < 0)||(particles[i].position.y < 0)||(particles[i].position.y > 500)) {
            particles.erase(particles.begin() + i);
        }
    }

    window.display();
  }


  return 0;
}
