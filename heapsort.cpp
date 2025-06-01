#include <iostream>
#include <vector>
#include <chrono>  // For measuring time

using namespace std;
using namespace std::chrono;

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int N, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2;// right = 2*i + 2

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < N && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected subtree
        heapify(arr, N, largest);
    }
}

// Main function to perform heap sort
void heapSort(vector<int>& arr, int N) {
    // Build a max heap
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // Extract elements one by one from heap
    for (int i = N - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << "\n";
}

int main() {
    int N;
    cout << "Enter number of elements: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the elements:\n";
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // Start time
    auto start = high_resolution_clock::now();

    heapSort(arr, N);

    // End time
    auto end = high_resolution_clock::now();

    // Calculate time taken
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Sorted array:\n";
    printArray(arr);

    cout << "Time taken by Heap Sort: " << duration.count() << " microseconds\n";

    return 0;
}
