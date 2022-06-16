#include "common.h"

map_t *create_map( int cols, int rows )
{
   map_t *map = (map_t *)calloc( sizeof(map_t), 1 );

   map->adrs = (char *)calloc( ( sizeof(char) * rows * cols ), 1 );
   map->rows = rows;
   map->cols = cols;

   for ( rows = 0 ; rows < map->rows ; rows++ )
   {
      for ( cols = 0 ; cols < map->cols ; cols++ )
      {
         map->adrs[cols+(rows*map->cols)] = ' ';
      }
   }

   return map;
}

void free_map( map_t *map )
{
   free( (void *)map->adrs );
   free( (void *)map );
}

void print_map( map_t *map )
{
   int rows, cols;

   for ( rows = 0 ; rows < map->rows ; rows++ )
   {
      for ( cols = 0 ; cols < map->cols ; cols++ )
      {
          printf("%c", map->adrs[cols+(rows*map->cols)]);
      }
      printf("\n");
   }
}

void set_map( map_t *map, int cols, int rows, char val )
{
    map->adrs[cols+(rows*map->cols)] = val;
}

