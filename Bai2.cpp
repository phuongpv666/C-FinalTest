
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class VanDongVien {
private:
    string hoten;
    int tuoi;
    string monthidau;
    float cannang;
    float chieucao;

public:
    VanDongVien() {}

    VanDongVien(string ht, int t, string mtd, float cn, float cc)
        : hoten(ht), tuoi(t), monthidau(mtd), cannang(cn), chieucao(cc) {}

    friend istream& operator>>(istream& is, VanDongVien& vdv) {
        cout << "Enter athlete information (athlete number is from 1 to n) (name): ";
        getline(is, vdv.hoten);
        cout << "Enter athlete age: ";
        is >> vdv.tuoi;
        cin.ignore(); // Clear the newline character from the input buffer
        cout << "Enter athlete Competitive_Sport: ";
        getline(is, vdv.monthidau);
        cout << "Enter athlete weight: ";
        is >> vdv.cannang;
        cout << "Enter athlete height: ";
        is >> vdv.chieucao;
        return is;
    }

    friend ostream& operator<<(ostream& os, const VanDongVien& vdv) {
        os << vdv.hoten << " " << vdv.tuoi << " " << vdv.monthidau << " " << vdv.cannang << " " << vdv.chieucao;
        return os;
    }

    bool operator>(const VanDongVien& other) const {
        if (chieucao > other.chieucao) {
            return true;
        } else if (chieucao == other.chieucao) {
            return cannang > other.cannang;
        }
        return false;
    }
};

int main() {
    int n;
    cout << "Enter the number of athletes: ";
    cin >> n;
    cin.ignore(); // Clear the newline character from the previous input

    if (n < 1) {
        cout << "Invalid input. The number of athletes must be at least 1." << endl;
        return 1;
    }

    vector<VanDongVien> athletes(n);

    for (int i = 0; i < n; ++i) {
        cin >> athletes[i];
        cin.ignore(); // Clear the newline character after each input
    }

    cout << "\nList of athletes:" << endl;
    for (const VanDongVien& vdv : athletes) {
        cout << vdv << endl;
    }

    sort(athletes.begin(), athletes.end(), greater<VanDongVien>());

    cout << "\nSorted list of athletes:" << endl;
    for (const VanDongVien& vdv : athletes) {
        cout << vdv << endl;
    }

    return 0;
}