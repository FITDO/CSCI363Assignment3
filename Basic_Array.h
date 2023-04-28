// -*- C++ -*-
// $Id: Basic_Array.h 380 2010-02-21 17:06:33Z brajadam $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Basic_Array.h 380 2010-02-08 05:10:33Z brajadam $
 *
 * Honor Pledge: Brandon Adams
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _BASIC_ARRAY_H_
#define _BASIC_ARRAY_H_

#include <cstring>

/**
 * @class Basic_Array
 *
 * Implementation of a basic array class.
 */
template <typename T>
class Basic_Array
{
public:
    /// Type definition of the element type.
    typedef T type;

    /// Default constructor.
    Basic_Array (void);

    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     */
    Basic_Array (size_t length);

    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     * @param[in]      fill          Initial value for each element
     */
    Basic_Array (size_t length, T fill);

    /**
     * Copy constructor
     *
     * @param[in]     arr         The source array.
     */
    Basic_Array (const Basic_Array & arr);

    /**
     * Retrieve the current size of the array.
     *
     * @return          The current size
     */
    size_t size (void) const;

    /**
     * Get the Element at the specified index. If the index is not
     * within the range of the array, then std::out_of_range exception
     * is thrown.
     *
     * @param[in]       index               Zero-based location
     * @exception       std::out_of_range   Invalid \a index value
    */
    T & operator [] (size_t index);

    /**
     * @overload
     *
     * The returned element is not modifiable.
     */
    const T & operator [] (size_t index) const;

    /**
     * Get the element at the specified index. If the \a index is not within
     * the range of the array, then std::out_of_range exception is thrown.
     *
     * @param[in]       index                 Zero-based location
     * @return          element at \index
     * @exception       std::out_of_range     Invalid index value
     */  
    T get (size_t index) const;

    /** 
     * Set the element at the specified \a index. If the \a index is not
     * within range of the array, then std::out_of_range exception is 
     * thrown.
     *
     * @param[in]       index                 Zero-based location
     * @param[in]       value                 New value for element
     * @exception       std::out_of_range     Invalid \a index value
     */
    void set (size_t index, T value);

    /**
     * Locate the specified element in the array. The index of the first
     * occurrence of the element is returned. If the element is not
     * found in the array, then -1 is returned.
     *
     * @param[in]        ch        element to search for
     * @return           Index value of the element
     * @retval           -1        element not found
     */
    int find (T element) const;

    /**
     * @overload
     *
     * This version allows you to specify the start index of the search. If
     * the start index is not within the range of the array, then the
     * std::out_of_range exception is thrown.
     *
     * @param[in]       ch                   element to search for
     * @param[in]       start                Index to begin search
     * @return          Index value of first occurrence
     * @retval          -1                   element not found
     * @exception       std::out_of_range    Invalid index
     */
    int find (T element, size_t start) const;

    /**
     * Test the array for equality.
     *
     * @param[in]       rhs                  Right hand side of equal to sign
     * @retval          true                 Left side is equal to right side
     * @retval          false                Left side is not equal to right side
     */
    bool operator == (const Basic_Array & rhs) const;

    /**
     * Test the array for inequality.
     *
     * @param[in]       rhs                  Right-hand size of not equal to sign
     * @retval          true                 Left side is not equal to right side
     * @retval          false                Left size is equal to right side
     */
    bool operator != (const Basic_Array & rhs) const;

    /**
     * Fill the contents of the array.
     *
     * @param[in]       element                   Fill element
     */
    void fill (T element);

    protected:
    /// Pointer to the actual data
    T * data_;

    /// Current size of the array.
    size_t cur_size_;
};

#include "Basic_Array.cpp"

#include "Basic_Array.inl"

#endif