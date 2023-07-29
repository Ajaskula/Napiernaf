// represtents variable in Macchiato language
public class Variable extends Expression {
  private Character name;

  public Variable(Character name) throws IllegalArgumentException {
    if (name == null || !name.isLowerCase(name)) {
      throw new IllegalArgumentException(
          "Argument name has to be a lowercase letter! but is " + name.toString());
    }
    this.name = name;
  }

  public Character getName() {
    return this.name;
  }

  @Override
  public int evaluate(State variables) throws VariableNotFoundException {
    return variables.getVariableValue(name);
  }

  @Override
  public String display() {
    return Character.toString(name);
  }
}
