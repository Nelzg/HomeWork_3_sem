#include <SFML\Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

  while (window.isOpen())
  {
    window.clear(sf::Color::Red);
    window.display();
  }

  return 0;
}
