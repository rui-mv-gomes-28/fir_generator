#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QVBoxLayout>
#include <QDebug>
#include <vector>
#include <QtMath>
#include <cmath>
#include <QValueAxis>
#include <QMessageBox>
#include <QFile>


enum WindType {
    Rectangular,
    Triangular,
    Welch,
    Sine,
    Hann,
    Hamming,
    Blackman,
    Nuttall,
    BlackmanNuttall,
    BlackmanHarris,
    FlatTop
};

enum FilterType {
    LowPass,
    HighPass,
    BandPass,
    BandStop
};


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /* Parameters */
    double sampleTimeS;
    double cuttoffFrequencyHz;
    double cuttoffFrequency2Hz;
    int numTotalSamples;
    int numShiftSamples;
    int numFreqSamples;
    WindType winType;
    FilterType filterType;

    /* Time Domain */
    std::vector<double> timeVector;
    std::vector<double> impulseResponse;
    std::vector<double> stepResponse;
    std::vector<double> window;
    std::vector<double> windowedImpulseResponse;
    std::vector<double> windowedStepResponse;

    /* Frequency Domain */
    std::vector<double> frequencyVectorHz;
    std::vector<double> impRespMag;
    std::vector<double> winRespMag;
    std::vector<double> winMag;

    /* functions */
    void FrmMain_Load();
    void ComputeTimeVector();
    void ComputeWindow();
    void ComputeResponses();
    void ComputeWindowedResponses();
    void ComputeFrequencyVector();
    void ComputeRespBode();
    void ComputeWindowDFT();

    double GetGainAtCutOff();
    void UpdatePlotSettings();

    void UpdateCharts();

private slots:
    void on_designFilter_clicked();
    void onSave();

private:
    Ui::MainWindow *ui;
    QChartView *createChartView(QLineSeries * series);

};
#endif // MAINWINDOW_H
