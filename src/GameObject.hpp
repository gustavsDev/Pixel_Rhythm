#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class GameObject {
  private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
  public:
    GameObject() {
      texture.create(1, 1);
    }

    GameObject(std::string file_dir) {
      setTexture(file_dir);
    }

    void setTexture(std::string file_dir) {
      texture.loadFromFile(file_dir);
      texture.setRepeated(true);
      sprite.setTexture(texture);
      sprite.setScale(
        texture.getSize().x / sprite.getLocalBounds().width, 
        texture.getSize().y / sprite.getLocalBounds().height);
    }

    sf::Sprite getSprite() {
      return sprite;
    }

    void render(sf::RenderWindow &window) {
      window.draw(sprite);
    }

    void update() {
      sprite.move(velocity);
    }

    void setPosition(sf::Vector2f position) {
      sprite.setPosition(position);
    }

    void setVelocity(sf::Vector2f velocity) {
      this->velocity = velocity;
    }

    sf::Vector2f getPosition() {
      return sprite.getPosition();
    }

    sf::Vector2f getVelocity() {
      return velocity;
    }
};
