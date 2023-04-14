#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE  100
#define BUFFER_SIZE     2*MAX_INPUT_SIZE

/// @brief Gera todas as possíveis strings resultantes da inserção de espaços na string de entrada.
/// @param str string de entrada na qual os espaços serão inseridos.
/// @param index índice atual da string de entrada str.
/// @param buffer  buffer temporário para construir a string de saída com espaços.
/// @param buffer_index índice atual do buffer buffer.
void generate_strings_with_spaces(char* str, int index, char* buffer, int buffer_index) 
{    
    if (index == strlen(str)) // a geração da palavra com espaços foi concluída. 
	{
        buffer[buffer_index] = '\0';
        printf("%s", buffer);
        return;
    }

    buffer[buffer_index] = str[index];

    index++;

    generate_strings_with_spaces(str, index, buffer, buffer_index+1);

    if (index < strlen(str) && (str[index] != '\n')) 
	{
        buffer_index++;
        buffer[buffer_index] = ' ';
        generate_strings_with_spaces(str, index, buffer, buffer_index+1);
    }
    
    buffer_index--; // backtracking
}


int main() 
{
    char input_string[MAX_INPUT_SIZE];

    while (fgets(input_string, MAX_INPUT_SIZE, stdin)) 
	{
        char buffer[BUFFER_SIZE];
        generate_strings_with_spaces(input_string, 0, buffer, 0);
        printf("\n");
    }
    
    return 0;
}