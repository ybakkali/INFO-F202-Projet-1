#ifndef  _VECTOR_H_
#define  _VECTOR_H_

template <typename Elem>
class Vector {
    protected :
        unsigned int VectorSize ;
    public :
        Vector () = default;
        Vector (unsigned int size ) : VectorSize(size) {}
        Vector (const Vector& other) : VectorSize(other.VectorSize) {}
        Vector (Vector&&) = default;
        virtual ~Vector () = default;
        Vector& operator= (const Vector&) = default;
        Vector& operator= (Vector&&) = default;
        virtual const Elem get (unsigned int) const noexcept = 0;
        virtual void set (unsigned int,Elem) noexcept = 0;
        virtual unsigned int size() const noexcept = 0;
};

#endif
