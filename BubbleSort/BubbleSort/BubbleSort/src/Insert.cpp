/******************************************************************************
**                                                                           **
* @file     Insert.cpp
* @author   Alberto Villa
* @date     2019/05/16
* @brief	  
**                                                                           **
******************************************************************************/

#include "Insert.h"

void
Insert::sort(Vector v) {
  int key = 0, j = 0;
  for(int i = 1; i < v.m_vector.size(); ++i)
  {
    key = v.m_vector[i];
    j = i - 1;

    while(j >= 0 && v.m_vector[j] > key)
    {
      v.m_vector[j + 1] = v.m_vector[j];
      j = j - 1;
    }
    v.m_vector[j + 1] = key;
  }
}
