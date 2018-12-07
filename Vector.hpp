#ifndef  _VECTOR_H_
#define  _VECTOR_H_

template <typename Elem>
class Vector {
  public :
    Vector (unsigned int);
    Vector (const Vector&) = default;
    Vector (Vector&&) = default;
    //virtual Vector& operator= (const Vector&) = default;
    Vector& operator= (Vector&&) = default;
    virtual const Elem get (int) const noexcept = 0;
    virtual void set (int,Elem) noexcept = 0;
    virtual ~Vector () = default;
  protected :
    unsigned int VectorSize ;
};

template <typename Elem>
Vector<Elem>::Vector(unsigned int size) : VectorSize(size) {}


#endif
