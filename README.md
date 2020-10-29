下一个游戏开始前将上一个游戏的指令集删除
但是在第二次游戏中输入"0 0"至第二次游戏的指令运行完毕后会闪退

#### 修改成功
```c++
void resetstack(){
    delete []OB;
    OB = new int*[size];
}    

```
修改为
```c++
 void resetstack(){
     delete []OB;
     size = 0;
     length = 0;
     OB = new int*[size];
 }
```
原因分析：
> 在弹出command时由于第一次游戏的指令记录次数没有归零,导致第二次游戏时
弹出command下标越界
