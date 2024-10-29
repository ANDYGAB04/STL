#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inFile("input.txt");
    int no_problems, no_doctors;
    string name, speciality;

    inFile >> no_problems;
    vector<string> names;
    vector<string> specialities;
    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        names.push_back(name);
        inFile >> speciality;
        specialities.push_back(speciality);
        // cout << name << ' ' << speciality << '\n';
    }

    inFile >> no_doctors;
    vector<string> docspeciality;
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        docspeciality.push_back(speciality);
        // cout << name << ' ' << speciality << '\n';
    }
    int i = 0;
    for (auto name = names.begin(); name < names.end(); name++) {
        bool ok = false;
        for (auto v = docspeciality.begin(); v < docspeciality.end(); v++) {


            if (*v == specialities[i]) {
                cout << *name << " " << "Acceptat" << endl;
                ok = true;
                break;
            }



        }


        if (!ok) {
            cout << *name << " " << "Refuzat" << endl;

        }
        i++;
    }

    return 0;
}