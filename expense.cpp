class Expense {
public:
    string date;        // format: YYYY-MM-DD
    double amount;
    string category;
    string description;

    Expense(string d, double a, string c, string desc)
        : date(d), amount(a), category(c), description(desc) {}

    string toString() const {
        stringstream ss;
        ss << date << "|" << fixed << setprecision(2) << amount << "|" << category << "|" << description;
        return ss.str();
    }

    static Expense fromString(const string& line) {
        stringstream ss(line);
        string date, amountStr, category, description;
        getline(ss, date, '|');
        getline(ss, amountStr, '|');
        getline(ss, category, '|');
        getline(ss, description, '|');
        return Expense(date, stod(amountStr), category, description);
    }
};
