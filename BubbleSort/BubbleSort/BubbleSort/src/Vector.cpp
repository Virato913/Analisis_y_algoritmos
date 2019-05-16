/******************************************************************************
**                                                                           **
* @file     Vector.cpp
* @author   Alberto Villa
* @date     2019/05/09
* @brief	  Implementation of Vector.h
**                                                                           **
******************************************************************************/

#include "Vector.h"

Vector::Vector() {

}

Vector::~Vector() {

}

void
Vector::clear() {
  m_vector.clear();
}

void
Vector::fill(int num, Type::E type) {
  if(type != Type::kRandom) {
    m_vector.reserve(num);
    switch(type) {
    case Type::kAscending:
      for(int i = 0; i < num; ++i) {
        m_vector.push_back(i);
      }
      break;
    case Type::kDescending:
      for(int i = 0; i < num; ++i) {
        m_vector.push_back(num - i);
      }
      break;
    case Type::kRandom:
      break;
    }
  }
}
