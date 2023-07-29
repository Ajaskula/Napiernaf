public interface BooleanCondition {
  abstract boolean evaluate(State variables, Expression left, Expression right)
      throws VariableNotFoundException, ZeroDivisionException;

  abstract String getOperator();
}
