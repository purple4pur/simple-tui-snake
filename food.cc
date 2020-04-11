#include "food.h"

#include <cstdlib>

#include "snake.h"

Food::Food(const Snake& snake) { this->Generate(snake); }

// ������ʳ��
void Food::Generate(const Snake& snake) {
  int X, Y;
GENERATE:
  X = rand() % 30;
  Y = rand() % 30;

  // ��������ȷ����ʳ���������ص�
  for (auto&& i : snake.body_) {
    if (Point(X, Y) == i) {
      goto GENERATE;
    }
  }

  // ���沢������ʳ��
  this->coord = Point(X, Y);
  this->coord.Dot("��");
}

// �ж��Ƿ񱻳�
bool Food::IsEaten(const Snake& snake) {
  // ֻ���ж��Ƿ����ͷ�ص�
  return this->coord == snake.body_.front();
}

// ǿ���ػ�
void Food::ForcedRedraw(void) { this->coord.Dot("��"); }
