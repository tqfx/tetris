#include "shape.c"
#include "board.c"

unsigned int count_A = 0;
unsigned int count_B = 0;
unsigned int count_C = 0;
unsigned int count_D = 0;
unsigned int count_I = 0;
unsigned int count_J = 0;
unsigned int count_L = 0;
unsigned int count_O = 0;
unsigned int count_S = 0;
unsigned int count_T = 0;
unsigned int count_Z = 0;
unsigned int height = 0;
unsigned int width = 0;

tetris_board board;
tetris_shape_t shape_A;
tetris_shape_t shape_B;
tetris_shape_t shape_C;
tetris_shape_t shape_D;
tetris_shape_t shape_I;
tetris_shape_t shape_J;
tetris_shape_t shape_L;
tetris_shape_t shape_O;
tetris_shape_t shape_S;
tetris_shape_t shape_T;
tetris_shape_t shape_Z;

int main(int argc, char *argv[]) {

    tetris_board_init(&board, height, width);
    tetris_shape_init(&shape_A, &tetris_shape_A);
    tetris_shape_init(&shape_B, &tetris_shape_B);
    tetris_shape_init(&shape_C, &tetris_shape_C);
    tetris_shape_init(&shape_D, &tetris_shape_D);
    tetris_shape_init(&shape_I, &tetris_shape_I);
    tetris_shape_init(&shape_J, &tetris_shape_J);
    tetris_shape_init(&shape_L, &tetris_shape_L);
    tetris_shape_init(&shape_O, &tetris_shape_O);
    tetris_shape_init(&shape_S, &tetris_shape_S);
    tetris_shape_init(&shape_T, &tetris_shape_T);
    tetris_shape_init(&shape_Z, &tetris_shape_Z);

    tetris_board_exit(&board);
    return 0;
}
