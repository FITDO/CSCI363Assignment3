#include "Num_Command.h"

//
// Num_Command (Stack<int> int)
//
Num_Command::Num_Command (Stack <int> & s , int n)
: Expr_Command (0) ,
  s_ (s) ,
  n_ (n)
{

}