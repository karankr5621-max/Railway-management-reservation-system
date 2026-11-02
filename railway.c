#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200
#define FILE_NAME "railway.dat"

struct Ticket {
    int pnr;
    char name[50];
    int age;
    char train[50];
    int trainNo;
    int seats;
    float fare;
};

struct Ticket tickets[MAX];
int count = 0;

int trains[3] = {101, 102, 103};
char trainNames[3][50] = {
    "Rajdhani Express",
    "Shatabdi Express",
    "Vande Bharat Express"
};

float fares[3] = {1200, 900, 1500};
int availableSeats[3] = {50, 40, 60};

// Load saved bookings
void loadData() {
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp != NULL) {
        count = fread(tickets, sizeof(struct Ticket),
                      MAX, fp);
        fclose(fp);
    }
}

// Save bookings
void saveData() {
    FILE *fp = fopen(FILE_NAME, "wb");

    if (fp == NULL) {
        printf("Error saving data!\n");
        return;
    }

    fwrite(tickets, sizeof(struct Ticket), count, fp);
    fclose(fp);
}

// Display available trains
void displayTrains() {
    printf("\n------ AVAILABLE TRAINS ------\n");

    for (int i = 0; i < 3; i++) {
        printf("\nTrain Number: %d", trains[i]);
        printf("\nTrain Name: %s", trainNames[i]);
        printf("\nFare per seat: Rs. %.2f", fares[i]);
        printf("\nAvailable Seats: %d\n",
               availableSeats[i]);
    }
}

// Book ticket
void bookTicket() {
    int choice, seats;

    if (count >= MAX) {
        printf("\nBooking limit reached!\n");
        return;
    }

    displayTrains();

    printf("\nSelect Train Number: ");
    scanf("%d", &choice);

    int index = -1;

    for (int i = 0; i < 3; i++) {
        if (trains[i] == choice) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nInvalid train number!\n");
        return;
    }

    printf("Enter number of seats: ");
    scanf("%d", &seats);

    if (seats <= 0 || seats > availableSeats[index]) {
        printf("\nSeats not available!\n");
        return;
    }

    struct Ticket t;

    printf("Enter passenger name: ");
    scanf(" %49[^\n]", t.name);

    printf("Enter passenger age: ");
    scanf("%d", &t.age);

    if (t.age <= 0 || t.age > 120) {
        printf("\nInvalid age!\n");
        return;
    }

    t.pnr = 100001;

    for (int i = 0; i < count; i++) {
        if (tickets[i].pnr >= t.pnr) {
            t.pnr = tickets[i].pnr + 1;
        }
    }

    t.trainNo = trains[index];
    strcpy(t.train, trainNames[index]);
    t.seats = seats;
    t.fare = fares[index] * seats;

    tickets[count] = t;
    count++;

    availableSeats[index] -= seats;

    saveData();

    printf("\n===== TICKET BOOKED SUCCESSFULLY =====\n");
    printf("PNR Number: %d\n", t.pnr);
    printf("Passenger: %s\n", t.name);
    printf("Train: %s\n", t.train);
    printf("Seats: %d\n", t.seats);
    printf("Total Fare: Rs. %.2f\n", t.fare);
}

// Search ticket
void searchTicket() {
    int pnr, found = 0;

    printf("\nEnter PNR Number: ");
    scanf("%d", &pnr);

    for (int i = 0; i < count; i++) {
        if (tickets[i].pnr == pnr) {
            printf("\n===== TICKET DETAILS =====\n");
            printf("PNR: %d\n", tickets[i].pnr);
            printf("Name: %s\n", tickets[i].name);
            printf("Age: %d\n", tickets[i].age);
            printf("Train: %s\n", tickets[i].train);
            printf("Train Number: %d\n", tickets[i].trainNo);
            printf("Seats: %d\n", tickets[i].seats);
            printf("Fare: Rs. %.2f\n", tickets[i].fare);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nTicket not found!\n");
    }
}

// Cancel ticket
void cancelTicket() {
    int pnr, found = 0;

    printf("\nEnter PNR Number to cancel: ");
    scanf("%d", &pnr);

    for (int i = 0; i < count; i++) {
        if (tickets[i].pnr == pnr) {

            for (int j = 0; j < 3; j++) {
                if (tickets[i].trainNo == trains[j]) {
                    availableSeats[j] += tickets[i].seats;
                    break;
                }
            }

            for (int j = i; j < count - 1; j++) {
                tickets[j] = tickets[j + 1];
            }

            count--;
            saveData();

            printf("\nTicket cancelled successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nPNR not found!\n");
    }
}

// Display all bookings
void viewBookings() {
    if (count == 0) {
        printf("\nNo bookings available!\n");
        return;
    }

    printf("\n====== ALL BOOKINGS ======\n");

    for (int i = 0; i < count; i++) {
        printf("\nPNR: %d", tickets[i].pnr);
        printf("\nPassenger: %s", tickets[i].name);
        printf("\nTrain: %s", tickets[i].train);
        printf("\nSeats: %d", tickets[i].seats);
        printf("\nFare: Rs. %.2f\n", tickets[i].fare);
    }
}

// Main function
int main() {
    int choice;

    loadData();

    do {
        printf("\n\n====== RAILWAY RESERVATION SYSTEM ======\n");
        printf("1. View Available Trains\n");
        printf("2. Book Ticket\n");
        printf("3. Search Ticket (PNR)\n");
        printf("4. Cancel Ticket\n");
        printf("5. View All Bookings\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1:
                displayTrains();
                break;

            case 2:
                bookTicket();
                break;

            case 3:
                searchTicket();
                break;

            case 4:
                cancelTicket();
                break;

            case 5:
                viewBookings();
                break;

            case 6:
                printf("\nThank you for using Railway Reservation System!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}