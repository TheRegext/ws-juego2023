#pragma once
#include <SFML/Graphics.hpp>

class Player: public sf::Drawable, public sf::Transformable
{
public:
  Player();
  void update();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  bool click(sf::Vector2f cursor);
  void changeColor();
protected:

private:
  sf::RectangleShape _body;
  sf::CircleShape _head;
  float _velocity;
};

