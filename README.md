# ft_printf

## Description

ft_printf is a project that aims to mimic the behavior of the original printf function from the C standard library. The project is part of the 42 curriculum and is designed to help students gain a deeper understanding of variadic functions, parsing, and string manipulation in C.

## Installation
To use the `libftprintf` library in your projects, follow these steps:

1. Clone the ft_printf repository: `git clone https://github.com/abouabra/42-ft_printf.git`
2. Navigate to the ft_printf directory: `cd 42-ft_printf`
3. Compile the library using the provided Makefile: `make`.
This will generate the `libftprintf.a` static library file.
4. Link `libftprintf.a` to your project at compile time. You can do this by including the library in your compilation command or by adding it to your project's Makefile.

## Usage
To use the functions provided by the ft_printf library, include the `ft_printf.h` header file in your source code:

## Example
```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    char *str = "Hello, World!";
    int len = ft_strlen(str);
    ft_printf("Length of string: %d\n", len);
    return (0);
}
```

1. Compile your source code with the `libftprintf.a` library:
```sh
gcc -o example example.c -L. -lft
```

2. Run the compiled program:
```sh
./example
```

3. The output should be:
```
Length of string: 13
```

## Documentation
The following conversion specifiers are handled:

### mandatory part
| Specifier | Description |
| --------- | ----------- |
| %c | Character |
| %s | String |
| %p | Pointer |
| %d | Decimal |
| %i | Integer |
| %u | Unsigned integer |
| %x | Hexadecimal |
| %X | Hexadecimal |
| %% | Percentage |

### bonus part
| Specifier | Description |
| --------- | ----------- |
| %- | left-justify |
| %0 | zero padding |
| %. | precision |
| %# | alternate form |
| %+ | always show sign |
| %space | space before positive numbers |

## Final Note
If you have any suggestions or improvements, feel free to open an issue or submit a pull request.