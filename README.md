### Text File Compression and Decompression Using Huffman Coding
This project implements a Huffman Coding algorithm for compressing and decompressing text files in C++.

## Features
Compresses text files to save space using Huffman coding.

Decompresses compressed files to restore the original text.

Demonstrates a practical implementation of lossless data compression.

## How It Works
Calculates the frequency of each character in the input text.

Builds a Huffman Tree based on character frequencies.

Encodes the text using Huffman codes.

Saves the compressed text to a file.

Decodes the text back to its original form using the Huffman tree.

## Requirements
C++ compiler (e.g., GCC or MSVC).

Standard Template Library (STL) support.

## How to Run

# Compile the program:

g++ -o huffman main.cpp
# Run the program:

./huffman


# Example
Input:

hello world
Compressed output saved to compressed.txt.
Decompressed text:

hello world