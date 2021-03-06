#include <vector>
#include <map>
#include "state.h"

state::state(std::vector<char> actions, std::map<int, int> reward, int value, int state_number, float discount, float probability){
  this->actions=actions;
  this->reward=reward;
  this->value=value;
  this->state_number=state_number;
  this->discount=discount;
  this->probability=probability;
}
state::state(){}
state::~state(){}
void state::set_value(float value){
  this->value=value;
}
void state::set_state_number(int state_number){
  this->state_number=state_number;
}
void state::set_discount(float discount){
  this->discount=discount;
}
void state::set_probability(float probability){
  this->probability=probability;
}
float state::get_discount(){
  return this->discount;
}
float state::get_probability(){
  return this->probability;
}
std::map<int, int> state::get_reward(){
  return this->reward;
}
int state::get_state_number(){
  return this->state_number;
}
float state::get_value(){
  return this->value;
}
std::vector<char> state::get_action(){
  return this->actions;
}

void state::to_string(){
  for (size_t i = 0; i < this->actions.size(); i++) {
    /* code */
    std::cout << this->actions[i] << '\n';
  }
  for (size_t i = 0; i < this->reward.size(); i++) {
    /* code */
    std::cout << this->reward[i] << '\n';
  }
  std::cout << this->value << '\n';
  std::cout << this->state_number << '\n';
  std::cout << this->discount << '\n';
  std::cout << this->probability << '\n';
}
