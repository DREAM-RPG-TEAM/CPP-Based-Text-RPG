#pragma once

#include "Player.h"

#include <algorithm>

// ��������� �������� �ʾ� ���� ������ �ʿ� ����, ��¸� ���ִ� Ŭ�����̱� ������ static���� �Լ� ����

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