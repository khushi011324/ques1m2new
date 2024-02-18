#include <chrono>
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std::chrono;
using namespace std;

// Function to fill an array with random values between 0 and 99
void randomVector(int vector[], int size) {
  for (int i = 0; i < size; i++) {
    vector[i] = rand() % 100;
  }
}

int main() {
  // Set the size of the vectors
  unsigned long size = 100000000;

  // Seed the random number generator with the current time
  srand(time(0));

  // Declare pointers for three integer arrays
  int *v1, *v2, *v3;

  // Record the start time using chrono library
  auto start = high_resolution_clock::now();

  // Allocate memory for the three arrays
  v1 = (int *)malloc(size * sizeof(int));
  v2 = (int *)malloc(size * sizeof(int));
  v3 = (int *)malloc(size * sizeof(int));

  // Fill v1 and v2 with random values
  randomVector(v1, size);
  randomVector(v2, size);

  // Perform element-wise addition of v1 and v2, storing the result in v3
  for (int i = 0; i < size; i++) {
    v3[i] = v1[i] + v2[i];
  }

  // Record the stop time using chrono library
  auto stop = high_resolution_clock::now();

  // Calculate the duration of the operation
  auto duration = duration_cast<microseconds>(stop - start);

  // Print the time taken by the operation
  cout << "Time taken by function: " << duration.count() << " microseconds"
       << endl;

  // Free the allocated memory
  free(v1);
  free(v2);
  free(v3);

  // Return 0 to indicate successful completion
  return 0;
}
