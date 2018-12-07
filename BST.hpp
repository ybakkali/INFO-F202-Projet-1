#ifndef  _BST_H_
#define  _BST_H_
#include "Node.hpp"
#include <iostream>

template <typename Elem>
class BST {
  public :
    BST();
    virtual ~BST() ;
    BST(const BST<Elem>&) = default ;
    BST<Elem>& operator=(const BST<Elem>&) = default ;
    typename BST<Elem>::iterator begin() const;
    // returns an iterator to the first element.
    typename BST<Elem>::iterator end() const ;
    // returns an iterator to the one past the last element.
    // when an iterator is incremented passed the end of the container
    // it should compare equal to the iterator returned by this call.

    class iterator ;
  protected :
    void setRootVal(Node<Elem>*) ;
    Node<Elem>* getRootVal() const ;
    Node<Elem>* getGlobalRoot( Node<Elem>*) const ;
    Node<Elem>* getNextNode( Node<Elem>*) const ;
    Node<Elem>* getPreviousNode( Node<Elem>*) const ;
    void fixNextPrevious(Node<Elem>* ) const ;
    void insert(int,Elem) ;
    Elem find(int) const ;
    void remove(Node<Elem>&) ; // KO
    Node<Elem>* GlobalRoot ;
  private :

};

template <typename Elem>
BST<Elem>::BST() : GlobalRoot(nullptr) {}

template <typename Elem>
BST<Elem>::~BST() {}

template <typename Elem>
Node<Elem>* BST<Elem>::getRootVal() const {
  return GlobalRoot ;
}
template <typename Elem>
void BST<Elem>::setRootVal(Node<Elem>* root) {
  GlobalRoot = root ;
}
template <typename Elem>
Node<Elem>* BST<Elem>::getGlobalRoot( Node<Elem>* node) const {
  Node<Elem>* currentNode = node ;
  if (currentNode != nullptr) {
    while (currentNode->getFather() != nullptr ) {
      currentNode = currentNode->getFather() ;
    }
  }
  return currentNode ;
}

template <typename Elem>
Node<Elem>* BST<Elem>::getNextNode( Node<Elem>* node) const {

  if (node->getRightChild() != nullptr ) {
    Node<Elem>* Next = node->getRightChild() ;
    while (Next->getLeftChild() != nullptr ) {
      Next = Next->getLeftChild() ;
    }
    return Next ;
  }
  else {
    Node<Elem>* Child_ = node ;
    Node<Elem>* Next = node->getFather() ;
    while (Next != nullptr && Next->getRightChild() == Child_){
      Child_ = Next ;
      Next = Next->getFather() ;
    }
    return Next ;
  }
}

template <typename Elem>
Node<Elem>* BST<Elem>::getPreviousNode( Node<Elem>* node) const {
  if (node->getLeftChild() != nullptr ) {
    Node<Elem>* Previous = node->getLeftChild() ;
    while (Previous->getRightChild() != nullptr ) {
      Previous = Previous->getRightChild() ;
    }
    return Previous ;
  }
  else {
    Node<Elem>* Child_ = node ;
    Node<Elem>* Previous = node->getFather() ;
    while (Previous != nullptr && Previous->getLeftChild()==Child_){
      Child_ = Previous ;
      Previous = Previous->getFather() ;
    }
    return Previous ;
  }
}

template <typename Elem>
void BST<Elem>::insert(int i,Elem newElem) {
  Node<Elem>* newNode = new Node<Elem>(i,newElem) ;
  Node<Elem>* currentNode = getRootVal() ;
  if (currentNode == nullptr) {
    setRootVal(newNode) ;
  }
  else {
    Node<Elem>* nodeCopy ;
    while (currentNode != nullptr) {
      nodeCopy = currentNode ;

      if (*newNode < *nodeCopy ) {
        currentNode = currentNode->getLeftChild() ;
      }
      else {
        currentNode = currentNode->getRightChild() ;
      }
    }

    newNode->setFather(nodeCopy);

    if ( *newNode == *nodeCopy ) {
      nodeCopy->setInfoValue(newElem) ;
    }
    else if (*newNode < *nodeCopy ) {
      nodeCopy->setLeftChild(newNode) ;
    }
    else {
      nodeCopy->setRightChild(newNode) ;
    }
  }
  fixNextPrevious(getRootVal()) ;
}
template <typename Elem>
Elem BST<Elem>::find(int index) const {
  Node<Elem>* currentNode = getRootVal() ;
  while (currentNode != nullptr && currentNode->getInfoIndex() != index) {
    if (index < currentNode->getInfoIndex() ) {
      currentNode = currentNode->getLeftChild() ;
    }
    else {
      currentNode = currentNode->getRightChild() ;
    }
  }

  if (currentNode == nullptr) {
    return false ;
  }
  else {
    return currentNode->getInfoValue() ;
  }
}
template <typename Elem>
void BST<Elem>::fixNextPrevious(Node<Elem>* currentNode) const {

  if (currentNode->getLeftChild() != nullptr ) {
    fixNextPrevious(currentNode->getLeftChild()) ;
  }

  currentNode->setNext(getNextNode(currentNode)) ;
  currentNode->setPrevious(getPreviousNode(currentNode)) ;
  //std::cout <<  currentNode->getInfoIndex() << ":" << currentNode->getInfoValue() <<std::endl  ;

  if (currentNode->getRightChild() != nullptr) {
    fixNextPrevious(currentNode->getRightChild()) ;
  }
}

template <typename Elem>
typename BST<Elem>::iterator BST<Elem>::begin() const {
  Node<Elem>* currentNode = getRootVal() ;
  while (currentNode->getLeftChild() != nullptr){
    currentNode = currentNode->getLeftChild() ;
  }
  return iterator(currentNode) ;
}
template <typename Elem>
typename BST<Elem>::iterator BST<Elem>::end() const {
  Node<Elem>* currentNode = getRootVal() ;
  while (currentNode->getLeftChild() != nullptr){
    currentNode = currentNode->getLeftChild() ;
  }
  return iterator(currentNode->getLeftChild()) ;
}
template <typename Elem>
class BST<Elem>::iterator {

  private :
  friend class BST;
  Node<Elem>* currentNode ;
  public :
  iterator() ;
  iterator(Node<Elem>*) ;
  ~iterator() ;
  iterator(const iterator&) = default ;
  iterator& operator=(const iterator&) = default;
  inline iterator& operator++ () ;
  // Advance the iterator to the next element.
  // Return a reference to yourself.
  inline iterator& operator-- () ;
  inline iterator operator++ (int);
  // Advance the iterator. But return the
  // original value.
  inline iterator operator-- (int);
  inline Elem operator* () const;
  // Return a reference to the node
  // That the current iterator represents.
  inline bool operator== (const iterator&) const ;
  inline bool operator!= (const iterator&) const ;
  // Check if two iterators represent
  // the same node (or end). return true
  // if they do not (its not equal).

};

template <typename Elem>
BST<Elem>::iterator::iterator() : currentNode(nullptr) {}

template <typename Elem>
BST<Elem>::iterator::iterator(Node<Elem>* node): currentNode(node) {}

template <typename Elem>
BST<Elem>::iterator::~iterator() {}

template <typename Elem>
typename BST<Elem>::iterator& BST<Elem>::iterator::operator++() {
  currentNode = currentNode->getNext() ;
  return *this ;
}

template <typename Elem>
typename BST<Elem>::iterator& BST<Elem>::iterator::operator--() {
  currentNode = currentNode->getPrevious() ;
  return *this ;
}

template <typename Elem>
typename BST<Elem>::iterator BST<Elem>::iterator::operator++(int) {
  iterator p(*this) ;
  currentNode = currentNode->getNext() ;
  return p ;
}

template <typename Elem>
typename BST<Elem>::iterator BST<Elem>::iterator::operator--(int) {
  iterator p(*this) ;
  currentNode = currentNode->getPrevious() ;
  return p ;
}

template <typename Elem>
Elem BST<Elem>::iterator::operator*() const{
  return currentNode->getInfoValue() ;
}

template <typename Elem>
bool BST<Elem>::iterator::operator==(const iterator& other) const {
  return currentNode == other.currentNode ;
}

template <typename Elem>
bool BST<Elem>::iterator::operator!=(const iterator& other) const {
  return !operator==(other) ;
}



#endif
