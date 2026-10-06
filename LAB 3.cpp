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
    // Variables for the file values
    int fileNum1, fileNum2, fileNum3, fileNum4;

    // Variables for the user values
    int userNum1, userNum2, userNum3, userNum4;

    double fileMean;
    double fileStdDev;
    double userMean;
    double userStdDev;

    // Open the input and output files
    ifstream inputFile("inMeanStd.dat");
    ofstream outputFile("outMeanStd.dat");

    // Check if the input file opened correctly
    if (!inputFile)
    {
        cout << "Error opening inMeanStd.dat." << endl;
        return 1;
    }

    // Check if the output file opened correctly
    if (!outputFile)
    {
        cout << "Error opening outMeanStd.dat." << endl;
        return 1;
    }

    // Read four integers from the input file
    inputFile >> fileNum1 >> fileNum2 >> fileNum3 >> fileNum4;

    // Calculate the mean for the file values
    fileMean = (fileNum1 + fileNum2 + fileNum3 + fileNum4) / 4.0;

    // Calculate the population standard deviation for the file values
    fileStdDev = sqrt(
        (
            (fileNum1 - fileMean) * (fileNum1 - fileMean) +
            (fileNum2 - fileMean) * (fileNum2 - fileMean) +
            (fileNum3 - fileMean) * (fileNum3 - fileMean) +
            (fileNum4 - fileMean) * (fileNum4 - fileMean)
        ) / 4.0
    );

    // Write the file results to outMeanStd.dat
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

    // Ask the user to enter four integers
    cout << "Enter the first integer: ";
    cin >> userNum1;

    cout << "Enter the second integer: ";
    cin >> userNum2;

    cout << "Enter the third integer: ";
    cin >> userNum3;

    cout << "Enter the fourth integer: ";
    cin >> userNum4;

    // Calculate the mean for the user values
    userMean = (userNum1 + userNum2 + userNum3 + userNum4) / 4.0;

    // Calculate the population standard deviation for the user values
    userStdDev = sqrt(
        (
            (userNum1 - userMean) * (userNum1 - userMean) +
            (userNum2 - userMean) * (userNum2 - userMean) +
            (userNum3 - userMean) * (userNum3 - userMean) +
            (userNum4 - userMean) * (userNum4 - userMean)
        ) / 4.0
    );

    // Display the user results on the screen
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

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}
