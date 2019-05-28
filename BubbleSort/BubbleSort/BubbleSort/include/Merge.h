/******************************************************************************
**                                                                           **
* @file     Merge.h
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
namespace Merge
{
  void
    sort(Vector& v, int l, int r);

  void
    merge(Vector& v, int l, int m, int r);
};
