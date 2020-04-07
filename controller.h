#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

class Controller {
 public:
  void Game(void);  // �����ƺ���

 private:
  int speed_;                            // �ٶȣ�ԽСԽ��
  std::string difficulty_;               // �Ѷ�
  int score_;                            // �÷�
  void InitWindow(void);                 // ��ʼ�����ڱ���ʹ�С
  void InitProps(const int difficulty);  // ��������
  int Welcome(void);                     // ��ӭ����
  int Pause(void);                       // ��ͣ��Ϸ
  int GameOver(void);                    // ��Ϸ����
  void UpdateStatus(void);               // ���±���
};

#endif  // CONTROLLER_H
