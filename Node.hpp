#ifndef  _NODE_H_
#define  _NODE_H_
#include "Info.hpp"

template <typename U>
class Node {

  private :
    Info<U> info ;
    Node<U> *Father ;
    Node<U> *RightChild ;
    Node<U> *LeftChild ;
  public :
    Node(unsigned int,U) ;
    Node(const Node<U>& ) ;
    ~Node() ;
    Node<U>& operator=(const Node<U>&) ;
    inline bool operator==(Node<U>& ) const ;
    inline bool operator!=(Node<U>& ) const ;
    inline bool operator<(const Node<U>& ) const ;
    //Getters
    Info<U> getInfo() const ;
    Node<U>* getFather() const ;
    Node<U>* getRightChild() const ;
    Node<U>* getLeftChild() const ;
    //Setters
    void setInfoValue(U)  ;
    void setFather(Node<U>*) ;
    void setRightChild(Node<U>*) ;
    void setLeftChild(Node<U>*) ;
};

template <typename U>
Node<U>::Node(unsigned i,U value) :info(i,value) , Father(nullptr),RightChild(nullptr),LeftChild(nullptr){}

template <typename U>
Node<U>::Node(const Node<U>& other) : info(other.info),Father(other.Father),RightChild(nullptr),LeftChild(nullptr){

    if (other.RightChild) {
        Node<U>* r = new Node<U>(*other.RightChild) ;
        r->setFather(this);
        this->setRightChild(r);
    }
    if (other.LeftChild) {
        Node<U>* l = new Node<U>(*other.LeftChild) ;
        l->setFather(this);
        this->setLeftChild(l);
    }
}

template <typename U>
Node<U>::~Node(){

    if (this->LeftChild) {
        delete this->LeftChild ;
    }
    if (this->RightChild) {
        delete this->RightChild ;
    }
}

template <typename U>
Node<U>& Node<U>::operator=(const Node<U>& other) {

  if (this != &other) {

    info = other.info ;
    Father = other.Father ;
    if (other.RightChild) {
        Node<U>* r = new Node<U> (*other.RightChild) ;
        r->setFather(this);
        this->setRightChild(r);
    }
    if (other.LeftChild) {
        Node<U>* l = new Node<U> (*other.LeftChild) ;
        l->setFather(this);
        this->setLeftChild(l);
    }
  }
  return *this ;
}
template <typename U>
bool Node<U>::operator==(Node<U>& other) const {
  return info == other.info ;
}
template <typename U>
bool Node<U>::operator!=(Node<U>& other) const {
  return !operator==(other) ;
}
template <typename U>
bool Node<U>::operator<(const Node<U>& other) const {
  return info < other.info ;
}

template <typename U>
void Node<U>::setInfoValue(U value) {
  info.setValue(value) ;
}
template <typename U>
Info<U> Node<U>::getInfo() const {
  return info ;
}
template <typename U>
Node<U>* Node<U>::getFather() const {
  return Father ;
}
template <typename U>
Node<U>* Node<U>::getRightChild() const {
  return RightChild ;
}
template <typename U>
Node<U>* Node<U>::getLeftChild() const {
  return LeftChild ;
}
template <typename U>
void Node<U>::setFather(Node<U>* newFather) {
   Father = newFather ;
}
template <typename U>
void Node<U>::setRightChild(Node<U>* newRightChild) {
   RightChild = newRightChild ;
}
template <typename U>
void Node<U>::setLeftChild(Node<U>* newLeftChild) {
   LeftChild = newLeftChild ;
}

#endif
