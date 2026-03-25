#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char**** get_document(char* text) {
    int p_count = 1;
    for(int i = 0; text[i]; i++)
        if(text[i] == '\n') p_count++;

    char**** document = malloc(p_count * sizeof(char***));

    int p = 0;
    char* para = strtok(text, "\n");
    while(para) {
        int s_count = 1;
        for(int i = 0; para[i]; i++)
            if(para[i] == '.') s_count++;

        document[p] = malloc(s_count * sizeof(char**));

        int s = 0;
        char* sent = strtok(para, ".");
        while(sent) {
            int w_count = 1;
            for(int i = 0; sent[i]; i++)
                if(sent[i] == ' ') w_count++;

            document[p][s] = malloc(w_count * sizeof(char*));

            int w = 0;
            char* word = strtok(sent, " ");
            while(word) {
                document[p][s][w] = malloc(strlen(word) + 1);
                strcpy(document[p][s][w], word);
                w++;
                word = strtok(NULL, " ");
            }
            s++;
            sent = strtok(NULL, ".");
        }
        p++;
        para = strtok(NULL, "\n");
    }
    return document;
}

char*** get_paragraph(char**** document, int p) {
    return document[p - 1];
}

char** get_sentence(char**** document, int p, int s) {
    return document[p - 1][s - 1];
}

char* get_word(char**** document, int p, int s, int w) {
    return document[p - 1][s - 1][w - 1];
}

