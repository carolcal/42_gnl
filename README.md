# Get Next Line

**Get Next Line** is a project at 42 School that implements a function to read and return the next line from a file descriptor. This allows line-by-line reading of text files, standard input, or other data streams. The project emphasizes memory management, dynamic buffer handling, and multi-line retrieval using a static variable.

## Function Overview

- **`get_next_line(int fd)`**:  
  - The core function of this project, `get_next_line` reads from the specified file descriptor `fd` and returns the next line, including the newline character (`\n`) if present.  
  - Uses a static variable to store any remaining characters from the previous read, enabling seamless line-by-line reading across multiple calls.  
  - Returns `NULL` if an error occurs, `fd` is invalid, `BUFFER_SIZE` is invalid, or the end of the file is reached.

### Bonus Functionality: Multiple File Descriptors

In the bonus version, `get_next_line` supports reading from multiple file descriptors concurrently, allowing separate reading states for each file.

To enable this:
- **Static `rest` Array**: The static `rest` variable was replaced with an array, `rest[FD_LEN]`, where `FD_LEN` specifies the maximum number of file descriptors that can be read simultaneously.
- Each `fd` has its own entry in the `rest` array, enabling `get_next_line` to track line reading progress for each file individually.

### Helper Functions

- **`read_line(int fd, char *buffer, char *rest)`**:  
  - Reads chunks of data from the file descriptor into `buffer` and appends them to `rest`, which stores leftover data from previous reads.  
  - Stops reading if a newline character (`\n`) is found or when there’s no more data to read.  
  - Returns `rest` with all the data read.

- **`get_rest(char *line)`**:  
  - Extracts any remaining data after the newline character in `line`, saving it in `rest` for the next call to `get_next_line`.  
  - Modifies `line` to only include the current line.  
  - Returns the remainder to be stored in `rest`.

- **`free_buffer(char **buffer)`**:  
  - Frees the allocated memory for `buffer` and sets it to `NULL`.  
  - Used to prevent memory leaks by freeing memory after each read.

### Utility Functions

- **`ft_strlen(const char *s)`**: Returns the length of a string.
- **`ft_calloc(size_t nmemb, size_t size)`**: Allocates memory and initializes it to zero.
- **`ft_substr(char const *s, unsigned int start, size_t len)`**: Creates a substring from a string.
- **`ft_strjoin(char const *s1, char const *s2)`**: Concatenates two strings into a new string.
- **`ft_strchr(const char *s, int c)`**: Finds the first occurrence of a character in a string.

## Compilation and Usage

### Define `BUFFER_SIZE`

To control the number of bytes read at a time, use the `-D` flag during compilation. `BUFFER_SIZE` is also defined in the header file with a default value, so the program will work even if it’s not defined during compilation.

In the header file:

```c
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
```

Or when compiling:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c -o get_next_line
```

### Define `FD_LEN`

In the bonus version, `FD_LEN` defines the maximum number of file descriptors supported. It is defined in the header file with a default value, but you can also control this number using the `-D` flag during compilation.

In the header file:

```c
#ifndef FD_LEN
# define FD_LEN 42
#endif
```

To compile the bonus version:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=5 -D FD_LEN=5 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o get_next_line_bonus
```

## Key Points

- **Efficient Memory Handling**: Uses `ft_calloc` and `free_buffer` for dynamic memory management.
- **Static Array for Multiple Descriptors**: The static `rest` array (`rest[FD_LEN]`) allows tracking leftover data for multiple file descriptors.
- **Customizable Buffer and FD Limit**: Adjust `BUFFER_SIZE` and `FD_LEN` to optimize performance based on expected file sizes and system memory.
