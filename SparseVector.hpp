#ifndef  _SPARSEVECTOR_H_
#define  _SPARSEVECTOR_H_

template <typename Elem>
class SparseVector : public Vector , public BST {

  explicit SparseVector(int) ;
  ~SparseVector();

};

template <typename Elem>
SparseVector<Elem>::SparseVector(int size) : Vect<Elem>() , VectorSize(size) {}





#endif
