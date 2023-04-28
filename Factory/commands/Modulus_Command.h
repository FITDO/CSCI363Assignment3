

#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

#include "Binary_Op_Command.h"

/**
 * @class Modulus_Command
 * 
 * Command for Modulus ( % )
 */
class Modulus_Command : public Binary_Op_Command
{
public:

    /**
     * Initializing constructor.
     *
     * @param[in]      s        stack
     */
    Modulus_Command (Stack <int> & s);

    /**
     * Takes two elements and performs modulus on them
     * 
     * @param   n1 
     * @param   n2 
     * @return  int 
     * @exception runtime_error
     */
    int evaluate (int n1 , int n2) const;
};

#endif