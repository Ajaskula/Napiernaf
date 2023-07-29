public class ModuloException extends ArithmeticException {
  public ModuloException(Expression expression) {
    super("Can't perform " + expression.display() + " % 0 operation");
  }

  public ModuloException(String string) {
    super(string);
  }
}
