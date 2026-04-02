#include "welcomemodule.h"

#include <DHiDPIHelper>
#include <QHBoxLayout>

DWIDGET_USE_NAMESPACE

WelcomeModule::WelcomeModule(QWidget *parent)
    : ModuleInterface(parent)
{
    m_selectBtn->hide();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

    m_welcomeLabel = new QLabel(this);
    m_welcomeLabel->setAlignment(Qt::AlignCenter);

    layout->addStretch(1);
    layout->addWidget(m_welcomeLabel, 0, Qt::AlignCenter);
    QLabel *titleLbl = new QLabel(this);
    titleLbl->setText(tr("Ready! GXDE is all set for you.\nEmbark on your productive journey now."));
    titleLbl->setAlignment(Qt::AlignCenter);
    titleLbl->setStyleSheet("font-size: 20px; font-weight: medium;");
    layout->addWidget(titleLbl, 0, Qt::AlignCenter);
    layout->addStretch(2);

    updateBigIcon();
}

void WelcomeModule::updateBigIcon()
{
    const QSize size(700, 450);
    setFixedSize(size);

    // 显示小图标，设置为合适的大小
    const QSize iconSize(200, 200);
    m_welcomeLabel->setFixedSize(iconSize);

    QPixmap pixmap = DHiDPIHelper::loadNxPixmap(":/resources/welcome.png");
    if (!pixmap.isNull()) {
        // 保持图像比例并适应图标大小
        pixmap = pixmap.scaled(iconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        m_welcomeLabel->setPixmap(pixmap);
    }

    m_welcomeLabel->show();
}

void WelcomeModule::updateSmallIcon()
{
    const QSize size(550, 346);
    setFixedSize(size);

    // 显示小图标，设置为合适的大小
    const QSize iconSize(150, 150);
    m_welcomeLabel->setFixedSize(iconSize);

    QPixmap pixmap = DHiDPIHelper::loadNxPixmap(":/resources/welcome.png");
    if (!pixmap.isNull()) {
        // 保持图像比例并适应图标大小
        pixmap = pixmap.scaled(iconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        m_welcomeLabel->setPixmap(pixmap);
    }

    m_welcomeLabel->show();
}

void WelcomeModule::updateSelectBtnPos() {}
