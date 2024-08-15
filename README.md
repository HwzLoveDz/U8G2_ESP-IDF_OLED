# U8G2_ESP-IDF_OLED
Port the U8G2 display driver library (which includes all drivers, fonts, and function methods) to an ESP-IDF component and provide an example.
## 初始化与其他方法请参阅官方Wiki，超级详细：https://github.com/olikraus/u8g2/wiki/u8g2setupc
## 如何使用例程
* 在`main`文件夹下的`CMakeLists.txt`文件中禁用或启用例程即可。一次只能取消注释一个例程，否则会如你所愿的报错。
![image](https://github.com/user-attachments/assets/29c91290-4475-45d7-9578-bfe387e12d28)
* 在接口库设置 I2C 引脚与频率
![image](https://github.com/user-attachments/assets/ae019071-307f-4490-83e6-57ff18779245)
* 例程为动态与静态页面缓存刷屏例程
![image](https://github.com/user-attachments/assets/77467168-16be-4ea5-81d0-e33cecbeaa30)
