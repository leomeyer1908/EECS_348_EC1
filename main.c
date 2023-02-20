#include <stdio.h>


void removeTaken(int dept_preferences[5][5], int dept, int progs_taken[5]) {
    do {
        for (int i = 0; i < 4; i++) {
            dept_preferences[i][dept] = dept_preferences[i+1][dept];
        }
    }
    while(progs_taken[dept_preferences[0][dept]-1]);
}

int main() {
    FILE* fp = fopen("input.txt", "r");
	int dept_preferences[5][5];
	int prog_preferences[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			fscanf(fp, "%d", &dept_preferences[i][j]);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			fscanf(fp, "%d", &prog_preferences[i][j]);
		}
	}
	fclose(fp);
    
    int dept_preference;
    int progs_taken[5] = {0,0,0,0,0};
    for (int i = 0; i < 5; i++) {
        dept_preference = dept_preferences[0][i]-1;
        for (int j = i+1; j < 5; j++) {
            if (dept_preferences[0][i] == dept_preferences[0][j]) {
                for (int k = 0; k < 5; k++) {
                    if (prog_preferences[k][dept_preference] == i+1) {
                        removeTaken(dept_preferences, j, progs_taken);
                        break;
                    } 
                    if (prog_preferences[k][dept_preference] == j+1) {
                        removeTaken(dept_preferences, i, progs_taken);
                        j = i;
                        dept_preference = dept_preferences[0][i]-1;
                        break;
                    }
                }
            }
        }
        printf("Department #%d will get Programmer #%d\n", i+1, dept_preference+1);
        progs_taken[dept_preference] = 1;
    }

    return 0;
}