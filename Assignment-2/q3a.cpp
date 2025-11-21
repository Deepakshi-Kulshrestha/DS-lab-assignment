#include <iostream>
using namespace std;
int findMissingLinear(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return size + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissingLinear(arr, size);
    cout << "(a) Missing number (Linear Search): " << missing << endl;

    return 0;
}

