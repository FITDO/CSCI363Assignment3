#include "Division_Command.h"
#include <exception>


// COMMENT: Your code will crash if you have divide by 0.

// FIXED: ADDED a try that throws an error if client tries to divide by 0

//
// Division_Command (Stack<int>)
//
Division_Command::Division_Command (Stack <int> & s)
: Binary_Op_Command (s , 2)
{
    
}

//
// evaluate (int , int)
//
int Division_Command::evaluate (int n1 , int n2) const
{
    // Avoid division by 0
    if ( n2 != 0 )
    {
        // Divide and return
        return n1 / n2;
    }
    else
    {
        // throws runtime_error
        throw std::runtime_error("Division by Zero Error");
    }
}