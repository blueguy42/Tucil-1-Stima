# Word Search Puzzle Solver
Tugas Kecil 1 IF2211 Strategi Algoritma Semester II Tahun 2021/2022

Solving Word Search Puzzle Using Brute Force Algorithm

## Table of Contents
* [General Information](#general-information)
* [Setup and Requirements](#setup-and-requirements)
* [Usage](#usage)
* [Contact](#contact)

## General Information
This simple program written in C solves a word search puzzle by brute force algorithm. It first reads through a given text file input containing the puzzle matrix and keywords to find. Then, it traverses through all the puzzle letters one-by-one. If the first letter is correct, it then checks for all the 8 wind directions (East, South-East, South, etc.) for all the remaining letters.

A simple heuristic optimization is made to better the search and to address the issue of out of bounds checking, by evaluating indices only up until length `n - m + 1` where n is the length of row/column and m is the length of a word.

## Setup and Requirements
A system with a Windows OS is recommended. Running in a Linux-based system requires the input `.txt` files to be made from scratch in a Linux text editor because of the difference between a Windows and Linux newline.

No additional requirements are needed to run the executable program file, but the <b>GCC compiler</b> is needed to re-compile the `main.c` file. To re-compile the program, simply run `compile.bat`.

<b>IMPORTANT: Do not change the folder structure as the program is dependent on the folder structure!</b>

A `.txt` file is used as the input for the puzzle and keywords. You can generate your own word search puzzle using this <a href="https://randomwordgenerator.com/">random word generator</a> and <a href="https://tools.atozteacherstuff.com/word-search-maker/wordsearch.php">word search generator</a>.

The file should follow the pattern:
```
<PUZZLE>

<KEYWORDS>
```
with spaces separating each character of the puzzle. Between the puzzle and keywords there should be an empty line. An example is as follows:
```
J S O L U T I S
S U N A R U U A
N E P T U N E T
S O N I E I S U
R C E V T R E R
A H T R A E S N
M M E R C U R Y

EARTH
JUPITER
MARS
MERCURY
NEPTUNE
SATURN
URANUS
VENUS
```

Make sure to put your puzzle text file into the `test/` folder!

## Usage
Simply run the `run.bat`. Input the filename of the puzzle text file (including the .txt extension).

Alternatively, you can run the program in the terminal by first going to the directory of the `bin/` folder and then running:
```
./main
```

## Contact
This program was made by Ahmad Alfani Handoyo (13520023).

You can find and contact me via <a href="http://www.linkedin.com/in/ahmad-alfani-handoyo/">LinkedIn</a>, <a href="http://github.com/blueguy42">GitHub</a>, <a href="http://www.instagram.com/afanhandoyo/">Instagram</a>, or <a href="mailto:ahmadalfanihandoyo1@gmail.com">Email</a>.
