/******************************************************************************
**                                                                           **
* @file     Radix.cpp
* @author   Alberto Villa
* @date     2019/05/30
* @brief
**                                                                           **
******************************************************************************/

#include "Radix.h"

int Radix::getMax(Vector v)
{
  int mx = v.m_vector[0];
  for(size_t i = 1; i < v.m_vector.size(); i++)
    if(v.m_vector[i] > mx)
      mx = v.m_vector[i];
  return mx;
}

void Radix::expSort(Vector& v, int exp)
{
  vector<int> output(v.m_vector.size()), count(10);
  int i;

  for(i = 0; i < v.m_vector.size(); i++)
    count[(v.m_vector[i] / exp) % 10]++;

  for(i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for(i = v.m_vector.size() - 1; i >= 0; i--)
  {
    output[count[(v.m_vector[i] / exp) % 10] - 1] = v.m_vector[i];
    count[(v.m_vector[i] / exp) % 10]--;
  }

  for(i = 0; i < v.m_vector.size(); i++)
    v.m_vector[i] = output[i];
}

void Radix::sort(Vector& v)
{
  int m = getMax(v);

  for(int exp = 1; m / exp > 0; exp *= 10)
    expSort(v, exp);
}
