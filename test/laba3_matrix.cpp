#include <iostream>
#include <vector>

using namespace std;

int main(){
    int rows, columns, zeros = 0, sum = 0, flag = 0, points = 0;
    cin >> rows >> columns;
    if ((rows > 10)||(columns > 10)) cout << "Размерности массива не соответствуют условиям задачи";
    else{
        vector<vector<int>> matrix;
        matrix.resize(rows);
        for (int i = 0; i < rows; i++){
            matrix[i].resize(columns);
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if ((i + j) % 2 == 0){
                    matrix[i][j] = 1;
                }
                else{
                    cin >> matrix[i][j];
                }
            }
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (matrix[i][j] == 0){
                    zeros += 1; 
                }
            }
            if (zeros != 0){
                for (int j = 0; j < columns; j++){
                    sum += matrix[i][j];
                }
            }
            zeros = 0;
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        cout << sum << ' ';
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                for (int m = 0; m < columns; m++){
                    if (matrix[i][j] > matrix[i][m]) break;
                    if (m == columns - 1) flag = 1;
                }
                if (flag == 1){
                    for (int m = 0; m < rows; m++){
                        if (matrix[i][j] < matrix[m][j]) break;
                        if (m == rows - 1) flag = 2;
                    }
                }
                if (flag == 2) points += 1;
                flag = 0;
            }
        }
        cout << points;
    }
    return 0;
}