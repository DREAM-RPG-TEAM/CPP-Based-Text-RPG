#include <iostream>

#include "DisplayMenu.h"

void DisplayMenu::MainMenu() 
{
	std::cout << "=============================" << std::endl;
	std::cout << "          메인 메뉴          " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "1. 게임 시작" << std::endl;
	std::cout << "2. 이전 게임 불러오기" << std::endl;
	std::cout << "3. 게임 나가기" << std::endl;
	std::cout << "=============================" << std::endl;

	std::cout << "선택: ";
}

void DisplayMenu::Robby() 
{
	std::cout << "=============================" << std::endl;
	std::cout << "          메인 로비          " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "1. 플레이어 상태 확인" << std::endl;
	std::cout << "2. 방 탐험" << std::endl;
	std::cout << "3. NPC와의 상호작용" << std::endl;
	std::cout << "4. 비밀의 방 입장" << std::endl;
	std::cout << "5. 인벤토리" << std::endl;
	std::cout << "6. 메인메뉴로" << std::endl;

	std::cout << "=============================" << std::endl;
	std::cout << "선택: ";
}

void DisplayMenu::EntryRoom() 
{
	std::cout << "=============================" << std::endl;
	std::cout << "           방 탐험		   " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "1. 1 번방 입장" << std::endl;
	std::cout << "2. 2 번방 입장" << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "선택: ";

}
void DisplayMenu::Room1() 
{
	std::cout << "=============================" << std::endl;
	std::cout << "           수수꼐끼		   " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "내가 없으면 아무것도 볼 수 없지만, 나는 모든 곳에 존재한다.나는 누구일까 ? " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "1. 빛" << std::endl;
	std::cout << "2. 어둠" << std::endl;
	std::cout << "3. 그림자" << std::endl;
	std::cout << "4. 시간" << std::endl;
	std::cout << "선택: ";
}

void DisplayMenu::Room2() 
{

}

// PlayerStatus함수는 player 참조자를 받아와서 플레이어의 상태를 출력하는 함수.
// 따라서 const 함수가 아닌 함수의 호출을 막아주기
void DisplayMenu::PlayerStatus(const Player& player) 
{
	std::cout << "=============================" << std::endl;
	std::cout << "     플레이어 스테이터스     " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "체력: " << player.GetHP() << std::endl;
	std::cout << "마나: " << player.GetMP() << std::endl;
	std::cout << "방어력: " << player.GetAttackPower() << std::endl;
	std::cout << "공격력: " << player.GetDefensePower() << std::endl;
	std::cout << "=============================" << std::endl;
}