#include "splash.h"


Splash::Splash(){
}


void Splash::Display(Controller const &controller, Renderer &renderer){
  bool running = true;
  renderer.RenderBMP(_filepath);
  while(running){
    // wait for user to press Enter to exit menu
    controller.HandleInput(running);
  }
}


void Splash::SetFilepath(std::string filepath){
  _filepath = filepath;
}

std::string Splash::GetFilepath(){
  return _filepath;
}