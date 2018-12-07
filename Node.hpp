#ifndef  _NODE_H_
#define  _NODE_H_
#include "Info.hpp"

template <typename Elem>
class Node {

  private :
    Info<Elem> info ;
    Node<Elem> *Father ;
    Node<Elem> *RightChild ;
    Node<Elem> *LeftChild ;
    Node<Elem> *Next ;
    Node<Elem> *Previous ;
  public :
    Node(int,Elem) ;
    Node(const Node<Elem>& ) ;
    ~Node() ;
    inline Node<Elem>& operator= (const Node<Elem>& ) ;
    inline bool operator==(Node<Elem>& ) const ;
    inline bool operator!=(Node<Elem>& ) const ;
    inline bool operator<(const Node<Elem>& ) const ;
    int getInfoIndex() const ;
    Elem getInfoValue() const ;
    Node<Elem>* getFather() const ;
    Node<Elem>* getRightChild() const ;
    Node<Elem>* getLeftChild() const ;
    Node<Elem>* getNext() const ;
    Node<Elem>* getPrevious() const ;
    void setInfoIndex(int)  ;
    void setInfoValue(Elem)  ;
    void setFather(Node<Elem>*) ;
    void setRightChild(Node<Elem>*) ;
    void setLeftChild(Node<Elem>*) ;
    void setNext(Node<Elem>*) ;
    void setPrevious(Node<Elem>*) ;
    void removeValue() ; // KO
};

template <typename Elem>
Node<Elem>::Node(int i,Elem value) :info(i,value) , Father(nullptr),RightChild(nullptr),LeftChild(nullptr),Next(nullptr),Previous(nullptr){}

template <typename Elem>
Node<Elem>::Node(const Node<Elem>& other) : info(other.info) , Father(other.Father),RightChild(other.RightChild),LeftChild(other.LeftChild),Next(other.Next),Previous(other.Previous) {}

template <typename Elem>
Node<Elem>::~Node(){}

template <typename Elem>
Node<Elem>& Node<Elem>::operator= (const Node<Elem>& other) {
  info = other.info ;
  Father = other.Father ;
  RightChild = other.RightChild ;
  LeftChild = other.LeftChild ;
  Next = other.Next ;
  Previous = other.Previous ;
  return *this ;
}
template <typename Elem>
bool Node<Elem>::operator==(Node<Elem>& other) const {
  return info == other.info ;
}
template <typename Elem>
bool Node<Elem>::operator!=(Node<Elem>& other) const {
  return !operator==(other) ;
}
template <typename Elem>
bool Node<Elem>::operator<(const Node<Elem>& other) const {
  return info < other.info ;
}
template <typename Elem>
void Node<Elem>::setInfoIndex(int i) {
  info.setIndex(i) ;
}
template <typename Elem>
void Node<Elem>::setInfoValue(Elem value) {
  info.setValue(value) ;
}
template <typename Elem>
Elem Node<Elem>::getInfoValue() const {
  return info.getValue() ;
}
template <typename Elem>
int Node<Elem>::getInfoIndex() const {
  return info.getIndex() ;
}
template <typename Elem>
Node<Elem>* Node<Elem>::getFather() const {
  return Father ;
}
template <typename Elem>
Node<Elem>* Node<Elem>::getRightChild() const {
  return RightChild ;
}
template <typename Elem>
Node<Elem>* Node<Elem>::getLeftChild() const {
  return LeftChild ;
}
template <typename Elem>
void Node<Elem>::setFather(Node<Elem>* newFather) {
   Father = newFather ;
}
template <typename Elem>
void Node<Elem>::setRightChild(Node<Elem>* newRightChild) {
   RightChild = newRightChild ;
}
template <typename Elem>
void Node<Elem>::setLeftChild(Node<Elem>* newLeftChild) {
   LeftChild = newLeftChild ;
}
template <typename Elem>
void Node<Elem>::removeValue() {
}
template <typename Elem>
void Node<Elem>::setNext(Node<Elem>* newNext) {
   Next = newNext ;
}
template <typename Elem>
void Node<Elem>::setPrevious(Node<Elem>* newPrevious) {
   Previous = newPrevious ;
}
template <typename Elem>
Node<Elem>* Node<Elem>::getNext() const {
  return Next ;
}
template <typename Elem>
Node<Elem>* Node<Elem>::getPrevious() const {
  return Previous ;
}
#endif
