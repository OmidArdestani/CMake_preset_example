#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private slots:
    void onCounterClicked();
    void onResetClicked();

private:
    void setupUi();
    void updateLabel();

    int m_count{0};

    QLabel    *m_titleLabel{nullptr};
    QLabel    *m_counterLabel{nullptr};
    QPushButton *m_incrementBtn{nullptr};
    QPushButton *m_resetBtn{nullptr};
    QSpinBox  *m_stepBox{nullptr};
};
