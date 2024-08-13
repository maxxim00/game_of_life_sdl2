#include <stdlib.h>

struct stat_data {
  float fps;
  int all_cells, a_cells, d_cells; //All alive dead cells
};
typedef struct stat_data stat_data;

extern stat_data *debug_data;
