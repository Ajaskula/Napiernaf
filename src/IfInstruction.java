import java.io.IOException;

// represents if instruction in Macchiato
public class IfInstruction extends Instruction {
  // left side condition's expression
  private Expression expression1;
  // right side condition's expression
  private Expression expression2;
  private Block ifInstructions;
  private Block elseInstructions;

  private BooleanCondition condition;

  public IfInstruction(Block ifInstructions, Block elseInstructions, Expression expression1,
      Expression expression2) {
    this.ifInstructions = ifInstructions;
    this.elseInstructions = elseInstructions;
    this.expression1 = expression1;
    this.expression2 = expression2;
  }

  public IfInstruction(Expression expression1, Expression expression2, BooleanCondition condition) {
    this.ifInstructions = new Block();
    this.elseInstructions = new Block();
    this.expression1 = expression1;
    this.expression2 = expression2;
    this.condition = condition;
  }

  @Override
  public void execute(State variables, Debugger debugger)
      throws IOException, VariableNotFoundException, ZeroDivisionException,
             VariableAlreadyDeclaredException, ModuloException {
    debugger.trace_instructions(this, variables);
    try {
      if (condition.evaluate(variables, expression1, expression2)) {
        ifInstructions.execute(variables, debugger);
      } else if (elseInstructions.getInstructions().size() != 0) {
        elseInstructions.execute(variables, debugger);
      }
    } catch (VariableNotFoundException e) {
      throw new VariableNotFoundException(
          e.getMessage() + " in: \n" + this.display(0) + "\n" + variables.display_level(0));
    } catch (ZeroDivisionException e) {
      throw new ZeroDivisionException(
          e.getMessage() + " in: \n" + this.display(0) + "\n" + variables.display_level(0));
    } catch (ModuloException e) {
      throw new ModuloException(
          e.getMessage() + " in: \n" + this.display(0) + "\n" + variables.display_level(0));
    }
  }

  public void addIfInstruction(Instruction instruction) {
    this.ifInstructions.getInstructions().add(instruction);
  }

  public void addElseInstruction(Instruction instruction) {
    this.elseInstructions.getInstructions().add(instruction);
  }

  @Override
  public String display(int level) {
    StringBuilder sb = new StringBuilder();
    sb.append("  ".repeat(level)).append("if");
    sb.append("( ");
    sb.append(expression1.display()).append(condition.getOperator());
    sb.append(expression2.display()).append(" )\n");

    if (ifInstructions.getInstructions().size() != 0) {
      sb.append(ifInstructions.display(level + 1));
    }
    if (elseInstructions.getInstructions().size() != 0) {
      sb.append("  ".repeat(level)).append("else\n");
      sb.append(elseInstructions.display(level + 1));
    }

    return sb.toString();
  }
}
