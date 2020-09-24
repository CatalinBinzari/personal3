# Naming Conventions for Files, Functions, Variables, Constants

- The name of each file must be unique.
- File names, function names and variable names should be as descriptive
     and meaningful as possible.
- The file names, function names and variable names can contain
     any of the following: a-z(lowercase), 0-9, '_'
- Use '_' to separate different words.
- Directories follow the same naming conventions as files.
- Declare each variable on a new line.
- Use capital letters for constants.

**Examples**:

    File name             - file_name.c
    Function name         - function_name()
    Variables             - int product_code;
                            int length1;
                            int length2;
    Constants             - const int LENGTH = 10;
                            #define LENGTH 10

# Comments

## File comment

  *Source file*:

    /*
      Name:        file_name.c

      Purpose:     This is an example of source file comment.
                   If the comment is too long, start a new line similar with this.
    */

  *Header File*:

    /*
      Header:  file_name.h

      Purpose: Example of header file comment.
    */

## Function comment

*Before function*:

    /*
      Name:        example_function

      Purpose:     This is an example

      Params:      IN    first_param   - description
                   IN    second_param  - description
                   OUT   result        - description

      Returns:  Example (Nothing, true, false, a variable value)
    */

*After function*:

    int function_name()
    {
        ....
    }  /* function_name */

   Use space to separate the '}' and the comment.
   Don't add empty space after the comment.

## Inline comment

    /* This is an example. */

# Indentation

  Never use **tab**.
  Use only **space**.<br />
  Use 2 spaces for multiple indentation levels.<br />
  Depending on functionality, use an empty line to separate different blocks of code.<br /><br />

 **Example**:

    bool function_name()
    {
      int rc;

      if (condiotion1)
      {
        rc = 1;
      }
      else if (condition2)
      {
        rc = 2;
      }
      else
      {
        rc = 3;
      }

      return rc;

    }

# Placing Braces and Spaces

- Place the opening brace at the beginning of the next line and closing brace
    on a new line
- Use braces even if there a single statement
- Use space after if, for, while, do, switch, case
- When declaring pointer data or a function that returns a pointer type,
     the preferred use of * is adjacent to the data name or function name
     and not adjacent to the type name
- Use one space around (on each side of) most binary and ternary operators,
     such as any of these:<br />
        =  +  -  <  >  *  /  %  |  &  ^  <=  >=  ==  !=  ?  :

     but no space after unary operators:<br />
        &  *  +  -  ~  !  sizeof  typeof

     no space before the postfix increment & decrement unary operators:<br />
        ++  --

     and no space around the . and -> structure member operators.

- Do not leave trailing whitespace at the ends of lines.
- Use brackets when instructions contains multiple conditions

**Examples**:<br />

    1)
      if (var1 > var2)
      {
        rc = TRUE;
      }

    2)
      for (ii = 0; ii < len; ii++)

    3)
      while (ii <= len)

    4)
      switch (value)
      {
        case 1:
          do_something;
          break;
        case 2:
          do_something;
          break;
        default:
          do_something;
          break;
      }

    5)
      sum = a + b;

    6)
      Be careful with alignment
      if ((a > b) &&
          (b > c) &&
          (a > c))

    7)
      condition ? value_if_true : value_if_false

# Breaking long lines and strings

   The limit on the length of lines is 100 columns.<br />
   Statements longer than 100 columns will be broken into sensible chunks,
   for example you can break the line after an operator.

   Write each function parameter on a new line. Keep same rule when the function
   is used.

    Ex: int function(int param1,
                     int param2,
                     int param3)
        Be careful with alignment


