#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 10
#define HEIGHT 10

int maze[HEIGHT][WIDTH] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,0,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,1,0,1},
	{1,1,1,1,1,1,0,1,0,1},
	{1,0,0,0,0,0,0,1,0,1},
	{1,0,1,1,1,1,1,1,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};
// �÷��̾� ��ġ
int playerX = 1, playerY = 1;

// ȭ�� ���
void drawMaze() {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == playerX && y == playerY) {
                printf("P "); // �÷��̾�
            }
            else if (maze[y][x] == 1) {
                printf("# "); // ��
            }
            else if (maze[y][x] == 2) {
                printf("E "); // �ⱸ
            }
            else {
                printf(". "); // ��
            }
        }
        printf("\n");
    }
}

// �Է� ó��
void movePlayer(char input) {
    int nextX = playerX, nextY = playerY;

    if (input == 'w') nextY--; // ���� �̵�
    else if (input == 's') nextY++; // �Ʒ��� �̵�
    else if (input == 'a') nextX--; // �������� �̵�
    else if (input == 'd') nextX++; // ���������� �̵�

    // �̵� ���� ���� Ȯ�� (���� �ƴ� ��� �̵�)
    if (maze[nextY][nextX] != 1) {
        playerX = nextX;
        playerY = nextY;
    }
}

int main() {
    printf("�̷� Ż�� ���ӿ� ���� ���� ȯ���մϴ�!\n");
    printf("�÷��̾�� 'P'�� ǥ�õ˴ϴ�. �ⱸ�� 'E'�Դϴ�.\n");
    printf("����Ű(WASD)�� ����Ͽ� �̵��ϼ���.\n");
    printf("���� Ű�� ������ ������ ���۵˴ϴ�!\n");
    getchar();

    while (1) {
        drawMaze();

        // �ⱸ ���� üũ
        if (maze[playerY][playerX] == 2) {
            printf("�����մϴ�! �̷θ� Ż���߽��ϴ�!\n");
            break;
        }

        // �Է� ��� �� ó��
        char input = _getch();
        movePlayer(input);
    }

    return 0;
}