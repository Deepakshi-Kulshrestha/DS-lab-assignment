#include <iostream>
using namespace std;

class MatrixStorage {
    int *D;        // Diagonal
    int *T;        // Tri-diagonal
    int *L;        // Lower Triangular
    int *U;        // Upper Triangular
    int *S;        // Symmetric
    int n;
public:
    MatrixStorage(int size) {
        n = size;
        D = new int[n];

        T = new int[3 * n - 2];

        L = new int[n * (n + 1) / 2];

        U = new int[n * (n + 1) / 2];

        S = new int[n * (n + 1) / 2];
    }

    ~MatrixStorage() {
        delete[] D;
        delete[] T;
        delete[] L;
        delete[] U;
        delete[] S;
    }

    // --- Diagonal Matrix ---
    void setDiagonal(int i, int j, int val) {
        if (i == j) D[i] = val;
    }

    int getDiagonal(int i, int j) {
        return (i == j) ? D[i] : 0;
    }

    // --- Tri-diagonal Matrix ---
    void setTriDiagonal(int i, int j, int val) {
        if (i - j == 1) T[i - 1] = val;
        else if (i == j) T[n - 1 + i] = val;
        else if (j - i == 1) T[2 * n - 1 + i] = val;
    }

    int getTriDiagonal(int i, int j) {
        if (i - j == 1) return T[i - 1];
        else if (i == j) return T[n - 1 + i];
        else if (j - i == 1) return T[2 * n - 1 + i];
        else return 0;
    }

    // --- Lower Triangular Matrix ---
    void setLowerTriangular(int i, int j, int val) {
        if (i >= j) L[i * (i + 1) / 2 + j] = val;
    }

    int getLowerTriangular(int i, int j) {
        if (i >= j) return L[i * (i + 1) / 2 + j];
        else return 0;
    }

    // --- Upper Triangular Matrix ---
    void setUpperTriangular(int i, int j, int val) {
        if (i <= j) U[i * n - (i * (i - 1)) / 2 + (j - i)] = val;
    }

    int getUpperTriangular(int i, int j) {
        if (i <= j) return U[i * n - (i * (i - 1)) / 2 + (j - i)];
        else return 0;
    }

    // --- Symmetric Matrix ---
    void setSymmetric(int i, int j, int val) {
        if (i >= j) S[i * (i + 1) / 2 + j] = val;
        else S[j * (j + 1) / 2 + i] = val;
    }

    int getSymmetric(int i, int j) {
        if (i >= j) return S[i * (i + 1) / 2 + j];
        else return S[j * (j + 1) / 2 + i];
    }
};

// --- Main Function ---
int main() {
    int n = 4;
    MatrixStorage mat(n);

    // Sample data for each type
    cout << "Setting Diagonal Matrix:\n";
    for (int i = 0; i < n; i++)
        mat.setDiagonal(i, i, i + 1);

    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat.getDiagonal(i, j) << " ";
        cout << endl;
    }

    cout << "\nSetting Tri-diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        if (i > 0) mat.setTriDiagonal(i, i - 1, -1);   // Sub-diagonal
        mat.setTriDiagonal(i, i, 4);                   // Diagonal
        if (i < n - 1) mat.setTriDiagonal(i, i + 1, -1); // Super-diagonal
    }

    cout << "Tri-diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat.getTriDiagonal(i, j) << " ";
        cout << endl;
    }

    cout << "\nSetting Lower Triangular Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            mat.setLowerTriangular(i, j, i + j);

    cout << "Lower Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat.getLowerTriangular(i, j) << " ";
        cout << endl;
    }

    cout << "\nSetting Upper Triangular Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            mat.setUpperTriangular(i, j, i + j);

    cout << "Upper Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat.getUpperTriangular(i, j) << " ";
        cout << endl;
    }

    cout << "\nSetting Symmetric Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            mat.setSymmetric(i, j, i + j);

    cout << "Symmetric Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat.getSymmetric(i, j) << " ";
        cout << endl;
    }

    return 0;
}

