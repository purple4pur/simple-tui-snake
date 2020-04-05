#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <deque>

#include "../library_cpp/include/point.h"

enum Direction { kUp = 0, kDown = 1, kLeft = 2, kRight = 3 };

class Snake {
 public:
  Snake(void);                                      // 初始化并打印蛇身
  void Forward(void);                               // 正常向前移动
  void ChangeDirection(const Direction direction);  // 改变方向
  bool HasHitBody(void);                            // 判断是否撞击自身
  void Append(void);                                // 加长
  void ForcedRedraw(void);                          // 强制重绘
  void Reset(void);                                 // 重置

 private:
  std::deque<Point> body_;             // 蛇身
  int direction_ = Direction::kRight;  // 前进方向

  friend class Food;  // Food 类设为友元以访问 body_
};

#endif  // SNAKE_H
