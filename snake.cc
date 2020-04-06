#include "snake.h"

#include "../library_cpp/include/console.h"
#include "../library_cpp/include/point.h"

// 初始化蛇身
Snake::Snake(void) {
  this->body_.assign({Point(3, 1), Point(2, 1), Point(1, 1)});
}

// 正常向前移动
void Snake::Forward(void) {
  // 末尾位置消去
  this->body_.back().Dot("  ");
  this->body_.pop_back();

  // 蛇头加长一节
  this->Append();
}

// 改变方向
void Snake::ChangeDirection(const Direction direction) {
  // 拒绝相反方向
  if (this->direction_ + direction == 1 || this->direction_ + direction == 5) {
    return;
  }

  this->direction_ = direction;
}

// 判断是否撞击自身
bool Snake::HasHitBody(void) {
  Point head = this->body_.front();
  for (auto&& i = this->body_.begin() + 3; i != this->body_.end(); ++i) {
    if (head == *i) {
      head.Dot("╳ ");
      return true;
    }
  }
  return false;
}

// 加长
void Snake::Append(void) {
  // 根据方向增加一个 Point
  switch (this->direction_) {
    case Direction::kDown:
      this->body_.emplace_front(this->body_.front() + Point(0, 1));
      break;
    case Direction::kUp:
      this->body_.emplace_front(this->body_.front() + Point(0, -1));
      break;
    case Direction::kRight:
      this->body_.emplace_front(this->body_.front() + Point(1, 0));
      break;
    case Direction::kLeft:
      this->body_.emplace_front(this->body_.front() + Point(-1, 0));
      break;
    default:
      return;
  }

  // 越界则从地图对面出现
  if (this->body_.front().GetX() < 0) {
    this->body_.front() += Point(30, 0);
  } else if (this->body_.front().GetX() > 29) {
    this->body_.front() += Point(-30, 0);
  } else if (this->body_.front().GetY() < 0) {
    this->body_.front() += Point(0, 30);
  } else if (this->body_.front().GetY() > 29) {
    this->body_.front() += Point(0, -30);
  }

  // 打印蛇头
  this->body_.front().Dot("●");
}

// 强制重绘
void Snake::ForcedRedraw(void) {
  for (auto&& i : this->body_) {
    i.Dot("●");
  }
}

// 重置
void Snake::Reset(void) {
  this->body_.clear();
  this->body_.assign({Point(3, 1), Point(2, 1), Point(1, 1)});
  for (auto&& i : this->body_) {
    i.Dot("●");
  }
  this->direction_ = Direction::kRight;
}
