//
//  main.c
//  task3
//
//  Created by Qurrat ULAIN KHAN on 18/09/25.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check password strength
int checkPasswordStrength(char password[]) {
    size_t length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    for ( size_t i= 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    int score = 0;

    // Check criteria
    if (length >= 8) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    return score;
}

int main(void) {
    char password[100];

    printf("Enter a password: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);

    printf("\nPassword strength analysis:\n");

    if (strength <= 2) {
        printf("Weak Password ❌\n");
    } else if (strength == 3 || strength == 4) {
        printf("Medium Password ⚠️\n");
    } else if (strength == 5) {
        printf("Strong Password ✅\n");
    }

    return 0;
}
