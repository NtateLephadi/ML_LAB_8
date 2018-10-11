#include "grid.h"
#include <algorithm>    // std::max
#include <fstream>



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
      std::cout << this->world[i][j].get_value() << " | ";
    }
    std::cout << '\n';
  }
}

bool grid::converge(grid lhs){
  for (size_t column = 0; column < this->world.size(); column++) {
    /* code */
    for (size_t row = 0; row < this->world[column].size(); row++) {
      /* code */
      if (this->world[column][row].get_value()!=lhs.world[column][row].get_value()) {
        /* code */
        return false;
      }
    }
  }
  return true;
}

void grid::fill_grid() {
  /* code */
  grid g;
  state s;
  g.world={{s,s,s},{s,s,s}};
  while (!this->converge(g)) {
    /* code */
    auto temp=this->world;
    for (size_t i = 0; i < 3; i++) {
      /* code */
      for (size_t column = 0; column < this->world.size(); column++) {
        /* code */
        for (size_t row = 0; row < this->world[column].size(); row++) {
          /* code */
          state next_state;
          for(char a: this->world[column][row].get_action()){
            switch (a) {
              case 'u':{
                next_state=this->world[column-1][row];
                this->world[column][row].set_value(std::max(this->world[column][row].get_value(), this->world[column][row].get_reward()[next_state.get_state_number()]+this->world[column][row].get_discount()*next_state.get_value()));
              }
              break;
              case 'd':{
                next_state=this->world[column+1][row];
                this->world[column][row].set_value(std::max(this->world[column][row].get_value(), this->world[column][row].get_reward()[next_state.get_state_number()]+this->world[column][row].get_discount()*next_state.get_value()));
              }
              break;
              case 'l':{
                next_state=this->world[column][row-1];
                this->world[column][row].set_value(std::max(this->world[column][row].get_value(), this->world[column][row].get_reward()[next_state.get_state_number()]+this->world[column][row].get_discount()*next_state.get_value()));
              }
              break;
              case 'r':{
                next_state=this->world[column][row+1];
                this->world[column][row].set_value(std::max(this->world[column][row].get_value(), this->world[column][row].get_reward()[next_state.get_state_number()]+this->world[column][row].get_discount()*next_state.get_value()));
              }
              break;
              default:{
              }
              break;
            }
          }
        }
      }
    }
    g.world = temp;
  }
}

void grid::write_optimal() {
  /* code */
  std::ofstream ofs ("ml_lab_8");
  for (size_t column = 0; column < 2; column++) {
    /* code */
    for (size_t row = 0; row < 3; row++) {
      /* code */
      ofs << this->world[column][row].get_value() << " | ";
    }
    ofs << '\n';
  }
  ofs.close();
}
