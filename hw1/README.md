# (Homework 1) Functional Programming
---

## Introduction
The objective of this homework is to find the *k* most frequent integers and *k* most frequent reals in a text file.

According to the homework document, this is the main mechanism to find documents on the web in a search engine.
There will be an input integer *k* >= 1 as a parameter.
The input file can contain words and numbers as well as other symbols, but words and other symbols can be ignored.

*Since this homework requires functional programming, **recursive** functions and **lambda** expressions should be used to solve the problem.*
Memory efficiency and time complexity do not have to be worried about (within reason)

## Program/Input Specification
The program will be called within a UNIX environment using the following syntax:
```shell
python3 freqnumber.py "k=3;input=input.txt;output=freqnumber.txt"
```

A number with only digits and sign is an integer.
A number having a decimal point will be considered real.
Scientific notation will not be used, therefore strings mixing letters and numbers will be ignored.
*Note: words can be followed by punctuation signs and can be capitalized*

### Input
The input will be a plain text file mixing numbers and words. The input file name will not be the same every time, therefore the program will have to parse for the name.
The input is only one text file with words and numbers separated by spaces, punctuation symbols, and any other common text symbols.
Repeated spaces should be considered as one space.
It is safe to assume that integers fit in 32-bits and real numbers as double (5 decimals max, 64-bits).
Numbers are also allowed to have a negative sign

### Output
The format of the output file should be the number followed by it's frequency, once per line.
There will be two lists: one for integers and one for reals.

Example with *k* = 3:
> integer:
>
> 1 1000
>
> -1 500
>
> 0 500
>
> real:
>
> -2.1 100
>
> 3.1416 5
>
> 1.5 3

### Requirements
- Programming Language: Python 3.xx
- **Functional programming** is the main requirement. All functions should be recursive, there should be *no mutation* and all computations will happen via lists.
- **Functional expressions**: The program should internally use lambda expressions to convert integers, instead of built-in functions. The program should use map()/reduce() functional constructs to compute frequencies when possible
- Lists (as available in the language) are required to store numbers: input, temporary, and output. Primitive operators provided by the language should be used. Array-based lists (provided by the language) are allowed.  
  Use of existing Python libraries with numeric arrays (e.g. numpy), dictionaries, or hash table data structures are not allowed. These libraries defeat a functional programming approach and do all the algorithmic work.  
  You are expected to develop recursive algorithms.
- Again, **no mutation**. Lists cannot be mutated, especially for sorting. Mutation in a growing list to read the input file is acceptable, but can be avoided. Mutation to insert or delete elements from lists should be avoided if possible.
- Follow a "strongly typed" language approach. Lists will be strongly typed; one list for integers and one for real nnumbers. Do not mix them.
- Recursive functions are required to process all lists. Loops (while/for) to process the list(s) are unacceptable.  
  While loops are only acceptable for I/O to read the input file into a list, but recursive I/O functions are encouraged. It's okay if they're slow.
- **Search and Sort Algorithms**: The lists should have recursive search and sort algorithms, without mutation. It is acceptable to have an *O(n^2^)* sort algorithm, but *O(nlog(n))* is encouraged; specify which one is being used.  
  Search can also 