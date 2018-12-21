#include "SparseVector.hpp"
#include <exception>
#include <iostream>

template <typename SpVector>
void Parcours(Vector<SpVector>& v) {
    for (unsigned int i = 0 ; i < v.size() ; i++) {
        std::cout << "Vector[" << i << "] = " << v.get(i) << std::endl;
    }
}

template <typename K>
void ParcoursBST(BST<K>& tree) {
    std::cout << "Index        Value" << std::endl;
    for (typename BST<K>::iterator it = tree.begin() ; it != tree.end() ; ++it) {
        std::cout << "( " << (*it).getInfo().getIndex() << "     ,    " << (*it).getInfo().getValue() << " )" << std::endl;
    }
}

int main() {

  SparseVector<int> SpVector(40) ;
  SpVector.set(10,100) ;
  SpVector.set(15,600) ;
  SpVector.set(5,110) ;
  SpVector.set(30,340) ;
  SpVector.set(3,190) ;

  SparseVector<int> SpVector_(SpVector)  ;
  SpVector_.set(30,180) ;
  SpVector_.set(20,440) ;
  SpVector_.set(38,130) ;

  SpVector.set(8,100) ;
  SpVector.set(3,500) ;

  std::cout<< "SpVector" << std::endl ;
  ParcoursBST(SpVector) ;
  std::cout<< "SpVector_" << std::endl ;
  ParcoursBST(SpVector_) ;

  try {
      SpVector.get(50) ;
  }
  catch (const std::exception& err) {
    std::cerr << "*** Error: " << err.what() << " ***" << std::endl;
  }

  try {
      SpVector_.set(55,1000) ;
  }
  catch (const std::exception& err) {
    std::cerr << "*** Error: " << err.what() << " ***" << std::endl;
  }
  return 0;
}
