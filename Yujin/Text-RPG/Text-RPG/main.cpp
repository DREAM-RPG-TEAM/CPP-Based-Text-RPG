#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <sstream>

#define endl '\n';

using namespace std;

// �÷��̾� �������ͽ� ����ü
struct PlayerStatus {
    int health = 50; // ü��
    int mana = 30; // ����
    int attack = 10; // ���ݷ�
    int defense = 1; // ����
    int gold = 100; // ���
};

// ���� �������ͽ� ����ü
struct MonsterStatus {
    string name; // �̸�
    int health; // ü��
    int attack; // ���ݷ�
    int defense; // ����
};

// �÷��̾� �������ͽ�
PlayerStatus player;

// �ִ� 10���� �������� ������ �� �ִ� �κ��丮
vector<string> inven;

// �������� �Ǹ��ϴ� �����۰� ����
struct ShopItem {
    string name;
    int price;
};

// ���� ������ ����Ʈ
vector<ShopItem> shop = {
    {"ü�� ����", 5},
    {"���� ����", 5},
    {"�㸧�� ����", 20},
    {"�㸧�� �䰩", 20},
    {"�㸧�� ���뽺", 20},
    {"�㸧�� ����", 20},
    {"���� ��", 30}
};

// ���� �޴� �ɼ�
enum class MENU {
    START = 1,
    LOAD,
    EXIT
};

// ���� �κ� �ɼ�
enum class LOBBY {
    STATUS = 1,
    ROOM,
    NPC,
    SECRET,
    INVEN,
    EXIT
};

// �� Ž�� �ɼ�
enum class ROOM {
    GUESS = 1,
    MONSTER,
    TREASURE,
    EXIT
};

// NPC ��ȭ �ɼ�
enum class NPC {
    SAGE = 1,
    MERCHANT,
    NUN,
    EXIT
};

// ���� �ൿ �ɼ�
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
//        cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
//    }
//
//    return cin.peek() == '\n';
//}

void mainMenu(); // 0. ���� �޴� �Լ�
void startGame(); // 1. ���� ���� �Լ�
void loadGame(); // 2. ���� ���� �ҷ����� �Լ�
void exitGame(); // 3. ���� ���� �Լ�

void mainLobby(); // 0. ���� �κ� �Լ�
void checkStatus(); // 1. �������ͽ� ���� �Լ�
void enterRoom(); // 2. �� Ž���ϱ� �Լ�
void talkNPC(); // 3. NPC�� ��ȭ�ϱ� �Լ�
void enterSecretRoom(); // 4. ����� �� �����ϱ� �Լ�
void checkInven(); // 5. �κ��丮 ���� �Լ�

void guessRoom(); // 2-1. ���������� ��
void monsterRoom(); // 2-2. ������ ��
void treasureRoom(); // 2-3. ���������� ��

void talkSage(); // 3-1. ���ڿ��� ��ȭ
void talkMerchant(); // 3-2. ���ΰ��� ��ȭ
void talkNun(); // 3-3. ������� ��ȭ

void battle(MonsterStatus& monster); // �÷��̾�� ���Ͱ� �����ϴ� �Լ�
int calcDamage(int attack, int defense); // ���� �� �������� ����ϴ� �Լ�

void addItem(string item); // �������� �κ��丮�� �߰��ϴ� �Լ�
void buyItem(int index); // �������� �����ϴ� �Լ�

int main() {
    mainMenu();
}

// 0. ���� �޴� �Լ�
void mainMenu() {
    int op;

    while (true) {
        cout << "=============================" << endl;
        cout << "          ���� �޴�          " << endl;
        cout << "=============================" << endl;
        cout << "1. ���� ����" << endl;
        cout << "2. ���� ���� �ҷ�����" << endl;
        cout << "3. ���� ������" << endl;
        cout << "=============================" << endl;
        cout << "����: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            system("cls");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
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
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
            break;
        }
    }
}

// 1. ���� ���� �Լ�
void startGame() {
    system("cls");
    mainLobby();
}

// 2. ���� ���� �ҷ����� �Լ�
void loadGame() {
    system("cls");
    mainLobby();
}

// 3. ���� ���� �Լ�
void exitGame() {
    system("cls");
    cout << "������ �����մϴ�." << endl;
}

// 0. ���� �κ� �Լ�
void mainLobby() {
    int op;

    while (true) {
        cout << "=============================" << endl;
        cout << "          ���� �κ�          " << endl;
        cout << "=============================" << endl;
        cout << "1. �������ͽ� ����" << endl;
        cout << "2. �� Ž���ϱ�" << endl;
        cout << "3. NPC�� ��ȭ�ϱ�" << endl;
        cout << "4. ����� �� �����ϱ�" << endl;
        cout << "5. �κ��丮 ����" << endl;
        cout << "6. ���� �޴��� ���ư���" << endl;
        cout << "=============================" << endl;
        cout << "����: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
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
            cout << "�˸�: ���� �޴��� ���ư��ϴ�." << endl;
            return;
        default:
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
            break;
        }
    }
}

// 1. �������ͽ� ���� �Լ�
void checkStatus() {
    cout << "=============================" << endl;
    cout << "     �÷��̾� �������ͽ�     " << endl;
    cout << "=============================" << endl;
    cout << "ü��: " << player.health << endl;
    cout << "����: " << player.mana << endl;
    cout << "���ݷ�: " << player.attack << endl;
    cout << "����: " << player.defense << endl;
    cout << "=============================" << endl;

    cout << "����Ϸ��� �ƹ� Ű�� �������� .. ";
    cin.ignore();
    cin.get();

    system("cls");
}

// 2. �� Ž���ϱ� �Լ�
void enterRoom() {
    int op;

    while (true) {
        cout << "=============================" << endl;
        cout << "         �� Ž���ϱ�         " << endl;
        cout << "=============================" << endl;
        cout << "1. ���������� ��" << endl;
        cout << "2. ������ ��" << endl;
        cout << "3. ���������� ��" << endl;
        cout << "4. ���� �κ�� ���ư���" << endl;
        cout << "=============================" << endl;
        cout << "����: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
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
            cout << "�˸�: ���� �κ�� ���ư��ϴ�." << endl;
            return;
        default:
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
            break;
        }
    }
}

// 2-1. ���������� ��
void guessRoom()
{
    int op;

    cout << "=============================" << endl;
    cout << "        ���������� ��        " << endl;
    cout << "=============================" << endl;
    cout << "���� ������ �ƹ��͵� �� �� ������," << endl;
    cout << "���� ��� ���� �����Ѵ�. ���� �����ϱ� ?" << endl;
    cout << "=============================" << endl;
    cout << "1. ��" << endl;
    cout << "2. ���" << endl;
    cout << "3. �׸���" << endl;
    cout << "4. �ð�" << endl;
    cout << "=============================" << endl;
    cout << "����: ";

    cin >> op;
    cout << "=============================" << endl;

    if (op == 1) {
        cout << "�����Դϴ�." << endl;
    } else {
        cout << "�����Դϴ�." << endl;
    }

    cout << "����Ϸ��� �ƹ� Ű�� �������� .. ";
    cin.ignore();
    cin.get();

    system("cls");
}

// 2-2. ������ ��
void monsterRoom()
{
    // ���� �������ͽ� ����
    MonsterStatus monster = { "���", 30, 8, 3 };

    cout << "=============================" << endl;
    cout << "         ������ ��         " << endl;
    cout << "=============================" << endl;
    cout << "���� " << monster.name << "��(��) ��Ÿ����!" << endl;
    cout << "=============================" << endl;

    cout << "����Ϸ��� �ƹ� Ű�� �������� .. ";
    cin.ignore();
    cin.get();

    // ���� ����
    battle(monster);

    // ���͸� �̰�ٸ� �������� �߰�
    if (monster.health <= 0) {
        cout << "=============================" << endl;
        cout << "         ������ ��         " << endl;
        cout << "=============================" << endl;
        cout << "���� " << monster.name << "��(��) �����ƴ�!" << endl;
        addItem("��������");
        cout << "���������� �����!" << endl;
        cout << "=============================" << endl;


        cout << "����Ϸ��� �ƹ� Ű�� �������� .. ";
        cin.get();
    }

    system("cls");
}

// 2-3. ���������� ��
void treasureRoom()
{
    cout << "=============================" << endl;
    cout << "        ���������� ��        " << endl;
    cout << "=============================" << endl;
    cout << "���� ������ �ƹ��͵� �� �� ������," << endl;
    cout << "���� ��� ���� �����Ѵ�. ���� �����ϱ� ?" << endl;
    cout << "=============================" << endl;
    cout << "1. ��" << endl;
    cout << "2. ���" << endl;
    cout << "3. �׸���" << endl;
    cout << "4. �ð�" << endl;
    cout << "=============================" << endl;
    cout << "����: ";
}

// 3. NPC�� ��ȭ�ϱ� �Լ�
void talkNPC() {
    int op;

    while (true) {
        cout << "=============================" << endl;
        cout << "        NPC�� ��ȭ�ϱ�       " << endl;
        cout << "=============================" << endl;
        cout << "1. ���ڿ��� ��ȭ" << endl;
        cout << "2. ���ΰ��� ��ȭ" << endl;
        cout << "3. ������� ��ȭ" << endl;
        cout << "4. ���� �κ�� ���ư���" << endl;
        cout << "=============================" << endl;
        cout << "����: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
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
            cout << "�˸�: ���� �κ�� ���ư��ϴ�." << endl;
            return;
        default:
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
            break;
        }
    }
}

// 3-1. ���ڿ��� ��ȭ
void talkSage() {
    cout << "=============================" << endl;
    cout << "        ���������� ��        " << endl;
    cout << "=============================" << endl;
    cout << "���� ������ �ƹ��͵� �� �� ������," << endl;
    cout << "���� ��� ���� �����Ѵ�. ���� �����ϱ� ?" << endl;
    cout << "=============================" << endl;
    cout << "1. ��" << endl;
    cout << "2. ���" << endl;
    cout << "3. �׸���" << endl;
    cout << "4. �ð�" << endl;
    cout << "=============================" << endl;
    cout << "����: ";
}

// 3-2. ���ΰ��� ��ȭ
void talkMerchant() {
    system("cls");

    int op;

    while (true) {
        cout << "���� ���: " << player.gold << " ���" << endl;
        cout << "=============================" << endl;
        cout << "          ���� ���          " << endl;
        cout << "=============================" << endl;

        for (int i = 0; i < shop.size(); i++) {
            cout << i + 1 << ". " << shop[i].name << " (" << shop[i].price << " ���)" << endl;
        }

        cout << shop.size() + 1 << ". ���� �κ�� ���ư���" << endl;
        cout << "=============================" << endl;
        cout << "����: ";
        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
            continue;
        }

        if (op == shop.size() + 1) {
            system("cls");
            cout << "�˸�: ���� �κ�� ���ư��ϴ�." << endl;
            break;
        } else if (op > 0 && op <= shop.size()) {
            buyItem(op - 1);
        } else {
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
        }
    }
}

// 3-3. ������� ��ȭ
void talkNun() {
    cout << "=============================" << endl;
    cout << "        ���������� ��        " << endl;
    cout << "=============================" << endl;
    cout << "���� ������ �ƹ��͵� �� �� ������," << endl;
    cout << "���� ��� ���� �����Ѵ�. ���� �����ϱ� ?" << endl;
    cout << "=============================" << endl;
    cout << "1. ��" << endl;
    cout << "2. ���" << endl;
    cout << "3. �׸���" << endl;
    cout << "4. �ð�" << endl;
    cout << "=============================" << endl;
    cout << "����: ";
}

// 4. ����� �� �����ϱ� �Լ�
void enterSecretRoom() {
    cout << "=============================" << endl;
    cout << "        ���������� ��        " << endl;
    cout << "=============================" << endl;
    cout << "���� ������ �ƹ��͵� �� �� ������," << endl;
    cout << "���� ��� ���� �����Ѵ�. ���� �����ϱ� ?" << endl;
    cout << "=============================" << endl;
    cout << "1. ��" << endl;
    cout << "2. ���" << endl;
    cout << "3. �׸���" << endl;
    cout << "4. �ð�" << endl;
    cout << "=============================" << endl;
    cout << "����: ";
}

// 5. �κ��丮 ���� �Լ�
void checkInven() {
    system("cls");

    cout << "���� ���: " << player.gold << " ���" << endl;
    cout << "=============================" << endl;
    cout << "           �κ��丮          " << endl;
    cout << "=============================" << endl;

    if (inven.empty()) {
        cout << "�˸�: �κ��丮�� ����ֽ��ϴ�." << endl;
    } else {
        for (int i = 0; i < inven.size(); i++) {
            cout << inven[i] << endl;
        }
    }

    cout << "=============================" << endl;

    // �ƹ� Ű�� ���� ���� �κ�� ���ư���
    cout << "����Ϸ��� �ƹ� Ű�� �������� .. ";
    cin.ignore(); // ���ۿ� �����ִ� ���� ���� ����
    cin.get(); // �ƹ� Ű�� �Է��� ������ ����

    system("cls");
}

// ���� �Լ�
void battle(MonsterStatus& monster) {
    int op;
    string lastMessage = "";

    while (player.health > 0 && monster.health > 0) {
        system("cls");

        cout << "=============================" << endl;
        cout << "          ���� ����          " << endl;
        cout << "=============================" << endl;
        cout << monster.name << " ü��: " << monster.health << endl;
        cout << "�÷��̾� ü��: " << player.health << endl;
        cout << "=============================" << endl;

        if (!lastMessage.empty()) {
            cout << lastMessage << endl;
            cout << "=============================" << endl;

        }

        cout << "1. �����ϱ�" << endl;
        cout << "2. �κ��丮 ����" << endl;
        cout << "3. ��������" << endl;
        cout << "=============================" << endl;
        cout << "����: ";

        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
            continue;
        }

        switch (static_cast<BATTLE>(op)) {
        case BATTLE::ATTACK:
        {
            int playerDamage = calcDamage(player.attack, monster.defense);
            monster.health -= playerDamage;
            lastMessage = "�÷��̾ " + to_string(playerDamage) + "��ŭ�� �������� ������!";

            if (monster.health <= 0) {
                system("cls");

                cout << "=============================" << endl;
                cout << "          ���� ����          " << endl;
                cout << "=============================" << endl;
                cout << "���� " << monster.name << "��(��) ��������!" << endl;
                cout << "=============================" << endl;

                cout << "����Ϸ��� �ƹ� Ű�� �������� .. ";
                cin.ignore();
                cin.get();

                system("cls");

                break;
            }
        }
        break;
        case BATTLE::INVEN:
            lastMessage = "�˸�: �賶�� �������ϴ�.";
            break;
        case BATTLE::ESCAPE:
            cout << "=============================" << endl;
            cout << "�˸�: ������ �����ƽ��ϴ�!\n" << endl;

            cout << "����Ϸ��� �ƹ� Ű�� �������� .. ";
            cin.ignore();
            cin.get();

            return;
        default:
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
            continue;
        }

        int monsterDamage = calcDamage(monster.attack, player.defense);
        player.health -= monsterDamage;
        lastMessage += "\n" + monster.name + "��(��) " + to_string(monsterDamage) + "��ŭ�� �������� ������!";

        if (player.health <= 0) {
            system("cls");

            cout << "=============================" << endl;
            cout << "          ���� ����          " << endl;
            cout << "=============================" << endl;
            cout << "�÷��̾ ��������!" << endl;
            cout << "=============================" << endl;

            cout << "����Ϸ��� �ƹ� Ű�� �������� .. ";
            cin.ignore();
            cin.get();
        }
    }
}

// ������ ��� �Լ�
int calcDamage(int attack, int defense) {
    int damage = attack - defense;
    return (damage > 0) ? damage : 1; // �ּ� ������: 1
}

// �������� �κ��丮�� �߰��ϴ� �Լ�
void addItem(string item) {
    if (inven.size() < 10) {
        inven.push_back(item);
    } else {
        cout << "�˸�: �κ��丮�� ���� á���ϴ�." << endl;
    }
}

// �������� �����ϴ� �Լ�
void buyItem(int index) {
    system("cls");

    if (inven.size() >= 10) {
        cout << "�˸�: �� �̻� �������� ������ �� �����ϴ�." << endl;
        return;
    }

    int price = shop[index].price;

    if (player.gold >= price) {
        player.gold -= price;
        addItem(shop[index].name);

        cout << "�˸�: " << shop[index].name << "��(��) �����߽��ϴ�." << endl;
    } else {
        cout << "�˸�: ���� ��尡 �����մϴ�." << endl;
    }
}
