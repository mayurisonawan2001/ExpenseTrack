#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
    ExpenseManager manager;
    int choice;

    do {
        cout << "\n====== Personal Expense Tracker ======\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. View Summary by Month\n";
        cout << "4. View Summary by Category\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addExpense(); break;
            case 2: manager.viewAllExpenses(); break;
            case 3: manager.viewSummaryByMonth(); break;
            case 4: manager.viewSummaryByCategory(); break;
            case 0: cout << "👋 Exiting. Bye!\n"; break;
            default: cout << "❌ Invalid choice.\n"; break;
        }

    } while (choice != 0);

    return 0;
}
