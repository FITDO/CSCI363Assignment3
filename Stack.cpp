// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge: Brandon Adams
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>
#include <cstring> 

#include "Array.h"
#include "Stack.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
:stack_( nullptr ) ,
    top_(0)
{
    this->stack_ = new Array<T>(20);
    this->top_ = 0;
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
: stack_( nullptr ) ,
    top_ (0)
{
    this->stack_ = new Array<T>(20);
    this->top_ = 0;
    // calls = operator
    *this = stack;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    // make sure stack_ is not a nullptr
    if ( stack_ )
    {
    	delete stack_;
    	this->stack_ = nullptr;
    }
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // make sure there is room to add eleement
    if ( top_ < stack_->max_size() )
    {
        // if there is room set the element
        this->stack_->set( top_ , element );
        this->top_++;
    }
    else
    {
        // if there is not room resize to add room
        this->stack_->resize( stack_->max_size() + 20 );
        this->stack_->set( top_ , element );
        this->top_++;
    }
}


//
// pop
//
template <typename T>
T Stack <T>::pop (void)
{   
    // if to make sure top_ is not 0
    if ( top_ > 0 )
    {
        // if top != 0 lower top
        T element = stack_->get(top_ - 1);
        this->top_--;
        return element;
    }
    else
    {
        // if top_ = 0 throw
        throw empty_exception("Stack is empty");
    }
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    if ( top_ > 0 )
    {
        return stack_->get(top_ - 1);
    }
    else
    {
        // if top_ = 0 throw
        throw empty_exception("Stack is empty");
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    // check for self reference
    if (this == &rhs)
    {
        return *this;
    }

    // make sure there is room to copy elements from rhs
    if ( stack_->max_size() < rhs.top_ )
    {
        stack_->resize( rhs.top_ + 5 );
    }

    // copy elements from rhs
    for ( int i = 0 ; i < rhs.top_ ; i++ )
    {
        this->stack_->set( i , rhs.stack_->get(i) );
    }

    // set top_ to rhs.top_
    this->top_ = rhs.top_;

    return *this;

}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    // delete stack_
    delete stack_;
    // make new stack_
    this->stack_ = new Array<T>(20);
    // set top_ to 0
    this->top_ = 0;
}
