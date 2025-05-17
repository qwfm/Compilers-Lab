#include "ast_dumper.hh"   
#include "nodes.hh"
#include "../utils/errors.hh"

namespace ast {

class Evaluator : public ConstASTVisitor {
  int result_;  

public:
  int evaluate(const Expr &root) {
    root.accept(*this);
    return result_;
  }

  virtual void visit(const IntegerLiteral &lit) override;
  virtual void visit(const BinaryOperator &op) override;
  virtual void visit(const Sequence &seq) override;
  virtual void visit(const IfThenElse &ite) override;

  virtual void visit(const StringLiteral &)        override { utils::error("cannot evaluate StringLiteral"); }
  virtual void visit(const Let &)                  override { utils::error("cannot evaluate Let"); }
  virtual void visit(const Identifier &)           override { utils::error("cannot evaluate Identifier"); }
  virtual void visit(const VarDecl &)              override { utils::error("cannot evaluate VarDecl"); }
  virtual void visit(const FunDecl &)              override { utils::error("cannot evaluate FunDecl"); }
  virtual void visit(const FunCall &)              override { utils::error("cannot evaluate FunCall"); }
  virtual void visit(const WhileLoop &)            override { utils::error("cannot evaluate WhileLoop"); }
  virtual void visit(const ForLoop &)              override { utils::error("cannot evaluate ForLoop"); }
  virtual void visit(const Break &)                override { utils::error("cannot evaluate Break"); }
  virtual void visit(const Assign &)               override { utils::error("cannot evaluate Assign"); }
};

} 
