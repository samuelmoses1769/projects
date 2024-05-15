#include <iostream>
#include <iomanip>

using namespace std;

class DigitalClock {
private:
    int hour;
    int minute;
    int second;

public:
    // Parameterized constructor
    DigitalClock(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    void tick() {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour = (hour + 1) % 24;
            }
        }
    }

    void display() {
        int displayHour = hour;
        string period = "AM";

        if (displayHour >= 12) {
            period = "PM";
            if (displayHour > 12)
                displayHour -= 12;
        }

        cout << setfill('0') << setw(2) << displayHour << ":"
             << setw(2) << minute << ":" << setw(2) << second << " " << period << endl;
    }
};

int main() {
    int initialHour, initialMinute, initialSecond;

    // Get initial hour, minute, and second from user input
    cout << "Enter initial hour (0-23): ";
    cin >> initialHour;

    cout << "Enter initial minute (0-59): ";
    cin >> initialMinute;

    cout << "Enter initial second (0-59): ";
    cin >> initialSecond;

    // Create a DigitalClock object with user-provided initial time
    DigitalClock clock(initialHour, initialMinute, initialSecond);

    
        clock.display();
        
    

    return 0;
}
