/*
 * These are the prototypes for fake data generator
 * @author john pilli
 * @author oswaldo castaneda
 *
 * @version 0.0.0
 * Last updated: 09/08/26
 *
 * Initial Version: 09/08/26
 *
 */

#ifndef UTILITIES_H // header guard
#define UTILITIES_H

#include <string>

// This .h file announces what functions exist and how to call them

// returnType functionName(parameters list); <-- this makes a function prototype

/*
 * This function generates a random phone number
 * in the given phone number format type
 *
 * @param phoneFormatType 0 = (111)-111-1111, 1 = 111-111-1111, 2 = 1-111-111-1111
 * @return A random phone number in a specified format
 *
 * (Examples: if needed)
 */


std::string generatePhoneNumber(int phoneFormatType); // phoneformat type allows you to choose between those 3 diff formats

/*
 * This function generates a random username made of consonants,
 * vowels, and two trailing digits
 *
 * @param length the number of letters in the username (before the digits)
 * @return a random username of the given length
 *
 * (Examples: if needed)
 */
std::string randomName(int length);

/*
 * This function generates a random number within a given range
 * and returns it as a string
 *
 * @param lowerBound the smallest value the number can be
 * @param upperBound the largest value the number can be
 * @return a random number in the given range, as a string
 *
 * (Examples: if needed)
 */
std::string randomNumberInRange(int lowerBound, int upperBound);

/*
 * This function generates a random string of lowercase letters
 *
 * @param length the number of letters in the word
 * @return a random lowercase word of the given length
 *
 * (Examples: if needed)
 */
std::string randomWord(int length);

/*
 * This function generates a random string of uppercase letters
 *
 * @param length the number of letters in the string
 * @return a random uppercase string of the given length
 *
 * (Examples: if needed)
 */
std::string randomCapitalLetter(int length);

/*
 * This function generates a random fake email address
 *
 * @return a random email address
 *
 * (Examples: if needed)
 */
std::string generateEmail();

/*
 * This function generates a random fake street address, city,
 * state, and zip code
 *
 * @return a random address in a specified format
 *
 * (Examples: if needed)
 */
std::string generateAddress();

/*
 * This function generates a random 16 digit test credit card number
 * formatted in groups of 4
 *
 * @return a random test credit card number
 *
 * (Examples: if needed)
 */
std::string generateCreditCard();

/*
 * This function generates a random 3 digit CVV
 *
 * @return a random CVV
 *
 * (Examples: if needed)
 */
std::string generateCVV();

/*
 * This function generates a random expiration date for a credit
 * card in month/year format
 *
 * @return a random expiration date
 *
 * (Examples: if needed)
 */
std::string generateDate();

#endif
