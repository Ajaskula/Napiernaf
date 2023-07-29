import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.Map;

// class represents the set of currently visible variables and their values0
public class State {
  private State parent;

  // stores variables and values visible in a given block
  private Map<Character, Integer> variables;

  public State(State parent) {
    this.parent = parent;
    this.variables = new IdentityHashMap<>();
  }

  public boolean checkIfVariableisDeclared(Character name) {
    if (this.variables.containsKey(name)) {
      return true;
    } else if (parent != null) {
      return parent.checkIfVariableisDeclared(name);
    }
    return false;
  }

  // displays values of variables declared in a <level> outside block
  public String display_level(int level) {
    StringBuilder sb = new StringBuilder();

    if (level > 0) {
      if (this.parent != null) {
        return parent.display_level(level - 1);
      } else {
        sb.append("Block is not nested this many times\n");
      }
    } else if (level == 0) {
      sb.append(display());
    }
    return sb.toString();
  }

  // set variable (name) to value
  public void setVariable(Character name, Integer value) throws VariableNotFoundException {
    if (this.variables.containsKey(name)) {
      this.variables.put(name, value);
    } else if (parent != null) {
      parent.setVariable(name, value);
    } else {
      throw new VariableNotFoundException(name);
    }
  }

  public Integer getVariableValue(Character name) throws VariableNotFoundException {
    if (this.variables != null && this.variables.containsKey(name)) {
      return variables.get(name);
    } else if (parent != null) {
      return parent.getVariableValue(name);
    } else {
      throw new VariableNotFoundException(name);
    }
  }

  // adds new variable to the map
  public void addVariable(Character name, Integer value) throws VariableAlreadyDeclaredException {
    if (variables.containsKey(name)) {
      throw new VariableAlreadyDeclaredException(name);
    } else {
      this.variables.put(name, value);
    }
  }

  public void removeVariable(Character name) {
    this.variables.remove(name);
  }

  public State getParent() {
    return this.parent;
  }

  public Map<Character, Integer> getVariables() {
    return this.variables;
  }

  public String display() {
    if (variables == null) {
      return "";
    }
    StringBuilder sb = new StringBuilder();

    Map<Character, Integer> mapToDisplay = new HashMap<>();

    mapToDisplay.putAll(variables);

    State parent = this.parent;

    while (parent != null) {
      Map<Character, Integer> parentVariables = parent.getVariables();
      for (Map.Entry<Character, Integer> variable : parentVariables.entrySet()) {
        if (!mapToDisplay.containsKey(variable.getKey())) {
          mapToDisplay.put(variable.getKey(), variable.getValue());
        }
      }

      parent = parent.getParent();
    }
    for (Map.Entry<Character, Integer> entry : mapToDisplay.entrySet()) {
      sb.append(entry.getKey()).append("=").append(entry.getValue()).append(" ");
    }
    sb.append("\n");
    return sb.toString();
  }
}
