// represents Subtraction Expressions
// enable to display and evaluate subtraction of expressions
public class Subtraction extends Expression {
  private Expression expresion1;
  private Expression expression2;

  Subtraction(Expression expression1, Expression expression2) throws IllegalArgumentException {
    if (expression1 == null || expression2 == null) {
      throw new IllegalArgumentException("Expression can't be null");
    }
    this.expresion1 = expression1;
    this.expression2 = expression2;
  }

  // calculate a value as a diff between values of two expressions
  @Override
  public int evaluate(State variables) throws VariableNotFoundException, ZeroDivisionException {
    int value1 = expresion1.evaluate(variables);
    int value2 = expression2.evaluate(variables);
    return value1 - value2;
  }

  @Override
  public String display() {
    return expresion1.display() + "-" + expression2.display();
  }
}
