#ifndef  _SPARSEVECTOR_H_
#define  _SPARSEVECTOR_H_
#include "BST.hpp"
#include "Vector.hpp"

template <typename Elem>
class SparseVector : public Vector<Elem> , public BST<Elem> {
  public :
    explicit SparseVector(unsigned int) ;
    ~SparseVector() = default;
    const Elem get (unsigned int) const noexcept override ;
    void set (unsigned int,Elem) noexcept override ;
    unsigned int size() const noexcept override;
  private :
    unsigned int VectorSize ;
};

template <typename Elem>
SparseVector<Elem>::SparseVector(unsigned int size) : Vector<Elem>() , VectorSize(size) {}

template <typename Elem>
unsigned int SparseVector<Elem>::size() const noexcept {
  return VectorSize ;
}

template <typename Elem>
const Elem SparseVector<Elem>::get(unsigned int index) const noexcept {
  if (index >= size()) {
    throw std::out_of_range("Index out of range") ;
  }
  return this->find(index) ;
}

template <typename Elem>
void SparseVector<Elem>::set(unsigned int index,Elem value) noexcept{
  if (index >= size()) {
    throw std::out_of_range("Index out of range") ;
  }
  this->insert(index,value) ;
}



#endif
