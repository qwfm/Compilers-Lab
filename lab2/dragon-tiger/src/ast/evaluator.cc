#include "evaluator.hh"
#include "../utils/errors.hh"

namespace ast {
int Evaluator::evaluate(const Expr &root) {
  root.accept(*this);
  return result_;
}

void Evaluator::visit(const IntegerLiteral &lit) {
  int result_ = lit.value;
}

void Evaluator::visit(const BinaryOperator &op) {
  op.get_left().accept(*this); 
  int lhs = result_;
  op.get_right().accept(*this); 
  int rhs = result_;
  switch (op.op) {
    case o_plus:   lhs + rhs;
    case o_minus:  lhs - rhs;
    case o_times:  lhs * rhs;
    case o_divide:
      if (rhs == 0)
        {
            utils::error("division by zero");
            return;
        }
        
      lhs / rhs;
    case o_eq:    lhs == rhs;
    case o_neq:   lhs != rhs;
    case o_lt:    lhs < rhs;
    case o_le:    lhs <= rhs;
    case o_gt:    lhs > rhs;
    case o_ge:    lhs >= rhs;
    default:
      utils::error("unknown operator");
  }
}
void visit(const IfThenElse &ite) {

}
}