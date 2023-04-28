// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge: Brandon Adams
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"

//
// Array
//
template <typename T>
Array <T>::Array (void)
: max_size_(0)
{
    this->data_ = nullptr;
    this->cur_size_ = 0;
    this-> max_size_ = 0;
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
: max_size_(0)
{
    // Makes sure length is greater than 0 to stop allocations with 0 bytes;
    if ( length > 0 )
    {
        this->data_ = new T [length];
        this->cur_size_ = length;
        this->max_size_ = length;
    }
    else
    {
        this->data_ = nullptr;
        this->cur_size_ = 0;
        this-> max_size_ = 0;
    }
}

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
: max_size_(0)
{
    // Makes sure length is greater than 0 to stop allocations with 0 bytes;
    if ( length > 0 )
    {
        this->data_ = new T [length];
        this->cur_size_ = length;
        this->max_size_ = length;
        
        // Calls the fill method to reuse code
        this->fill(fill);
    }
    else
    {
        this->data_ = nullptr;
        this->cur_size_ = 0;
        this-> max_size_ = 0;
    }
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
: max_size_(0)
{
    this->data_ = nullptr;
    this->cur_size_ = 0;
    this-> max_size_ = 0;
    // calls the = operator
    *this = array;
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    // Makes sure data_ is not a nullptr
    if ( this->data_)
    {
        delete [] this->data_;
        // Set data_ to null for safety
        this->data_ = nullptr;
    }
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    // Check for self reference
    if ( this == &rhs )
    {
        return *this;
    }

    // if data_ is not null delete it
    if ( this->data_ )
    {
        delete [] this->data_;
        this->data_ = nullptr;
    }

    // Check if data_ is greater than 0 and data_ is not null
    if ( rhs.data_ && rhs.cur_size_ > 0 )
    {
        // copy variables from rhs
        size_t rework = rhs.cur_size_;
        this->data_ = new T [rework];
        this->cur_size_ = rework;
        this->max_size_ = rework;

        for ( int i = 0 ; i < rework ; i++ )
        {
            this->data_[i] = rhs.data_[i];
        }
    }
    else
    {
        this->cur_size_ = 0;
        this->max_size_ = 0;
    }
    
    return *this;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    // If else if else to find out what to do
    if ( new_size <= this->max_size_ )
    {
        // If new_size is less than or equal to max_size_ simply hide the indexs
        // by setting cur_size_
        this->cur_size_ = new_size;
    }
    else if ( max_size_ > 0 )
    {
        // if new_size_ is greater than max_size_ and max_size_ is not 0
        // create a temp pointer
        T * tempdata = this->data_;
        this->data_ = new T [new_size];

        // copy data over
        for ( size_t i = 0 ; i < this->cur_size_ ; i++ )
        {
            this->data_[i] = tempdata[i];
        }
        
        // set new sizes
        this->cur_size_ = new_size;
        this->max_size_ = new_size;

        // delete old data
        delete [] tempdata;
    }
    else 
    {
        // if max_size_ is 0

        // allocate data and set new sizes
        this->data_ = new T [new_size];
        this->cur_size_ = new_size;
        this->max_size_ = new_size;
    }
}

/**
 * First checks if cur_size_ does not equal max_size
 * if cur_size_ does not equal make a new array and carry
 * over the old elements and deletes the old array
 * if cur_size_ = 0 delete the array and set data_ to null
 * if cur_size_ and max_size_ equal do nothing
 */
template <typename T>
void Array <T>::shrink (void)
{
    if (this->cur_size_ < this->max_size_ && this->cur_size_ > 0) 
    {
        T * ptr = new T[this->cur_size_];
        for (int i = 0 ; i < this->cur_size_ ; i++)
        {
            // COMMENT Just write data_[i]. It's much cleaner.
            // FIXED added data_[i] and ptr[i]

            ptr[i] = this->data_[i];
        }
        delete [] this->data_;
        this->data_ = ptr;
        this->max_size_ = this->cur_size_;
    }
    else if (this->cur_size_ == 0)
    {
        delete [] this->data_;
        this->data_ = nullptr;
    }
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
    // check for self reference
    if ( this == &rhs ) 
    {
        return true;
    }

    // check if sizes match
    if ( rhs.cur_size_ != this->cur_size_ )
    {
        return false;
    }

    // check each index to see if they match
    for ( size_t i = 0 ; i < this->cur_size_ ; i++ )
    {
        // compare each index
        if ( this->data_[i] != rhs.data_[i] )
        {
            return false;
        }
    }

    // return true if everything matches
    return true;
}

/**
 * Makes a temp holder then creates a var called run_time which
 * is the cur_size_ of the array divided by 2. Starts a for loop to swap elements.
 * uses a temp to hold a variable then swaps.
 */
template <typename T>
void Array <T>::reverse (void)
{
    T temp;
    int last = this->cur_size_ - 1;

    int run_time = this->cur_size_ / 2;
    for ( int i = 0 ; i < run_time ; i++ )
    {
        temp = this->data_[i];
        this->data_[i] = this->data_[last - i];
        this->data_[last - i] = temp;
    }
}

/** Try Removed
 * has a try catch and if to stop errors from occuring 
 * checks for begin/end >= cur_size_ or end > begin will
 * throw errors for each but will return a null array
 * Generates an array to return using the array constructor
 * with size, where size = end - begin. Then uses a loop to
 * transfer data to shallow array. Return generated array
 */
template <typename T>
Array <T> Array <T>::slice (size_t begin, size_t end) const
{
    if (begin < this->cur_size_ && end < this->cur_size_ && begin <= end)
    {
        int run_time = (end - begin) + 1;
        Array shallow_arr(run_time);
        for ( int i = 0 ; i < run_time ; i++)
        {
            // COMMENT Just write data_[i]. It's much cleaner.
            // FIXED added data_[i]

            shallow_arr.data_[i] = this->data_[begin + i];
        }
        return shallow_arr;
    }
    else if (begin >= this->cur_size_)
    {
        throw std::out_of_range("Index out of range");
    }
    else
    {
        throw std::range_error("End can not be less than begin");
    }
}