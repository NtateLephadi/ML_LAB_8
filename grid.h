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
      grid(std::vector<std::vector<state>>);
      void to_string();
      int next_value(state);
      void fill_grid(state);
};
#endif
