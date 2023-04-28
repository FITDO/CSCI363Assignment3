

#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

/**
 * @class Stack_Expr_Command_Factory
 * 
 * A Stack Expr Command Factory used to generate commands
 * This implemtation is a flyweight
 */
class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:

    /**
     * Initializing constructor
     * 
     * @param[in]    stack      stack_ 
     */
    Stack_Expr_Command_Factory (Stack <int> & stack);

    // Destructor
    ~Stack_Expr_Command_Factory (void);

    /**
     * Create a number command object
     * 
     * @param[in]    num 
     * @return       Num_Command * 
     */
    Num_Command * create_number_command (int num); 

    /**
     * Return an Add_Command.
     * If one has not been made yet make one
     * If it already has been made return that one
     * 
     * @return       Add_Command * 
     */
    Add_Command * create_add_command (void); 

    /**
     * Return an Subtract_Command.
     * If one has not been made yet make one
     * If it already has been made return that one 
     * 
     * @return        Subtract_Command * 
     */
    Subtract_Command * create_subtract_command (void); 

    /**
     * Return an Multiply_Command.
     * If one has not been made yet make one
     * If it already has been made return that one 
     * 
     * @return         Multiply_Command * 
     */
    Multiply_Command * create_multiply_command (void);

    /**
     * Return an Division_Command.
     * If one has not been made yet make one
     * If it already has been made return that one 
     * 
     * @return         Division_Command * 
     */
    Division_Command * create_division_command (void);

    /**
     * Return an Modulus_Command.
     * If one has not been made yet make one
     * If it already has been made return that one 
     * 
     * @return         Modulus_Command * 
     */
    Modulus_Command * create_modulus_command (void);

    /**
     * Deletes all commands made by the factory
     * 
     * 
     */
    void clear_all (void);

    /**
     * Deletes all number commands made by the factory
     * 
     * 
     */
    void clear_num_commands (void);

private:

    // Stack used to make commands
    // Each factory gets one stack.
    Stack <int> & stack_;

    // Array of number commands to keep track of commands created
    Array <Num_Command *> num_commands_;
    //Keep track of the amount of num commands
    int count_;

    // Commands created by the factory
    Add_Command * add_command_;
    Subtract_Command * subtract_command_;
    Multiply_Command * multiply_command_;
    Division_Command * division_command_;
    Modulus_Command * modulus_command_;

    // Hidden to prevent client from calling

    /**
     * Copy constructor
     * 
     * @param[in]    stack_expr_command_factory
     */
    Stack_Expr_Command_Factory (const Stack_Expr_Command_Factory & stack_expr_command_factory);

    /**
     * Assignment operator
     * 
     * @param[in]   stack_expr_command_factory 
     * @return      const Stack_Expr_Command_Factory& 
     */
    const Stack_Expr_Command_Factory & operator = (const Stack_Expr_Command_Factory & stack_expr_command_factory);
};


#endif