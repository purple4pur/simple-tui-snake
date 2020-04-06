#include "snake.h"

#include "../library_cpp/include/console.h"
#include "../library_cpp/include/point.h"

// ��ʼ������
Snake::Snake(void) {
  this->body_.assign({Point(3, 1), Point(2, 1), Point(1, 1)});
}

// ������ǰ�ƶ�
void Snake::Forward(void) {
  // ĩβλ����ȥ
  this->body_.back().Dot("  ");
  this->body_.pop_back();

  // ��ͷ�ӳ�һ��
  this->Append();
}

// �ı䷽��
void Snake::ChangeDirection(const Direction direction) {
  // �ܾ��෴����
  if (this->direction_ + direction == 1 || this->direction_ + direction == 5) {
    return;
  }

  this->direction_ = direction;
}

// �ж��Ƿ�ײ������
bool Snake::HasHitBody(void) {
  Point head = this->body_.front();
  for (auto&& i = this->body_.begin() + 3; i != this->body_.end(); ++i) {
    if (head == *i) {
      head.Dot("�w ");
      return true;
    }
  }
  return false;
}

// �ӳ�
void Snake::Append(void) {
  // ���ݷ�������һ�� Point
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

  // Խ����ӵ�ͼ�������
  if (this->body_.front().GetX() < 0) {
    this->body_.front() += Point(30, 0);
  } else if (this->body_.front().GetX() > 29) {
    this->body_.front() += Point(-30, 0);
  } else if (this->body_.front().GetY() < 0) {
    this->body_.front() += Point(0, 30);
  } else if (this->body_.front().GetY() > 29) {
    this->body_.front() += Point(0, -30);
  }

  // ��ӡ��ͷ
  this->body_.front().Dot("��");
}

// ǿ���ػ�
void Snake::ForcedRedraw(void) {
  for (auto&& i : this->body_) {
    i.Dot("��");
  }
}

// ����
void Snake::Reset(void) {
  this->body_.clear();
  this->body_.assign({Point(3, 1), Point(2, 1), Point(1, 1)});
  for (auto&& i : this->body_) {
    i.Dot("��");
  }
  this->direction_ = Direction::kRight;
}
