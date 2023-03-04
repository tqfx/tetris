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
int tetris_board_push(tetris_board const *const ctx, tetris_shape_t *const shape);
void tetris_board_show(tetris_board const *const ctx);

#if defined(__cplusplus)
}
#endif /* __cplusplus */
