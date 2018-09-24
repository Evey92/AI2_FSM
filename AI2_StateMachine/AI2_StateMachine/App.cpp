#include "pch.h"
#include "App.h"

App::App()
{
  m_currentState = nullptr;
  SetState(new LogoState());
  m_windowManager.Create();
}

void App::SetState(AppState* pNewState)
{
  //Cargar el Logo por primera vez
  if (m_currentState == nullptr)
  {
    m_stateStack.push(pNewState);
    m_currentState = pNewState;
    m_currentState->m_pApp = this;
    m_currentState->OnEnter();
    
  }
  //Si esta "Pausado" el juego
  else 
  {
    /*if (m_isPaused)
    {
      m_currentState->OnExit();
     
      m_currentState = pNewState;
      m_currentState->m_pApp = this;
      m_currentState->OnEnter();
    }*/
    //Cualquier otro estado
    /*else
    {*/
      m_currentState->OnExit();
      delete(m_currentState);
      m_stateStack.push(pNewState);
      m_currentState = pNewState;
      m_currentState->m_pApp = this;
      m_currentState->OnEnter();
    //}
  }
}

void App::Update()
{
  while (m_windowManager.m_appWindow.isOpen())
  {
    while (m_windowManager.m_appWindow.pollEvent(m_windowManager.event))
    {
      if (m_windowManager.event.type == sf::Event::Closed)
        m_windowManager.m_appWindow.close();
      else
        m_currentState->OnUpdate();
    }

    m_windowManager.m_appWindow.clear();
    m_windowManager.m_appWindow.draw(m_windowManager.m_Testshape);
    m_windowManager.m_appWindow.draw(m_windowManager.sprite);
    m_windowManager.m_appWindow.draw(m_windowManager.text);
    m_windowManager.m_appWindow.display();
  }
  m_currentState->OnUpdate();
}