#include<stdio.h>
#include<stdlib.h>


void output(char **arr,int rows,int cols);
char* check(char **board,int rows,int cols);


int main(){
    unsigned int rows = 8, cols = 8;
    unsigned int row_input = 4, col_input = 4;


    char **chessboard = malloc(rows * sizeof(char *));

    if(chessboard == NULL){
        printf("Error Allocating Memory for Chessboard");
        return 1;   //exit error 1
    }

    for(int i = 0; i < rows; i++){
        chessboard[i] = malloc(cols * sizeof(char));
        if(chessboard[i] == NULL){
            printf("Error Allocating Memory for Chessboard[%d]", i);
            return 2;
        }
    }

    //print_chessboard();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            chessboard[i][j] = '-';     //*(*chessboard + i) + j)
        }
    }

    for(int i = 1; i <= 8; i++){
        do{
            if(row_input < 1 || row_input > 8 || col_input < 1 || col_input > 8) printf("Unsupported Input, Try Again\n");
            printf("Enter position of Queen_%d (1-8)\n", i);
            scanf(" %u,%u", &row_input, &col_input);
        } while(row_input < 1 || row_input > 8 || col_input < 1 || col_input > 8);
        chessboard[row_input-1][col_input-1] = 'Q';
    }

    output(chessboard,rows, cols);

    printf("\n");

    printf("%s\n", check(chessboard, rows, cols));

}


void output(char **arr,int rows,int cols){
    for(int i = 0; i <  rows; i++) {
        printf("\n");
        for(int j = 0; j < cols; j++)
            printf("%c ", arr[i][j]);
    }
}


char* check(char **board,int rows,int cols){
    for(int i = 0; i < rows; i++) {                             //rows
        for(int j = 0; j < cols; j++){
            if(board[i][j] == 'Q'){
                int l = j;
                if(l != 0){
                    l--;
                    while(l >= 0){
                        if(board[i][l] == 'Q') return "Loss";
                        l--;

                    }
                }
                l = j;
                if(l != cols){
                    l++;
                    while(l < cols){
                        if(board[i][l] == 'Q') return "Loss";
                        l++;
                    }
                }
            }
        }
    }

    for(int i = 0; i < rows; i++) {                             //cols
        for(int j = 0; j < cols; j++){
            if(board[j][i] == 'Q'){
                int k = j;
                if(k != 0){
                    k--;
                    while(k >= 0){
                        if(board[k][i] == 'Q') return "Loss";
                        k--;

                    }
                }
                k = j;
                if(k != rows){
                    k++;
                    while(k < rows){
                        if(board[k][i] == 'Q') return "Loss";
                        k++;

                    }
                }
            }
        }
    }


    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            if(board[i][j] == 'Q'){
                int a = i + 1;
                int b = j + 1;


                while(a < rows && b < cols){
                    if(board[a][b] == 'Q') return "Loss";
                    a += 1;
                    b += 1;
                }

                a = i - 1;
                b = j - 1;
                while(a >= 0 && b >= 0){
                    if (board[a][b] == 'Q') return "Loss";
                    a -= 1;
                    b -= 1;
                }

                a = i - 1;
                b = j + 1;
                while(a >= 0 && b < cols){
                    if (board[a][b] == 'Q') return "Loss";
                    a -= 1;
                    b += 1;
                }

                a = i + 1;
                b = j - 1;
                while(a < rows && b >= 0){
                    if(board[a][b] == 'Q') return "Loss";
                    a += 1;
                    b -= 1;
                }

            }
        }
    }
    return "Victory!";
}