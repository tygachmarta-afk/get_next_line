*This project has been created as part of the 42 curriculum by <mtyhach>.*

# Get Next Line

## 📝 Description
The goal of **get_next_line** is to write a function that returns a line read from a file descriptor. Each call to the function allows reading the next line of a text file, one line at a time, until the end of the file is reached. 

This project introduces the highly important concept of **static variables** in C programming. It teaches how to manage memory dynamically, manipulate buffers efficiently, and handle multiple file descriptors simultaneously without losing track of the reading position.

### Key Features
- **Line-by-Line Reading**: Returns the line including the terminating `\n` character (except if the file ends without one).
- **Dynamic Buffering**: Works seamlessly with any given `BUFFER_SIZE` (from `1` to macro values like `10000000`).
- **Bonus Implementation**: Supports multiple file descriptors concurrently. You can switch between reading `fd 3`, `fd 4`, and `fd 5` alternately without losing the reading state of any file.

---

## 🛠️ Instructions

### Prerequisites
You need a standard C compiler like `gcc` or `clang` and a Linux/macOS environment.

### Compilation
The `BUFFER_SIZE` must be defined during compilation using the `-D BUFFER_SIZE=n` flag.
### Compilation
The `BUFFER_SIZE` must be defined during compilation using the `-D BUFFER_SIZE=n` flag.

#### Mandatory Part Compilation:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4 main.c get_next_line.c get_next_line_utils.c -o gnl_test
```

#### Bonus Part Compilation:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

### Execution
Run the compiled binary directly from your terminal:
```bash
./gnl_test
./gnl_bonus
```

### Memory Leak Testing (Valgrind)
To check for memory leaks and ensure perfect heap management during evaluation, execute:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./gnl_test
valgrind --leak-check=full --show-leak-kinds=all ./gnl_bonus
```

---

## 🚀 Testing Suite & Evaluation Tools
*Note: The following test files and `main` components are provided here for evaluation purposes and quick peer-review testing. They are excluded from the final push repository according to 42 rules.*

### 📄 How to Setup Test Files
Create a file named `testo.txt` in the same directory using `vim` or `cat`:
```bash
vim testo.txt
```
Insert some random text lines inside it, for example:
```text
Questa è la prima linea,
questa è la seconda yabadaba dooo!
questa è la terza.
Ultimaaaaaaaa.
```
Verify the file content with:
```bash
cat testo.txt
```

### 💻 Testing Code: Mandatory Part (`main.c`)
```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 1;
	fd = open("testo.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Errore: Impossibile aprire il file 'testo.txt'\n");
		return (1);
	}
	printf("--- INIZIO TEST GET_NEXT_LINE ---\n\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[Riga %d]: %s", line_count, line);
		free(line);
		line_count++;
	}
	printf("\n--- FINE FILE RAGGIUNTA ---\n");
	close(fd);
	return (0);
}
```

### 💻 Testing Code: Bonus Part (`main_bonus.c`)
```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("file1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 == -1)
		return (printf("Errore creazione file1.txt\n"), 1);
	write(fd1, "FILE 1 - Riga A\nFILE 1 - Riga B\nFILE 1 - Riga C\n", 48);
	close(fd1);

	fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 == -1)
		return (printf("Errore creazione file2.txt\n"), 1);
	write(fd2, "file 2 - riga uno\nfile 2 - riga due\n", 36);
	close(fd2);

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		return (printf("Errore apertura file per la lettura\n"), 1);

	printf("--- INIZIO TEST BONUS (LETTURA ALTERNATA) ---\n\n");

	line = get_next_line(fd1);
	printf("[FD %d]: %s", fd1, line);
	free(line);

	line = get_next_line(fd2);
	printf("[FD %d]: %s", fd2, line);
	free(line);

	line = get_next_line(fd1);
	printf("[FD %d]: %s", fd1, line);
	free(line);

	line = get_next_line(fd2);
	printf("[FD %d]: %s", fd2, line);
	free(line);

	line = get_next_line(fd1);
	printf("[FD %d]: %s", fd1, line);
	free(line);

	// Cleaning remaining static allocations for Valgrind 100% clean check
	while ((line = get_next_line(fd1)) != NULL)
		free(line);
	while ((line = get_next_line(fd2)) != NULL)
		free(line);

	printf("\n--- FINE TEST BONUS ---\n");
	close(fd1);
	close(fd2);
	return (0);
}
```

---

## 📚 Resources

### Classic References
- **Unix System Calls**: Manual pages for `read()`, `open()`, and `close()`.
- **C Memory Management**: Documentation on `malloc()`, `free()`, and the behavior of heap segmentation.
- **Static Variables**: Standard C documentation regarding life cycle and scope of variables declared with the `static` keyword.

### Use of AI
AI was used as a supportive tool during the development of this project for the following specific tasks:
- **Debugging & Error Diagnosis**: Assisting in analyzing and tracking down critical memory bugs like `malloc(): corrupted top size` and `free(): invalid pointer`.
- **Creation of main testers & README.md file**.