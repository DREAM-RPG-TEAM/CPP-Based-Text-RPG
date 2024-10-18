#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>

#define endl '\n';

using namespace std;

// �÷��̾� �������ͽ� ����ü
struct PlayerStatus {
    int health = 50; // ü��
    int mana = 30; // ����
    int attack = 10; // ���ݷ�
    int defense = 0; // ����
    int gold = 100; // ���
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
enum MainMenuOption {
    START = 1,
    LOAD,
    EXIT
};

// ���� �κ� �ɼ�
enum MainLobbyOption {
    STATUS = 1,
    ROOM,
    NPC,
    SECRET,
    INVEN,
    EXIT
};

// �� Ž�� �ɼ�
enum RoomOption {
    GUESS = 1,
    MONSTER,
    TREASURE,
    EXIT
};

// NPC ��ȭ �ɼ�
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
//void openShop(); // 3. ���ΰ��� �ŷ� �Լ�

void guessRoom(); // 2-1. ���������� ��
void monsterRoom(); // 2-2. ������ ��
void treasureRoom(); // 2-1. ���������� ��

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
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
            break;
        }
    }
}

// 1. ���� ���� �Լ�
void startGame() {
    mainLobby();
}

// 2. ���� ���� �ҷ����� �Լ�
void loadGame() {
    mainLobby();
}

// 3. ���� ���� �Լ�
void exitGame() {
    system("cls");
    cout << "������ �����մϴ�." << endl;
}

// 0. ���� �κ� �Լ�
void mainLobby() {
    system("cls");

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
    system("cls");

    cout << "=============================" << endl;
    cout << "     �÷��̾� �������ͽ�     " << endl;
    cout << "=============================" << endl;
    cout << "ü��: " << player.health << endl;
    cout << "����: " << player.mana << endl;
    cout << "���ݷ�: " << player.attack << endl;
    cout << "����: " << player.defense << endl;
    cout << "=============================" << endl;

    // �ƹ� Ű�� ���� ���� �κ�� ���ư���
    cout << "����Ϸ��� �ƹ� Ű�� �������� .. ";
    cin.ignore(); // ���ۿ� �����ִ� ���� ���� ����
    cin.get(); // �ƹ� Ű�� �Է��� ������ ����

    system("cls");
}

// 2. �� Ž���ϱ� �Լ�
void enterRoom() {
    system("cls");

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
            cout << "�˸�: ���� �κ�� ���ư��ϴ�." << endl;
            return; // ���� �κ�� ���ư�
        default:
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
            break;
        }
    }

    system("cls");
}

// 2. �κ��丮 Ȯ�� �Լ�
void checkInven() {
    system("cls");

    cout << "���� ���: " << player.gold << " ���" << endl;
    cout << "=============================" << endl;
    cout << "          �κ��丮           " << endl;
    cout << "=============================" << endl;

    if (inven.empty()) {
        cout << "�˸�: �κ��丮�� ����ֽ��ϴ�." << endl;
    }
    else {
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

// 3. ���ΰ��� �ŷ� �Լ�
void openShop() {
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
        }
        else if (op > 0 && op <= shop.size()) {
            buyItem(op - 1);
        }
        else {
            system("cls");
            cout << "�˸�: ��ȿ�� ���ڸ� �Է����ּ���." << endl;
        }
    }
}

// �������� �κ��丮�� �߰��ϴ� �Լ�
void addItem(string item) {
    system("cls");

    if (inven.size() < 10) {
        inven.push_back(item);
    }
    else {
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
    }
    else {
        cout << "�˸�: ���� ��尡 �����մϴ�." << endl;
    }
}