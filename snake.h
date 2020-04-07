#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <deque>

#include "../library_cpp/include/point.h"

enum Direction { kUp = 0, kDown = 1, kLeft = 2, kRight = 3 };

class Snake {
 public:
  Snake(void);                                      // ��ʼ������
  void Forward(void);                               // ������ǰ�ƶ�
  void ChangeDirection(const Direction direction);  // �ı䷽��
  bool HasHitBody(void);                            // �ж��Ƿ�ײ������
  void Append(void);                                // �ӳ�
  void ForcedRedraw(void);                          // ǿ���ػ�
  void Reset(void);                                 // ����

 private:
  std::deque<Point> body_;             // ����
  int direction_ = Direction::kRight;  // ǰ������

  friend class Food;  // Food ����Ϊ��Ԫ�Է��� body_
};

#endif  // SNAKE_H
