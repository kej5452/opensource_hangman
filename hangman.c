#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

void drawscreen(int chance, char* used_char, char* answer_word);
void drawintro();
char* choose_problem(int topic);
void play_game(char* word);
boolean compare_answer(char* word, char answer);

int main() {
	char* word;
	int topic = 0;

		drawintro();
		scanf("%d", &topic);
		while (1) {
			if (topic == 4) {
				break;
			}
			else {
				word = choose_problem(topic);
				//printf("%s", word);
				play_game(word);
			}
		}
		return 0;
}

void play_game(char* word) {
	char* used_char = malloc (26*sizeof(char));
	char* answer_word = malloc(strlen(word)*sizeof(char));
	answer_word[strlen(word)] = '\0';
	int index_used = 0;
	int used_chance = 0;
	boolean success = FALSE;
	char answer = ' ';
	int i;
	//drawscreen(used_chance, used_char, answer_word);
	while (1) {
		used_char = "\0";
		scanf("%c", &answer);
		scanf("%c", &answer);
		if (compare_answer(word, answer) == FALSE) {
			used_chance++;
		}
		else {
			for (i = 0;i < strlen(word);i++) {
				if (word[i] == answer) answer_word[i] = answer;
			}
		}
		if (strcmp(word, answer_word) == 0) success = TRUE;
		drawscreen(used_chance, used_char, answer_word);
		if (used_chance < 7 && success == TRUE) break;	
	}

}

boolean compare_answer(char* word, char answer) {
	int i;
	int chance;
	boolean find = FALSE;
	for (i = 0;i < strlen(word);i++) {
		if (word[i] == answer) {
			find = TRUE;
			break;
		}	
	}
	return find;
}
void drawscreen(int chance, char* used_char, char* answer_word) {
	//system("cls");
	switch (chance) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		break;
	}

}

void drawintro() {
	//system("clear");
	//system("cls");
	printf("-------------------------------------------\n");
	printf("		HANGMAN					\n");
	printf("-------------------------------------------\n");
	printf("   문제의 주제를 선택하세요(번호입력)\n");
	printf("    1.과일 2.동물 3.음식 4.게임종료\n");
}

char* choose_problem(int topic) {
	int max_length = 15;
	char* word = malloc((max_length+2)*sizeof(char));
	int rand_counter = 0;
	int i;
	FILE *problem;
	switch (topic) {
	case 1:
		problem = fopen("fruit.txt", "r");
		rand_counter = rand() % 15; //각 주제 당 15개의 단어;
		for (i = 0;i < rand_counter;i++) {
			fgets(word, max_length, problem);
		}
		word[strlen(word)-1] = '\0';
		break;
	case 2:
		problem = fopen("animal.txt", "r");
		rand_counter = rand() % 15; //각 주제 당 15개의 단어;
		for (i = 0;i < rand_counter;i++) {
			fgets(word, max_length, problem);
		}
		word[strlen(word) - 1] = '\0';
		break;
	case 3:
		problem = fopen("food.txt", "r");
		rand_counter = rand() % 15; //각 주제 당 15개의 단어;
		for (i = 0;i < rand_counter;i++) {
			fgets(word, max_length, problem);
		}
		word[strlen(word) - 1] = '\0';
		break;
	default:
		break;
	}
	return word;
}