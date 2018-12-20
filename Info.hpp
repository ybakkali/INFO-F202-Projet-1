#ifndef  _INFO_H_
#define  _INFO_H_


template <typename T>
class Info {

  private :
    unsigned int Index ;
    T Value ;
  public :
    Info(unsigned int,T) ;
    Info(const Info<T>& ) ;
    Info(Info<T>&&) = default;
    ~Info() ;
    inline Info<T>& operator= (const Info<T>&) ;
    inline Info<T>& operator= (Info<T>&&) = default ;
    inline bool operator==(const Info<T>&) const ;
    inline bool operator!=(const Info<T>&) const ;
    inline bool operator<(const Info<T>&) const  ;

    //Setters
    void setIndex(unsigned int) ;
    void setValue(T);
    //Getters
    unsigned int getIndex() const ;
    T getValue() const ;
};

template <typename T>
Info<T>::Info(unsigned i,T value) : Index(i) , Value(value) {}

template <typename T>
Info<T>::Info(const Info<T>& other ) : Index(other.getIndex()) , Value(other.getValue()) {}

template <typename T>
Info<T>::~Info() {}

template <typename T>
Info<T>& Info<T>::operator= (const Info<T>& other) {
  if (this != &other) {
    Index = other.getIndex() ;
    Value = other.getValue() ;
  }
  return *this ;
}

template <typename T>
bool Info<T>::operator< (const Info<T>& other) const {
  return this->getIndex() < other.getIndex() ;
}
template <typename T>
bool Info<T>::operator==(const Info<T>& other) const {
  return this->getIndex() == other.getIndex() ;
}
template <typename T>
bool Info<T>::operator!=(const Info<T>&  other) const {
  return !operator==(other) ;
}
template <typename T>
void Info<T>::setIndex(unsigned int i) {
  Index = i ;
}
template <typename T>
void Info<T>::setValue(T value) {
  Value = value ;
}
template <typename T>
unsigned int Info<T>::getIndex() const {
  return Index ;
}
template <typename T>
T Info<T>::getValue() const {
  return Value ;
}

#endif
