public class LessEqExpression implements BooleanCondition {
  @Override
  public boolean evaluate(State variables, Expression left, Expression right)
      throws VariableNotFoundException, ZeroDivisionException {
    return left.evaluate(variables) <= right.evaluate(variables);
  }

  @Override
  public String getOperator() {
    return " <= ";
  }
}