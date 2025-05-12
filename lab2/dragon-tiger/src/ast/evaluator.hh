#include "ast_dumper.hh"

namespace ast {

class Evaluator : public ConstASTVisitor {
public:
  // точка входу: даєш корінь AST і отримуєш int або помилку
  int evaluate(const Expr &root);
  
  // інші — залиште або киньте помилку
  virtual void visit(const IntegerLiteral &lit) override;
  virtual void visit(const BinaryOperator &op) override;
  virtual void visit(const Sequence &seq) override;
  virtual void visit(const IfThenElse &ite) override;
  // решта вузлів: киньте utils::error("cannot eval this node")
private:
  int result_;  // сюди зберігайте поточний обчислений результат
};

} // namespace ast
