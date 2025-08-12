#include <iostream>
using namespace std;
int main() {
    int a[10][10], transpose[10][10], row, col;
    cout << "Enter rows and columns: ";
    cin >> row >> col;
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < row; i++)
   for (int j = 0; j < col; j++)
            cin >> a[i][j];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            transpose[j][i] = a[i][j];
    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++)
            cout << transpose[i][j] << " ";
        cout << endl;
    }
    return 0;
}

