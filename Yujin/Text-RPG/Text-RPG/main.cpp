#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>

#define endl '\n';

using namespace std;

// 플레이어 스테이터스 구조체
struct PlayerStatus {
    int health = 50; // 체력
    int mana = 30; // 마나
    int attack = 10; // 공격력
    int defense = 0; // 방어력
    int gold = 100; // 골드
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
enum MainMenuOption {
    START = 1,
    LOAD,
    EXIT
};

// 메인 로비 옵션
enum MainLobbyOption {
    STATUS = 1,
    ROOM,
    NPC,
    SECRET,
    INVEN,
    EXIT
};

// 방 탐험 옵션
enum RoomOption {
    GUESS = 1,
    MONSTER,
    TREASURE,
    EXIT
};

// NPC 대화 옵션
enum RoomOption {
    GUESS = 1,
    MONSTER,
    TREASURE
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
//void openShop(); // 3. 상인과의 거래 함수

void guessRoom(); // 2-1. 수수께끼의 방
void monsterRoom(); // 2-2. 몬스터의 방
void treasureRoom(); // 2-1. 보물상자의 방

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

        switch (op) {
        case START:
            startGame();
            break;
        case LOAD:
            loadGame();
            break;
        case EXIT:
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
    mainLobby();
}

// 2. 이전 게임 불러오기 함수
void loadGame() {
    mainLobby();
}

// 3. 게임 종료 함수
void exitGame() {
    system("cls");
    cout << "게임을 종료합니다." << endl;
}

// 0. 메인 로비 함수
void mainLobby() {
    system("cls");

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

        switch (op) {
        case STATUS:
            checkStatus();
            break;
        case ROOM:
            enterRoom();
            break;
        case NPC:
            talkNPC();
            break;
        case SECRET:
            enterSecretRoom();
            break;
        case INVEN:
            checkInven();
            break;
            //case SHOP:
            //    openShop();
            //    break;
        case EXIT:
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
    system("cls");

    cout << "=============================" << endl;
    cout << "     플레이어 스테이터스     " << endl;
    cout << "=============================" << endl;
    cout << "체력: " << player.health << endl;
    cout << "마나: " << player.mana << endl;
    cout << "공격력: " << player.attack << endl;
    cout << "방어력: " << player.defense << endl;
    cout << "=============================" << endl;

    // 아무 키나 눌러 메인 로비로 돌아가기
    cout << "계속하려면 아무 키나 누르세요 .. ";
    cin.ignore(); // 버퍼에 남아있는 개행 문자 제거
    cin.get(); // 아무 키나 입력을 받으면 진행

    system("cls");
}

// 2. 방 탐험하기 함수
void enterRoom() {
    system("cls");

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

        switch (op) {
        case 1:
            guessRoom();
            break;
        case 2:
            monsterRoom();
            break;
        case 3:
            treasureRoom();
            break;
        case 4:
            system("cls");
            cout << "알림: 메인 로비로 돌아갑니다." << endl;
            return; // 메인 로비로 돌아감
        default:
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
            break;
        }
    }

    system("cls");
}

// 2. 인벤토리 확인 함수
void checkInven() {
    system("cls");

    cout << "보유 골드: " << player.gold << " 골드" << endl;
    cout << "=============================" << endl;
    cout << "          인벤토리           " << endl;
    cout << "=============================" << endl;

    if (inven.empty()) {
        cout << "알림: 인벤토리가 비어있습니다." << endl;
    }
    else {
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

// 3. 상인과의 거래 함수
void openShop() {
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
        }
        else if (op > 0 && op <= shop.size()) {
            buyItem(op - 1);
        }
        else {
            system("cls");
            cout << "알림: 유효한 숫자를 입력해주세요." << endl;
        }
    }
}

// 아이템을 인벤토리에 추가하는 함수
void addItem(string item) {
    system("cls");

    if (inven.size() < 10) {
        inven.push_back(item);
    }
    else {
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
    }
    else {
        cout << "알림: 보유 골드가 부족합니다." << endl;
    }
}