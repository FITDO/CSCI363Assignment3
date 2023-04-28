#include "Stack_Expr_Command_Factory.h"

//
// Stack_Expr_Command_Factory (Stack <int>)
//
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack <int> & stack)
: stack_ (stack) ,
 num_commands_ (10) ,
 count_ (0) ,
 add_command_ (nullptr) ,
 subtract_command_ (nullptr) ,
 multiply_command_ (nullptr) ,
 division_command_ (nullptr) ,
 modulus_command_ (nullptr)
{

}

//
// ~Stack_Expr_Command_Factory
//
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void)
{
    delete add_command_;
    delete subtract_command_;
    delete multiply_command_;
    delete division_command_;
    delete modulus_command_;
    
    for (int i = 0 ; i < num_commands_.size () ; i++)
    {
        delete num_commands_[i];
    }
}

//
// create_number_command (int)
//
Num_Command * Stack_Expr_Command_Factory::create_number_command (int num)
{
    // make a number command
    Num_Command * holder = new Num_Command (this->stack_ , num);

    // Check if there is room to add to the array
    if (count_ >= num_commands_. size ())
    {
        this->num_commands_.resize ( count_ + 5);
    }

    // Insert number command into the array
    this->num_commands_[count_] = holder;

    count_++;

    // Return number command
    return holder;
}

//
// create_add_command
//
Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{
    // Check if add command is already made
    if (!add_command_)
    {
        // make a new one
        this->add_command_ = new Add_Command (this->stack_);
    }
    // return add command
    return this->add_command_;
}

//
// create_subtract_command
//
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
    // Check if subtract command is already made
    if (!subtract_command_)
    {
        // Make a new one
        this->subtract_command_ = new Subtract_Command (this->stack_);
    }
    // Return subtract command
    return this->subtract_command_;
}

//
// create_multiply_command
//
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{
    // Check if multiply command is already made
    if (!multiply_command_)
    {
        // Make a new one
        this->multiply_command_ = new Multiply_Command (this->stack_);
    }
    // Return multiply command
    return this->multiply_command_;
}

//
// create_division_command
//
Division_Command * Stack_Expr_Command_Factory::create_division_command (void)
{
    // Check if division command already exists
    if (!division_command_)
    {
        // Make a new one
        this->division_command_ = new Division_Command (this->stack_);
    }
    //Return division command
    return this->division_command_;
}

//
// create_modulus_command
//
Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void)
{
    // Check if modulus command already exists
    if (!modulus_command_)
    {
        // Make a new one
        this->modulus_command_ = new Modulus_Command (this->stack_);
    }
    // Return modulus command
    return this->modulus_command_;
}

//
// clear_all
//
void Stack_Expr_Command_Factory::clear_all (void)
{
    // Check if pointer is not nullptr
    // if it isnt give back the memory

    if (add_command_)
    {
        delete add_command_;
        this->add_command_ = nullptr;
    }

    if (subtract_command_)
    {
        delete subtract_command_;
        this->subtract_command_ = nullptr;
    }

    if (multiply_command_)
    {
        delete multiply_command_;
        this->multiply_command_ = nullptr;
    }

    if (division_command_)
    {
        delete division_command_;
        this->division_command_ = nullptr;
    }

    if (modulus_command_)
    {
        delete modulus_command_;
        this->modulus_command_ = nullptr;
    }

    // call clear_num_commands
    this->clear_num_commands ();
}

//
// clear_num_commands
//
void Stack_Expr_Command_Factory::clear_num_commands (void)
{
    // Iterator through num_coommands to delete all pointers
    for (int i = 0 ; i < num_commands_.size () ; i++)
    {
        delete num_commands_[i];
        num_commands_[i] = nullptr;
    }

    // reset counter
    this->count_ = 0;
}