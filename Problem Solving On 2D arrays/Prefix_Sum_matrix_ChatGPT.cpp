// This program first reads in the size of the array and then the elements of the array.
// It then calculates the prefix sum matrix by using the following formula:

// prefixSum[i][j] = arr[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1]

// This formula takes into account the prefix sum of the elements above and to the left of the current element,
// and subtracts the prefix sum of the elements above and to the left of the current element that were double counted.

// Finally, the program prints out the prefix sum matrix.

// --By ChatGPT

#include <iostream>

using namespace std;

const int N = 100;

int n, m;
int arr[N][N];
int prefixSum[N][N];

int main() {
  cin >> n >> m;

  // Read in the array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  // Calculate the prefix sum matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      prefixSum[i][j] = arr[i][j];
      if (i > 0) prefixSum[i][j] += prefixSum[i-1][j];
      if (j > 0) prefixSum[i][j] += prefixSum[i][j-1];
      if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
    }
  }

  // Print the prefix sum matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << prefixSum[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}