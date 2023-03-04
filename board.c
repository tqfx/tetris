#include "board.h"

#include <stdlib.h>

tetris_board *tetris_board_init(tetris_board *const ctx, unsigned int const height, unsigned int const width) {
    ctx->board = (int *)calloc(height * width, sizeof(int));
    ctx->height = height;
    ctx->width = width;
    return ctx;
}

tetris_board *tetris_board_exit(tetris_board *const ctx) {
    free(ctx->board);
    ctx->board = NULL;
    ctx->height = 0;
    ctx->width = 0;
    return ctx;
}

void tetris_board_place(tetris_board const *const ctx, unsigned int const height, unsigned int const width, tetris_shape_t const *const shape) {
    for (unsigned int count = 0; count < shape->shape->count; ++count) {
        unsigned int h = height + shape->point[count][0];
        unsigned int w = width + shape->point[count][1];
        ctx->board[h * ctx->width + w] = shape->shape->name;
    }
}

int tetris_board_check(tetris_board const *const ctx, unsigned int const height, unsigned int const width, tetris_shape_t const *const shape) {
    int ok = 1;
    for (unsigned int count = 0; count < shape->shape->count; ++count) {
        unsigned int h = height + shape->point[count][0];
        unsigned int w = width + shape->point[count][1];
        if (h >= ctx->height || w >= ctx->width || ctx->board[h * ctx->width + w]) {
            ok = 0;
            break;
        }
    }
    return ok;
}
