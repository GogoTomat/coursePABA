#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct _Morse {
    char morse[7];
    char symbol;
} Morse;

Morse dictionaryEng[] =
        {
                {".-", 'a'},
                {"-...", 'b'},
                {"-.-.", 'c'},
                {"-..", 'd'},
                {".", 'e'},
                {"..-.", 'f'},
                {"--.", 'g'},
                {"....", 'h'},
                {"..", 'i'},
                {".---", 'j'},
                {"-.-", 'k'},
                {".-..", 'l'},
                {"--", 'm'},
                {"-.", 'n'},
                {"---", 'o'},
                {".--.", 'p'},
                {"--.-", 'q'},
                {".-.", 'r'},
                {"...", 's'},
                {"-", 't'},
                {"..-", 'u'},
                {"...-", 'v'},
                {".--", 'w'},
                {"-.--", 'x'},
                {"-..-", 'y'},
                {"--..", 'z'},
                {"-----", '0'},
                {".----", '1'},
                {"..---", '2'},
                {"...--", '3'},
                {"....-", '4'},
                {"-....", '5'},
                {"--....", '6'},
                {"---...", '7'},
                {"---..", '8'},
                {"----.", '9'}
        };

Morse dictionaryRus[] = {
       {".-", 'а'},
       {"-...", 'б'},
       {".--", 'в'},
       {"--.", 'г'},
       {"-..", 'д'},
       {".", 'е'},
       {"...-", 'ж'},
       {"--..", 'з'},
       {"..", 'и'},
       {".---", 'й'},
       {"-.-", 'к'},
       {".-..", 'л'},
       {"--", 'м'},
       {"-.", 'н'},
       {"----", 'о'},
       {".--.", 'п'},
       {".-.", 'р'},
       {"...", 'с'},
       {".", 'т'},
       {"..-", 'у'},
       {"..-.", 'в'},
       {"....", 'х'},
       {"-.-.", 'ц'},
       {"---.", 'ч'},
       {"----", 'ш'},
       {"--.-", 'щ'},
       {".--.-.", 'ъ'},
       {"-.--", 'ы'},
       {"-..-", 'ь'},
       {"...-...", 'э'},
       {"..--", 'ю'},
       {".-.-", 'я'},
       {"-----", '0'},
       {".----", '1'},
       {"..---", '2'},
       {"...--", '3'},
       {"....-", '4'},
       {"-....", '5'},
       {"--....", '6'}, 
       {"---...", '7'},
       {"---..", '8'},
       {"----.", '9'}
};

char getOneLetterEng(char message[7]){
    char sym = 0;

    for (int j = 0; j < 36; j++)
        if(strcmp(message, dictionaryEng[j].morse) == 0)
            sym = dictionaryEng[j].symbol;

    return sym;
}

char getOneLetterRus(char message[7]){
    char sym = 0;

    for (int j = 0; j < 36; j++)
        if(strcmp(message, dictionaryRus[j].morse) == 0)
            sym = dictionaryRus[j].symbol;

    return sym;
}

void decodeEng(char message[250]){
    printf("Press '!' to quit the program");
    int i = 0;
    if (message == NULL){
        return;
    }
    while(printf("Enter text:\n"), fflush(stdin), fgets(message, 250, stdin) != NULL) {
        for(i = 0; message[i] != '\0'; i++) {
             if(message[i] == ' '){
                printf("    ");
            }
            else if (message[i] == '!'){
                exit(0);
            }
            else
                for (int j = 0; j < 36; j++)
                    if(message[i] == dictionaryEng[j].symbol) {
                        printf("%s ", dictionaryEng[j].morse);
                        break;
                    }
        }
        printf("\n");
    }
}

void decodeRus(char message[250]){
    printf("Press '!' to quit the program");
    int i = 0;
    if (message == NULL){
        return;
    }
    while(printf("Enter text:\n"), fflush(stdin), fgets(message, 250, stdin) != NULL) {
        for(i = 0; message[i] != '\0'; i++) {
            if(message[i] == ' ')
                printf("    ");
            else if (message[i] == '!'){
                exit(0);
            }
            else
                for (int j = 0; j < 36; j++)
                    if(message[i] == dictionaryRus[j].symbol) {
                        printf("%s ", dictionaryRus[j].morse);
                        break;
                    }
        }
        printf("\n");
    }
}

void encodeEng(char message[250])
{
    int i = 0;
    char buff[7] = {0};
    int iBuff = 0;
    printf("Press '!' to quit the program");
    while (printf("Enter text:\n"), fflush(stdin), fgets(message, 250, stdin) != NULL) {
        for (i = 0; i < 250; i++) {
            if (i && message[i-1] == ' ' && message[i] == ' ') {
                printf(" ");
            } 
            else if (message[i] == '!'){
                exit(0);
            }
            else if (message[i] == ' ' || message[i] == '\n' || message[i] == '\0') {
                if (message[i] == '\0')
                    break;
                char c = getOneLetterEng(buff);
                iBuff = 0;

                memset(buff, 0, 7);

                printf("%c", c);


            } else if (message[i] == '-' || message[i] == '.') {
                buff[iBuff] = message[i];
                iBuff++;
            }
        }
        printf("\n");
    }
}

void encodeRus(char message[250])
{
    int i = 0;
    char buff[7] = {0};
    int iBuff = 0;
    printf("Press '!' to quit the program");

    while (printf("Enter text:\n"), fflush(stdin), fgets(message, 250, stdin) != NULL) {
        for (i = 0; i < 250; i++) {
            if (i && message[i-1] == ' ' && message[i] == ' ') {
                printf(" ");
            } 
            else if (message[i] == '!'){
                exit(0);
            }
            else if (message[i] == ' ' || message[i] == '\n' || message[i] == '\0') {
                if (message[i] == '\0')
                    break;
                char c = getOneLetterRus(buff);
                iBuff = 0;

                memset(buff, 0, 7);

                printf("%c", c);


            } else if (message[i] == '-' || message[i] == '.') {
                buff[iBuff] = message[i];
                iBuff++;
            }
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int i = 0;
    char reply[1024];
    printf("Choose the action\n");
    printf("1 - Translate from English to Morse Code\n");
    printf("2 - Translate from Morse Code to English\n");
    printf("3 - Translate from Russian to Morse Code\n");
    printf("4 - Translate from Morse Code to Russian\n");
    int input;
    scanf( "%d", &input);
    switch (input) {
        case 1:
            decodeEng(reply);
            break;
        case 2:
            encodeEng(reply);
            break;
        case 3:
            decodeRus(reply);
        case 4:
            encodeRus(reply);
        default:
            printf("Wrong action");
    }

    return 0;
}
