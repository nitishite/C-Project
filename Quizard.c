#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "submission_info.h"

// ANSI escape codes for text colors
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

// Structure to represent a quiz question.
struct QuizQuestion
{
    char question[256];
    char options[4][64];
    char correctOption;
};

// Arrays to store quiz questions for each category.
struct QuizQuestion sportsQuestions[20];
struct QuizQuestion triviaQuestions[20];
struct QuizQuestion politicsQuestions[20];

// Function to initialize quiz questions for all categories.
void initializeQuizQuestions()
{
    // Initialize sports questions and answers.
    struct QuizQuestion sportsQuestionsInit[20] = {
        {"Which country won the FIFA World Cup in 2022?",
         {"A. Brazil", "B. Germany", "C. Argentina", "D. France"},
         'C'},
        {"Who holds the record for the most centuries in Cricket?",
         {"A. Virat Kohli", "B. Sachin Tendulkar", "C. Ricky Ponting", "D. Don Bradman"},
         'B'},
        {"In which city were the 2010 Commonwealth Games held?",
         {"A. New Delhi", "B. London", "C. Sydney", "D. Toronto"},
         'A'},
        {"What is the most-watched sport in the world?",
         {"A. Basketball", "B. Cricket", "C. Football", "D. Baseball"},
         'C'},
        {"Who is considered the greatest boxer of all time?",
         {"A. Mike Tyson", "B. Floyd Mayweather", "C. Muhammad Ali", "D. Manny Pacquiao"},
         'C'},
        {"Which country is famous for inventing the sport of golf?",
         {"A. France", "B. Scotland", "C. Germany", "D. England"},
         'B'},
        {"Who is the fastest man in the world?",
         {"A. Usain Bolt", "B. Carl Lewis", "C. Michael Johnson", "D. Justin Gatlin"},
         'A'},
        {"Which country has won the most Olympic gold medals?",
         {"A. China", "B. Russia", "C. United States", "D. Germany"},
         'C'},
        {"Which Indian field hockey player, is often referred to as 'The Wizard'?",
         {"A. Dhanraj Pillay", "B. Sandeep Singh", "C. Dhyan Chand", "D. Sardar Singh"},
         'C'},
        {"Who is the most decorated Olympian of all time?",
         {"A. Michael Phelps", "B. Usain Bolt", "C. Simone Biles", "D. Jesse Owens"},
         'A'},
    };

    // Initialize trivia questions and answers.
    struct QuizQuestion triviaQuestionsInit[20] = {
        {"What is the largest planet in our solar system?",
         {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"},
         'C'},
        {"Who wrote the play 'Romeo and Juliet'?",
         {"A. William Shakespeare", "B. Charles Dickens", "C. Jane Austen", "D. Mark Twain"},
         'A'},
        {"Who painted the Mona Lisa?",
         {"A. Leonardo da Vinci", "B. Vincent van Gogh", "C. Pablo Picasso", "D. Michelangelo"},
         'A'},
        {"What is the chemical symbol for gold?",
         {"A. Go", "B. Gl", "C. Au", "D. Ag"},
         'C'},
        {"What is the largest mammal in the world?",
         {"A. Elephant", "B. Blue Whale", "C. Giraffe", "D. Rhinoceros"},
         'B'},
        {"Which planet is known as the Red Planet?",
         {"A. Venus", "B. Mars", "C. Jupiter", "D. Saturn"},
         'B'},
        {"What is the tallest mountain in the world?",
         {"A. Mount St. Helens", "B. Mount Kilimanjaro", "C. Mount Everest", "D. Mount Rushmore"},
         'C'},
        {"How many continents are there on Earth?",
         {"A. 4", "B. 6", "C. 7", "D. 5"},
         'C'},
        {"Who is the author of 'To Kill a Mockingbird'?",
         {"A. F. Scott Fitzgerald", "B. Harper Lee", "C. Ernest Hemingway", "D. George Orwell"},
         'B'},
        {"What is the largest ocean in the world?",
         {"A. Atlantic Ocean", "B. Indian Ocean", "C. Arctic Ocean", "D. Pacific Ocean"},
         'D'},
    };

    // Initialize politics questions and answers.
    struct QuizQuestion politicsQuestionsInit[20] = {
        {"Who is the current President of the United States?",
         {"A. Barack Obama", "B. Joe Biden", "C. Donald Trump", "D. George W. Bush"},
         'B'},
        {"Which political ideology supports smaller government and more personal freedom?",
         {"A. Liberalism", "B. Conservatism", "C. Libertarianism", "D. Socialism"},
         'C'},
        {"Who is the Prime Minister of the United Kingdom?",
         {"A. Boris Johnson", "B. Rishi Sunak", "C. Emmanuel Macron", "D. Theresa May"},
         'B'},
        {"In which year was the United Nations founded?",
         {"A. 1945", "B. 1956", "C. 1962", "D. 1931"},
         'A'},
        {"Who was the principal architect of the Indian Constitution?",
         {"A. Mahatma Gandhi", "B. Jawaharlal Nehru", "C. B.R. Ambedkar", "D. Sardar Vallabhbhai Patel"},
         'C'},
        {"Who is the Chancellor of Germany?",
         {"A. Angela Merkel", "B. Xi Jinping", "C. Olaf Scholz", "D. Tony Blair"},
         'C'},
        {"Which treaty established the European Union (EU)?",
         {"A. Treaty of Versailles", "B. Maastricht Treaty", "C. NATO Agreement", "D. Kyoto Protocol"},
         'B'},
        {"Who was the first President of India?",
         {"A. Jawaharlal Nehru", "B. Dr. Sarvepalli Radhakrishnan", "C. Sardar Vallabhbhai Patel", "D. Dr. Rajendra Prasad"},
         'D'},
        {"Which country is known as the 'Land of the Rising Sun'?",
         {"A. China", "B. South Korea", "C. Japan", "D. Vietnam"},
         'C'},
        {"Who is the current President of Russia?",
         {"A. Dmitry Medvedev", "B. Boris Yeltsin", "C. Vladimir Putin", "D. Mikhail Gorbachev"},
         'C'},
    };

    // Copy the initialized questions to the main array using pointers.
    for (int i = 0; i < 20; i++)
    {
        sportsQuestions[i] = sportsQuestionsInit[i];
        triviaQuestions[i] = triviaQuestionsInit[i];
        politicsQuestions[i] = politicsQuestionsInit[i];
    }
}

// Function to display a question with styling.
void displayQuestion(struct QuizQuestion *question, int questionNumber)
{
    system("cls");

    printf("Category: ");
    if (question >= sportsQuestions && question < sportsQuestions + 10)
    {
        printf("%s* * * Sports * * *%s\n", COLOR_YELLOW, COLOR_RESET);
    }
    else if (question >= triviaQuestions && question < triviaQuestions + 10)
    {
        printf("%s* * * Trivia * * *%s\n", COLOR_CYAN, COLOR_RESET);
    }
    else
    {
        printf("%s* * * Politics * * *%s\n", COLOR_RED, COLOR_RESET);
    }

    printf("*************************************\n\n");
    printf("%sQuestion %d: %s%s\n\n", COLOR_CYAN, questionNumber + 1, question->question, COLOR_RESET);

    for (int i = 0; i < 4; i++)
    {
        printf("%s%s%s\n\n", COLOR_GREEN, question->options[i], COLOR_RESET);
    }
}

// Function to clear the screen.
void clearScreen()
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n')
        ;
    getchar();
    system("cls");
}

void clearScreenMenu()
{
    while (getchar() != '\n')
        ;
    getchar();
}

void clearScreenMenuForQuiz()
{
    while (getchar() != '\n')
        ;
    system("cls");
}

// Function to display scores from the results file.
void viewScores()
{
    FILE *resultsFile = fopen("quiz_results.txt", "r");

    printf("\n%s********** Quiz Results **********%s\n\n", COLOR_YELLOW, COLOR_RESET);

    char line[256];
    while (fgets(line, sizeof(line), resultsFile))
    {
        printf("%s", line);
    }

    printf("\n%s**********************************%s\n", COLOR_YELLOW, COLOR_RESET);

    fclose(resultsFile);

    int viewScoresChoice;

    do
    {
        printf("\nOptions:\n");
        printf("\n1. Clear Results\n\n");
        printf("2. Return to Main Menu\n");
        printf("\nEnter the number of your choice: ");
        scanf("%d", &viewScoresChoice);

        switch (viewScoresChoice)
        {
        case 1:
            FILE *clearFile = fopen("quiz_results.txt", "w");
            if (clearFile != NULL)
            {
                system("cls");
                fclose(clearFile);
                printf("\n%s********** Results Cleared **********%s\n\n", COLOR_GREEN, COLOR_RESET);
                printf("\nPress Enter to go to Main Menu");
                getch();
                return;
            }
            else
            {
                printf("%sError clearing results.%s\n", COLOR_RED, COLOR_RESET);
                printf("\nPress Enter to go to Main Menu");
                getch();
                return;
            }
        case 2:
            return;
        default:
            printf("\n%sInvalid choice. Please try again.%s\n", COLOR_RED, COLOR_RESET);
            break;
        }
    } while (1);
}

void shuffleQuestions(struct QuizQuestion *questions, int poolSize)
{
    srand(time(NULL));
    for (int i = 0; i < poolSize - 1; i++)
    {
        int j = i + rand() % (poolSize - i);
        struct QuizQuestion temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int main()
{
    printf("%s\n", SUBMISSION_INFO);
    sleep(3);

    int categoryChoice;
    char playerName[64];

    initializeQuizQuestions();

    int mainMenuChoice;

    shuffleQuestions(sportsQuestions, 10);
    shuffleQuestions(triviaQuestions, 10);
    shuffleQuestions(politicsQuestions, 10);

    do
    {
    start:
        system("cls");

        shuffleQuestions(sportsQuestions, 10);
        shuffleQuestions(triviaQuestions, 10);
        shuffleQuestions(politicsQuestions, 10);

        printf("*************************************\n");
        printf("*                                   *\n");
        printf(" *       WELCOME TO QUIZARD!       *\n");
        printf("*                                   *\n");
        printf("*************************************\n\n");

        printf("Main Menu:\n");
        printf("\n%s1. Play Quizard!\n\n", COLOR_GREEN);
        printf("%s2. View Scores\n\n", COLOR_YELLOW);
        printf("%s0. Exit\n", COLOR_RED);

        printf("%s\nEnter the number of your choice: ", COLOR_RESET);
        scanf("%d", &mainMenuChoice);

        switch (mainMenuChoice)
        {
        case 0:
            return 0;

        case 1:
            do
            {
                system("cls");
                int correctAnswers = 0;

                printf("~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n");
                printf("|     Got what it takes to be a QUIZARD?!     |\n");
                printf("~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n");

                printf("\n\nPlease enter your name: ");
                scanf("%s", playerName);

                printf("\nSelect a quiz category:\n\n");
                printf("%s1. Sports\n\n", COLOR_BLUE);
                printf("%s2. Trivia\n\n", COLOR_CYAN);
                printf("%s3. Politics\n", COLOR_YELLOW);

                printf("%s\nEnter the number of the category you want to play (or 0 to go to the main menu): ", COLOR_RESET);
                scanf("%d", &categoryChoice);

                if (categoryChoice == 0)
                {
                    break;
                }

                if (categoryChoice < 1 || categoryChoice > 3)
                {
                    printf("\n%sInvalid category choice. Please try again.%s\n", COLOR_RED, COLOR_RESET);
                    clearScreen();
                }
                else
                {
                    system("cls");

                    struct QuizQuestion *categoryQuestions;
                    int categorySize;

                    if (categoryChoice == 1)
                    {
                        categoryQuestions = sportsQuestions;
                        categorySize = 10;
                    }
                    else if (categoryChoice == 2)
                    {
                        categoryQuestions = triviaQuestions;
                        categorySize = 10;
                    }
                    else if (categoryChoice == 3)
                    {
                        categoryQuestions = politicsQuestions;
                        categorySize = 10;
                    }

                    FILE *resultsFile = fopen("quiz_results.txt", "a");
                    if (resultsFile == NULL)
                    {
                        printf("%sError opening results file.%s\n", COLOR_RED, COLOR_RESET);
                        return 1;
                    }

                    for (int i = 0; i < categorySize; i++)
                    {
                        char answer;
                        displayQuestion(&categoryQuestions[i], i);
                        printf("%s\nEnter your answer (A/B/C/D):", COLOR_RESET);
                        scanf(" %c", &answer);

                        char correctAnswer = categoryQuestions[i].correctOption;

                        if (toupper(answer) == correctAnswer)
                        {
                            printf("\n%sYou chose the correct option.%s\n", COLOR_GREEN, COLOR_RESET);
                            correctAnswers++;
                        }
                        else
                        {
                            printf("\n%sSorry. The correct option is %c.%s\n", COLOR_RED, correctAnswer, COLOR_RESET);
                        }

                        clearScreen();
                    }

                    if (categoryChoice == 1)
                        fprintf(resultsFile, "Name: %s, Category: Sports, Score: %d\n", playerName, correctAnswers);
                    else if (categoryChoice == 2)
                        fprintf(resultsFile, "Name: %s, Category: Trivia, Score: %d\n", playerName, correctAnswers);
                    else if (categoryChoice == 3)
                        fprintf(resultsFile, "Name: %s, Category: Politics, Score: %d\n", playerName, correctAnswers);

                    fclose(resultsFile);

                    printf("\n%s%s, you got %d out of 10 questions correct.%s\n", COLOR_CYAN, playerName, correctAnswers, COLOR_RESET);

                    if (correctAnswers >= 8)
                    {
                        printf("\n%sCongratulations! You are a QUIZARD!%s\n", COLOR_GREEN, COLOR_RESET);
                    }
                    else
                    {
                        printf("\n%sSorry, you didn't win. Try again!%s\n", COLOR_RED, COLOR_RESET);
                    }

                    printf("%s\nPress Enter to go to the Main Menu...", COLOR_RESET);
                    clearScreenMenuForQuiz();
                    goto start;
                }
            } while (categoryChoice != 0);
            break;

        case 2:
            system("cls");
            viewScores();
            goto start;
            break;

        default:
            printf("\n%sInvalid choice. Please try again.%s\n", COLOR_RED, COLOR_RESET);
            clearScreenMenu();
            break;
        }
    } while (mainMenuChoice != 0);

    return 0;
}
