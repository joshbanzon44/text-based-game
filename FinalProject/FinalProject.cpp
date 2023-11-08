#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <tuple>
#include "Item.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Entity.h"
#include "Player.h"
#include "Room.h"

using namespace std;

bool openingFunction()
{
	cout << "----------------------------------------------------------------------------" << endl;


	cout << "Opening introduction/story/setting goes here" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "You find yourself at the base of an Egyptian pyramid. \nAn open door lies ahead of you." << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	string input;
	cin >> input;
	cin.clear();
	cout << "----------------------------------------------------------------------------" << endl;

	

	while (input.find("quit") == string::npos)
	{
		if (input.find("enter") != string::npos || input.find("forward") != string::npos || input.find("in") != string::npos)
		{
			cout << "You walk into the dark corridor of the pyramid's entrance. The room has \nfour doors, one in each direction. As you enter,"
				<< " the entrance to the pyramid \nbehind you slams shut.\n" << endl;
			return false;
		}
		if (input.find("leave") != string::npos || input.find("away") != string::npos || input.find("left") != string::npos || input.find("right") != string::npos)
		{
			cout << "It's too dark to head anywhere else. The only way seems in." << endl;
			cout << "----------------------------------------------------------------------------" << endl;
		}
		else
		{
			cout << "Not sure what you meant by that. Try a different wording." << endl;
			cout << "----------------------------------------------------------------------------" << endl;
		}

		cin >> input;
		cin.clear();
		cout << "----------------------------------------------------------------------------" << endl;
	}

	return true;
}


int main()
{
	//Set seed for random number generation for entire program
	srand((unsigned)time(NULL));

	//Variable constraints
	/*
	* Accuracy: 1-100
	* Power: 1-20
	* Size: 1-20
	*
	* //Weapon constructor
	*  objName(Name, WeaponType, Description, Size, Power, Accuracy)
	*
	*/

	//Initialize player
	Player player;

	//Initialize weapons 
	//Name, type, description, size, power, accuracy
	Weapon sword("Rusty sword", "sword", "A dull weapon. Found at a previous dig site to be kept as an antique.", 3, 5, 85); //Starting sword

	Weapon axe("Axe of Death", "axe", "Weapon of choice for an executioner, with the word 'DEATH' engraved in its handle.", 5, 12, 60);
	axe.setFindStr("A thick stone block sits in the center of the room. Against it leans a mighty axe.");
	Weapon spear("Bronze-Tipped Spear","spear","Long handled weapon with a sharp but small bronze tip. \nEasy to use and keep your distance, but not the most effective.",9,9,80);
	spear.setFindStr("");
	Weapon mace("Morning Star","mace","Two-handed, spiked weapon designed to break swords and even the strongest armor. Almost too heavy to wield.",5,20,45);
	mace.setFindStr("");
	Weapon dagger("Copper Dagger","dagger","A small copper blade with a wooden handle. Likely used as a tool by its predecessors, but doubles as a weapon.",2,5,95);
	dagger.setFindStr("");
	Weapon khopesh("Royal Saber","khopesh","A curved/sickle-shaped sword native to the Egyptians. Used in ancient warface for deadly close quartered combat, or a symbol of power.", 7,15,85);
	khopesh.setFindStr("");

	//Initialize items
	//Name, type, description, size, health increase, max health increase
	Item rock("Rock", "rock", "a small rock.", 1, -1, 0);	//Starting item

	Item potion1("Elixir of Life", "potion", "Pink, glowing liquid that holds unseen power. Magically imbued with the life of others.", 3, 5, 25);
	potion1.setFindStr("Beneath the rubble of a decayed statue, a glass bottle emits a bright pink light.");
	Item potion2("Elixir of Healing", "potion", "Nutritional and restorative liquid used to keep warriors in the battle.", 3, 40, 0);
	potion2.setFindStr("");
	Item defib("Defibrillator", "device", "An weak and old defibrillator. Could be used to spark adrenaline.", 6, 50, -20);
	defib.setFindStr("");
	Item apple("Apple", "food", "An apple! It has been a while since you've eaten.", 2, 7, 0);
	apple.setFindStr("");

	//Initialize enemies
	//Name, type, health, power, accuracy
	Enemy leopard("Akin the Protector", "leopard", 9, 5, 50);
	leopard.setFindStr("In the middle of the room, something covered in what appears as black rosettes rests. Upon closer look, you\nrealize the rose shaped spots and the cream/orange background create the pattern of a large feline.");
	Enemy skeleton("Judas the Forgotten", "skeleton", 15, 3, 40);
	skeleton.setFindStr("As you enter, the remains of a temple guard begin to reanimate. An armored skeleton\nof the abandoned body rises and guards the room.");
	Enemy scribe("Dedi the Wicked", "scribe", 20, 4, 60);
	scribe.setFindStr("");
	Enemy lancer("Bomani the Undead","lancer",30,7,60);
	lancer.setFindStr("");

	//Boss
	Enemy ra("Ra, God of the Sun", "Ra", 100, 10, 65);
	ra.setFindStr("Upon the throne sits a man with the head of a falcon and a sun shaped crown. He wields a \nsceptor of gold in one hand, and wooden ankh in the other.");

	//Initialize rooms
	Room rooms[5][4];
	
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			Room setRoom(x, y);
			string s = "This is room (" + to_string(x) + "," + to_string(y) + ").";
			setRoom.setString(s);

			if (x == 2 && y == 0) //Specifically set the first room differently
			{
				setRoom.setFirstRoom(true);
				setRoom.setString("This is the first room");
			}

			rooms[x][y] = setRoom;
		}
	}

	//Set room entrance strings




	//Set enemies in rooms
	rooms[2][1].setEnemy(leopard);
	rooms[0][2].setEnemy(skeleton);
	rooms[4][0].setEnemy(scribe);
	rooms[1][3].setEnemy(lancer);
	rooms[3][3].setEnemy(ra);

	//Set weapons in rooms
	rooms[1][0].setWeapon(axe);


	//Set items in rooms
	rooms[3][0].setItem(potion1);


	//Give player starting items
	player.get(sword);
	player.get(rock);

	system("cls");

	//Title Screen
	cout << "----------------------------------------------------------------------------" << endl;

	cout <<
		"		███████  ██████  ██████  ██   ██     ██   ██\n" <<
		"		   ███  ██    ██ ██   ██ ██  ██      ██   ██\n" <<
		"		  ███   ██    ██ ██████  █████       ███████\n" <<
		"		 ███    ██    ██ ██   ██ ██  ██           ██\n" <<
		"		███████  ██████  ██   ██ ██   ██          ██"
		<< endl;
	//https://patorjk.com/software/taag/#p=testall&f=Blocks&t=ZORK%204
	//ANSI Regular
	cout << "		Created By: Josh Banzon and Blayne Mastrangelo" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Welcome to our text based adventure game! Try to answer with one word and" << endl;
	cout << "		typing 'quit' at anytime will end the game. " << endl;
	cout << "			Have fun and enjoy!" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Explore the entire pyramid, defeat all enemies, and escape the Wrath of Ra!" << endl;
	cout << "----------------------------------------------------------------------------" << endl;


	int start = 0;
	cout << "Enter any number to start (0 to quit): " << endl;
	cin >> start;

	if (start == 0)
	{
		cout << "Exiting game... Thank you for playing!" << endl;
		exit(0);
	}
	system("cls");

	//If they enter quit, set x to 0. Else, set to 1
	bool quit = openingFunction(); //Function to establish plot, introduce game, and enter pyramid.
	if (quit == true)
	{
		cout << "Exiting game... Thank you for playing!" << endl;
		exit(0);
	}


	//Initialize global variables for game
	tuple <int, int, char> XYDirection;
	string input;
	int roomsVisited = 0; //Keep track of how many rooms the player has entered. Must explore all 20 before the door opens.
	int enemiesDefeated = 0; //Keep track of enemies defeated
	bool exitNotif = true;
	bool canExit = false;
	bool win = false;

	//Coorindations and direction for first room
	XYDirection = make_tuple(2, 0, 'S');

	//Enter the first room
	Room currentRoom = rooms[get<0>(XYDirection)][get<1>(XYDirection)];
	currentRoom.enter(get<2>(XYDirection));
	if (!currentRoom.hasBeenVisited())
	{
		roomsVisited++;
		currentRoom.visit();
	}
	cout << "----------------------------------------------------------------------------" << endl;


	while (input.find("quit") == string::npos)	//Loop for each room
	{
		cin >> input;
		cin.clear();
		cout << "----------------------------------------------------------------------------" << endl;

		//Loop in each room
		while (true)
		{
			if (input.find("quit") != string::npos)
			{
				break;
			}
			else if (input.find("leave") != string::npos)		//Leave room
			{
				cout << "You decide to leave this room." << endl;
				break;
			}
			else if (currentRoom.hasEnemy && (input.find("fight") != string::npos || input.find("attack") != string::npos))	//Fighting
			{
				cout << "You find yourself face to face with " << currentRoom.getEnemy().name << "." << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cout << "Are you ready?" << endl;
				cin >> input;
				cin.clear();

				//Give player option to fight or leave
				bool ready = false;
				while (!ready)
				{
					if (input.find("quit") != string::npos)
					{
						break;
					}
					else if (input.find("ready") != string::npos || input.find("y") != string::npos || input.find("go") != string::npos)
					{
						ready = true;
						continue;
					}
					else if (input.find("n") != string::npos || input.find("leave") != string::npos || input.find("run") != string::npos)
					{
						cout << "You flee from " << currentRoom.getEnemy().name << "." << endl;
						break;
					}
					else
					{
						cout << "Not sure what you meant by that." << endl;
					}
					cout << "----------------------------------------------------------------------------" << endl;
					cin >> input;
					cin.clear();
					cout << "----------------------------------------------------------------------------" << endl;

				}

				if (input.find("quit") != string::npos || input.find("n") != string::npos || input.find("leave") != string::npos || input.find("run") != string::npos)
				{
					break;
				}

				bool win;
				if (ready)
				{
					win = player.fight(currentRoom.getEnemy()); // Fight the enemy in this room
				}

				if (!win)
				{
					input = "quit";
					break;
				}
				else
				{
					currentRoom.hasEnemy = false;
					enemiesDefeated++;
					cout << "----------------------------------------------------------------------------" << endl;
					cout << "You defeated " << currentRoom.getEnemy().name << "." << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					currentRoom.entranceStr();
					cout << "----------------------------------------------------------------------------" << endl;
				}
			}
			else if (input.find("fight") != string::npos || input.find("attack") != string::npos)  //Try to fight but no enemy in room
			{
				cout << "There's nothing to fight in here." << endl;
			}
			else if ((input.find("get") != string::npos || input.find("pick") != string::npos) && currentRoom.hasItem)	//Pick up item
			{
				player.get(currentRoom.getItem());
				currentRoom.hasItem = false;
				cout << "You pickup the " << currentRoom.getItem().type << "." << endl;
				cout << "----------------------------------------------------------------------------" << endl;
			}
			else if ((input.find("get") != string::npos || input.find("pick") != string::npos) && currentRoom.hasWeapon)	//Pick up weapon
			{
				player.get(currentRoom.getWeapon());
				currentRoom.hasWeapon = false;

				cout << "You pickup the " << currentRoom.getWeapon().type << "." << endl;
				cout << "----------------------------------------------------------------------------" << endl;
			}
			else if (input.find("get") != string::npos || input.find("pick") != string::npos)	//Try to pick up item but no item in room
			{
				cout << "There are not any items to pickup." << endl;
			}
			else if (input.find("open") != string::npos || input.find("inv") != string::npos || input.find("back") != string::npos)		//Sneak
			{
				system("cls");
				player.openInventory();
				cout << "You close your backpack and return to the room." << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				currentRoom.entranceStr();
				cout << "----------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "We did not understand what you said. Try a different wording." << endl;
			}
			cin >> input;
			cin.clear();
			cout << "----------------------------------------------------------------------------" << endl;
		}
		
		if (input.find("quit") != string::npos)
		{
			continue;
		}

		//Pick which room to go to next
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Which way do you want to go? (forward, backward, left, right) " << endl;
		cin >> input;
		cin.clear();
		while (input.find("quit") == string::npos && input.find("forward") == string::npos && input.find("backward") == string::npos && input.find("right") == string::npos && input.find("left") == string::npos)
		{
			cout << "----------------------------------------------------------------------------" << endl;
			cout << "Invalid direction. Enter one of the four options or quit." << endl;
			cout << "----------------------------------------------------------------------------" << endl;
			cin >> input;
			cin.clear();
		}

		if (input.find("quit") != string::npos)
		{
			continue;
		}

		XYDirection = currentRoom.nextRoom(input); 
		currentRoom = rooms[get<0>(XYDirection)][get<1>(XYDirection)]; //Set next room
		cout << "----------------------------------------------------------------------------" << endl;
		currentRoom.enter(get<2>(XYDirection));
		if (!currentRoom.hasBeenVisited())
		{
			roomsVisited++;
			currentRoom.visit();
		}
		cout << "----------------------------------------------------------------------------" << endl;

		//If they visit all 20 rooms, allow player to leave.
		if (roomsVisited >= 10 && enemiesDefeated >= 5 && exitNotif)
		{
			canExit = true;
			exitNotif = false;
			cout << "A metallic knocking begins, like gears turning. A door opens elsewhere." << endl;
			cout << "----------------------------------------------------------------------------" << endl;
		}


		if (canExit && currentRoom.isFirstRoom())
		{
			//Allow player to leave pyramid and win
			cout << "You feel the outside breeze and see an opened door. You realize you're back" << 
				"\nin the room you entered into. A sense of relief fills your mind knowing you are \nfinally free." << endl;
			cout << "----------------------------------------------------------------------------" << endl;
			cout << "Are you ready to leave?" << endl;
			cin >> input;
			cin.clear();
			cout << "----------------------------------------------------------------------------" << endl;

			if (input.find("yes") != string::npos || input.find("y") != string::npos || input.find("please") != string::npos)
			{
				cout << "You have walk out of the pyramid and see a group of wanders. With what energy\nyou still possess, you take off"
					<< " towards them and explain who you are. They take you in\nand guide you back to your camp. You believe life will return to normal,"
					<< " until the sun sets and the wooden ankh you kept from Ra begins to glow..." << endl << endl;
			}
			else if (input.find("no") != string::npos || input.find("stay") != string::npos || input.find("dont") != string::npos)
			{
				cout << "After everything you've fought and experienced in the pyramid, you decide you can no longer continue.\nThe injuries sustained"
					<< " and mental toll the expedition left on you leave you helpless only steps\nfrom rescue. As you feel the life fading from your body," 
					<< " you feel a warming sensation in your\nhand. You look and see the wooden ankh glowing and filling your body with a heat" <<
					"you've never felt. Maybe Ra can never be truly defeated..." << endl << endl;
			}
			else
			{
				cout << "You're unsure of your decision, but the fear this place strikes into you forces you to leave." << endl;
				cout << "You have walk out of the pyramid and see a group of wanders. With what energy\nyou still possess, you take off"
					<< " towards them and explain who you are. They take you in\nand guide you back to your camp. You believe life will return to normal,"
					<< " until the sun sets and the wooden ankh you kept from Ra begins to glow..." << endl << endl;
			}
			win = true;
			break;
		}
	}

	cout << "Game over!" << endl;
	if (win)
	{
		cout << "Congratulations! You beat the game!" << endl;
	}
	else
	{
		cout << "Try again sometime!" << endl;
	}
}

