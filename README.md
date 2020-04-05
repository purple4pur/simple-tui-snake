# simple-tui-snake

非常简陋的贪吃蛇，纯 Cpp，文本界面，运行在控制台 (CMD)。

写这个这么菜的玩意儿是一次简单的尝试，读其他人的 [贪吃蛇游戏源码](https://github.com/silence1772/GreedySnake) ，然后自己实现一遍，这个过程还是非常有价值的（在看得懂源码的前提下，再次感谢大佬的详细注释）。

后续会完善所有文件的注释，或许也在博客上水一篇详细介绍（这么菜的项目还有介绍的必要么）。

## 本地编译

注意，除了此 RP 内的文件外，编译还依赖另一个又简单又菜的 Cpp 库 [library_cpp](https://github.com/purple4pur/library_cpp) ，并且需要正确的相对路径。

```
git clone git@github.com:purple4pur/library_cpp.git
git clone git@github.com:purple4pur/simple-tui-snake.git
cd ./simple-tui-snake
make
```

## 特别注意

因为没有协调好编码，为了能正确地显示中文，所有涉及到输出的文件都采用了 GB 2312 编码，其余是默认的 UTF-8 ……当然了，最终的成品也就需要在 GB 2312 环境下才能正确显示。

害，还是太菜了。

欢迎来 Issues 批评这么菜的我，暂不接受 PR。
