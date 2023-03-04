#include "../shape.c"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static void tetris_shape_show(tetris_shape_t *ctx) {
    unsigned int height = 0;
    for (unsigned int i = 0; i < ctx->shape->count; ++i) {
        if (ctx->shape->point[i][0] + 2 > height) {
            height = ctx->shape->point[i][0] + 2;
        }
        if (ctx->shape->point[i][1] + 2 > height) {
            height = ctx->shape->point[i][1] + 2;
        }
    }
    unsigned int const width = ctx->shape->step * height * 2;
    int *const board = (int *)malloc(sizeof(int) * height * width);
    memset(board, ' ', sizeof(int) * height * width);
    unsigned int count = 0;
    do {
        for (unsigned int i = 0; i < ctx->shape->count; ++i) {
            board[ctx->point[i][0] * width + height * count + ctx->point[i][1]] = ctx->shape->name;
        }
        ++count;
    } while (tetris_shape_rotate(ctx));
    do {
        for (unsigned int i = 0; i < ctx->shape->count; ++i) {
            board[ctx->point[i][0] * width + height * count + ctx->point[i][1]] = ctx->shape->name;
        }
        ++count;
    } while (tetris_shape_reverse(ctx));
    for (unsigned int i = 0; i < height; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            printf("%c", board[i * width + j]);
        }
        putchar('\n');
    }
    free(board);
}

int main(void) {
    tetris_shape_t ctx;

    tetris_shape_init(&ctx, &tetris_shape_A);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_B);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_C);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_D);
    tetris_shape_show(&ctx);

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

    tetris_shape_init(&ctx, &tetris_shape_U);
    tetris_shape_show(&ctx);

    tetris_shape_init(&ctx, &tetris_shape_X);
    tetris_shape_show(&ctx);

    return 0;
}
