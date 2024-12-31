#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <cctype>

using namespace std;

struct Expense {
    string category;
    double amount;
    double percentage;
};

string formatCurrency(double amount) {
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << amount;
    string str = ss.str();

    int pos = str.find('.');
    if (pos == string::npos) pos = str.length();

    for (int i = pos - 3; i > 0; i -= 3) {
        str.insert(i, ".");
    }
    return "Rp" + str;
}

bool isDuplicateCategory(const vector<Expense>& expenses, const string& category) {
    for (const auto& expense : expenses) {
        if (expense.category == category) {
            return true;
        }
    }
    return false;
}

template<typename T>
T getValidInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value >= 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
            cout << "Nilai tidak boleh negatif! Silakan coba lagi." << endl;
        } else {
            cout << "Input tidak valid! Masukkan angka yang benar." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void displayGraph(const vector<Expense>& expenses) {
    cout << "\n=== Grafik Pengeluaran ===" << endl;
    const int maxWidth = 50;

    for (const auto& expense : expenses) {
        cout << left << setw(15) << expense.category << ": ";
        int barLength = static_cast<int>(expense.percentage / 2);
        string bar(barLength, '*');
        cout << bar << " " << fixed << setprecision(1) << expense.percentage << "%" << endl;
    }
}

void saveToFile(const vector<Expense>& expenses, double income, double totalExpenses, 
                double balance, double expenseRatio) {
    ofstream file("Laporan_Keuangan.txt");
    if (!file.is_open()) {
        cout << "Error: Tidak dapat membuka file untuk penulisan" << endl;
        return;
    }

    file << fixed << setprecision(2);
    file << "=== Laporan Keuangan ===" << endl;
    file << left << setw(20) << "Kategori" 
         << right << setw(15) << "Pengeluaran (Rp)" 
         << right << setw(15) << "Persentase (%)" << endl;
    file << string(50, '-') << endl;

    for (const auto& expense : expenses) {
        file << left << setw(20) << expense.category 
             << right << setw(15) << expense.amount
             << right << setw(15) << expense.percentage << endl;
    }

    file << string(50, '-') << endl;
    file << "\nTotal Pengeluaran: " << formatCurrency(totalExpenses) << endl;
    file << "Total Pendapatan: " << formatCurrency(income) << endl;
    file << "Sisa Pendapatan: " << formatCurrency(balance) << endl;
    file << "\nAnalisis Keuangan:" << endl;
    file << "Rasio Pengeluaran: " << expenseRatio << "% dari pendapatan" << endl;

    if (balance > 0) {
        file << "Status: SURPLUS" << endl;
        file << "Rekomendasi: Pertimbangkan untuk menabung " << formatCurrency(balance) 
             << " atau " << (balance/income)*100 << "% dari pendapatan Anda." << endl;
    } else if (balance == 0) {
        file << "Status: IMPAS" << endl;
        file << "Rekomendasi: Pertimbangkan untuk mengurangi pengeluaran dan membuat dana darurat." << endl;
    } else {
        file << "Status: DEFISIT" << endl;
        file << "Rekomendasi: Anda perlu memangkas pengeluaran sebesar " << formatCurrency(-balance) 
             << " atau mencari sumber pendapatan tambahan." << endl;
    }

    file.close();
    cout << "Laporan keuangan berhasil disimpan ke 'Laporan_Keuangan.txt'" << endl;
}

void sortExpenses(vector<Expense>& expenses) {
    sort(expenses.begin(), expenses.end(), 
         [](const Expense& a, const Expense& b) {
             return a.amount > b.amount;
         });
}

void showStatistics(const vector<Expense>& expenses) {
    auto maxExpense = max_element(expenses.begin(), expenses.end(),
        [](const Expense& a, const Expense& b) { return a.amount < b.amount; });

    cout << "Pengeluaran Tertinggi: " << maxExpense->category << " dengan jumlah " 
         << formatCurrency(maxExpense->amount) << endl;
}

int main() {
    bool continueProgram = true;

    while (continueProgram) {
        vector<Expense> expenses;
        double totalExpenses = 0;

        cout << "==== Simulasi Manajemen Keuangan Mahasiswa ====" << endl;

        double income = getValidInput<double>("Masukkan pendapatan bulanan Anda (Rp): ");

        int numExpenses = getValidInput<int>("Masukkan jumlah kategori pengeluaran: ");

        for (int i = 0; i < numExpenses; i++) {
            Expense expense;
            do {
                cout << "\nMasukkan kategori pengeluaran ke-" << (i+1) 
                     << " (contoh: Makanan, Transportasi, Dll): ";
                getline(cin, expense.category);

                if (expense.category.empty()) {
                    cout << "Kategori tidak boleh kosong! Silakan coba lagi." << endl;
                } else if (isDuplicateCategory(expenses, expense.category)) {
                    cout << "Kategori ini sudah ada. Silakan masukkan kategori lain." << endl;
                }
            } while (expense.category.empty() || isDuplicateCategory(expenses, expense.category));

            expense.amount = getValidInput<double>("Masukkan jumlah pengeluaran untuk " + 
                                                   expense.category + " (Rp): ");

            totalExpenses += expense.amount;
            expenses.push_back(expense);
        }

        for (auto& expense : expenses) {
            expense.percentage = (expense.amount / totalExpenses) * 100;
        }

        cout << fixed << setprecision(2);
        cout << "\n=== Laporan Keuangan ===" << endl;
        cout << left << setw(20) << "Kategori" 
             << right << setw(15) << "Pengeluaran (Rp)" 
             << right << setw(15) << "Persentase (%)" << endl;
        cout << string(50, '-') << endl;

        sortExpenses(expenses);
        for (const auto& expense : expenses) {
            cout << left << setw(20) << expense.category 
                 << right << setw(15) << expense.amount
                 << right << setw(15) << expense.percentage << endl;
        }

        cout << string(50, '-') << endl;
        double balance = income - totalExpenses;
        double expenseRatio = (totalExpenses / income) * 100;

        cout << "\nTotal Pengeluaran: " << formatCurrency(totalExpenses) << endl;
        cout << "Total Pendapatan: " << formatCurrency(income) << endl;
        cout << "Sisa Pendapatan: " << formatCurrency(balance) << endl;

        cout << "\n=== Analisis Keuangan ===" << endl;
        cout << "Rasio Pengeluaran: " << expenseRatio << "% dari pendapatan" << endl;

        if (balance > 0) {
            cout << "Status: SURPLUS" << endl;
            cout << "Rekomendasi: Pertimbangkan untuk menabung " << formatCurrency(balance) 
                 << " atau " << (balance/income)*100 << "% dari pendapatan Anda." << endl;
        } else if (balance == 0) {
            cout << "Status: IMPAS" << endl;
            cout << "Rekomendasi: Pertimbangkan untuk mengurangi pengeluaran dan membuat dana darurat." << endl;
        } else {
            cout << "Status: DEFISIT" << endl;
            cout << "Rekomendasi: Anda perlu memangkas pengeluaran sebesar " << formatCurrency(-balance) 
                 << " atau mencari sumber pendapatan tambahan." << endl;
        }

        displayGraph(expenses);
        showStatistics(expenses);  
        saveToFile(expenses, income, totalExpenses, balance, expenseRatio);

        char choice;
        cout << "\nApakah Anda ingin melakukan simulasi lagi? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        continueProgram = (tolower(choice) == 'y');
    }

    cout << "Terima kasih telah menggunakan Simulasi Manajemen Keuangan Mahasiswa!" << endl;
    return 0;
}
