#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// RNG Functions
#define seed()          ( srand( time( NULL ) ) )
#define getSRand()      ( ( float ) rand( ) / ( float ) RAND_MAX )
#define getRand( x )    ( int ) ( ( x ) * getSRand( ) )


#define COLS 80
#define ROWS 40

char buffer[2][COLS][ROWS];

void init_buffer( void )
{
    int c, r;

    memset( buffer, 0, sizeof(buffer) );

    for ( c = 0 ; c < COLS ; c++ )
    {
        for ( r = 0 ; r < ROWS ; r++ )
        {
            if ( getSRand() > 0.38 )
            {
                buffer[0][c][r] = 1;
            }
        }
    }
}

typedef struct {
    int c_offs;
    int r_offs;
} dirs_t;

#define MAX_DIRS    8
dirs_t dirs[MAX_DIRS] = {
//     c   r
    { -1, -1 },
    {  0, -1 },
    {  1, -1 },
    { -1,  0 },
    {  1,  0 },
    { -1,  1 },
    {  0,  1 },
    {  1,  1 }
};

int count_cells( int observe, int c, int r )
{
    int cells = 0;
    int c1, r1;

    for ( int i = 0 ; i < MAX_DIRS ; i++ )
    {
        c1 = c + dirs[i].c_offs;
        r1 = r + dirs[i].r_offs;

        if ( ( c1 < 0 ) || ( c1 >= COLS ) ||
             ( r1 < 0 ) || ( r1 >= ROWS ) )
        {
            cells++;
        }
        else
        {
            cells += buffer[observe][c1][r1];
        }
    }

    return cells;
}

void process( int observe, int set )
{
    int c, r;

//    memset( &buffer[set][0][0], 0, (ROWS * COLS * sizeof(char)) );

    for ( r = 0 ; r < ROWS ; r++ )
    {
        for ( c = 0 ; c < COLS ; c++ )
        {
            if ( count_cells( observe, c, r ) > 4 )
            {
                buffer[set][c][r] = 1;
            }
            else
            {
                buffer[set][c][r] = 0;
            }
        }
    }

    return;
}

void print_buffer( int observe )
{
    int c, r;

    for ( r = 0 ; r < ROWS ; r++ )
    {
        for ( c = 0 ; c < COLS ; c++ )
        {
            if ( buffer[observe][c][r] )
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void main()
{
    int observe=0, set=1, iter;

    seed( );

    init_buffer();

    for ( iter = 0 ; iter < 20 ; iter++ )
    {
        process( observe, set );
        observe = !observe;
        set = !set;
    }

    print_buffer(observe);

    return;
}

