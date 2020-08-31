// Listing 10-5 and 10-6

#include "isprime.h"
#include <stdlib.h>

/**
 * power() - 
 * @x:
 * @y:
 * @p:
 *
 * (Long Description)
 * This function is in Listing 10-5.
 *
 * Return: 
 */
static unsigned long long power(unsigned long long x, unsigned long long y,
                                unsigned long long p) {
  unsigned long long result = 1;
  x %= p;

  while (y) {
    if (y & 1) result = (result * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return result;
}

/**
 * miller_rabin_test() -
 * @d:
 * @n:
 *
 * (Long Description)
 * This function is in Listing 10-5.
 *
 * Return: 
 */
static bool miller_rabin_test(unsigned long long d, unsigned long long n) {
  unsigned long long a = 2 + rand() % (n - 4);
  unsigned long long x = power(a, d, n);

  if (x == 1 || x == n - 1) return true;

  while (d != n - 1) {
    x = (x * x) % n;
    d *= 2;

    if (x == 1) return false;
    if (x == n - 1) return true;
  }
  return false;
} 

/**
 * is_prime() - Interface to the Miller-Rabin primality test algorithm
 * @n: the number to test
 * @k: the number of times to perform the test
 *
 * This function is in Listing 10-5.
 *
 * This functions uses a fixed number of iterations of the Miller-Rabin test
 * and reports whether the input values are probably prime or definitely not prime.
 *
 * Return: 
 */
bool is_prime(unsigned long long n, unsigned int k) {
  if (n <= 1 || n == 4) return false;
  if (n <= 3) return true;

  unsigned long long d = n - 1;
  while (d % 2 == 0) d /= 2;

  for (; k != 0; --k) {
    if (!miller_rabin_test(d, n)) return false;
  }
  return true;
}
