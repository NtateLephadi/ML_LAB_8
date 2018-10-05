#include <vector>
#include <map>
#include "state.h"

#ifndef GRID_H
#define GRID_H

class state{
    private:
      std::vector<std::vector<state>> grid;
    public:
      grid();
      ~grid();
      int fill_grid(state s);
      int next_value(state s, int action);
      void fill_grid(state s);
};
#endif
