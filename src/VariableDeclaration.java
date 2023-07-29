public class VariableDeclaration {
  private Expression expression;
  private Character name;

  public VariableDeclaration(Character name, Expression expression) {
    if (name == null || expression == null || !name.isLowerCase(name)) {
      throw new IllegalArgumentException("Illegal variable name");
    }
    this.expression = expression;
    this.name = name;
  }

  // adds variable to the current state
  public void execute(State variables) throws VariableAlreadyDeclaredException,
                                              VariableNotFoundException, ZeroDivisionException,
                                              ModuloException {
    variables.addVariable(this.name, this.expression.evaluate(variables));
  }
}
