#include "SetHT.h"
#include <iostream>

void addTicket(SetHT *set) {
    int ticket;
    bool valid = true;
    while(valid) {
        valid = false;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter ticket number: " ;
        std::cin >> ticket;
        if (std::cin.fail()) {
            std::cout << "Not a valid ticket number!" << '\n';
            valid = true;
        }
    }
    if(set->add(ticket))
        std::cout << "Ticket added successfully!" << '\n';
    else std::cout << "Ticket already in the list!" << '\n';
}

void deleteTicket(SetHT *set) {
    int ticket;
    bool valid = true;
    while(valid) {
        valid = false;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter ticket number: " ;
        std::cin >> ticket;
        if (std::cin.fail()) {
            std::cout << "Not a valid ticket number!" << '\n';
            valid = true;
        }
    }
    if(set->search(ticket)) {
        set->remove(ticket);
        std::cout << "Ticket deleted successfully!" << '\n';
    } else
        std::cout << "Ticket not in the list!" << '\n';
}

void validateTicket(SetHT *set) {
    int ticket;
    bool valid = true;
    while(valid) {
        valid = false;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter ticket number: " ;
        std::cin >> ticket;
        if (std::cin.fail()) {
            std::cout << "Not a valid ticket number!" << '\n';
            valid = true;
        }
    }
    if(set->search(ticket)) {
        std::cout << "Valid ticket!" << '\n';
    } else
        std::cout << "Invalid ticket!" << '\n';
}

void printMenu() {
    std::cout << "1. Add new ticket" << '\n';
    std::cout << "2. Delete a ticket" << '\n';
    std::cout << "3. Validate ticket" << '\n';
    std::cout << "0. Exit" << '\n';
}

int main() {
    auto set = new SetHT();
    int o = -1;
    while (o != 0 ) {
        printMenu();
        std::cin >> o;
        switch (o) {
            case 0:
                std::cout << "Bye!";
                break;
            case 1:
                addTicket(set);
                break;
            case 2:
                deleteTicket(set);
                break;
            case 3:
                validateTicket(set);
                break;
            default:
                std::cout << "Not a valid option!" << '\n';
        }
    }
    return 0;
}
