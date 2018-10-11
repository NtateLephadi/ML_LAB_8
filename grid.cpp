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
  grid g, temp;
  state s;
  s.set_value(1.0);
  g.world={{s,s,s},{s,s,s}};
  temp.world=g.world;
  while (this->converge(g)==0) {
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
    g.world=temp.world;
    temp.world=this->world;
  }
  this->write_optimal();
}

void grid::write_optimal() {
  /* code */
  std::ofstream ofs ("question1");
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

std::vector<state> grid::optimal_policy(state s){
  std::vector<state> states, optimal_states;
  state next_state;
  optimal_states.push_back(s);
  for (size_t column = 0; column < this->world.size(); column++) {
    /* code */
    for (size_t row = 0; row < this->world[column].size(); row++) {
      /* code */
      if (s.get_value()==this->world[column][row].get_value()) {
        /* code */
        while (s.get_state_number()!=3) {
          /* code */
          for(char a: s.get_action()){
            switch (a) {
              case 'u':{
                next_state=this->world[column-1][row];
                states.push_back(next_state);
              }
              break;
              case 'd':{
                next_state=this->world[column+1][row];
                states.push_back(next_state);
              }
              break;
              case 'l':{
                next_state=this->world[column][row-1];
                states.push_back(next_state);
              }
              break;
              case 'r':{
                next_state=this->world[column][row+1];
                states.push_back(next_state);
              }
              break;
              default:{

              }
              break;
            }
            std::cout << "/* message */" << '\n';
          }
          s=optimal_state(states);
          optimal_states.push_back(s);
          states.clear();
        }
      }
    }
  }
  return optimal_states;
}

state grid::optimal_state(std::vector<state> v){
  state s;
  for (size_t column = 0; column < v.size(); column++) {
    /* code */
    if(v[column].get_value()>s.get_value()){
      s.set_value(v[column].get_value());
      s.set_state_number(v[column].get_state_number());
    }
  }
  return s;
}

void grid::write_optimal_policy(std::vector<state> states) {
  /* code */
  std::ofstream ofs ("question2");
  for(auto s: states){
    ofs << "s" << s.get_state_number() << "->";
  }
  ofs.close();
}
