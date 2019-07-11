/******************************************************************************
**                                                                           **
* @file     Main.cpp
* @author   Alberto Villa
* @date     2019/07/11
* @brief    
**                                                                           **
******************************************************************************/

#include "Tree.h"

int main() {
  auto* g_Tree = new Tree<int>();

  g_Tree->initialize(5);

  g_Tree->insert(11);

  g_Tree->insert(3);

  g_Tree->insert(1);

  g_Tree->remove(1);

  return 0;
}
