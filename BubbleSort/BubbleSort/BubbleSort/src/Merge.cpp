/******************************************************************************
**                                                                           **
* @file     Merge.cpp
* @author   Alberto Villa
* @date     2019/05/26
* @brief	  
**                                                                           **
******************************************************************************/

#include "Merge.h"


void
Merge::sort(Vector& v, int l, int r) {
  if(l < r)
  {
    int m = l + (r - l) / 2;

    sort(v, l, m);
    sort(v, m + 1, r);

    merge(v, l, m, r);
  }
}

void
Merge::merge(Vector& v, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  Vector L, R;

  for(i = 0; i < n1; i++)
    L.m_vector.push_back(v.m_vector[l + i]);
  for(j = 0; j < n2; j++)
    R.m_vector.push_back(v.m_vector[m + 1 + j]);

  i = 0;
  j = 0; 
  k = l; 
  while(i < n1 && j < n2)
  {
    if(L.m_vector[i] <= R.m_vector[j])
    {
      v.m_vector[k] = L.m_vector[i];
      i++;
    }
    else
    {
      v.m_vector[k] = R.m_vector[j];
      j++;
    }
    k++;
  }

  while(i < n1)
  {
    v.m_vector[k] = L.m_vector[i];
    i++;
    k++;
  }

  while(j < n2)
  {
    v.m_vector[k] = R.m_vector[j];
    j++;
    k++;
  }
}
