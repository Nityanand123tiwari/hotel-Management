#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Booking {
    int roomNumber;
    string guestName;
    string checkInDate;
    string checkOutDate;
};

vector<Booking> bookings;

bool isRoomAvailable(int roomNumber) {
    for (auto &b : bookings) {
        if (b.roomNumber == roomNumber) {
            return false; // Room is already booked
        }
    }
    return true;
}

void addBooking() {
    Booking b;
    cout << "Enter Room Number: ";
    cin >> b.roomNumber;
    cin.ignore(); // Ignore newline after integer input

    if (!isRoomAvailable(b.roomNumber)) {
        cout << "Room is already booked!\n";
        return;
    }

    cout << "Enter Guest Name: ";
    getline(cin, b.guestName);

    cout << "Enter Check-in Date (YYYY-MM-DD): ";
    getline(cin, b.checkInDate);

    cout << "Enter Check-out Date (YYYY-MM-DD): ";
    getline(cin, b.checkOutDate);

    bookings.push_back(b);
    cout << "Booking successful!\n";
}

void showBookings() {
    if (bookings.empty()) {
        cout << "No bookings found.\n";
        return;
    }

    for (const auto &b : bookings) {
        cout << "Room " << b.roomNumber << ": " << b.guestName
             << " from " << b.checkInDate << " to " << b.checkOutDate << endl;
    }
}

void menu() {
    int choice;
    do {
        cout << "\n--- Hotel Management System ---\n";
        cout << "1. Book a Room\n";
        cout << "2. Show All Bookings\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear buffer

        switch (choice) {
            case 1:
                addBooking();
                break;
            case 2:
                showBookings();
                break;
            case 3:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

int main() {
    menu();
    return 0;
}
