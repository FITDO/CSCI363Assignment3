

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Stack_Expr_Command_Factory.h"

#include <string>


/**
 * @class Calculator
 * 
 * A Stack Based Calculator
 */
class Calculator
{
public:

    /**
     * @class parenthesis_error
     * 
     * Exception thrown to indicate mismatched '(' and ')'
     */
    class parenthesis_error : public std::runtime_error
    {
    public:
        // default constructor 
        parenthesis_error (void)
        : std::runtime_error ("Parthesis Error") { }

        /**
         * Construct a new parenthesis error object
         * 
         * @param[in] msg       Error message
         */
        parenthesis_error (const char * msg)
        : std::runtime_error (msg) { }
        
    };

    /**
     * @class result_error
     * 
     * Exception thrown to catch result errors
     * ex 2 + 2 2
     */
    class result_error : public std::runtime_error
    {
    public:
        // default constructor
        result_error (void)
        : std::runtime_error ("Stack Error") { }

        /**
         * Construct a new result error object
         * 
         * @param[in] msg          error Message
         */
        result_error (const char * msg)
        : std::runtime_error (msg) { }

    };

    // Default Constructor
    Calculator (void);

    // Destructor
    ~Calculator (void);

    /**
     * Takes in a string and solves the problem 
     * Returns value generated
     * 
     * @param[in] infix 
     * @return  int             Answer to problem
     * @exception
     */
    int calculate (std::string infix);

    /**
     * Runs the calculate method in a while loop.
     * Has a try and catch will not stop unless
     * the client enters 'QUIT'
     * 
     */
    void run (void);

private:

    /**
     * A function to add commands to the postfix array
     * 
     * @param[in]    postfix 
     * @param[in]    cmd 
     * @param[in]    location 
     */
    void insert_postfix (Array <Expr_Command *> & postfix , Expr_Command * cmd , size_t & location);

    /**
     * Turns a infix string into a postfix array
     * 
     * @param[in]    infix 
     * @return       string
     */
    std::string infix_to_postfix (std::string infix , Array <Expr_Command *> & postfix , size_t & location);

    /**
     * Perform all Commands in the postfix Array
     * 
     */
    void evaluate_postfix (Array <Expr_Command *> & postfix);

    /**
     * Confirms if the inputed string has the same amount of 
     * '(' and ')' if not returns false else returns true
     * 
     * @param[in]   str
     * @return      bool
     */
    bool validate_equation (std::string & str);

    // Stack to perform calculation
    Stack <int> result_;
    // factory for commands
    Stack_Expr_Command_Factory factory_;
};


#endif