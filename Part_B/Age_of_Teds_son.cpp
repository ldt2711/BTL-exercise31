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

class CalculateMain
{
private:
    map<string, pair<string, int>> birthRecords; // Lưu quan hệ cha - con và tuổi của cha khi sinh con
    map<string, int> ages; // Lưu tuổi của từng người
    dlist<Person> sortedList;
public:
    CalculateMain()
    {
        // Cụ Ted có tuổi là 100
        ages["Ted"] = 100;
    }
    // Hàm reset để xóa dữ liệu trước khi xử lý bộ dữ liệu mới
    void reset() {
        birthRecords.clear();
        ages.clear();
        ages["Ted"] = 100;
        sortedList.clear();
    }
    // Đọc thông tin từng giấy khai sinh
    void readBirthRecordInfo(int X){
        for (int i = 0; i < X; ++i) {
            string father, child;
            int fatherAgeWhenChildBorn;
            cin >> father >> child >> fatherAgeWhenChildBorn;
            birthRecords[child] = {father, fatherAgeWhenChildBorn};
        }
    }
    // Tính tuổi của từng người con cháu
    void calculateAgeAll(){
        for (const auto &record : birthRecords) {
            string child = record.first;
            calculateAge(child, ages, birthRecords);
        }
    }
    // Tạo danh sách các người cần sắp xếp (loại bỏ cụ Ted)
    void sortListOfSon(){
        for (const auto &entry : ages) {
            if (entry.first != "Ted") { // Loại cụ Ted khỏi danh sách
                sortedList.push_back({entry.first, entry.second});
            }
        }

        // Sắp xếp danh sách theo tiêu chí bài toán
        sortedList.sort(comparePersons);
    }
    // In kết quả
    void printListOfSon(int t){
        cout << "DATASET " << t << endl;
        for (const auto &person : sortedList) {
            cout << person.name << " " << person.age << endl;
        }
    }
};

int main() {
    int numTests;
    cin >> numTests;
    CalculateMain C;

    for (int t = 1; t <= numTests; ++t) {
        int X;
        cin >> X;

        C.reset();

        // Đọc thông tin từng giấy khai sinh
        C.readBirthRecordInfo(X);

        // Tính tuổi của từng người con cháu
        C.calculateAgeAll();

        // Tạo danh sách các người cần sắp xếp (loại bỏ cụ Ted)
        C.sortListOfSon();

        // In kết quả
        C.printListOfSon(t);
    }

    return 0;
}
