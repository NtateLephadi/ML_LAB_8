#include <vector>
#include <map>
#include "state.h"

#ifndef GRID_H
#define GRID_H

class state{
    private:
      std::vector<std::vector<state>> grid;
    public:
      grid(int height, int width);
      ~grid();
};
#endif
