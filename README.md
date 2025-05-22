# quiz - Command-Line Quiz Program  
A simple command-line quiz for testing knowledge of Linux, C, and GitHub.

---

## Description  
This program allows users to view and answer multiple-choice style questions directly from the command line. It covers basic concepts related to Linux, C, and GitHub. Users can use command-line flags to display specific questions and submit answers, receiving immediate feedback on their response.

---

## Getting Started

### Dependencies  
- Terminal environment (Linux, macOS, WSL)
- GCC or any C compiler  

### Installing  
1. Clone or download the repository:

    ```bash
    git clone https://github.com/benbloomie/2XC3-the-ci-pipeline-assignment
    cd 2XC3-the-ci-pipeline-assignment
    ```

2. Compile the program:

    ```bash
    gcc -o quiz quiz.c
    ```

---

## Executing the Program

Run the program using `quiz`. Use the following options:

- To view a question:

    ```bash
    ./quiz -1
    ```

- To answer a question:

    ```bash
    ./quiz -1 ls
    ```
