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
test