#ifndef  _VECTOR_H_
#define  _VECTOR_H_

template <typename Elem>
class Vector {
  public :
    virtual const Elem& get () const noexcept = 0;
    virtual Elem& set (int,Elem) noexcept = 0;
    Vector () = default;
    Vector (const Vector&) = default;
    Vector (Vector&&) = default;
    virtual Vector& operator= (const Vector&) = default;
    Vector& operator= (Vector&&) = default;
    virtual ~Vector () = default;
  private :
    int VectorSize ;
}

#endif
