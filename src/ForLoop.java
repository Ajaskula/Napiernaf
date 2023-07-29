import java.io.IOException;

// represents ForLoop instruction
// enable to create ForLoop in Macchiato
public class ForLoop extends Instruction {
  // variable is an iterator of a loop
  private Variable variable;
  // instructions to perform in a loop
  private Block instructions;
  // condition of a loop
  private Expression expression;

  public ForLoop(Variable variable, Expression expression) {
    this.variable = variable;
    this.instructions = new Block();
    this.expression = expression;
  }

  public void addInstruction(Instruction instruction) {
    instructions.getInstructions().add(instruction);
  }

  @Override
  public void execute(State oldvariables, Debugger debugger)
      throws IOException, VariableNotFoundException, VariableAlreadyDeclaredException,
             ModuloException, ZeroDivisionException {
    State variables = new State(oldvariables);
    debugger.trace_instructions(this, oldvariables);
    int repeatNumber;

    try {
      repeatNumber = expression.evaluate(variables);
    } catch (ZeroDivisionException e) {
      throw new ZeroDivisionException(
          e.getMessage() + " in:\n " + this.display(0) + "\n" + variables.display_level(0));
    } catch (VariableNotFoundException e) {
      throw new VariableNotFoundException(
          e.getMessage() + " in:\n " + this.display(0) + "\n" + variables.display_level(0));
    } catch (ModuloException e) {
      throw new ModuloException(
          e.getMessage() + " in:\n " + this.display(0) + "\n" + variables.display_level(0));
    }
    if (!variables.checkIfVariableisDeclared(variable.getName())) {
      variables.addVariable(variable.getName(), 0);
    }
    for (int i = 0; i < repeatNumber; i++) {
      // set loop variable to the proper value
      variables.setVariable(variable.getName(), i);

      // perform loop instructions
      instructions.execute(variables, debugger);
    }
    variables.removeVariable(variable.getName());
  }
  @Override
  public String display(int level) {
    StringBuilder sb = new StringBuilder();
    sb.append("  ".repeat(level)).append("for ");
    sb.append(variable.display()).append(" ");
    sb.append(expression.display()).append("\n");
    sb.append(instructions.display(level + 1));
    return sb.toString();
  }
}
