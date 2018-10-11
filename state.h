#include <vector>
#include <map>
#include <iostream>

#ifndef STATE_H
#define STATE_H

class state{
    private:
      std::vector<char> actions;
      std::map<int, int> reward;
      int state_number;
      float discount, probability, value;
    public:
      state(std::vector<char>, std::map<int, int>, int, int, float, float);
      state();
      ~state();
      void set_value(float);
      void set_discount(float);
      void set_probability(float);
      void set_state_number(int);
      float get_discount();
      float get_probability();
      std::map<int, int> get_reward();
      int get_state_number();
      float get_value();
      std::vector<char> get_action();
      void to_string();
};
#endif
