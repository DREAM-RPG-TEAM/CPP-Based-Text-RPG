#pragma once

// ���� Ÿ���� ���� ������� ���� ������ ��ӵ� Ű����� �����ؼ� ���ϰ� �� ��!
using uint32 = unsigned int;
using int32 = int;

class Player 
{
private:
	// �̸��� PlayerŬ������ �̸��� �ߺ��Ǿ Player ����
	struct stStatus // PlayerŬ���������� ����ü ���Ǹ� ����� ��� ���⿡ ����
	{
		int hp;
		int mp;
		int attackPower;
		int defensePower;
	};

public:
	Player(); // �⺻������
	Player(int hp, int mp, int attackPower, int defensePower);

	void SetHP(uint32 value);
	void SetMP(uint32 value);
	void SetAttackPower(uint32 value);
	void SetDefensePower(uint32 value);

	// ����¥���� �������ְ� ���⼭ �̷��� ����
	int GetHP() const { return m_status.hp; }
	int GetMP() const { return m_status.mp; }
	int GetAttackPower() const { return m_status.attackPower; }
	int GetDefensePower() const { return m_status.defensePower; }

private:
	stStatus m_status;
};