#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent a student record
struct Student {
    char name[50];
    int age;
    int rollno;
};

int main(int argc, char *argv[]) {
    // Create a file pointer
    FILE *file;

    // Open the file in write mode
    file = fopen("student_records.txt", "w");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Array to store 10 student records
    struct Student students[10];

    // Input data for 10 students
    for (int i = 0; i < 3; ++i) {
        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Roll Number: ");
        scanf("%d", &students[i].rollno);

        // Write the student data to the file with "|" as separator
        fprintf(file, "%-20s | %-4d | %-4d\n", students[i].name, students[i].age, students[i].rollno);
    }

    // Close the file
    fclose(file);

    printf("Student records written to student_records.txt successfully.\n");

    FILE *inf;
    struct Student inp[10];
    inf = fopen("student_records.txt", "r");

    if (inf == NULL) {
        fprintf(stderr, "\nError opening the file\n");
        exit(1);
    }

    if (argc == 2) {
        if (strstr(argv[1], "SELECT*") ==0) {
	   printf("in * here");
            printf("%-20s | %-4s | %-4s\n", "Name", "Age", "Roll No");
            char line[100]; // Adjust the size as needed
            while (fgets(line, sizeof(line), inf) != NULL) {
                sscanf(line, "%[^|] | %d | %d", inp[0].name, &inp[0].age, &inp[0].rollno);
                printf("%-20s | %-4d | %-4d\n", inp[0].name, inp[0].age, inp[0].rollno);
            }
        }else if (strstr(argv[1], "SELECT*WHEREAGE>=60") == 0) {
   printf("in 60 here");
    printf("%-20s | %-4s | %-4s\n", "Name", "Age", "Roll No");
    char line[100]; // Adjust the size as needed
    while (fgets(line, sizeof(line), inf) != NULL) {
        sscanf(line, "%[^|] | %d | %d", inp[0].name, &inp[0].age, &inp[0].rollno);
	printf("age",inp[0].age);
        if (inp[0].age >= 60)  // Use >= here
            printf("HERE %-20s | %-4d | %-4d\n", inp[0].name, inp[0].age, inp[0].rollno);
    }
}else if (strstr(argv[1], "SELECTAGE,ROLLNO") == 0) {
            printf("%-4s | %-4s\n", "Age", "Roll No");
            char line[100]; // Adjust the size as needed
            while (fgets(line, sizeof(line), inf) != NULL) {
                sscanf(line, "%[^|] | %d | %d", inp[0].name, &inp[0].age, &inp[0].rollno);
                printf("%-4d | %-4d\n", inp[0].age, inp[0].rollno);
            }
        } else {
            printf("Invalid option entered\n");
        }
    } else {
        printf("Invalid number of arguments\n");
    }

    fclose(inf);

    return 0;
}