#include "evaluator.hh"

namespace ast {

void Evaluator::visit(const IntegerLiteral &lit) {
  result_ = lit.value;
}

void Evaluator::visit(const BinaryOperator &binop) {
  // 1) обчислити лівий
  binop.get_left().accept(*this);
  int lhs = result_;

  // 2) обчислити правий
  binop.get_right().accept(*this);
  int rhs = result_;

  // 3) застосувати потрібну операцію
  switch (binop.op) {
    case o_plus:   result_ = lhs + rhs; break;
    case o_minus:  result_ = lhs - rhs; break;
    case o_times:  result_ = lhs * rhs; break;
    case o_divide:
      if (rhs == 0) utils::error("division by zero");
      result_ = lhs / rhs;
      break;
    case o_eq:     result_ = (lhs == rhs); break;
    case o_neq:    result_ = (lhs != rhs); break;
    case o_lt:     result_ = (lhs < rhs);  break;
    case o_le:     result_ = (lhs <= rhs); break;
    case o_gt:     result_ = (lhs > rhs);  break;
    case o_ge:     result_ = (lhs >= rhs); break;
    default:
      utils::error("unknown binary operator");
  }
}

void Evaluator::visit(const Sequence &seq) {
  const auto &exprs = seq.get_exprs();
  if (exprs.empty()) {
    utils::error("empty sequence");
  }
  for (auto &e : exprs) {
    e->accept(*this);
  }
}

void Evaluator::visit(const IfThenElse &ite) {
  int cond = evaluate(ite.get_condition());
  if (cond != 0) {
    result_ = evaluate(ite.get_then_part());
  } else {
    result_ = evaluate(ite.get_else_part());
  }
}

} 
