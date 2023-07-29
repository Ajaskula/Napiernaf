public class VariableAlreadyDeclaredException extends Exception {
  public VariableAlreadyDeclaredException(Character name) {
    super("Variable " + name + " has been declared before");
  }

  public VariableAlreadyDeclaredException(String string) {
    super(string);
  }
}
