# C Academy Training

This repository contains the documentation and the tasks that will be implemented during the 1st month of the C academy.

## Documentation

This [document](https://gitlab.computaris.net:8181/c-academy-2020/training/-/blob/master/Documentation.md) contains links to tutorials and articles about C programming and the other tools used during academy training.

## Programming tasks

C programming training is divided into 3 parts. Each part covers some aspects of the C programming language and has a list of tasks (small programs) that must be implemented:

- C programming part 1 [tasks](https://gitlab.computaris.net:8181/c-academy-2020/training/-/blob/master/C-programming-part-1.md);
- C programming part 2 [tasks](https://gitlab.computaris.net:8181/c-academy-2020/training/-/blob/master/C-programming-part-2.md);
- C programming part 3 [tasks](https://gitlab.computaris.net:8181/c-academy-2020/training/-/blob/master/C-programming-part-3.md);

## How to do the tasks

All programming task should be developed using the [example project](https://gitlab.computaris.net:8181/c-academy-2020/training/-/tree/master/example) as a model.
The code will be stored in Computaris GitLab under the project [c-academy-2020](https://gitlab.computaris.net:8181/c-academy-2020). Each user will have a personal repository `c-academy-2020/users/<your name>`.

For each task create a separate directory named `part<p>task<t>` (where `p` and `t` represents the part and the task number: `part1-task01`, `part1-task02`, ...) in your own repository.

Organize your code in a similar structure as the provided example:

- `include` and `lib` directories contains common headers and libraries (just copy them from sample project);
- `src` directory contains the code of your program:

  - the function `main` defined in `src/main.c` should contain the code that reads user input and prints output;
  - the functions that implement the logic of your program (like computing area of a rectangle) should be defined in a separate module (like `src/rectangle.c` / `src/rectangle.h`). This separation is important because it allows us to write unit tests to check that the functions work as expected.

- `tests` directory contains the unit tests (UTs). Update the `tests/test_main.c` file with tests specific to the logic of your program. For some tasks we'll provide a list of UTs for others you may have to determine a list of suitable test cases. UTs are implemented using the [cmocka](https://cmocka.org/) framework where each test function has same prototype `void test_function_name_condition(void **state)`. Test functions name usually indicates which function is tested and what condition it tests (see the example project and `task02` details for some naming suggestions).
- `Makefile` is the build file. Read the comments in this file to understand what changes should be done to build your projects. The sample `Makefile` uses `build` as output directory support the following targets:

  - `make` - compiles the main program;
  - `make test` - compiles and run the UTs;
  - `make all` - compiles the main program and UTs and run the UTs;
  - `make clean` - removes the output (`buils`) directory;

## Git useful commands

You can find a list of useful Git commands [here](https://gitlab.computaris.net:8181/c-academy-2020/training/-/blob/master/Git-useful-commands.md);
