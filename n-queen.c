#include <stdio.h>
#define N 10

int board[N][N];
int solutions = 0;

void print_board(int n) {
    int i, j;
    printf("Solution %d:\n", solutions++);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_safe(int row, int col, int n) {
    int i, j;
    for(i = 0; i < col; i++) {
        if(board[row][i]) return 0;
    }
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j]) return 0;
    }
    for(i = row, j = col; j >= 0 && i < n; i++, j--) {
        if(board[i][j]) return 0;
    }
    return 1;
}

void solve(int col, int n) {
    int i;
    if(col == n) {
        print_board(n);
        return;
    }
    for(i = 0; i < n; i++) {
        if(is_safe(i, col, n)) {
            board[i][col] = 1;
            solve(col + 1, n);
            board[i][col] = 0;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the chessboard: ");
    scanf("%d", &n);
    solve(0, n);
    printf("Total solutions: %d", solutions);
    return 0;
}
