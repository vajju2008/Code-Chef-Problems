#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;
};

struct paragraph {
    struct sentence* data;
    int sentence_count;
};

struct document {
    struct paragraph* data;
    int paragraph_count;
};

struct document get_document(char* text) {
    struct document doc;
    doc.paragraph_count = 0;

    char* temp = malloc(strlen(text) + 1);
    strcpy(temp, text);

    char* p = strtok(temp, "\n");
    while (p) {
        doc.paragraph_count++;
        p = strtok(NULL, "\n");
    }

    doc.data = malloc(doc.paragraph_count * sizeof(struct paragraph));

    strcpy(temp, text);
    p = strtok(temp, "\n");
    int pi = 0;

    while (p) {
        struct paragraph para;
        para.sentence_count = 0;

        char* temp2 = malloc(strlen(p) + 1);
        strcpy(temp2, p);

        char* s = strtok(temp2, ".");
        while (s) {
            para.sentence_count++;
            s = strtok(NULL, ".");
        }

        para.data = malloc(para.sentence_count * sizeof(struct sentence));

        strcpy(temp2, p);
        s = strtok(temp2, ".");
        int si = 0;

        while (s) {
            struct sentence sen;
            sen.word_count = 0;

            char* temp3 = malloc(strlen(s) + 1);
            strcpy(temp3, s);

            char* w = strtok(temp3, " ");
            while (w) {
                sen.word_count++;
                w = strtok(NULL, " ");
            }

            sen.data = malloc(sen.word_count * sizeof(struct word));

            strcpy(temp3, s);
            w = strtok(temp3, " ");
            int wi = 0;

            while (w) {
                sen.data[wi].data = malloc(strlen(w) + 1);
                strcpy(sen.data[wi].data, w);
                wi++;
                w = strtok(NULL, " ");
            }

            para.data[si++] = sen;
            s = strtok(NULL, ".");
        }

        doc.data[pi++] = para;
        p = strtok(NULL, "\n");
    }

    return doc;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1];
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(
    struct document Doc, int k, int m, int n
) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

