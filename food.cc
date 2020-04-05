#include "food.h"

#include <cstdlib>
#include <ctime>

#include "snake.h"

Food::Food(void) {
  srand(time(NULL));
  this->coord = Point(rand() % 30, rand() % 25 + 5);
}

// ������ʳ��
void Food::Generate(const Snake& snake) {
  srand(time(NULL));
  int X, Y;
GENERATE:
  X = rand() % 30;
  Y = rand() % 30;
  for (auto&& i : snake.body_) {
    if (Point(X, Y) == i) {
      goto GENERATE;
    }
  }
  this->coord = Point(X, Y);
  this->coord.Dot("��");
}

// �ж��Ƿ񱻳�
bool Food::IsEaten(const Snake& snake) {
  return this->coord == snake.body_.front();
}

// ǿ���ػ�
void Food::ForcedRedraw(void) { this->coord.Dot("��"); }
