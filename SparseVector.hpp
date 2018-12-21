#ifndef  _SPARSEVECTOR_H_
#define  _SPARSEVECTOR_H_
#include "BST.hpp"
#include "Vector.hpp"
#include <stdexcept>

template <typename Elem>
class SparseVector : public Vector<Elem> , public BST<Elem> {
  public :
    SparseVector(unsigned int) ;
    SparseVector(const SparseVector&) ;
    ~SparseVector() = default;
    SparseVector& operator= (const SparseVector&) ;
    const Elem get (unsigned int) const noexcept override ;
    void set (unsigned int,Elem) noexcept override ;
    unsigned int size() const noexcept override;
};

template <typename Elem>
SparseVector<Elem>::SparseVector(unsigned int size) :
                            Vector<Elem>(size),BST<Elem>() {}

template <typename Elem>
SparseVector<Elem>::SparseVector(const SparseVector<Elem>& other) :
                            Vector<Elem>(other.VectorSize),BST<Elem>(other) {}

template <typename Elem>
SparseVector<Elem>& SparseVector<Elem>::operator=(const SparseVector& other) {
    if (this != &other) {
        Vector<Elem>::operator=(other.VectorSize) ;
        BST<Elem>::operator=(other) ;
    }
    return *this ;
}

template <typename Elem>
unsigned int SparseVector<Elem>::size() const noexcept {
  return this->VectorSize ;
}

template <typename Elem>
const Elem SparseVector<Elem>::get(unsigned int index) const noexcept {

    if (index >= size()) {
        throw std::invalid_argument("Search : index out of range") ;
    }

    return this->find(index) ;
}

template <typename Elem>
void SparseVector<Elem>::set(unsigned int index,Elem value) noexcept{

    if (index >= size()) {
        throw std::invalid_argument("Insert : index out of range") ;
    }
    else {
        this->insert(index,value) ;
    }
}


#endif
