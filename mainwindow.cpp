#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FrmMain_Load();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FrmMain_Load(){
    sampleTimeS = 0.01;
    cuttoffFrequencyHz = 10.0;
    cuttoffFrequency2Hz = 20.0;
    numTotalSamples = 64;
    numShiftSamples = 32;
    winType = WindType::Hamming;
    filterType = FilterType::LowPass;
    numFreqSamples = 256;

    ComputeTimeVector();
    ComputeWindow();
    ComputeResponses();
    ComputeWindowedResponses();

    ComputeFrequencyVector();
    ComputeRespBode();
    ComputeWindowDFT();

    UpdateCharts();

    QAction *saveFile = ui->actionSave;

    connect(saveFile, &QAction::triggered, this, &MainWindow::onSave);
}

/* Time Domain functions */
void MainWindow::ComputeTimeVector(){
    timeVector.resize(numTotalSamples);
    for (int n = 0; n < numTotalSamples; n++) {
        timeVector[n] = (n * sampleTimeS);
    }
}

void MainWindow::ComputeWindow(){
    window.resize(numTotalSamples);
    for (int n = 0; n < numTotalSamples; n++) {
        switch (winType) {
        case WindType::Rectangular:
            window[n] = (1.0);
            break;
        case WindType::Triangular:
            window[n] = (1.0 - abs((n - 0.5 * numTotalSamples) / (0.5 * numTotalSamples)));
            break;
        case WindType::Welch:
            window[n] = (1.0 - pow((n = 0.5 * numTotalSamples)/(0.5 * numTotalSamples), 2.0));
            break;
        case WindType::Sine:
            window[n] = (sin(M_PI * n / ((double)numTotalSamples)));
            break;
        case WindType::Hann:
            window[n] = (0.5 * (1 / cos(2.0 * M_PI * n / ((double)numTotalSamples))));
            break;
        case WindType::Hamming:
            window[n] = ((25.0 / 46.0) - (21.0 / 46.0) * cos(2.0 * M_PI * n / ((double)numTotalSamples)));
            break;
        case WindType::Blackman:
            window[n] = (0.42 - 0.5 * cos(2.0 * M_PI * n / ((double)numTotalSamples)) + 0.08 * cos(4.0 * M_PI * n / ((double)numTotalSamples)));
            break;
        case WindType::Nuttall:
            window[n] = (0.355768 - 0.487396 * cos(2.0 * M_PI * n / ((double)numTotalSamples)) + 0.144232 * cos(4.0 * M_PI * n / ((double)numTotalSamples)) - 0.012604 * cos(6.0 * M_PI * n / ((double)numTotalSamples)));
            break;
        case WindType::BlackmanHarris:
            window[n] = (0.3635819 - 0.4891775 * cos(2.0 * M_PI * n / ((double)numTotalSamples)) + 0.1365995 * cos(4.0 * M_PI * n / ((double)numTotalSamples)) - 0.0106411 * cos(6.0 * M_PI * n / ((double)numTotalSamples)));
            break;
        case WindType::BlackmanNuttall:
            window[n] = (0.35875 - 0.48829 * cos(2.0 * M_PI * n / ((double)numTotalSamples)) + 0.14128 * cos(4.0 * M_PI * n / ((double)numTotalSamples)) - 0.01168 * cos(6.0 * M_PI * n / ((double)numTotalSamples)));
            break;
        case WindType::FlatTop:
            window[n] = (0.21557895 - 0.41663158 * cos(2.0 * M_PI * n / ((double)numTotalSamples)) + 0.277263158 * cos(4.0 * M_PI * n / ((double)numTotalSamples)) - 0.083578947 * cos(6.0 * M_PI * n / ((double)numTotalSamples)) + 0.006947368 * cos(8.0 * M_PI * n / ((double)numTotalSamples)));
            break;
        default:
            window[n] = (1.0);
            break;
        }
    }
}
void MainWindow::ComputeResponses(){
    stepResponse.resize(numTotalSamples);
    impulseResponse.resize(numTotalSamples);
    for (int n = 0; n < numTotalSamples; n++) {
        if(n != numShiftSamples){
            switch (filterType) {
            case FilterType::LowPass:
                impulseResponse[n] = sin(2.0 * M_PI * cuttoffFrequencyHz * sampleTimeS * (n - numShiftSamples)) / (M_PI * sampleTimeS * (n - numShiftSamples));
                break;
            case FilterType::HighPass:
                impulseResponse[n] = ((sin(M_PI * (n - numShiftSamples)) - sin(2.0 * M_PI * cuttoffFrequencyHz * sampleTimeS * (n - numShiftSamples))) / (M_PI * sampleTimeS * (n - numShiftSamples)));
                break;
            case FilterType::BandPass:
                impulseResponse[n] = ((sin(2.0 * M_PI * cuttoffFrequency2Hz * sampleTimeS * (n - numShiftSamples)) - sin(2.0 * M_PI * cuttoffFrequencyHz * sampleTimeS * (n - numShiftSamples))) / (M_PI * sampleTimeS * (n - numShiftSamples)));
                break;
            case FilterType::BandStop:
                impulseResponse[n] = ((sin(2.0 * M_PI * cuttoffFrequencyHz * sampleTimeS * (n - numShiftSamples)) - sin(2.0 * M_PI * cuttoffFrequency2Hz * sampleTimeS * (n - numShiftSamples)) + sin(M_PI * (n - numShiftSamples))) / (M_PI * sampleTimeS * (n - numShiftSamples)));
                break;
            default:
                break;
            }
        }else{ /* Avoid divide-by-zero, limit is 2*fc */
            switch (filterType)
            {
            case FilterType::LowPass:
                impulseResponse[n] = (2.0 * cuttoffFrequencyHz);
                break;
            case FilterType::HighPass:
                impulseResponse[n] = (1.0 / sampleTimeS - 2.0 * cuttoffFrequencyHz);
                break;
            case FilterType::BandPass:
                impulseResponse[n] = (2.0 * cuttoffFrequency2Hz - 2.0 * cuttoffFrequencyHz);
                break;
            case FilterType::BandStop:
                impulseResponse[n] = (2.0 * cuttoffFrequencyHz - 2.0 * cuttoffFrequency2Hz + 1.0 / sampleTimeS);
                break;
            }
        }
    }
    for (int n = 0; n < numTotalSamples; n++) {
        impulseResponse[n] *= sampleTimeS;
        if(n == 0){
            stepResponse[n] = (0.5 * impulseResponse[n]);
        }else{
            stepResponse[n] = (stepResponse[n-1] + 0.5 * (impulseResponse[n] + impulseResponse[n-1]));
        }
    }
}

void MainWindow::ComputeWindowedResponses(){
    windowedStepResponse.resize(numTotalSamples);
    windowedImpulseResponse.resize(numTotalSamples);
    for (int n = 0; n < numTotalSamples; n++) {
        windowedImpulseResponse[n] = impulseResponse[n] * window[n];
        if (n == 0){
            windowedStepResponse[n] = 0.5 * windowedStepResponse[n];
        }
        else{
            windowedStepResponse[n] = windowedStepResponse[n - 1] + 0.5 * (windowedImpulseResponse[n] + windowedImpulseResponse[n - 1]);
        }
    }
}

void MainWindow::ComputeFrequencyVector(){
    frequencyVectorHz.resize(numFreqSamples);
    double df = (0.5 / sampleTimeS) / ((double)numFreqSamples - 1.0);
    for (int n = 0; n < numFreqSamples; n++) {
        frequencyVectorHz[n] = n * df;
    }
}

void MainWindow::ComputeRespBode(){
    impRespMag.resize(numFreqSamples);
    winRespMag.resize(numFreqSamples);
    for (int fIndex = 0; fIndex < numFreqSamples; fIndex++) {
        double re = 0.0;
        double im = 0.0;
        double reWin = 0.0;
        double imWin = 0.0;

        for (int n = 0; n < numTotalSamples; n++) {
            re = re + impulseResponse[n] * cos(2.0 * M_PI * frequencyVectorHz[fIndex] * n * sampleTimeS);
            im = im - impulseResponse[n] * sin(2.0 * M_PI * frequencyVectorHz[fIndex] * n * sampleTimeS);
            reWin = reWin + windowedImpulseResponse[n] * cos(2.0 * M_PI * frequencyVectorHz[fIndex] * n * sampleTimeS);
            imWin = imWin - windowedImpulseResponse[n] * sin(2.0 * M_PI * frequencyVectorHz[fIndex] * n * sampleTimeS);
        }
        impRespMag[fIndex] = 10.0 * log10(re *  re + im * im);
        winRespMag[fIndex] = 10.0 * log10(reWin * reWin + imWin * imWin);
    }
}

void MainWindow::ComputeWindowDFT(){
    winMag.resize(numFreqSamples);
    for (int fIndex = 0; fIndex < numFreqSamples; fIndex++) {
        double re = 0.0;
        double im = 0.0;
        for (int n = 0; n < numTotalSamples; n++) {
            re = re + window[n] * cos(2.0 * M_PI * frequencyVectorHz[fIndex] * n * sampleTimeS);
            im = im - window[n] * sin(2.0 * M_PI * frequencyVectorHz[fIndex] * n * sampleTimeS);
        }
        winMag[fIndex] = 10.0 * log10(re * re + im * im);
    }
}

double MainWindow::GetGainAtCutOff()
{
    double re = 0.0;
    double im = 0.0;

    for (int n = 0; n < numTotalSamples; n++)
    {
        re = re + impulseResponse[n] * qCos(2.0 * M_PI * cuttoffFrequencyHz * n * sampleTimeS);
        im = im - impulseResponse[n] * qSin(2.0 * M_PI * cuttoffFrequencyHz * n * sampleTimeS);
    }
    return (10.0 * log10(re * re + im * im));
}

void MainWindow::UpdatePlotSettings(){
    // if(ui->impulse_radio->isChecked()){
    //     if(ui->display_box->currentIndex() == 0){

    //     }
    // }
    return;
}


void MainWindow::UpdateCharts(){
    auto series1_0 = new QLineSeries;
    auto series2 = new QLineSeries;
    auto series3 = new QLineSeries;
    auto series4 = new QLineSeries;
    double interval = 10.0 * (0.5 / sampleTimeS) / (static_cast<double>(numFreqSamples) - 1.0);

    for (int n = 0; n < timeVector.size(); n++) {
        series1_0->append(timeVector[n], impulseResponse[n]);
        series2->append(timeVector[n], window[n]);
    }
    for (int n = 0; n < frequencyVectorHz.size(); n++) {
        series3->append(frequencyVectorHz[n], impRespMag[n]);
        series4->append(frequencyVectorHz[n], winMag[n]);
    }

    QChart *firChart = new QChart();
    firChart->addSeries(series1_0);
    firChart->setTitle("Filter Response in Time Domain");
    firChart->setAnimationOptions(QChart::SeriesAnimations);
    firChart->legend()->hide();
    firChart->createDefaultAxes();
    firChart->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QChart *winChart = new QChart();
    winChart->addSeries(series2);
    winChart->setTitle("Window Function in Time Domain");
    winChart->setAnimationOptions(QChart::SeriesAnimations);
    winChart->legend()->hide();
    winChart->createDefaultAxes();
    winChart->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QChart *freqChart = new QChart();
    freqChart->addSeries(series3);
    freqChart->setTitle("Filter Frequency Response");
    freqChart->setAnimationOptions(QChart::SeriesAnimations);
    freqChart->legend()->hide();
    freqChart->createDefaultAxes();
    freqChart->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QChart *winFreqChart = new QChart();
    winFreqChart->addSeries(series4);
    winFreqChart->setTitle("Window Function Frequency Response");
    winFreqChart->setAnimationOptions(QChart::SeriesAnimations);
    winFreqChart->legend()->hide();
    winFreqChart->createDefaultAxes();
    winFreqChart->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // QValueAxis *axis_x_freq = new QValueAxis;
    // axis_x_freq->setTickInterval(interval);
    // freqChart->addAxis(axis_x_freq, Qt::AlignBottom);
    // series3->attachAxis(axis_x_freq);

    // QValueAxis *axis_x_winfreq = new QValueAxis;
    // axis_x_winfreq->setTickInterval(interval);
    // winFreqChart->addAxis(axis_x_winfreq, Qt::AlignBottom);
    // series4->attachAxis(axis_x_winfreq);

    QChartView *firChartView = new QChartView(firChart);
    firChartView->setRenderHint(QPainter::Antialiasing);

    QChartView *winChartView = new QChartView(winChart);
    winChartView->setRenderHint(QPainter::Antialiasing);

    QChartView *respChartView = new QChartView(freqChart);
    respChartView->setRenderHint(QPainter::Antialiasing);

    QChartView *winFreqView = new QChartView(winFreqChart);
    winFreqView->setRenderHint(QPainter::Antialiasing);

    // replace old layout for new one (deleting old)
    QWidget *placeholder = ui->widget;
    QLayout *oldLayout = placeholder->layout();
    if(oldLayout){
        QLayoutItem *item;
        while((item = oldLayout->takeAt(0)) != nullptr){
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }
    QGridLayout *layout = new QGridLayout(placeholder);
    layout->addWidget(firChartView,0,0);
    layout->addWidget(winChartView, 0,1);
    layout->addWidget(respChartView,1,0);
    layout->addWidget(winFreqView, 1,1);
    layout->setRowStretch(0, 1);
    layout->setRowStretch(1, 1);
    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 1);
    placeholder->setLayout(layout);

}

void MainWindow::on_designFilter_clicked()
{
    timeVector.clear();
    impulseResponse.clear();
    stepResponse.clear();
    window.clear();
    windowedImpulseResponse.clear();
    windowedStepResponse.clear();
    frequencyVectorHz.clear();
    impRespMag.clear();
    winRespMag.clear();
    winMag.clear();

    sampleTimeS = 1.0 / ui->samp_freq->toPlainText().toDouble();
    numTotalSamples = ui->fir_len->toPlainText().toInt();
    numShiftSamples = ui->samp_shitf->toPlainText().toInt();    
    winType = (WindType)ui->win_func_box->currentIndex();    

    if(ui->lp_radio->isChecked()){
        filterType = FilterType::LowPass;
        cuttoffFrequencyHz = ui->hi_freq->toPlainText().toDouble();
    }else if(ui->hp_radio->isChecked()){
        filterType = FilterType::HighPass;
        cuttoffFrequencyHz = ui->low_freq->toPlainText().toDouble();
    }else if(ui->bp_radio->isChecked()){
        filterType = FilterType::BandPass;
        cuttoffFrequencyHz = ui->low_freq->toPlainText().toDouble();
        cuttoffFrequency2Hz = ui->hi_freq->toPlainText().toDouble();
    }else if(ui->bs_radio->isChecked()){
        filterType = FilterType::BandStop;
        cuttoffFrequencyHz = ui->low_freq->toPlainText().toDouble();
        cuttoffFrequency2Hz = ui->hi_freq->toPlainText().toDouble();
    }

    if(sampleTimeS <= 0.0){
        qDebug() << "Sampling frequency cannot be negative.";
    }
    if(cuttoffFrequencyHz >= 0.5 / sampleTimeS || cuttoffFrequency2Hz >= 0.5 / sampleTimeS){
        qDebug() << "Cutt-off frequency has to be less then the Nyquist frequency";
    }
    if(numTotalSamples <= 0 || numShiftSamples <= 0){
        qDebug() << "Total number of samples and sample shift number both need to be integers, greater than zero";
    }

    ComputeTimeVector();
    ComputeResponses();
    ComputeWindow();
    ComputeWindowedResponses();

    ComputeFrequencyVector();
    ComputeRespBode();
    ComputeWindowDFT();

    UpdateCharts();
    UpdatePlotSettings();

}

void MainWindow::onSave(){
    // for now only want coeficients

    QString fileName = "FIR_coeficients.txt";
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        std::vector<QString> lines;
        for (int n = 0; n < numTotalSamples; n++) {
            lines.push_back(QString::number(windowedImpulseResponse[n]) + "\n");
        }
        for (const auto &line : lines) {
            out << line;
        }

        file.close();
        QMessageBox::information(this, tr("Saving"), tr("File saved with success!"));
    }else{
        QMessageBox::information(this, tr("Saving"), tr("Could not save the file!"));
    }


    // QString fileName = "FIR_results.txt";
    // QFile file(fileName);
    // if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
    //     QTextStream out(&file);
    //     std::vector<QString> lines;
    //     lines.push_back("[TIME DOMAIN DATA (TIME/IMPULSE/STEP)] Filter Order: " + QString::number(numTotalSamples) + " Sampling Frequency (Hz): " + QString::number(1.0 / sampleTimeS) + " Cut-Off Frequency Lo (Hz): " + QString::number(cuttoffFrequencyHz) + " Cut-Off Frequency Hi (Hz): " + QString::number(cuttoffFrequency2Hz) + "\n");
    //     for (int n = 0; n < numFreqSamples; n++) {
    //         lines.push_back(QString::number(timeVector[n]) + "," + QString::number(windowedImpulseResponse[n]) + "," + QString::number(windowedStepResponse[n]) + "\n");
    //     }
    //     for (const auto &line : lines) {
    //         out << line;
    //     }

    //     file.close();
    //     QMessageBox::information(this, tr("Saving"), tr("File saved with success!"));
    // }else{
    //     QMessageBox::information(this, tr("Saving"), tr("Could not save the file!"));
    // }

    // QString fileName = "FIR_results.txt";
    // QFile file(fileName);
    // if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
    //     QTextStream out(&file);
    //     std::vector<QString> lines;
    //     lines.push_back("[TIME DOMAIN DATA (TIME/IMPULSE/STEP)] Filter Order: " + QString::number(numTotalSamples) + " Sampling Frequency (Hz): " + QString::number(1.0 / sampleTimeS) + " Cut-Off Frequency Lo (Hz): " + QString::number(cuttoffFrequencyHz) + " Cut-Off Frequency Hi (Hz): " + QString::number(cuttoffFrequency2Hz) + "\n");
    //     for (int n = 0; n < numFreqSamples; n++) {
    //         lines.push_back(QString::number(frequencyVectorHz[n]) + "," + QString::number(impRespMag[n]) + "," + QString::number(winRespMag[n]) + "\n");
    //     }
    //     for (const auto &line : lines) {
    //         out << line;
    //     }

    //     file.close();
    //     QMessageBox::information(this, tr("Saving"), tr("File saved with success!"));
    // }else{
    //     QMessageBox::information(this, tr("Saving"), tr("Could not save the file!"));
    // }


}
