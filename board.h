#pragma once

#include "shape.h"

typedef struct tetris_board {
    int *board;
    unsigned int height, width;
} tetris_board;

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

tetris_board *tetris_board_init(tetris_board *ctx, unsigned int height, unsigned int width);
tetris_board *tetris_board_exit(tetris_board *ctx);

void tetris_board_place(tetris_board const *ctx, unsigned int height, unsigned int width, tetris_shape_t const *shape);
int tetris_board_check(tetris_board const *ctx, unsigned int height, unsigned int width, tetris_shape_t const *shape);

#if defined(__cplusplus)
}
#endif /* __cplusplus */
