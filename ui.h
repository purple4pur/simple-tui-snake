#pragma once
#ifndef UI_H
#define UI_H

#include <string>

namespace Ui {

void WelcomeUi(void);              // ��ӭ����
void WelcomeUi(const int select);  // ��ӭ�������ѡ��
void PauseUi(void);                // ��ͣ����
void PauseUi(const int select);    // ��ͣ�������ѡ��
void GameOverUi(const std::string difficulty, const int score);  // ��Ϸ��������
void GameOverUi(const int select);  // ��Ϸ�����������ѡ��

}  // namespace Ui

#endif  // UI_H
