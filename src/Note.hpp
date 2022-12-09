#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

#define NOTE_SIZE 32

class Note {
  private:
    sf::Texture texture;
    sf::Sprite sprite;
    float time = 0;
    float note = 0;
  public:
    int state = 0;
    Note() {
        texture.loadFromFile("res/img/Note.png");
        sprite.setTexture(texture);
    }

    void render(sf::RenderWindow &window) {
        if(state != 0) return;
        window.draw(sprite); 
    }

    void update(sf::RenderWindow &window, int counter) {
        if(state != 0) return;    
        sprite.setPosition(sf::Vector2f(note * NOTE_SIZE, counter - time + window.getSize().y - 32.f));
    }

    void setTime(int time) {
        this->time = time;
    }

    int getTime() {
        return time;
    }

    void setNote(int note) {
        this->note = note;
    }
};
