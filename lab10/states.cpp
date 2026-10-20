#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdio>
#include <gtk/gtk.h>

using namespace std;

/**
 * @brief Inserts commas into a string of digits (e.g. "4447100 --> 4,447,100")
 * @param digits C-string of digits to format
 * @param result Output buffer for the formatted C-string; must be large enough
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

/**
 * @brief Splits a comma-separated line into name, abbreviation, and population
 *
 * @param line Input line, e.g. "Alabama,AL,4447100"
 * @param name Output: the state name
 * @param abbr Output: the abbreviation
 * @param population Output: the population digits
 */

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

/**
 * @brief Builds one aligned, formatted row from a state's data
 *
 * @param name The state name
 * @param abbr The two-letter abbreviation
 * @param population The population as a plain digits, e.g. "4447100"
 * @param row Output buffer for the formatted row; must hold at least 100 chars
 */
void formatLine(const char *name, const char *abbr, const char *population, char *row)
{

    char withCommas[20];

    formatWithCommas(population, withCommas); //

    snprintf(row, 100, "%-18s %-6s %12s", name, abbr, withCommas);
    // row is where the text goes (output array)
    // 100 is the max characters (protects for overflow)
    //"%s %s is the template, each %s is a slot that gets filled by one of the follwoing values in order"
    // name, abbr are the values that fill those slots
}

/**
 * @brief Reads every line of the input file, formats it, and writes the rows to the output file
 *
 * @param inName Path of the input file, e.g. "us_states_population.txt"
 * @param outName Path of the output file, e.g. "us_states_population_formatted.txt"
 * @return true if the file was formatted and written; false if a file couldn't be opened
 */

bool processFile(const char *inName, const char *outName)
{
    ifstream in(inName);

    if (!in)
    {
        cout << "Could not open " << inName << endl;
        return false;
    }
    
    ofstream out(outName);

    if (!out)
    {
        cout << "Could not open " << outName << endl;
        return false;
    }


    char line[100];
    char name[50], abbr[5], pop[20], row[100];

    while (in.getline(line, 100))
    {
        parseLine(line, name, abbr, pop);
        formatLine(name, abbr, pop, row);
        out << row << endl;
    }
    return true;
}

/**
 * @brief Runs when the button is clicked; formats the states file and updates the label 
 *
 * @param button The button that was clicked (unused)
 * @param data The GtkLabel to update with a status message
 */
static void onButtonClicked(GtkButton *button, gpointer data)
{
    if (processFile("us_states_population.txt", "us_states_population_formatted.txt"))
    {
        gtk_label_set_text(GTK_LABEL(data), "Done! Wrote us_states_population_formatted.txt");
    }
    else 
    {
        gtk_label_set_text(GTK_LABEL(data), "Error: couldn't open a file.");
    }
}

/**
 * @brief Builds the window and the "Format file" button
 *
 * @param app The GtkApplication that was activated
 * @param user_data Extra data from g_signal_connect (unused)
 */
static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "State Populations");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 150);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

    GtkWidget *label = gtk_label_new("Click the button to format the file");
    GtkWidget *button = gtk_button_new_with_label("Format file");

    g_signal_connect(button, "clicked", G_CALLBACK(onButtonClicked), label);

    gtk_box_append(GTK_BOX(box), button);
    gtk_box_append(GTK_BOX(box), label);
    gtk_window_set_child(GTK_WINDOW(window), box); 

    gtk_window_present(GTK_WINDOW(window));
}

/**
 * @brief Creates the GTK application and runs it
 *
 * @param argc Command-line argument count
 * @param argv Command-line arguments
 * @return Exit status of the application
 */
int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
