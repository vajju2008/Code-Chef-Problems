#include <stdio.h>

#include <string.h>

#include <stdbool.h>


#define MAX_LEN 201 // Maximum combined length of names and pile


void count_letters(const char* str, int* letter_count) {

while (*str) {

letter_count[*str - 'A']++;

str++;

}

}


int main() {

int i;

char guest[MAX_LEN], host[MAX_LEN], pile[MAX_LEN];

int guest_host_letters[26] = {0}; // Count for guest and host letters

int pile_letters[26] = {0}; // Count for pile letters


// Input the guest's name, host's name, and the pile of letters

scanf("%s", guest);

scanf("%s", host);

scanf("%s", pile);


// Count letters in guest's and host's names

count_letters(guest, guest_host_letters);

count_letters(host, guest_host_letters);


// Count letters in the pile

count_letters(pile, pile_letters);


// Compare the letter counts

bool is_possible = true;

for (i = 0; i < 26; i++) {

if (guest_host_letters[i] != pile_letters[i]) {

is_possible = false;

break;

}

}


// Output the result

if (is_possible) {

printf("YES\n");

} else {

printf("NO\n");

}


return 0;

}