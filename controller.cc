#include "controller.h"

#include <Windows.h>

#include <iostream>
#include <string>

#include "../library_cpp/include/console.h"
#include "food.h"
#include "snake.h"
#include "ui.h"

// 主控制函数
void Controller::Game(void) {
  Snake snake;
  Food food;
START:
  this->InitWindow();
  Console::Clear();
  int difficulty = this->Welcome();
  if (!difficulty) {
    return;
  }
  this->SetSpeed(difficulty);
  this->UpdateStatus();
  Console::Clear();
  snake.ForcedRedraw();
  food.ForcedRedraw();
  while (true) {
    if (char key = Console::CatchKey()) {
      switch (key) {
        case ARROW_UP:
          snake.ChangeDirection(Direction::kUp);
          break;
        case ARROW_DOWN:
          snake.ChangeDirection(Direction::kDown);
          break;
        case ARROW_LEFT:
          snake.ChangeDirection(Direction::kLeft);
          break;
        case ARROW_RIGHT:
          snake.ChangeDirection(Direction::kRight);
          break;
        case SPACE:
          switch (this->Pause()) {
            case 2:
              goto GAMEOVER;
            case 1:
            default:
              Console::Clear();
              snake.ForcedRedraw();
              food.ForcedRedraw();
              break;
          }
          break;
        default:
          break;
      }
    }
    if (food.IsEaten(snake)) {
      snake.Append();
      food.Generate(snake);
      this->score_ += 20;
      this->UpdateStatus();
    } else {
      snake.Forward();
    }
    Console::SetCsrPos(0, 29);
    if (snake.HasHitBody()) {
      goto GAMEOVER;
    }
    Sleep(this->speed_);
  }
GAMEOVER:
  switch (this->GameOver()) {
    case 1:
      snake.Reset();
      food.Generate(snake);
      goto START;
    case 2:
    default:
      break;
  }
}

// 初始化窗口标题和大小
void Controller::InitWindow(void) {
  Console::SetTitle("菜鸡の贪食蛇");
  Console::SetWindowSize(30, 30);
}

// 设置速度
void Controller::SetSpeed(const int difficulty) {
  switch (difficulty) {
    case 5:
      this->speed_ = 30;
      this->difficulty_ = "非人哉";
      break;
    case 4:
      this->speed_ = 50;
      this->difficulty_ = "地狱";
      break;
    case 3:
      this->speed_ = 80;
      this->difficulty_ = "困难";
      break;
    case 2:
      this->speed_ = 120;
      this->difficulty_ = "中等";
      break;
    case 1:
    default:
      this->speed_ = 200;
      this->difficulty_ = "简单";
      break;
  }
  this->score_ = 0;
}

// 欢迎界面
// @Return: 0: 退出游戏 1-6: 难度编号
int Controller::Welcome(void) {
  Ui::WelcomeUi();
  Ui::WelcomeUi(1);
  int select = 1;
  while (char key = Console::GetKey()) {
    switch (key) {
      case ARROW_RIGHT:
      case ARROW_DOWN:
        if (select < 6) {
          ++select;
          Ui::WelcomeUi(select);
        }
        break;
      case ARROW_LEFT:
      case ARROW_UP:
        if (select > 1) {
          --select;
          Ui::WelcomeUi(select);
        }
        break;
      case RETURN:
      case SPACE:
        if (select == 6) {
          select = 0;
        }
        return select;
      default:
        break;
    }
  }
  return 0;
}

// 暂停游戏
// @Return: 1: 继续游戏 2: 退出游戏
int Controller::Pause(void) {
  Ui::PauseUi();
  Ui::PauseUi(1);
  int select = 1;
  while (char key = Console::GetKey()) {
    switch (key) {
      case ARROW_RIGHT:
      case ARROW_DOWN:
        if (select < 2) {
          ++select;
          Ui::PauseUi(select);
        }
        break;
      case ARROW_LEFT:
      case ARROW_UP:
        if (select > 1) {
          --select;
          Ui::PauseUi(select);
        }
        break;
      case RETURN:
      case SPACE:
        return select;
      default:
        break;
    }
  }
  return 0;
}

// 游戏结束
// @Return: 1: 重新开始 2: 结束游戏
int Controller::GameOver(void) {
  Ui::GameOverUi(this->difficulty_, this->score_);
  Ui::GameOverUi(1);
  int select = 1;
  while (char key = Console::GetKey()) {
    switch (key) {
      case ARROW_RIGHT:
      case ARROW_DOWN:
        if (select < 2) {
          ++select;
          Ui::GameOverUi(select);
        }
        break;
      case ARROW_LEFT:
      case ARROW_UP:
        if (select > 1) {
          --select;
          Ui::GameOverUi(select);
        }
        break;
      case RETURN:
      case SPACE:
        return select;
      default:
        break;
    }
  }
  return 0;
}

// 更新标题
void Controller::UpdateStatus(void) {
  std::string title =
      (std::string) "菜鸡の贪食蛇 / 难度: " + this->difficulty_ +
      (std::string) " / 得分: " + std::to_string(this->score_);
  Console::SetTitle(title);
}
