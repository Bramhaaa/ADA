#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];  // Choosing last element as pivot
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    // Start time measurement
    auto start = high_resolution_clock::now();

    // Perform Quick Sort
    quickSort(arr, 0, N - 1);

    // End time measurement
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    // Output sorted array
    cout << "Sorted array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    cout << "Time taken by Quick Sort: " << duration.count() << " microseconds\n";

    return 0;
}
