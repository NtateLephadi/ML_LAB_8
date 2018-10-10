#include "grid.h"
#include <algorithm>    // std::max

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

void grid::fill_grid() {
  /* code */
  for (size_t column = 0; column < this->world.size(); column++) {
    /* code */
    for (size_t row = 0; row < this->world[column].size(); row++) {
      /* code */
      auto s = this->world[column][row];
      for(char a: s.get_action()){
        switch (a) {
          case 'u':{
            auto s_next=this->world[column+1][row];
            s.set_value(std::max(s.get_value(), (s.get_reward()[s_next.get_state_number()]+s.get_discount()*s_next.get_value())));
          }
          break;
          case 'd':{
            auto s_next=this->world[column-1][row];
            s.set_value(std::max(s.get_value(), (s.get_reward()[s_next.get_state_number()]+s.get_discount()*s_next.get_value())));
          }
          break;
          case 'l':{
            auto s_next=this->world[column][row-1];
            s.set_value(std::max(s.get_value(), (s.get_reward()[s_next.get_state_number()]+s.get_discount()*s_next.get_value())));
          }
          break;
          case 'r':{
            auto s_next=this->world[column][row+1];
            s.set_value(std::max(s.get_value(), (s.get_reward()[s_next.get_state_number()]+s.get_discount()*s_next.get_value())));
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
