/******************************************************************************
**                                                                           **
* @file     Bubble.cpp
* @author   Alberto Villa
* @date     2019/05/16
* @brief	  
**                                                                           **
******************************************************************************/

#include "Bubble.h"

void
Bubble::sort(Vector v) {
  int temp = 0;
  for(int i = 0; i < v.m_vector.size() - 1; ++i) {
    for(int j = 0; j < v.m_vector.size() - i - 1; ++j) {
      if(v.m_vector[j] > v.m_vector[j + 1]) {
        temp = v.m_vector[j];
        v.m_vector[j] = v.m_vector[j + 1];
        v.m_vector[j + 1] = temp;
      }
    }
  }
}
