#include <stdio.h>
#include <conio.h>

int game[20][20] = { { 0, } , }; //2���� �迭�� �ٵ����� �����ϰ� 0~19�� �� �� 20�ٷ� �̷���� �ִ�. �ڿ� {0,}�� ��� ��Ҹ� 0���� �ʱ�ȭ �Ѵ�.

void printTitle();
void updatePlate();
int checkFive(int);
int checkFive2(int, int, int);

int main() {
    int input[2];
    int cache;  //�޴����� ������ ���� �Է� ���� �����̴�.
    printTitle();   //������ ���� ������ ��� �ϴ� ��
    printf("�� ���� ���� : 1\n�� ���� ���� : 0\n�� �Է� : ");
    scanf_s("%d", &cache);  //�޴��� ���� ����
    switch (cache) {
    case 0:         // 0 �Է½� ���� ����             
        printf("���� ����.\n");
        return;
        break;
    case 1:         // 1 �Է½� ���� ����
        printf("������ �����մϴ�.\n");
        break;

    }
    for (;;) {          // ���ѷ���. for�� �ȿ� �ִ� ������ �����ϸ� break�� ��������
        system("cls");      //ȭ�鿡 �ִ°� ����� �Լ�. ������� #include<windows.h>�� ����Ǿ� �ִ�
        printTitle();       //������ ���� ���
        updatePlate();      //������ ���
        if (checkFive(2)) {     // ���� checkFive���� �鵹�� �̱�� �������� ����
            printf("�鵹 ��!\n");
            _getch();
            break;
        }
        printf("�浹 �����Դϴ�.\n");
        scanf_s("%d %d", &input[0], &input[1]);     //���� ��ġ�� ������ ��ǥ�� �Է� ����
        if (input[0] == -1 && input[1] == -1) break;
        game[input[1]][input[0]] = 1;       //�ش� �����ǿ� �浹 ǥ��
        system("cls");      //'�浹 �����Դϴ�'�� �Է¹��� ��ǥ ȭ�� �󿡼� ������
        printTitle();       // ���� system("cls"); ������ ���������ϱ� �ٽ� ���� ���
        updatePlate();      //���� ���� ����. ������ ���
        if (checkFive(1)) {     // ���� checkFive���� �浹�� �̱�� �������� ����
            printf("�浹 ��!\n");
            _getch();
            break;
        }
        printf("�鵹 �����Դϴ�.\n");
        scanf_s("%d %d", &input[0], &input[1]);     //���� ��ġ�� ������ ��ǥ�� �Է� ����
        if (input[0] == -1 && input[1] == -1) break;
        game[input[1]][input[0]] = 2;       // �ش� �����ǿ� �鵹 ǥ��
    }
    printf("���� ����\n");
    return 0;
}

void printTitle() {     // ������ ����
    printf("<���� omok>\n");
    for (int n = 0; n < 45; n++) {
        printf("-");
    }
    printf("\n");
}

void updatePlate() {        //�������� �׸�
    printf("  ");
    for (int n = 0; n < 20; n++)   //������ ��� ����: 0~19
        if (n > 9) printf("%d", n);     //�� �ڸ� ���̸� �״�� ���
        else printf(" %d", n);          //�� �ڸ� ���̸� ���� �տ��� ������ �Ѱ� ���
    printf("\n");
    for (int n = 0; n < 20; n++) {      //���� ���ڿ� �ٵ����� ���
        if (n > 9) printf("%d", n);     //���� ���� ���: 2�ڸ� ���̸� �״�� ���
        else printf(" %d", n);      //���ڸ� ���̸� ���� �տ� ���� ���
        for (int m = 0; m < 20; m++) {      //�ٵ����� �׸���. ������ 20��
            if (game[n][m] == 0) printf("��");       //game �迭�� 0�̸� ��ĭ
            else if (game[n][m] == 1) printf("��");  //1�̸� ������
            else if (game[n][m] == 2) printf("��");  //2�̸� ��
        }
        printf("\n");
    }
}

int checkFive(int color) {      // color: 1: ������, 2: �� �˻�
    int cache;
    for (int n = 0; n < 20; n++) {      //�ٵ����� ��ĭ�� �˻�
        for (int m = 0; m < 20; m++) {
            if (game[n][m] == 0) continue;    // �ٵ��ǿ� ���� �������� ������ �ٸ� ĭ �˻�
            cache = checkFive2(n, m, color);         //�ٵ��ǿ� ���� ���� ������ 5���� �������� �����ִ��� �˻�(���⼭ �� ���� ���� check�� ȣ��)
            if (cache == 1) return 1;        //���� checkFive2 �Լ��� ����� 1�̸� ����
        }
    }
    return 0;
}

int checkFive2(int x, int y, int color) {
    int count = 0;     // ���� üũ
    for (int n = 0; n < 5; n++) {
        if (x + n >= 20) return 0;      // �ٵ����� x��ǥ(����) 5���� �ȵǸ� ������
        if (game[x + n][y] == color) count++;
    }
    if (count == 5) return 1;
    count = 0;      // ���� üũ
    for (int n = 0; n < 5; n++) {
        if (y + n >= 20) return 0;      // ���� ĭ�� 5�� �� �Ǹ� 0�� ��ȯ
        if (game[x][y + n] == color) count++;
    }
    if (count == 5) return 1;
    count = 0;      // �밢��(�»󿡼� ���Ϲ���) üũ
    for (int n = 0; n < 5; n++) {
        if (x + n >= 20) return 0;      // ���� ĭ(����)�� 5�� �� �Ǹ� 0�� ��ȯ
        else if (y + n >= 20) return 0;     // ���� ĭ(����)�� 5�� �� �Ǹ� 0�� ��ȯ
        if (game[x + n][y + n] == color) count++;
    }
    if (count == 5) return 1;       // ���� ���� ���� 5���̸� 1�� ��ȯ
    count = 0;       // �밢��(���Ͽ��� ������) üũ
    for (int n = 0; n < 5; n++) {
        if (x + n >= 20) return 0;      // ���� ĭ(����)�� 5�� �� �Ǹ� 0�� ��ȯ
        else if (y - n < 0) return 0;       // ���� ĭ(����)�� 5�� �� �Ǹ� 0�� ��ȯ
        if (game[x + n][y - n] == color) count++;       // ���� ���� ���̸� count ���� 1�� ����
    }
    if (count == 5) return 1;
    return 0;
}