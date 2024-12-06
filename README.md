# Simple Example of building a Static Library

## Introduction

This is a simple example of how to build a static library in C. The example is based on the following project structure:

```
.
├── bin             # Build    
│   ├── include     # Header Files
│   └── lib         # Static Library
├── src             # Source of the Static Library
│   ├── mylib.c
│   └── mylib.h
├──test
│  └── main.c       # Test Program / links with the static library 
└── Makefile        # Build Script
```

## Building the Static Library

The static library is built using the following steps:
1- Compile the source files in the `src` directory to object files.
2- Archive the object files into a static library.
3- Move the static library to the `bin/lib` directory.
4- Move the header files to the `bin/include` directory.
5- Compile the test program in the `bin` directory and link it with the static library.

The build script is provided in the `Makefile`. To build the static library, run the following command:

```bash
make
```

This will create the static library in the `bin/lib` directory and the test program in the `bin` directory.

## Running the Test Program

To run the test program, use the following command:

```bash
./bin/test
```
or 
```bash
make run
```
## Cleaning Up

To clean up the build artifacts, run the following command:

```bash
make clean
```
it will also remove the test program and library.

to clean only the object files, run the following command:

```bash
make clean_obj
```
