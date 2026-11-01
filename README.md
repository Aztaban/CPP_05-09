# 42 C++ Modules (CPP05–CPP09)

A 42 school repository covering the second **five C++ modules**, written in **C++98**.
The focus moves from object-oriented foundations to exceptions, casts, templates, STL containers, iterators, and algorithms — ending with a merge-insertion sorting project.

## 🚀 Overview

| Module | Focus | Exercises |
| --- | --- | --- |
| **CPP05** | Exceptions and abstract classes | Bureaucrats, forms, specialized forms, and an intern that creates forms |
| **CPP06** | C++ casts and type identification | Scalar conversion, pointer serialization, and runtime type identification |
| **CPP07** | Templates | Generic `swap` / `min` / `max`, array iteration, and a templated array |
| **CPP08** | Containers, iterators, and algorithms | `easyfind`, `Span`, and an iterable `MutantStack` |
| **CPP09** | Practical STL applications | Bitcoin Exchange, Reverse Polish Notation, and `PmergeMe` |

Each exercise has its own `Makefile` and builds independently with strict compiler warnings.

## ✅ Key topics practiced

- Exception handling, custom exception types, and input validation
- Abstract classes, inheritance, and polymorphic behavior
- Orthodox Canonical Form and resource ownership
- `static_cast`, `reinterpret_cast`, and `dynamic_cast`
- Function templates, class templates, and generic programming
- Deep copying and bounds-checked array access
- STL containers, iterators, and standard algorithms
- File parsing, date-based lookups, and stack-based expression evaluation
- Recursive sorting, binary insertion, and comparison counting

## 📁 Repository structure

```text
├── module_05/
│   ├── ex00/                 # Bureaucrat
│   ├── ex01/                 # Form
│   ├── ex02/                 # Abstract and specialized forms
│   └── ex03/                 # Intern
├── module_06/
│   ├── ex00/                 # ScalarConverter
│   ├── ex01/                 # Serializer
│   └── ex02/                 # Runtime type identification
├── module_07/
│   ├── ex00/                 # Function templates
│   ├── ex01/                 # iter
│   └── ex02/                 # Array
├── module_08/
│   ├── ex00/                 # easyfind
│   ├── ex01/                 # Span
│   └── ex02/                 # MutantStack
└── module_09/
    ├── ex00/                 # Bitcoin Exchange
    ├── ex01/                 # Reverse Polish Notation
    └── ex02/                 # PmergeMe
```

## 🛠️ Compilation

A C++ compiler with C++98 support and `make` are required. From the repository root:

```bash
cd module_05/ex00
make
./bureaucrat
```

Common Makefile targets:

```bash
make          # Build the executable
make clean    # Remove object and dependency files
make fclean   # Also remove the executable
make re       # Rebuild from scratch
```

All exercises compile with:

```text
-Wall -Wextra -Werror -std=c++98
```

## ▶️ Usage

Run each example from its exercise directory after building with `make`.

| Directory | Command | Purpose |
| --- | --- | --- |
| `module_06/ex00` | `./convert 42.0f` | Convert a scalar literal to other scalar types |
| `module_06/ex01` | `./serializer` | Demonstrate pointer serialization and deserialization |
| `module_07/ex02` | `./array` | Run templated array examples |
| `module_08/ex01` | `./span` | Run shortest/longest span examples and edge cases |
| `module_09/ex00` | `./btc input.txt` | Evaluate values using historical exchange rates |
| `module_09/ex01` | `./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"` | Evaluate a Reverse Polish Notation expression |
| `module_09/ex02` | `./PmergeMe 3 5 9 7 4` | Sort a sequence using two containers |

Bitcoin Exchange loads `data.csv` from the current working directory; the exercise includes both this database and a sample `input.txt`.

## 🔍 CPP09 / ex02 — PmergeMe

The final exercise implements **Ford–Johnson merge-insertion sort** using both **`std::vector`** and **`std::deque`**. It combines recursive ordering with binary insertion, using information from earlier comparisons to limit later searches.

### How the implementation works

1. **Form pairs.** Compare adjacent values and store each pair as a smaller and a larger element. Keep an unpaired final value aside when the input size is odd.
2. **Sort the larger elements recursively.** Reorder the pairs by their larger elements while preserving each pair's association.
3. **Build the main chain.** Start with the sorted larger elements, then place the smaller element of the first pair at the beginning.
4. **Insert pending elements.** Use a Jacobsthal-based order to choose which smaller element to insert next. Binary search is bounded by that element's larger partner, since the smaller element must come before it.
5. **Insert the unpaired value.** In this implementation, an odd leftover element is inserted last using binary search over the entire chain.

The Jacobsthal sequence follows `J(n) = J(n - 1) + 2 × J(n - 2)`, starting with `0, 1`. Its boundaries determine groups of pending elements, which are inserted in reverse order within each group to control binary-search range sizes.

### Input and output

Pass **distinct positive integers**, one per command-line argument, within the `int` range:

```bash
cd module_09/ex02
make
./PmergeMe 3 5 9 7 4
```

Both containers produce the sorted sequence `3 4 5 7 9`. The current executable uses a diagnostic output mode that prints:

- The sequence before and after sorting for each container
- Processing time in microseconds for each container
- Counted sorting comparisons alongside a Ford–Johnson theoretical comparison reference

Zero, negative values, duplicates, non-integer input, and values above `INT_MAX` are rejected.

For a larger random sequence, the Makefile provides a convenience target using `shuf`:

```bash
make run          # 3,000 distinct integers
make run N=10000  # 10,000 distinct integers
```

### Reading the results

The two containers offer different storage layouts: `std::vector` stores elements contiguously, while `std::deque` uses segmented storage. The exercise makes it possible to compare their behavior under the same sorting strategy.

Comparison counts and elapsed time describe different aspects of the implementation. Timings also include allocations, element movement, and bookkeeping; the comparison counter tracks pairing and binary-search comparisons, rather than every comparison used by helper routines. Parsing happens before the timed sorting sections.

The displayed theoretical count is a reference, not an enforced limit or proof of optimality. In particular, this version inserts an odd leftover value last rather than including it in the Jacobsthal insertion schedule, so its comparison count can differ from that reference. Very small inputs may also report zero microseconds because timing uses `clock()`.

## 🧪 Testing

Exercises include small demonstration and verification cases in their `main.cpp` files. Examples cover invalid grades and form operations, array bounds and copies, missing values, and empty or full spans. `Span` also includes a test with 100,001 values.

The RPN exercise includes a test-case file and shell runner:

```bash
cd module_09/ex01
make
bash run_tests.sh
```

Useful manual checks for `PmergeMe` include a single value, already sorted and reverse-sorted sequences, odd and even input sizes, and rejected inputs:

```bash
./PmergeMe 42
./PmergeMe 1 2 3 4 5
./PmergeMe 6 5 4 3 2 1
./PmergeMe 3 3
./PmergeMe 0 1
./PmergeMe 1 abc
```

## 🧼 Memory checks (Valgrind)

For exercises that allocate memory, run the executable under Valgrind. For example, from `module_07/ex02` after building:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./array
```

Check for leaks, invalid reads or writes, and double frees, especially when testing copy constructors and assignment operators.

## 🛠️ Notes / Limitations

- Written for C++98: no `nullptr`, range-based loops, or modern smart pointers.
- Exercises are independent programs; there is no repository-wide build target.
- Several programs use ANSI colors and additional diagnostic output.
- Sorting times depend on the machine, input order, compiler settings, and timer resolution.

## 👤 Author

Created and maintained by [Martin Justa](https://github.com/aztaban) as part of the 42 school curriculum.
