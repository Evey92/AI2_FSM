#include "pch.h"
#include "AppState.h"
#include "App.h"
#include <iostream>

void LogoState::OnEnter()
{
 
  sf::Texture logo;
  logo.loadFromFile("DarkDeep.png");
  std::cout << "Estoy en el logo" << std::endl;

  m_pApp->m_windowManager.sprite.setPosition(sf::Vector2f(400, 200));
  m_pApp->m_windowManager.setRectangeSize(sf::Vector2f(800, 600));
  m_pApp->m_windowManager.setRectanglePosition(sf::Vector2f(300, 300));
  m_pApp->m_windowManager.m_Testshape.setFillColor(sf::Color::Black);
  m_pApp->m_windowManager.sprite.setTexture(logo, true);
   
}

void LogoState::OnUpdate()
{

  std::cout << "Estoy en el update de logo" << std::endl;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    m_pApp->SetState(new MenuState());
}

void LogoState::OnExit()
{
  std::cout << "Estoy saliendo del logo" << std::endl;
  m_pApp->m_stateStack.pop();
}

void MenuState::OnEnter()
{
  m_pApp->m_windowManager.setRectangeSize(sf::Vector2f(1200, 800));
  m_pApp->m_windowManager.m_Testshape.setPosition(sf::Vector2f(200, 50));
  m_pApp->m_windowManager.text.setFont(m_pApp->m_windowManager.font);
  m_pApp->m_windowManager.m_Testshape.setFillColor(sf::Color::White);
  m_pApp->m_windowManager.text.setString("Welcome to Galahad's Holy Grail!\n\n\n\n\n\t\t\t\t\t\tMain Menu\n\n\nPresiona Enter para jugar. \nPresiona O para opciones.");
  m_pApp->m_windowManager.text.setPosition(sf::Vector2f(500, 200));
  m_pApp->m_windowManager.text.setCharacterSize(30);
  m_pApp->m_windowManager.text.setFillColor(sf::Color::Black);
  m_pApp->m_windowManager.sprite.setColor(sf::Color::Transparent);
  std::cout << "Estoy en el Main Menu" << std::endl;
  
}

void MenuState::OnUpdate()
{
  std::cout << "Estoy en el update del Main Menu" << std::endl;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    m_pApp->SetState(new OptionsState());
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    m_pApp->SetState(new PlayState());
}

void MenuState::OnExit()
{
  m_pApp->m_stateStack.pop();
}

void PlayState::OnEnter()
{
  std::cout << "Estoy en el juego" << std::endl;
  m_pApp->m_windowManager.text.setString("Estamos jugando!. \nPresiona Esc para pausar el juego.\nPresiona H para abrir el menu de ayuda\nPresionar G para game over (Provisional)");
  m_pApp->m_windowManager.text.setPosition(sf::Vector2f(600, 500));
  m_pApp->m_windowManager.setRectangeSize(sf::Vector2f(1200, 800));
  m_pApp->m_windowManager.m_Testshape.setPosition(sf::Vector2f(200, 50));

}

void PlayState::OnUpdate()
{

  std::cout << "Estamos jugando!" << std::endl;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
  {
    m_pApp->SetState(new PauseState());
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
  {
    m_pApp->SetState(new GameOverState());
    
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
  {
    m_pApp->SetState(new HelpState());
  }
}

void PlayState::OnExit()
{
  m_pApp->m_stateStack.pop();
}

void PauseState::OnEnter()
{
  std::cout << "Estamos en pausa!" << std::endl;
  m_pApp->m_windowManager.text.setString("Pausa.\n\nPresiona Enter para Regresar al juego\nPresiona O para Opciones.");
  m_pApp->m_windowManager.text.setPosition(sf::Vector2f(500, 600));
  m_pApp->m_windowManager.setRectangeSize(sf::Vector2f(1300, 950));
  m_pApp->m_windowManager.m_Testshape.setPosition(sf::Vector2f(50, 50));
  m_pApp->m_isPaused = true;
}

void PauseState::OnUpdate()
{
  std::cout << "Estamos en el update pausa!" << std::endl;
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
  {
    m_pApp->SetState(new PlayState()); // Aquí, sé que se supone que debería volver al juego anterior guardado en el stack en vez de crear uno nuevo. Pero la verdas no sé que hice que no se guarda en el Stack.
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    m_pApp->SetState(new OptionsState());
}

void PauseState::OnExit()
{
  std::cout << "Saliendo de pausa" << std::endl;
  m_pApp->m_stateStack.pop();
  //m_pApp->m_isPaused = false;
}

void GameOverState::OnEnter()
{
  std::cout << "Estoy en el Game Over" << std::endl;
  m_pApp->m_windowManager.text.setString("Se acabó el jueguito mi estimado.\n\nPresiona Espacio para regresar al menú principal.");
}

void GameOverState::OnUpdate()
{
  
  std::cout << "Estoy en el update de Game Over" << std::endl;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    m_pApp->SetState(new MenuState());
  }
}

void GameOverState::OnExit()
{
  m_pApp->m_stateStack.pop();

}

void HelpState::OnEnter()
{
  std::cout << "Entrando a HELP" << std::endl;
  m_pApp->m_windowManager.text.setFont(m_pApp->m_windowManager.font);
  m_pApp->m_windowManager.m_Testshape.setFillColor(sf::Color::White);
  m_pApp->m_windowManager.text.setFillColor(sf::Color::Red);
  m_pApp->m_windowManager.text.setString("THERE'S NO HELP HERE BOI. \n\n\nPresiona Enter para regresar a Juego.");
  m_pApp->m_windowManager.text.setPosition(sf::Vector2f(500, 200));
  m_pApp->m_windowManager.text.setCharacterSize(40);
  m_pApp->m_windowManager.text.setFillColor(sf::Color::Black);
  
}

void HelpState::OnUpdate()
{
  std::cout << "Estoy en HELP" << std::endl;
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
  {
    m_pApp->SetState(new PlayState()); // Aquí, sé que se supone que debería volver al juego anterior guardado en el stack en vez de crear uno nuevo. Pero la verdas no sé que hice que no se guarda en el Stack.
  }
}

void HelpState::OnExit()
{
  m_pApp->m_stateStack.pop();
  //m_pApp->SetState(new MenuState());
}

void OptionsState::OnEnter()
{
  std::cout << "Estoy en Opciones" << std::endl;
  m_pApp->m_windowManager.text.setString("Opciones.\n\n\nPresiona el numero del menu al que quieras ingresar\n1.-Gameplay\n2.-Graphics\n3.-Sound\nEsc para salir del menu.");
  m_pApp->m_windowManager.text.setPosition(sf::Vector2f(300, 300));
  
}

void OptionsState::OnUpdate()
{
  std::cout << "Estoy en opciones" << std::endl;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
  {
    m_pApp->SetState(new GameplayState());
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
  {
    m_pApp->SetState(new GraphicsState());
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
  {
    m_pApp->SetState(new SoundState());
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
  {
    if (m_pApp->m_isPaused)
      m_pApp->SetState(new PauseState());
    else
      m_pApp->SetState(new MenuState());
  }

}

void OptionsState::OnExit()
{
  m_pApp->m_stateStack.pop();
  m_pApp->m_isPaused = false;
  //m_pApp->SetState(new MenuState());
}

void GameplayState::OnEnter()
{
  std::cout << "Estoy en gameplay" << std::endl;
  m_pApp->m_windowManager.text.setString("Gameplay Options.\n\n\Por ahora no hay nada mas que hacer aquí D:\nEspacio para regresar a opciones.");
}

void GameplayState::OnUpdate()
{
  std::cout << "Estoy en el update de gameplay" << std::endl;
 
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    m_pApp->SetState(new OptionsState());
  }

}

void GameplayState::OnExit()
{
  m_pApp->m_stateStack.pop();
  //m_pApp->SetState(new MenuState());
}

void GraphicsState::OnEnter()
{
  std::cout << "Estoy en Graphics" << std::endl;
  m_pApp->m_windowManager.text.setString("Graphics Options.\n\n\Por ahora no hay nada mas que hacer aquí :D\nEspacio para regresar a opciones.");
}

void GraphicsState::OnUpdate()
{
  std::cout << "Estoy en el update de graphics" << std::endl;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    m_pApp->SetState(new OptionsState());
  }
}

void GraphicsState::OnExit()
{
  m_pApp->m_stateStack.pop();
  //m_pApp->SetState(new MenuState());
}

void SoundState::OnEnter()
{
  std::cout << "Estoy en Sound" << std::endl;
  m_pApp->m_windowManager.text.setString("Sound Options.\n\n\Por ahora no hay nada mas que hacer aquí, que sad :(\nEspacio para regresar a opciones.");
}

void SoundState::OnUpdate()
{
  std::cout << "Estoy en el update de Sound" << std::endl;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    m_pApp->SetState(new OptionsState());
  }
}

void SoundState::OnExit()
{
  m_pApp->m_stateStack.pop();
  //m_pApp->SetState(new MenuState());
}