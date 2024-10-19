#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <sstream>

#define endl '\n';

using namespace std;

// 플레이어 스테이터스 구조체
struct PlayerStatus {
    int health = 50; // 체력
    int mana = 30; // 마나
    int attack = 10; // 공격력
    int defense = 1; // 방어력
    int gold = 100; // 골드
};

// 몬스터 스테이터스 구조체
struct MonsterStatus {
    string name; // 이름
    int health; // 체력
    int attack; // 공격력
    int defense; // 방어력
};

// 플레이어 스테이터스
PlayerStatus player;

// 최대 10개의 아이템을 저장할 수 있는 인벤토리
vector<string> inven;

// 상점에서 판매하는 아이템과 가격
struct ShopItem {
    string name;
    int price;
};

// 상점 아이템 리스트
vector<ShopItem> shop = {
    {"체력 포션", 5},
    {"마나 포션", 5},
    {"허름한 투구", 20},
    {"허름한 흉갑", 20},
    {"허름한 레깅스", 20},
    {"허름한 부츠", 20},
    {"낡은 검", 30}
};

// 메인 메뉴 옵션
enum class MENU {
    START = 1,
    LOAD,
    EXIT
};

// 메인 로비 옵션
enum class LOBBY {
    STATUS = 1,
    ROOM,
    NPC,
    SECRET,
    INVEN,
    EXIT
};

// 방 탐험 옵션
enum class ROOM {
    GUESS = 1,
    MONSTER,
    TREASURE,
    EXIT
};

// NPC 대화 옵션
enum class NPC {
    SAGE = 1,
    MERCHANT,
    NUN,
    EXIT
};

// 전투 행동 옵션
enum class BATTLE {
    ATTACK = 1,
    INVEN,
    ESCAPE
};

//inline bool checkChar() {
//    if (cin.fail()) {
//        cin.clear();
//        system("cls");
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        cout << "알림: 유효한 숫자를 입력해주세요." << endl;
//    }
//
//    return cin.peek() == '\n';
//}

void mainMenu(); // 0. 메인 메뉴 함수
void startGame(); // 1. 게임 시작 함수
void loadGame(); // 2. 이전 게임 불러오기 함수
void exitGame(); // 3. 게임 종료 함수

void mainLobby(); // 0. 메인 로비 함수
void checkStatus(); // 1. 스테이터스 보기 함수
void enterRoom(); // 2. 방 탐험하기 함수
void talkNPC(); // 3. NPC와 대화하기 함수
void enterSecretRoom(); // 4. 비밀의 방 입장하기 함수
void checkInven(); // 5. 인벤토리 열기 함수

void guessRoom(); // 2-1. 수수께끼의 방
void monsterRoom(); // 2-2. 몬스터의 방
void treasureRoom(); // 2-3. 보물상자의 방

void talkSage(); // 3-1. 현자와의 대화
void talkMerchant(); // 3-2. 상인과의 대화
void talkNun(); // 3-3. 수녀와의 대화

void battle(MonsterStatus& monster); // 플레이어와 몬스터가 전투하는 함수
int calcDamage(int attack, int defense); // 전투 중 데미지를 계산하는 함수

void addItem(string item); // 아이템을 인벤토리에 추가하는 함수
void buyItem(int index); // 아이템을 구매하는 함수

int main() {
    mainMenu();
}

// 0. 메인 메뉴 함수
void mainMenu() {
    int op;

    while (true) {
        cout << "=============================" << endl;
        cout << "          메인 메뉴          " << endl;
        cout << "=============================" << endl;
        cout << "1. 게임 시작" << endl;
        cout << "2. 이전 게임 불러오기" << endl;
        cout << "3. 게임 나가기" << endl;
        cout << "=============================" << endl;
        cout << "선택: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            system("cls");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
        }

        switch (static_cast<MENU>(op)) {
        case MENU::START:
            startGame();
            break;
        case MENU::LOAD:
            loadGame();
            break;
        case MENU::EXIT:
            exitGame();
            return;
        default:
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            break;
        }
    }
}

// 1. 게임 시작 함수
void startGame() {
    system("cls");
    mainLobby();
}

// 2. 이전 게임 불러오기 함수
void loadGame() {
    system("cls");
    mainLobby();
}

// 3. 게임 종료 함수
void exitGame() {
    system("cls");
    cout << "게임을 종료합니다." << endl;
}

// 0. 메인 로비 함수
void mainLobby() {
    int op;

    while (true) {
        cout << "=============================" << endl;
        cout << "          메인 로비          " << endl;
        cout << "=============================" << endl;
        cout << "1. 스테이터스 보기" << endl;
        cout << "2. 방 탐험하기" << endl;
        cout << "3. NPC와 대화하기" << endl;
        cout << "4. 비밀의 방 입장하기" << endl;
        cout << "5. 인벤토리 열기" << endl;
        cout << "6. 메인 메뉴로 돌아가기" << endl;
        cout << "=============================" << endl;
        cout << "선택: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            continue;
        }

        switch (static_cast<LOBBY>(op)) {
        case LOBBY::STATUS:
            system("cls");
            checkStatus();
            break;
        case LOBBY::ROOM:
            system("cls");
            enterRoom();
            break;
        case LOBBY::NPC:
            system("cls");
            talkNPC();
            break;
        case LOBBY::SECRET:
            system("cls");
            enterSecretRoom();
            break;
        case LOBBY::INVEN:
            system("cls");
            checkInven();
            break;
        case LOBBY::EXIT:
            system("cls");
            cout << "알림: 메인 메뉴로 돌아갑니다." << endl;
            return;
        default:
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            break;
        }
    }
}

// 1. 스테이터스 보기 함수
void checkStatus() {
    cout << "=============================" << endl;
    cout << "     플레이어 스테이터스     " << endl;
    cout << "=============================" << endl;
    cout << "체력: " << player.health << endl;
    cout << "마나: " << player.mana << endl;
    cout << "공격력: " << player.attack << endl;
    cout << "방어력: " << player.defense << endl;
    cout << "=============================" << endl;

    cout << "계속하려면 아무 키나 누르세요 .. ";
    cin.ignore();
    cin.get();

    system("cls");
}

// 2. 방 탐험하기 함수
void enterRoom() {
    int op;

    while (true) {
        cout << "=============================" << endl;
        cout << "         방 탐험하기         " << endl;
        cout << "=============================" << endl;
        cout << "1. 수수께끼의 방" << endl;
        cout << "2. 몬스터의 방" << endl;
        cout << "3. 보물상자의 방" << endl;
        cout << "4. 메인 로비로 돌아가기" << endl;
        cout << "=============================" << endl;
        cout << "선택: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            continue;
        }

        switch (static_cast<ROOM>(op)) {
        case ROOM::GUESS:
            system("cls");
            guessRoom();
            break;
        case ROOM::MONSTER:
            system("cls");
            monsterRoom();
            break;
        case ROOM::TREASURE:
            system("cls");
            treasureRoom();
            break;
        case ROOM::EXIT:
            system("cls");
            cout << "알림: 메인 로비로 돌아갑니다." << endl;
            return;
        default:
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            break;
        }
    }
}

// 2-1. 수수께끼의 방
void guessRoom()
{
    int op;

    cout << "=============================" << endl;
    cout << "        수수께끼의 방        " << endl;
    cout << "=============================" << endl;
    cout << "내가 없으면 아무것도 볼 수 없지만," << endl;
    cout << "나는 모든 곳에 존재한다. 나는 누구일까 ?" << endl;
    cout << "=============================" << endl;
    cout << "1. 빛" << endl;
    cout << "2. 어둠" << endl;
    cout << "3. 그림자" << endl;
    cout << "4. 시간" << endl;
    cout << "=============================" << endl;
    cout << "선택: ";

    cin >> op;
    cout << "=============================" << endl;

    if (op == 1) {
        cout << "정답입니다." << endl;
    } else {
        cout << "오답입니다." << endl;
    }

    cout << "계속하려면 아무 키나 누르세요 .. ";
    cin.ignore();
    cin.get();

    system("cls");
}

// 2-2. 몬스터의 방
void monsterRoom()
{
    // 몬스터 스테이터스 설정
    MonsterStatus monster = { "고블린", 30, 8, 3 };

    cout << "=============================" << endl;
    cout << "         몬스터의 방         " << endl;
    cout << "=============================" << endl;
    cout << "몬스터 " << monster.name << "이(가) 나타났다!" << endl;
    cout << "=============================" << endl;

    cout << "계속하려면 아무 키나 누르세요 .. ";
    cin.ignore();
    cin.get();

    // 전투 시작
    battle(monster);

    // 몬스터를 이겼다면 나뭇가지 추가
    if (monster.health <= 0) {
        cout << "=============================" << endl;
        cout << "         몬스터의 방         " << endl;
        cout << "=============================" << endl;
        cout << "몬스터 " << monster.name << "을(를) 물리쳤다!" << endl;
        addItem("나뭇가지");
        cout << "나뭇가지를 얻었다!" << endl;
        cout << "=============================" << endl;


        cout << "계속하려면 아무 키나 누르세요 .. ";
        cin.get();
    }

    system("cls");
}

// 2-3. 보물상자의 방
void treasureRoom()
{
    cout << "=============================" << endl;
    cout << "        수수께끼의 방        " << endl;
    cout << "=============================" << endl;
    cout << "내가 없으면 아무것도 볼 수 없지만," << endl;
    cout << "나는 모든 곳에 존재한다. 나는 누구일까 ?" << endl;
    cout << "=============================" << endl;
    cout << "1. 빛" << endl;
    cout << "2. 어둠" << endl;
    cout << "3. 그림자" << endl;
    cout << "4. 시간" << endl;
    cout << "=============================" << endl;
    cout << "선택: ";
}

// 3. NPC와 대화하기 함수
void talkNPC() {
    int op;

    while (true) {
        cout << "=============================" << endl;
        cout << "        NPC와 대화하기       " << endl;
        cout << "=============================" << endl;
        cout << "1. 현자와의 대화" << endl;
        cout << "2. 상인과의 대화" << endl;
        cout << "3. 수녀와의 대화" << endl;
        cout << "4. 메인 로비로 돌아가기" << endl;
        cout << "=============================" << endl;
        cout << "선택: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            continue;
        }

        switch (static_cast<NPC>(op)) {
        case NPC::SAGE:
            system("cls");
            talkSage();
            break;
        case NPC::MERCHANT:
            system("cls");
            talkMerchant();
            break;
        case NPC::NUN:
            system("cls");
            talkNun();
            break;
        case NPC::EXIT:
            system("cls");
            cout << "알림: 메인 로비로 돌아갑니다." << endl;
            return;
        default:
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            break;
        }
    }
}

// 3-1. 현자와의 대화
void talkSage() {
    cout << "=============================" << endl;
    cout << "        수수께끼의 방        " << endl;
    cout << "=============================" << endl;
    cout << "내가 없으면 아무것도 볼 수 없지만," << endl;
    cout << "나는 모든 곳에 존재한다. 나는 누구일까 ?" << endl;
    cout << "=============================" << endl;
    cout << "1. 빛" << endl;
    cout << "2. 어둠" << endl;
    cout << "3. 그림자" << endl;
    cout << "4. 시간" << endl;
    cout << "=============================" << endl;
    cout << "선택: ";
}

// 3-2. 상인과의 대화
void talkMerchant() {
    system("cls");

    int op;

    while (true) {
        cout << "보유 골드: " << player.gold << " 골드" << endl;
        cout << "=============================" << endl;
        cout << "          상점 목록          " << endl;
        cout << "=============================" << endl;

        for (int i = 0; i < shop.size(); i++) {
            cout << i + 1 << ". " << shop[i].name << " (" << shop[i].price << " 골드)" << endl;
        }

        cout << shop.size() + 1 << ". 메인 로비로 돌아가기" << endl;
        cout << "=============================" << endl;
        cout << "선택: ";
        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            continue;
        }

        if (op == shop.size() + 1) {
            system("cls");
            cout << "알림: 메인 로비로 돌아갑니다." << endl;
            break;
        } else if (op > 0 && op <= shop.size()) {
            buyItem(op - 1);
        } else {
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
        }
    }
}

// 3-3. 수녀와의 대화
void talkNun() {
    cout << "=============================" << endl;
    cout << "        수수께끼의 방        " << endl;
    cout << "=============================" << endl;
    cout << "내가 없으면 아무것도 볼 수 없지만," << endl;
    cout << "나는 모든 곳에 존재한다. 나는 누구일까 ?" << endl;
    cout << "=============================" << endl;
    cout << "1. 빛" << endl;
    cout << "2. 어둠" << endl;
    cout << "3. 그림자" << endl;
    cout << "4. 시간" << endl;
    cout << "=============================" << endl;
    cout << "선택: ";
}

// 4. 비밀의 방 입장하기 함수
void enterSecretRoom() {
    cout << "=============================" << endl;
    cout << "        수수께끼의 방        " << endl;
    cout << "=============================" << endl;
    cout << "내가 없으면 아무것도 볼 수 없지만," << endl;
    cout << "나는 모든 곳에 존재한다. 나는 누구일까 ?" << endl;
    cout << "=============================" << endl;
    cout << "1. 빛" << endl;
    cout << "2. 어둠" << endl;
    cout << "3. 그림자" << endl;
    cout << "4. 시간" << endl;
    cout << "=============================" << endl;
    cout << "선택: ";
}

// 5. 인벤토리 열기 함수
void checkInven() {
    system("cls");

    cout << "보유 골드: " << player.gold << " 골드" << endl;
    cout << "=============================" << endl;
    cout << "           인벤토리          " << endl;
    cout << "=============================" << endl;

    if (inven.empty()) {
        cout << "알림: 인벤토리가 비어있습니다." << endl;
    } else {
        for (int i = 0; i < inven.size(); i++) {
            cout << inven[i] << endl;
        }
    }

    cout << "=============================" << endl;

    // 아무 키나 눌러 메인 로비로 돌아가기
    cout << "계속하려면 아무 키나 누르세요 .. ";
    cin.ignore(); // 버퍼에 남아있는 개행 문자 제거
    cin.get(); // 아무 키나 입력을 받으면 진행

    system("cls");
}

// 전투 함수
void battle(MonsterStatus& monster) {
    int op;
    string lastMessage = "";

    while (player.health > 0 && monster.health > 0) {
        system("cls");

        cout << "=============================" << endl;
        cout << "          전투 시작          " << endl;
        cout << "=============================" << endl;
        cout << monster.name << " 체력: " << monster.health << endl;
        cout << "플레이어 체력: " << player.health << endl;
        cout << "=============================" << endl;

        if (!lastMessage.empty()) {
            cout << lastMessage << endl;
            cout << "=============================" << endl;

        }

        cout << "1. 공격하기" << endl;
        cout << "2. 인벤토리 열기" << endl;
        cout << "3. 도망가기" << endl;
        cout << "=============================" << endl;
        cout << "선택: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            continue;
        }

        switch (static_cast<BATTLE>(op)) {
        case BATTLE::ATTACK:
        {
            int playerDamage = calcDamage(player.attack, monster.defense);
            monster.health -= playerDamage;
            lastMessage = "플레이어가 " + to_string(playerDamage) + "만큼의 데미지를 입혔다!";

            if (monster.health <= 0) {
                system("cls");

                cout << "=============================" << endl;
                cout << "          전투 종료          " << endl;
                cout << "=============================" << endl;
                cout << "몬스터 " << monster.name << "이(가) 쓰러졌다!" << endl;
                cout << "=============================" << endl;

                cout << "계속하려면 아무 키나 누르세요 .. ";
                cin.ignore();
                cin.get();

                system("cls");

                break;
            }
        }
        break;
        case BATTLE::INVEN:
            lastMessage = "알림: 배낭을 열었습니다.";
            break;
        case BATTLE::ESCAPE:
            cout << "=============================" << endl;
            cout << "알림: 무사히 도망쳤습니다!\n" << endl;

            cout << "계속하려면 아무 키나 누르세요 .. ";
            cin.ignore();
            cin.get();

            return;
        default:
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            continue;
        }

        int monsterDamage = calcDamage(monster.attack, player.defense);
        player.health -= monsterDamage;
        lastMessage += "\n" + monster.name + "이(가) " + to_string(monsterDamage) + "만큼의 데미지를 입혔다!";

        if (player.health <= 0) {
            system("cls");

            cout << "=============================" << endl;
            cout << "          전투 종료          " << endl;
            cout << "=============================" << endl;
            cout << "플레이어가 쓰러졌다!" << endl;
            cout << "=============================" << endl;

            cout << "계속하려면 아무 키나 누르세요 .. ";
            cin.ignore();
            cin.get();
        }
    }
}

// 데미지 계산 함수
int calcDamage(int attack, int defense) {
    int damage = attack - defense;
    return (damage > 0) ? damage : 1; // 최소 데미지: 1
}

// 아이템을 인벤토리에 추가하는 함수
void addItem(string item) {
    if (inven.size() < 10) {
        inven.push_back(item);
    } else {
        cout << "알림: 인벤토리가 가득 찼습니다." << endl;
    }
}

// 아이템을 구매하는 함수
void buyItem(int index) {
    system("cls");

    if (inven.size() >= 10) {
        cout << "알림: 더 이상 아이템을 구매할 수 없습니다." << endl;
        return;
    }

    int price = shop[index].price;

    if (player.gold >= price) {
        player.gold -= price;
        addItem(shop[index].name);

        cout << "알림: " << shop[index].name << "을(를) 구매했습니다." << endl;
    } else {
        cout << "알림: 보유 골드가 부족합니다." << endl;
    }
}
