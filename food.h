#pragma once
#ifndef FOOD_H
#define FOOD_H

#include "../library_cpp/include/point.h"
#include "snake.h"

class Food {
 public:
  Point coord;
  Food(void);
  void Generate(const Snake& snake);  // 生成新食物
  bool IsEaten(const Snake& snake);   // 判断是否被吃
  void ForcedRedraw(void);            // 强制重绘
};

#endif  // FOOD_H
