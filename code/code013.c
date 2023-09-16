#include <stdio.h>

// Define the structure for employee information
struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percentage;
    float da_percentage;
    float gross_salary;
};

int main() {
    int n;

    // Read the number of employees
    printf("Enter no. of employees: ");
    scanf("%d", &n);

    // Declare an array of structures to store employee information
    struct Employee employees[n];

    // Input employee information for each employee
    for (int i = 0; i < n; i++) {
        printf("Enter employee %d information:\n", i + 1);

        // Read employee details
        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Designation: ");
        scanf("%s", employees[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);

        printf("HRA %%: ");
        scanf("%f", &employees[i].hra_percentage);

        printf("DA %%: ");
        scanf("%f", &employees[i].da_percentage);

        // Calculate gross salary
        employees[i].gross_salary = employees[i].basic_salary + 
                                    (employees[i].hra_percentage / 100) * employees[i].basic_salary + 
                                    (employees[i].da_percentage / 100) * employees[i].basic_salary;
    }

    // Display employee information with gross salary
    printf("Employee Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basic_salary);
        printf("HRA %%: %.2f%%\n", employees[i].hra_percentage);
        printf("DA %%: %.2f%%\n", employees[i].da_percentage);
        printf("Gross Salary: %.2f\n", employees[i].gross_salary);
    }

    return 0;
}
