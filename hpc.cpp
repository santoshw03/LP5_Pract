#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return i + 1;
}

void quicksort(int arr[], int start, int end) {
    int index;
    if (start < end) {
        index = partition(arr, start, end);
#pragma omp parallel sections
        {
#pragma omp section
            {
                quicksort(arr, start, index - 1);
            }
#pragma omp section
            {
                quicksort(arr, index + 1, end);
            }
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of elements you want to Enter\n";
    cin >> N;
    int arr[N];
    cout << "Enter the array: \n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    quicksort(arr, 0, N - 1);
    cout << "Array after Sorting is: \n";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
