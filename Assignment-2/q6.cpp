#include <iostream>
using namespace std;

#define MAX 100
struct Triplet {
    int row;
    int col;
    int val;
};
void display(Triplet mat[], int size) {
    cout << "Row Col Val\n";
    for (int i = 0; i < size; i++)
        cout << mat[i].row << "   " << mat[i].col << "   " << mat[i].val << endl;
}
int transpose(Triplet mat[], Triplet result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i].row = mat[i].col;
        result[i].col = mat[i].row;
        result[i].val = mat[i].val;
    }
    return size;
}
int addSparse(Triplet a[], int sizeA, Triplet b[], int sizeB, Triplet result[]) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            result[k] = a[i];
            result[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        } else if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }

    while (i < sizeA) result[k++] = a[i++];
    while (j < sizeB) result[k++] = b[j++];

    return k;
}

int multiplySparse(Triplet a[], int sizeA, Triplet b[], int sizeB, Triplet result[]) {
    int k = 0;

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (a[i].col == b[j].row) {
                int row = a[i].row;
                int col = b[j].col;
                int val = a[i].val * b[j].val;
                bool found = false;
                for (int m = 0; m < k; m++) {
                    if (result[m].row == row && result[m].col == col) {
                        result[m].val += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result[k].row = row;
                    result[k].col = col;
                    result[k].val = val;
                    k++;
                }
            }
        }
    }

    return k;
}
int main() {
   
    Triplet A[MAX] = {
        {0, 0, 1}, {0, 2, 2},
        {1, 1, 3},
        {2, 0, 4}, {2, 2, 5}
    };
    int sizeA = 5;
    Triplet B[MAX] = {
        {0, 0, 6}, {0, 2, 7},
        {1, 1, 8},
        {2, 0, 9}, {2, 2, 10}
    };
    int sizeB = 5;
    cout << "\nMatrix A:\n";
    display(A, sizeA);

    cout << "\nMatrix B:\n";
    display(B, sizeB);
    Triplet transA[MAX];
    int transSize = transpose(A, transA, sizeA);
    cout << "\nTranspose of Matrix A:\n";
    display(transA, transSize);
    Triplet sum[MAX];
    int sumSize = addSparse(A, sizeA, B, sizeB, sum);
    cout << "\nAddition of A + B:\n";
    display(sum, sumSize);
    Triplet product[MAX];
    int prodSize = multiplySparse(A, sizeA, B, sizeB, product);
    cout << "\nMultiplication of A * B:\n";
    display(product, prodSize);

    return 0;
}

