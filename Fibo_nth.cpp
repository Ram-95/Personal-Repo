#include<iostream>
#include<cmath>

int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  double x = 1000000007;
  return round(pow(phi, n) / sqrt(5)) % x;
}

// Driver Code
int main ()
{
  int n = 10;

  std::cout << fib(n) << std::endl;
  return 0;
}
