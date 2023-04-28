// -*- C++ -*-
// $Id: Add_Command.inl 828 2022-3-31 14:21:52Z brajadam $

//
// precedence
//
inline
int Expr_Command::precedence (void) const
{
    return p_;
}