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
        
        // Delay to simulate real-time
        // Adjust sleep duration according to the desired update rate
        // For example, sleep for 1 second for a real-time effect
        // You may need to include appropriate headers for sleep function on your system
        // e.g., #include <unistd.h> for Unix-like systems or #include <windows.h> for Windows
        // Here, I'll assume a delay of 1 second
        // Adjust this according to your needs or the platform you are using
        // For Windows, you can use Sleep(1000) for 1 second delay
        // For Unix-like systems, you can use sleep(1) for 1 second delay
        // Remember to include the appropriate headers for your system
        // sleep(1); // Unix-like systems
        // Sleep(1000); // Windows systems
    

    return 0;
}
