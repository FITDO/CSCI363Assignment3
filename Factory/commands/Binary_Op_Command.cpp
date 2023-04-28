#include "Binary_Op_Command.h"

//
// Binary_Op_Command ( Stack <int> , int)
//
Binary_Op_Command::Binary_Op_Command(Stack <int> & s , int p)
: Expr_Command (p) ,
s_ (s)
{

}

//
// execute
//
void Binary_Op_Command::execute (void)
{
    // Pops two element
    int n2 = s_.pop () , n1 = s_.pop ();
    // call the evaluate method
    int result = this->evaluate (n1 , n2);
    // pushes result back to the stack
    s_.push ( result );
}
