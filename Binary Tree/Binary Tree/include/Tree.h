/******************************************************************************
**                                                                           **
* @file     Tree.h
* @author   Alberto Villa
* @date     2019/07/11
* @brief    
**                                                                           **
******************************************************************************/

#pragma once

#include "Node.h"

/**
*  Description:
*     
*  Sample usage:
*     
*/
template <typename T>
class Tree
{
 public:
  /*********************************************************************************************
  * Constructors
  *********************************************************************************************/

  /**
  *  @brief Default constructor
  */
  Tree() : m_root(nullptr) {}
  
  /**
  *  @brief Default destructor
  */
  ~Tree() {
    delete m_root;
  }

  /*********************************************************************************************
  * Methods
  *********************************************************************************************/

  void
  initialize(T data) {
    m_root = new Node<T>(data);
  }

  void
  insert(T data) {
    if(m_root != nullptr) {
      insert(data, m_root);
    }
  }

  void
    remove(T data) {
    Node<T>* node = find(data, m_root);
    if(node != nullptr) {
      Node<T>* parent = node->Parent();
      if(node->Right() == nullptr && node->Left() == nullptr) {
        (parent->Left() == node) ? parent->Left(nullptr) : parent->Right(nullptr);
      }
      else if(node->Right() != nullptr && node->Left() != nullptr) {
        Node<T>* nP = node->Right()->Left();
        while(nP->Left() != nullptr) {
          nP = nP->Left();
        }
        (parent->Left() == node) ?
          parent->Left(node->Right()) : parent->Right(node->Right());

        node->Left()->Parent(nP);
        nP->Left(node->Left());
      }
      else if(node->Left() != nullptr) {
        node->Left()->Parent(parent);
        (parent->Left() == node) ?
          parent->Left(node->Left()) : parent->Right(node->Left());
      }
      else if(node->Right() != nullptr) {
        node->Right()->Parent(parent);
        (parent->Left() == node) ? parent->Left(node->Right()) : parent->Right(node->Right());
      }
    }
  }

  /**
  *  @brief 
  */
  void
  inOrder() {
    if(m_root != nullptr) {
      inOrder(m_root);
    }
  }

  /**
  *  @brief 
  */
  void
  postOrder() {
    if(m_root != nullptr) {
      postOrder(m_root);
    }
  }

  /**
  *  @brief 
  */
  void
  preOrder() {
    if(m_root != nullptr) {
      postOrder(m_root);
    }
  }

 private:
  void
  insert(T data, Node<T>* node) {
    if(data < node->Data()) {
      if(node->Left() != nullptr) {
        insert(data, node->Left());
      }
      else {
        node->Left(new Node<T>(data, node));
      }
    }
    else {
      if(node->Right() != nullptr) {
        insert(data, node->Right());
      }
      else {
        node->Right(new Node<T>(data, node));
      }
    }
  }

  Node<T>*
  find(T data, Node<T>* node) {
    if(data == node->Data()) {
      return node;
    }
    else {
      if(node->Right() != nullptr) {
        if(data > node->Right()->Data()) {
          return find(data, node->Right());
        }
      }
      else {
        return find(data, node->Left());
      }
      return nullptr;
    }
    return nullptr;
  }

  void
  inOrder(Node<T>* node) {

  }

  void
  postOrder(Node<T>* node) {

  }

  void
  preOrder(Node<T>* node) {

  }

  /*********************************************************************************************
  * Members
  *********************************************************************************************/
  /**
  *  @brief 
  */
  Node<T>* m_root = nullptr;
};
