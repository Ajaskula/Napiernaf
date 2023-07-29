public class Main {
  // This is Program from the task, there are some commented lines to test this code for Exceptions
  public static void main(String[] args) {
    // This is program from the task
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ProgramBlock glownyBlok = new ProgramBlock();

    VariableDeclaration przyp1 = new VariableDeclaration('n', new NumericalLiteral(30));

    glownyBlok.addDeclaration(przyp1);

    ForLoop petla1 =
        new ForLoop(new Variable('k'), new Subtraction(new Variable('n'), new NumericalLiteral(1)));

    glownyBlok.addInstruction(petla1);

    ProgramBlock blokwew = new ProgramBlock();

    petla1.addInstruction(blokwew);

    VariableDeclaration przyp2 = new VariableDeclaration('p', new NumericalLiteral(1));

    blokwew.addDeclaration(przyp2);

    AssigmentInstruction przyp =
        new AssigmentInstruction('k', new Addition(new Variable('k'), new NumericalLiteral(2)));

    blokwew.addInstruction(przyp);

    ForLoop loop2 =
        new ForLoop(new Variable('i'), new Subtraction(new Variable('k'), new NumericalLiteral(2)));
    blokwew.addInstruction(loop2);

    AssigmentInstruction przyp3 =
        new AssigmentInstruction('i', new Addition(new Variable('i'), new NumericalLiteral(2)));

    loop2.addInstruction(przyp3);

    IfInstruction war2 = new IfInstruction(new Modulo(new Variable('k'), new Variable('i')),
        new NumericalLiteral(0), new EqExpression());

    loop2.addInstruction(war2);

    AssigmentInstruction przpy4 = new AssigmentInstruction('p', new NumericalLiteral(0));

    war2.addIfInstruction(przpy4);

    IfInstruction war3 =
        new IfInstruction(new Variable('p'), new NumericalLiteral(1), new EqExpression());
    blokwew.addInstruction(war3);

    Print pri = new Print(new Variable('k'));

    war3.addIfInstruction(pri);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // This is code to test program for VariableAlreadyDeclaredException
    //       ProgramBlock glownyBlok = new ProgramBlock();
    //
    //       VariableDeclaration przyp1 = new VariableDeclaration('n', new NumericalLiteral(30));
    //
    //       glownyBlok.addDeclaration(przyp1);
    //
    //       ForLoop petla1 =
    //               new ForLoop(new Variable('k'), new Subtraction(new Variable('n'), new
    //               NumericalLiteral(1)));
    //
    //       glownyBlok.addInstruction(petla1);
    //
    //       ProgramBlock blokwew = new ProgramBlock();
    //
    //       petla1.addInstruction(blokwew);
    //
    //       VariableDeclaration przyp2 = new VariableDeclaration('p', new NumericalLiteral(1));
    //     VariableDeclaration przyp9 = new VariableDeclaration('p', new NumericalLiteral(1));
    //
    //       blokwew.addDeclaration(przyp2);
    //     blokwew.addDeclaration(przyp9);
    //
    //       AssigmentInstruction przyp =
    //               new AssigmentInstruction('k', new Addition(new Variable('k'), new
    //               NumericalLiteral(2)));
    //
    //       blokwew.addInstruction(przyp);
    //
    //       ForLoop loop2 =
    //               new ForLoop(new Variable('i'), new Subtraction(new Variable('k'), new
    //               NumericalLiteral(2)));
    //       blokwew.addInstruction(loop2);
    //
    //       AssigmentInstruction przyp3 =
    //               new AssigmentInstruction('i', new Addition(new Variable('i'), new
    //               NumericalLiteral(2)));
    //
    //       loop2.addInstruction(przyp3);
    //
    //       IfInstruction war2 = new IfInstruction(new Modulo(new Variable('k'), new
    //       Variable('i')),
    //               new NumericalLiteral(0), new EqExpression());
    //
    //       loop2.addInstruction(war2);
    //
    //       AssigmentInstruction przpy4 = new AssigmentInstruction('p', new NumericalLiteral(0));
    //
    //       war2.addIfInstruction(przpy4);
    //
    //       IfInstruction war3 =
    //               new IfInstruction(new Variable('p'), new NumericalLiteral(1), new
    //               EqExpression());
    //       blokwew.addInstruction(war3);
    //
    //       Print pri = new Print(new Variable('k'));
    //
    //       war3.addIfInstruction(pri);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // This is code to test program for ZeroDivisionException
    //       ProgramBlock glownyBlok = new ProgramBlock();
    //
    //       VariableDeclaration przyp1 = new VariableDeclaration('n', new NumericalLiteral(30));
    //
    //       glownyBlok.addDeclaration(przyp1);
    //
    //       ForLoop petla1 =
    //               new ForLoop(new Variable('k'), new Subtraction(new Variable('n'), new
    //               NumericalLiteral(1)));
    //
    //       glownyBlok.addInstruction(petla1);
    //
    //       ProgramBlock blokwew = new ProgramBlock();
    //
    //       petla1.addInstruction(blokwew);
    //
    //       VariableDeclaration przyp2 = new VariableDeclaration('p', new NumericalLiteral(1));
    //
    //       blokwew.addDeclaration(przyp2);
    //
    //       AssigmentInstruction przyp =
    //               new AssigmentInstruction('k', new Addition(new Variable('k'), new
    //               NumericalLiteral(2)));
    //
    //       blokwew.addInstruction(przyp);
    //
    //       ForLoop loop2 =
    //               new ForLoop(new Variable('i'), new Subtraction(new Variable('k'), new
    //               NumericalLiteral(2)));
    //       blokwew.addInstruction(loop2);
    //
    //       AssigmentInstruction przyp3 =
    //               new AssigmentInstruction('i', new Addition(new Variable('i'), new
    //               NumericalLiteral(0)));
    //
    //       loop2.addInstruction(przyp3);
    //
    //       IfInstruction war2 = new IfInstruction(new Division(new Variable('k'), new
    //       Variable('i')),
    //               new NumericalLiteral(0), new EqExpression());
    //
    //       loop2.addInstruction(war2);
    //
    //       AssigmentInstruction przpy4 = new AssigmentInstruction('p', new NumericalLiteral(0));
    //
    //       war2.addIfInstruction(przpy4);
    //
    //       IfInstruction war3 =
    //               new IfInstruction(new Variable('p'), new NumericalLiteral(1), new
    //               EqExpression());
    //       blokwew.addInstruction(war3);
    //
    //       Print pri = new Print(new Variable('k'));
    //
    //       war3.addIfInstruction(pri);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // This is code to test program for ModuloException
    //       ProgramBlock glownyBlok = new ProgramBlock();
    //
    //       VariableDeclaration przyp1 = new VariableDeclaration('n', new NumericalLiteral(30));
    //
    //       glownyBlok.addDeclaration(przyp1);
    //
    //       ForLoop petla1 =
    //               new ForLoop(new Variable('k'), new Subtraction(new Variable('n'), new
    //               NumericalLiteral(1)));
    //
    //       glownyBlok.addInstruction(petla1);
    //
    //       ProgramBlock blokwew = new ProgramBlock();
    //
    //       petla1.addInstruction(blokwew);
    //
    //       VariableDeclaration przyp2 = new VariableDeclaration('p', new NumericalLiteral(1));
    //
    //       blokwew.addDeclaration(przyp2);
    //
    //       AssigmentInstruction przyp =
    //               new AssigmentInstruction('k', new Addition(new Variable('k'), new
    //               NumericalLiteral(2)));
    //
    //       blokwew.addInstruction(przyp);
    //
    //       ForLoop loop2 =
    //               new ForLoop(new Variable('i'), new Subtraction(new Variable('k'), new
    //               NumericalLiteral(2)));
    //       blokwew.addInstruction(loop2);
    //
    //       AssigmentInstruction przyp3 =
    //               new AssigmentInstruction('i', new Addition(new Variable('i'), new
    //               NumericalLiteral(0)));
    //
    //       loop2.addInstruction(przyp3);
    //
    //       IfInstruction war2 = new IfInstruction(new Modulo(new Variable('k'), new
    //       Variable('i')),
    //               new NumericalLiteral(0), new EqExpression());
    //
    //       loop2.addInstruction(war2);
    //
    //       AssigmentInstruction przpy4 = new AssigmentInstruction('p', new NumericalLiteral(0));
    //
    //       war2.addIfInstruction(przpy4);
    //
    //       IfInstruction war3 =
    //               new IfInstruction(new Variable('p'), new NumericalLiteral(1), new
    //               EqExpression());
    //       blokwew.addInstruction(war3);
    //
    //       Print pri = new Print(new Variable('k'));
    //
    //       war3.addIfInstruction(pri);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // This is code to test program for VariableNotFoundException
    //       ProgramBlock glownyBlok = new ProgramBlock();
    //
    //       VariableDeclaration przyp1 = new VariableDeclaration('n', new NumericalLiteral(30));
    //
    //       glownyBlok.addDeclaration(przyp1);
    //
    //       ForLoop petla1 =
    //               new ForLoop(new Variable('k'), new Subtraction(new Variable('n'), new
    //               NumericalLiteral(1)));
    //
    //       glownyBlok.addInstruction(petla1);
    //
    //       ProgramBlock blokwew = new ProgramBlock();
    //
    //       petla1.addInstruction(blokwew);
    //
    //       VariableDeclaration przyp2 = new VariableDeclaration('p', new NumericalLiteral(1));
    //
    //       blokwew.addDeclaration(przyp2);
    //
    //       AssigmentInstruction przyp =
    //               new AssigmentInstruction('k', new Addition(new Variable('k'), new
    //               NumericalLiteral(2)));
    //
    //       blokwew.addInstruction(przyp);
    //
    //       ForLoop loop2 =
    //               new ForLoop(new Variable('i'), new Subtraction(new Variable('j'), new
    //               NumericalLiteral(2)));
    //       blokwew.addInstruction(loop2);
    //
    //       AssigmentInstruction przyp3 =
    //               new AssigmentInstruction('i', new Addition(new Variable('i'), new
    //               NumericalLiteral(2)));
    //
    //       loop2.addInstruction(przyp3);
    //
    //       IfInstruction war2 = new IfInstruction(new Modulo(new Variable('k'), new
    //       Variable('i')),
    //               new NumericalLiteral(0), new EqExpression());
    //
    //       loop2.addInstruction(war2);
    //
    //       AssigmentInstruction przpy4 = new AssigmentInstruction('p', new NumericalLiteral(0));
    //
    //       war2.addIfInstruction(przpy4);
    //
    //       IfInstruction war3 =
    //               new IfInstruction(new Variable('p'), new NumericalLiteral(1), new
    //               EqExpression());
    //       blokwew.addInstruction(war3);
    //
    //       Print pri = new Print(new Variable('k'));
    //
    //       war3.addIfInstruction(pri);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ProgramExecution execute = new ProgramExecution(glownyBlok);
    // uncomment this to run program with debugging
    execute.debug();
    // uncomment this to run program without debugging
    //      execute.execute();
  }
}