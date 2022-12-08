#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

#define NOTE_SIZE 32

class Note {
  private:
    sf::Texture texture;
    sf::Sprite sprite;
    int time = 0;
    int note = 0;
  public:
    Note() {
      texture.loadFromFile("res/img/Note.png");
      sprite.setTexture(texture);
    }

    void render(sf::RenderWindow &window) {
      window.draw(sprite); 
    }

    void update(int counter) {
      sprite.setPosition(sf::Vector2f(note * NOTE_SIZE, counter - time * NOTE_SIZE));
    }

    void setTime(int time) {
      this->time = time;
    }

    void setNote(int note) {
      this->note = note;
    }
};
