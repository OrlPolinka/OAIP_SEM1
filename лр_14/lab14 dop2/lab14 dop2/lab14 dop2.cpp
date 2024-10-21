#include <iostream> 
#include <time.h>
using namespace std;

int main() {
	const int n = 5;
	int A[n][n];
	srand(time(NULL));//используем генератор случайных чисел для заполнение матрицы

    //заполняем массив значениями в соответствии с условием
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i + j >= n){
                A[i][j] = i + j + 1 - n;
            }
                
            else{
                A[i][j] = i + j + 1;
            }
        }
    }
        
    //выводим наш массив на экран:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}