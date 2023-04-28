

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Op_Command.h"

/**
 * @class Division_Command
 * 
 * Command for Division ( / )
 */
class Division_Command : public Binary_Op_Command
{
public:

    /**
     * Construct a new Division_Command object
     * 
     * @param[in]       s       stack
     */
    Division_Command (Stack <int> & s);

    /**
     * Takes two elements and divides them
     * 
     * @param[in] n1 
     * @param[in] n2 
     * @return int 
     * @exception runtime_error
     */
    int evaluate (int n1 , int n2) const;
};

#endif