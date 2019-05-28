/******************************************************************************
**                                                                           **
* @file     Binary.cpp
* @author   Alberto Villa
* @date     2019/05/26
* @brief	  
**                                                                           **
******************************************************************************/

#include "Binary.h"

int
Binary::search(Vector& v, int l, int r, int x) {
  if(r >= l)
  {
    int m = l + (r - l) / 2;

    if(v.m_vector[m] == x)
      return m;

    if(v.m_vector[m] > x)
      return search(v, l, m - 1, x);

    return search(v, m + 1, r, x);
  }

  return -1;
}
