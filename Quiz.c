#include <stdio.h>

void displayQuestion(const char *question, const char *options[], char correctOption);
char getAnswer();

int main() {
    int score = 0;
    char answer;

    const char *questions[] = {
        "What is the capital of France?",
        "Which planet is known as the Red Planet?",
        "Who wrote 'To Kill a Mockingbird'?",
        "What is the smallest prime number?",
        "Which element has the chemical symbol 'O'?"
    };

    const char *options[][4] = {
        {"A. Berlin", "B. Madrid", "C. Paris", "D. Rome"},
        {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"},
        {"A. Mark Twain", "B. J.K. Rowling", "C. Harper Lee", "D. Ernest Hemingway"},
        {"A. 0", "B. 1", "C. 2", "D. 3"},
        {"A. Gold", "B. Oxygen", "C. Silver", "D. Hydrogen"}
    };

    const char correctOptions[] = {'C', 'B', 'C', 'C', 'B'};

    int numQuestions = sizeof(correctOptions) / sizeof(correctOptions[0]);

    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questions[i], options[i], correctOptions[i]);
        answer = getAnswer();

        if (answer == correctOptions[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %c.\n", correctOptions[i]);
        }
        printf("\n");
    }

    printf("Your final score is %d out of %d.\n", score, numQuestions);

    return 0;
}

void displayQuestion(const char *question, const char *options[], char correctOption) {
    printf("%s\n", question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", options[i]);
    }
    printf("Enter your answer (A/B/C/D): ");
}

char getAnswer() {
    char answer;
    scanf(" %c", &answer);
    return answer;
}