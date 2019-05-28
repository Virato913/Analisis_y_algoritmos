/******************************************************************************
**                                                                           **
* @file     Quick.cpp
* @author   Alberto Villa
* @date     2019/05/26
* @brief	  
**                                                                           **
******************************************************************************/

#include "Quick.h"


void
Quick::sort(Vector& v, int p, int r) {
  if(p < r)
  {
    int q = partition(v, p, r);
    sort(v, p, q - 1);
    sort(v, q + 1, r);
  }
}

int
Quick::partition(Vector& v, int start, int end) {
  unsigned int pivot = v.m_vector[start];
  unsigned int from_left = start + 1;
  unsigned int from_right = end;
  unsigned int tmp;

  while(from_left != from_right) {
    if(v.m_vector[from_left] <= pivot) from_left++;
    else {
      while((from_left != from_right) && (pivot < v.m_vector[from_right])) from_right--;
      tmp = v.m_vector[from_right];
      v.m_vector[from_right] = v.m_vector[from_left];
      v.m_vector[from_left] = tmp;
    }
  }

  if(v.m_vector[from_left] > pivot) from_left--;
  v.m_vector[start] = v.m_vector[from_left];
  v.m_vector[from_left] = pivot;

  return (from_left);
}
