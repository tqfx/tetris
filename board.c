#include "board.h"
#include <stdlib.h>

tetris_board *tetris_board_init(tetris_board *const ctx, unsigned int const height, unsigned int const width) {
    ctx->height = height;
    ctx->width = width;
    ctx->board = (int *)malloc(sizeof(int) * height * width);
    return ctx;
}

tetris_board *tetris_board_exit(tetris_board *const ctx) {
    free(ctx->board);
    ctx->board = NULL;
    ctx->height = 0;
    ctx->width = 0;
    return ctx;
}

int tetris_board_push(tetris_board const *const ctx, tetris_shape_t *const shape) {
    for (unsigned int height = 0; height < ctx->height; ++height) {
        for (unsigned int width = 0; width < ctx->width; ++width) {
            do {
                int ok = 1;
                for (unsigned int count = 0; count < shape->shape->count; ++count) {
                    unsigned int h = height + shape->point[count][0];
                    unsigned int w = width + shape->point[count][1];
                    if (h >= ctx->height || w >= ctx->width ||
                        ctx->board[h * ctx->width + w]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    for (unsigned int count = 0; count < shape->shape->count; ++count) {
                        unsigned int h = height + shape->point[count][0];
                        unsigned int w = width + shape->point[count][1];
                        ctx->board[h * ctx->width + w] = shape->shape->name;
                    }
                    return ok;
                }
            } while (tetris_shape_rotate(shape));
        }
    }
    return 0;
}

#include <stdio.h>
void tetris_board_show(tetris_board const *const ctx) {
    for (unsigned int height = 0; height < ctx->height; ++height) {
        for (unsigned int width = 0; width < ctx->width; ++width) {
            int name = ctx->board[height * ctx->width + width];
            putchar(name ? name : ' ');
        }
        putchar('\n');
    }
}
