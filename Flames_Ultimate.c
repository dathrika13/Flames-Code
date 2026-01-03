/*
 * ╔═══════════════════════════════════════════════════════════════════════╗
 * ║              🔥 FLAMES - Ultimate Edition 🔥                          ║
 * ║                                                                       ║
 * ║  Author: Saicharitha Dathrika                                         ║
 * ║  Version: 3.0 (Ultimate Edition)                                      ║
 * ║                                                                       ║
 * ║  Features:                                                            ║
 * ║  ✅ Colorful Text UI          ✅ Names with spaces                    ║
 * ║  ✅ History tracking          ✅ Save to file                         ║
 * ║  ✅ Sound effects             ✅ Longer names (100 chars)             ║
 * ╚═══════════════════════════════════════════════════════════════════════╝
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
    #define BEEP() Beep(800, 200)
    #define BEEP_SUCCESS() { Beep(523, 150); Beep(659, 150); Beep(784, 200); }
    #define BEEP_LOVE() { Beep(523, 100); Beep(659, 100); Beep(784, 100); Beep(1047, 300); }
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define CLEAR "clear"
    #define BEEP() printf("\a"); fflush(stdout)
    #define BEEP_SUCCESS() { printf("\a"); fflush(stdout); }
    #define BEEP_LOVE() { printf("\a"); fflush(stdout); usleep(100000); printf("\a"); fflush(stdout); }
    #define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

// ============================================
// ANSI Color Codes
// ============================================
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define ITALIC      "\033[3m"
#define UNDERLINE   "\033[4m"
#define BLINK       "\033[5m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BRIGHT_RED  "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"

// ============================================
// Constants
// ============================================
#define MAX_NAME_LENGTH 100
#define MAX_HISTORY 50
#define HISTORY_FILE "flames_history.txt"

// ============================================
// Data Structures
// ============================================
typedef struct {
    char name1[MAX_NAME_LENGTH];
    char name2[MAX_NAME_LENGTH];
    char result;
    char resultText[20];
    char timestamp[30];
} FlamesRecord;

// Global history array
FlamesRecord history[MAX_HISTORY];
int historyCount = 0;
int soundEnabled = 1;

// ============================================
// Function Prototypes
// ============================================
void displayBanner();
void displayMenu();
void displayFlamesMeaning();
void displayResult(char result, char *name1, char *name2);
void playFlames();
void toLowercase(char *str);
void removeNonAlpha(char *dest, const char *src);
void clearInputBuffer();
void pressEnterToContinue();
void displayCredits();
void displayLoadingAnimation();
void displayHistory();
void saveResultToFile(FlamesRecord *record);
void loadHistoryFromFile();
void clearHistory();
void getCurrentTimestamp(char *buffer);
char calculateFlames(const char *name1, const char *name2);
const char* getResultText(char result);
void playSound(char result);
void settingsMenu();
void exportHistory();

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
    
    // Load history from file
    loadHistoryFromFile();
    
    do {
        system(CLEAR);
        displayBanner();
        displayMenu();
        
        printf(CYAN "\n  👉 Enter your choice: " RESET);
        if(scanf("%d", &choice) != 1) {
            clearInputBuffer();
            choice = -1;
        }
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                system(CLEAR);
                playFlames();
                break;
            case 2:
                system(CLEAR);
                displayHistory();
                pressEnterToContinue();
                break;
            case 3:
                system(CLEAR);
                displayFlamesMeaning();
                pressEnterToContinue();
                break;
            case 4:
                system(CLEAR);
                settingsMenu();
                break;
            case 5:
                system(CLEAR);
                displayCredits();
                pressEnterToContinue();
                break;
            case 6:
                system(CLEAR);
                printf(YELLOW "\n\n");
                printf("  ╔═══════════════════════════════════════════════════════╗\n");
                printf("  ║                                                       ║\n");
                printf("  ║   " MAGENTA "Thank you for playing FLAMES Ultimate! 💖" YELLOW "          ║\n");
                printf("  ║                                                       ║\n");
                printf("  ║   " WHITE "Your history has been saved automatically." YELLOW "          ║\n");
                printf("  ║   " WHITE "May you find your true relationship!" YELLOW "                ║\n");
                printf("  ║                                                       ║\n");
                printf("  ╚═══════════════════════════════════════════════════════╝\n");
                printf(RESET "\n\n");
                if(soundEnabled) BEEP();
                break;
            default:
                printf(RED "\n  ❌ Invalid choice! Please try again.\n" RESET);
                if(soundEnabled) BEEP();
                pressEnterToContinue();
        }
    } while(choice != 6);
    
    return 0;
}

// ============================================
// Display Functions
// ============================================

void displayBanner() {
    printf(BRIGHT_RED BOLD);
    printf("\n");
    printf("  ███████╗██╗      █████╗ ███╗   ███╗███████╗███████╗\n");
    printf("  ██╔════╝██║     ██╔══██╗████╗ ████║██╔════╝██╔════╝\n");
    printf("  █████╗  ██║     ███████║██╔████╔██║█████╗  ███████╗\n");
    printf("  ██╔══╝  ██║     ██╔══██║██║╚██╔╝██║██╔══╝  ╚════██║\n");
    printf("  ██║     ███████╗██║  ██║██║ ╚═╝ ██║███████╗███████║\n");
    printf("  ╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝\n");
    printf(RESET);
    printf(BRIGHT_YELLOW "          🔥 Ultimate Relationship Calculator 🔥\n" RESET);
    printf(DIM "                    Version 3.0\n" RESET);
    printf(CYAN "  ════════════════════════════════════════════════════════\n" RESET);
}

void displayMenu() {
    printf(WHITE "\n");
    printf("  ┌───────────────────────────────────────────────────────┐\n");
    printf("  │" BRIGHT_CYAN "                     MAIN MENU                         " WHITE "│\n");
    printf("  ├───────────────────────────────────────────────────────┤\n");
    printf("  │                                                       │\n");
    printf("  │   " BRIGHT_GREEN "[1]" WHITE " 💕  Play FLAMES                                  │\n");
    printf("  │                                                       │\n");
    printf("  │   " BRIGHT_GREEN "[2]" WHITE " 📜  View History (%d records)                    │\n", historyCount);
    printf("  │                                                       │\n");
    printf("  │   " BRIGHT_GREEN "[3]" WHITE " 📖  What is FLAMES?                              │\n");
    printf("  │                                                       │\n");
    printf("  │   " BRIGHT_GREEN "[4]" WHITE " ⚙️   Settings                                    │\n");
    printf("  │                                                       │\n");
    printf("  │   " BRIGHT_GREEN "[5]" WHITE " ℹ️   About / Credits                              │\n");
    printf("  │                                                       │\n");
    printf("  │   " BRIGHT_GREEN "[6]" WHITE " 🚪  Exit                                         │\n");
    printf("  │                                                       │\n");
    printf("  └───────────────────────────────────────────────────────┘\n");
    printf(RESET);
}

void settingsMenu() {
    int choice;
    do {
        system(CLEAR);
        printf(BRIGHT_YELLOW BOLD "\n");
        printf("  ╔═══════════════════════════════════════════════════════╗\n");
        printf("  ║                   ⚙️  SETTINGS                         ║\n");
        printf("  ╠═══════════════════════════════════════════════════════╣\n" RESET);
        printf(WHITE "  ║                                                       ║\n");
        printf("  ║   " BRIGHT_GREEN "[1]" WHITE " 🔊  Sound Effects: %-3s                         ║\n", soundEnabled ? "ON " : "OFF");
        printf("  ║                                                       ║\n");
        printf("  ║   " BRIGHT_GREEN "[2]" WHITE " 📤  Export History to File                       ║\n");
        printf("  ║                                                       ║\n");
        printf("  ║   " BRIGHT_GREEN "[3]" WHITE " 🗑️   Clear All History                           ║\n");
        printf("  ║                                                       ║\n");
        printf("  ║   " BRIGHT_GREEN "[4]" WHITE " ↩️   Back to Main Menu                           ║\n");
        printf("  ║                                                       ║\n");
        printf(BRIGHT_YELLOW "  ╚═══════════════════════════════════════════════════════╝\n" RESET);
        
        printf(CYAN "\n  👉 Enter choice: " RESET);
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                soundEnabled = !soundEnabled;
                printf(GREEN "\n  ✅ Sound effects %s!\n" RESET, soundEnabled ? "enabled" : "disabled");
                if(soundEnabled) BEEP();
                SLEEP_MS(1000);
                break;
            case 2:
                exportHistory();
                pressEnterToContinue();
                break;
            case 3:
                printf(YELLOW "\n  ⚠️  Are you sure you want to clear all history? (y/n): " RESET);
                char confirm;
                scanf(" %c", &confirm);
                clearInputBuffer();
                if(confirm == 'y' || confirm == 'Y') {
                    clearHistory();
                    printf(GREEN "\n  ✅ History cleared!\n" RESET);
                } else {
                    printf(CYAN "\n  ℹ️  Operation cancelled.\n" RESET);
                }
                SLEEP_MS(1500);
                break;
            case 4:
                break;
            default:
                printf(RED "\n  ❌ Invalid choice!\n" RESET);
                SLEEP_MS(1000);
        }
    } while(choice != 4);
}

void displayFlamesMeaning() {
    printf(BRIGHT_YELLOW BOLD "\n");
    printf("  ╔═══════════════════════════════════════════════════════════╗\n");
    printf("  ║            📖 WHAT DOES FLAMES MEAN? 📖                   ║\n");
    printf("  ╠═══════════════════════════════════════════════════════════╣\n" RESET);
    printf(WHITE "  ║                                                           ║\n");
    printf("  ║   " BRIGHT_RED BOLD "F" RESET WHITE " - " BRIGHT_GREEN "Friends" WHITE "       👫  Just good friends!             ║\n");
    printf("  ║                                                           ║\n");
    printf("  ║   " BRIGHT_RED BOLD "L" RESET WHITE " - " BRIGHT_MAGENTA "Love" WHITE "          💕  There's love in the air!       ║\n");
    printf("  ║                                                           ║\n");
    printf("  ║   " BRIGHT_RED BOLD "A" RESET WHITE " - " BRIGHT_CYAN "Affection" WHITE "     💖  Deep affection & care!         ║\n");
    printf("  ║                                                           ║\n");
    printf("  ║   " BRIGHT_RED BOLD "M" RESET WHITE " - " BRIGHT_YELLOW "Marriage" WHITE "      💒  Wedding bells are ringing!     ║\n");
    printf("  ║                                                           ║\n");
    printf("  ║   " BRIGHT_RED BOLD "E" RESET WHITE " - " RED "Enemies" WHITE "       😠  Oops! Not a good match!         ║\n");
    printf("  ║                                                           ║\n");
    printf("  ║   " BRIGHT_RED BOLD "S" RESET WHITE " - " BRIGHT_BLUE "Siblings" WHITE "      👨‍👩‍👧‍👦  Like brother and sister!       ║\n");
    printf("  ║                                                           ║\n");
    printf(BRIGHT_YELLOW "  ╚═══════════════════════════════════════════════════════════╝\n" RESET);
    printf("\n");
    printf(BRIGHT_CYAN "  ┌───────────────────────────────────────────────────────────┐\n");
    printf("  │" WHITE "                      HOW TO PLAY                          " BRIGHT_CYAN "│\n");
    printf("  ├───────────────────────────────────────────────────────────┤\n");
    printf("  │" WHITE " 1. Enter two names (spaces allowed!)                      " BRIGHT_CYAN "│\n");
    printf("  │" WHITE " 2. Common letters are counted and removed                 " BRIGHT_CYAN "│\n");
    printf("  │" WHITE " 3. Remaining count is used for elimination                " BRIGHT_CYAN "│\n");
    printf("  │" WHITE " 4. Count through F-L-A-M-E-S repeatedly                   " BRIGHT_CYAN "│\n");
    printf("  │" WHITE " 5. Last remaining letter = Your relationship!             " BRIGHT_CYAN "│\n");
    printf("  └───────────────────────────────────────────────────────────┘\n" RESET);
}

void displayCredits() {
    printf(BRIGHT_MAGENTA BOLD "\n");
    printf("  ╔═══════════════════════════════════════════════════════════╗\n");
    printf("  ║                    ABOUT / CREDITS                        ║\n");
    printf("  ╠═══════════════════════════════════════════════════════════╣\n" RESET);
    printf(WHITE "  ║                                                           ║\n");
    printf("  ║   " BRIGHT_CYAN "Program:" WHITE "      FLAMES - Ultimate Edition                 ║\n");
    printf("  ║   " BRIGHT_CYAN "Version:" WHITE "      3.0                                       ║\n");
    printf("  ║   " BRIGHT_CYAN "Language:" WHITE "     C Programming                             ║\n");
    printf("  ║                                                           ║\n");
    printf("  ║   " BRIGHT_YELLOW "Author:" WHITE "       Saicharitha Dathrika                     ║\n");
    printf("  ║                                                           ║\n");
    printf("  ║   " BRIGHT_GREEN "Features:" WHITE "                                              ║\n");
    printf("  ║     ✅ Colorful Text-based UI                            ║\n");
    printf("  ║     ✅ Names with spaces support                         ║\n");
    printf("  ║     ✅ History tracking (up to 50 records)               ║\n");
    printf("  ║     ✅ Auto-save to file                                 ║\n");
    printf("  ║     ✅ Sound effects                                     ║\n");
    printf("  ║     ✅ Export history feature                            ║\n");
    printf("  ║     ✅ Cross-platform (Windows/Mac/Linux)                ║\n");
    printf("  ║     ✅ Support for long names (100 chars)                ║\n");
    printf("  ║                                                           ║\n");
    printf(BRIGHT_MAGENTA "  ╚═══════════════════════════════════════════════════════════╝\n" RESET);
}

void displayLoadingAnimation() {
    const char *frames[] = {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"};
    printf(BRIGHT_YELLOW "\n  ");
    for(int i = 0; i < 15; i++) {
        printf("\r  %s Calculating your destiny...", frames[i % 10]);
        fflush(stdout);
        SLEEP_MS(100);
    }
    printf("\r  ✨ Calculating your destiny... Done!   \n" RESET);
    SLEEP_MS(300);
}

void displayResult(char result, char *name1, char *name2) {
    printf(BRIGHT_CYAN "\n  ══════════════════════════════════════════════════════════\n" RESET);
    printf(BRIGHT_YELLOW BOLD "                        🎯 RESULT 🎯\n" RESET);
    printf(BRIGHT_CYAN "  ══════════════════════════════════════════════════════════\n\n" RESET);
    
    printf(WHITE "         %s" BRIGHT_MAGENTA " 💕 " WHITE "%s\n\n" RESET, name1, name2);
    
    switch(result) {
        case 'F':
            printf(BRIGHT_GREEN BOLD);
            printf("  ┌─────────────────────────────────────────────────────────┐\n");
            printf("  │                                                         │\n");
            printf("  │        👫  F R I E N D S  👫                             │\n");
            printf("  │                                                         │\n");
            printf("  │      You two make amazing friends!                      │\n");
            printf("  │      Cherish this beautiful friendship! 🌟              │\n");
            printf("  │                                                         │\n");
            printf("  └─────────────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'L':
            printf(BRIGHT_MAGENTA BOLD);
            printf("  ┌─────────────────────────────────────────────────────────┐\n");
            printf("  │                                                         │\n");
            printf("  │        💕  L O V E  💕                                  │\n");
            printf("  │                                                         │\n");
            printf("  │      There's LOVE in the air!                           │\n");
            printf("  │      You two are meant to be together! 💖               │\n");
            printf("  │                                                         │\n");
            printf("  └─────────────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'A':
            printf(BRIGHT_CYAN BOLD);
            printf("  ┌─────────────────────────────────────────────────────────┐\n");
            printf("  │                                                         │\n");
            printf("  │        💖  A F F E C T I O N  💖                        │\n");
            printf("  │                                                         │\n");
            printf("  │      Deep affection connects you both!                  │\n");
            printf("  │      There's a special bond between you! 🌹             │\n");
            printf("  │                                                         │\n");
            printf("  └─────────────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'M':
            printf(BRIGHT_YELLOW BOLD);
            printf("  ┌─────────────────────────────────────────────────────────┐\n");
            printf("  │                                                         │\n");
            printf("  │        💒  M A R R I A G E  💒                          │\n");
            printf("  │                                                         │\n");
            printf("  │      Wedding bells are ringing!                         │\n");
            printf("  │      You two are destined to be together! 💍            │\n");
            printf("  │                                                         │\n");
            printf("  └─────────────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'E':
            printf(BRIGHT_RED BOLD);
            printf("  ┌─────────────────────────────────────────────────────────┐\n");
            printf("  │                                                         │\n");
            printf("  │        😠  E N E M I E S  😠                            │\n");
            printf("  │                                                         │\n");
            printf("  │      Oops! Not a great match!                           │\n");
            printf("  │      Maybe try to understand each other? 🤔             │\n");
            printf("  │                                                         │\n");
            printf("  └─────────────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
            
        case 'S':
            printf(BRIGHT_BLUE BOLD);
            printf("  ┌─────────────────────────────────────────────────────────┐\n");
            printf("  │                                                         │\n");
            printf("  │        👨‍👩‍👧‍👦  S I B L I N G S  👨‍👩‍👧‍👦                          │\n");
            printf("  │                                                         │\n");
            printf("  │      You share a sibling-like bond!                     │\n");
            printf("  │      Family love is forever! 👪                         │\n");
            printf("  │                                                         │\n");
            printf("  └─────────────────────────────────────────────────────────┘\n");
            printf(RESET);
            break;
    }
    printf("\n");
}

void displayHistory() {
    printf(BRIGHT_YELLOW BOLD "\n");
    printf("  ╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("  ║                        📜 FLAMES HISTORY                              ║\n");
    printf("  ╠═══════════════════════════════════════════════════════════════════════╣\n" RESET);
    
    if(historyCount == 0) {
        printf(WHITE "  ║                                                                       ║\n");
        printf("  ║   " DIM "No history yet! Play FLAMES to create some memories! 💕" WHITE "           ║\n");
        printf("  ║                                                                       ║\n");
    } else {
        printf(WHITE "  ║  " UNDERLINE "%-3s  %-20s  %-20s  %-12s" RESET WHITE "       ║\n", "No.", "Name 1", "Name 2", "Result");
        printf("  ║─────────────────────────────────────────────────────────────────────║\n");
        
        int start = (historyCount > 10) ? historyCount - 10 : 0;
        for(int i = start; i < historyCount; i++) {
            printf("  ║  " BRIGHT_CYAN "%-3d" WHITE "  %-20.20s  %-20.20s  ", 
                   i + 1, history[i].name1, history[i].name2);
            
            // Color code the result
            switch(history[i].result) {
                case 'F': printf(BRIGHT_GREEN); break;
                case 'L': printf(BRIGHT_MAGENTA); break;
                case 'A': printf(BRIGHT_CYAN); break;
                case 'M': printf(BRIGHT_YELLOW); break;
                case 'E': printf(BRIGHT_RED); break;
                case 'S': printf(BRIGHT_BLUE); break;
            }
            printf("%-12s" RESET WHITE "       ║\n", history[i].resultText);
        }
        
        if(historyCount > 10) {
            printf("  ║                                                                       ║\n");
            printf("  ║   " DIM "(Showing last 10 of %d records. Export to see all.)" RESET WHITE "              ║\n", historyCount);
        }
    }
    
    printf(BRIGHT_YELLOW "  ╚═══════════════════════════════════════════════════════════════════════╝\n" RESET);
}

// ============================================
// FLAMES Game Logic
// ============================================

void playFlames() {
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];
    char cleanName1[MAX_NAME_LENGTH], cleanName2[MAX_NAME_LENGTH];
    char playAgain;
    
    do {
        system(CLEAR);
        
        printf(BRIGHT_RED BOLD "\n");
        printf("  🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n");
        printf(RESET);
        printf(BRIGHT_YELLOW BOLD "                 💕 FLAMES CALCULATOR 💕\n" RESET);
        printf(BRIGHT_RED BOLD "  🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n\n" RESET);
        
        printf(BRIGHT_CYAN "  ┌─────────────────────────────────────────────────────────┐\n");
        printf("  │     Enter the names to check! (spaces allowed)          │\n");
        printf("  └─────────────────────────────────────────────────────────┘\n\n" RESET);
        
        // Get first name (with spaces)
        printf(BRIGHT_GREEN "  👤 Enter First Name:  " WHITE);
        fgets(name1, MAX_NAME_LENGTH, stdin);
        name1[strcspn(name1, "\n")] = 0;  // Remove newline
        
        // Get second name (with spaces)
        printf(BRIGHT_MAGENTA "  👤 Enter Second Name: " WHITE);
        fgets(name2, MAX_NAME_LENGTH, stdin);
        name2[strcspn(name2, "\n")] = 0;  // Remove newline
        
        // Validate input
        if(strlen(name1) == 0 || strlen(name2) == 0) {
            printf(RED "\n  ❌ Names cannot be empty! Please try again.\n" RESET);
            if(soundEnabled) BEEP();
            pressEnterToContinue();
            continue;
        }
        
        // Store original names for display
        char displayName1[MAX_NAME_LENGTH], displayName2[MAX_NAME_LENGTH];
        strcpy(displayName1, name1);
        strcpy(displayName2, name2);
        
        // Remove non-alphabetic characters and convert to lowercase
        removeNonAlpha(cleanName1, name1);
        removeNonAlpha(cleanName2, name2);
        toLowercase(cleanName1);
        toLowercase(cleanName2);
        
        if(strlen(cleanName1) == 0 || strlen(cleanName2) == 0) {
            printf(RED "\n  ❌ Names must contain at least one letter!\n" RESET);
            if(soundEnabled) BEEP();
            pressEnterToContinue();
            continue;
        }
        
        // Loading animation
        displayLoadingAnimation();
        
        // Calculate FLAMES result
        char result = calculateFlames(cleanName1, cleanName2);
        
        // Play sound
        if(soundEnabled) playSound(result);
        
        // Display result
        displayResult(result, displayName1, displayName2);
        
        // Save to history
        if(historyCount < MAX_HISTORY) {
            strncpy(history[historyCount].name1, displayName1, MAX_NAME_LENGTH - 1);
            strncpy(history[historyCount].name2, displayName2, MAX_NAME_LENGTH - 1);
            history[historyCount].result = result;
            strcpy(history[historyCount].resultText, getResultText(result));
            getCurrentTimestamp(history[historyCount].timestamp);
            
            // Save to file
            saveResultToFile(&history[historyCount]);
            historyCount++;
            
            printf(DIM "  💾 Result saved to history!\n" RESET);
        } else {
            printf(DIM "  ⚠️  History is full! Export and clear to save new records.\n" RESET);
        }
        
        // Play again?
        printf(BRIGHT_YELLOW "\n  ┌─────────────────────────────────────────────────────────┐\n");
        printf("  │       Want to try another pair? (Y/N): " RESET);
        scanf(" %c", &playAgain);
        clearInputBuffer();
        printf(BRIGHT_YELLOW "  └─────────────────────────────────────────────────────────┘\n" RESET);
        
    } while(playAgain == 'Y' || playAgain == 'y');
}

char calculateFlames(const char *name1, const char *name2) {
    int freq1[26] = {0}, freq2[26] = {0};
    int i, sum = 0;
    
    // Count letter frequencies for name1
    for(i = 0; name1[i]; i++) {
        if(name1[i] >= 'a' && name1[i] <= 'z') {
            freq1[name1[i] - 'a']++;
        }
    }
    
    // Count letter frequencies for name2
    for(i = 0; name2[i]; i++) {
        if(name2[i] >= 'a' && name2[i] <= 'z') {
            freq2[name2[i] - 'a']++;
        }
    }
    
    // Calculate absolute difference
    for(i = 0; i < 26; i++) {
        int diff = freq1[i] - freq2[i];
        if(diff < 0) diff = -diff;
        sum += diff;
    }
    
    // FLAMES calculation
    if(sum == 0) {
        return 'M';  // Same name = Marriage
    }
    
    // FLAMES elimination algorithm
    char flames[] = "FLAMES";
    int flamesLen = 6;
    int pos = 0;
    
    while(flamesLen > 1) {
        pos = (pos + sum - 1) % flamesLen;
        
        // Remove character at pos
        for(i = pos; i < flamesLen - 1; i++) {
            flames[i] = flames[i + 1];
        }
        flamesLen--;
        flames[flamesLen] = '\0';
        
        if(pos == flamesLen) {
            pos = 0;
        }
    }
    
    return flames[0];
}

const char* getResultText(char result) {
    switch(result) {
        case 'F': return "Friends";
        case 'L': return "Love";
        case 'A': return "Affection";
        case 'M': return "Marriage";
        case 'E': return "Enemies";
        case 'S': return "Siblings";
        default: return "Unknown";
    }
}

void playSound(char result) {
    switch(result) {
        case 'L':
        case 'M':
            BEEP_LOVE();
            break;
        default:
            BEEP_SUCCESS();
            break;
    }
}

// ============================================
// File Operations
// ============================================

void saveResultToFile(FlamesRecord *record) {
    FILE *file = fopen(HISTORY_FILE, "a");
    if(file != NULL) {
        fprintf(file, "%s|%s|%c|%s|%s\n", 
                record->name1, record->name2, 
                record->result, record->resultText, 
                record->timestamp);
        fclose(file);
    }
}

void loadHistoryFromFile() {
    FILE *file = fopen(HISTORY_FILE, "r");
    if(file == NULL) return;
    
    char line[512];
    historyCount = 0;
    
    while(fgets(line, sizeof(line), file) && historyCount < MAX_HISTORY) {
        line[strcspn(line, "\n")] = 0;
        
        char *token = strtok(line, "|");
        if(token) strncpy(history[historyCount].name1, token, MAX_NAME_LENGTH - 1);
        
        token = strtok(NULL, "|");
        if(token) strncpy(history[historyCount].name2, token, MAX_NAME_LENGTH - 1);
        
        token = strtok(NULL, "|");
        if(token) history[historyCount].result = token[0];
        
        token = strtok(NULL, "|");
        if(token) strncpy(history[historyCount].resultText, token, 19);
        
        token = strtok(NULL, "|");
        if(token) strncpy(history[historyCount].timestamp, token, 29);
        
        historyCount++;
    }
    
    fclose(file);
}

void clearHistory() {
    historyCount = 0;
    FILE *file = fopen(HISTORY_FILE, "w");
    if(file != NULL) {
        fclose(file);
    }
}

void exportHistory() {
    char filename[100];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    sprintf(filename, "flames_export_%04d%02d%02d_%02d%02d%02d.txt",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec);
    
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        printf(RED "\n  ❌ Failed to create export file!\n" RESET);
        return;
    }
    
    fprintf(file, "╔═══════════════════════════════════════════════════════════════════════╗\n");
    fprintf(file, "║                    FLAMES HISTORY EXPORT                              ║\n");
    fprintf(file, "╠═══════════════════════════════════════════════════════════════════════╣\n");
    fprintf(file, "║  Total Records: %-5d                                                 ║\n", historyCount);
    fprintf(file, "╚═══════════════════════════════════════════════════════════════════════╝\n\n");
    
    fprintf(file, "%-5s %-25s %-25s %-15s %s\n", "No.", "Name 1", "Name 2", "Result", "Date/Time");
    fprintf(file, "─────────────────────────────────────────────────────────────────────────────────\n");
    
    for(int i = 0; i < historyCount; i++) {
        fprintf(file, "%-5d %-25.25s %-25.25s %-15s %s\n",
                i + 1, history[i].name1, history[i].name2,
                history[i].resultText, history[i].timestamp);
    }
    
    fprintf(file, "\n─────────────────────────────────────────────────────────────────────────────────\n");
    fprintf(file, "Generated by FLAMES Ultimate Edition v3.0\n");
    fprintf(file, "Author: Saicharitha Dathrika\n");
    
    fclose(file);
    
    printf(GREEN "\n  ✅ History exported to: %s\n" RESET, filename);
}

void getCurrentTimestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec);
}

// ============================================
// Utility Functions
// ============================================

void toLowercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void removeNonAlpha(char *dest, const char *src) {
    int j = 0;
    for(int i = 0; src[i]; i++) {
        if(isalpha(src[i])) {
            dest[j++] = src[i];
        }
    }
    dest[j] = '\0';
}

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void pressEnterToContinue() {
    printf(BRIGHT_YELLOW "\n  Press ENTER to continue..." RESET);
    getchar();
}
