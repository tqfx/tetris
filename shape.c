#include "shape.h"

tetris_shape const tetris_shape_A = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0},
        // clang-format on
    },
    1,
    1,
    'A',
};

tetris_shape const tetris_shape_B = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1},
        {0, 0}, {1, 0},
        // clang-format on
    },
    2,
    2,
    'B',
};

tetris_shape const tetris_shape_C = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1}, {0, 2},
        {0, 0}, {1, 0}, {2, 0},
        // clang-format on
    },
    3,
    2,
    'C',
};

tetris_shape const tetris_shape_D = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1}, {1, 0},
        {0, 0}, {0, 1}, {1, 1},
        {0, 0}, {1, 0}, {1, 1},
        {0, 1}, {1, 0}, {1, 1},
        // clang-format on
    },
    3,
    4,
    'D',
};

tetris_shape const tetris_shape_I = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1}, {0, 2}, {0, 3},
        {0, 0}, {1, 0}, {2, 0}, {3, 0},
        // clang-format on
    },
    4,
    2,
    'I',
};

tetris_shape const tetris_shape_J = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1}, {0, 2}, {1, 2},
        {0, 0}, {0, 1}, {1, 0}, {2, 0},
        {0, 0}, {1, 0}, {1, 1}, {1, 2},
        {0, 1}, {1, 1}, {2, 1}, {2, 0},
        // clang-format on
    },
    4,
    4,
    'J',
};

tetris_shape const tetris_shape_L = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1}, {0, 2}, {1, 0},
        {0, 0}, {0, 1}, {1, 1}, {2, 1},
        {0, 0}, {1, 0}, {2, 0}, {2, 1},
        {0, 2}, {1, 0}, {1, 1}, {1, 2},
        // clang-format on
    },
    4,
    4,
    'L',
};

tetris_shape const tetris_shape_O = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1}, {1, 1}, {1, 0},
        // clang-format on
    },
    4,
    1,
    'O',
};

tetris_shape const tetris_shape_S = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {1, 0}, {1, 1}, {2, 1},
        {0, 1}, {0, 2}, {1, 0}, {1, 1},
        // clang-format on
    },
    4,
    2,
    'S',
};

tetris_shape const tetris_shape_T = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1}, {0, 2}, {1, 1},
        {0, 0}, {1, 0}, {2, 0}, {1, 1},
        {0, 1}, {1, 0}, {1, 1}, {2, 1},
        {0, 1}, {1, 0}, {1, 2}, {1, 1},
        // clang-format on
    },
    4,
    4,
    'T',
};

tetris_shape const tetris_shape_Z = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1}, {1, 1}, {1, 2},
        {0, 1}, {1, 0}, {1, 1}, {2, 0},
        // clang-format on
    },
    4,
    2,
    'Z',
};

tetris_shape const tetris_shape_U = {
    (unsigned int[][2]){
        // clang-format off
        {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 2},
        {0, 0}, {0, 1}, {1, 0}, {2, 0}, {2, 1},
        {0, 0}, {0, 1}, {1, 1}, {2, 0}, {2, 1},
        {0, 0}, {0, 2}, {1, 0}, {1, 1}, {1, 2},
        // clang-format on
    },
    5,
    4,
    'U',
};

tetris_shape const tetris_shape_X = {
    (unsigned int[][2]){
        // clang-format off
        {0, 1}, {1, 0}, {1, 1}, {1, 2}, {2, 1},
        // clang-format on
    },
    5,
    1,
    'X',
};

tetris_shape_t *tetris_shape_init(tetris_shape_t *ctx, tetris_shape const *const shape) {
    ctx->point = shape->point;
    ctx->shape = shape;
    ctx->step = 0;
    return ctx;
}

unsigned int tetris_shape_rotate(tetris_shape_t *ctx) {
    ++ctx->step;
    if (ctx->step >= ctx->shape->step) {
        ctx->step = 0;
    }
    ctx->point = ctx->shape->point + ctx->shape->count * ctx->step;
    return ctx->step;
}

unsigned int tetris_shape_reverse(tetris_shape_t *ctx) {
    if (ctx->step == 0) {
        ctx->step = ctx->shape->step;
    }
    --ctx->step;
    ctx->point = ctx->shape->point + ctx->shape->count * ctx->step;
    return ctx->step;
}
