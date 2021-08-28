#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>

using namespace std;

class trains
{
protected:
    int number;
    string departure, destination;
public:
    trains() :number(0), departure(0), destination(0) {}             //default constructor
    trains(const trains& ent) :number(ent.number), departure(ent.departure), destination(ent.destination) {}
    trains(int _number, string _departure, string _destination)
    {
        number = _number;                        //train number
        departure = _departure;                  //time departure
        destination = _destination;              //place destnation
    }
    int getNumber()                       
    {
        return number;
    }
    string getDeparture()
    {
        return departure;
    }
    string getDestination()
    {
        return destination;
    }
    void operator = (trains q)
    {
        number = q.number;
        departure = q.departure;
        destination = q.destination;
    }
};

void addTrain(vector <trains>& tr)                          //function for add trains
{
    int num;
    string station, time;

    cout << "\nEnter train number: "; cin >> num;
    cin.ignore();
    cout << "Enter time departure: "; cin >> time;
    cin.ignore();
    cout << "Enter place destination: "; cin >> station;
    cin.ignore();
    tr.push_back(trains(num, time, station));
}

void allTrains(vector <trains>& tr)                           //function for print all trains
{
    if (tr.empty())
    {
        cout << "List is empty! " << endl; return;            //check vector
    }
    vector <trains>::iterator iter = tr.begin();
    cout << "\n\nTrain number  " << '\t' << " Time departure " << '\t' << " Place destination " << endl;
    while (iter != tr.end())                                  //passing in vector
    {
        cout << iter->getNumber() << setw(25) << iter->getDeparture() << setw(25) << iter->getDestination() << '\n';
        iter++;
    }
}

void findTrain(vector<trains>& tr)                           //function to find train
{
    if (tr.empty()) { cout << "List is empty\n"; return; }   //check vector
    int ftrain;
    cout << "\n\nEnter train number: " << endl;
    cin >> ftrain;

    bool found = false;
    for (vector <trains>::iterator iter = tr.begin(); iter != tr.end(); ++iter)    //passing in vector
    {
        if (iter->getNumber() == ftrain)                     //train finded
        {
            cout << "\nPlace destination " << '\t' << " Time departure " << endl;
            cout << iter->getDestination() << setw(25) << iter->getDeparture() << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Train not found! " << endl;         //train not finded
}

void main()
{
    int quantity;
    vector <trains> DB;
    cout << "Enter train info. How many trains do you want to enter? Enter quantity (1, 2, 3, 4, 5 ...) "; cin >> quantity;
    for (int i = 0; i < quantity; i++)
    {
        addTrain(DB);
    }
    allTrains(DB);
    findTrain(DB);
}