#include "grid.h"

grid::grid(){}
grid::~grid(){}
grid::grid(std::vector<std::vector<state>> world){
  this->world=world;
}
void grid::to_string(){
  for (size_t i = 0; i < this->world.size(); i++) {
    /* code */
    for (size_t j = 0; j < this->world[i].size(); j++) {
      /* code */
      this->world[i][j].to_string();
    }
  }
}
