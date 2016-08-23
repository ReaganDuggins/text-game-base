// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include <iostream>;
#include <string>;
#include <vector>;
#include <istream>;
#include <sstream>;
#include <iterator>;

using namespace std;

///////////////////////////////////////////

vector<char*> split(char str[]) {
	vector<char*> chars{};
	char * pch;
	pch = strtok(str, "\n");
	chars.push_back(pch);
	while (pch != NULL)
	{
		pch = strtok(NULL, "\n");
		chars.push_back(pch);
	}
	return chars;
}

inline bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}
///////////////////////////////////////////

///////////////////////////////////////////Arc
public class Arc {
	// this class's purpose is to wrap a set of Expositions and Decisions into a neat, easy to traverse list.
	string title;
	vector<Fragment*> arc;
	/*
	// this calls the subclass's tell for each member of arc, so use this to tell each piece of the story
	for (auto frag : arc) {
		frag->tell();
	}
	
	*/
	
public:
	Arc(string ttl, vector<Fragment*> rc) {
		title = ttl;
		arc = rc;
	};
	void tell();
	
};

void Arc::tell() {
	// calls tell() for each story fragment in the arc, using the decisions from Decisions when they are made
	int choice = -1;
	for (auto frag : arc) {
		if (choice == -1) {
			choice = frag->tell();
		}
		else {
			choice = frag->tell(choice);
		}
		
	}
}

/////////////////////////////////////////////Fragment

public class Fragment {
	// this is either a Decision or an Exposition, makes it so they can be in same list (can be extended to other fragments too if needed)
public:
	void tell() {
		cout << "Frag";
	}
};

///////////////////////////////////////////Decision
public class Decision : public Fragment {
	// this class presents a paragraph about a decision, writes the possible decision down (each preceeded by the associated number), takes the
	// player's input on which decision to make, makes sure the input won't cause a crash or anything (asking for redo if needbe), and then
	// calls the method associated with that choice.

public:

	string title;
	string presentation;
	vector<char*> choices;
	
	Decision(string presentn, char choi[]);
	void presentQ(); // present the question
	int decide(); // print choices and prompt to decide
	//void react(int decisionMade); // act on decision (changing variables, etc.)      This is now in its own class
	int tell();
};



Decision::Decision(string presentn, char choi[]) {
	// initialize all the things!
	presentation = presentn;
	choices = split(choi);
};
int Decision::tell() {
	presentQ();
	int decision = decide();
	return decision;
}
void Decision::presentQ() {
	// print presentation to present the choice, then print the choices with their corresponding indeces.
	cout << presentation << "\n";
	for (int i = 0; i < choices.size(); i++) {
		if (choices[i] != NULL) {
			cout << i << ": " << choices[i] << "\n";
		}
	}
	cout << "\n";
};
int Decision::decide() {
	// this method takes the player's decision, tests it, loops input if necessary, then returns the choice (as an int)
	cout << "Your choice? ";
	
	int cho = -1;
	bool badInput = false;
	string chos = "";

	do {
		if (badInput) {// test the input
			cout << "\nTry one of the suggested numbers: ";
			
		}
		
		getline(cin, chos);
		if (isInteger(chos)) {
			cho = stoi(chos);
		}
		else {
			badInput = true;
		}

		
		if (cho < 0 || cho >= choices.size()) {
			cho = -1;
			badInput = true;

		}
	} while (cho == -1);

	return cho; 
};



//////////////////////////////////////////Exposition
public class Exposition : public Fragment {
	// This is simply a large amount of text given to the reader at a reasonable pace.
public:	
	string title;
	vector<char*> paragraphs;
	// eventuall different transitions

	Exposition(vector<char*>);
	void Exposit();
	int tell() {
		return -1;
	}
};


Exposition::Exposition(vector<char*> ps) {
	paragraphs = ps;
}

void Exposition::Exposit()
/// This method prints the Exposition to screen in bite sized chunks, separated by a \n char.
{
	int i = 0;
	for (auto paragraph : paragraphs) {
		if (paragraph != NULL) {
			cout << paragraph << "\n";
			cout << "\n<any key to continue>...\n";
			cin.get();
		}
		i++;
	}
}




int main()
{
	char str[] = "Blargety bloogity\nthis is a story\nand I am testing out\nmy system to see\nif it works!\n:D";
	vector<char*> s = split(str);

	Exposition e( s );
	//e.Exposit();

	char cho[] = "This is the first choice, it's happy.\nChoice two is kinda ominous.\nChoice three is terrible!\nIs choice 4 even really a choice? O.o";
	Decision d("Now it is time to make a decision. Which will you choose? O.o", cho);
	//d.presentQ();
	//cout << ":::::: " << d.decide();

	e.tell();
	cout << endl;
	d.tell();
	cout << endl;
	Exposition* x = &e;
	Decision* y = &d;
	vector<Fragment*> arc;
	arc.push_back(x);
	arc.push_back(y);
	string s = "Blurfen";
	Arc a();
	
	
	return 0;
}


