#include "../shape.c"
#include "../board.c"

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
        tetris_board_show(&board);
    }

    tetris_board_exit(&board);
    return 0;
}
