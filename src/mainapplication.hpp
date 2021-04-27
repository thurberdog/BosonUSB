#ifndef MAINAPPLICATION_HPP
#define MAINAPPLICATION_HPP

#include <stdio.h>
#include <fcntl.h>               // open, O_RDWR
#include <opencv2/opencv.hpp>
#include <unistd.h>              // close
#include <sys/ioctl.h>           // ioctl
#include <asm/types.h>           // videodev2.h
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/videodev2.h>
#define YUV   0
#define RAW16 1

//using namespace cv;

#define v_major 1
#define v_minor 0

// Define COLOR CODES
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// Need to clean video for linux structs to avoid some random initializations problems (not always present)
#define CLEAR(x) memset(&(x), 0, sizeof(x))

#include <QObject>

class MainApplication : public QObject
{
    Q_OBJECT
public:
    explicit MainApplication(QObject *parent = nullptr);
    // Global variables to keep this simple
    int width;
    int height;

    void print_help();
    int init(int argc, char **argv);

    // Types of sensors supported
    enum sensor_types {
      Boson320, Boson640
    };
    void AGC_Basic_Linear(cv::Mat input_16, cv::Mat output_8, int height, int width);
signals:

};

#endif // MAINAPPLICATION_HPP
