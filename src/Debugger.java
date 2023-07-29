import java.io.IOException;
import java.util.Scanner;

// enable to run programs in Macchiato and follow it's instructions
// make available orders:
// c - continue running of the program, at the end displays values of variables in the most external
// block s <number> - program performs <number> steps, and display next instruction to go d <number>
// - displays current values of available variables, numbers informs how many external block
// variables will be displayed e - disrupt running of a program
public class Debugger {
  // number of instructions to perform
  int counter;

  public Debugger(int counter) {
    this.counter = counter;
  }

  void trace_instructions(Instruction i, State state) throws IOException {
    if (counter == 0) {
      System.out.print(i.display(0));
      while (true) {
        // takes instruction from a user
        int command = System.in.read();
        Scanner scanner = new Scanner(System.in);
        switch (command) {
          // ends program
          case 'e':
            System.exit(1);
            // displays current State
          case 'd':
            int value = scanner.nextInt();
            if (state != null) {
              System.out.print(state.display_level(value));
            } else {
              System.out.println("Block is not nested so many times");
            }
            break;
          // continue
          case 'c':
            counter = -1;
            return;
          // perform <number> next steps, and display next instruction
          case 's':
            int steps = 1;
            scanner.useDelimiter("\\s+");
            if (scanner.hasNextInt()) {
              steps = scanner.nextInt();
            }
            counter = steps;
            return;
        }
      }
    }
    if (counter != -1) {
      counter--;
    }
  }
}
