#### 2019.05.01

## Midterm ─ [Embedded System Development and OS Design](http://www.nc.es.ncku.edu.tw/course/embedded/)

#### 請 fork 此 repo ，並完成以下要求(依完整度部份給分)：

1. 使用 HSI 作為 PLL 之 clock source，將 system clock 調整為168 MHz，並使用 MCO2 輸出 (divided by 4)

2. 使綠色 LED 恆亮

3. 宣告一個 global uint32_t array，並給予初始值`{0xA, 0xB, 0xC, 0xD, 0xE, 0xF}`，使用 gdb 驗證此 global array 有成功被初始化(請將 gdb 畫面截圖存放至原始碼目錄下)

#### 請將結果 push 回自己的 github

#### 評分方式：

1. make
2. make flash
3. 綠燈恆亮
4. MCO2 輸出
5. 附圖

=============================================================================================================================================================================================================
附圖的部份出了一點狀況,感覺是我指令打錯了！



