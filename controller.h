#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

class Controller {
 public:
  void Game(void);  // 主控制函数

 private:
  int speed_;                            // 速度，越小越快
  std::string difficulty_;               // 难度
  int score_;                            // 得分
  void InitWindow(void);                 // 初始化窗口标题和大小
  void InitProps(const int difficulty);  // 设置属性
  int Welcome(void);                     // 欢迎界面
  int Pause(void);                       // 暂停游戏
  int GameOver(void);                    // 游戏结束
  void UpdateStatus(void);               // 更新标题
};

#endif  // CONTROLLER_H
