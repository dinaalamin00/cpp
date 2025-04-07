#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int value;
    bool visited;
    bool captured;
} t_board;

typedef struct {
    int capsum;
    int captured_i[2]; // Stores positions of captured dice
    int captured_j[2];
    int captured_count;
    bool cap_flag;
} t_cap;

void copy_board(t_board dest[3][3], t_board src[3][3]) {
    memcpy(dest, src, sizeof(t_board) * 9);
}

bool is_full(t_board b[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j].value == 0) return false;
        }
    }
    return true;
}

int hash_count(t_board b[3][3]) {
    int hash = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hash = ((hash * 10) + b[i][j].value) % (1 << 30);
        }
    }
    return hash;
}

void check_cap(t_board b[3][3], t_cap *cap, int i, int j, int ii, int jj) {
    if (i < 0 || j < 0 || ii < 0 || jj < 0 || 
        i > 2 || ii > 2 || j > 2 || jj > 2) {
        return;
    }
    
    if (b[i][j].value == 0 || b[ii][jj].value == 0) {
        return;
    }

    int sum = b[i][j].value + b[ii][jj].value;
    if (sum <= 6 && sum > cap->capsum) {
        cap->cap_flag = true;
        cap->capsum = sum;
        cap->captured_i[0] = i;
        cap->captured_j[0] = j;
        cap->captured_i[1] = ii;
        cap->captured_j[1] = jj;
        cap->captured_count = 2;
    }
}

t_cap captured(t_board b[3][3], int i, int j) {
    t_cap cap = {0};
    
    // Check all possible adjacent pairs
    check_cap(b, &cap, i-1, j, i, j-1);
    check_cap(b, &cap, i-1, j, i, j+1);
    check_cap(b, &cap, i, j-1, i, j+1);
    check_cap(b, &cap, i, j-1, i+1, j);
    check_cap(b, &cap, i, j+1, i+1, j);
    check_cap(b, &cap, i+1, j, i-1, j);
    
    return cap;
}

void simulate(t_board board[3][3], int* sum, int depth) {
    if (depth == 0 || is_full(board)) {
        *sum = (*sum + hash_count(board)) % (1 << 30);
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j].value == 0) {
                t_cap cap = captured(board, i, j);
                
                if (cap.cap_flag) {
                    // Capture move
                    t_board new_board[3][3];
                    copy_board(new_board, board);
                    new_board[i][j].value = cap.capsum;
                    for (int k = 0; k < cap.captured_count; k++) {
                        new_board[cap.captured_i[k]][cap.captured_j[k]].value = 0;
                    }
                    simulate(new_board, sum, depth-1);
                }
                
                // Non-capture move
                t_board new_board[3][3];
                copy_board(new_board, board);
                new_board[i][j].value = 1;
                simulate(new_board, sum, depth-1);
            }
        }
    }
}

int main() {
    t_board board[3][3];
    int depth, sum = 0;
    
    scanf("%d", &depth);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &board[i][j].value);
            board[i][j].visited = false;
            board[i][j].captured = false;
        }
    }
    
    simulate(board, &sum, depth);
    printf("%d\n", sum);
    return 0;
}