#include <SFML/Graphics.hpp>

#include "src/GameObject.hpp"
#include "src/Paddle.hpp"
#include <string>

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

  Paddle paddle;

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::Closed:
          window.close();
          break;
      }
    }
    paddle.update(window);

    window.clear(sf::Color::Black);
    paddle.render(window);
    window.display();
  }

  return 0;
}
