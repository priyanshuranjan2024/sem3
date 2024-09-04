#include <stdio.h>
#include <stdlib.h>

// Define the Employee structure
struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
};

// Function to calculate the gross salary
float calculate_gross_salary(float basic_salary, float hra_percent, float da_percent) {
    float hra = (hra_percent / 100) * basic_salary;
    float da = (da_percent / 100) * basic_salary;
    return basic_salary + hra + da;
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Allocate memory for n employees
    struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (employees == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input the information of each employee
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d\n", i + 1);
        printf("Emp-id: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);
        printf("HRA %%: ");
        scanf("%f", &employees[i].hra_percent);
        printf("DA %%: ");
        scanf("%f", &employees[i].da_percent);
    }

    // Display the information of each employee along with their gross salary
    for (int i = 0; i < n; i++) {
        float gross_salary = calculate_gross_salary(employees[i].basic_salary, employees[i].hra_percent, employees[i].da_percent);
        printf("\nEmployee %d\n", i + 1);
        printf("Emp-id: %d\n", employees[i].emp_id);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basic_salary);
        printf("HRA %%: %.2f\n", employees[i].hra_percent);
        printf("DA %%: %.2f\n", employees[i].da_percent);
        printf("Gross Salary: %.2f\n", gross_salary);
    }

    // De-allocate the memory
    free(employees);

    return 0;
}
