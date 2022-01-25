# Word Search Puzzle Solver
Tugas Kecil 1 IF2211 Strategi Algoritma Semester II Tahun 2021/2022

Solving Word Search Puzzle Using Brute-Force Algorithm

## Table of Contents
* [General Information](#general-information)
* [Setup and Requirements](#setup-and-requirements)
* [Usage](#usage)
* [Contact](#contact)

## General Information
This simple program written in C solves a word search puzzle by brute-force algorthm. It first reads through a given text file input containing the puzzle matrix and keywords to find. Then, it traverses through all the puzzle letters one-by-one. If the first letter is correct, it then checks for all the 8 wind directions (East, South-East, South, etc.) for all the remaining letters.

A simple heuristic optimization is made to better the search and to address the issue of out of bounds checking which is to check indices up until length `n - m + 1` where n is the length of row/column and m is the length of a word.

## Setup and Requirements

## Usage
You can generate your own word search puzzle using this <a href="https://randomwordgenerator.com/">random word generator</a> and <a href="https://tools.atozteacherstuff.com/word-search-maker/wordsearch.php">word search generator</a>.

## Contact
This program was made by Ahmad Alfani Handoyo (13520023).

You can find and contact me via <a href="http://www.linkedin.com/in/ahmad-alfani-handoyo/">LinkedIn</a>, <a href="http://github.com/blueguy42">GitHub</a>, <a href="http://www.instagram.com/afanhandoyo/">Instagram</a>, or <a href="mailto:ahmadalfanihandoyo1@gmail.com">Email</a>.