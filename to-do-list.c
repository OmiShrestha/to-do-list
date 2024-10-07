//Author: Omi Shrestha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 100

void displayTasks(char tasks[][TASK_LENGTH], int taskCount) {
    printf("Todo List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d: %s\n", i + 1, tasks[i]);
    }
}

int main(void) {
    char tasks[MAX_TASKS][TASK_LENGTH];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("\n1. Add Task\n2. Display Tasks\n3. Delete Task\n4. Exit\n");
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
                displayTasks(tasks, taskCount);
                break;
            case 3:
                if (taskCount > 0) {
                    int deleteIndex;
                    printf("Enter task number to delete: ");
                    scanf("%d", &deleteIndex);
                    if (deleteIndex > 0 && deleteIndex <= taskCount) {
                        for (int i = deleteIndex - 1; i < taskCount - 1; i++) {
                            strcpy(tasks[i], tasks[i + 1]);
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
