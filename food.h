#pragma once
#ifndef FOOD_H
#define FOOD_H

#include "../library_cpp/include/point.h"
#include "snake.h"

class Food {
 public:
  Point coord;
  Food(const Snake& snake);
  void Generate(const Snake& snake);  // ������ʳ��
  bool IsEaten(const Snake& snake);   // �ж��Ƿ񱻳�
  void ForcedRedraw(void);            // ǿ���ػ�
};

#endif  // FOOD_H
