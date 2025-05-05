/*
 * Author: Omi Shrestha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TASKS 100
#define TASK_LENGTH 100

void displayTasks(char tasks[][TASK_LENGTH], int taskCount) {
    printf("Todo List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d: %s\n", i + 1, tasks[i]);
    }
}

void saveTasksToFile(char tasks[][TASK_LENGTH], int taskCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for saving tasks.\n");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%s\n", tasks[i]);
    }
    fclose(file);
    printf("Tasks saved successfully.\n");
}

void loadTasksFromFile(char tasks[][TASK_LENGTH], int *taskCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No saved tasks found. Starting fresh.\n");
        return;
    }
    *taskCount = 0;
    while (fgets(tasks[*taskCount], TASK_LENGTH, file)) {
        tasks[*taskCount][strcspn(tasks[*taskCount], "\n")] = 0; // remove newline
        (*taskCount)++;
    }
    fclose(file);
    printf("Tasks loaded successfully.\n");
}

void markTaskAsCompleted(bool completed[], int taskIndex) {
    completed[taskIndex] = true;
    printf("Task %d marked as completed.\n", taskIndex + 1);
}

void displayTasksWithCompletion(char tasks[][TASK_LENGTH], bool completed[], int taskCount) {
    printf("Todo List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d: %s %s\n", i + 1, tasks[i], completed[i] ? "[Done]" : "");
    }
}

int main(void) {
    char tasks[MAX_TASKS][TASK_LENGTH];
    bool completed[MAX_TASKS] = {false};
    int taskCount = 0;
    int choice;

    loadTasksFromFile(tasks, &taskCount, "tasks.txt");

    while (1) {
        printf("\n1. Add Task\n2. Display Tasks\n3. Delete Task\n4. Mark Task as Completed\n5. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                if (taskCount < MAX_TASKS) {
                    printf("Enter the task: ");
                    fgets(tasks[taskCount], TASK_LENGTH, stdin);
                    tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0; // remove newline
                    taskCount++;
                } else {
                    printf("Task list is full!\n");
                }
                break;
            case 2:
                displayTasksWithCompletion(tasks, completed, taskCount);
                break;
            case 3:
                if (taskCount > 0) {
                    int deleteIndex;
                    printf("Enter task number to delete: ");
                    scanf("%d", &deleteIndex);
                    if (deleteIndex > 0 && deleteIndex <= taskCount) {
                        for (int i = deleteIndex - 1; i < taskCount - 1; i++) {
                            strcpy(tasks[i], tasks[i + 1]);
                            completed[i] = completed[i + 1];
                        }
                        taskCount--;
                        printf("Task deleted.\n");
                    } else {
                        printf("Invalid task number.\n");
                    }
                } else {
                    printf("No tasks to delete!\n");
                }
                break;
            case 4:
                if (taskCount > 0) {
                    int completeIndex;
                    printf("Enter task number to mark as completed: ");
                    scanf("%d", &completeIndex);
                    if (completeIndex > 0 && completeIndex <= taskCount) {
                        markTaskAsCompleted(completed, completeIndex - 1);
                    } else {
                        printf("Invalid task number.\n");
                    }
                } else {
                    printf("No tasks to mark as completed!\n");
                }
                break;
            case 5:
                saveTasksToFile(tasks, taskCount, "tasks.txt");
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
