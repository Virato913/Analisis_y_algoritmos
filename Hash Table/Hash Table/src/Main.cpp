#include "HashTable.h"

int main()
{
  HashTable::Table<int, int> test;

  test.insertNode(1, 1);
  test.insertNode(10, 5);

  test.get(10);

  test.deleteNode(1);

  return 0;
}
