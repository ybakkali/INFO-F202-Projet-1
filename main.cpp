#include "SparseVector.hpp"

template <typename V>
void Parcours(Vector<V>& v) {
    for (unsigned int i = 0 ; i < v.size() ; i++) {
        std::cout << "Vecteur [" << i << "] = " << v.get(i) << std::endl;
    }
}

template <typename K>
void ParcoursT(BST<K>& tree) {
    std::cout << "Index        Value" << std::endl;
    for (typename BST<K>::iterator it = tree.begin() ; it != tree.end() ; ++it) {
        std::cout << "( " << (*it)->getInfoIndex() << "     ,    " << (*it)->getInfoValue() << " )" << std::endl;
    }
}

int main() {

  Node<int> nd(1,10);
  Node<int> nn(2,111) ;
  nd.setLeftChild(&nn);
  Node<int> tmp(nd);
  std::cout<< nd.getLeftChild() << std::endl ;
  std::cout<< nd.getInfoValue() << std::endl ;
  std::cout<< tmp.getLeftChild() << std::endl ;
  SparseVector<int> V(40) ;
  SparseVector<int> P(V) ;
  V.set(10,5) ;
  V.set(15,60) ;
  V.set(5,11) ;
  V.set(30,0) ;
  V.set(3,19) ;
  V.set(3,100) ;
  std::cout<< "V" << std::endl ;
  ParcoursT(V) ;
  std::cout<< "P" << std::endl ;
  ParcoursT(P) ;
  //Parcours(V) ;

  return 0;
}
