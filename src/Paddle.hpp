#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Paddle {
  private:
    GameObject obj;
  public:
    Paddle() {
      obj.setTexture("res/img/Paddle_1.png");
    }

    void render(sf::RenderWindow &window) {
      obj.render(window);
    }

    void update(sf::RenderWindow &window) {
      obj.setPosition(
          sf::Vector2f(
            sf::Mouse::getPosition(window).x - (obj.getSprite().getScale().x * obj.getSprite().getTexture()->getSize().x) / 2,
            window.getSize().y - 32.f
          )
        );
    }
};
