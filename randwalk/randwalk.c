#include "common.h"

#define COLS  80
#define ROWS  40
#define WALK  50
#define RUNS  40

void main()
{
   map_t *map = create_map( COLS, ROWS );
   int rows, cols, walk, runs;

   seed();

   for ( runs = 0 ; runs < RUNS ; runs++ )
   {
      rows = getRand( ROWS );
      cols = getRand( COLS );

      for ( walk = 0 ; walk < WALK ; walk++ )
      {
         set_map( map, cols, rows, '*' );

         switch( getRand( 4 ) )
         {
            case 0:    // UP
               rows--;
               break;
            case 1:    // DOWN
               rows++;
               break;
            case 2:    // LEFT
               cols--;
               break;
            case 3:    // RIGHT
               cols++;
               break;
         }

         if ( ( cols >= COLS ) || ( cols < 0 ) || 
              ( rows >= ROWS ) || ( rows < 0 ) )
         {
            break;
         }
      }

   }

   print_map( map );

   free_map( map );

   return;
}
