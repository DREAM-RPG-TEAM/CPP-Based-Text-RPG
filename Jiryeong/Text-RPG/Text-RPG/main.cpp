#include <iostream>
#include <stdlib.h>
#include <conio.h>  // Windows 전용

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
		::system("cls"); // 내가 정의한 함수가 아닌, 윈도우 함수라고 ::을 붙여서 명시
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "알림: 유효한 숫자를 입력해주세요." << std::endl;
	}
	return std::cin.peek() == '\n';
}

void Robby() // inline으로 정의x
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
			std::cout << "1. 나가기" << std::endl;

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
							std::cout << "정답 : 열쇠를 획득하였습니다!" << std::endl;
						}
						else
						{
							std::cout << "실패하셨습니다. 다시 도전해주세요......" << std::endl;
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
			std::cout << "~~~~~~~~~다시 선택하시오~~~~~~~~" << std::endl << std::endl << std::endl;
			continue;
		}
	}
}

// Game 클래스를 정의하여 main 함수를 간단하게 만들어보자
/*
int main()
{
	Game game;
	game.Init(); // 필요 시
	game.Run();
	game.Destroy(); // 필요 시

	return 0;
}
*/

int main() 
{
	int input;
	MENU menu;

	// 객체로 선언할 이유가 없음
	// DisplayMenu displayMenu;

	while(true)
	{
		::system("cls");

		DisplayMenu::MainMenu();

		std::cin >> input;
		menu = static_cast<MENU>(input);

		if (!CheckChar()) continue; // 한줄로 깔끔하게

		switch (menu)
		{
		case MENU::START:
			std::cout << "입력 : 1. 게임시작" << std::endl;
			std::cout << "로비로 입장하시겠습니다." << std::endl;
			Robby();
			break;

		case MENU::SAVE :
			std::cout << "입력 : 2. 전 게임 불러오기." << std::endl;
			break;

		case MENU::EXIT:
			std::cout << "입력 : 3. 게임 나가기" << std::endl;
			return 0;

		default :
			std::cout << "!!!!!! 다시 선택해주세요 !!!!!!!!" << std::endl << std::endl<<std::endl;
			continue;
		}
		std::cout << std::endl << std::endl;
	}

	return 0;
}