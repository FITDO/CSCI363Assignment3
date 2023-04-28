#include "Modulus_Command.h"

//
// Modulus_Command
//
Modulus_Command::Modulus_Command (Stack <int> & s)
:Binary_Op_Command (s , 2)
{
    
}

//
// evaluate (int , int)
//
int Modulus_Command::evaluate (int n1 , int n2) const
{
    // Avoid division by 0
    if ( n2 != 0 )
    {
        // Divide and return
        return n1 % n2;
    }
    else
    {
        // throws runtime_error
        throw std::runtime_error("Division by Zero Error");
    }
}