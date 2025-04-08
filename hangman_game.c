// C-Program to implement the Hangman Game
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6


//struct to hold a hint and word
struct WordWithHint
{
       char word[MAX_WORD_LENGTH];
       char hint[MAX_WORD_LENGTH];
};

//function to display the current status of the word
void display_word(const char word[], const bool guessed[]);

//function to draw the hangman
void draw_hangman(int tries);


//driver code
int main(){
  
   //seed the random number generator with the current state
   //time
   srand(time(NULL));
   
    //array of words and hints
    struct WordWithHint wordlist[] = 
    {
        {"apple","fruits"},
        {"tiger","animal"},
        {"play","verb"},
        {"ares","mythology"},
        //add more words and hints here
    };

    //select a ranfdom wword from the list
    int IndexList = rand() % 4;

    const char *SecretWord = wordlist[IndexList].word;
    const char *hint = wordlist[IndexList].hint;
   
     int wordLength = strlen(SecretWord);
     char guessedWord[MAX_WORD_LENGTH] = {0};
     bool guessedLetter[26] = {false};

     printf("welcome to hangman game\n");
     printf("hint: %s\n",hint);

     int tries = 0;
     while(tries < MAX_TRIES){

       printf("\n"); 
       display_word(guessedWord , guessedLetter);
       draw_hangman(tries);

       char guess;
       printf("Enter a letter: ");
         scanf(" %c",&guess);
            guess = tolower(guess);

            if(guessedLetter[guess - 'a']){
                printf("You've already guessed that letter. "
                       "Try again.\n");
                continue;
            }

            guessedLetter[guess - 'a'] = true;

            






     }




    return 0;
}


void display_word(const char word[], const bool guessed[])
{
    printf("Word: ");
    for(int i = 0 ; word[i] != '\0' ; i++){
         if(guessed[word[i] - 'a']){
            printf("%c ",word[i]); 
         }else{
            printf("_ ");
         }
    }
    printf("\n");
}

void draw_hangman(int tries)
{
    const char* hangmanParts[]
    = { "     _________",    "    |         |",
        "    |         O",   "    |        /|\\",
        "    |        / \\", "    |" };

printf("\n");
for (int i = 0; i <= tries; i++) {
    printf("%s\n", hangmanParts[i]);
}
}
