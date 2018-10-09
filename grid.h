#include <vector>
#include <map>
#include "state.h"

#ifndef GRID_H
#define GRID_H

class grid{
    private:
      std::vector<std::vector<state>> world;
    public:
      grid();
      ~grid();
      int fill_grid(state);
      int next_value(state, int);
      void fill_grid(state);
};
#endif
