#include "Calculator.h"

#include <sstream> // stringstream

//
// Calculator
//
Calculator::Calculator (void)
: result_ () ,
factory_ (result_) 
{

}

//
// ~Calculator
//
Calculator::~Calculator (void)
{
    
}

//
// Calculate (string)
//
int Calculator::calculate (std::string infix)
{
    // An array to hold commands
    Array <Expr_Command *> postfix (10);
    // Final size of the postfix array
    size_t end = 0;

    // Same Check for parenthesis
    if ( !validate_equation (infix) )
    {
        throw parenthesis_error("Check Parenthesis");
    }
    
    // Call infix_to_postfix method
    infix_to_postfix (infix , postfix , end);

    // Resize to stop from calling a nullptr 
    postfix.resize (end);

    // call evaluate_postfix method to perform commands
    evaluate_postfix (postfix);

    // delete all num commands to free memory
    factory_.clear_num_commands();

    // pop result from stack
    int result = result_.pop();
    // check to make sure result stack is empty 
    // if it isnt too many nums were added
    if ( result_.is_empty ())
    {
        return result;
    }
    else // result is not empty
    {
        // clear result
        result_.clear ();
        // throw error that stack isn't empty
        throw result_error ("Result Stack not empty");
    }
    
}

//
// run
//
void Calculator::run (void)
{
    bool keep_going = true;
    std::string equation;
    int res = 0;
    while (keep_going)
    {
        // try to catch errors
        try
        {
            // clear cin
            std::cin.clear ();

            // Prompt user and get input
            std::cout << "Enter A Problem: " << std::endl;
            getline (std::cin , equation);

            // Check if user wants to quit
            if (equation != "QUIT")
            {
                // Try to solve equation
                res = this->calculate(equation);
                // display result
                std::cout << "= " << res << std::endl;
            }
            else
            {
                // leave while loop
                keep_going = false;
            }
        }
        catch (std::exception & ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }
}

//
// insert_postfix (Array<Expr_Command *> & , Expr_Command * , size_t)
//
void Calculator::insert_postfix (Array <Expr_Command *> & postfix , Expr_Command * cmd , size_t & location)
{
    // check to make sure there is room
    if (postfix.size () <= location)
    {
        // add more space
        postfix.resize ( postfix.size () + 5);
    }

    // insert command
    postfix[location] = cmd;
    location++;
}

//
// infix_to_postfix (string , Array <Expr_Command *> , size_t)
//
std::string Calculator::infix_to_postfix (std::string infix , Array <Expr_Command *> & postfix , size_t & location)
{
    // Initialize variables
    std::istringstream input(infix);
    std::string token;
    std::string continuation = "";
    Expr_Command * cmd;

    // Stack to hold values
    Stack <Expr_Command *> temp;

    // bool for checks
    bool is_num;
    bool keep_looking;

    // Keep going till input is done
    while (!input.eof ())
    {
        // set is_num to false
        is_num = false;

        // get next token
        input >> token;

        // check to make sure the tokens aren't parthesis
        if (token != ")" && token != "(")
        {
            // Use checks to make a commands
            if (token == "+")
            {
                cmd = factory_.create_add_command ();
            }
            else if (token == "-")
            {
                cmd = factory_.create_subtract_command ();
            }
            else if (token == "*")
            {
                cmd = factory_.create_multiply_command ();
            }
            else if (token == "/")
            {
                cmd = factory_.create_division_command ();
            }
            else if (token == "%")
            {
                cmd = factory_.create_modulus_command ();
            }
            else // token == number
            {
                is_num = true;
                int number = stoi(token);
                cmd = factory_.create_number_command (number);
            }

            // check if command is a Number command
            if (is_num)
            {
                // throught it into the postfix
                insert_postfix(postfix , cmd , location);
            }
            else // cmd is not Num_Command
            {
                keep_looking = true;

                // Look through temp stack to keep precendence 
                while (keep_looking)
                {
                    // if stack is empty just insert the command
                    if (temp.is_empty ())
                    {
                        temp.push (cmd);
                        // stop looking
                        keep_looking = false;
                    }
                    // check if current command has has a greater precedence that temp
                    // command.
                    else if (temp.top()->precedence () < cmd->precedence())
                    {
                        // push command into stack
                        temp.push (cmd);
                        // stop looking
                        keep_looking = false;
                    }
                    else
                    {
                        // Keep inserting commands into postfix until one of the
                        // above branches are true
                        insert_postfix(postfix , temp.pop () , location);
                    }
                }
            }
        }
        else if (token == ")")
        {
            // get the rest of the stringstream 
            getline (input , continuation);
            // clear the stringstream
            input.clear ();

            // Begin to pop all element from temp stack and insert them into postfix
            while (!temp.is_empty ())
            {
                insert_postfix (postfix , temp.pop () , location);
            }

            // return rest of string
            return continuation;
        }
        else if (token == "(")
        {
             
            // store the rest of input into continuation
            getline (input , continuation);

            // clear input 
            input.clear ();

            // Call infix_to_postfix to read
            // a new part of the string once
            // this instance hits a ')' token
            // return to this version
            continuation = infix_to_postfix (continuation , postfix , location);

            // Check if continuation is empty
            if (continuation != "" && continuation != "DONE")
            {
                // if there are still more tokens continue
                input.str (continuation);
            }
            else
            {
                // break
                break;
            }
        }

    }

    // Pop all elements from tempstack and insert into postfix
    while (!temp.is_empty ())
    {
        insert_postfix (postfix , temp.pop () , location);
    }

    // Returns Done if there is no more string
    return "DONE";
}

//
// evaluate_postfix (Array <Expr_Command *>)
//
void Calculator::evaluate_postfix (Array <Expr_Command *> & postfix)
{
    // Iterator through postfix and exectue the commands
    for (int i = 0; i < postfix.size (); i++)
    {
        // Perform commands in the array
        postfix.get(i)->execute();
    }
}

//
// validate_equation (string)
//
bool Calculator::validate_equation (std::string & str)
{
    // Declare counters
    // l_count counts '('
    // r_count counts ')'
    int l_count = 0 , r_count = 0;

    // for loop to check each char
    for (int i = 0 ; i < str.length () ; i++)
    {
        // checks
        if (str[i] == '(')
        {
            l_count++;
        }
        else if (str[i] == ')')
        {
            r_count++;
        }
    }

    // if there is a discrepence then return false
    if (l_count == r_count)
    {
        return true;
    }
    else
    {
        return false;
    }
}