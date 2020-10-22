#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define SIZE 50

using namespace std;

struct Covid19
{
    string gender;
    string name;
    int age;
    int day;
    double dailyTemp[10];
};

Covid19 patientInfo[SIZE];
void calculateGender(Covid19 *patientInfo, int &, int &, int &);
void check_Youngest_Oldest(Covid19 *patientInfo, int *, int *, string *, string *);

int main()
{
    ifstream inFile("covid.txt");

    int count = 0, male = 0, female = 0, youngest = 2, oldest = 0;
    string line, youngestGen, oldestGen, ages, days;

    for (int a = 0; a < SIZE; a++)
    {
        patientInfo[count].gender = "";
        patientInfo[count].name = "";
        patientInfo[count].age = 0;
        patientInfo[count].day = 0;

        for (int b = 0; b < patientInfo[count].day; b++)
        {
            patientInfo[a].dailyTemp[b] = 0.0;
        }
    }

    while (getline(inFile, line))
    {
        stringstream ss(line);

        getline(ss, patientInfo[count].gender, ';');
        getline(ss, patientInfo[count].name, ';');

        ss.ignore();

        getline(ss, ages, ' ');
        getline(ss, days, ' ');

        stringstream convertAge(ages);
        stringstream convertDay(days);

        convertAge >> patientInfo[count].age;
        convertDay >> patientInfo[count].day;

        for (int i = 0; i < patientInfo[count].day; i++)
        {
            ss >> patientInfo[count].dailyTemp[i];
        }
        count++;
    }

    check_Youngest_Oldest(patientInfo, &youngest, &oldest, &youngestGen, &oldestGen);

    calculateGender(patientInfo, female, male, count);

    cout << female << "\n"
         << male << "\n"
         << patientInfo[0].age << "\n"
         << patientInfo[0].day << "\n"
         << patientInfo[0].dailyTemp[0] << "\n";

    int longestDay = patientInfo[0].day, day40 = 0, patientAge;
    string patientName, patientGender;

    for (int i = 0; i < SIZE; i++)
    {
        if (longestDay <= patientInfo[i].day)
        {
            longestDay = patientInfo[i].day;
            patientName = patientInfo[i].name;
            patientAge = patientInfo[i].age;
            patientGender = patientInfo[i].gender;
        }

        for (int j = 0; j < longestDay; j++)
        {
            if (patientInfo[i].dailyTemp[j] > 40)
            {
                day40++;
            }
        }
    }

    ofstream outFile;
    outFile.open("summary.txt", ios::out);

    outFile << "LIST OF COVID 19 PATIENTS" << endl;
    outFile << "Summary of Covid19 patients\n" << endl;
    outFile << "==========================" << endl;
    outFile << "Total number of male patients: " << male << endl;
    outFile << "Total number of female patients: " << female << endl;
    outFile << "The youngest patient age: " << youngest << "(" << youngestGen << ")" <<endl;
    outFile << "The oldest patient age: " << oldest << "(" << oldestGen << ")" << endl;
    outFile << "The longest length of stay in the ward is " << longestDay << " days with " << day40 << " days temperature above 40'C" << endl;
    outFile << "The patient's name is " << patientName << "(" << patientGender << ", " << patientAge << " years old)." << endl;

    outFile.close();

    return 0;
}

void calculateGender(Covid19 *patientInfo, int &female, int &male, int &count)
{
    for (int i = 0; i < count; i++)
    {
        if (patientInfo[i].gender == "female")
        {
            female++;
        }
        else
        {
            male++;
        }
    }
}

void check_Youngest_Oldest(Covid19 *patientInfo, int *youngest, int *oldest, string *youngGender, string *oldGender)
{

    *youngest = patientInfo[0].age;
    *youngGender = patientInfo[0].gender;

    // *oldest = patientInfo[0].age;
    // *oldGender = patientInfo[0].gender;

    for (int i = 0; i < SIZE; i++)
    {
        if (patientInfo[i].age <= *youngest) {

            *youngest = patientInfo[i].age;
            *youngGender = patientInfo[i].gender;

        } else if (patientInfo[i].age >= *oldest) {
            *oldest = patientInfo[i].age;
            *oldGender = patientInfo[i].gender;
        }
    }
}
