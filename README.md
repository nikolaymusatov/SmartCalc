# SmartCalc
## Information
In this project an extended version of the standard calculator in C++ was implemented. the calculator is able to calculate arithmetic expressions and some mathematical functions (sine, cosine, logarithm, etc.). Besides calculating expressions, it also supports the use of the variable _x_ and the graphing of the corresponding function.

Implementation includes:
- The program is developed in C++ language of C++17 standard;
- Full coverage of expression calculation modules with unit-tests using the GTest library was prepared;
- The program is built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, test.
- GUI implementation, based on Qt library:
- The program was implemented using the MVC pattern, which means:
   - there is no business logic code in the view code;
   - there is no interface code in the controller and the model;
   - controller is thin;
- Both integers and real numbers with a dot can be input into the program. The input of numbers in exponential notation is also supported;
- The calculation is done after you complete entering the calculating expression and press the `=` symbol;
- Calculating arbitrary bracketed arithmetic expressions in infix notation;
- Calculate arbitrary bracketed arithmetic expressions in infix notation with substitution of the value of the variable _x_ as a number;
- Plotting a graph of a function given by an expression in infix notation with the variable _x_ (with coordinate axes, mark of the used scale and an adaptive grid);
- Bracketed arithmetic expressions in infix notation support the following arithmetic operations and mathematical functions:
   - **Arithmetic operators**:
     | Operator name | Infix notation <br /> (Classic) |
      | --------- | ------ |
      | Brackets | (a + b) |
      | Addition | a + b |
      | Subtraction | a - b |
      | Multiplication | a * b |
      | Division | a / b |
      | Power | a ^ b |
      | Modulus | a mod b |
      | Unary plus | +a |
      | Unary minus | -a |
   - **Functions**:
      | Function description | Function |
      | ------ | ------ |
      | Computes cosine | cos(x) |
      | Computes sine | sin(x) |
      | Computes tangent | tan(x) |
      | Computes arc cosine | acos(x) |
      | Computes arc sine | asin(x) |
      | Computes arc tangent | atan(x) |
      | Computes square root | sqrt(x) |
      | Computes natural logarithm | ln(x) |
      | Computes common logarithm | log(x) |

## Makefile targets
 - **all**: runs targets install,  tests and gcov_report;
 - **install**: creates "Build" folder in project directory, builds the project as an App-bundle;
 - **uninstall**: deletes "Build" folder;
 - **clean**: deletes all files used during running targets tests, dvi, dist, gcov_report;
 - **dvi**: creates documentation files with provided "doxyfile", opens html-page with project documentation (doxygen is required);
 - **dist**: creates tar-archive with ready to use app inside;
 - **test**: run provided tests of calculation methods of Model-class. (GTest library is required. Also u need to tell path to GTest library in src/Test/gtest_dependency.pri inside GOOGLETEST_DIR variable);
 - **gcov_report**: creates html-page with information about tests coverage (gcovr is required, should be run only after "test" target).