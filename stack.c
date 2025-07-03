#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value);
int pop();
int peek();
void display();
void change(int position, int value);

int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Change\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter position from top (1 = top): ");
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &value);
                change(position, value);
                break;
            case 6:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Function definitions

void push(int value) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = value;
        printf("Pushed %d\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void change(int position, int value) {
    int index = top - position + 1;
    if (index < 0 || index > top) {
        printf("Invalid position!\n");
    } else {
        stack[index] = value;
        printf("Changed element at position %d to %d\n", position, value);
    }
}
