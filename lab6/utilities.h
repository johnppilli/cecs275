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
#include <vector>
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
double sumCategoryPercentages(std::vector<int> &studentScores, std::vector<int> &maxScores, int startIndex, int count);

/**
 * This function computes one student's average percentage earned in each of the six
 * weighted categories (labs, quizzes, exam 1, exam 2, project, final exam). Results are
 * written back through the reference parameters so the same logic can be reused both for
 * the logged-in student's own report and for every student when building class averages.
 * @param studentScores the student's scores
 * @param maxScores     the maximum possible scores, in the same order
 * @param numLabs, numQuizzes, numExams, numProjects, numFinal  how many assignments are in each category
 * @param avgLab, avgQuiz, avgExam1, avgExam2, avgProject, avgFinal  set to this student's average percentage for each category
 */
void computeCategoryAverages(std::vector<int> &studentScores, std::vector<int> &maxScores,
                              int numLabs, int numQuizzes, int numExams, int numProjects, int numFinal,
                              double &avgLab, double &avgQuiz, double &avgExam1, double &avgExam2,
                              double &avgProject, double &avgFinal);

/**
 * This function reads every student's row in the scores file and computes the whole
 * class's average percentage in each of the six weighted categories. Students with a
 * blank row are skipped entirely so they don't pull the class average down.
 * @param scoresFile the scores file to read from
 * @param classLab, classQuiz, classExam1, classExam2, classProject, classFinal  set to the class average percentage for each category
 */
void computeClassAverages(std::string scoresFile, double &classLab, double &classQuiz, double &classExam1,
                           double &classExam2, double &classProject, double &classFinal);

/**
 * This function prints a comparison between the logged-in student's category averages
 * and the whole class's average for the same categories.
 * @param scoresFile the scores file to read from, used to compute the class averages
 * @param avgLab, avgQuiz, avgExam1, avgExam2, avgProject, avgFinal  the logged-in student's own category averages
 */
void printClassComparison(std::string scoresFile, double avgLab, double avgQuiz, double avgExam1,
                           double avgExam2, double avgProject, double avgFinal);

/**
 * This function converts a final percentage into a letter grade:
 * 90+ = A, 80-89.99 = B, 70-79.99 = C, 60-69.99 = D, below 60 = F.
 * @param totalPercentage the final weighted percentage
 * @return the letter grade ('A', 'B', 'C', 'D' or 'F')
 */
std::string lettergrade(double totalPercentage);

/**
 * This function prints one category's scores on a single line, e.g. "Labs: 5 2 3 ...".
 * @param label      the category name to print
 * @param scores     the array holding all of the student's scores
 * @param startIndex index of the category's first score
 * @param count      how many scores to print
 */
void printCategoryScores(std::string label, std::vector<int> &scores, int startIndex, int count);

/**
 * This function checks whether a file can be opened for reading.
 * @param fileName the name (or full path) of the file
 * @return true if the file exists and opens, false otherwise
 */
bool fileExists(std::string fileName);

/**
 * This function generates the fake data files. It writes fake_users.txt
 * (100 random username/password pairs) and fake_scores.txt (the counts row,
 * the max-scores row, then 100 students' randomly generated scores).
 */
void generateFakeData();

/**
 * This function prints the score report for the logged-in student. It reads the
 * max-scores row and the student's own row from the scores file, then displays the
 * username, scores by category, percentage earned, weighted contribution,
 * total final percentage and final letter grade (percentages to two decimals).
 * @param scoresFile        the scores file to read from
 * @param loggedInRowIndex  the logged-in student's position in the users file (1 = first user)
 * @param loggedInUsername  the username to show on the report
 */
void generateScoreReport(std::string scoresFile, int loggedInRowIndex, std::string loggedInUsername);

#endif
