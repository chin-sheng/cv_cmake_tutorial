# CPP Tutorial Howework 1

## 作業題目
- 將 test_knn.py 裡的內容換成 C++ 版本, 包括但不限於以下內容
  - data/digits.png 分成 5000 個 20 * 20 的圖片
  - 每個 20 * 20 的圖片 flatten 成 400 * 1 的向量
  - 5000 個向量分成 2500 個向量為訓練資料, 2500 個為驗證資料
  - 訓練 knn 並驗證其正確性
  - 正確預測 data/test_data/3.png, data/test_data/8.png

## 作業完成條件
- 修改以下四個檔案
  - src/knn_test.cpp
  - src/knn_train.cpp
  - Dockerfile
  - CMakeLists.txt
- 使得啟動 container 時, 可以執行執行結果 
  
