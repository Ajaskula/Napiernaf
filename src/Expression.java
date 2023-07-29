abstract class Expression {
  abstract int evaluate(State variables) throws VariableNotFoundException, ZeroDivisionException;

  abstract String display();
}
