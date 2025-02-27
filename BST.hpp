#ifndef  _BST_H_
#define  _BST_H_
#include "Node.hpp"

template <typename Elem>
class BST {
  public :
    BST();
    BST(const BST<Elem>&) ;
    virtual ~BST() ;
    BST<Elem>& operator=(const BST<Elem>&) ;

    class iterator ;
    typename BST<Elem>::iterator begin () {return iterator(this,getFirst());}
    typename BST<Elem>::iterator end ()   {return iterator(this,getLast());}

  protected :
    void setRootVal(Node<Elem>*) ;
    Node<Elem>* getRootVal() const ;
    Node<Elem>* getGlobalRoot( Node<Elem>*) const ;
    Node<Elem>* getNext( Node<Elem>*) const ;
    Node<Elem>* getPrevious( Node<Elem>*) const ;
    Node<Elem>* getFirst() const;
    Node<Elem>* getLast() const ;
    void insert(unsigned int,Elem) ;
    Elem find(unsigned int) const ;
  private :
    Node<Elem>* root ;
};

template <typename Elem>
BST<Elem>::BST() : root(nullptr) {}

template <typename Elem>
BST<Elem>::BST(const BST<Elem>& other) : root(other.root) {

    if (other.root != nullptr) {
        this->root = new Node<Elem>(*other.root);
    }
}

template <typename Elem>
BST<Elem>& BST<Elem>::operator=(const BST<Elem>& other) {

    if (this != &other) {
        this->root = other->root ;
    }
    return *this;
}

template <typename Elem>
BST<Elem>::~BST() {
    delete this->root ;
}

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
  return root ;
}
template <typename Elem>
void BST<Elem>::setRootVal(Node<Elem>* Root) {
  root = Root ;
}
template <typename Elem>
Node<Elem>* BST<Elem>::getGlobalRoot(Node<Elem>* node) const {

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
void BST<Elem>::insert(unsigned int i,Elem newElem) {

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
      delete newNode ;
    }
    else if (*newNode < *nodeCopy ) {
      nodeCopy->setLeftChild(newNode) ;
    }
    else {
      nodeCopy->setRightChild(newNode) ;
    }
  }
}
template <typename Elem>
Elem BST<Elem>::find(unsigned int index) const {

  Node<Elem>* currentNode = getRootVal() ;
  while (currentNode != nullptr && currentNode->getInfo().getIndex() != index) {
    if (index < currentNode->getInfo().getIndex() ) {
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
    return currentNode->getInfo().getValue() ;
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
  inline iterator& operator-- () ;
  inline iterator operator++ (int);
  inline iterator operator-- (int);
  inline Node<Elem>& operator* () const;
  inline bool operator== (const iterator&) const ;
  inline bool operator!= (const iterator&) const ;
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
Node<Elem>& BST<Elem>::iterator::operator*() const{
  return *currentNode ;
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
