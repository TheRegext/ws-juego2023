#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
  /// Inicializacion de modo de ventana
  /// crea la ventana
  sf::RenderWindow window(sf::VideoMode(800, 600), "Mi Juegazo!", sf::Style::Default );

  window.setFramerateLimit(60);
  Player player;

  bool isPress = false;


  // Game Loop
  while (window.isOpen())
  {
    // COLA DE MENSAJES
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

    }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      if (!isPress)
      {
        isPress = true;

        sf::Vector2i cursor = sf::Mouse::getPosition(window);
        if (player.click({ (float)cursor.x, (float)cursor.y })) {
          player.changeColor();
        }
      }
    }
    else {
      isPress = false;
    }

    // borra la pantalla
     window.clear();

     player.update();

   
     
    //dibuja 
    window.draw(player);


    // presentamos
    // muestra
    window.display(); // flip
  }

  return 0;
}