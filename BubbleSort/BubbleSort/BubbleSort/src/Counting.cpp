/******************************************************************************
**                                                                           **
* @file     Counting.cpp
* @author   Alberto Villa
* @date     2019/05/30
* @brief	  
**                                                                           **
******************************************************************************/

#include "Counting.h"
#include <algorithm>

void Counting::sort(Vector& v)
{
  int max = *std::max_element(v.m_vector.begin(), v.m_vector.end());
  int min = *std::min_element(v.m_vector.begin(), v.m_vector.end());
  int range = max - min + 1;

  vector<int> count(range), output(v.m_vector.size());
  for(int i = 0; i < v.m_vector.size(); i++)
    count[v.m_vector[i] - min]++;

  for(int i = 1; i < count.size(); i++)
    count[i] += count[i - 1];

  for(int i = v.m_vector.size() - 1; i >= 0; i--)
  {
    output[count[v.m_vector[i] - min] - 1] = v.m_vector[i];
    count[v.m_vector[i] - min]--;
  }

  for(int i = 0; i < v.m_vector.size(); i++)
    v.m_vector[i] = output[i];
}
