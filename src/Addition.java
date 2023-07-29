// represents Addition Expressions
// enable to display and evaluate sum of expressions
public class Addition extends Expression {
  private Expression expresion1;
  private Expression expresion2;

  Addition(Expression expression1, Expression expression2) throws IllegalArgumentException {
    if (expression1 == null || expression2 == null) {
      throw new IllegalArgumentException("Expression can't be null");
    }
    this.expresion1 = expression1;
    this.expresion2 = expression2;
  }

  // calculates value of addition as a sum of it's expressions
  @Override
  public int evaluate(State variables) throws VariableNotFoundException, ZeroDivisionException {
    int value1 = expresion1.evaluate(variables);
    int value2 = expresion2.evaluate(variables);
    return value1 + value2;
  }

  // displays Addition object as a sum of two it's expressions
  @Override
  public String display() {
    return expresion1.display() + "+" + expresion2.display();
  }
}
