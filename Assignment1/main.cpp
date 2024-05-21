#include <cstdio>
#include <cstring>
#include <cstdlib>

char** text;
int row_number = 10;
int buffer_size = 256;

void print_help(){
    printf("This program is the 'Simple Text Editor'\n"
           "It implements the following commands:\n");
    printf("1 - Append text symbols to the end\n");
    printf("2 - Start the new line\n");
    printf("3 - Saving the information\n");
    printf("4 - Loading the information\n");
    printf("5 - Print the current text to console\n");
    printf("6 - Insert the text by line and symbol index\n");
    printf("7 - Search for the text\n");
    printf("8 - Clearing the console\n");
}
void append_text_to_end(){

}

void start_new_line(){

}
void save_info(){

}
void load_info(){

}
void print_text(){

}
void insert_text_by_line(){

}
void search_text(){

}
void clear_console(){

}
int main() {
    int user_command;

    text = (char**)malloc(row_number * sizeof(char*)); // виділяємо памʼять для поінтерів
    if (text == nullptr){
        fprintf(stderr, "Cannot allocate memory for this input");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < row_number; i++){
        text[i] = (char*) malloc(buffer_size * sizeof(char));
        if (text[i] == nullptr){
            fprintf(stderr, "Cannot allocate memory for this input");
            return EXIT_FAILURE;
        }
        text[i][0] = '\0';
    }

    print_help();
    while (true){
        printf("Enter the command: ");
        scanf("%d", &user_command);
        switch (user_command) {
            case 1: append_text_to_end();
                break;
            case 2: start_new_line();
                break;
            case 3: save_info();
                break;
            case 4: load_info();
                break;
            case 5: print_text();
                break;
            case 6: insert_text_by_line();
                break;
            case 7: search_text();
                break;
            case 8: clear_console();
                break;
            default:
                printf("This command is not implemented\n");
        }
    }

}
