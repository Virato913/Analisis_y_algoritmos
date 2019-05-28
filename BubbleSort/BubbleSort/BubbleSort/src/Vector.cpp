/******************************************************************************
**                                                                           **
* @file     Vector.cpp
* @author   Alberto Villa
* @date     2019/05/09
* @brief	  Implementation of Vector.h
**                                                                           **
******************************************************************************/

#include "Vector.h"
#include <iostream>
#include <random>

Vector::Vector() {

}

Vector::~Vector() {
  clear();
}

void
Vector::clear() {
  m_vector.clear();
}

void
Vector::fill(int num, Type::E type) {
  if(type != Type::kCount) {
    m_vector.reserve(num);
    switch(type) {
    case Type::kAscending:
      for(int i = 0; i < num; ++i) {
        m_vector.push_back(i);
      }
      break;
    case Type::kDescending:
      for(int i = 0; i < num; ++i) {
        m_vector.push_back(num - i - 1);
      }
      break;
    case Type::kRandom:
      std::mt19937 rng{ std::random_device{}() };
      for(int i = 0; i < num; ++i) {
        std::uniform_int_distribution<> n(0, num);
        m_vector.push_back(n(rng));
      }
      break;
    }
  }
}

void
Vector::print() {
  for(auto& it : m_vector) {
    std::cout << it;
  }
  std::cout << std::endl;
}
