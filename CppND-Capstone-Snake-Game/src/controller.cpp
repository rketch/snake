#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running) const {
    // Overload the HandleInput method to be called when we are not playing the game (menus)
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } 
    else if (e.type == SDL_KEYDOWN) {
      // if we press a key  
      switch (e.key.keysym.sym) {
        case SDLK_RETURN:
          // quit playing with the enter button
          running = false;
        case SDLK_RETURN2:
          running = false;
        case SDLK_KP_ENTER:
          running = false;
      }
    }
  }
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } 
    else if (e.type == SDL_KEYDOWN) {
      // if we press a key
        switch (e.key.keysym.sym) {
          case SDLK_ESCAPE:
            // quit playing with the escape button
            running = false;
          case SDLK_UP:
            ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
            break;

          case SDLK_DOWN:
            ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
            break;

          case SDLK_LEFT:
            ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
            break;

          case SDLK_RIGHT:
            ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
            break;
      }
    }
  }
}