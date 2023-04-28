

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

/**
 * @class Subtract_Command
 * 
 * Command for Subtration ( - )
 */
class Subtract_Command : public Binary_Op_Command
{
public:

    /**
     * Initializing constructor.
     *
     * @param[in]      s        stack
     */
    Subtract_Command (Stack <int> & s);

    /**
     * Takes two elements and subtracts them 
     * 
     * @param[in] n1 
     * @param[in] n2 
     * @return int 
     */
    int evaluate (int n1 , int n2) const;
};

#include "Subtract_Command.inl"

#endif