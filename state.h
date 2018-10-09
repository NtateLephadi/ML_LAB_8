#include <vector>
#include <map>

#ifndef STATE_H
#define STATE_H

class state{
    private:
      std::vector<char> actions;
      std::map<int, int> reward;
      int value, state_number;
      float discount, probability;
    public:
      state(std::vector<char>, std::map<int, int>, int, int, float, float);
      state();
      ~state();
      void set_value(int);
      void set_discount(float);
      void set_probability(float);
      float get_discount();
      float get_probability();
      int get_reward(int);
      int get_state_number();
      int get_value();
      void to_string();
};
#endif
