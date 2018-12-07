#include "BST.hpp"

int main() {

  //BST<int> *tree = new BST<int>() ;
  BST<int> tree ;
  //BST<int>::iterator test ;
  /*
  for (int i = 0 ; i < 10 ; ++i  ) {
    int x ;
    if (i%2 == 0) { x= i*4 ; }
    else {x=i+4 ;}
    tree.insert(x,i);
  }
  */
  tree.insert(10,5) ;
  tree.insert(15,60) ;
  tree.insert(5,11) ;
  tree.insert(30,0) ;
  tree.insert(3,19) ;
  tree.inorder(tree.getRootVal());
  //tree.find(7) ;

  BST<int>::iterator it;

  for(it = tree.begin(); it != tree.end(); it++) {
      std::cout << *it << std::endl;
      /*
      if (it != tree.begin()) {
        it-- ;
        std::cout << *it << std::endl;
      }
      */
  }
  return 0;
}
