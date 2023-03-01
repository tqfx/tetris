#pragma once

#include <stdint.h>

enum {
    TETRIS_I = 'I',
    TETRIS_J = 'J',
    TETRIS_L = 'L',
    TETRIS_O = 'O',
    TETRIS_S = 'S',
    TETRIS_T = 'T',
    TETRIS_Z = 'Z'
};

/*! {{0, 0}, {1, 0}, {2, 0}, {3, 0}}
    I
    I
    I
    I
*/
extern unsigned int const tetris_shape_I0[4][2];
/*! {{0, 0}, {0, 1}, {0, 2}, {0, 3}}
    IIII
*/
extern unsigned int const tetris_shape_I1[4][2];
/*! {{0, 1}, {1, 1}, {2, 1}, {2, 0}}
     J
     J
    JJ
*/
extern unsigned int const tetris_shape_J0[4][2];
/*! {{1, 2}, {1, 1}, {1, 0}, {0, 0}}
    J
    JJJ
*/
extern unsigned int const tetris_shape_J1[4][2];
/*! {{2, 0}, {1, 0}, {0, 0}, {0, 1}}
    JJ
    J
    J
*/
extern unsigned int const tetris_shape_J2[4][2];
/*! {{0, 0}, {0, 1}, {0, 2}, {1, 2}}
    JJJ
      J
*/
extern unsigned int const tetris_shape_J3[4][2];
/*! {{0, 0}, {1, 0}, {2, 0}, {2, 1}}
    L
    L
    LL
*/
extern unsigned int const tetris_shape_L0[4][2];
/*! {{0, 2}, {0, 1}, {0, 0}, {1, 0}}
    LLL
    L
*/
extern unsigned int const tetris_shape_L1[4][2];
/*! {{2, 1}, {1, 1}, {0, 1}, {0, 0}}
    LL
     L
     L
*/
extern unsigned int const tetris_shape_L2[4][2];
/*! {{1, 0}, {1, 1}, {1, 2}, {0, 2}}
      L
    LLL
*/
extern unsigned int const tetris_shape_L3[4][2];
/*! {{0, 0}, {0, 1}, {1, 1}, {1, 0}}
    OO
    OO
*/
extern unsigned int const tetris_shape_O0[4][2];
/*! {{0, 2}, {0, 1}, {1, 1}, {1, 0}}
     SS
    SS
*/
extern unsigned int const tetris_shape_S0[4][2];
/*! {{0, 0}, {1, 0}, {1, 1}, {2, 1}}
    S
    SS
     S
*/
extern unsigned int const tetris_shape_S1[4][2];
/*! {{0, 0}, {0, 1}, {0, 2}, {1, 1}}
    TTT
     T
*/
extern unsigned int const tetris_shape_T0[4][2];
/*! {{0, 1}, {1, 1}, {2, 1}, {1, 0}}
     T
    TT
     T
*/
extern unsigned int const tetris_shape_T1[4][2];
/*! {{1, 2}, {1, 1}, {1, 0}, {0, 1}}
     T
    TTT
*/
extern unsigned int const tetris_shape_T2[4][2];
/*! {{2, 0}, {1, 0}, {0, 0}, {1, 1}}
    T
    TT
    T
*/
extern unsigned int const tetris_shape_T3[4][2];
/*! {{0, 0}, {0, 1}, {1, 1}, {1, 2}}
    ZZ
     ZZ
*/
extern unsigned int const tetris_shape_Z0[4][2];
/*! {{0, 1}, {1, 1}, {1, 0}, {2, 0}}
     Z
    ZZ
    Z
*/
extern unsigned int const tetris_shape_Z1[4][2];

typedef struct tetris_shape {
    unsigned int const (*point)[2];
    unsigned int count;
    int shape;
} tetris_shape;

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

tetris_shape *tetris_shape_init(tetris_shape *ctx, int shape);
unsigned int tetris_shape_rotate(tetris_shape *ctx);
unsigned int tetris_shape_reverse(tetris_shape *ctx);

#if defined(__cplusplus)
}
#endif /* __cplusplus */
