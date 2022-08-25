#include <vector>
#include <string>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/ml/ml.hpp>  


class TrainDigit
{
  public:
    void train_val_split(cv::Mat& img); // 將 TrainLabel, ValLabel, TrainData, ValData 賦值
    void train(); // 利用 TrainLabel, TrainData 訓練 knn
    void validation(); // 利用 ValLabel, ValData 驗證 knn
    void save_model(std::string out_model_path); // 儲存 model

  private:
    cv::Mat TrainLabel;
    cv::Mat ValLabel;
    cv::Mat TrainData;
    cv::Mat ValData;
    int image_size = 20;
    cv::Ptr<cv::ml::KNearest> kclassifier;
};

