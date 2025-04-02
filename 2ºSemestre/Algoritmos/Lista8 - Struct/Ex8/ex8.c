#include <stdio.h>
#include <string.h>

struct employee {
    char name[50];
    float salary;
    int type; // 0 - Developer, 1 - Designer, 2 - Manager, 3 - Support
};

typedef struct employee Employee;

void print_best3(int n, Employee v[n]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i].salary < v[j].salary) {
                Employee temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    printf("Os tres empregados com os maiores salarios sao:\n");
    for (int i = 0; i < 3 && i < n; i++) {
        printf("%s\n", v[i].name);
    }
}

int main() {
    Employee employees[] = {
        {"Alice", 5000.0, 0},
        {"Bob", 7000.0, 1},
        {"Charlie", 6000.0, 2},
        {"David", 8000.0, 3},
        {"Eve", 7500.0, 0}
    };
    int n = sizeof(employees) / sizeof(employees[0]); //5

    print_best3(n, employees);

    return 0;
}