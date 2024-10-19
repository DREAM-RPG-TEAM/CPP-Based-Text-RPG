#pragma once
#include "Player.h"

// �������� ���� �Լ� ���� �� ���� �� �� ��!

// �ʱ�ȭ����Ʈ : https://boycoding.tistory.com/246

Player::Player() : m_status{ }
{}

Player::Player(int hp, int mp, int attackPower, int defensePower) :
	m_status{ hp, mp, attackPower, defensePower }
{
}

void Player::SetHP(uint32 value)
{
	if (value > 100) return;

	m_status.hp = value;
}

void Player::SetMP(uint32 value)
{
	if (value > 30) return;

	m_status.mp = value;
}

void Player::SetAttackPower(uint32 value)
{
	if (value > 40) return;

	m_status.attackPower = value;
}

void Player::SetDefensePower(uint32 value)
{
	if (value > 20) return;

	m_status.defensePower = value;
}