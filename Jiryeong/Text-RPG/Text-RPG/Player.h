#pragma once

// 변수 타입은 따로 헤더파일 만들어서 팀에서 약속된 키워드로 정의해서 편하게 쓸 것!
using uint32 = unsigned int;
using int32 = int;

class Player 
{
private:
	// 이름은 Player클래스의 이름과 중복되어서 Player 제거
	struct stStatus // Player클래스에서만 구조체 정의를 사용할 경우 여기에 정의
	{
		int hp;
		int mp;
		int attackPower;
		int defensePower;
	};

public:
	Player(); // 기본생성자
	Player(int hp, int mp, int attackPower, int defensePower);

	void SetHP(uint32 value);
	void SetMP(uint32 value);
	void SetAttackPower(uint32 value);
	void SetDefensePower(uint32 value);

	// 한줄짜리는 가독성있게 여기서 이렇게 정의
	int GetHP() const { return m_status.hp; }
	int GetMP() const { return m_status.mp; }
	int GetAttackPower() const { return m_status.attackPower; }
	int GetDefensePower() const { return m_status.defensePower; }

private:
	stStatus m_status;
};