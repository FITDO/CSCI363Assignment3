// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge: Brandon Adams
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return top_;
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    return ( (top_ > 0) ? false : true ); 
}
