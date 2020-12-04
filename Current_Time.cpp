#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
       time_t timeNow = time(0);

       
       tm *localTime = localtime(&timeNow);

       // use tm structure in <ctime>

       cout << "Year: " << 1900 + localTime->tm_year << endl;
       cout << "Month: " << 1 + localTime->tm_mon << endl;
       cout << "Day: " << localTime->tm_mday << endl;
       
       return 0;
}
