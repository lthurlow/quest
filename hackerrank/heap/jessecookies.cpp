#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// from stack overflow, basically to keep vector sorted
// this will make algorithm easier to choose cookies
void keep_sorted (std::vector< int > &cont, int value)
{
  std::vector< int >::iterator it =
  std::lower_bound (cont.begin ( ), cont.end ( ), value, std::less< int > ( ));
  cont.insert (it, value); // insert before iterator it
}

// return the number of operations completed.
int updateCookies (std::vector< int > &cookies, int sweetness, int &counter)
{
  // if first cookie is greater than sweetness, we are done
  // the array should never be empty, we should return -1
  if (cookies[0] >= sweetness)
  {
    return 0;
  }
  else
  {
    // catch the case where the previous time we added cookies and now we cant do any more
    // if we did recursion this would be our base case.
    if (cookies.size ( ) == 1)
    {
      counter = -1;
      return -1;
    }
    else
    {
      // lets try first with the greedy approach and see if that works
      int c0 = cookies[0];
      int c1 = cookies[1];
      cookies.erase (cookies.begin ( ));
      cookies.erase (cookies.begin ( ));
      keep_sorted (cookies, c0 + (2 * c1));
      counter += 1;
      return 1;
    }
  }
}

int main ( )
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int num_cookies, sweetness;
  int ret = scanf ("%d %d", &num_cookies, &sweetness); // throw away return code
  std::vector< int > cookies;                          // our cookie array
  for (int i = 0; i < num_cookies; ++i)
  { // read until all cookies are ready
    int cookie;
    ret = scanf ("%d", &cookie);
    keep_sorted (cookies, cookie); // sorted vector
  }
  int num_operations = 0;
  // updateCookies will return 0 when done, and -1 if impossible, otherwise
  // the value will always be greater than 0
  while (updateCookies (cookies, sweetness, num_operations) > 0)
    ;
  printf ("%d\n", num_operations);
  return 0;
}
