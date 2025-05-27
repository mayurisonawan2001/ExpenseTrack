class ExpenseManager {
private:
    vector<Expense> expenses;
    const string filename = "expenses.txt";

public:
    ExpenseManager() {
        loadFromFile();
    }

    void addExpense() {
        string date, category, desc;
        double amount;

        cout << "Enter date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter amount: ";
        cin >> amount;
        cin.ignore();
        cout << "Enter category: ";
        getline(cin, category);
        cout << "Enter description: ";
        getline(cin, desc);

        expenses.emplace_back(date, amount, category, desc);
        saveToFile();
        cout << "✅ Expense added!\n";
    }

    void viewAllExpenses() {
        cout << "\n📋 All Expenses:\n";
        for (const auto& e : expenses) {
            cout << e.date << " | ₹" << fixed << setprecision(2) << e.amount
                 << " | " << e.category << " | " << e.description << "\n";
        }
    }

    void viewSummaryByMonth() {
        map<string, double> monthlyTotal;
        for (const auto& e : expenses) {
            string month = e.date.substr(0, 7); // "YYYY-MM"
            monthlyTotal[month] += e.amount;
        }

        cout << "\n📆 Monthly Summary:\n";
        for (const auto& entry : monthlyTotal) {
            cout << entry.first << " : ₹" << fixed << setprecision(2) << entry.second << "\n";
        }
    }

    void viewSummaryByCategory() {
        map<string, double> categoryTotal;
        for (const auto& e : expenses) {
            categoryTotal[e.category] += e.amount;
        }

        cout << "\n📂 Category Summary:\n";
        for (const auto& entry : categoryTotal) {
            cout << entry.first << " : ₹" << fixed << setprecision(2) << entry.second << "\n";
        }
    }

    void saveToFile() {
        ofstream out(filename);
        for (const auto& e : expenses) {
            out << e.toString() << "\n";
        }
    }

    void loadFromFile() {
        ifstream in(filename);
        string line;
        while (getline(in, line)) {
            if (!line.empty()) {
                expenses.push_back(Expense::fromString(line));
            }
        }
    }
};
