/******************************************************************************
**                                                                           **
* @file     Node.h
* @author   Alberto Villa
* @date     2019/07/11
* @brief    
**                                                                           **
******************************************************************************/

#pragma once

/**
*  Description:
*     
*  Sample usage:
*     
*/
template <typename T>
class Node
{
 public:
  /*********************************************************************************************
  * Constructors
  *********************************************************************************************/

  /**
  *  @brief Default constructor
  */
  Node() : m_left(nullptr),
    m_right(nullptr),
    m_parent(nullptr) {}
  
  /**
  *  @brief 
  *  @param 
  */
  Node(T data) : m_data(data),
    m_left(nullptr),
    m_right(nullptr),
    m_parent(nullptr) {}

  /**
  *  @brief 
  *  @param 
  *  @param 
  */
  Node(T data, Node* parent) : m_data(data),
    m_left(nullptr),
    m_right(nullptr),
    m_parent(parent) {}

  /**
  *  @brief 
  *  @param 
  */
  Node(const Node& r) {
    Data(r.Data());
    Left(r.Left());
    Right(r.Right());
    Parent(r.Parent());
  }

  /**
  *  @brief Default destructor
  */
  ~Node() {
    if(Left() != nullptr) {
      delete Left();
    }
    if(Right() != nullptr) {
      delete Right();
    }
  }

  /*********************************************************************************************
  * Methods
  *********************************************************************************************/
  
  /**
  *  @brief 
  */
  T
  Data() const { return m_data; }

  /**
  *  @brief 
  */
  void Data(T val) { m_data = val; }

  /**
  *  @brief 
  */
  Node<T>*
  Left() const { return m_left; }

  /**
  *  @brief 
  */
  void
  Left(Node<T>* val) { m_left = val; }

  /**
  *  @brief 
  */
  Node<T>*
  Right() const { return m_right; }

  /**
  *  @brief 
  */
  void
  Right(Node<T>* val) { m_right = val; }

  /**
  *  @brief 
  */
  Node<T>*
  Parent() const { return m_parent; }

  /**
  *  @brief 
  */
  void
  Parent(Node<T>* val) { m_parent = val; }

  /*********************************************************************************************
  * Members
  *********************************************************************************************/
 private:
  /**
  *  @brief 
  */
  T m_data;

  /**
  *  @brief 
  */
  Node<T>* m_left = nullptr;
  
  /**
  *  @brief 
  */
  Node<T>* m_right = nullptr;
  
  /**
  *  @brief 
  */
  Node<T>* m_parent = nullptr;
};
