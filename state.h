#include <vector>
#include <map>

#ifndef STATE_H
#define STATE_H

class state{
    private:
      std::vector<char> actions;
      std::map<int, int> reward;
      int value, state_number;
    public:
      state(std::vector<char>, std::map<int, int>, int);
      ~state();
      void set_value(int);
      int get_reward(int);
      int get_state_number();
      int get_value();
};
#endif
