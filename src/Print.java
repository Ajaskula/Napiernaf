import java.io.IOException;

// represents Print instruction in Macchiato
// enables to display expression evaluation
public class Print extends Instruction {
  private Expression expression;

  public Print(Expression expression) {
    this.expression = expression;
  }

  @Override
  public void execute(State variables, Debugger debugger)
      throws IOException, VariableNotFoundException, ZeroDivisionException, ModuloException {
    debugger.trace_instructions(this, variables);
    try {
      int value = expression.evaluate(variables);
      System.out.println(value);
    } catch (ZeroDivisionException e) {
      throw new ZeroDivisionException(
          e.getMessage() + " in:\n " + this.display(0) + "\n" + variables.display_level(0));
    } catch (ModuloException e) {
      throw new ModuloException(
          e.getMessage() + " in:\n " + this.display(0) + "\n" + variables.display_level(0));
    }
  }

  @Override
  public String display(int level) {
    return "  ".repeat(level) + " print " + expression.display() + "\n";
  }
}
