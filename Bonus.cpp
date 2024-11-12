#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inFile("input1.txt");
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
    vector<string> docnames;
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        docspeciality.push_back(speciality);
        // cout << name << ' ' << speciality << '\n';
        docnames.push_back(name);
    }
    int i = 0, j = 0;
    vector<string> specialitiesbusy;
    for (auto name = names.begin(); name < names.end(); name++) {
        bool ok = false;
        for (auto v = docspeciality.begin(); v < docspeciality.end(); v++) {


            if (*v == specialities[i] && find(specialitiesbusy.begin(), specialitiesbusy.end(), specialities[i]) == specialitiesbusy.end()) {
                cout << docnames[j] << " " << *name << endl;
                j++;
                specialitiesbusy.push_back(*v);
                break;
            }



        }


        i++;
    }

    return 0;
}