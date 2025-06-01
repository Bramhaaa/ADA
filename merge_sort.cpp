#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to merge two subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    
    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

    // Measure start time
    auto start = high_resolution_clock::now();

    // Perform merge sort
    mergeSort(arr, 0, N - 1);

    // Measure end time
    auto end = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<microseconds>(end - start);

    // Output sorted array
    cout << "Sorted array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    cout << "Time taken by Merge Sort: " << duration.count() << " microseconds\n";

    return 0;
}

