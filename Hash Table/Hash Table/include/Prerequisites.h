/******************************************************************************
**                                                                           **
* @file     Prerequisites.h
* @author   Alberto Villa
* @date     2019/07/10
* @brief    
**                                                                           **
******************************************************************************/

#pragma once

#include <cmath>
#include <map>
#include <vector>

/**
*  Description:
*     
*  Sample usage:
*     
*/
namespace HashTable
{
  /**
  *  @brief 
  */
  template <typename T,
            typename A = std::allocator<T>>
  using Vector = std::vector<T, A>;

  /**
  *  @brief 
  */
  template<typename K,
           typename T,
           typename P = std::less<K>,
           typename A = std::allocator<std::pair<const K, T>>>
  using Map = std::map<K, T, P, A>;
}
