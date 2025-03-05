#include <cstdlib>
#include <iostream>
#include <limits>
#include <random>
#define Min_Number 0
#define Max_Number 99
int main(int argc, char const *argv[]) {
  /* Create random number */
  std::random_device rd;
  std::uniform_int_distribution<int> dist(0, 99);

  int target = dist(rd); //< Create random numer from 0 to 99
  int guess;             //<0-256
  std::cout << " Command your number " << std::endl;

  while (1) {
    if (!(std::cin >> guess)) {
      std::cerr << "[Warning]:Number must be between 0-99\n";
      std::cout << "Error encoutered, exiting..\n";
      std::cout << "Generated number was :" << target << std::endl;
      return EXIT_FAILURE; //< Exit error
    }

    /* Check the predict of guess is valid */
    if (guess < Min_Number || guess > Max_Number) {
      std::cerr << "[Warning]: Number must be between 0-99 \n";
      continue;
    }

    /* Check the predict */
    if (guess > target) {
      std::cout << "So cua toi nho hon.\n"
                << "So cua toi la:" << target << std::endl;
    } else if (guess < target) {
      std::cout << "So cua toi lon hon.\n"
                << "So cua toi la:" << target << std::endl;
    } else {
      std::cout << "Bingo you are right! " << target << "!\n";
      return EXIT_SUCCESS;
    }
  }

  return 0;
}
