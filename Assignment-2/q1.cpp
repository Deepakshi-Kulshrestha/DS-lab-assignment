#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    int* arr = new int[size];  
    cout << "Enter " << size << " elements in sorted order:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int result = binarySearch(arr, size, key);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;
    delete[] arr;  
    return 0;
}

