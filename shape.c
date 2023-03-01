#include "shape.h"

unsigned int const tetris_shape_I0[4][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};
unsigned int const tetris_shape_I1[4][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
unsigned int const tetris_shape_J0[4][2] = {{0, 1}, {1, 1}, {2, 1}, {2, 0}};
unsigned int const tetris_shape_J1[4][2] = {{1, 2}, {1, 1}, {1, 0}, {0, 0}};
unsigned int const tetris_shape_J2[4][2] = {{2, 0}, {1, 0}, {0, 0}, {0, 1}};
unsigned int const tetris_shape_J3[4][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 2}};
unsigned int const tetris_shape_L0[4][2] = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};
unsigned int const tetris_shape_L1[4][2] = {{0, 2}, {0, 1}, {0, 0}, {1, 0}};
unsigned int const tetris_shape_L2[4][2] = {{2, 1}, {1, 1}, {0, 1}, {0, 0}};
unsigned int const tetris_shape_L3[4][2] = {{1, 0}, {1, 1}, {1, 2}, {0, 2}};
unsigned int const tetris_shape_O0[4][2] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
unsigned int const tetris_shape_S0[4][2] = {{0, 2}, {0, 1}, {1, 1}, {1, 0}};
unsigned int const tetris_shape_S1[4][2] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
unsigned int const tetris_shape_T0[4][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 1}};
unsigned int const tetris_shape_T1[4][2] = {{0, 1}, {1, 1}, {2, 1}, {1, 0}};
unsigned int const tetris_shape_T2[4][2] = {{1, 2}, {1, 1}, {1, 0}, {0, 1}};
unsigned int const tetris_shape_T3[4][2] = {{2, 0}, {1, 0}, {0, 0}, {1, 1}};
unsigned int const tetris_shape_Z0[4][2] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
unsigned int const tetris_shape_Z1[4][2] = {{0, 1}, {1, 1}, {1, 0}, {2, 0}};

#undef countof
#define countof(x) (sizeof(x) / sizeof(*(x)))

tetris_shape *tetris_shape_init(tetris_shape *ctx, int shape) {
    ctx->shape = shape;
    switch (ctx->shape) {
    case 'I':
        ctx->point = tetris_shape_I0;
        ctx->count = countof(tetris_shape_I0);
        break;
    case 'J':
        ctx->point = tetris_shape_J0;
        ctx->count = countof(tetris_shape_J0);
        break;
    case 'L':
        ctx->point = tetris_shape_L0;
        ctx->count = countof(tetris_shape_L0);
        break;
    case 'O':
        ctx->point = tetris_shape_O0;
        ctx->count = countof(tetris_shape_O0);
        break;
    case 'S':
        ctx->point = tetris_shape_S0;
        ctx->count = countof(tetris_shape_S0);
        break;
    case 'T':
        ctx->point = tetris_shape_T0;
        ctx->count = countof(tetris_shape_T0);
        break;
    case 'Z':
        ctx->point = tetris_shape_Z0;
        ctx->count = countof(tetris_shape_Z0);
        break;
    default:
        ctx->point = 0;
        ctx->count = 0;
        break;
    }
    return ctx;
}

unsigned int tetris_shape_rotate(tetris_shape *ctx) {
    unsigned int step = 0;
    switch (ctx->shape) {
    case 'I':
        if (ctx->point == tetris_shape_I0) {
            ctx->point = tetris_shape_I1;
            step = 1;
        } else {
            ctx->point = tetris_shape_I0;
        }
        break;
    case 'J':
        if (ctx->point == tetris_shape_J0) {
            ctx->point = tetris_shape_J1;
            step = 1;
        } else if (ctx->point == tetris_shape_J1) {
            ctx->point = tetris_shape_J2;
            step = 2;
        } else if (ctx->point == tetris_shape_J2) {
            ctx->point = tetris_shape_J3;
            step = 3;
        } else {
            ctx->point = tetris_shape_J0;
        }
        break;
    case 'L':
        if (ctx->point == tetris_shape_L0) {
            ctx->point = tetris_shape_L1;
            step = 1;
        } else if (ctx->point == tetris_shape_L1) {
            ctx->point = tetris_shape_L2;
            step = 2;
        } else if (ctx->point == tetris_shape_L2) {
            ctx->point = tetris_shape_L3;
            step = 3;
        } else {
            ctx->point = tetris_shape_L0;
        }
        break;
    case 'S':
        if (ctx->point == tetris_shape_S0) {
            ctx->point = tetris_shape_S1;
            step = 1;
        } else {
            ctx->point = tetris_shape_S0;
        }
        break;
    case 'T':
        if (ctx->point == tetris_shape_T0) {
            ctx->point = tetris_shape_T1;
            step = 1;
        } else if (ctx->point == tetris_shape_T1) {
            ctx->point = tetris_shape_T2;
            step = 2;
        } else if (ctx->point == tetris_shape_T2) {
            ctx->point = tetris_shape_T3;
            step = 3;
        } else {
            ctx->point = tetris_shape_T0;
        }
        break;
    case 'Z':
        if (ctx->point == tetris_shape_Z0) {
            ctx->point = tetris_shape_Z1;
            step = 1;
        } else {
            ctx->point = tetris_shape_Z0;
        }
        break;
    case 'O':
    default:
        break;
    }
    return step;
}

unsigned int tetris_shape_reverse(tetris_shape *ctx) {
    unsigned int step = 0;
    switch (ctx->shape) {
    case 'I':
        if (ctx->point == tetris_shape_I0) {
            ctx->point = tetris_shape_I1;
            step = 1;
        } else {
            ctx->point = tetris_shape_I0;
        }
        break;
    case 'J':
        if (ctx->point == tetris_shape_J0) {
            ctx->point = tetris_shape_J3;
            step = 3;
        } else if (ctx->point == tetris_shape_J3) {
            ctx->point = tetris_shape_J2;
            step = 2;
        } else if (ctx->point == tetris_shape_J2) {
            ctx->point = tetris_shape_J1;
            step = 1;
        } else {
            ctx->point = tetris_shape_J0;
        }
        break;
    case 'L':
        if (ctx->point == tetris_shape_L0) {
            ctx->point = tetris_shape_L3;
            step = 3;
        } else if (ctx->point == tetris_shape_L3) {
            ctx->point = tetris_shape_L2;
            step = 2;
        } else if (ctx->point == tetris_shape_L2) {
            ctx->point = tetris_shape_L1;
            step = 1;
        } else {
            ctx->point = tetris_shape_L0;
        }
        break;
    case 'S':
        if (ctx->point == tetris_shape_S0) {
            ctx->point = tetris_shape_S1;
            step = 1;
        } else {
            ctx->point = tetris_shape_S0;
        }
        break;
    case 'T':
        if (ctx->point == tetris_shape_T0) {
            ctx->point = tetris_shape_T3;
            step = 3;
        } else if (ctx->point == tetris_shape_T3) {
            ctx->point = tetris_shape_T2;
            step = 2;
        } else if (ctx->point == tetris_shape_T2) {
            ctx->point = tetris_shape_T1;
            step = 1;
        } else {
            ctx->point = tetris_shape_T0;
        }
        break;
    case 'Z':
        if (ctx->point == tetris_shape_Z0) {
            ctx->point = tetris_shape_Z1;
            step = 1;
        } else {
            ctx->point = tetris_shape_Z0;
        }
        break;
    case 'O':
    default:
        break;
    }
    return step;
}
