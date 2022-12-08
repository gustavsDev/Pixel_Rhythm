#include <SFML/Graphics.hpp>
#include <string>

#include "src/GameObject.hpp"
#include "src/Note.hpp"
#include "src/Paddle.hpp"

int main(int argc, char *args[]) {
  sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

  Paddle paddle;

  int counter = 0;

  Note notes[10];

  for(int i = 0; i < sizeof(notes) / sizeof(Note); i++) {
    notes[i].setTime(i);
    notes[i].setNote(i);
  }
  
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
    for(int i = 0; i < sizeof(notes) / sizeof(Note); i++) {
      notes[i].update(counter);
    }

    window.clear(sf::Color::Black);

    background.render(window);
    paddle.render(window);

    for(int i = 0; i < sizeof(notes) / sizeof(Note); i++) {
      notes[i].render(window);
    }

    window.display();

    counter++;
  }

  return 0;
}
