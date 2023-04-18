#include <iostream>
#include <cctype>
#include <cstring>

//Colton Vitkoczy 
//CS 163-009
//Karla Fant

//The purpose of this .h file is to build the classes and structs required for working with and ADT.
//First a struct is built for the series containing all relevant information that needs to be contained
//about the series. it then creates a series_node invoking the ocnstructors and destructors for the series
//struct, along with a series object called a_series and a pointer node to the next.
//after this a source_node is created containing the name a next arrow and a series_head pointer. Finally,
//The list class is created providing the funtion prototypes that will be used.

// Struct object containing information about aseries
struct series
{
	series(); // constructor
	~series();// destructor
	char * series_name; // pointer for series name
	char * genre;       // pointer for series genre
	float num_seasons;  // declaration for number of seasons in the series
	float num_episodes; // decleration for number of episodes in the series
	char * fav_actor;   // pointer for favorite actor in the series
};

struct series_node
{
	series a_series;    // Creating an object of the series struct
	series_node * next; // Setting a next pointer in the node
};


struct source_node
{
	source_node();      // constructor 
	~source_node();     // destructor
	char * name;        // pointer for a source name
	source_node * next; // next pointer for the source node
	series_node * series_head; // Head pointer contained in each source node for LLL of series
	series_node * series_tail; // Tail pointer contained in each source node for the LLL of series
};

class list
{
	public:
		list(); // constructor
		~list();// destrucotr ~~~~ These are for task 1

		int add_source(char name_toadd[]);    // Task 2.a -- Add a new source, pass in information about the name of new source
		int check_existing_source(char name[]);    // Task 2.b -- Return an error - if this source already exists
		int display();                         // Task 3 -- Display all sources
		int search_sources_add(char name[], char new_series[], char new_genre[], char new_fav_actor[], float new_num_seasons, float new_num_episodes); 
		int sort_series();                                 // Task 4.b -- Provide a way to sort the series given by a particular source.

		int display_all_series(char name[]);               // Task 5 -- Display all series recomended by a particular source
		int remove_source(char name[]); // Task 6 -- Remove a particular source
		int display_genre(char genre[], series_node * & series_head);		// Task 8 -- Display every series by a particular genre 

	private:
		source_node * head; // head pointer
		source_node * tail; // tail pointer

};
	
