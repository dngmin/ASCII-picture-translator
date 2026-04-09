#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
const std::string ascii_simple = "@%#*+=-:. ";
const std::string ascii_complicated = R"($@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'. )";

// ユーザーセッティング
const int wanted_max_width_pixel_size = 200;
const std::string ascii = ascii_simple;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "[EN]please input Image file path" << std::endl;
        std::cout << "[JP]画像ファイルのパスを入力してください。" << std::endl;
        std::cout << "[KO]이미지 파일 경로를 입력해주세요." << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        return 0;
    }

    std::string Image_path = argv[1];
    cv::Mat img, img_gray;
    img = cv::imread(Image_path);
    if (img.empty())
    {
        std::cout << "[Error] Could not open or fine the image!" << std::endl;
        return -1;
    }
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

    int height = img.rows, width = img.cols;
    int divide_scale = (width <= wanted_max_width_pixel_size? 1 : width/wanted_max_width_pixel_size + 1);
    int ascii_index;
    // 浮動小数点で宣言しても int / intは intなのでどちらかに小数点をつける
    double color_scale_threshold = 256.0 / ascii.size();

    for (int row = 0; row < height; row+=divide_scale*2)
    {
        for (int col = 0; col < width; col+=divide_scale)
        {
            ascii_index = int(img_gray.at<uchar>(row,col)) / color_scale_threshold;
            std::cout << ascii[ascii_index];
        }
        std::cout << std::endl;
    }

    cv::imshow("Source Image", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}