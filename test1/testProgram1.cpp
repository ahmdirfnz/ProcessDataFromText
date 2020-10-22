#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Covid19
{
    string gender;
    string name;
    int age;
    int day;
    double dailyTemp[];
};

Covid19 patientInfo[3];

int main()
{
    ifstream inFile("covid.txt");
    string line,ages,days,dailys;

    vector<string> dailyT;
    // string *dailyT;
    // string dailyT[patientInfo]

    // patientInfo[0].dailyTemp[0] = 0.0; 
    

    int i = 0;

    while (getline(inFile, line))
    {
        stringstream ss(line);
        getline(ss, patientInfo[i].gender, ';');
        getline(ss, patientInfo[i].name, ';');
        ss.ignore();
        // ss.ignore();
        ss >> patientInfo[i].age >> patientInfo[i].day;
        ss.ignore();
        // ss.ignore();
        

        

        // for (int j = 0; j < patientInfo[i].day; j++)
        // {
        //     ss >> patientInfo[i].dailyTemp[j];
        // }
        

        // ss.ignore();
        // ss.ignore();

        // getline(ss, dailys, ' ');
        // patientInfo[0].dailyTemp[0] = stod(dailys);
        
        for (int j = 0; j < patientInfo[i].day; j++)
        {
            
            // getline(ss, dailyT[j], ' ');
            // patientInfo[i].dailyTemp[j] = stod(dailyT[j]);
            ss >> patientInfo[i].dailyTemp[j];
            
        }
        // ss.ignore();

        i++;

}
// inFile.close();
        cout << patientInfo[0].gender << "\n"
         << patientInfo[0].name << "\n"
         << patientInfo[0].age << "\n"
         << patientInfo[0].day << "\n"
         << patientInfo[0].dailyTemp[0] << "\n";

        // for (int i = 0; i < dailyT.size(); i++)
        // {
        //     cout << dailyT[i] << "\n";
        // }     
}
