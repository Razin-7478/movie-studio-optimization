/*
 * Movie Studio Optimization System
 * --------------------------------
 * Stage 1: Scene Scheduling using Activity Selection (Greedy)
 * Stage 2: Equipment Allocation using 0/1 Knapsack (Dynamic Programming)
 *
 * Author : Mohammad Razin Masud
 * Course : Algorithm Lab (CSE 2202)
 * University of Liberal Arts Bangladesh
 */

#include <stdio.h>

/* ===================== Activity Selection ===================== */

struct Scene {
    int id;          /* auto-generated ID */
    int start, end;
};

/* Simple bubble sort by ending time (ascending) */
void sortScenes(struct Scene s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].end > s[j].end) {
                struct Scene temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

/* ===================== Knapsack Helper ===================== */

int max(int a, int b) {
    return (a > b) ? a : b;
}

/* ===================== Main Program ===================== */

int main(void) {
    printf("===============================================================\n");
    printf("       MOVIE STUDIO OPTIMIZATION SYSTEM (C PROGRAM)\n");
    printf("===============================================================\n\n");

    /* ----------------- Stage 1: Activity Selection ----------------- */
    int n;
    printf("STAGE 1: SCENE SCHEDULING (Activity Selection)\n");
    printf("---------------------------------------------------------------\n");
    printf("Enter number of scenes to schedule: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of scenes.\n");
        return 1;
    }

    struct Scene s[n];

    printf("\nPlease enter ONLY start and end times.\n");
    printf("Format: StartTime EndTime\n");
    printf("Example: 1 4\n\n");

    for (int i = 0; i < n; i++) {
        s[i].id = i + 1;   /* auto-generate ID */
        printf("Enter Start and End time for Scene %d: ", i + 1);
        if (scanf("%d %d", &s[i].start, &s[i].end) != 2) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    sortScenes(s, n);

    printf("\n\n==================== SELECTED SCENES ====================\n");
    int count = 1;
    printf("Scene %d (Start: %d, End: %d)\n", s[0].id, s[0].start, s[0].end);

    int lastEnd = s[0].end;

    for (int i = 1; i < n; i++) {
        if (s[i].start >= lastEnd) {
            printf("Scene %d (Start: %d, End: %d)\n", s[i].id, s[i].start, s[i].end);
            lastEnd = s[i].end;
            count++;
        }
    }

    printf("---------------------------------------------------------------\n");
    printf("Total Non-Overlapping Scenes Selected: %d\n", count);
    printf("===============================================================\n\n");

    /* ----------------- Stage 2: 0/1 Knapsack ----------------- */
    int items, capacity;

    printf("STAGE 2: EQUIPMENT OPTIMIZATION (0/1 Knapsack)\n");
    printf("---------------------------------------------------------------\n");
    printf("Enter number of equipment items available: ");
    if (scanf("%d", &items) != 1 || items <= 0) {
        printf("Invalid number of items.\n");
        return 1;
    }

    int weight[items], value[items];

    printf("\nEnter equipment details in this format:\n");
    printf("Weight Value\n");
    printf("Example: 4 10\n\n");

    for (int i = 0; i < items; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        if (scanf("%d %d", &weight[i], &value[i]) != 2) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("\nEnter equipment budget (maximum allowed weight): ");
    if (scanf("%d", &capacity) != 1 || capacity < 0) {
        printf("Invalid capacity.\n");
        return 1;
    }

    /* DP table: dp[i][w] = max value using first i items with capacity w */
    int dp[items + 1][capacity + 1];

    for (int i = 0; i <= items; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\n\n================ SELECTED EQUIPMENT ITEMS ================\n");
    printf("Maximum Production Value Achieved: %d\n", dp[items][capacity]);
    printf("Items included in the optimal solution:\n");

    int w = capacity;
    for (int i = items; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d  (Weight = %d, Value = %d)\n",
                   i, weight[i - 1], value[i - 1]);
            w -= weight[i - 1];
        }
    }

    printf("---------------------------------------------------------------\n");
    printf("Optimization Completed Successfully!\n");
    printf("===============================================================\n");

    return 0;
}
