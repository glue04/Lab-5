#include <stdio.h>
#include <stdlib.h>

int main() {

    int score;
    const char *scoreNames[] = {
        "TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"
    };
    
    const int scoreValues[] = {
        8, 7, 6, 3, 2
    };

    const int numScores = sizeof(scoreValues) / sizeof(scoreValues[0]);

    printf("Enter 0 or 1 to STOP\n");

    while(1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if(score <= 1) {
            break;
        }

        printf("possible combinations of scoring plays:\n");

        for (int a = 0; a * scoreValues[0] <= score; a++) {
            for (int b = 0; b * scoreValues[1] <= score; b++) {
                for (int c = 0; c * scoreValues[2] <= score; c++) {
                    for (int d = 0; d * scoreValues[3] <= score; d++) {
                        for (int e = 0; e * scoreValues[4] <= score; e++) {
                            if (a * scoreValues[0] + b * scoreValues[1] + c * scoreValues[2] + d * scoreValues[3] + e * scoreValues[4] == score) {
                                printf("%d %s, %d %s, %d %s, %d %s, %d %s\n", a, scoreNames[0], b, scoreNames[1], c, scoreNames[2], d, scoreNames[3], e, scoreNames[4]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
	
