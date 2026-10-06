/*
Name: Pedro Henrique Morais
Instructor: David Busch
Lab 3

Description:
This program reads four integers from a file and from the user.
It calculates the mean and population standard deviation.
The results are written to a file and displayed on the screen.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int fileNum1, fileNum2, fileNum3, fileNum4;
    int userNum1, userNum2, userNum3, userNum4;

    double fileMean;
    double fileStdDev;
    double userMean;
    double userStdDev;

    ifstream inputFile("inMeanStd.dat");
    ofstream outputFile("outMeanStd.dat");

    if (!inputFile)
    {
        cout << "Error opening inMeanStd.dat." << endl;
        return 1;
    }

    inputFile >> fileNum1 >> fileNum2 >> fileNum3 >> fileNum4;

    fileMean = (fileNum1 + fileNum2 + fileNum3 + fileNum4) / 4.0;

    fileStdDev = sqrt(
        (
            (fileNum1 - fileMean) * (fileNum1 - fileMean) +
            (fileNum2 - fileMean) * (fileNum2 - fileMean) +
            (fileNum3 - fileMean) * (fileNum3 - fileMean) +
            (fileNum4 - fileMean) * (fileNum4 - fileMean)
            ) / 4.0
    );

    outputFile << fixed << setprecision(2);

    outputFile << "File Input Results" << endl;
    outputFile << "Values: "
        << fileNum1 << " "
        << fileNum2 << " "
        << fileNum3 << " "
        << fileNum4 << endl;

    outputFile << "Mean: " << fileMean << endl;
    outputFile << "Population Standard Deviation: "
        << fileStdDev << endl;

    cout << "Enter the first integer: ";
    cin >> userNum1;

    cout << "Enter the second integer: ";
    cin >> userNum2;

    cout << "Enter the third integer: ";
    cin >> userNum3;

    cout << "Enter the fourth integer: ";
    cin >> userNum4;

    userMean = (userNum1 + userNum2 + userNum3 + userNum4) / 4.0;

    userStdDev = sqrt(
        (
            (userNum1 - userMean) * (userNum1 - userMean) +
            (userNum2 - userMean) * (userNum2 - userMean) +
            (userNum3 - userMean) * (userNum3 - userMean) +
            (userNum4 - userMean) * (userNum4 - userMean)
            ) / 4.0
    );

    cout << fixed << setprecision(2);

    cout << endl;
    cout << "User Input Results" << endl;
    cout << "Values: "
        << userNum1 << " "
        << userNum2 << " "
        << userNum3 << " "
        << userNum4 << endl;

    cout << "Mean: " << userMean << endl;
    cout << "Population Standard Deviation: "
        << userStdDev << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}