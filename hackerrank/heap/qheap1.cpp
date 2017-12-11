/*
This question is designed to help you get a better understanding of basic heap operations.
You will be given queries of  types:

"1 v " - Add an element  to the heap.
"2 v " - Delete the element  from the heap.
"3" - Print the minimum of all the elements in the heap.

NOTE: It is guaranteed that the element to be deleted will be there in the heap. Also, at any
instant, only distinct elements will be in the heap.

Input Format

The first line contains the number of queries, Q.
Each of the next Q lines contains a single query of any one of the 3 above mentioned types.

Constraints
1 <= Q <= 10^5
-10^9 <= v <= 10^9


Output Format

For each query of type 3, print the minimum value on a single line.

Sample Input

5
1 4
1 9
3
2 4
3
Sample Output

4
9
Explanation

After the first 2 queries, the heap contains {4, 9}. Printing the minimum gives 4 as the output.
Then, the query deletes 4 from the heap, and the 5th query gives 9 as the output.

*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int printMin (vector< int > &heap)
{
  // in order to not enforce a default minimum, use first value,
  // but verify vector is not empty
  if (heap.size ( ) == 0)
  {
    return 0;
  }
  // use the first value to start with
  int min = heap[0];
  for (int i = 0; i != heap.size ( ); ++i)
  {
    if (heap[i] < min)
    {
      min = heap[i];
    }
  }
  return min;
}

int main ( )
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int inputs, optcode, value;
  std::vector< int > heap;
  int ret = scanf ("%d", &inputs); // we will not use return status, assume good formatting
  int min = 0; // set to zero incase first instruction is 3, otherwise min gets set on insert
  for (int i = 0; i < inputs; ++i)
  {
    ret = scanf ("%d", &optcode);
    // if optcode is 3 print minimum value, not sure what they want for if heap is empty, 0?
    if (optcode == 3)
    {
      // printf("%d\n", printMin(heap));
      printf ("%d\n", min);
      // otherwise read in the value to operate on, 1 for insert, 2 for delete
    }
    else
    {
      ret = scanf (" %d", &value);
      if (optcode == 1)
      {
        if (heap.size ( ) < 1 || value < min)
        {
          min = value;
        }
        heap.push_back (value);
      }
      else
      {
        // guarenteed to only have unique values.
        int min2 = heap[0]; // assuming valid inputs, can only delete if element is there
        bool del = min == value ? true : false; // if we are deleting minimum value
        std::vector< int >::iterator delpoint;  // element to delete after finding new min

        if (del)
        {
          if (min == min2)
          {
            // if heap.size is 1, then value will be deleted, and will be reset on insert.
            if (heap.size ( ) != 1)
            {
              min2 = heap[1];
            }
          }
        }
        for (std::vector< int >::iterator i = heap.begin ( ); i != heap.end ( ); ++i)
        {
          if (del)
          { // hopefully compiler will be smart and remove if false
            // if the value is the next smallest, should be set to min2
            // assumes that min != min2 initially.
            if (*i > min and *i < min2)
            {
              min2 = *i;
            }
          }
          if (*i == value)
          {
            // can only shortcut if we are not deleting min, if we are, need O(n) to find new min
            if (!del)
            {
              heap.erase (i);
              break;
            }
            else
            {
              delpoint = i;
            }
          }
        }
        if (del)
        {
          heap.erase (delpoint);
          min = min2;
        }
      }
    }
  }
  return 0; // program exited fine.
}
