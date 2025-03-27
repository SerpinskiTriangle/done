#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_WORD_SIZE 64
#define MAX_WORD_COUNT (64 * 64) // idk


struct word_node {
  char *word;
  int word_length;
  int occurances;
};




char word_terminators[3] = [' ', '\n', '\t'];


int char_in(char char, char *string, int string_len){
  for (int i = 0; i < string_len; i++){
    char == string[i] ? return 1 : 0;
  }
  return -1;
}


int same_word(char *word_1, int word_1_len, char *word_2, int word_2_len){
  if (word_1_len != word_2_len){
    return 0;
  }

  for (int index = 0; index < word_1_len; index++){
    if (word_1[index] != word_2[index]){
      return 0;
    }
  }

  return 1;
}


int insert_word(char *word, int word_len, struct word_node *word_list, int word_list_len){
  for (int index = 0; index < word_list_len; index++){
     
  }
}


int main(){
  FILE *file = fopen("test.txt", "r");


  if (file == NULL){
    printf("failed to open file \n");
    exit(EXIT_FAILURE);
  }


  char c;

  char *word = (char *)calloc(MAX_WORD_SIZE, sizeof(char));

  struct word_node *word_list = (struct word_node *)calloc(MAX_WORD_COUNT, sizeof(word_node));

  while ((c = fgetc(file)) != EOF){
    //check for word terminating chars
    if(char_in(c, word_terminators)){
           
    }
      //if not add char to word buffer
      //if so handle the word
  }


  return 0;
}
