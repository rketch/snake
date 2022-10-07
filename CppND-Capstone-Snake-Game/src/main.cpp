#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "splash.h"
#include <stdlib.h>

static const char ScoreFile[] = "/home/workspace/snake/CppND-Capstone-Snake-Game/Score.csv";

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  // initialize game.
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  // play the game.
  game.Run(controller, renderer, kMsPerFrame);
  
  // you are dead. Display splash screen.
  Splash splash;
  splash.SetFilepath("/home/workspace/snake/CppND-Capstone-Snake-Game/cat_picture.bmp");
  splash.Display(controller, renderer);
  
  // after quitting the game, write the score to a CSV file to prove that you are a snake master.
  FILE * score_log = fopen(ScoreFile,"w");
  if(score_log){
    fprintf(score_log, "Score: %u, Size: %u \n", game.GetScore(), game.GetSize());
  }
  fclose(score_log);
  // output contents of CSV to terminal
  system("cat /home/workspace/snake/CppND-Capstone-Snake-Game/Score.csv");
  std::cout << " \nGame has terminated successfully!\n";
  return 0;
}