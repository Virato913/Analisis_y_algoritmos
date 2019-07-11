/******************************************************************************
**                                                                           **
* @file     Vectorf.cpp
* @author   Alberto Villa
* @date     2019/06/03
* @brief	  
**                                                                           **
******************************************************************************/

#include "Vectorf.h"
#include <iostream>

Vectorf::Vectorf()
{

}

Vectorf::~Vectorf()
{
  clear();
}

void Vectorf::clear()
{
  m_vector.clear();
}

void Vectorf::fill(int n)
{
  m_vector.reserve(n);
  for (int i = 0; i < n; ++i) {
    m_vector.push_back((std::rand() % 1000 + 1) + (float)std::rand() / RAND_MAX);
  }
}

void Vectorf::print()
{
  for (auto& it : m_vector) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
}
