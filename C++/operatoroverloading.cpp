#include <iostream>
using namespace std;

class Time {
   private:
      int hours;
      int minutes;

   public:
      Time() {
         hours = 0;
         minutes = 0;
      }
      Time(int h, int m) {
         hours = h;
         minutes = m;
      }
      void display() {
         cout << "Hours: " << hours << "Minutes: " << minutes <<endl;
      }

      Time operator-- () {
         --minutes;
         if(minutes >= 60) {
            ++hours;
            minutes -= 60;
         }
         return Time(hours, minutes);
      }
};

int main() {
   Time T1(11, 59);

   --T1;
   T1.display();
   --T1;
   T1.display();
}
