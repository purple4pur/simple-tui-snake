#include "ui.h"

#include <iostream>

#include "../library_cpp/include/console.h"

// ��ӭ����
void Ui::WelcomeUi(void) {
  int line = 6;
  Console::SetCsrPos(8, line++);
  std::cout << "������������������������������������������������������";
  Console::SetCsrPos(8, line++);
  std::cout << "��       �˼���̰����      ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��          By Purple4pur  ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��                         ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��     ����� - �ƶ�       ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��     �س� - ѡ��         ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��     �ո� - ��ͣ / ѡ��  ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��                         ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��           ��          ��";  // line 14
  Console::SetCsrPos(8, line++);
  std::cout << "��           �е�          ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��           ����          ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��           ����          ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��           ������        ��";
  Console::SetCsrPos(8, line++);
  std::cout << "��           ����          ��";
  Console::SetCsrPos(8, line++);
  std::cout << "������������������������������������������������������";
}

// ��ӭ�������ѡ��
void Ui::WelcomeUi(const int select) {
  bool slt[7] = {0};
  slt[select] = true;
  for (int i = 1; i <= 6; ++i) {
    Console::SetCsrPos(12, 13 + i);
    std::cout << (slt[i] ? " ->" : "   ");
  }
  Console::SetCsrPos(0, 29);
}

// ��ͣ����
void Ui::PauseUi(void) {
  int line = 9;
  Console::SetCsrPos(9, line++);
  std::cout << "����������������������������������������������";
  Console::SetCsrPos(9, line++);
  std::cout << "��      ��Ϸ����ͣ     ��";
  Console::SetCsrPos(9, line++);
  std::cout << "��                     ��";
  Console::SetCsrPos(9, line++);
  std::cout << "��    ����      ����   ��";  // line 12
  Console::SetCsrPos(9, line++);
  std::cout << "����������������������������������������������";
}

// ��ͣ�������ѡ��
void Ui::PauseUi(const int select) {
  bool slt[3] = {0};
  slt[select] = true;
  for (int i = 1; i <= 2; ++i) {
    Console::SetCsrPos(i * 5 + 5, 12);
    std::cout << (slt[i] ? "->" : "  ");
  }
  Console::SetCsrPos(0, 29);
}

// ��Ϸ��������
void Ui::GameOverUi(const std::string difficulty, const int score) {
  int line = 9;
  Console::SetCsrPos(9, line++);
  std::cout << "����������������������������������������������";
  Console::SetCsrPos(9, line++);
  std::cout << "��       �˼���֤      ��";
  Console::SetCsrPos(9, line++);
  std::cout << "��                     ��";
  Console::SetCsrPos(9, line++);
  std::cout << "��    �Ѷ�:            ��";  // line 12
  Console::SetCsrPos(9, line++);
  std::cout << "��    �÷�:            ��";  // line 13
  Console::SetCsrPos(9, line++);
  std::cout << "��                     ��";
  Console::SetCsrPos(9, line++);
  std::cout << "��    ����      ����   ��";  // line 15
  Console::SetCsrPos(9, line++);
  std::cout << "����������������������������������������������";
  Console::SetCsrPos(15, 12);
  std::cout << difficulty;
  Console::SetCsrPos(15, 13);
  std::cout << score;
}

// ��Ϸ�����������ѡ��
void Ui::GameOverUi(const int select) {
  bool slt[3] = {0};
  slt[select] = true;
  for (int i = 1; i <= 2; ++i) {
    Console::SetCsrPos(i * 5 + 5, 15);
    std::cout << (slt[i] ? "->" : "  ");
  }
  Console::SetCsrPos(0, 29);
}
