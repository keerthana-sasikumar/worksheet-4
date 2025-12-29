#include <iostream>
using namespace std;

class DB;

class DM
{
    int meter, cm;

public:
    void getdata()
    {
        cout << "Enter meters and centimeters: ";
        cin >> meter >> cm;
    }

    void showdata()
    {
        cout << "Distance in meters: " << meter << " m " << cm << " cm" << endl;
    }

    friend DM addDistance(DM, DB);
};

class DB
{
    int feet, inch;

public:
    void getdata()
    {
        cout << "Enter feet and inches: ";
        cin >> feet >> inch;
    }

    friend DM addDistance(DM, DB);
};

// Friend function definition
DM addDistance(DM d1, DB d2)
{
    DM result;

    // Convert feet and inches to centimeters
    int total_cm = (d2.feet * 12 + d2.inch) * 2.54;

    result.meter = d1.meter;
    result.cm = d1.cm + total_cm;

    if (result.cm >= 100)
    {
        result.meter += result.cm / 100;
        result.cm = result.cm % 100;
    }

    return result;
}

int main()
{
    DM d1, d3;
    DB d2;

    d1.getdata();
    d2.getdata();

    d3 = addDistance(d1, d2);

    cout << "Total Distance:\n";
    d3.showdata();

    return 0;
}
