#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

int getNum(void);
void setCases(float cases[]);
int pickUserCase();
//float randomNum(time_t t);
int pickCases(int numOfCases, float cases[], int user);
int randNum(void);
float bankOffer(float cases[]);
int gameOver(int deal, float cases[], int userCase, float offer);
int printCases(float cases[]);

int main(void) {

	float cases[26];
	int userCase = 0, round = 0, deal = 0;
	float offer = 0;

	for (int i = 0; i < 26; i++) {
		cases[i] = 0;
	}

	setCases(cases);
	userCase = pickUserCase();

	for (int k = 6; k >= 1; k--) {
		round++;
		printf("this is round %d, pick %d cases\n", round, k);
		pickCases(k, cases, userCase);

		printCases(cases);
		offer = bankOffer(cases);
		printf("the banker offered you... $%.1f\n", offer);
		printf("Deal(1).. or no deal(2)?\n");
		deal = getNum();
		if (deal == 1) {
			gameOver(deal, cases, userCase, offer);
			break;
		}
		
	}
//	pickCases(6, cases, userCase);

	/*for (int i = 0; i < 13; i++) {
		printf("%7.1f%11.1f\n", cases[i], cases[i + 13]);
	}*/
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

int randNum(void) {
	
	int random;
	time_t t;
	srand((unsigned)time(&t));
	random = (rand() % 26);

	return random;


}
void setCases(float cases[]) {
	FILE *file;
	file = fopen("cases.txt", "r");
	float nextCase=0;
	time_t t;
	srand((unsigned)time(&t));
	int random;


	for (int i = 0; i < 26; i++) {
	fscanf(file, "%f", &cases[i]);
	}
	/*for (int i = 0; i < 26; i++) {
		RAND:
		random = randNum();

		if (cases[random] == 0) {
			fscanf(file, "%f", &cases[random]);
			printf("%f\n", cases[random]);
		}
		else{
			goto RAND;
		}*/
	/*for (int i = 0; i < 26;i++){

		random = randNum();

		if (cases[random] == 0) {
			fscanf(file, "%f", &cases[random]);
		}
		else {
			while (cases[random] != 0) {
				
				random = randNum();
				//fscanf(file, "%f", &cases[random]);
				if (cases[random] == 0) {
					printf("hi");
					break;
				
				}
			}
			fscanf(file, "%f", &cases[random]);
			
		}*/

		

		//cases[i] = i;
		//printf("%f\n", cases[i]);
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
	
	
	fclose(file);
}

int pickUserCase() {
	int nCase = 0;
	printf("please pick your case number\n");
	//	scanf_s("%d", &nCase);
	nCase = getNum();
		return nCase-1;
	}

int pickCases(int num, float cases[], int user) {
	int index=0;
	for (int i = 0; i < num; i++) {
		printf("pick a case...\n");
			index = getNum();
			if (index == (user+1)) {
				printf("You can't pick your own case dummy\n");
				//num++;
				i--;
			}
			else if (cases[index - 1] == 0.0) {
				printf("you already picked that case dummy\n");
				i--;
			}
			else {
				printf("that case held %f\n", cases[index - 1]);
				cases[index - 1] = 00000.0000;
			}
		}
	}

int printCases(float cases[]) {

	/*for (int i = 0; i < 13; i++) {
		if (cases[i] == 0) {
			printf("%7 gone%11.1f\n", cases[i + 13]);
		}
		else if (cases[i + 13] == 0) {
			printf("%7.1f%11 gone\n", cases[i]);
		}
		else if (cases[i] == 0 && cases[i + 13] == 0) {
			printf("%7 gone%11 gone\n");
		}
		else {
			printf("%7.1f%11.1f\n", cases[i], cases[i + 13]);
		}
	}*/

	for (int i = 0; i < 13; i++) {
		if (cases[i] == 0 && cases[i + 13] == 0) {
			printf("%7 gone%11 gone\n");
		}
		else if (cases[i] == 0) {
			printf("%7 gone%11d\n",i + 13);
		}
		else if (cases[i + 13] == 0) {
			printf("%7d%11 gone\n", i);
		} 
		else {
			printf("%7d%11d\n", i, i + 13);
		}
	}

}

float bankOffer(float cases[]) {

	int count = 0;
	float offer = 0, sum = 0;
	float random = (rand() % (110 + 1 - 75)) + 75;

	for (int i = 0; i < 26; i++) {
		if (cases[i] != 0) {
			sum += cases[i];
			count++;
		}
	}
	offer = sum / count;
	random /= 100;
	offer *= random;
	
	return offer;



}

int gameOver(int deal, float cases[], int userCase, float offer) {

	printf("Congrats, you won $%.1f\n",offer );
	printf("You're case held $%.1f\n", cases[userCase]);

	if (cases[userCase] > offer) {
		printf("You made a horrible deal\n");
	}
	else {
		printf("You made a great deal\n");
	}
	return 0;

}