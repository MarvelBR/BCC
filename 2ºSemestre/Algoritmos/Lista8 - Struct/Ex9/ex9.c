#include <stdio.h>

struct employee {
    char name[50];
    float salary;
    int type; // 0 - Developer, 1 - Designer, 2 - Manager, 3 - Support
};

typedef struct employee Employee;

void income_report(int n, Employee v[n]) {
    float total_salary = 0.0;
    float type_salary[4] = {0.0, 0.0, 0.0, 0.0};  // Developer, Designer, Manager, Support
    int type_count[4] = {0, 0, 0, 0};

    int i;
    for (i = 0; i < n; i++) {
        total_salary += v[i].salary;
        type_salary[v[i].type] += v[i].salary;
        type_count[v[i].type]++;
    }

    printf("Total dos salarios: %.2f\n", total_salary);
    printf("Media geral dos salarios: %.2f\n", total_salary / n);

    char *types[4] = {"Developer", "Designer", "Manager", "Support"};
    for (i = 0; i < 4; i++) {
        if (type_count[i] > 0) {
            printf("Media de %s: %.2f\n", types[i], type_salary[i] / type_count[i]);
        } else {
            printf("Media de %s: N/A\n", types[i]); 
        }
    }
}

int main() {
    Employee employees[] = {
        {"Alice", 5000.0, 0},
        {"Bob", 4500.0, 1},
        {"Charlie", 7000.0, 2},
        {"David", 4800.0, 0},
        {"Eve", 3000.0, 3},
        {"Frank", 3200.0, 3},
        {"Grace", 4000.0, 1},
        {"Hank", 7500.0, 2}
    };

    int num_employees = sizeof(employees) / sizeof(employees[0]);
    income_report(num_employees, employees);

    return 0;
}