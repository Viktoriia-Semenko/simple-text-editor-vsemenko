#include <cstdio>
#include <cstring>
#include <cstdlib>

char** text;
int row_number = 10;
int buffer_size = 256;
int line_count = 0;

void print_help();
void append_text_to_end();
void start_new_line();
void save_info();
void load_info();
void print_text();
void insert_text_by_line();
void search_text();
void free_memory();
bool file_exists(const char* filename);

enum Commands{
    COMMAND_HELP = 0,
    COMMAND_APPEND = 1,
    COMMAND_NEW_LINE = 2,
    COMMAND_SAVE = 3,
    COMMAND_LOAD = 4,
    COMMAND_PRINT = 5,
    COMMAND_INSERT_LI = 6,
    COMMAND_SEARCH = 7,
};

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
        char continue_input[2];
        printf("Enter the command: ");
        if (scanf("%d", &user_command) != 1){ // scanf повертає 1, якщо програма зчитала інтежер
            printf("Invalid input. Please, enter the number given in the help-menu.\n");
            int a;
            while ((a = getchar()) != '\n') {}
            continue;
        }
        switch (user_command) {
            case COMMAND_HELP:
                print_help();
                break;
            case COMMAND_APPEND:
                append_text_to_end();
                break;
            case COMMAND_NEW_LINE:
                start_new_line();
                break;
            case COMMAND_SAVE:
                save_info();
                break;
            case COMMAND_LOAD:
                load_info();
                break;
            case COMMAND_PRINT:
                print_text();
                break;
            case COMMAND_INSERT_LI:
                insert_text_by_line();
                break;
            case COMMAND_SEARCH:
                search_text();
                break;
            default:
                printf("This command is not implemented\n");
        }
        printf("Do you want to continue?:(y/n) ");
        scanf("%s", continue_input);
        if (strcmp(continue_input, "y") == 0){
            continue;
        }
        else if (strcmp(continue_input, "n") == 0){
            break;
        }
        else printf("Enter a valid answer\n");
   }
    free_memory();
    return 0;
}

void print_help(){
    printf("This program is the 'Simple Text Editor'\n"
           "It implements the following commands:\n");
    printf("0 - See the commands\n");
    printf("1 - Append text symbols to the end\n");
    printf("2 - Start the new line\n");
    printf("3 - Saving the information\n");
    printf("4 - Loading the information\n");
    printf("5 - Print the current text to console\n");
    printf("6 - Insert the text by line and symbol index\n");
    printf("7 - Search for the text\n");
}

void append_text_to_end(){
    char buffer[256];
    printf("Enter a text to append: ");
    getchar(); // видалєямо рядок залишений з інпута
    fgets(buffer, buffer_size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // якщо знайдемо новий рядок

    if (line_count == 0){
        strcpy(text[line_count], buffer);
        line_count ++;
    } else{
        strcat(text[line_count - 1], buffer); // додаємо текст в останній рядок
    }
}

void start_new_line(){
    if (line_count >= row_number){
        row_number *= 2; // якщо недостатньо рядків, то виділяємо в два рази більше
        text = (char**)realloc(text, row_number * sizeof(char*));
        if (text == nullptr){
            fprintf(stderr, "Fail to reallocate memory\n");
            exit(EXIT_FAILURE);
        }
        for (int i = line_count; i < row_number; i++) {
            text[i] = (char*)malloc(buffer_size * sizeof(char)); // виділяємо памʼять для нових рядків
            if (text[i] == nullptr){
                fprintf(stderr, "Memory allocating is failed\n");
                exit(EXIT_FAILURE);
            }
            text[i][0] = '\0';
        }
    }
    text[line_count][0] = '\0';
    line_count++; // до підрахунку рядків додаємо рядок
    printf("New line is started.\n");
}

void save_info(){
    char save_name[100];
    printf("Enter the file name for saving: ");
    scanf("%s", save_name);

    FILE* file;
    if (file_exists(save_name)){
        printf("Do you want ot overwrite this file (y/n)?: ");
        char response;
        getchar();
        scanf("%c", &response);

        if (response == 'y'){
            file = fopen(save_name, "w");
        } else if (response == 'n'){
            file = fopen(save_name, "a");
            fseek(file, 0, SEEK_END);
        } else {
            printf("Invalid answer\n");
            return;
        }

    } else {
        file = fopen(save_name, "w");
    }
    if (file == nullptr)
    {
        printf("Error while opening file\n");
        return;
    }

    for (int i = 0; i < line_count; i++) {
        fprintf(file, "%s\n", text[i]); // додаємо новий рядок псіля кожного нового
    }
    fclose(file);
    printf("Text has been saved successfully\n");
}

void load_info(){
    char load_name[100];
    printf("Enter the file name for loading: ");
    scanf("%s", load_name);

    FILE* file;
    file = fopen(load_name, "r");
    if (file == nullptr) {
        printf("Error opening file");
    }
    else {
        char my_string[100];
        while (fgets(my_string, sizeof(my_string), file) != nullptr) { // sizeof - максимальна кількість прочитаних рядків``
            printf("%s\n", my_string);
        }
        fclose(file);
        printf("Text has been loaded successfully\n");
    }
}

void print_text(){
    for (int i = 0; i < line_count; i++) {
        printf("%s\n", text[i]);
    }
}

void insert_text_by_line(){
    int line, index;
    char buffer[256];
    printf("Choose line and index: ");
    scanf("%d %d", &line, &index);
    if (line >= line_count || index > strlen(text[line])) {
        printf("You entered invalid line or index");
        return;
    }

    printf("Enter text to insert: ");
    getchar(); // очищуємо новий рядок що залишився від scanf
    fgets(buffer, buffer_size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // видалення пустого рядку який йде після інпута користувача

    char temporary_buffer[256]; // зберігає текст який уде псіля того що ми вставили
    strcpy(temporary_buffer, text[line] + index);
    text[line][index] = '\0'; // щоб завершити рядок
    strcat(text[line], buffer); // додаємо текст до існуючого рядка
    strcat(text[line], temporary_buffer); // додаємо текст який залишився після того що вставили
    printf("Text has been inserted.\n");
}

void search_text(){
    char buffer[256];
    printf("Enter text to search: ");
    getchar();
    fgets(buffer, buffer_size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    bool is_found = false;
    for (int i = 0; i < line_count; i++) {
        char* position = text[i];
        while((position = strstr(position, buffer)) != nullptr){
            printf("Text is present in this position: %d %ld\n", i, position - text[i]);
            position += strlen(buffer);
            is_found = true;
            }
        }
    if (!is_found){
        printf("There is no match for the given text.\n");
    }
}

void free_memory(){
    for (int i = 0; i < row_number; i++) {
        free(text[i]);
    }
    free(text);
}

bool file_exists(const char *filename){
    FILE* file_pointer = fopen(filename, "r");
    bool is_exists = false;
    if (file_pointer != nullptr){
        is_exists = true;
        fclose(file_pointer);
    }
    return is_exists;
}