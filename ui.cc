#include "ui.h"

#include <iostream>

#include "../library_cpp/include/console.h"

// 欢迎界面
void Ui::WelcomeUi(void) {
  int line = 6;
  Console::SetCsrPos(8, line++);
  std::cout << "┌─────────────────────────┐";
  Console::SetCsrPos(8, line++);
  std::cout << "│       菜鸡の贪吃蛇      │";
  Console::SetCsrPos(8, line++);
  std::cout << "│          By Purple4pur  │";
  Console::SetCsrPos(8, line++);
  std::cout << "│                         │";
  Console::SetCsrPos(8, line++);
  std::cout << "│     方向键 - 移动       │";
  Console::SetCsrPos(8, line++);
  std::cout << "│     回车 - 选择         │";
  Console::SetCsrPos(8, line++);
  std::cout << "│     空格 - 暂停 / 选择  │";
  Console::SetCsrPos(8, line++);
  std::cout << "│                         │";
  Console::SetCsrPos(8, line++);
  std::cout << "│           简单          │";  // line 14
  Console::SetCsrPos(8, line++);
  std::cout << "│           中等          │";
  Console::SetCsrPos(8, line++);
  std::cout << "│           困难          │";
  Console::SetCsrPos(8, line++);
  std::cout << "│           地狱          │";
  Console::SetCsrPos(8, line++);
  std::cout << "│           非人哉        │";
  Console::SetCsrPos(8, line++);
  std::cout << "│           罢了          │";
  Console::SetCsrPos(8, line++);
  std::cout << "└─────────────────────────┘";
}

// 欢迎界面绘制选项
void Ui::WelcomeUi(const int select) {
  bool slt[7] = {0};
  slt[select] = true;
  for (int i = 1; i <= 6; ++i) {
    Console::SetCsrPos(12, 13 + i);
    std::cout << (slt[i] ? " ->" : "   ");
  }
  Console::SetCsrPos(0, 29);
}

// 暂停界面
void Ui::PauseUi(void) {
  int line = 9;
  Console::SetCsrPos(9, line++);
  std::cout << "┌─────────────────────┐";
  Console::SetCsrPos(9, line++);
  std::cout << "│      游戏已暂停     │";
  Console::SetCsrPos(9, line++);
  std::cout << "│                     │";
  Console::SetCsrPos(9, line++);
  std::cout << "│    继续      放弃   │";  // line 12
  Console::SetCsrPos(9, line++);
  std::cout << "└─────────────────────┘";
}

// 暂停界面绘制选项
void Ui::PauseUi(const int select) {
  bool slt[3] = {0};
  slt[select] = true;
  for (int i = 1; i <= 2; ++i) {
    Console::SetCsrPos(i * 5 + 5, 12);
    std::cout << (slt[i] ? "->" : "  ");
  }
  Console::SetCsrPos(0, 29);
}

// 游戏结束界面
void Ui::GameOverUi(const std::string difficulty, const int score) {
  int line = 9;
  Console::SetCsrPos(9, line++);
  std::cout << "┌─────────────────────┐";
  Console::SetCsrPos(9, line++);
  std::cout << "│       菜鸡认证      │";
  Console::SetCsrPos(9, line++);
  std::cout << "│                     │";
  Console::SetCsrPos(9, line++);
  std::cout << "│    难度:            │";  // line 12
  Console::SetCsrPos(9, line++);
  std::cout << "│    得分:            │";  // line 13
  Console::SetCsrPos(9, line++);
  std::cout << "│                     │";
  Console::SetCsrPos(9, line++);
  std::cout << "│    不服      认了   │";  // line 15
  Console::SetCsrPos(9, line++);
  std::cout << "└─────────────────────┘";
  Console::SetCsrPos(15, 12);
  std::cout << difficulty;
  Console::SetCsrPos(15, 13);
  std::cout << score;
}

// 游戏结束界面绘制选项
void Ui::GameOverUi(const int select) {
  bool slt[3] = {0};
  slt[select] = true;
  for (int i = 1; i <= 2; ++i) {
    Console::SetCsrPos(i * 5 + 5, 15);
    std::cout << (slt[i] ? "->" : "  ");
  }
  Console::SetCsrPos(0, 29);
}
