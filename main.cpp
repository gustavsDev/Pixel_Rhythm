#include <SFML/Graphics.hpp>

int main() {
 sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::Closed:
          window.close();
          break;
      }
    }
  }

  window.clear();
  window.display();
  return 0;
}
