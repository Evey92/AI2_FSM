#pragma once
#include <SFML/Graphics.hpp>

class Window {
public:
  Window() {font.loadFromFile("Roboto-Bold.ttf");};
  ~Window() {};

  sf::RenderWindow m_appWindow;
  sf::RectangleShape m_Testshape;
  sf::Sprite sprite;
  sf::Font font;
  
  sf::Text text;
  sf::Event event;
  void Create();
  void Render();
  void setRectangeSize(sf::Vector2f size);
  void setRectanglePosition(sf::Vector2f position);
};