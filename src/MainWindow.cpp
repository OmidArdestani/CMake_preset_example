#include "MainWindow.h"

#include <QApplication>
#include <QFont>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Qt CMake Preset Sample"));
    setMinimumSize(360, 220);
    setupUi();
}

void MainWindow::setupUi()
{
    // ── Central widget ───────────────────────────────────────────────────
    auto *central = new QWidget(this);
    setCentralWidget(central);

    auto *rootLayout = new QVBoxLayout(central);
    rootLayout->setContentsMargins(20, 20, 20, 20);
    rootLayout->setSpacing(12);

    // ── Title ────────────────────────────────────────────────────────────
    m_titleLabel = new QLabel(tr("Counter Demo"), central);
    QFont titleFont = m_titleLabel->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    m_titleLabel->setFont(titleFont);
    m_titleLabel->setAlignment(Qt::AlignCenter);
    rootLayout->addWidget(m_titleLabel);

    // ── Counter display ──────────────────────────────────────────────────
    m_counterLabel = new QLabel(central);
    QFont countFont = m_counterLabel->font();
    countFont.setPointSize(32);
    m_counterLabel->setFont(countFont);
    m_counterLabel->setAlignment(Qt::AlignCenter);
    updateLabel();
    rootLayout->addWidget(m_counterLabel);

    // ── Step control ─────────────────────────────────────────────────────
    auto *stepGroup = new QGroupBox(tr("Step"), central);
    auto *stepLayout = new QHBoxLayout(stepGroup);
    m_stepBox = new QSpinBox(stepGroup);
    m_stepBox->setRange(1, 100);
    m_stepBox->setValue(1);
    stepLayout->addWidget(m_stepBox);
    rootLayout->addWidget(stepGroup);

    // ── Buttons ──────────────────────────────────────────────────────────
    auto *btnLayout = new QHBoxLayout;
    m_incrementBtn = new QPushButton(tr("Increment"), central);
    m_resetBtn     = new QPushButton(tr("Reset"),     central);
    btnLayout->addWidget(m_incrementBtn);
    btnLayout->addWidget(m_resetBtn);
    rootLayout->addLayout(btnLayout);

    // ── Status bar ───────────────────────────────────────────────────────
    statusBar()->showMessage(tr("Ready"));

    // ── Connections ──────────────────────────────────────────────────────
    connect(m_incrementBtn, &QPushButton::clicked, this, &MainWindow::onCounterClicked);
    connect(m_resetBtn,     &QPushButton::clicked, this, &MainWindow::onResetClicked);
}

void MainWindow::onCounterClicked()
{
    m_count += m_stepBox->value();
    updateLabel();
    statusBar()->showMessage(tr("Incremented by %1").arg(m_stepBox->value()));
}

void MainWindow::onResetClicked()
{
    m_count = 0;
    updateLabel();
    statusBar()->showMessage(tr("Counter reset"));
}

void MainWindow::updateLabel()
{
    m_counterLabel->setText(QString::number(m_count));
}
