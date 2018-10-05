#include <vector>
#include <map>
#include "state.h"

state::state(std::vector<char> actions, std::map<int, int> reward){
  this->actions=actions;
  this->reward=reward;
}
state::~state(){}
void set_value(int value){

}
int state::get_reward(int n){
  return this->reward[n];
}
int state::get_number(){
  return this->number;
}
