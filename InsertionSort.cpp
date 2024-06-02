
#include <iostream>
#include <vector>
#include <random>

// Function to perform insertion sort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; //second element is set to the key
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    // Create a random number generator engine
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator

    // Define the distribution
    std::uniform_int_distribution<> dis(1, 100); // Generate numbers between 1 and 100

    // Number of random numbers to generate
    const int numRandomNumbers = 20;

    // Vector to store the random numbers
    std::vector<int> randomNumbers;

    // Generate and store the random numbers
    for (int i = 0; i < numRandomNumbers; ++i) {
        randomNumbers.push_back(dis(gen));
    }

    // Output the unsorted random numbers
    std::cout << "Unsorted numbers:" << std::endl;
    for (int number : randomNumbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Sort the random numbers using insertion sort
    insertionSort(randomNumbers);

    // Output the sorted numbers
    std::cout << "Sorted numbers:" << std::endl;
    for (int number : randomNumbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
