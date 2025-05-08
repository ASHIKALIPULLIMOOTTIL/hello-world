#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the array

// Function to display the array
void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specified position
int insert(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return size;
    }
    if (position < 0 || position > size) {
        printf("Invalid position. Please enter a position between 0 and %d.\n", size);
        return size;
    }

    // Shift elements to the right
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element
    arr[position] = element;
    size++;

    printf("Element inserted successfully.\n");
    return size;
}

// Function to delete an element at a specified position
int delete(int arr[], int size, int position) {
    if (size == 0) {
        printf("Array is empty. Cannot delete elements.\n");
        return size;
    }
    if (position < 0 || position >= size) {
        printf("Invalid position. Please enter a position between 0 and %d.\n", size - 1);
        return size;
    }

    // Shift elements to the left
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    printf("Element deleted successfully.\n");
    return size;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Current size of the array
    int choice, element, position;

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (0 to %d): ", size);
                scanf("%d", &position);
                size = insert(arr, size, element, position);
                break;
            case 2:
                printf("Enter the position of the element to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                size = delete(arr, size, position);
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

