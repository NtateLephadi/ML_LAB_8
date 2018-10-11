#include <iostream>
#include <vector>
#include <map>
#include "grid.h"
#include "state.h"
#include "limits.h"
int main(int argc, char const *argv[]) {
  /* code */
  state s1, s2, s3, s4, s5, s6;
  s1=state({'r','d'},{},0,1,0.8,1.0);
  s2=state({'l','r','d'},{{3,50}},0,2,0.8,1.0);
  s3=state({},{},0,3,0.8,1.0);
  s4=state({'u','r'},{},0,4,0.8,1.0);
  s5=state({'u','l','r'},{},0,5,0.8,1.0);
  s6=state({'u','l'},{{3,100}},0,6,0.8,1.0);
  grid g({{s1,s2,s3},{s4,s5,s6}});

  g.fill_grid();
  g.to_string();

  return 0;
}
