// represents Modulo Expressions
// enable to display and evaluate Modulo operation of two expressions
public class Modulo extends Expression {
  private Expression expresion1;
  private Expression expresion2;

  Modulo(Expression expression1, Expression expression2) throws IllegalArgumentException {
    if (expression1 == null || expression2 == null) {
      throw new IllegalArgumentException("Expression can't be null");
    }
    this.expresion1 = expression1;
    this.expresion2 = expression2;
  }

  @Override
  public int evaluate(State variables)
      throws ArithmeticException, VariableNotFoundException, ZeroDivisionException {
    int value1 = expresion1.evaluate(variables);
    int value2 = expresion2.evaluate(variables);
    if (value2 == 0) {
      throw new ModuloException(expresion1);
    }
    return value1 % value2;
  }

  @Override
  public String display() {
    return expresion1.display() + " % " + expresion2.display();
  }
}
