import java.io.IOException;

// represents Assigment instruction
// enable to assign evaluated value of expression to a variable (name)
public class AssigmentInstruction extends Instruction {
  private Character name;
  private Expression expression;

  public AssigmentInstruction(Character name, Expression expression) {
    this.name = name;
    this.expression = expression;
  }

  // assigns evaluated value of expression to variable (name)
  // if there is no declared variable as name than throws an exception
  // if an error appeared during calculating expression value, variable value is not modified
  public void execute(State variables, Debugger debugger)
      throws IOException, VariableNotFoundException, ZeroDivisionException, ModuloException {
    try {
      debugger.trace_instructions(this, variables);
      int value = expression.evaluate(variables);
      variables.setVariable(name, value);
    } catch (VariableNotFoundException e) {
      throw new VariableNotFoundException(
          e.getMessage() + " in:\n " + this.display(0) + "\n" + variables.display_level(0));
    }
  }

  // level informs how many times instruction is nested
  public String display(int level) {
    return ("  ".repeat(level) + this.name + " = " + expression.display() + "\n");
  }
}
