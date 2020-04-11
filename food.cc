#include "food.h"

#include <cstdlib>

#include "snake.h"

Food::Food(const Snake& snake) { this->Generate(snake); }

// 生成新食物
void Food::Generate(const Snake& snake) {
  int X, Y;
GENERATE:
  X = rand() % 30;
  Y = rand() % 30;

  // 遍历蛇身，确保新食物与蛇身不重叠
  for (auto&& i : snake.body_) {
    if (Point(X, Y) == i) {
      goto GENERATE;
    }
  }

  // 保存并绘制新食物
  this->coord = Point(X, Y);
  this->coord.Dot("◇");
}

// 判断是否被吃
bool Food::IsEaten(const Snake& snake) {
  // 只需判断是否和蛇头重叠
  return this->coord == snake.body_.front();
}

// 强制重绘
void Food::ForcedRedraw(void) { this->coord.Dot("◇"); }
