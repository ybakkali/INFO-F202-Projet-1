#ifndef  _INFO_H_
#define  _INFO_H_


template <typename Elem>
class Info {

  private :
    int Index ;
    Elem Value ;
  public :
    Info(int,Elem) ;
    Info(const Info<Elem>& ) ;
    ~Info() ;
    inline Info<Elem>& operator= (const Info<Elem>& ) ;
    inline bool operator==(const Info<Elem>& ) const ;
    inline bool operator!=(const Info<Elem>&  ) const ;
    inline bool operator<(const Info<Elem>&  ) const  ;
    void setIndex(int) ;
    void setValue(Elem);
    int getIndex() const ;
    Elem getValue() const ;
};

template <typename Elem>
Info<Elem>::Info(int i,Elem value) : Index(i) , Value(value) {}

template <typename Elem>
Info<Elem>::Info(const Info<Elem>& other ) : Index(other.getIndex()) , Value(other.getValue()) {}

template <typename Elem>
Info<Elem>::~Info() {}

template <typename Elem>
Info<Elem>& Info<Elem>::operator= (const Info<Elem>& other) {
  Index = other.getIndex() ;
  Value = other.getValue() ;
  return *this ;
}

template <typename Elem>
bool Info<Elem>::operator< (const Info<Elem>& other) const {
  return this->getIndex() < other.getIndex() ;
}
template <typename Elem>
bool Info<Elem>::operator==(const Info<Elem>& other) const {
  return this->getIndex() == other.getIndex() ;
}
template <typename Elem>
bool Info<Elem>::operator!=(const Info<Elem>&  other) const {
  return !operator==(other) ;
}
template <typename Elem>
void Info<Elem>::setIndex(int i) {
  Index = i ;
}
template <typename Elem>
void Info<Elem>::setValue(Elem value) {
  Value = value ;
}
template <typename Elem>
int Info<Elem>::getIndex() const {
  return Index ;
}
template <typename Elem>
Elem Info<Elem>::getValue() const {
  return Value ;
}

#endif
