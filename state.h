#include <vector>
#include <map>

#ifndef STATE_H
#define STATE_H

class state{
    private:
      std::vector<char> actions;
      std::map<state, int> reward;
      int value;
    public:
      state(std::vector<char> v, std::map<state, int> map);
      ~state();
      void set_value(int value);
      int get_reward(state s);
};
#endif
