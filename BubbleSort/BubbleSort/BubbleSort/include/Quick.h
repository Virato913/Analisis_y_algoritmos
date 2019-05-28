/******************************************************************************
**                                                                           **
* @file     Quick.h
* @author   Alberto Villa
* @date     2019/05/26
* @brief	  
**                                                                           **
******************************************************************************/

#pragma once

#include "Vector.h"

/**
*  Description:
*     
*  Sample usage:
*     
*/
namespace Quick
{
  void
    sort(Vector& v, int q, int r);

  int
    partition(Vector& v, int start, int end);
};
