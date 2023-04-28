

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"

/**
 * @class Add_Command
 * 
 * Command for Addition ( + )
 */
class Add_Command : public Binary_Op_Command
{
public:

    /**
     * Initializing constructor.
     *
     * @param[in]      s        stack
     */
    Add_Command (Stack <int> & s);

    /**
     * Takes two elements and adds them 
     * 
     * @param[in] n1 
     * @param[in] n2 
     * @return int 
     */
    int evaluate (int n1 , int n2) const;
};

#include "Add_Command.inl"

#endif