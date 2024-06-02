#include <iostream>
#include <vector>
#include <random>

void quickSort(std::vector<int>& );
int Partition(std::vector<int>&,int ,int);
void quick_Sort(std::vector<int> &, int , int );

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
    std::cout<<std::endl;
    quickSort(randomNumbers);
    return 0;
}

void quickSort(std::vector<int>& arr)
{
    int n = arr.size();
    int low=0;
    int high= n;
    int pivot;
    if(low<high)
    {
        int pivot=Partition(arr,low,high);
        quick_Sort(arr,low, pivot-1);
        quick_Sort(arr,pivot+1,high);
    }
}
void quick_Sort(std::vector<int> &a, int i, int j)
{

}

