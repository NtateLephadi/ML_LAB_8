#include <vector>
#include <map>
#include "state.h"

state::state(std::vector<char> actions, std::map<int, int> reward, int value){
  this->actions=actions;
  this->reward=reward;
  this->value=value;
}
state::~state(){}
void state::set_value(int value){
  this->value=value;
}
int state::get_reward(int n){
  return this->reward[n];
}
int state::get_state_number(){
  return this->state_number;
}

int state::get_value(){
  return this->value;
}
