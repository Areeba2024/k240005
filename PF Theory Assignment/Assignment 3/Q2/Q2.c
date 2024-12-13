#include <stdio.h>
#include <string.h>

struct Player {
    char playerName[50];
    int ballScores[12];
    int totalScore;
};

int validateScore(int score) {
    return (score >= 0 && score <= 6);
}

void playGame(struct Player* player) {
    printf("Enter name for %s: ", player->playerName);
    fgets(player->playerName, 50, stdin);
    strtok(player->playerName, "\n");

    player->totalScore = 0;
    for (int i = 0; i < 12; i++) {
        int score;
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &score);

        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            player->ballScores[i] = 0;
            printf("Invalid score. Ball marked, but no score added.\n");
        }
    }
}

void findWinner(struct Player player1, struct Player player2) {
    printf("\nFinal Scores:\n");
    printf("%s: %d\n", player1.playerName, player1.totalScore);
    printf("%s: %d\n", player2.playerName, player2.totalScore);

    if (player1.totalScore > player2.totalScore) {
        printf("Winner: %s\n", player1.playerName);
    } else if (player2.totalScore > player1.totalScore) {
        printf("Winner: %s\n", player2.playerName);
    } else {
        printf("It's a tie!\n");
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\nMatch Scoreboard:\n");

    printf("%s:\n", player1.playerName);
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: %d\n", i + 1, player1.ballScores[i]);
    }
    printf("Total Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n\n", player1.totalScore / (float)12);

    printf("%s:\n", player2.playerName);
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: %d\n", i + 1, player2.ballScores[i]);
    }
    printf("Total Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", player2.totalScore / (float)12);
}

int main() {
    struct Player player1 = {"Player 1", {0}, 0};
    struct Player player2 = {"Player 2", {0}, 0};

    printf("\nPlayer 1's Turn:\n");
    getchar();
    playGame(&player1);

    printf("\nPlayer 2's Turn:\n");
    getchar();
    playGame(&player2);

    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}
