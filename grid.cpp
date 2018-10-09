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

state grid::next_state(state s, char action){
  for (size_t column = 0; column < this->world.size(); column++) {
    /* code */
    for (size_t row = 0; row < this->world[column]; row++) {
      /* code */
      if (this->world[column][row]==s) {
        /* code */
        return this->world[column][row];
      }
    }
  }
}
