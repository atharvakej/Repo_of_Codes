#include <iostream>
#include <vector>
using namespace std;

string getDayOfWeek(int year, int month, int day) {
    // If month is January or February, adjust it to 13th or 14th month of the previous year
    if (month == 1 || month == 2) {
        month += 12;
        year -= 1;
    }

    int K = year % 100;  // Last two digits of the year
    int J = year / 100;  // First two digits of the year

    // Zeller's Congruence formula
    int h = (day + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    // Map the result of 'h' to the correct day name
    const char* daysOfWeek[] = {"SATURDAY", "SUNDAY", "MONDAY", 
                                "TUESDAY", "WEDNESDAY", 
                                "THURSDAY", "FRIDAY"};

    return daysOfWeek[h];
}

int main() {
    int N;
    cin >> N;
    vector<int> year(N), month(N), day(N);

    // Read N dates
    for (int i = 0; i < N; ++i) {
        char dash1, dash2;  // To ignore the '-' separators
        cin >> year[i] >> dash1 >> month[i] >> dash2 >> day[i];
    }

    // Output the day of the week for each date
    for (int i = 0; i < N; ++i) {
        cout << getDayOfWeek(year[i], month[i], day[i]) << endl;
    }

    return 0;
}
