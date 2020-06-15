/*
 * next_prime.cpp
 *
 * Find the next prime number that comes after
 * the user's submitted n, up to 1998, whose
 * next prime is 1999.
 *
 * Required linked libraries: cmath
 *
 * author: Ryan Morehouse
 * license: MIT
 */

#include <math.h>
#include <iostream>
#include <sstream>
#define MIN 1
#define MAX 1998


void error_msg()
{
  std::cout << "Usage: next_prime.o [n]\n";
  std::cout << "[n] is a positive integer less than 1999\n";
}

bool isPrime(int number)
{
  if(number < 2)
    return false;

  bool is_prime_local = true;
  if(number > 2)
  {
    double max_range = ceil(sqrt((double)number));
    int i = 2;
    while(is_prime_local)
    {
      if(number % i == 0)
        is_prime_local = false;
      else if(i > max_range)
        break;
      else
        i += 1;
    }
  }

  return is_prime_local;
}


int main(int argc, char *argv[]) {
  // user input
  int n;

  // verify there is an arg
  if(argc < 2) {
    error_msg();
    return 1;
  }

  // verify arg is within limits
  std::istringstream ss(argv[1]);
  if (!(ss >> n)) {
    error_msg();
    return 1;
  } else if (n < MIN || n > MAX) {
    error_msg();
    return 1;
  }

  // simple cases
  if(n == 1)
  {
    std::cout << "2\n";
    return 0;
  }
  else if(n == 2)
  {
    std::cout << "3\n";
    return 0;
  }

  // iteration flag
  bool prime_found = false;

  // test values
  int test_max = n * 2;
  int i = n + 1;

  while(!prime_found)
  {
    if(i == test_max)
    {
      std::cout << "There has been a fatal programming error.\n";
      std::cout << "A prime should have been found but was not.\n";
      return 1;
    }
    prime_found = isPrime(i);
    if(prime_found)
      break;
    else if(i % 2 == 0)
      i += 1; // i is even, go to next odd
    else
      i += 2; // i is odd, go to next odd
  }

  std::cout << i << std::endl;
  return 0;
}


