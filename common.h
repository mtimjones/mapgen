#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
   char *adrs;
   int  rows;
   int  cols;
} map_t;

map_t *create_map( int rows, int cols );
void   free_map( map_t *map );
void   print_map( map_t *map );
void   set_map( map_t *map, int rows, int cols, char val );

// RNG Functions
#define seed()          ( srand( time( NULL ) ) )
#define getSRand()      ( ( float ) rand( ) / ( float ) RAND_MAX )
#define getRand( x )    ( int ) ( ( x ) * getSRand( ) )

#endif // __COMMON_H__
