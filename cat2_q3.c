/*
Name: Katuku Muthami 
Reg. No: CT100/G/26212/25
Description: Program to process integers from a file, compute sum and average, and print formatted results.
*/

#include <stdio.h>

const int num_ints = 10;

void inputIntegers() {
    FILE *fout = fopen("input.txt", "w");
    if (fout == NULL) {
        printf("Error opening input.txt for writing.\n");
        return;
    }
    int num;
    printf("Enter 10 integers:\n");
    for (int i = 0; i < num_ints; i++) {
        printf("Integer %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fout, "%d\n", num);
    }
    fclose(fout);
}

void computeAndWriteSumAvg() {
    FILE *fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input.txt for reading.\n");
        return;
    }
    FILE *fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error opening output.txt for writing.\n");
        fclose(fin);
        return;
    }

    int sum = 0, value, count = 0;
    while (fscanf(fin, "%d", &value) == 1 && count < num_ints) {
        sum += value;
        count++;
    }
    double avg = (count > 0) ? (double)sum / count : 0.0;
    fprintf(fout, "Sum: %d\nAverage: %.2f\n", sum, avg);

    fclose(fin);
    fclose(fout);
}

void displayFiles() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "r");
    int value;
    printf("\nContents of input.txt:\n");
    if (fin == NULL) {
        printf("Could not open input.txt\n");
    } else {
        for (int i = 0; i < num_ints; i++) {
            if (fscanf(fin, "%d", &value) == 1)
                printf("Integer %d: %d\n", i + 1, value);
        }
        fclose(fin);
    }
    printf("\nContents of output.txt:\n");
    if (fout == NULL) {
        printf("Could not open output.txt\n");
    } else {
        char line[100];
        while (fgets(line, sizeof(line), fout))
            printf("%s", line);
        fclose(fout);
    }
}

int main() {
    inputIntegers();
    computeAndWriteSumAvg();
    displayFiles();
    return 0;
}