#include <iostream>
#include <vector>
using namespace std;

// Directions
#define LEFT -1
#define RIGHT 1

// Function to print a permutation
void printPermutation(const vector<int>& perm) {
    for (int num : perm)
        cout << num << " ";
    cout << "\n";
}

// Function to find the largest mobile element index
int getMobileElementIndex(const vector<int>& perm, const vector<int>& dir, int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        int neighbor = i + dir[i];
        if (neighbor >= 0 && neighbor < n && perm[i] > perm[neighbor]) {
            if (mobile == 0 || perm[i] > perm[mobile])
                mobile = i;
        }
    }
    return mobile;
}

// Main function to generate permutations using Johnson–Trotter
void generatePermutations(int n) {
    vector<int> perm(n);
    vector<int> dir(n, LEFT);

    for (int i = 0; i < n; i++)
        perm[i] = i + 1;

    printPermutation(perm);

    while (true) {
        int mobileIdx = getMobileElementIndex(perm, dir, n);
        if (mobileIdx == 0 && (mobileIdx + dir[mobileIdx] < 0 || mobileIdx + dir[mobileIdx] >= n))
            break;

        int neighborIdx = mobileIdx + dir[mobileIdx];
        swap(perm[mobileIdx], perm[neighborIdx]);
        swap(dir[mobileIdx], dir[neighborIdx]);

        // After swap, update mobileIdx to new position
        mobileIdx = neighborIdx;

        // Reverse directions of elements greater than the moved one
        for (int i = 0; i < n; i++) {
            if (perm[i] > perm[mobileIdx])
                dir[i] = -dir[i];
        }

        printPermutation(perm);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements for permutation: ";
    cin >> n;

    generatePermutations(n);

    return 0;
}
