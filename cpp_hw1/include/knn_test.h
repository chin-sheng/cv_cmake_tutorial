#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/ml/ml.hpp>  


class TestDigit
{
  public:
    void load_model(std::string model_path);
    float inference(cv::Mat& img); //預測結果

  private:
    int image_size = 20;
    cv::Ptr<cv::ml::KNearest> kclassifier;
};