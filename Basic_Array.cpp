// $Id: Basic_Array.cpp 827 2022-02-21 14:20:53Z brajadam $

// Honor Pledge: Brandon Adams
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Basic_Array.h"
#include <cstring>          // for size_t
#include <stdexcept>        // for std::out_of_bounds exception

//
// Basic_Array
//
template <typename T>
Basic_Array <T>::Basic_Array (void)
: data_( nullptr) ,
 cur_size_ (0)
{
    
}

//
// Basic_Array
//
template <typename T>
Basic_Array <T>::Basic_Array (size_t length)
: data_ ( nullptr ) ,
 cur_size_ (0)
{
    if( length > 0 )
    {
        this->data_ = new T [length];
    }
    this->cur_size_ = length;
}

//
// Basic_Array
//
template <typename T>
Basic_Array <T>::Basic_Array (size_t length, T fill)
: data_ ( nullptr ) ,
 cur_size_ (0)
{
    if( length > 0 )
    {
        this->data_ = new T [length];
    }
    this->cur_size_ = length;

    this->fill (fill);
}

//
// Basic_Array
//
template <typename T>
Basic_Array <T>::Basic_Array (const Basic_Array & arr)
: data_ ( nullptr ) ,
 cur_size_ (0)
{
    if ( arr.data_ )
    {
        this->data_ = new T [arr.size()];
        this->cur_size_ = arr.size();

        *this = arr;
    }
}

//
// operator []
//
template <typename T>
T & Basic_Array <T>::operator[] (size_t index)
{
    // make sure index is less than cur_size_
    if ( index < cur_size_ )
    {
        // if index is less than cur_size_
        return data_[index];
    }
    else
    {
        // if index is greater than or equal to cur_size_ 
        // throw out of range error
        throw std::out_of_range("Index out of range");
    }
}

//
// operator [] 
//
template <typename T>
const T & Basic_Array <T>::operator [] (size_t index) const
{
    if ( index < cur_size_ )
    {
        // if index is less than cur_size_
        return data_[index];
    }
    else
    {
        // if index is greater than or equal to cur_size_ 
        // throw out of range error
        throw std::out_of_range("Index out of range");
    }
}

//
// get
//
template <typename T>
T Basic_Array <T>::get (size_t index) const
{
    if ( index < cur_size_ )
    {
        // if index is less than cur_size_
        return data_[index];
    }
    else
    {
        // if index is greater than or equal to cur_size_ 
        // throw out of range error
        throw std::out_of_range("Index out of range");
    }
}

//
// set
//
template <typename T>
void Basic_Array <T>::set (size_t index, T value)
{
    if ( index < cur_size_ )
    {
        // if index is less than cur_size_
        data_[index] = value;
    }
    else
    {
        // if index is greater than or equal to cur_size_ 
        // throw out of range error
        throw std::out_of_range("Index out of range");
    }
}

//
// find (T, size_t) 
//
template <typename T>
int Basic_Array <T>::find (T val, size_t start) const
{

    // for loop to check every index after start
    for ( size_t i = start ; i < this->cur_size_ ; i++ )
    {
        // check each index
        if ( data_[i] == val )
        {
            return i;
        }
    }

    // if val is not found return -1
    return -1;
}

//
// operator ==
//
template <typename T>
bool Basic_Array <T>::operator == (const Basic_Array & rhs) const
{
    // check for self reference
    if ( this == &rhs ) 
    {
        return true;
    }

    // check if sizes match
    if ( rhs.cur_size_ != cur_size_ )
    {
        return false;
    }

    // check each index to see if they match
    for ( size_t i = 0 ; i < cur_size_ ; i++ )
    {
        // compare each index
        if ( data_[i] != rhs.data_[i] )
        {
            return false;
        }
    }

    // return true if everything matches
    return true;
}

//
// fill
//
template <typename T>
void  Basic_Array <T>::fill (T value)
{
    // fill each variable
    for( size_t i = 0 ; i < cur_size_ ; i++ )
    {
        data_[i] = value;
    }
}
