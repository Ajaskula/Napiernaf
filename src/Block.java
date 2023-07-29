import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Block {
  private List<Instruction> instructions;

  public Block() {
    this.instructions = new ArrayList<>();
  }

  public List<Instruction> getInstructions() {
    return this.instructions;
  }
  public void addInstruction(Instruction instruction) {
    this.instructions.add(instruction);
  }

  public void execute(State variables, Debugger debugger)
      throws IOException, VariableNotFoundException, VariableAlreadyDeclaredException,
             ZeroDivisionException, ModuloException {
    // execute instructions
    for (Instruction instruction : instructions) {
      instruction.execute(variables, debugger);
    }
  }

  public String display(int level) {
    StringBuilder sb = new StringBuilder();
    for (Instruction instruction : instructions) {
      sb.append(instruction.display(level));
    }
    return sb.toString();
  }
}
