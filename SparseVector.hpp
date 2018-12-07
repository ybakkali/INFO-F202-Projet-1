#ifndef  _SPARSEVECTOR_H_
#define  _SPARSEVECTOR_H_
#include "BST.hpp"
#include "Vector.hpp"

template <typename Elem>
class SparseVector : public Vector<Elem> , public BST<Elem> {
  public :
  explicit SparseVector(unsigned int) ;
  ~SparseVector()=default;
  const Elem get (int) const noexcept override ;
  void set (int,Elem) noexcept override ;

};

template <typename Elem>
SparseVector<Elem>::SparseVector(unsigned int size) : Vector<Elem>(size) {}

template <typename Elem>
const Elem SparseVector<Elem>::get(int index) const noexcept {
  return this->find(index) ;
}

template <typename Elem>
void SparseVector<Elem>::set(int index,Elem value) noexcept{
  this->insert(index,value) ;
}



#endif
