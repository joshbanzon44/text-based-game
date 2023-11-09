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
	cout << "You are an archaeologist who's been studying the ancient Egyptian gods. Ra,\n" <<
		"the God of the Sun and Egypt's first pharaoh, " << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "You find yourself at the base of an Egyptian pyramid. An open door lies\nahead of you." << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	string input;
	cin >> input;
	cin.clear();
	cout << "----------------------------------------------------------------------------" << endl;

	

	while (input.find("quit") == string::npos)
	{
		if (input.find("enter") != string::npos || input.find("forward") != string::npos || input.find("in") != string::npos)
		{
			cout << "As you pass through the imposing entrance of the pyramid, a cool draft of air welcomes you into the ancient structure. The room has \nfour doors, one in each direction. Suddenly,"
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

	//Initialize player
	Player player;

	//Initialize weapons 
	//Name, type, description, size, power, accuracy
	Weapon sword("Rusty Sword", "sword", "A dull weapon. Found at a previous dig site to\n	be kept as an antique.", 3, 5, 85); //Starting sword

	Weapon axe("Axe of Death", "axe", "Weapon of choice for an executioner, with the\n	word 'DEATH' engraved in its handle.", 5, 12, 60);
	axe.setFindStr("Against the block, leans a mighty axe. Dull from its use, and covered in black, dried blood.");
	Weapon spear("Bronze-Tipped Spear","spear","Long handled weapon with a sharp but small bronze tip.\n	Easy to use and keep your distance, but not the most effective.",9,9,80);
	spear.setFindStr("One weapon remains hung on the wall, a spear. It was the weapon of choice for the armies of Egypt.");
	Weapon mace("Morning Star","mace","Two-handed, spiked weapon designed to break\n	swords and even the strongest armor. Almost too heavy to wield.",5,20,45);
	mace.setFindStr("In the corner of your eye, you notice a handle under a fallen shield. You kick the\nshield to reveal a large, spiked metal ball at the end of it.");
	Weapon dagger("Copper Dagger","dagger","A small copper blade with a wooden handle.\n	Likely used as a tool by its predecessors, but doubles as a weapon.",2,5,95);
	dagger.setFindStr("While almost all booths contain nothing of use, you notice a copper dagger on the counter of a mason's stand.");
	Weapon khopesh("Royal Saber","khopesh","A curved/sickle-shaped sword native to the\n	Egyptians. Used in ancient warface for deadly close quartered combat, or a symbol of power.", 7,15,85);
	khopesh.setFindStr("On the wall, hangs a silver sword with a golden handle. Sharp and jeweled, the blade looks fit for a king.");

	//Initialize items
	//Name, type, description, size, health increase, max health increase
	Item rock("Rock", "rock", "a small rock.", 1, -1, 0, false);	//Starting item

	Item potion1("Elixir of Life", "potion", "Pink, glowing liquid that holds unseen power.\n	Magically imbued with the life of others.", 3, 5, 25);
	potion1.setFindStr("Beneath the rubble of a decayed statue, a glass bottle emits a bright pink light.");
	Item potion2("Elixir of Healing", "potion", "Nutritional and restorative liquid used to keep\n	warriors in the battle.", 3, 40, 0);
	potion2.setFindStr("One bottle rack hangs in the corner of the room with a single\nbottle. On it, sits a sealed liquid with the label 'SEKHEM.'");
	Item defib("Defibrillator", "device", "A weak and old defibrillator. Could be used to\n	spark adrenaline.", 6, 50, -10);
	defib.setFindStr("Attached to the dead travelers chest are two sticky pads with wires leading to a device. In its decent condition, it could still work.");
	Item apple("Apple", "food", "An apple! It has been a while since you've eaten. But, how did an apple get here?", 2, 7, 0);
	apple.setFindStr("On a small table in the corner, a bright red apple sits. It's a wonder how it got there.");

	//Boss item
	Item ankh("Ra's Ankh","ankh","Egyptian symbol of life. Wooden totem, t-shaped and topped by a\ndroplet-shaped loop. The engravings on it are of a language beyond history.", 1 , 0, 0, false);

	//Initialize enemies
	//Name, type, health, power, accuracy
	Enemy leopard("Akin the Protector", "sphinx", 9, 5, 50);
	leopard.setFindStr("In the center of the room, a majestic sphinx rests, its eyes seemingly following your every move.");
	Enemy skeleton("Judas the Forgotten", "skeleton", 15, 3, 40);
	skeleton.setFindStr("As you enter, the remains of a temple guard begin to reanimate. An armored\nskeleton of the abandoned body rises and guards the room.");
	Enemy scribe("Dedi the Wicked", "scribe", 20, 4, 60);
	scribe.setFindStr("Surrounded by candles and hieroglyphs drawn in blood, a scribe sits in the center of the room. They radiate a feeling of malice.");
	Enemy lancer("Bomani the Undead","lancer",30,7,60);
	lancer.setFindStr("The lid of a sarcophagus with a depiction of a horse slides off and falls to the\nground. From the dead arises a fallen lancer, ready to fight once again.");

	//Boss
	Enemy ra("Ra, God of the Sun", "Ra", 100, 10, 65);
	ra.setFindStr("Upon the throne sits a man with the head of a falcon and a sun shaped crown. He wields a\nsceptor of gold in one hand, and wooden ankh in the other.");

	//Initialize rooms
	Room rooms[5][4];
	
	//Loop to set all rooms in 2D array
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
				setRoom.setString("The walls of this room are adorned with faded hieroglyphs, telling tales of pharaohs and gods.\nA dim glow emanates from a few torches. The air is thick with a sense of mystery, and the stone underfoot bears the weight of centuries.");
			}

			//Set room in the 2D array
			rooms[x][y] = setRoom;
		}
	}

	//Set empty room entrance strings
	rooms[0][0].setString("You enter an empty room. The variance of fade on the floor tells you whatever\nwas here was either moved, or taken.");
	rooms[1][1].setString("You enter a cracked room where debris fell from the ceiling and smashed the ground in the\ncenter of the room. Time has laid waste to this room and leaves it unidentifiable.");
	rooms[2][3].setString("You enter a tall but empty room. Faded art covers only half the ceiling and\nscaffolding blocks one of the doors. Who knows why they never finished.");
	rooms[3][1].setString("You enter a room with what looks like a well in the center. Thirsty and excited,\nyou run to it only to find it dry. You can't remember the last time you had water.");
	rooms[4][2].setString("You enter an empty room. The variance of fade on the floor tells you whatever\nwas here was either moved, or taken.");

	//Set enemies in rooms and related entrance string
	rooms[2][1].setEnemy(leopard);
	rooms[2][1].setString("You find yourself in an cavern with walls carved with ancient\nsymbols. It seems as though they never carved it like the rest of the rooms.\nThe air is tinged with an otherworldly energy, and the flickering torchlight casts eerie shadows.");

	rooms[0][2].setEnemy(skeleton);
	rooms[0][2].setString("You enter a room with an empty altar in the middle. Beside it, the body of a guard lay. He must've given his life to protect whatever was there.");

	rooms[4][0].setEnemy(scribe);
	rooms[4][0].setString("You step into a vast room filled with towering shelves of ancient scrolls and papyrus. The air is thick with\nthe musty scent of knowledge.");

	rooms[1][3].setEnemy(lancer);
	rooms[1][3].setString("Dimly lit torches cast eerie shadows on the stone walls adorned with funerary paintings.\nSarcophagi, some cracked open, line the chamber, and an unsettling silence hangs in the air.");

	rooms[3][3].setEnemy(ra);
	rooms[3][3].setString("You enter a royal chamber. Almost everything present is trimmed or made entirely of gold. Paintings and shrines\ndepict legendary battles, but all share a single character, Ra. At the North side of the room, a throne sits.");

	//Set weapons in rooms and related entrance string
	rooms[3][2].setWeapon(axe);
	rooms[3][2].setString("You enter what must've been an execution chamber. Benches round the room with a large stone\nin the center while a wheeled guillotine rests in the corner. The atmosphere instills fear in you.");

	rooms[0][3].setWeapon(khopesh);
	rooms[0][3].setString("Upon entering, you find a secret chamber with walls adorned with precious jewels and golden artifacts. A mysterious aura fills the air, and a single flickering torch barely illuminates the room.");

	rooms[4][1].setWeapon(spear);
	rooms[4][1].setString("You enter an abandoned armory. The solemn stillness of the room whispers tales of\nbattles long gone, now only echoes in the hollow chambers of this forsaken arsenal.");

	rooms[1][0].setWeapon(dagger);
	rooms[1][0].setString("You're surrounded by abandoned stalls laden with exotic spices, colorful fabrics, and\nintricate trinkets. The stalls have vibrant tapestries, creating a lively aura of sights and sounds.");

	rooms[1][2].setWeapon(mace);
	rooms[1][2].setString("Upon entering, your senses are overwhelmed by the scent of oiled metal and leather. An\narmory with shelves of shields lines the wall. All the weapons seem to be missing.");

	//Set items in rooms and related entrance string
	rooms[4][3].setItem(potion1);
	rooms[4][3].setString("Statues line the room you enter, each of a different Egyptian god. However breath-taking, the\ntowering statues did not stand the test of time. Many are eroded and their details faded.");

	rooms[2][2].setItem(potion2);
	rooms[2][2].setString("As you enter, you're surrounded by an array of empty vials, jars, and mysterious contraptions.\nStrange symbols are etched into the wooden tables, and ancient scrolls containing alchemical secrets line the shelves.");

	rooms[3][0].setItem(apple);
	rooms[3][0].setString("You enter into a large dining quarter. Tables, chairs, and benches line the room with two\nlarge, clay pots over a piles of ash. You imagine how lively this place must've been when it was full.");

	rooms[0][1].setItem(defib);
	rooms[0][1].setString("A horrifying smell retches you as the door opens. Dread fills your body as you\nenter this room and see a decaying body of a past traveler. You realize\nhis poor fate may not differ from your own.");

	//Give player starting items
	player.get(sword);
	player.get(rock);

	system("cls");

	//Title Screen
	cout << "----------------------------------------------------------------------------" << endl;

	cout <<
		 "   	     _______ _______ _______  _____         _______\n" <<
		 "   		|    |______ |  |  | |_____] |      |______\n" <<
		 "   		|    |______ |  |  | |       |_____ |______\n" <<
		     
		 "   			 _____  _______\n" <<
		 "   			|     | |______\n" <<
		 "   			|_____| |\n" <<
		 "   			______	 _______\n" <<
		 "   			|_____/  |_____|\n" <<
		 "   			|     |  |     |\n" << endl;
	//https://patorjk.com/software/taag/#p=testall&f=Blocks&t=ZORK%204
	//ANSI Regular
	cout << "		Created By: Josh Banzon and Blayne Mastrangelo" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Welcome to our text based adventure game! Try to answer with one word and" << endl;
	cout << "		typing 'quit' at anytime will end the game. " << endl;
	cout << "			Have fun and enjoy!" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Explore the entire pyramid, defeat all enemies, and escape the temple of Ra!" << endl;
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

					if (currentRoom.getEnemy().type == "Ra")
					{
						cout << "As he falls to his knees, his body begins to disintegrate quickly. In seconds, \nall that remains is a pile of dust and his wooden ankh." << endl;
						cout << "----------------------------------------------------------------------------" << endl;
						cout << "You pick up the ankh." << endl;
						cout << "----------------------------------------------------------------------------" << endl;
					}

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
				cout << "You pick up the " << currentRoom.getItem().type << "." << endl;
				cout << "----------------------------------------------------------------------------" << endl;
			}
			else if ((input.find("get") != string::npos || input.find("pick") != string::npos) && currentRoom.hasWeapon)	//Pick up weapon
			{
				player.get(currentRoom.getWeapon());
				currentRoom.hasWeapon = false;

				cout << "You pick up the " << currentRoom.getWeapon().type << "." << endl;
				cout << "----------------------------------------------------------------------------" << endl;
			}
			else if (input.find("get") != string::npos || input.find("pick") != string::npos)	//Try to pick up item but no item in room
			{
				cout << "There are not any items to pick up." << endl;
			}
			else if (input.find("open") != string::npos || input.find("inv") != string::npos || input.find("backpack") != string::npos)		//Sneak
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
		if (exitNotif && roomsVisited >= 10 && enemiesDefeated >= 5)
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
				"\nin the room you entered from. A sense of relief fills your mind knowing you\nare finally free." << endl;
			cout << "----------------------------------------------------------------------------" << endl;
			cout << "Are you ready to leave?" << endl;
			cin >> input;
			cin.clear();
			cout << "----------------------------------------------------------------------------" << endl;

			if (input.find("yes") != string::npos || input.find("y") != string::npos || input.find("please") != string::npos)
			{
				cout << "You have walk out of the pyramid and see a group of wanders. With what\nenergy you still possess, you take off"
					<< " towards them and explain who you are.\nThey take you in and guide you back to your camp. You believe life will\nreturn to normal,"
					<< " until the sun sets and the wooden ankh you kept from Ra\nbegins to glow..." << endl << endl;
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
				cout << "You're unsure of your decision, but the fear this place strikes into you\nforces you to leave. ";
				cout << "You have walk out of the pyramid and see a group of \nwanders. With what energyyou still possess, you take off"
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

