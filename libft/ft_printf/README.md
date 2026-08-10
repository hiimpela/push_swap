*This project has been created as part of the 42 curriculum by nfil.*

## Description
The `ft_printf` project is a custom implementation of the standard C library `printf` function. The primary goal of this project is to learn how to manage variadic functions in C and to build a well-structured, extensible codebase. This static library mimics the behavior of the original `printf` without replicating its native buffer management. It parses format strings and handles the following conversion specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.


## Instructions
The project is built using a `Makefile`. To compile and use the library, follow these steps:

1. **Compilation:** Run `make` at the root of the repository. This will compile all `.c` source files using `cc` with the `-Wall`, `-Wextra`, and `-Werror` flags, creating the static library `libftprintf.a`.
2. **Integration:** To use the custom `ft_printf` in your own C projects, include the header file in your code (`#include "ft_printf.h"`).
3. **Execution:** Compile your program alongside the static library.

**Available Makefile Rules:**

* `make` / `make all`: Compiles the static library.
* `make clean`: Removes all generated object (`.o`) files.
* `make fclean`: Removes object files and the `libftprintf.a` binary.
* `make re`: Performs a complete recompilation (executes `fclean` followed by `all`).


## Algorithm and Data Structure

Only the mandatory part of the project was written - the bonus part was not attempted.

**Data Structure:**
To handle an unknown number of format arguments, the project relies exclusively on the `va_list` data type and the associated macros (`va_start`, `va_arg`, `va_end`) provided by the `<stdarg.h>` library. Complex data structures were avoided to maintain strict compliance with the requirement prohibiting standard buffer management.

**Algorithm:**
The core algorithm functions as a linear string parser and router.

1. A wrapper function iterates through the format string character by character.
2. Standard characters are written directly to standard output.
3. When a `%` symbol is encountered, the algorithm inspects the immediate next character to identify the required conversion specifier.
4. The router then delegates the task to a specific helper function (e.g., `ft_putstr`, `ft_putnbr_lowerhex`), passing the extracted `va_arg` of the appropriate type.
5. Because `ft_printf` must return the total number of printed characters, every helper function computes its own output length. For numeric conversions, the functions utilize recursion to isolate and print individual digits, returning a cumulative sum back up the call stack to the main wrapper function.


## Resources

* [C Variadic Functions (stdarg.h) Documentation](https://en.cppreference.com/w/c/variadic)
* [Linux Programmer's Manual: `printf` (man 3 printf)](https://linux.die.net/man/3/printf)

**AI Usage:**

Gemini was used in writing this readme.
