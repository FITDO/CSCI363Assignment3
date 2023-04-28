

#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

/**
 * @class Num_Command
 * 
 * Command to push a number to the stack
 */
class Num_Command : public Expr_Command
{
public:

    /**
     * Initializing constructor.
     * 
     * @param   s   Stack
     * @param   n   value
     */
    Num_Command (Stack <int> & s , int n);

    /**
     * pushes a number onto the stack
     * 
     */
    void execute (void);

private:
    // Stack address
    Stack <int> & s_;
    // Value
    int n_;
};

#include "Num_Command.inl"

#endif