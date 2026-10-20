#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

/**
 * @brief Inserts commas into a string of digits (e.g. "4447100 --> 4,447,100")
 * @param digits C-string of digits to format
 * @param result Output buffer for teh formattted C-string; must be large enough
 *               for the digits, the commas, and the '\0'.
 */

void formatWithCommas(const char *digits, char *result)
{
    int len = strlen(digits);
    int j = 0; // where we put the result

    for (int i = 0; i < len; i++)
    {
        if (i > 0 && (len - i) % 3 == 0)
        {
            result[j++] = ','; // puts a comma into the result j
        }
        result[j++] = digits[i];
    }
    result[j] = '\0';
}

void parseLine(const char *line, char *name, char *abbr, char *population)
{
    char copy[100]; // allocate 100 chars of memory

    if (strlen(line) >= 100) // extra check for overflow
    {
        name[0] = abbr[0] = population[0] = '\0'; // leave the outputs empty
        return;                                   // stop here don't copy it
    }

    strcpy(copy, line); // fills the first slots with the line's characters
                        // and adds the \0 right after the last one

    char *token = strtok(copy, ","); // this looks inside "copy" for the first comma
                                     // and replaces it with a \0 to end it
    strcpy(name, token);

    token = strtok(nullptr, ","); // nullptr means no new string, so just conitnue from
                                  // where you stopped before, so like Alabama to AL
    strcpy(abbr, token);

    token = strtok(nullptr, ","); // same thing here, nullptr and population
    strcpy(population, token);
}

int main()
{
    char name[50], abbr[5], pop[20], formatted[20];

    parseLine("New Hampshire,NH,1235786", name, abbr, pop);
    formatWithCommas(pop, formatted);

    cout << name << endl;
    cout << abbr << endl;
    cout << formatted << endl;
    return 0;
}
