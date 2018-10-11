#include <vector>
#include <map>
#include "state.h"
#include <string>

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
      void fill_grid();
      bool converge(grid);
      void write_optimal();
      std::vector<state> optimal_policy(state);

};
#endif
