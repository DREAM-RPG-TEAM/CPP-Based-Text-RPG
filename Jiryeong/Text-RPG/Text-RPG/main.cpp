#include <iostream>
#include <stdlib.h>
#include <conio.h>  // Windows ����

#include "Player.h"
#include "DisplayMenu.h"

enum class MENU 
{
	START=1,
	SAVE,
	EXIT
};

enum class ROBBY 
{
	STATUS=1,
	ROOM,
	NPC,
	SECRET_ROOM,
	INVENTORY,
	EXIT,
};

bool CheckChar() 
{
	if (std::cin.fail()) 
	{
		std::cin.clear();
		::system("cls"); // ���� ������ �Լ��� �ƴ�, ������ �Լ���� ::�� �ٿ��� ���
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << std::endl;
	}
	return std::cin.peek() == '\n';
}

void Robby() // inline���� ����x
{
	Player player;
	int input, i_Input;
	ROBBY robby;

	::system("cls");

	while (true)
	{
		::system("cls");

		DisplayMenu::Robby();
		std::cin >> input;
		robby = static_cast<ROBBY>(input);

		if (!CheckChar()) continue;

		switch (robby)
		{
		case ROBBY::STATUS:

			::system("cls");
			DisplayMenu::PlayerStatus(player);
			std::cout << "1. ������" << std::endl;

			while (true) 
			{
				std::cin >> input;
				if (!CheckChar()) continue;
				if (input == 1) break;
			}
			break;
		case ROBBY::ROOM:

			::system("cls");
			DisplayMenu::EntryRoom();

			while (true)
			{
				std::cin >> i_Input;
				if (!CheckChar()) 	continue;
				
				while (true)
				{
					switch (i_Input)
					{
					case 1:
						std::cin >> i_Input;
						if (!CheckChar())	continue;
						
						if (i_Input == 2)
						{
							std::cout << "���� : ���踦 ȹ���Ͽ����ϴ�!" << std::endl;
						}
						else
						{
							std::cout << "�����ϼ̽��ϴ�. �ٽ� �������ּ���......" << std::endl;
						}
					case 2:
						break;
					default:
						break;
					}
				}
			}
			

		case ROBBY::NPC:
		case ROBBY::SECRET_ROOM:
		case ROBBY::INVENTORY:
		case ROBBY::EXIT:
		default:
			std::cout << "~~~~~~~~~�ٽ� �����Ͻÿ�~~~~~~~~" << std::endl << std::endl << std::endl;
			continue;
		}
	}
}

// Game Ŭ������ �����Ͽ� main �Լ��� �����ϰ� ������
/*
int main()
{
	Game game;
	game.Init(); // �ʿ� ��
	game.Run();
	game.Destroy(); // �ʿ� ��

	return 0;
}
*/

int main() 
{
	int input;
	MENU menu;

	// ��ü�� ������ ������ ����
	// DisplayMenu displayMenu;

	while(true)
	{
		::system("cls");

		DisplayMenu::MainMenu();

		std::cin >> input;
		menu = static_cast<MENU>(input);

		if (!CheckChar()) continue; // ���ٷ� ����ϰ�

		switch (menu)
		{
		case MENU::START:
			std::cout << "�Է� : 1. ���ӽ���" << std::endl;
			std::cout << "�κ�� �����Ͻðڽ��ϴ�." << std::endl;
			Robby();
			break;

		case MENU::SAVE :
			std::cout << "�Է� : 2. �� ���� �ҷ�����." << std::endl;
			break;

		case MENU::EXIT:
			std::cout << "�Է� : 3. ���� ������" << std::endl;
			return 0;

		default :
			std::cout << "!!!!!! �ٽ� �������ּ��� !!!!!!!!" << std::endl << std::endl<<std::endl;
			continue;
		}
		std::cout << std::endl << std::endl;
	}

	return 0;
}