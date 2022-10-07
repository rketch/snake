#ifndef SPLASH_H
#define SPLASH_H


#include <string>
#include "renderer.h"
#include "controller.h"

class Splash{
  /* */
  public: 
  Splash(); // constructor
  ~Splash(){
    // Destructor
  }
  	void Display(Controller const &controller, Renderer &renderer);
  	void SetFilepath(std::string filepath);
  	std::string GetFilepath();
  private:
    std::string _filepath;
    };

#endif