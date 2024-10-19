#include <iostream>

#include "DisplayMenu.h"

void DisplayMenu::MainMenu() 
{
	std::cout << "=============================" << std::endl;
	std::cout << "          ���� �޴�          " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "1. ���� ����" << std::endl;
	std::cout << "2. ���� ���� �ҷ�����" << std::endl;
	std::cout << "3. ���� ������" << std::endl;
	std::cout << "=============================" << std::endl;

	std::cout << "����: ";
}

void DisplayMenu::Robby() 
{
	std::cout << "=============================" << std::endl;
	std::cout << "          ���� �κ�          " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "1. �÷��̾� ���� Ȯ��" << std::endl;
	std::cout << "2. �� Ž��" << std::endl;
	std::cout << "3. NPC���� ��ȣ�ۿ�" << std::endl;
	std::cout << "4. ����� �� ����" << std::endl;
	std::cout << "5. �κ��丮" << std::endl;
	std::cout << "6. ���θ޴���" << std::endl;

	std::cout << "=============================" << std::endl;
	std::cout << "����: ";
}

void DisplayMenu::EntryRoom() 
{
	std::cout << "=============================" << std::endl;
	std::cout << "           �� Ž��		   " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "1. 1 ���� ����" << std::endl;
	std::cout << "2. 2 ���� ����" << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "����: ";

}
void DisplayMenu::Room1() 
{
	std::cout << "=============================" << std::endl;
	std::cout << "           ��������		   " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "���� ������ �ƹ��͵� �� �� ������, ���� ��� ���� �����Ѵ�.���� �����ϱ� ? " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "1. ��" << std::endl;
	std::cout << "2. ���" << std::endl;
	std::cout << "3. �׸���" << std::endl;
	std::cout << "4. �ð�" << std::endl;
	std::cout << "����: ";
}

void DisplayMenu::Room2() 
{

}

// PlayerStatus�Լ��� player �����ڸ� �޾ƿͼ� �÷��̾��� ���¸� ����ϴ� �Լ�.
// ���� const �Լ��� �ƴ� �Լ��� ȣ���� �����ֱ�
void DisplayMenu::PlayerStatus(const Player& player) 
{
	std::cout << "=============================" << std::endl;
	std::cout << "     �÷��̾� �������ͽ�     " << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "ü��: " << player.GetHP() << std::endl;
	std::cout << "����: " << player.GetMP() << std::endl;
	std::cout << "����: " << player.GetAttackPower() << std::endl;
	std::cout << "���ݷ�: " << player.GetDefensePower() << std::endl;
	std::cout << "=============================" << std::endl;
}