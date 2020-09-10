//  Sequences.c
//  
//
//  Created by Rodrigo Garcia and Jesus Dominguez on 09/09/2020.
//

#include"Sequences.h"

/**
 * Returns the value of the fibonacci sequence at index n calculated sequentially
 * @param
 *      n (long long int):
 *          Index of the fibonacci sequence
 * @return long long int value
*/

long long int Sequences_sfibo(long long int n)
{
  long long int i=0, j=1, temp;
  long long int count;

  for(count = 0;count < n;count++)
    {
      temp = i + j;
      i = j;
      j = temp;
    }

  return i;
  
}


/**
 * Returns the value of the fibonacci sequence at index n calculated recursively
 * @param
 *      n (long long int):
 *          Index of the fibonacci sequence
 * @return long long int value
*/
long long int Sequences_rfibo(long long int n)
{
  if(n < 2)
  {
    return n;
  }

  else
  {
    return Sequences_rfibo(n-2) + Sequences_rfibo(n-1);
  }
  
}
