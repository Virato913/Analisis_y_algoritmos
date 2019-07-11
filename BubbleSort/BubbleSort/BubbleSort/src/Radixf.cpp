/******************************************************************************
**                                                                           **
* @file     Radixff.cpp
* @author   Alberto Villa
* @date     2019/06/03
* @brief	  
**                                                                           **
******************************************************************************/

#include "Radixf.h"

float Radixf::getMax(Vectorf v)
{
  float mx = v.m_vector[0];
  for (size_t i = 1; i < v.m_vector.size(); i++)
    if (v.m_vector[i] > mx)
      mx = v.m_vector[i];
  return mx;
}

void Radixf::expSort(Vectorf& v, int exp)
{
  vector<int> output(v.m_vector.size()), count(10);
  int i;

  for (i = 0; i < v.m_vector.size(); i++)
    count[(int)(v.m_vector[i] / exp) % 10]++;

  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (i = v.m_vector.size() - 1; i >= 0; i--)
  {
    output[count[(int)(v.m_vector[i] / exp) % 10] - 1] = v.m_vector[i];
    count[(int)(v.m_vector[i] / exp) % 10]--;
  }

  for (i = 0; i < v.m_vector.size(); i++)
    v.m_vector[i] = output[i];
}

void Radixf::sort(Vectorf& v)
{
  float m = getMax(v);

  for (int exp = 1; m / exp > 0; exp *= 10)
    expSort(v, exp);
}
