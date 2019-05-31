/******************************************************************************
**                                                                           **
* @file     Bucket.cpp
* @author   Alberto Villa
* @date     2019/05/30
* @brief
**                                                                           **
******************************************************************************/

#include "Bucket.h"

void Bucket::sort(Vector& v)
{
  int dim = v.m_vector.size();
  vector<float> b[dim];

  for(int i = 0; i < v.m_vector.size(); i++)
  {
    int bi = v.m_vector.size() * v.m_vector[i];
    b[bi].push_back(v.m_vector[i]);
  }

  for(int i = 0; i < v.m_vector.size(); i++)
    sort(b[i].begin(), b[i].end());

  int index = 0;
  for(int i = 0; i < v.m_vector.size(); i++)
    for(int j = 0; j < b[i].size(); j++)
      v.m_vector[index++] = b[i][j];
}
