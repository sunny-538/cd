#include <stdio.h>
#include <string.h>

struct symbol {
    char name[20];
    char type[10];
    int address;
} table[50];

int count = 0;

void insert() {
    printf("\nEnter name, type, and address: ");
    scanf("%s %s %d", table[count].name, table[count].type, &table[count].address);
    count++;
}

void display() {
    printf("\n%-15s %-10s %-10s\n", "Name", "Type", "Address");
    printf("-----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-10s %-10d\n", table[i].name, table[i].type, table[i].address);
    }
}


void search() {
    char name[20];
    int found = 0;
    printf("\nEnter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Found: %s\t%s\t%d\n", table[i].name, table[i].type, table[i].address);
            found = 1;
            break;
        }
    }
    if (!found) printf("Identifier not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert  2.Display  3.Search  4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
