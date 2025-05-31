# To-Do List

A command-line Todo List application written in C that allows users to manage their tasks easily. This program provides a basic interface for adding, displaying,
and deleting tasks.

## Features

- **Add Task**: Users can add new tasks to the list.
- **Display Tasks**: Users can view all the tasks currently in the list, with each task numbered for easy reference.
- **Delete Task**: Users can delete a task by entering its corresponding number from the displayed list.

## Additional Features

- **Mark Task as Completed**: Users can mark tasks as completed, and completed tasks are displayed with a "[Done]" tag.
- **Save and Load Tasks**: Tasks are automatically saved to a file and loaded when the program starts, ensuring persistence across sessions.

## How to Compile and Run

To compile and run this program, ensure you have a C compiler installed (e.g., GCC). Follow these steps:

1. Clone this repository:
   ```bash
   git clone https://github.com/OmiShrestha/to-do-list.git
   cd to-do-list
   ```

## How to Run the Program

1. Compile the program using the following command:
   ```bash
   clang -g to-do-list.c -o to-do-list
   ```

2. Run the compiled program:
   ```bash
   ./to-do-list
   ```
