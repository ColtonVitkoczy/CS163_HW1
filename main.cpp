#include "vitkoczy-colton-prog1.h"
using namespace std;

//Colton Vitkoczy
//CS 163-009
//Karla Fant
//
// The purpose of this File is to be the clieant interface that allows testing on the ADT by reading in user input
int main()
{
	char name[30]; // Array of source names  
	list object;   // declaring an object of th elist class 
	char response = 'N'; // To get user input when going through loops
	//int series_count = 0; 

	series_node * series_head = NULL; // Setting series head pointer to NULL
	series_node * series_tail = NULL; // Setting series tail pointer to NULL

	char series_name[50];       // Array of series names
	char genre[20];             // Array for the genre data types
	float num_seasons = 0;      // float for num of seasons 
	float num_episodes = 0;     // Float for number of episodes
	char fav_actor[30];         // Array for the favorite actor in the series
	
	cout << "Would you like to add a source?: " << endl; // Prompting the user to add in a source
	cin >> response;            // Gettin ghte response
	cin.ignore(100, '\n');
	
	while(toupper(response) == 'Y') // setting the while loop allows them to continue adding in sources
	{
		do  // Start of the do while loop to ensure the source entered doesn't already exist
		{
			cout << "Please insert a source name: ";
			cin.get(name, 30, '\n');
			cin.ignore(100, '\n');
			cout << '\n';

			if(object.check_existing_source(name)) // returns 1 if exists therefore if is true and outputs error
				cout << "ERROR, this name already exists, please re-enter." << endl;

		}while(object.check_existing_source(name)); // making sure we only exit the while loop when a new source is added
		
		object.add_source(name); // funciton to add source name in a LLL

		cout << "Would you like to enter another? "; // Prompting user input for a response variable
		cin >>(response);
		cin.ignore(100, '\n');
	}

	object.display(); // Function call to display all sources in the LLL
	
	cout << "Would you like to enter a series by a specific source? "; // Prompts the user to enter in a series py source
	cin >>(response);
	cin.ignore(100, '\n');

	while(toupper(response) == 'Y')
	{
		// the following get source name input form user
		cout << "Please enter a source name and then add in a series " << endl;
		cin.get(name, 30, '\n');
		cin.ignore(100, '\n');
		// grabs a series name
		cout << "Please insert a series name: ";
		cin.get(series_name, 30, '\n');
		cin.ignore(100, '\n');
		cout <<'\n';
		// grabs a genre
		cout << "Please insert a genre: ";
		cin.get(genre, 30, '\n');
		cin.ignore(100, '\n');
		cout << '\n' ;
		// gets the favorite actor in the series
		cout << "Please insert a favorite actor: " ; 
		cin.get(fav_actor, 30, '\n');
		cin.ignore(100, '\n');
		cout << '\n' ;
		// gets # of seasons
		cout << "Please insert number of seasons: " ;
		cin >> num_seasons;
		cin.ignore(100, '\n');
		cout << '\n' ;
		// gets # of episodes
		cout << "Please insert number of episodes: ";
		cin >> num_episodes;
		cin.ignore(100, '\n');
		cout << '\n' ;
		// The funciton below passes in all the user input then creates a LLL of series for the
		// specific source name passed into the function 
		object.search_sources_add(name, series_name, genre, fav_actor, num_seasons, num_episodes); 
	
		cout << "Would you like to enter another? "; // Allows the user to repeat the previuos steps 
		cin >>(response);
		cin.ignore(100, '\n');
	}

	// Prompts the user to enter a rouce name to display series recommendations
	cout << "Insert a name to display series by a specific source: " ;
	cin.get(name, 30, '\n');
	cin.ignore(100, '\n');

	object.display_all_series(name); // displays all the series recommended by a specific source

	cout << "Insert a source name to remove" ; // Prompts the user to enter in a source name to remove
	cin.get(name, 30, '\n');
	cin.ignore(100, '\n');
		
	object.remove_source(name); // Function the passes in the source name and removes the source node

	cout << "Check to see if source was removed" << endl;
	object.display(); // Displays the LLL of sources after a srouce has been removed

	// Prompts the user to enter in a genre to display
	cout << "Insert a genre to display every item of that particular genre: " ; 
	
	cin.get(genre, 30, '\n');
	cin.ignore(100, '\n');
	cout << '\n' ;
	
	object.display_genre(genre, series_head); // Function call to display every series by a specific genre

	return 0;
}
