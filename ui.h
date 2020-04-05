#pragma once
#ifndef UI_H
#define UI_H

#include <string>

namespace Ui {

void WelcomeUi(void);              // 欢迎界面
void WelcomeUi(const int select);  // 欢迎界面绘制选项
void PauseUi(void);                // 暂停界面
void PauseUi(const int select);    // 暂停界面绘制选项
void GameOverUi(const std::string difficulty, const int score);  // 游戏结束界面
void GameOverUi(const int select);  // 游戏结束界面绘制选项

}  // namespace Ui

#endif  // UI_H
