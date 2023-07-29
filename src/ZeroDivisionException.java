public class ZeroDivisionException extends Exception {
  public ZeroDivisionException() {
    super("There was an attempt to divide by 0!");
  }

  public ZeroDivisionException(String string) {
    super(string);
  }
}
