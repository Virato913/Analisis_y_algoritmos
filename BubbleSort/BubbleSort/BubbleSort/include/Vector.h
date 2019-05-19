/******************************************************************************
**                                                                           **
* @file     Vector.h
* @author   Alberto Villa
* @date     2019/05/09
* @brief	  Vector object that will be filled with numbers
**                                                                           **
******************************************************************************/

#pragma once

#include "Prerequisites.h"

/**
*  Description:
*
*  Sample usage:
*
*/
namespace Type {
  enum E {
    kAscending = 0,
    kDescending,
    kRandom,
    kCount
  };
}

/**
*  Description:
*     
*  Sample usage:
*     
*/
class Vector
{
 public:
  /*********************************************************************************************
  * Constructors
  *********************************************************************************************/

  /**
  *  @brief Default constructor
  */
  Vector();
  
  /**
  *  @brief Default destructor
  */
  ~Vector();
  
  /*********************************************************************************************
  * Operators Overloads
  *********************************************************************************************/

  

  /*********************************************************************************************
  * Methods
  *********************************************************************************************/

  /**
  *  @brief Empties vector
  */
  void
  clear();

  /**
  *  @brief Fills vector with random elements
  *  @param Number of elements to fill it with
  *  @param How it'll fill (ascending, descending, random)
  */
  void
  fill(int num, Type::E type);

  /**
  *  @brief Print vector's contents
  */
  void
  print();

  /*********************************************************************************************
  * Members
  *********************************************************************************************/

  /**
  *  @brief Vector containing all elements
  */
  vector<int> m_vector;
};
