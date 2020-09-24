# C Programming Bonus Round
  * File I/O
  * Algorithms, performance, memory efficiency

# Tasks

1. Text replacement utility.

  [PART 1]

  Write a C program that reads an input file named `values.ini` in the current directory.

  Syntax of the input file is as such:
  - blank line: skip, do nothing;
  - comment line: starts with the `#` character, but not necessarily on the first position in the line;
  - key-value pair: `key` = `"value"`

  The key:
  1) Can start at any position in the line (spaces and tabs before are ignored);
  2) Must be at least one character long;
  3) First character can only be an alphabetic character or `_`;
  4) Subsequent characters can be alphabetic, numeric, or `_`, up to a maximum of 31 characters;

  The value:
  1) Must be specified between double-quotes and can start at any position after the `=` sign;
  2) Must *not* be allowed to extend on the next line;
  3) Can contain any printable character, except `"`.

  The program shall parse the values file according to the above specifications and load each key-value pair into a suitable
  data structure in memory;
  Any violation of the syntax must be reported in the form of a fairly intuitive error message printed to the standard error
  output
  The dictionary containing all the key-value pairs can likewise be structured in whatever manner you see fit (array, list):
  you can decide based on the API requirements below (please be prepared to justify your choice if asked, though).
  Keys must be unique; Declarations that refer an existing key are resolved by replacing the existing value with the new one
  and likewise reporting the anomaly by printing a suitable message.
  Empty values are not allowed; Declarations that assign an emtpy value to a given key shall cause that key to be removed (or
  otherwise treated as non-existing).
  There should be no artificial limit on the number of key-value pairs that the dictionary can hold (there are of course
  technological limits - so values like INT_MAX or SHRT_MAX be perfectly acceptable)

  Furthermore, the program should define a basic API for querying and modifying the dictionary (please declare in a separate
  header file):

  bool  has_value(const char* key);
  char* get_value(const char* key);
  bool  add_value(const char* key, const char* value);
  bool  rem_value(const char* key);

  Add an extra feature that you may consider useful: optimising dictionary access, string table(s) or extending the API would
  count as such (again - please be prepared to describe and argument your choices).

  The program shall just print all the defined key-value pairs (in no particular order).
  As a suggestion - since your program won't do much without a `values.ini` file, add a basic one in your source directory and
  define a simple makefile rule that copies it to the build directory, where you can run and test your program.

  Please close all the file descriptors or streams and free all the allocated memory before exiting (you can use valgrind to
  verify).

  [PART 2]

  Add the following capabilities to the program written in PART 1:

  Command line arguments:
  -l: "list": list the defined key-value pairs, as per PART1;
  -h: "help": show a helpful message describing the usage and command line options of the program;
  -v: "verbose": set verbose mode (described below);
  -r <input_file>: mandatory argument specifying the file to read and process;
  -o <output_file>: optional argument specifying the file to write the output of the program into; If not present, use a
  default one of your choice (or derive a one based on the name of the input file)

  If no arguments are specified - print a help message as per -h and exit.

  Text replacement:
  Open the input file specified with the -r argument and apply replacemnts to it, as such:
  - If a word in the input file has the form "$<name>", it shall be replaced with the value in the dictionary corresponding
  to the key <name>;  If the verbose mode is active (-v option), print a helpful message to stderr describing the replacement
  you've just made: line and column numbers welcome!
  - If a word in the input file that has the form "$<name>" but a value for it has not been defined in the dictionary, leave the
  original text intact and print a helpful error message (to stderr), irrespective of the verbose status;
  - The replaced text shall be written into the output file only. No changes whatsoever shall be applied to the input file;
  - Text replacement routine shall be written as a testable, standalone function (useful for unit testing);

  Consider adding an extra feature that you may find useful (for instance - defining values from the command line arguments)
