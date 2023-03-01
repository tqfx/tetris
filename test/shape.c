#include "../shape.c"
#include <string.h>
#include <stdio.h>

static void tetris_shape_show(tetris_shape *shape) {
    unsigned int count = 0;
    int board[4][4 * 4 * 2];
    memset(board, ' ', sizeof(int) * 4 * 4 * 4 * 2);
    do {
        for (unsigned int i = 0; i < shape->count; ++i) {
            board[shape->point[i][0]][shape->point[i][1] + count * 4] = shape->shape;
        }
        ++count;
    } while (tetris_shape_rotate(shape));
    do {
        for (unsigned int i = 0; i < shape->count; ++i) {
            board[shape->point[i][0]][shape->point[i][1] + count * 4] = shape->shape;
        }
        ++count;
    } while (tetris_shape_reverse(shape));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4 * 4 * 2; ++j) {
            printf("%c", board[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int main(void) {
    tetris_shape shape;

    tetris_shape_init(&shape, TETRIS_I);
    tetris_shape_show(&shape);

    tetris_shape_init(&shape, TETRIS_J);
    tetris_shape_show(&shape);

    tetris_shape_init(&shape, TETRIS_L);
    tetris_shape_show(&shape);

    tetris_shape_init(&shape, TETRIS_O);
    tetris_shape_show(&shape);

    tetris_shape_init(&shape, TETRIS_S);
    tetris_shape_show(&shape);

    tetris_shape_init(&shape, TETRIS_T);
    tetris_shape_show(&shape);

    tetris_shape_init(&shape, TETRIS_Z);
    tetris_shape_show(&shape);

    return 0;
}
