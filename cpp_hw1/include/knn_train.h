#include <vector>
#include <string>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/ml/ml.hpp>  


class TrainDigit
{
  public:
    void train_val_split(cv::Mat& img);
    void train();
    void validation();
    void save_model(std::string out_model_path);

  private:
    cv::Mat TrainLabel;
    cv::Mat ValLabel;
    cv::Mat TrainData;
    cv::Mat ValData;
    int image_size = 20;
    cv::Ptr<cv::ml::KNearest> kclassifier;
};

