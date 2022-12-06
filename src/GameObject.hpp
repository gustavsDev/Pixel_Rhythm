#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class GameObject {
  private:
    sf::Texture texture;
    sf::Sprite sprite;
  public:
    GameObject() {
      texture.create(1, 1);
    }

    GameObject(std::string file_dir) {
      setTexture(file_dir);
    }

    void setTexture(std::string file_dir) {
      if (!texture.loadFromFile(file_dir)) {
        std::cout << "Could not load texture at " << file_dir << std::endl;
      }
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

    void setPosition(sf::Vector2f position) {
      sprite.setPosition(position);
    }

    sf::Vector2f getPosition() {
      return sprite.getPosition();
    }
};
