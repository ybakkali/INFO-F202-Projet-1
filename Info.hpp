#ifndef  _INFO_H_
#define  _INFO_H_


template <typename Elem>
class Info {

  private :
    unsigned int Index ;
    Elem Value ;
  public :
    Info(unsigned int,Elem) ;
    Info(const Info<Elem>& ) ;
    Info(Info<Elem>&&) = default;
    ~Info() ;
    inline Info<Elem>& operator= (const Info<Elem>&) ;
    inline Info<Elem>& operator= (Info<Elem>&&) = default ;
    inline bool operator==(const Info<Elem>&) const ;
    inline bool operator!=(const Info<Elem>&) const ;
    inline bool operator<(const Info<Elem>&) const  ;

    //Setters
    void setIndex(unsigned int) ;
    void setValue(Elem);
    //Getters
    unsigned int getIndex() const ;
    Elem getValue() const ;
};

template <typename Elem>
Info<Elem>::Info(unsigned i,Elem value) : Index(i) , Value(value) {}

template <typename Elem>
Info<Elem>::Info(const Info<Elem>& other ) : Index(other.getIndex()) , Value(other.getValue()) {}

template <typename Elem>
Info<Elem>::~Info() {}

template <typename Elem>
Info<Elem>& Info<Elem>::operator= (const Info<Elem>& other) {
  if (this != &other) {
    Index = other.getIndex() ;
    Value = other.getValue() ;
  }
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
void Info<Elem>::setIndex(unsigned int i) {
  Index = i ;
}
template <typename Elem>
void Info<Elem>::setValue(Elem value) {
  Value = value ;
}
template <typename Elem>
unsigned int Info<Elem>::getIndex() const {
  return Index ;
}
template <typename Elem>
Elem Info<Elem>::getValue() const {
  return Value ;
}

#endif
