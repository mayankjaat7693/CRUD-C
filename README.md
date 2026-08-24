# C CRUD File Handling Project

## Overview

This project is a C-based CRUD application that demonstrates how to store, read, update, and delete data using files.

The main purpose of this project is to understand **file handling, data structures, strings, characters, and CRUD operations in C**.

The project is divided into different source files so that the application logic and library functions remain organized and easy to maintain.

## CRUD Operations

CRUD stands for:

* **Create** – Add new data to the file.
* **Read** – Display or search existing data.
* **Update** – Modify existing data.
* **Delete** – Remove existing data.

## Project Files

### `application_string.c`

This file handles operations related to string-based data.

It contains application-level logic for accepting, processing, searching, and managing string information.

### `applicationchar.c`

This file handles character-based operations used by the application.

It is mainly used for working with individual characters and character-related input.

### `applicationstructure.c`

This file contains the main application logic based on C structures.

Structures are used to group related data together and make it easier to store and manage records.

### `library.c`

This file contains reusable functions used by the application.

Keeping common functions in a separate library file makes the code more organized and reduces duplicate code.

## Concepts Used

This project uses the following C concepts:

* File Handling
* Structures
* Strings
* Characters
* Functions
* Pointers
* Arrays
* Dynamic Memory Allocation
* Searching
* Updating Records
* Deleting Records
* Reading and Writing Files
* Modular Programming
* CRUD Operations

## File Handling

The application uses C file-handling functions to store and manage data.

Common operations include:

* Opening a file
* Reading data from a file
* Writing data to a file
* Updating records
* Deleting records
* Closing a file

The project demonstrates how data can be stored permanently instead of keeping everything only in memory.

## Basic Working Flow

The general flow of the application is:

```text
Start
  |
  v
Select Operation
  |
  +---- Create ----> Add Record
  |
  +---- Read ------> Display/Search Record
  |
  +---- Update ----> Modify Record
  |
  +---- Delete ----> Remove Record
  |
  v
Save Changes
  |
  v
Exit
```

## How to Compile

Using GCC:

```bash
gcc application_string.c applicationchar.c applicationstructure.c library.c -o application
```

Run the program:

```bash
./application
```

## Purpose of the Project

This project was created to get practical experience with **C programming and file handling**.

Instead of writing everything in a single source file, the project separates different parts of the application into multiple files. This makes the code easier to understand, test, modify, and reuse.

## Future Improvements

The project can be extended by adding:

* Better input validation
* More search options
* Sorting records
* Multiple file support
* Error handling
* Menu improvements
* Binary file storage
* Linked-list based record management
* Separate header (`.h`) files
* Separate modules for CRUD operations
* A database such as SQLite

## Author

This project is created as a practical C programming project to understand **CRUD operations and file handling**.

