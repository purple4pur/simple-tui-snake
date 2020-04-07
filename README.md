# simple-tui-snake

非常简陋的贪吃蛇，纯 Cpp，文本界面，运行在控制台 (CMD)。

写这个这么菜的玩意儿是一次简单的尝试，读其他人的 [贪吃蛇游戏源码](https://github.com/silence1772/GreedySnake) ，然后自己实现一遍，这个过程还是非常有价值的（在看得懂源码的前提下，再次感谢大佬的详细注释）。

已更新所有代码的注释！并且，希望在有生之年能让可爱的小蛇自己跑起来！gkd!

## 本地编译

注意，除了此 RP 内的文件外，编译还依赖另一个又简单又菜的 Cpp 库 [library_cpp](https://github.com/purple4pur/library_cpp) ，并且需要正确的相对路径。

```
git clone git@github.com:purple4pur/library_cpp.git
git clone git@github.com:purple4pur/simple-tui-snake.git
cd ./simple-tui-snake
make
```

## 特别注意

所有代码文件都采用了 GB 2312 编码，当然了，编译出来的玩意儿也就需要在 GB 2312 环境下才能正确显示。

害，还是太菜了。

欢迎来 Issues 批评这么菜的我，暂不接受 PR。
