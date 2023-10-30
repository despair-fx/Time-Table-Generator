#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const int numDays = 5; // Number of days in the week (e.g., Monday to Friday)
const int numSlots = 3; // Number of time slots per day

// Define the subjects and teachers with key-value pairs
map<string, string> teacherSubjects = {
    {"Dr. Naveen Tiwari", "Android Programming"},
    {"Mr. Devender Singh", "Programming with .NET C#"},
    {"Mr. Harshit Pandey", "Optimization Techniques"},
    {"Mr. Praveen Joshi", "Cryptography"}
    // Add more subjects and teachers here
};

// Data structure to represent the schedule
map<string, map<int, vector<string>>> schedule; // teacher -> day -> slots

const int maxLecturesPerWeek = 3;

bool exceedsMaxLectures(const string &teacher) {
    int count = 0;
    for (int day = 0; day < numDays; day++) {
        for (int slot = 0; slot < numSlots; slot++) {
            if (schedule[teacher][day][slot] != "No Class") {
                count++;
            }
        }
    }
    return count >= maxLecturesPerWeek;
}

void initializeSchedule() {
    for (const auto &teacherSubjectPair : teacherSubjects) {
        const string &teacher = teacherSubjectPair.first;
        for (int day = 0; day < numDays; day++) {
            schedule[teacher][day] = vector<string>(numSlots, "No Class");
        }
    }
}

void assignSubjects() {
    for (int day = 0; day < numDays; day++) {
        for (int slot = 0; slot < numSlots; slot++) {
            for (const auto &entry : teacherSubjects) {
                const string &teacher = entry.first;
                const string &subject = entry.second;

                if (!exceedsMaxLectures(teacher) && schedule[teacher][day][slot] == "No Class") {
                    schedule[teacher][day][slot] = subject;
                }
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    // Initialize the schedule with empty slots
    initializeSchedule();

    // Assign subjects to teachers
    assignSubjects();

    // Print the schedule
    for (const auto &entry : teacherSubjects) {
        const string &teacher = entry.first;
        cout << "Schedule for " << teacher << ":" << endl;
        for (int day = 0; day < numDays; day++) {
            cout << "Day " << day << ": ";
            for (int slot = 0; slot < numSlots; slot++) {
                cout << schedule[teacher][day][slot] << " | ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
