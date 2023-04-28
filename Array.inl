// -*- C++ -*-
// $Id: Array.inl 828 2011-02-07 14:21:52Z hillj $

// Honor Pledge: Brandon Adams
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// max_size
//
template <typename T>
inline
size_t Array <T>::max_size (void) const
{
    return this->max_size_;
}

template <typename T>
inline
bool Array <T>::operator != (const Array & rhs) const
{
    return !(this->operator==(rhs));
}

template <typename T>
Array <T> Array<T>::slice (size_t begin) const
{
    return this->slice( begin , this->cur_size_ - 1);
}