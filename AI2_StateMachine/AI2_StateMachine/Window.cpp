#include "pch.h"
#include "Window.h"

void Window::Create()
{
  m_appWindow.create(sf::VideoMode(1600, 1000), "Galahads Holy Grail");
  /*m_Testshape.setSize(sf::Vector2f(400.0f, 200.0f));
  m_Testshape.setPosition(sf::Vector2f(0.f, 0.0f));
  m_Testshape.setFillColor(sf::Color::Magenta);
  */
}

void Window::Render()
{

}

void Window::setRectangeSize(sf::Vector2f size)
{
  m_Testshape.setSize(size);
}

void Window::setRectanglePosition(sf::Vector2f position)
{
  m_Testshape.setPosition(position);
}
