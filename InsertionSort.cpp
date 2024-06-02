#include <iostream>
#include <iostream>
#include <vector>
#include <random>

int main() {
    // Create a random number generator engine
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator

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
    std::cout << "Random numbers:" << std::endl;
    for (int number : randomNumbers) {
        std::cout << number << std::endl;
    }

    return 0;
}
