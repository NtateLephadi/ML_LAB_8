#include <vector>
#include <map>

#ifndef STATE_H
#define STATE_H

class state{
    private:
      std::vector<char> actions;
      std::map<int, int> reward;
      int value, number;
    public:
      state(std::vector<char> v, std::map<int, int> map);
      ~state();
      void set_value(int value);
      int get_reward(int);
      int get_number();
};
#endif
