# Railway Reservation System

A console-based Railway Reservation System developed in C that allows users to manage train bookings, check seat availability, search reservations using PNR numbers, and cancel tickets. The system uses file handling to maintain booking records even after the program is closed.

## Features

- **View Available Trains:** Displays train numbers, train names, ticket fares, and available seats.
- **Book Tickets:** Allows passengers to select trains, enter passenger details, and reserve seats.
- **PNR Generation:** Automatically generates a unique PNR number for every booking.
- **Search Reservations:** Retrieves ticket details using the PNR number.
- **Cancel Tickets:** Cancels existing reservations and restores the corresponding seat availability.
- **View All Bookings:** Displays all currently stored reservations.
- **Persistent Storage:** Uses binary file handling to save and retrieve booking records.

## Technologies Used

- **Programming Language:** C
- **Concepts:** Structures, Arrays, Functions, Pointers, Loops, Conditional Statements, String Handling and File Handling.
- **Storage:** Binary File Handling (`fread()` and `fwrite()`).
- **Compiler:** GCC

## How It Works

1. The program loads previously saved booking records from `railway.dat` when it starts.
2. Users can select an operation from the main menu.
3. During booking, the system validates the train number, seat availability, and passenger details.
4. A unique PNR is generated, and the total fare is calculated according to the number of seats.
5. Booking information is stored in a binary file.
6. Users can subsequently search, view, or cancel their reservations.
7. When a ticket is cancelled, the corresponding seats are restored.

## Sample Display

### 1. Main Menu

```text
====== RAILWAY RESERVATION SYSTEM ======

1. View Available Trains
2. Book Ticket
3. Search Ticket (PNR)
4. Cancel Ticket
5. View All Bookings
6. Exit

Enter your choice:
```

### 2. Available Trains

```text
------ AVAILABLE TRAINS ------

Train Number: 101
Train Name: Rajdhani Express
Fare per seat: Rs. 1200.00
Available Seats: 50

Train Number: 102
Train Name: Shatabdi Express
Fare per seat: Rs. 900.00
Available Seats: 40

Train Number: 103
Train Name: Vande Bharat Express
Fare per seat: Rs. 1500.00
Available Seats: 60
```

### 3. Successful Ticket Booking

```text
===== TICKET BOOKED SUCCESSFULLY =====

PNR Number: 100001
Passenger: Rahul Sharma
Train: Rajdhani Express
Seats: 2
Total Fare: Rs. 2400.00
```

### 4. Ticket Cancellation

```text
Enter PNR Number to cancel: 100001

Ticket cancelled successfully!
```

## Project Structure

```text
Railway-Reservation-System/
│
├── railway.c
├── railway.dat
└── README.md
```


## How to Run

1. Clone or download this repository.
2. Open the project folder in VS Code.
3. Open the terminal.
4. Compile the program:

```bash
gcc railway.c -o railway
```

5. Execute the program:

```bash
./railway
```

For Windows:

```bash
railway.exe
```

## Concepts Demonstrated

This project demonstrates the practical application of C programming concepts, particularly structures for organizing passenger information, arrays for managing multiple reservations, functions for modular programming, and binary file handling for persistent data storage.

## Future Scope

- Integration of additional trains and routes.
- Date-based train scheduling.
- Separate passenger and administrator access.
- Improved input validation and booking management.
- Database integration for more scalable storage.

---

**Project:** Railway Reservation System  
**Language:** C  
**Type:** Console-Based Application