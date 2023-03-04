#pragma once

typedef struct tetris_shape {
    unsigned int const (*const point)[2];
    unsigned int const count;
    unsigned short const step;
    short const name;
} tetris_shape;

extern tetris_shape const tetris_shape_A;
extern tetris_shape const tetris_shape_B;
extern tetris_shape const tetris_shape_C;
extern tetris_shape const tetris_shape_D;
extern tetris_shape const tetris_shape_I;
extern tetris_shape const tetris_shape_J;
extern tetris_shape const tetris_shape_L;
extern tetris_shape const tetris_shape_O;
extern tetris_shape const tetris_shape_S;
extern tetris_shape const tetris_shape_T;
extern tetris_shape const tetris_shape_Z;
extern tetris_shape const tetris_shape_U;
extern tetris_shape const tetris_shape_X;

typedef struct tetris_shape_t {
    unsigned int const (*point)[2];
    tetris_shape const *shape;
    unsigned int step;
    int const _R0;
} tetris_shape_t;

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

tetris_shape_t *tetris_shape_init(tetris_shape_t *ctx, tetris_shape const *shape);
unsigned int tetris_shape_rotate(tetris_shape_t *ctx);
unsigned int tetris_shape_reverse(tetris_shape_t *ctx);

#if defined(__cplusplus)
}
#endif /* __cplusplus */
