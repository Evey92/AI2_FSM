#pragma once
#include "AppState.h"
#include "Window.h"

class App
{
public:
  App();
  ~App() {};

  bool m_isPaused = false;
  Window m_windowManager;
  std::stack<AppState*> m_stateStack;
  std::vector<sf::Drawable*> m_vDrawableObjects;
  AppState* m_currentState;

  void Update();
  void SetState(AppState* pNewState);
   
};