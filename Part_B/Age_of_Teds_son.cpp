#include <iostream>
#include <string>
#include <map>
#include "DList.cpp"
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int age;
};

bool comparePersons(const Person &a, const Person &b) {
    // So sánh tuổi giảm dần, nếu tuổi bằng nhau thì so sánh tên theo thứ tự từ điển
    if (a.age != b.age) return a.age > b.age;
    return a.name < b.name;
}

// Hàm đệ quy tính tuổi của một người
int calculateAge(const string &person, map<string, int> &ages, map<string, pair<string, int>> &birthRecords) {
    // Tìm xem person có trong map ages chưa
    if (ages.find(person) != ages.end()) {
        return ages[person]; // Nếu tuổi đã được xác định thì trả về
    }

    string father = birthRecords[person].first;
    int fatherAgeWhenChildBorn = birthRecords[person].second;

    // Tính tuổi của cha trước nếu chưa có
    ages[person] = calculateAge(father, ages, birthRecords) - fatherAgeWhenChildBorn;
    return ages[person];
}

int main() {
    int numTests;
    cin >> numTests;

    for (int t = 1; t <= numTests; ++t) {
        int X;
        cin >> X;

        map<string, pair<string, int>> birthRecords; // Lưu quan hệ cha - con và tuổi của cha khi sinh con
        map<string, int> ages; // Lưu tuổi của từng người

        // Đọc thông tin từng giấy khai sinh
        for (int i = 0; i < X; ++i) {
            string father, child;
            int fatherAgeWhenChildBorn;
            cin >> father >> child >> fatherAgeWhenChildBorn;
            birthRecords[child] = {father, fatherAgeWhenChildBorn};
        }

        // Cụ Ted có tuổi là 100
        ages["Ted"] = 100;

        // Tính tuổi của từng người con cháu
        for (const auto &record : birthRecords) {
            string child = record.first;
            calculateAge(child, ages, birthRecords);
        }

        // Tạo danh sách các người cần sắp xếp (loại bỏ cụ Ted)
        dlist<Person> sortedList;
        for (const auto &entry : ages) {
            if (entry.first != "Ted") { // Loại cụ Ted khỏi danh sách
                sortedList.push_back({entry.first, entry.second});
            }
        }

        // Sắp xếp danh sách theo tiêu chí bài toán
        sortedList.sort(comparePersons);

        // In kết quả
        cout << "DATASET " << t << endl;
        for (const auto &person : sortedList) {
            cout << person.name << " " << person.age << endl;
        }
    }

    return 0;
}
