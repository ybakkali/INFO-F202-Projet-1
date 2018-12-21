#ifndef  _INFO_H_
#define  _INFO_H_

template <typename T,typename I = unsigned int>
class Info {

  private :
    I Index ;
    T Value ;
  public :
    Info(I,T) ;
    Info(const Info<T,I>&) ;
    ~Info() ;
    inline Info<T,I>& operator= (const Info<T,I>&) ;
    inline bool operator==(const Info<T,I>&) const ;
    inline bool operator!=(const Info<T,I>&) const ;
    inline bool operator<(const Info<T,I>&) const  ;

    //Setters
    void setValue(T);
    //Getters
    I getIndex() const ;
    T getValue() const ;
};

template <typename T,typename I>
Info<T,I>::Info(I i,T value) : Index(i) , Value(value) {}

template <typename T,typename I>
Info<T,I>::Info(const Info<T,I>& other):Index(other.Index),Value(other.Value) {}

template <typename T,typename I>
Info<T,I>::~Info() {}

template <typename T,typename I>
Info<T,I>& Info<T,I>::operator= (const Info<T,I>& other) {
  if (this != &other) {
    Index = other.Index ;
    Value = other.Value ;
  }
  return *this ;
}
template <typename T,typename I>
bool Info<T,I>::operator< (const Info<T,I>& other) const {
  return this->Index < other.Index ;
}
template <typename T,typename I>
bool Info<T,I>::operator==(const Info<T,I>& other) const {
  return this->Index == other.Index ;
}
template <typename T,typename I>
bool Info<T,I>::operator!=(const Info<T,I>&  other) const {
  return !operator==(other) ;
}
template <typename T,typename I>
void Info<T,I>::setValue(T value) {
  Value = value ;
}
template <typename T,typename I>
I Info<T,I>::getIndex() const {
  return Index ;
}
template <typename T,typename I>
T Info<T,I>::getValue() const {
  return Value ;
}

#endif
