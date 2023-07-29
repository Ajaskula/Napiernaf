import java.io.IOException;

abstract class Instruction {
  abstract void execute(State declarations, Debugger debugger)
      throws IOException, VariableNotFoundException, VariableAlreadyDeclaredException,
             ZeroDivisionException;

  abstract String display(int level);
}
