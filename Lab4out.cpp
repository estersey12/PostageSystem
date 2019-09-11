//Emmanuelle Esters
//Lab4out
//Postage addressing system

#include <iostream>
#include <cstdlib>
#include "graph1.h"

using namespace std;

string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validateCity(string city);
bool validateState(string state);
bool validateZip(string zip);
string convertToUpper(string input);
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight);

int main()
{
	string repeat = "y";
	string fn = " ";
	string ln = " ";
	string addr = " ";
	string city = " ";
	string state = " ";
	string zip = " ";
	int weight = 0;
	string buffer = " ";
	bool res = false;
	string upper;

	displayGraphics();

	do
	{
		do
		{
			//Prompt for the first name - 
			fn = getString("Enter First Name: ");

			//validate the name
			res = validateName(fn);

		} while (!res);
		
		do
		{
			//Prompt for the last name - 
			ln = getString("Enter Last Name: ");

			//validate the name
			res = validateName(ln);

		} while (!res);

		do
		{
			//Prompt for the address 
			addr = getString("Enter Street Address: ");

			//validate the name
			res = validateAddress(addr);

		} while (!res);
		
		do
		{
			//Prompt for the city 
			city = getString("Enter City: ");

			//validate the name
			res = validateCity(city);

		} while (!res);

		do
		{
			//Prompt for the state
			state = getString("Enter State: ");

			//validate the name
			res = validateState(state);

		} while (!res);

		do
		{
			//Prompt for the zip 
			zip = getString("Enter Zip: ");

			//validate the name
			res = validateZip(zip);

		} while (!res);

			do
			{
				//Prompt for the weight 
				buffer = getString("Enter Weight: ");

				//String to int
				weight = stoi(buffer);

			} while ((weight < 1) || (weight > 6));

		//Convert First to Upper
		fn = convertToUpper(fn);

		//covert last to upper
		ln = convertToUpper(ln);

		//covert state to upper
		state = convertToUpper(state);

		//Display
		displayLetter(fn, ln, addr, city, state, zip, weight);



		//Repeat Prompt 
		cout << "Would you like to repeat? (y/n): ";
		getline(cin, repeat);

		clearGraphics();
		system("cls");

	} while (repeat == "y" || repeat == "Y");

	return 0;
}

string getString(string prompt)
{
	string buffer;

	//Prompt user for name using getline (prompt contains the message displayed to user))
	cout << prompt;
	getline(cin, buffer);

	return buffer;
}

bool validateName(string name)
{
	bool res = true;

	//Validate the name – return true if valid, false if not
	for (int i = 0; i < name[i] != NULL; i++)
	{
		if (isalpha(name[i]) == 0)
		{
			
				res = false;
				cout << "Name is invalid. Please re-enter. " << endl;
				break;
			
		}
	}

	return res;
}

bool validateAddress(string address)
{
	bool res = true;

	//Validate the name – return true if valid, false if not
	for (int i = 0; i < address[i] != NULL; i++)
	{
		if (isalpha(address[i]) == 0)
		{
			if (isalnum(address[i]) == 0)
			{

				if (isspace(address[i]) == 0)
				{
					res = false;
					cout << "Address is invalid. Please re-enter. " << endl;
					break;
				}
			}
		}
	}

	return res;
}

bool validateCity(string city)
{

	bool res = true;

	//Validate the name – return true if valid, false if not
	for (int i = 0; i < city[i] != NULL; i++)
	{
		if (isalpha(city[i]) == 0)
		{

			res = false;
			cout << "City is invalid. Please re-enter. " << endl;
			break;

		}
	}

	return res;
}

bool validateState(string state)
{

	bool res = true;

	if (state.length() != 2)
	{
		res = false;

		return res;
	}

	for (int i = 0; i < state[i] != NULL; i++)
	{
		if (isalpha(state[i]) == 0)
		{

			res = false;
			cout << "State is invalid. Please re-enter. " << endl;
			break;

		}
	}
}

bool validateZip(string zip)
{
	bool res = true;

	if (zip.length() != 5)
	{
		res = false;

		return res;
	}

	for (int i = 0; i < zip[i] != NULL; i++)
	{
		if (isdigit(zip[i] == 0))
		{
			res = false;
				cout << "Zip is invalid. Please re-enter. " << endl;
				break;
		}
	}
}

string convertToUpper(string input)
{
	int i = 0;

	//Convert input to all uppercase
	for (i = 0; input[i] != NULL; i++)
	{
		input[i] = toupper(input[i]);
	}

	//Return converted input
	return input;
}

void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight)
{
	//declare variables
	int obj = 0;
	double cost = 0;
	int i = 0;
	int j = 0;

	//draw box
	obj = drawLine(200, 385, 490, 385, 1);
	setColor(obj, 225, 225, 225);
	obj = drawLine(490, 385, 490, 470, 1);
	setColor(obj, 225, 225, 225);
	obj = drawLine(490, 470, 200, 470, 1);
	setColor(obj, 225, 225, 225);
	obj = drawLine(200, 470, 200, 385, 1);
	setColor(obj, 225, 225, 225);

	//display images
	displayBMP("envelope.dib", 0, 0);
	displayBMP("returnAddress.dib", 43, 26);

	//recipient info
	gout << setPos(315, 210) << setColor(0, 0, 0) << fn << " " << ln << endg;
	gout << setPos(315, 230) << setColor(0, 0, 0) << addr << endg;
	gout << setPos(315, 250) << setColor(0, 0, 0) << city << ", " << state << " " << zip << endg;

	//summary box
	cost = weight * .47;

	gout << setPos(205, 400) << setColor(50, 100, 225) << "Weight: " << weight << " ounces" << endg;
	gout << setPos(205, 420) << setColor(50, 100, 225) << "Cost of First Class Stamp: 47 Cents" << endg;
	gout << setPos(205, 440) << setColor(50, 100, 225) << "Total Mailing Cost: $" << setPrecision(2) << cost << endg;

	//display stamps
	switch (weight) {
	case 1: displayBMP("stamp.dib", 525, 20);
		break;
	case 2: displayBMP("stamp.dib", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
		break;
	case 3: displayBMP("stamp.dib", 525, 20);
		displayBMP("stamp.dib", 450, 20);
		displayBMP("stamp.dib", 375, 20);
		break;
	case 4: displayBMP("stamp.dib", 525, 20);
		displayBMP("stamp.dib", 450, 20);
		displayBMP("stamp.dib", 375, 20);
		displayBMP("stamp.dib", 525, 99);
		break;
	case 5: displayBMP("stamp.dib", 525, 20);
		displayBMP("stamp.dib", 450, 20);
		displayBMP("stamp.dib", 375, 20);
		displayBMP("stamp.dib", 525, 99);
		displayBMP("stamp.dib", 450, 99);
		break;
	case 6: displayBMP("stamp.dib", 525, 20);
		displayBMP("stamp.dib", 450, 20);
		displayBMP("stamp.dib", 375, 20);
		displayBMP("stamp.dib", 525, 99);
		displayBMP("stamp.dib", 450, 99);
		displayBMP("stamp.dib", 375, 99);
		break;
	}


}
