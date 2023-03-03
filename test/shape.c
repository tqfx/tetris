#include "../shape.c"
#include <string.h>
#include <stdio.h>

static void tetris_shape_show(tetris_shape_t *ctx) {
    unsigned int count = 0;
    int board[4][4 * 4 * 2];
    memset(board, ' ', sizeof(int) * 4 * 4 * 4 * 2);
    do {
        for (unsigned int i = 0; i < ctx->shape->count; ++i) {
            board[ctx->point[i][0]][ctx->point[i][1] + count * 4] = ctx->shape->name;
        }
        ++count;
    } while (tetris_shape_rotate(ctx));
    do {
        for (unsigned int i = 0; i < ctx->shape->count; ++i) {
            board[ctx->point[i][0]][ctx->point[i][1] + count * 4] = ctx->shape->name;
        }
        ++count;
    } while (tetris_shape_reverse(ctx));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4 * 4 * 2; ++j) {
            printf("%c", board[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int main(void) {
    tetris_shape_t ctx;

    tetris_shape_init(&ctx, &tetris_shape_I);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_J);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_L);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_O);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_S);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_T);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_Z);
    tetris_shape_show(&ctx);

    return 0;
}
