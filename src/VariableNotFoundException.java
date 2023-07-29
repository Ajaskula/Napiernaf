public class VariableNotFoundException extends Exception {
  public VariableNotFoundException(Character name) {
    super("Variable " + name + " not found");
  }

  public VariableNotFoundException(String string) {
    super(string);
  }
}
