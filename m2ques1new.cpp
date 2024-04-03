#include <chrono> // Include the chrono library for time measurement
#include <cstdlib> // Include the cstdlib library for dynamic memory allocation
#include <iostream> // Include the iostream library for input and output
#include <time.h> // Include the time.h library for time-related functions

using namespace std::chrono; // Use the std::chrono namespace for chrono library
using namespace std; // Use the std namespace for standard C++ components

// Function to generate random values and fill them into an array
void randomVector(int vector[], int size) {
  for (int i = 0; i < size; i++) {
    vector[i] = rand() % 100; // Generate a random value between 0 and 99
  }
}

int main() {
  unsigned long size = 100000000; // Size of the arrays
  srand(time(0)); // Seed the random number generator with the current time

  int *v1, *v2, *v3; // Declare pointers to arrays
  auto start = high_resolution_clock::now(); // Start measuring time

  v1 = (int *)malloc(size * sizeof(int)); // Allocate memory for v1
  v2 = (int *)malloc(size * sizeof(int)); // Allocate memory for v2
  v3 = (int *)malloc(size * sizeof(int)); // Allocate memory for v3

  randomVector(v1, size); // Fill v1 with random values
  randomVector(v2, size); // Fill v2 with random values

  // Add corresponding elements of v1 and v2 and store the result in v3
  for (int i = 0; i < size; i++) {
    v3[i] = v1[i] + v2[i];
  }

  auto stop = high_resolution_clock::now(); // Stop measuring time
  auto duration = duration_cast<microseconds>(stop - start); // Calculate the duration
  cout << "Time taken by function :" << duration.count() << " microseconds" // Output the duration
       << endl;
  return 0;
}
