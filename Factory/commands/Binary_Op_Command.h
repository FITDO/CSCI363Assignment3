

#ifndef _BINARY_OP_COMMAND_
#define _BINARY_OP_COMMAND_

#include "Expr_Command.h"
#include "Stack.h"

/**
 * @class Binary_Op_Command
 * 
 * Template class to perform binary operator commands
 * commands that take two operators
 */
class Binary_Op_Command : public Expr_Command
{
protected:
    /**
     * Construct a new Binary_Op_Command object
     * 
     * @param[in] s     stack
     * @param[in] p     precedence
     */
    Binary_Op_Command (Stack <int> & s , int p);

public:
    /**
     * Performs a command on the stack 
     * calls the evaluate method
     */
    void execute (void);

    /**
     * Command left for child classes to define
     * 
     * @param[in] n1 
     * @param[in] n2 
     * @return int 
     */
    virtual int evaluate (int n1, int n2) const = 0;

private:
    // Stack to perform commands on
    Stack <int> & s_;
};

#endif