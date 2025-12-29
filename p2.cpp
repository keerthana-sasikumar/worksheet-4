#include <iostream>
using namespace std;

class TIME
{
    int hr, min, sec;

public:
    void getdata()
    {
        cout << "Enter hours, minutes and seconds: ";
        cin >> hr >> min >> sec;
    }

    void showdata()
    {
        cout << hr << " : " << min << " : " << sec << endl;
    }

    // Operator overloading for +
    TIME operator+(TIME t)
    {
        TIME temp;
        temp.sec = sec + t.sec;
        temp.min = min + t.min;
        temp.hr  = hr + t.hr;

        if (temp.sec >= 60)
        {
            temp.sec -= 60;
            temp.min++;
        }
        if (temp.min >= 60)
        {
            temp.min -= 60;
            temp.hr++;
        }

        return temp;
    }

    // Operator overloading for ++ (post-increment)
    void operator++(int)
    {
        sec++;
        if (sec >= 60)
        {
            sec = 0;
            min++;
        }
        if (min >= 60)
        {
            min = 0;
            hr++;
        }
    }
};

int main()
{
    TIME t1, t2, t3;

    t1.getdata();
    t2.getdata();

    t3 = t1 + t2;
    t1++;

    cout << "Time t3: ";
    t3.showdata();

    cout << "Time t1 after increment: ";
    t1.showdata();

    return 0;
}
