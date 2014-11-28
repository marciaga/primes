#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;
// a function that checks whether a number is prime
bool is_prime(int n)
{
  int i;
  bool prime = true;
  // if n is 2 or 3, just set prime to true
  if (n == 2 || n == 3)
  {
    prime = true;
  }
  // if n is less than 2, it can't possibly be prime
  else if (n < 2)
  {
    prime = false;
  }
  // otherwise check whether n is divisible by any other integers
  else
  {
    for (i = 2; i <= sqrt(n); ++i) {
      // first, if n is divisible evenly by 2, it's not prime
      if (n % i == 0)
      {
        prime = false;
      }
      // if n isn't divisible evenly by 2, continue checking up until its square root
    }
  }
  return prime;
}
// a function that returns a vector of prime numbers
vector<int> primesMaker(int num)
{
  // create a vector to hold the primes
  vector<int> primes;
  int j;
  // create a really large number for checking nearly arbitrarily large integers
  int a = numeric_limits<int>::max();
  // we're going to potentially check a lot of integers...
  for (j = 2; j < a; ++j) {
    // check the size of primes
    if (primes.size() == num)
    {
      // if it's as large as we want, then end the loop
      break;
    }
    // check whether j is prime
    if (is_prime(j))
    {
      // it's prime, so push it into primes vector
      primes.push_back(j);
    }
  }
  return primes;
}

int main() {
  int primes_input;
  cout << "Please enter the number of primes you want, then press enter:\n";
  cin >> primes_input;
  vector<int> primes_wanted = primesMaker(primes_input);
  // loop through primes_wanted, printing out its contents
  int k;
  for (k = 0; k < primes_wanted.size(); ++k) {
    cout << primes_wanted.at(k) << " is prime.\n";
  }
  return 0;
}
