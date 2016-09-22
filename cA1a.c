#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

int getNum(void);
void setCases(float cases[]);
//int pickUserCase();
//float randomNum(time_t t);
int pickCases(int numOfCases, float cases[]);

int main(void) {

	float cases[26];
	int userCase=0;
	setCases(cases);
	//userCase = pickUserCase();

	pickCases(6, cases);

		for (int i = 0; i < 13; i++) {
	printf("%7.1f%11.1f\n", cases[i], cases[i+13]);
	}
}


int getNum(void)
{
	char record[121] = { 0 };
	int number = 0;
	fgets(record, 121, stdin);
	if (sscanf(record, " %d", &number) != 1)
	{
		number = -1;
	}
	return number;
}


void setCases(float cases[]) {
	FILE *file;
	file = fopen("cases.txt", "r");
	float nextCase=0;
	time_t t;
	srand((unsigned)time(&t));
	int random;

	for (int i = 0; i < 26; i++) {
		cases[i] = i;
		printf("%f\n", cases[i]);
		//random = (rand() % 26);
		//printf("%d\n", random);
		//if (cases[random] == 0) {
			//cases[random] = fscanf(file, "%f", &cases[random]);
		//}
		/*random = (rand() % 26);
		if (cases[random] == 0) {
			fscanf(file, "%f", &cases[random]);
		}
		else {
			random = (rand() % 26);
			fscanf(file, "%f", &cases[random]);
		}*/
	
	}
	fclose(file);
}

/*int pickUserCase() {
	int nCase = 0;
	printf("please pick your case number\n");
		scanf_s("%d", &nCase);
		return nCase;
	}*/

int pickCases(int num, float cases[]) {
	int index=0;
	for (int i = 0; i < num; i++) {
		printf("pick a case...\n");
			index = getNum();
			printf("that case held %f\n", cases[index-1]);
			cases[index-1] = 00000.0000;
		}
	}