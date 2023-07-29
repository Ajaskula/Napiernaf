// represents numerical literal expression in Macchiato
public class NumericalLiteral extends Expression {
  private int value;

  public NumericalLiteral(int value) {
    this.value = value;
  }

  @Override
  public int evaluate(State variables) {
    return this.value;
  }

  @Override
  public String display() {
    return Integer.toString(value);
  }
}
