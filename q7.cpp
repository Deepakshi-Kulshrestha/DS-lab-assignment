#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int l, int m, int r) {
    int leftSize = m - l + 1;
    int rightSize = r - m;

    int* left = new int[leftSize];
    int* right = new int[rightSize];

    for (int i = 0; i < leftSize; i++) left[i] = arr[l + i];
    for (int j = 0; j < rightSize; j++) right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l, inv_count = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            inv_count += (leftSize - i);
        }
    }

    while (i < leftSize) arr[k++] = left[i++];
    while (j < rightSize) arr[k++] = right[j++];

    delete[] left;
    delete[] right;

    return inv_count;
}

int countInversions(int arr[], int l, int r) {
    int inv_count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        inv_count += countInversions(arr, l, m);
        inv_count += countInversions(arr, m + 1, r);
        inv_count += mergeAndCount(arr, l, m, r);
    }
    return inv_count;
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countInversions(arr, 0, n - 1);
    cout << "Number of inversions: " << result << endl;

    return 0;
}

