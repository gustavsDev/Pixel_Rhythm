#include <SFML/Graphics.hpp>
#include <string>

#include "src/GameObject.hpp"
#include "src/Note.hpp"
#include "src/Paddle.hpp"

int main(int argc, char *args[]) {
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    Paddle paddle;

    float counter = 0;
    float health = 100;

    Note notes[50];

    for(int i = 0; i < sizeof(notes) / sizeof(Note); i++) {
        notes[i].setTime(i * 64 + 100);
        notes[i].setNote((std::rand() * 30 + 64) % 20);
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
            case sf::Event::MouseButtonPressed:
                bool hit = false;
                for(int i = 0; i < sizeof(notes) / sizeof(Note); i++) {
                    int time = notes[i].getTime();
                    if(time - counter > 32 || time - counter < -10) continue;
                    hit = true;
                    notes[i].state = 1;
                }
                if(!hit) health--;
                break;
        }
    }
    paddle.update(window);
    for(int i = 0; i < sizeof(notes) / sizeof(Note); i++) {
        notes[i].update(window, counter);
        if(notes[i].getTime() - counter > -10) continue;
        if(notes[i].state == -1) continue;
        notes[i].state = -1;
        health--;
    }

    window.clear(sf::Color::Black);

    background.render(window);
    paddle.render(window);

    for(int i = 0; i < sizeof(notes) / sizeof(Note); i++) {
      notes[i].render(window);
    }

    sf::RectangleShape healthBar(sf::Vector2f((window.getSize().x / 100.f) * health, 10.f));
        healthBar.setFillColor(sf::Color::Red);
    window.draw(healthBar);

    window.display();

    counter += 0.6f;
  }

  return 0;
}
