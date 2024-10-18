#pragma once

#include "Player.h"

#include <algorithm>

// 멤버변수가 존재하지 않아 상태 관리가 필요 없는, 출력만 해주는 클래스이기 때문에 static으로 함수 정의

class DisplayMenu 
{
public:
	static void PlayerStatus(const Player& player);
	static void Robby();
	static void EntryRoom();
	static void Room1();
	static void Room2();
	static void MainMenu();
};