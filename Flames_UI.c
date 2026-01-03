/*
 * ╔═══════════════════════════════════════════════════════════╗
 * ║           🔥 FLAMES - Relationship Calculator 🔥          ║
 * ║                                                           ║
 * ║  Author: Saicharitha Dathrika                             ║
 * ║  Version: 2.0 (Enhanced UI)                               ║
 * ╚═══════════════════════════════════════════════════════════╝
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
#else
    #include <unistd.h>
    #define CLEAR "clear"
#endif

// ============================================
// ANSI Color Codes
// ============================================
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"

// ============================================
// Function Prototypes
// ============================================
void displayBanner();
void displayMenu();
void displayFlamesMeaning();
void displayResult(char result, char *name1, char *name2);
void playFlames();
void toLowercase(char *str);
void clearInputBuffer();
void pressEnterToContinue();
void displayCredits();
void displayLoadingAnimation();

// ============================================
// Main Function
// ============================================
int main() {
    int choice;
    
    #ifdef _WIN32
    // Enable ANSI colors on Windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | 0x0004);
    #endif
    
    do {
        system(CLEAR);
        displayBanner();
        displayMenu();
        
        printf(CYAN "\n  👉 Enter your choice: " RESET);
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                system(CLEAR);
                playFlames();
                break;
            case 2:
                system(CLEAR);
                displayFlamesMeaning();
                pressEnterToContinue();
                break;
            case 3:
                system(CLEAR);
                displayCredits();
                pressEnterToContinue();
                break;
            case 4:
                system(CLEAR);
                printf(YELLOW "\n\n");
                printf("  ╔═══════════════════════════════════════════════╗\n");
                printf("  ║                                               ║\n");
                printf("  ║   " MAGENTA "Thank you for playing FLAMES! 💖" YELLOW "           ║\n");
                printf("  ║                                               ║\n");
                printf("  ║   " WHITE "May you find your true relationship!" YELLOW "       ║\n");
                printf("  ║                                               ║\n");
                printf("  ╚═══════════════════════════════════════════════╝\n");
                printf(RESET "\n\n");
                break;
            default:
                printf(RED "\n  ❌ Invalid choice! Please try again.\n" RESET);
                pressEnterToContinue();
        }
    } while(choice != 4);
    
    return 0;
}

// ============================================
// Display Functions
// ============================================

void displayBanner() {
    printf(RED BOLD);
    printf("\n");
    printf("  ███████╗██╗      █████╗ ███╗   ███╗███████╗███████╗\n");
    printf("  ██╔════╝██║     ██╔══██╗████╗ ████║██╔════╝██╔════╝\n");
    printf("  █████╗  ██║     ███████║██╔████╔██║█████╗  ███████╗\n");
    printf("  ██╔══╝  ██║     ██╔══██║██║╚██╔╝██║██╔══╝  ╚════██║\n");
    printf("  ██║     ███████╗██║  ██║██║ ╚═╝ ██║███████╗███████║\n");
    printf("  ╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝\n");
    printf(RESET);
    printf(YELLOW "        🔥 Relationship Calculator Game 🔥\n" RESET);
    printf(CYAN "  ══════════════════════════════════════════════════\n" RESET);
}

void displayMenu() {
    printf(WHITE "\n");
    printf("  ┌─────────────────────────────────────────────────┐\n");
    printf("  │" CYAN "                   MAIN MENU                     " WHITE "│\n");
    printf("  ├─────────────────────────────────────────────────┤\n");
    printf("  │                                                 │\n");
    printf("  │   " GREEN "[1]" WHITE " 💕  Play FLAMES                          │\n");
    printf("  │                                                 │\n");
    printf("  │   " GREEN "[2]" WHITE " 📖  What is FLAMES?                      │\n");
    printf("  │                                                 │\n");
    printf("  │   " GREEN "[3]" WHITE " ℹ️   About / Credits                      │\n");
    printf("  │                                                 │\n");
    printf("  │   " GREEN "[4]" WHITE " 🚪  Exit                                  │\n");
    printf("  │                                                 │\n");
    printf("  └─────────────────────────────────────────────────┘\n");
    printf(RESET);
}

void displayFlamesMeaning() {
    printf(YELLOW BOLD "\n");
    printf("  ╔═══════════════════════════════════════════════════════╗\n");
    printf("  ║          📖 WHAT DOES FLAMES MEAN? 📖                 ║\n");
    printf("  ╠═══════════════════════════════════════════════════════╣\n" RESET);
    printf(WHITE "  ║                                                       ║\n");
    printf("  ║   " RED BOLD "F" RESET WHITE " - " GREEN "Friends" WHITE "     👫  Just good friends!           ║\n");
    printf("  ║                                                       ║\n");
    printf("  ║   " RED BOLD "L" RESET WHITE " - " MAGENTA "Love" WHITE "        💕  There's love in the air!     ║\n");
    printf("  ║                                                       ║\n");
    printf("  ║   " RED BOLD "A" RESET WHITE " - " CYAN "Affection" WHITE "   💖  Deep affection & care!       ║\n");
    printf("  ║                                                       ║\n");
    printf("  ║   " RED BOLD "M" RESET WHITE " - " YELLOW "Marriage" WHITE "    💒  Wedding bells are ringing!   ║\n");
    printf("  ║                                                       ║\n");
    printf("  ║   " RED BOLD "E" RESET WHITE " - " RED "Enemies" WHITE "     😠  Oops! Not a good match!       ║\n");
    printf("  ║                                                       ║\n");
    printf("  ║   " RED BOLD "S" RESET WHITE " - " BLUE "Siblings" WHITE "    👨‍👩‍👧‍👦  Like brother and sister!     ║\n");
    printf("  ║                                                       ║\n");
    printf(YELLOW "  ╚═══════════════════════════════════════════════════════╝\n" RESET);
    printf("\n");
    printf(CYAN "  ┌───────────────────────────────────────────────────────┐\n");
    printf("  │" WHITE "                    HOW TO PLAY                        " CYAN "│\n");
    printf("  ├───────────────────────────────────────────────────────┤\n");
    printf("  │" WHITE " 1. Enter two names                                   " CYAN "│\n");
    printf("  │" WHITE " 2. Common letters are removed                        " CYAN "│\n");
    printf("  │" WHITE " 3. Remaining letters are counted                     " CYAN "│\n");
    printf("  │" WHITE " 4. Count through F-L-A-M-E-S repeatedly              " CYAN "│\n");
    printf("  │" WHITE " 5. Last remaining letter = Your relationship!        " CYAN "│\n");
    printf("  └───────────────────────────────────────────────────────┘\n" RESET);
}

void displayCredits() {
    printf(MAGENTA BOLD "\n");
    printf("  ╔═══════════════════════════════════════════════════════╗\n");
    printf("  ║                    ABOUT / CREDITS                    ║\n");
    printf("  ╠═══════════════════════════════════════════════════════╣\n" RESET);
    printf(WHITE "  ║                                                       ║\n");
    printf("  ║   " CYAN "Program:" WHITE "    FLAMES - Relationship Calculator       ║\n");
    printf("  ║   " CYAN "Version:" WHITE "    2.0 (Enhanced UI Edition)              ║\n");
    printf("  ║   " CYAN "Language:" WHITE "   C Programming                          ║\n");
    printf("  ║                                                       ║\n");
    printf("  ║   " YELLOW "Author:" WHITE "     Saicharitha Dathrika                   ║\n");
    printf("  ║                                                       ║\n");
    printf("  ║   " GREEN "Features:" WHITE "                                          ║\n");
    printf("  ║     • Colorful Text-based UI                         ║\n");
    printf("  ║     • Interactive Menu System                        ║\n");
    printf("  ║     • Cross-platform Support                         ║\n");
    printf("  ║     • ASCII Art Graphics                             ║\n");
    printf("  ║                                                       ║\n");
    printf(MAGENTA "  ╚═══════════════════════════════════════════════════════╝\n" RESET);
}

void displayLoadingAnimation() {
    printf(YELLOW "\n  Calculating");
    fflush(stdout);
    for(int i = 0; i < 3; i++) {
        #ifdef _WIN32
        Sleep(400);
        #else
        usleep(400000);
        #endif
        printf(".");
        fflush(stdout);
    }
    printf(" 💫\n" RESET);
    #ifdef _WIN32
    Sleep(500);
    #else
    usleep(500000);
    #endif
}

void displayResult(char result, char *name1, char *name2) {
    printf(CYAN "\n  ══════════════════════════════════════════════════\n" RESET);
    printf(YELLOW BOLD "                      🎯 RESULT 🎯\n" RESET);
    printf(CYAN "  ══════════════════════════════════════════════════\n\n" RESET);
    
    printf(WHITE "       %s" MAGENTA " 💕 " WHITE "%s\n\n" RESET, name1, name2);
    
    switch(result) {
        case 'F':
            printf(GREEN BOLD);
            printf("  ┌─────────────────────────────────────────────────┐\n");
            printf("  │                                                 │\n");
            printf("  │      👫  F R I E N D S  👫                      │\n");
            printf("  │                                                 │\n");
            printf("  │    You two make amazing friends!                │\n");
            printf("  │    Cherish this beautiful friendship! 🌟        │\n");
            printf("  │                                                 │\n");
            printf("  └─────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'L':
            printf(MAGENTA BOLD);
            printf("  ┌─────────────────────────────────────────────────┐\n");
            printf("  │                                                 │\n");
            printf("  │      💕  L O V E  💕                            │\n");
            printf("  │                                                 │\n");
            printf("  │    There's LOVE in the air!                     │\n");
            printf("  │    You two are meant to be together! 💖         │\n");
            printf("  │                                                 │\n");
            printf("  └─────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'A':
            printf(CYAN BOLD);
            printf("  ┌─────────────────────────────────────────────────┐\n");
            printf("  │                                                 │\n");
            printf("  │      💖  A F F E C T I O N  💖                  │\n");
            printf("  │                                                 │\n");
            printf("  │    Deep affection connects you both!            │\n");
            printf("  │    There's a special bond between you! 🌹       │\n");
            printf("  │                                                 │\n");
            printf("  └─────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'M':
            printf(YELLOW BOLD);
            printf("  ┌─────────────────────────────────────────────────┐\n");
            printf("  │                                                 │\n");
            printf("  │      💒  M A R R I A G E  💒                    │\n");
            printf("  │                                                 │\n");
            printf("  │    Wedding bells are ringing!                   │\n");
            printf("  │    You two are destined to be together! 💍      │\n");
            printf("  │                                                 │\n");
            printf("  └─────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'E':
            printf(RED BOLD);
            printf("  ┌─────────────────────────────────────────────────┐\n");
            printf("  │                                                 │\n");
            printf("  │      😠  E N E M I E S  😠                      │\n");
            printf("  │                                                 │\n");
            printf("  │    Oops! Not a great match!                     │\n");
            printf("  │    Maybe try to understand each other? 🤔       │\n");
            printf("  │                                                 │\n");
            printf("  └─────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'S':
            printf(BLUE BOLD);
            printf("  ┌─────────────────────────────────────────────────┐\n");
            printf("  │                                                 │\n");
            printf("  │      👨‍👩‍👧‍👦  S I B L I N G S  👨‍👩‍👧‍👦                    │\n");
            printf("  │                                                 │\n");
            printf("  │    You share a sibling-like bond!               │\n");
            printf("  │    Family love is forever! 👪                   │\n");
            printf("  │                                                 │\n");
            printf("  └─────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
    }
    printf("\n");
}

// ============================================
// FLAMES Game Logic
// ============================================

void playFlames() {
    char name1[50], name2[50];
    int freq1[26] = {0}, freq2[26] = {0}, diff[26] = {0};
    int i, j, sum = 0;
    char playAgain;
    
    do {
        // Reset arrays
        for(i = 0; i < 26; i++) {
            freq1[i] = 0;
            freq2[i] = 0;
            diff[i] = 0;
        }
        sum = 0;
        
        system(CLEAR);
        
        printf(RED BOLD "\n");
        printf("  🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n");
        printf(RESET);
        printf(YELLOW BOLD "              💕 FLAMES CALCULATOR 💕\n" RESET);
        printf(RED BOLD "  🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n\n" RESET);
        
        printf(CYAN "  ┌─────────────────────────────────────────────────┐\n");
        printf("  │         Enter the names to check!                │\n");
        printf("  └─────────────────────────────────────────────────┘\n\n" RESET);
        
        // Get first name
        printf(GREEN "  👤 Enter First Name:  " WHITE);
        scanf("%49s", name1);
        clearInputBuffer();
        
        // Get second name
        printf(MAGENTA "  👤 Enter Second Name: " WHITE);
        scanf("%49s", name2);
        clearInputBuffer();
        
        // Convert to lowercase
        toLowercase(name1);
        toLowercase(name2);
        
        int len1 = strlen(name1);
        int len2 = strlen(name2);
        
        // Count letter frequencies for name1
        for(i = 0; i < len1; i++) {
            if(name1[i] >= 'a' && name1[i] <= 'z') {
                freq1[name1[i] - 'a']++;
            }
        }
        
        // Count letter frequencies for name2
        for(i = 0; i < len2; i++) {
            if(name2[i] >= 'a' && name2[i] <= 'z') {
                freq2[name2[i] - 'a']++;
            }
        }
        
        // Calculate absolute difference
        for(i = 0; i < 26; i++) {
            diff[i] = freq1[i] - freq2[i];
            if(diff[i] < 0) {
                diff[i] = -diff[i];
            }
            sum += diff[i];
        }
        
        // Loading animation
        displayLoadingAnimation();
        
        // FLAMES calculation
        char result;
        
        if(sum == 0) {
            result = 'M';  // Same name = Marriage
        }
        else if(sum <= 6) {
            switch(sum) {
                case 1: result = 'F'; break;
                case 2: result = 'L'; break;
                case 3: result = 'A'; break;
                case 4: result = 'M'; break;
                case 5: result = 'E'; break;
                case 6: result = 'S'; break;
            }
        }
        else {
            // FLAMES elimination algorithm
            char flames[] = "FLAMES";
            int flamesLen = 6;
            int pos = 0;
            
            while(flamesLen > 1) {
                // Calculate position to eliminate
                pos = (pos + sum - 1) % flamesLen;
                
                // Remove character at pos
                for(i = pos; i < flamesLen - 1; i++) {
                    flames[i] = flames[i + 1];
                }
                flamesLen--;
                flames[flamesLen] = '\0';
                
                // Adjust position if at end
                if(pos == flamesLen) {
                    pos = 0;
                }
            }
            result = flames[0];
        }
        
        // Capitalize names for display
        name1[0] = name1[0] - 32;
        name2[0] = name2[0] - 32;
        
        // Display result
        displayResult(result, name1, name2);
        
        // Play again?
        printf(YELLOW "\n  ┌─────────────────────────────────────────────────┐\n");
        printf("  │       Want to try another pair? (Y/N): " RESET);
        scanf(" %c", &playAgain);
        clearInputBuffer();
        printf(YELLOW "  └─────────────────────────────────────────────────┘\n" RESET);
        
    } while(playAgain == 'Y' || playAgain == 'y');
}

// ============================================
// Utility Functions
// ============================================

void toLowercase(char *str) {
    for(int i = 0; str[i]; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void pressEnterToContinue() {
    printf(YELLOW "\n  Press ENTER to continue..." RESET);
    getchar();
}