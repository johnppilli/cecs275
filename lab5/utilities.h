

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

std::string randomWord(int length);

std::string randomNumberInRange(int lowerBound, int upperBound);

std::string generateRandomUsername();

std::string generateRandomPassword();

std::string generateRandomScores(int min, int max);

std::string randomCapitalLetter();

std::string randomLowerCaseLetter();

double sumCategoryPercentages(int studentScores[], int maxScores[], int startIndex, int count);

char lettergrade(double totalPercentage);

void printCategoryScores(std::string label, int scores[], int startIndex, int count);

#endif
