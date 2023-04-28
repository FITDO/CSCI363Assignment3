// -*- C++ -*-
// $Id: Basic_Array.inl 828 2011-21-07 14:21:52Z brajadam $

// Honor Pledge: Brandon Adams
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
template <typename T>
inline
size_t Basic_Array <T>::size (void) const
{
    return cur_size_;
}

//
// operator !=
//
template <typename T>
bool Basic_Array <T>::operator != (const Basic_Array & rhs) const
{
    return !(this->operator==(rhs));
}

//
// find (char)
//
template  <typename T>
int Basic_Array <T>::find (T value) const
{
    return find ( value  , 0 );
}