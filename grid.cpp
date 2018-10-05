#include "grid.h"

grid::grid(){}

grid::~grid();

int grid::next_value(state s, int a){
    state next;
    for (state s1: this->world){
      if (s1.get_number()==s.get_number()) {
        /* code */
        next = s1;
        break;
      }
    }
    return next.get_value();
}

void grid::fill_grid(state s){
  int reward = s.get_reward(s.get_number());
  float discount = 0.8;
  int value = next_value(s);
  value = reward + discount*value;
}
