#include <stdio.h>
#include<stdlib.h>
#include<string.h> 

#define FILE_NAME "disaster_database.txt"

// Disaster Structure
struct disaster {
    char name[50];
    char location[50];
    char date[50];
    char time[50];
    char type[50];
    int death;
    int scale;
};

typedef struct disaster disaster;
// Add Disaster Details
void addDisaster() { // Removed semicolon here
    FILE *fpt=fopen(FILE_NAME, "a");
    if(fpt==NULL) {
        printf("Error in opening file:(\n");
        return; // Added return statement
    }
    
    disaster d;
    printf("Enter the name of the disaster: ");
    scanf("%s", d.name);
    printf("Enter the affected Location: ");
    scanf("%s", d.location);
    printf("Enter the date of the disaster: ");
    scanf("%s", d.date);
    printf("Enter the time of the disaster: ");
    scanf("%s", d.time);
    printf("Enter the type of the disaster: ");
    scanf("%s", d.type);
    printf("Enter the number of deaths: ");
    scanf("%d", &d.death);
    printf("Enter the scale of the disaster: ");
    scanf("%d", &d.scale);

    fwrite(&d, sizeof(disaster), 1, fpt);
    fclose(fpt);

    printf("Disaster added successfully!\n");
}

// View the Disaster Details
void viewDisaster() {
    FILE *fpt = fopen(FILE_NAME, "r"); // Removed quotes around FILE_NAME
    if(fpt==NULL) {
        printf("Error in opening file!\n");
        return; // Added return statement
    }

    disaster d;
    printf("-----------------Disaster Details-----------------\n");
    printf("Name\tLocation\tDate\tTime\tType\tDeath\tScale\n");
    printf("-------------------------------------------------\n");
    while(fread(&d, sizeof(disaster), 1, fpt)) {
        printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", d.name, d.location, d.date, d.time, d.type, d.death, d.scale);
    }
    fclose(fpt);
}

// Showing disaster alerts
void showDisasterAlert() {
    FILE *fpt = fopen(FILE_NAME, "r");
    if(fpt==NULL) {
        printf("Error in opening file!\n");
        return; // Added return statement
    }

    disaster d;
    while(fread(&d, sizeof(disaster), 1, fpt)) {
        if(d.scale>5) {
            printf("Alert! Disaster with scale %d is detected in %s\n", d.scale, d.location);
        }
    }
    fclose(fpt);
}

// main function
int main() {
    int choice;
    while(1) {
        printf("1. Add Disaster\n");
        printf("2. View Disaster\n");
        printf("3. Show Disaster Alert\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addDisaster();
                break;
            case 2:
                viewDisaster();
                break;
            case 3:
                showDisasterAlert();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}