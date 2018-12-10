#include "SparseVector.hpp"

int main() {

  SparseVector<int> V(40) ;
  /*
  for (int i = 0 ; i < 10 ; ++i  ) {
    int x ;
    if (i%2 == 0) { x= i*4 ; }
    else {x=i+4 ;}
    V.set(x,i);
  }
  */
  V.set(10,5) ;
  V.set(15,60) ;
  V.set(5,11) ;
  V.set(30,0) ;
  V.set(3,19) ;
  std::cout << "Value " << V.get(7) << std::endl ;
  std::cout << "Value " << V.get(10) << std::endl ;
  std::cout << "Value " << V.get(3) << std::endl ;
  V.set(3,100) ;
  std::cout << "Value " << V.get(3) << std::endl ;
  SparseVector<int>::iterator it;

  for(it = V.begin(); it != V.end(); it++) {
      std::cout << *it << std::endl;
      /*
      if (it != V.begin()) {
        it-- ;
        std::cout << *it << std::endl;
      }
      */
  }
  return 0;
}
