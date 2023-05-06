#include "Player.h"

Player::Player()
{
  _velocity = 8;

  _body.setSize({ 20, 50 });
  _body.setOrigin({ 10,50 });

  _head.setRadius(25);
  _head.setFillColor(sf::Color::Blue);
  _head.setOrigin({ 25, 50 });
  _head.setPosition({ 0, -50 });
}

void Player::update()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    move({ _velocity, 0 });
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    move({ -_velocity, 0 });
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    move({ 0, -_velocity });
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    move({ 0, _velocity });
  }

  if (getPosition().x < 0) {
    setPosition({ 850, getPosition().y });
  }

  if (getPosition().x > 850) {
    setPosition({ 0, getPosition().y });
  }

  if (getPosition().y < 0) {
    setPosition({ getPosition().x, 700 });
  }

  if (getPosition().y > 700) {
    setPosition({ getPosition().x, 0 });
  }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();


  target.draw(_body, states);
  target.draw(_head, states);
}

bool Player::click(sf::Vector2f cursor)
{
  return getTransform().transformRect(_body.getGlobalBounds()).contains(cursor)
    || getTransform().transformRect(_head.getGlobalBounds()).contains(cursor);
}

void Player::changeColor()
{
  sf::Color aux = _body.getFillColor();
  _body.setFillColor(_head.getFillColor());
  _head.setFillColor(aux);
}
