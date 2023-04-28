

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

/**
 * @class Multiply_Command
 * 
 * Command for Multiplication ( * )
 */
class Multiply_Command : public Binary_Op_Command
{
public:

    /**
     * Initializing constructor.
     *
     * @param[in]      s        stack
     */
    Multiply_Command (Stack <int> & s);

    /**
     * Takes two elements and multiplies them
     * 
     * @param n1 
     * @param n2 
     * @return int 
     */
    int evaluate (int n1 , int n2) const;
};

#include "Multiply_Command.inl"

#endif