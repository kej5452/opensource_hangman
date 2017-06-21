#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define MAX_Chance 7
#define MAX_STR_LEN 4000

void drawscreen(int chance, char* used_char, char* answer_word);
void drawintro();
char* choose_problem(int topic);
void play_game(char* word);
boolean compare_answer(char* word, char answer);
char*  trim(char *s); // 문자열 좌우 공백 모두 삭제 함수
char* ltrim(char *s); // 문자열 좌측 공백 제거 함수
char* rtrim(char* s); // 문자열 우측 공백 제거 함수

static int stopswitch = 0;
static int score = 0; 
int main() {
	char* word;
	int topic = 0;

		drawintro();
		scanf("%d", &topic);
		if (topic == 4) {
			printf("Quit\n");
			return 0;
		}
		while (1) {			
			word = choose_problem(topic);
			//printf("%s", word);
			play_game(word);
			if (stopswitch == 2) {
				printf("Game over! your score is %d.\n", score);
				stopswitch = 0;
				score = 0;					
				break;
			}
		}
		return 0;
}

void play_game(char* word) {
	char remained_char[27] = "abcdefghijklmnopqrstuvwxyz";
	remained_char[26] = '\0';
	char* answer_word = malloc((strlen(word))*sizeof(char));
	answer_word = strset(answer_word, ' ');
	answer_word[strlen(answer_word) - 1] = '\0';
	int index_used = 0;
	int used_chance = 0;
	boolean success = FALSE;
	char answer = ' ';
	int i;
	
	while (1) {
		drawscreen(used_chance, remained_char, answer_word);
		scanf("%c", &answer);
		scanf("%c", &answer);
		if (compare_answer(word, answer) == FALSE) {
			used_chance++;
			remained_char[answer - 97] = ' ';
		}
		else {
			for (i = 0;i < strlen(word);i++) {
				if (word[i] == answer) answer_word[i] = answer;
				remained_char[answer - 97] = ' ';
			}
		}
		if (strcmp(trim(answer_word), word) == 0) success = TRUE;
		drawscreen(used_chance, remained_char, answer_word);
		if (used_chance < MAX_Chance && success == TRUE) {
			score += 10;
			printf("\n");
			printf("You are right! The answer is %s.\n", answer_word);
			printf("Will you continue to solve the quiz? : 1.yes  2.no\n");
			scanf("%d", &stopswitch);
			break;
		}
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

void drawscreen(int chance, char* remained_char, char* answer_word) {
	system("cls");
	switch (chance) {
	case 0:
		printf("┌───┐\n│\n│\n│\n│\n└──────\n");	
		break;
	case 1:
		printf("┌───┐\n│　○\n│\n│\n│\n└──────\n");
		break;
	case 2:
		printf("┌───┐\n│　○\n│　 |\n│\n│\n└──────\n");
		break;
	case 3:
		printf("┌───┐\n│　○\n│　/|\n│\n│\n└──────\n");
		break;
	case 4:
		printf("┌───┐\n│　○\n│　/|＼\n│　\n│\n└──────\n");
		break;
	case 5:
		printf("┌───┐\n│　○\n│　/|＼\n│　/\n│\n└──────\n");
		break;
	case 6:
		printf("┌───┐\n│　○\n│　/|＼\n│　/＼\n│\n└──────\n");
		break;
	case 7:
		printf("┌───┐\n│　○\n│　 X\n│　/|＼\n│　/＼\n└──────\n");
		break;
	default:
		break;
	}
	printf("The characters that you can use : %s\n", remained_char);
	printf("your answer : %s\n", answer_word);
	printf("chance : %d\n", MAX_Chance - chance);
	printf("choose the character you want : ");
}

void drawintro() {
	printf("-------------------------------------------\n");
	printf("		HANGMAN					\n");
	printf("-------------------------------------------\n");
	printf("	choose topic (insert number)\n");
	printf("	1.fruit 2.animal 3.food 4.quit\n");
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

// 문자열 우측 공백문자 삭제 함수
char* rtrim(char* s) {
	char t[MAX_STR_LEN];
	char *end;

	// Visual C 2003 이하에서는
	// strcpy(t, s);
	// 이렇게 해야 함
	strcpy(t, s); // 이것은 Visual C 2005용
	end = t + strlen(t) - 1;
	while (end != t && isspace(*end))
		end--;
	*(end + 1) = '\0';
	s = t;

	return s;
}


// 문자열 좌측 공백문자 삭제 함수
char* ltrim(char *s) {
	char* begin;
	begin = s;

	while (*begin != '\0') {
		if (isspace(*begin))
			begin++;
		else {
			s = begin;
			break;
		}
	}

	return s;
}


// 문자열 앞뒤 공백 모두 삭제 함수
char* trim(char *s) {
	return rtrim(ltrim(s));
}