#ifndef _EXPR_COMMAND_FACTORY_
#define _EXPR_COMMAND_FACTORY_

#include "Num_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Division_Command.h"
#include "Modulus_Command.h"

/**
 * @class Expr_Command_Factory
 * 
 * Template class for Expr Command Factories
 */
class Expr_Command_Factory
{
protected:
    
    // Default constructor
    Expr_Command_Factory (void);

    // Destructor
    ~Expr_Command_Factory (void);
    
public:

    /**
     * Create a number command object to return
     * 
     * @param[in]      num      number
     * @return      Num_Command* 
     */
    virtual Num_Command * create_number_command (int num) = 0; 

    /**
     * Create a add command object
     * 
     * @return      Add_Command* 
     */
    virtual Add_Command * create_add_command (void) = 0; 

    /**
     * Create a subtract command object
     * 
     * @return Subtract_Command* 
     */
    virtual Subtract_Command * create_subtract_command (void) = 0; 

    /**
     * Create a multiply command object
     * 
     * @return Multiply_Command* 
     */
    virtual Multiply_Command * create_multiply_command (void) = 0;

    /**
     * Create a division command object
     * 
     * @return Division_Command* 
     */
    virtual Division_Command * create_division_command (void) = 0;

    /**
     * Create a modulus command object
     * 
     * @return Modulus_Command* 
     */
    virtual Modulus_Command * create_modulus_command (void) = 0;

private:
    
    // Hidden to prevent Client from calling methods

    /**
     * Copy constructor
     * 
     * @param[in]   expr_command_factory
     */
    Expr_Command_Factory (const Expr_Command_Factory & expr_command_factory);

    /**
     * Assignment operator
     * 
     * @param[in]   expr_command_factory
     * @return const Expr_Command_Factory& 
     */
    const Expr_Command_Factory & operator = (const Expr_Command_Factory & expr_command_factory);
};

#endif