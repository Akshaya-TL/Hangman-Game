#include<stdio.h>
#include<time.h>
#include<string.h>
int main(){
	
	
	printf("\n\n                                                                                   Welcome to HANGMAN GAME \n");
	printf("                                                                           CREATED BY AKSHAYA(531) & SUDEEPYA(501)\n\n");
	printf("                                                               Please Read The Rules:\n\n");
	printf("                                                              > You will be given 10 chances.\n"); 
	printf("                                                              > You need to guess a five-lettered word.\n");
	printf("                                                              > Enter only one letter (a-z) for each chance.\n");
	printf("                                                              > Each wrong guess would near the man to death.\n");
	printf("                                                              > 5 wrong guesses and the man will die.\n");
	printf("                                                              > All the best and Save The Man!!!\n\n\n");
	char again = 'y';
   do{
    int i = 0, count = 0;
    int category, stop = 0; 
   	char guessedch, guessed_word[10] = "_ _ _ _ _", secret_word[10] = "_ _ _ _ _";
	srand(time(0));
	
	printf("                                                              Choose a category :\n");
	printf("                                                              1> COMPUTER          2> ANIMALS           \n");
	printf("                                                              3> FOOD              4> SPORTS          \n");
	printf("                                                              5> RANDOM                \n\n");
	printf("                                                              Enter category number : ");
	scanf("%d", &category);
	getchar();
	
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};  
	
	FILE *fp;
	switch(category){
	
	case 1:
	fp = fopen("C:\\Users\\AKSHAYA\\computer.txt", "r");
	fseek(fp, (rand() % 14) * 10, SEEK_SET);
	fgets(secret_word, 10, fp);
	fclose(fp);	
	break;
	
	case 2:
	fp = fopen("C:\\Users\\AKSHAYA\\animals.txt", "r");
	fseek(fp, (rand() % 14) * 10, SEEK_SET);
	fgets(secret_word, 10, fp);
	fclose(fp);	
	break;
	
	case 3:
	fp = fopen("C:\\Users\\AKSHAYA\\food.txt", "r");
	fseek(fp, (rand() % 14) * 10, SEEK_SET);
	fgets(secret_word, 10, fp);
	fclose(fp);	
	break;
	
	case 4:
	fp = fopen("C:\\Users\\AKSHAYA\\sports.txt", "r");
	fseek(fp, (rand() % 14) * 10, SEEK_SET);
	fgets(secret_word, 10, fp);
	fclose(fp);	
	break;
	
	case 5:
	while(i < 10){
 
	secret_word[i] = alpha[rand() % (26)];
	  i += 2;
	  }
	  break;
	  
     }
	
	
	printf("                                                                      %s", secret_word);                          //To explain the program more effectively
    int misses = 0;
    char missed_chars[6] = "     ";
     
    while(count < 10){
    int crct_guess = 0;
	
	label:
		
	printf( "\n                                                                       ** HANGMAN **\n");
	printf("                                                                     ***************\n");
	printf("                                                                     ...............\n\n");
	printf("                                                                        %s\n\n", guessed_word);  
 

	printf("                                                                     ...............\n\n");
	printf("                                                                     ***************\n");
	if(stop == -1){
    printf("\n\n                                                         CONGRATULATIONS YOU HAVE SAVED THE MAN !!! ");
	break;}
	
    printf("\n                                                                  misses: %s", missed_chars);
	printf("\n                                                                  Enter a char : ");
	scanf("%c", &guessedch);
	getchar();  
	for(i = 0; i < 10; i += 2){
		if(secret_word[i] == guessedch){
			guessed_word[i] = guessedch;
			crct_guess += 1;
		}
	}

	if(strcmp(guessed_word ,secret_word) == 0){
		stop = -1;
		goto label;
}
	else  if(crct_guess == 0){
		misses += 1;
		missed_chars[misses - 1] = guessedch;
		missed_chars[misses] = '\0';

		switch(misses){ 
		
		case 1:
		printf("                                                                      ____________\n");
        printf("                                                                      |          |\n");
        printf("                                                                                 |\n");
        printf("                                                                                 |\n");
        printf("                                                                                 |\n");
        printf("                                                                                 |\n");
        printf("                                                                     ____________|\n\n\n");
		break;
		
		case 2:
		printf("                                                                     ____________\n");
        printf("                                                                     |          |\n");
        printf("                                                                     O          |\n");
        printf("                                                                                |\n");
        printf("                                                                                |\n");
        printf("                                                                                |\n");
        printf("                                                                    ____________|\n\n\n");
		break;
		
		case 3:
     	printf("                                                                    ____________\n");
        printf("                                                                    |          |\n");
        printf("                                                                    O          |\n");
        printf("                                                                    |          |\n");
        printf("                                                                    |          |\n");
        printf("                                                                               |\n");
        printf("                                                                   ____________|\n\n\n");
		break;
		
		case 4:
		printf("                                                                    ____________\n");
        printf("                                                                    |          |\n");
        printf("                                                                    O          |\n");
        printf("                                                                   \\|/         |\n");
        printf("                                                                    |          |\n");
        printf("                                                                               |\n");
        printf("                                                                   ____________|\n\n\n");
		break;
			
	    case 5:
	    printf("                                                                     GAME OVER\n");
		printf("                                                                    ____________\n");
        printf("                                                                    |          |\n");
        printf("                                                                    O          |\n");
        printf("                                                                   \\|/         |\n");
        printf("                                                                    |          |\n");
        printf("                                                                   / \\         |\n");
        printf("                                                                   ____________|\n\n\n");
        printf("                                                                 misses : %s  \n\n", missed_chars);
		break;
		}
		if(misses == 5)
		break;
}
	
	count++ ;}
	
	printf("\n                                                                The secret word is %s", secret_word);
	printf("\n                                                                 Do u want to play again ? (y/n) ");
	scanf("%c", &again);
	}while(again == 'y');
	printf("\n                                                                    Thank You for playing!!!");
	return 0;
}


