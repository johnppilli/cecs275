/**
 * utilities.h
 * Declarations for the helper functions used by lab5.cpp (Grade Calculator).
 * Covers random data generation for the fake users/scores files, the grade
 * calculations for the score report, and small file/output helpers.
 * The definitions live in utilities.cpp.
 *
 * @author John Pilli
 * @author Oswaldo Castaneda
 * @version 0.0.0
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

/**
 * This function builds a string of random lowercase letters.
 * @param length how many letters the word should have
 * @return a random lowercase string of the given length
 */
std::string randomWord(int length);

/**
 * This function picks a random whole number between two bounds (both inclusive).
 * @param lowerBound the smallest value that can be returned
 * @param upperBound the largest value that can be returned
 * @return the random number, converted to a string
 */
std::string randomNumberInRange(int lowerBound, int upperBound);

/**
 * This function generates a fake username: a random lowercase word 6 to 12 letters long,
 * followed by a random number from 1 to 99 (e.g. "kzcxlhwyv20").
 * @return the generated username
 */
std::string generateRandomUsername();

/**
 * This function generates a fake 12-character password made of a digit, a lowercase letter
 * and an uppercase letter, repeated four times (e.g. "7rF8qY4qF9kX").
 * @return the generated password
 */
std::string generateRandomPassword();

/**
 * This function generates a random score. Used for both the maximum possible score of an
 * assignment (min > 0) and a student's actual score (min = 0, max = that
 * assignment's maximum).
 * @param min the lowest score that can be generated
 * @param max the highest score that can be generated
 * @return the random score, as a string
 */
std::string generateRandomScores(int min, int max);

/**
 * This function picks one random uppercase letter (A-Z) from an alphabet array.
 * @return a single uppercase letter, as a string
 */
std::string randomCapitalLetter();

/**
 * This function picks one random lowercase letter (a-z) from an alphabet array.
 * @return a single lowercase letter, as a string
 */
std::string randomLowerCaseLetter();

/**
 * This function adds up the percentage earned on each assignment in one category.
 * For every assignment in the range it computes (score / max score) * 100
 * and adds it to a running total. Dividing the result by count gives the
 * category average.
 * @param studentScores the student's 31 scores
 * @param maxScores     the 31 maximum possible scores, in the same order
 * @param startIndex    index of the category's first assignment
 * @param count         how many assignments are in the category
 * @return the sum of the individual assignment percentages
 */
double sumCategoryPercentages(int studentScores[], int maxScores[], int startIndex, int count);

/**
 * This function converts a final percentage into a letter grade:
 * 90+ = A, 80-89.99 = B, 70-79.99 = C, 60-69.99 = D, below 60 = F.
 * @param totalPercentage the final weighted percentage
 * @return the letter grade ('A', 'B', 'C', 'D' or 'F')
 */
char lettergrade(double totalPercentage);

/**
 * This function prints one category's scores on a single line, e.g. "Labs: 5 2 3 ...".
 * @param label      the category name to print
 * @param scores     the array holding all of the student's scores
 * @param startIndex index of the category's first score
 * @param count      how many scores to print
 */
void printCategoryScores(std::string label, int scores[], int startIndex, int count);

/**
 * This function checks whether a file can be opened for reading.
 * @param fileName the name (or full path) of the file
 * @return true if the file exists and opens, false otherwise
 */
bool fileExists(std::string fileName);

#endif
