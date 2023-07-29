import java.io.IOException;

// This class execute programs in Macchiato
// there are two options to execute with (debug) and without debugger (execute)
public class ProgramExecution {
  private ProgramBlock block;

  public ProgramExecution(ProgramBlock block) {
    this.block = block;
  }

  public void addBlock(ProgramBlock block) {
    this.block = block;
  }

  // execute program without debugger
  public void execute() {
    try {
      Debugger debugger = new Debugger(-1);
      block.execute(null, debugger);

    } catch (VariableAlreadyDeclaredException e) {
      System.out.println(e.getMessage());
    } catch (VariableNotFoundException e) {
      System.out.println(e.getMessage());
    } catch (ZeroDivisionException e) {
      System.out.println(e.getMessage());
    } catch (ModuloException e) {
      System.out.println(e.getMessage());
    } catch (IOException e) {
      System.out.println("Input or output error has appeared!");
    }
  }

  // execute program with debugger
  public void debug() {
    Debugger debugger = new Debugger(0);
    try {
      block.execute(null, debugger);
      if (debugger.counter > 0) {
        System.out.println("Program ended in less number of steps");
      }
    } catch (VariableAlreadyDeclaredException e) {
      System.out.println(e.getMessage());
    } catch (VariableNotFoundException e) {
      System.out.println(e.getMessage());
    } catch (ZeroDivisionException e) {
      System.out.println(e.getMessage());
    } catch (ModuloException e) {
      System.out.println(e.getMessage());
    } catch (IOException e) {
      System.out.println("Input or output error has appeared!");
    }
  }
}
