*This project has been created as part of the 42 curriculum by fedacax.*

# get_next_line

## Description

get_next_line is a 42 curriculum project whose goal is to write a function that reads a file descriptor and returns its content one line at a time, each time it is called.

The project is an introduction to static variables in C, file reading with `read`, and dynamic memory management. It also shows why buffering matters: the function reads blocks of `BUFFER_SIZE` bytes, but must return exactly one line per call, keeping whatever was read past that line for the next call.

The function prototype is:

```c
char *get_next_line(int fd);
```

It returns the line that was read, including the terminating separator when there is one, or `NULL` when there is nothing else to read or an error occurs. The returned string is allocated with `malloc` and must be freed by the caller.

### Bonus

The bonus version adds two things:

- **Multiple file descriptors.** The function can alternate between several open file descriptors without losing the reading state of any of them. The maximum number of descriptors handled is defined by `FD_MAX`.
- **Custom separator.** The character that ends a line is configurable through `SEPARATOR` (default: `'\n'`), so the same function can read data split by any other character.

## Instructions

### Compilation

The three macros can be defined at compile time:

| Macro | Default | Description |
|---|---|---|
| `BUFFER_SIZE` | `100` | Number of bytes read per `read` call |
| `SEPARATOR` | `'\n'` | Character that ends a line |
| `FD_MAX` | `1024` | Maximum number of file descriptors handled (bonus) |

Mandatory part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Bonus part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -D SEPARATOR="'\\n'" -D FD_MAX=1024 \
    get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

### Usage

Include the header in your code:

```c
#include "get_next_line.h"     // mandatory
#include "get_next_line_bonus.h" // bonus
```

Example:

```c
int     fd = open("file.txt", O_RDONLY);
char    *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

### Edge cases

- Returns `NULL` if `fd` is invalid, if `BUFFER_SIZE` is not positive, or if `read` fails.
- If the file does not end with the separator, the last line is returned without it.
- An empty file returns `NULL` on the first call.
- Works with any `BUFFER_SIZE`, from `1` to very large values.
- Works with standard input as well as regular files.
- Bonus: each file descriptor keeps its own reading state, so calls can be interleaved freely.

## How it works

Each call reads from the file descriptor in blocks of `BUFFER_SIZE` bytes and appends them to a leftover string until it contains a separator or the end of the file is reached. The line is then extracted and returned, and everything after the separator is kept as the new leftover for the next call.

The leftover is stored in a `static` variable, the only way to keep state between calls without global variables. In the bonus version this is an array indexed by file descriptor, with `FD_MAX` positions, so each descriptor has its own independent leftover. The leftover is freed as soon as it is empty, and also on error, to avoid leaks.

## Resources

### References

- `man` pages, the main source for understanding the behavior of `read`, `open` and `malloc`
- [cppreference – C](https://en.cppreference.com/w/c)
- [GeeksforGeeks](https://www.geeksforgeeks.org/c/c-programming-language/)
- [Stack Overflow](https://stackoverflow.com/), for specific questions and comparing approaches
- Discussions with other 42 students, mainly about edge cases and testing

### AI usage

AI was used as a study and debugging aid, not to write the functions. Specifically:

- clarifying concepts such as static variables and how `read` behaves with different buffer sizes;
- interpreting compiler errors, segfaults, memory leaks and AddressSanitizer reports;
- reviewing code that had already been written, looking for edge cases that had been missed.