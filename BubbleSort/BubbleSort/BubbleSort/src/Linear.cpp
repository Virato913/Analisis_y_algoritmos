/******************************************************************************
**                                                                           **
* @file     Linear.cpp
* @author   Alberto Villa
* @date     2019/05/26
* @brief	  
**                                                                           **
******************************************************************************/

#include "Linear.h"

int
Linear::search(Vector& v, int x) {
  for(int i = 0; i < v.m_vector.size(); i++)
    if(v.m_vector[i] == x)
      return i;
  return -1;
}
