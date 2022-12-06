#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "src/GameObject.hpp"
#include "src/Paddle.hpp"
#include <string>

int main(int argc, char *args[]) {
  sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

  Paddle paddle;
  
  GameObject background("res/img/BG_1.png");
    background.setPosition(sf::Vector2f(0.f, 0.f));

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

    window.clear(sf::Color::Green);
    background.render(window);
    paddle.render(window);
    window.display();
  }

  return 0;
}
