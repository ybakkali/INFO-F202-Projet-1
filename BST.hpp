#ifndef  _BST_H_
#define  _BST_H_
#include "Node.hpp"
#include <iostream>

template <typename Elem>
class BST {
  public :
    BST();
    virtual ~BST() ;
    class iterator ;
    BST(const BST<Elem>&) = default ;
    BST<Elem>& operator=(const BST<Elem>&) = default ;


    typename BST<Elem>::iterator begin () {return iterator(this,First);}
    // returns an iterator to the first element.
    typename BST<Elem>::iterator end ()   {return iterator(this,Last);}
    // returns an iterator to the one past the last element.
    // when an iterator is incremented passed the end of the container
    // it should compare equal to the iterator returned by this call.
  protected :
    void setRootVal(Node<Elem>*) ;
    Node<Elem>* getRootVal() const ;
    Node<Elem>* getGlobalRoot( Node<Elem>*) const ;
    Node<Elem>* getNext( Node<Elem>*) const ;
    Node<Elem>* getPrevious( Node<Elem>*) const ;
    Node<Elem>* getFirst() const;
    Node<Elem>* getLast() const ;
    void fixNextPrevious(Node<Elem>*) const ;
    void insert(unsigned int,Elem) ;
    Elem find(unsigned int) const ;
    void remove(Node<Elem>&) ; // KO
  private :
    Node<Elem>* BinarySearchTree ;
    Node<Elem>* First ;   // Pointer to first item
    Node<Elem>* Last ;    // Pointer to next field of last item
};

template <typename Elem>
BST<Elem>::BST() : BinarySearchTree(nullptr) , First(nullptr) , Last(nullptr) {}

template <typename Elem>
BST<Elem>::~BST() {}

template <typename Elem>
 Node<Elem>* BST<Elem>::getFirst() const {
  Node<Elem>* currentNode = getRootVal() ;
  while (currentNode->getLeftChild() != nullptr){
    currentNode = currentNode->getLeftChild() ;
  }
  return currentNode ;
}
template <typename Elem>
Node<Elem>* BST<Elem>::getLast() const {
  Node<Elem>* currentNode = getRootVal() ;
  while (currentNode->getLeftChild() != nullptr){
    currentNode = currentNode->getLeftChild() ;
  }
  return currentNode->getLeftChild() ;
}

template <typename Elem>
Node<Elem>* BST<Elem>::getRootVal() const {
  return BinarySearchTree ;
}
template <typename Elem>
void BST<Elem>::setRootVal(Node<Elem>* root) {
  BinarySearchTree = root ;
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
Node<Elem>* BST<Elem>::getNext( Node<Elem>* node) const {

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
Node<Elem>* BST<Elem>::getPrevious( Node<Elem>* node) const {
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
void BST<Elem>::insert(unsigned i,Elem newElem) {
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
  First = getFirst() ;
  Last =  getLast() ;
  //fixNextPrevious(getRootVal()) ;
}
template <typename Elem>
Elem BST<Elem>::find(unsigned int index) const {
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

  currentNode->setNext(getNext(currentNode)) ;
  currentNode->setPrevious(getPrevious(currentNode)) ;


  if (currentNode->getRightChild() != nullptr) {
    fixNextPrevious(currentNode->getRightChild()) ;
  }
}

template <typename Elem>
class BST<Elem>::iterator {

  private :
  friend class BST;
  BST<Elem>* BinaryTree ;
  Node<Elem>* currentNode ;
  public :
  iterator() ;
  iterator(BST<Elem>*,Node<Elem>*) ;
  ~iterator() ;
  iterator(const iterator&) = default ;
  iterator& operator=(const iterator&) = default;
  inline iterator& operator++ () ;
  // Advance the iterator to the next element. Return a reference to yourself.
  inline iterator& operator-- () ;
  inline iterator operator++ (int);
  // Advance the iterator. But return the original value.
  inline iterator operator-- (int);
  inline Elem operator* () const;
  // Return a reference to the node that the current iterator represents.
  inline bool operator== (const iterator&) const ;
  inline bool operator!= (const iterator&) const ;
  // Check if two iterators represent the same node (or end). return true
  // if they do not (its not equal).

};

template <typename Elem>
BST<Elem>::iterator::iterator() : BinaryTree(nullptr),currentNode(nullptr) {}

template <typename Elem>
BST<Elem>::iterator::iterator(BST<Elem>* bst,Node<Elem>* node): BinaryTree(bst), currentNode(node) {}

template <typename Elem>
BST<Elem>::iterator::~iterator() {}

template <typename Elem>
typename BST<Elem>::iterator& BST<Elem>::iterator::operator++() {
  currentNode = BinaryTree->getNext(currentNode) ;
  return *this ;
}

template <typename Elem>
typename BST<Elem>::iterator& BST<Elem>::iterator::operator--() {
  currentNode = BinaryTree->getPrevious(currentNode) ;
  return *this ;
}

template <typename Elem>
typename BST<Elem>::iterator BST<Elem>::iterator::operator++(int) {
  iterator p(*this) ;
  currentNode = BinaryTree->getNext(currentNode) ;
  return p ;
}

template <typename Elem>
typename BST<Elem>::iterator BST<Elem>::iterator::operator--(int) {
  iterator p(*this) ;
  currentNode = BinaryTree->getPrevious(currentNode) ;
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
