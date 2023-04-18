#include "vitkoczy-colton-prog1.h"


// Colton Vitkoczy
// CS163-009
// Karla Fant

// The purpose of this file is to hold all functions in the ADT
// It starts with the source_nodes envoking constructors and destructors as necessary,
// it then does the same thing for the series_nodes. Next, it adds a source to the beggining of a LLL
// after that it creates a function to display all sources, and the next checks to see if that source
// already exists. The rest of the functions so far are stubs or commented out. This file will 
// contain all functions from list class. 



// constructor setting series_tail, series_head, and name ot NULL 
source_node::source_node()
{
	series_tail = NULL;
	series_head = NULL;
	name = NULL;
}
// destructor sets dyanmic memory for name in source node to null,
// then sets a temp node loops through the series nodes and deletes
// each node then sets series_head to temp whic is NULL
source_node::~source_node()
	
{
	if (name)
		delete [] name;
	name = NULL;

	series_node * temp = NULL;
	while (series_head)
	{
		temp = series_head->next;
		delete series_head;
		series_head = temp;
	}
}
//constructor for dyanmic memory in our series struct to NULL along with
//the two float variables this stuct is contained in source_node as a_series  
series::series()
{
	series_name = NULL;
	genre = NULL;
	fav_actor = NULL;
	num_seasons = 0;
	num_episodes = 0;
}

//Destructor sets the dunamic memory in our series struct back to NULL and 
//setes the float sback to 0 
series::~series()
{
	if (series_name)
		delete [] series_name;
	if (genre)
		delete [] genre;
	if (fav_actor)
		delete [] fav_actor;

	series_name = genre = fav_actor = NULL;
	num_seasons = 0;
	num_episodes = 0;

}

//constructor for setting the head and tail pointers back to NULL
list::list()
{
	head = NULL;
	tail = NULL;
}

// Destructor for list goes creates a no pointer of a source_node struct object
// then loops through the LLL of source nodes and deletes memory in each node
// then sets head = temp which is NULL and sets tail to NULL
list::~list()
{
	source_node * temp = NULL;
	while (head)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	tail = NULL;
}

// This function passes a name to add to our source node,
// it starts by creating a new source_node struct then sets the name we passed into
// our function and copys it into the node struct, it then sets temp->next to null
// and goes on to add in the node to the end of the LLL. I did this at the end so
// when we display the LLL it display in the order the user put in their sources
int list::add_source(char name_toadd[])
{
	source_node * temp = new source_node;
	if (!temp) return 0;

	temp->name = new char[strlen(name_toadd) + 1];
	strcpy(temp->name, name_toadd);

	temp->next = NULL;

	if (!head)
	{
		head = tail = temp;
	}

	else
	{
		tail->next = temp;
		tail = tail->next;
	}
	return 1;
}

// Funciton to loop through LLL and display every source
int list::display()
{
	if (!head) return 0;

	source_node * current = head;
	while(current)
	{
		std::cout << current->name << std::endl;
        	current = current->next;
    	}
   	return 1;	
}

// This function is supposed to check and make sure there isn't an existing
// source with the same name, it does so by setting a current pointer traversing
// the LL with a while loop and then checks to see if that name alread exists in 
// and source_node if it does so the function is halted and a 1 is returned 
int list::check_existing_source(char name[])
{
	source_node * current = head;
	while(current)
	{
		if (strcmp(current->name, name) == 0)
		{
			return 1;
		}
		current = current->next;
	}
	return 0;
}

// The following function takes in a name of a source and creates a LLL of series given by that source, placing the data passed into the 
// function from the client. First we check to ensure there is a a LLL of source nodes, then it checks for the condition that
// the LLL of source nodes has only one node in the list and that node contains the matching source name. If this condition is true
// we declare a new series node adds in the data then sets that next arrow to null. After this the function goes into the third condition 
// where we know we have a LLL greater than 1 and we loop through that list comparing if any source name matches the source name passed
// in throgh the function, if so new information is added in a new temp node and that temp node is then appended at the end of
// the LLL of series nodes for that specific name.   
int list::search_sources_add(char name[], char new_series[], char new_genre[],char new_fav_actor[], float new_num_seasons, float new_num_episodes) 
{
	if(head == NULL) return 0;


	if(head->next == NULL && strcmp(head->name, name) == 0)
	{	
		head->series_head = new series_node;

		head->series_head->a_series.series_name = new char[strlen(new_series)+1];
		strcpy(head->series_head->a_series.series_name, new_series);

		head->series_head->a_series.genre = new char[strlen(new_genre)+1];
		strcpy(head->series_head->a_series.genre, new_genre);

		head->series_head->a_series.fav_actor = new char[strlen(new_fav_actor)+1];
		strcpy(head->series_head->a_series.series_name, new_fav_actor);

		head->series_head->a_series.num_seasons = new_num_seasons;	
		
		head->series_head->a_series.num_episodes = new_num_episodes;

		head->series_head->next = NULL;

		return 1;
	}
	
	series_node * temp = new series_node;
	source_node * current = head;

	while(current)
	{
		if(strcmp(current->name, name) == 0)
		{
			temp->a_series.series_name = new char[strlen(new_series)+1];
			strcpy(temp->a_series.series_name, new_series);

			temp->a_series.genre = new char[strlen(new_genre)+1];
			strcpy(temp->a_series.genre, new_genre);

			temp->a_series.fav_actor = new char[strlen(new_fav_actor)+1];
			strcpy(temp->a_series.fav_actor, new_fav_actor);

			temp->a_series.num_seasons = new_num_seasons;	
			
			temp->a_series.num_episodes = new_num_episodes;
			
			temp->next = NULL;

			if (!current->series_tail)
			{
				current->series_tail =current->series_head = temp;
			}

			else
			{
				current->series_tail->next = temp;
				current->series_tail =current->series_tail->next;
			}
		 	return 1;
		}
		current = current->next;
	}

	return 1;
} 

/*
int list::sort_series()                                 // Task 4.b -- Provide a way to sort the series given by a particular source.
{

}
*/
// This function displays all series by a given name passed into the function
// first we set a current pointer of source_node and set equal to head, and 
// a pointer called temp of that set to NULL we start with the outer while loop which
// traverses through the LLL of source_nodes for each node it checks with the if statement
// whether or not there's a match it then sets temp to the current series head and traverses 
// through the LLL of series_nodes and outputs each data member 
int list::display_all_series(char name[])
{
	source_node * current = head;
	series_node * temp = NULL;
	while(current)
	{
		if (strcmp(current->name, name) == 0)
		{
			temp = current->series_head;

			while(temp)
			{
				std::cout << temp->a_series.series_name << std::endl;
				std::cout << temp->a_series.genre << std::endl;
				std::cout << temp->a_series.fav_actor << std::endl;
				std::cout << temp->a_series.num_seasons << std::endl;
				std::cout << temp->a_series.num_episodes << std::endl;
				std::cout << std::endl;
				
				temp = temp->next; 	
			}
		}
		current = current->next;
	}
	return 0;
}

// Tsk 6 remove a particular source from the list
// This function is built to take in a source name from the user and delete that source node
// it first makes sure the LLL isn't empty then, checks to see if theres only one node in the list 
// and checks to see if that one node contains the matching name, if so it deletes that node.
// Next, we set two pointers of source_node, being previuos and current. It then traverses through
// the LLL of sources checking to make sure we've reached the ned of the LLL and that there were no 
// matches. If there are the loop is halted along with the movement of the pointer arrows, thus we 
// can then go in set the node previuos was pointing to, to point to currents next node, and then delete 
// current.  
int list::remove_source(char name[])
{
	if (!head) return 0;

	if (!head->next && strcmp(head->name, name) == 0)
	{
		delete head;
		head = NULL;
		return 1;	
	}

	source_node * previuos = head;
	source_node * current = head->next;
	
	while (current && strcmp(current->name, name) != 0)
	{
		previuos = current;
		current = current->next;
	}
	if(current)
	{
		previuos->next = current->next;
		delete current;
	}
	return 1;
}
// This function takes in a specific genre and outputs each series in the ADT
// that matches that genre. It starts by ensuring the LLL of source nodes is non empty
// then creates two pointers a current for the source node head and a temp for the series_head
// it starts with the outer while loop then immediately traverses though the LLL of series nodes
// and check to see if there's a matching genre then outputs the data in that series if the genre matches  
int list::display_genre(char genre[], series_node * & series_head)
{
	if(!head) return 0;

	source_node * current = head;
	series_node * temp = series_head;

	while(current)
	{
		while(temp)
		{
			if(strcmp(temp->a_series.genre, genre) == 0)
			{
				std::cout << temp->a_series.series_name << std::endl;
				std::cout << temp->a_series.genre << std::endl;
				std::cout << temp->a_series.fav_actor << std::endl;
				std::cout << temp->a_series.num_seasons << std::endl;
				std::cout << temp->a_series.num_episodes << std::endl;
				std::cout << std::endl;
			}
			temp = temp->next;
		}
		current = current->next;
	}
	return 1;
}	
