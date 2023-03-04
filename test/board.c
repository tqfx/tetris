#include "../shape.c"
#include "../board.c"

#include <stdio.h>

static void tetris_board_show(tetris_board const *const ctx) {
    for (unsigned int height = 0; height < ctx->height; ++height) {
        for (unsigned int width = 0; width < ctx->width; ++width) {
            int name = ctx->board[height * ctx->width + width];
            putchar(name ? name : ' ');
        }
        putchar('\n');
    }
}

static int tetris_board_push(tetris_board const *const ctx, tetris_shape_t *const shape) {
    for (unsigned int height = 0; height < ctx->height; ++height) {
        for (unsigned int width = 0; width < ctx->width; ++width) {
            unsigned int step = shape->step;
            do {
                if (tetris_board_check(ctx, height, width, shape)) {
                    tetris_board_place(ctx, height, width, shape);
                    return 1;
                }
            } while (tetris_shape_rotate(shape) != step);
        }
    }
    return 0;
}

int main(void) {
    tetris_board board;
    tetris_shape_t I, J, L, O, S, T, Z;
    tetris_board_init(&board, 14, 10);
    tetris_shape_init(&I, &tetris_shape_I);
    tetris_shape_init(&J, &tetris_shape_J);
    tetris_shape_init(&L, &tetris_shape_L);
    tetris_shape_init(&O, &tetris_shape_O);
    tetris_shape_init(&S, &tetris_shape_S);
    tetris_shape_init(&T, &tetris_shape_T);
    tetris_shape_init(&Z, &tetris_shape_Z);

    for (unsigned int bag = 0; bag < 5; ++bag) {
        tetris_board_push(&board, &I);
        tetris_board_push(&board, &J);
        tetris_board_push(&board, &L);
        tetris_board_push(&board, &O);
        tetris_board_push(&board, &S);
        tetris_board_push(&board, &T);
        tetris_board_push(&board, &Z);
    }
    tetris_board_show(&board);

    tetris_board_exit(&board);
    return 0;
}
