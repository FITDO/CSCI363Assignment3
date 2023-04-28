

#ifndef _EXPR_COMMAND_CPP_
#define _EXPR_COMMAND_CPP_

#include <string>

/**
 * @class Expr_Command
 * 
 * Parent Class of all commands
 */
class Expr_Command 
{
protected:

    /**
     * Construct a new Expr_Command object
     * 
     * @param p 
     */
    Expr_Command (int p);

public:

    // Default Constructor
    Expr_Command (void);

    // Left to child classes to define
    virtual void execute (void) = 0;

    /**
     * Returns the precedence (p_) of the command
     * 
     * @return int 
     */
    int precedence (void) const;

private:
    // defines the precedence of the command
    // higher precednece = more important
    // Used for turing infix to postfix
    int p_;
};

#include "Expr_Command.inl"

#endif