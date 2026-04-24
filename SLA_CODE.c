#include <stdio.h>
#include <string.h>
#define MAX 50

/* Structure  */
struct Zone {
    char name[30];
    int airQuality;
    int waterSupply;
    int greenCover;
    int transport;
    float score;
};

struct Zone zones[MAX];
int count = 0;

/* Functions */
void addZone();
void displayZones();
void searchZone();
void rankZones();
void cityReport();

int main() {
    int choice;

    do {
        printf("\n--- Multi-Zone Smart City Sustainability Analyzer (SDG 11) ---\n");
        printf("1. Add city zone details\n");
        printf("2. Display all zones\n");
        printf("3. Search zone by name\n");
        printf("4. Rank zones (sorting)\n");
        printf("5. Generate city report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addZone(); break;
            case 2: displayZones(); break;
            case 3: searchZone(); break;
            case 4: rankZones(); break;
            case 5: cityReport(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}

/* FOor Adding zone details */
void addZone() {
    if(count >= MAX) {
        printf("Zone limit reached!\n");
        return;
    }

    printf("Enter zone name: ");
    scanf("%s", zones[count].name);

    printf("Enter Air Quality score (0-100): ");
    scanf("%d", &zones[count].airQuality);

    printf("Enter Water Supply score (0-100): ");
    scanf("%d", &zones[count].waterSupply);

    printf("Enter Green Cover score (0-100): ");
    scanf("%d", &zones[count].greenCover);

    printf("Enter Transport Facility score (0-100): ");
    scanf("%d", &zones[count].transport);

    /* calculate sustainability score */
    zones[count].score =
        (zones[count].airQuality +
         zones[count].waterSupply +
         zones[count].greenCover +
         zones[count].transport) / 4.0;

    count++;
    printf("Zone added successfully!\n");
}

/* Display all zones */
void displayZones() {
    int i;

    if(count == 0) {
        printf("No zones available.\n");
        return;
    }

   printf("%-10s %-5s %-6s %-6s %-9s %s\n",
       "Zone","Air","Water","Green","Transport","Score");
   for(i = 0; i < count; i++) {
        printf("%-10s %-5d %-6d %-6d %-9d %.2f\n",
       zones[i].name,
       zones[i].airQuality,
       zones[i].waterSupply,
       zones[i].greenCover,
       zones[i].transport,
       zones[i].score);
    }
}

/* Search zone by name */
void searchZone() {
    char search[30];
    int i, found = 0;

    if(count == 0) {
        printf("No data available.\n");
        return;
    }

    printf("Enter zone name to search: ");
    scanf("%s", search);

    for(i = 0; i < count; i++) {
        if(strcmp(zones[i].name, search) == 0) {
            printf("\nZone Found!\n");
            printf("Name: %s\n", zones[i].name);
            printf("Air Quality: %d\n", zones[i].airQuality);
            printf("Water Supply: %d\n", zones[i].waterSupply);
            printf("Green Cover: %d\n", zones[i].greenCover);
            printf("Transport: %d\n", zones[i].transport);
            printf("Sustainability Score: %.2f\n", zones[i].score);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Zone not found!\n");
}

/* Ranking of zones by sustainability score */
void rankZones() {
    int i, j;
    struct Zone temp;

    if(count == 0) {
        printf("No data available.\n");
        return;
    }

    for(i = 0; i < count - 1; i++) {
        for(j = i + 1; j < count; j++) {
            if(zones[i].score < zones[j].score) {
                temp = zones[i];
                zones[i] = zones[j];
                zones[j] = temp;
            }
        }
    }

    printf("\nZones ranked successfully (Highest Score First).\n");
    displayZones();
}

/*For Generating city sustainability report */
void cityReport() {

    int i;
    float avgScore = 0;

    if(count == 0) {
        printf("No zones available.\n");
        return;
    }

    for(i = 0; i < count; i++) {
        avgScore += zones[i].score;
    }
    avgScore /= count;

    printf("\n--- City Sustainability Report ---\n");
    printf("Total Zones: %d\n", count);
    printf("Average City Sustainability Score: %.2f\n", avgScore);

    if(avgScore >= 75)
        printf("City Status: Highly Sustainable\n");
    else if(avgScore >= 50)
        printf("City Status: Moderately Sustainable\n");
    else
        printf("City Status: Needs Improvement\n");
}
