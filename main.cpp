#include "MarbleMachine.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void printMenu()
{
    cout << "Add all desired pieces and then finish track by adding an output piece." << endl;
    cout << "1. Insert Piece" << endl;
    cout << "2. Remove Piece" << endl;
    cout << "3. Add Output and Run" << endl;
    cout << "4. Quit" << endl;
}

void printMenu2()
{
    cout<<"Select piece to add:"<<endl;
    cout << "1. Straight (short)" << endl;
    cout << "2. Straight (long)" << endl;
    cout << "3. Buffer (Small)" << endl;
    cout << "4. Buffer (Large)" << endl;
    cout << "5. Splitter/Joiner" << endl;
}

void printMenu3(MarbleMachine* mm)
{
    cout << "======Add Marbles or Return======"  << endl << endl;;
    mm->print();
    cout << endl << "1. Add marbles by rate and duration" << endl;
    cout << "2. Add marbles by number and duration" << endl;
    cout << "3. Add marbles by rate and number" << endl;
    cout << "4. Remove output and edit track" << endl;
    cout << "5. Quit" << endl;
}

int getRate()
{
    string buf;
    cout << "Enter Rate (Marbles/sec, max 10) or b for back:" << endl;
    getline(cin,buf);
    if(buf == "b")
        return -1;

    int rate = atoi(buf.c_str());
    while(!(rate>0 && rate<=10))
    {
        cout << "Please enter a valid rate (1-10) or b for back:" << endl;
        getline(cin,buf);
        if(buf == "b")
        {
            return -1;
        }

        rate = atoi(buf.c_str());
    }
    return rate;
}

int getDur()
{
    string buf;
    cout << "Enter duration (Seconds, max 10):" << endl;
    getline(cin,buf);
    if(buf == "b")
        return -1;

    int dur = atoi(buf.c_str());
    while(!(dur>0 && dur<=10))
    {
        cout << "Please enter a valid duration (1-10) or b for back:" << endl;
        getline(cin,buf);
        if(buf == "b")
        {
            return -1;
        }

        dur = atoi(buf.c_str());
    }
    return dur;
}

int getNum()
{
    string buf;
    cout << "Enter a number of marbles (100 max):" << endl;
    getline(cin,buf);
    if(buf == "b")
        return -1;

    int num = atoi(buf.c_str());
    while(!(num>0 && num<=100))
    {
        cout << "Please enter a valid duration (1-100) or b for back:" << endl;
        getline(cin,buf);
        if(buf == "b")
        {
            return -1;
        }

        num = atoi(buf.c_str());
    }
    return num;
}

void runRateDur(MarbleMachine* mm)
{
    int rate = getRate();
    if(rate == -1)
        return;
    int dur = getDur();
    if(dur == -1)
        return;

    mm->runRD(rate,dur);
}

void runNumDur(MarbleMachine* mm)
{
    int num = getNum();
    if(num == -1)
        return;
    int dur = getDur();
    if(dur == -1)
        return;

    mm->runND(num,dur);
}

void runRateNum(MarbleMachine* mm)
{
    int rate = getRate();
    if(rate == -1)
        return;
    int num = getNum();
    if(num == -1)
        return;

    mm->runRN(rate,num);
}

int main(int argc,char **argv)
{
    MarbleMachine mm;
    while(true)
    {
        string buf;
        char c;
        if(!mm.closed())
        {
            cout << "======Marble Machine======" << endl << endl;
            mm.print();
            cout<<endl;
            printMenu();
            getline(cin,buf);
            if(buf.length() > 1)
                c = 0;
            else
                c = buf[0];
            switch(c)
            {
            case '1':
            {
                printMenu2();
                getline(cin,buf);
                int n = atoi(buf.c_str());
                if(!(n > 0 && n <= 5))
                {
                    while(!(n > 0 && n <= 5))
                    {
                        cout<<"Invalid Input"<<endl;
                        printMenu2();
                        getline(cin,buf);
                        n = atoi(buf.c_str());
                        if(n==-1)
                        {
                            break;
                        }
                        if(n > 0 && n <= 5)
                        {
                            mm.addElement(n);
                        }
                    }
                }
                else
                {
                    mm.addElement(n);
                }
                break;
            }
            case '2':
            {
                mm.popElement();
                break;
            }
            case '3':
            {
                mm.addElement(6);
                break;
            }
            case '4':
            {
                cout<<"Goodbye!"<<endl;
                return 0;
                break;
            }
            default:
            {
                cout<<"Invalid input"<<endl;
                break;
            }
            }
        }
        else
        {
            printMenu3(&mm);
            getline(cin,buf);
            if(buf.length() > 1)
                c = 0;
            else
                c = buf[0];
            switch(c)
            {
            case '1':
            {
                runRateDur(&mm);
                break;
            }
            case '2':
            {
                runNumDur(&mm);
                break;
            }
            case '3':
            {
                runRateNum(&mm);
                break;
            }
            case '4':
            {
                mm.popElement();
                break;
            }
            case '5':
            {
                cout<<"Goodbye!"<<endl;
                return 0;
                break;
            }
            default:
            {
                cout<<"Invalid Input"<<endl;
                break;
            }
            }
        }
    }
}
