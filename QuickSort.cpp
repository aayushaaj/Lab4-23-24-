#include <iostream>
#include <vector>
#include <random>

void quickSort(std::vector<int>& arr);
void quick_Sort(std::vector<int>& arr, int low, int high);
int Partition(std::vector<int>& arr, int low, int high);

int main() {
    // Create a random number generator engine
    std::random_device rd;
    std::default_random_engine gen(rd()); // Use std::random_device to seed the generator

    // Define the distribution
    std::uniform_int_distribution<> dis(1, 100); // Generate numbers between 1 and 100

    // Number of random numbers to generate
    const int numRandomNumbers = 10;

    // Vector to store the random numbers
    std::vector<int> randomNumbers;

    // Generate and store the random numbers
    for (int i = 0; i < numRandomNumbers; ++i) {
        randomNumbers.push_back(dis(gen));
    }

    // Output the random numbers
    std::cout << "Unsorted Random numbers:" << std::endl;
    for (int number : randomNumbers) {
        std::cout << number << std::endl;
    }
    std::cout << std::endl;

    // Sort the random numbers using quicksort
    quickSort(randomNumbers);

    // Output the sorted numbers
    std::cout << "Sorted Random numbers:" << std::endl;
    for (int number : randomNumbers) {
        std::cout << number << std::endl;
    }

    return 0;
}

void quickSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return; // No need to sort
    quick_Sort(arr, 0, arr.size() - 1);
}

void quick_Sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = Partition(arr, low, high);
        quick_Sort(arr, low, pivot - 1);
        quick_Sort(arr, pivot + 1, high);
    }
}

int Partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high + 1;

    while (true) {
        while (arr[++i] < pivot) {
            if (i == high) break;
        }
        while (arr[--j] > pivot) {
            if (j == low) break;
        }
        if (i >= j) break;
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);
    return j;
}
