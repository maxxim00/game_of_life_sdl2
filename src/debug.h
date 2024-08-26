#include <stdlib.h>

struct stat_data {
  double fps, tpf;
  int a_cells, d_cells; //Alive dead cells
};
typedef struct stat_data stat_data;

extern stat_data *debug_data;
