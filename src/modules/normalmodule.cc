/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     kirigaya <kirigaya@mkacg.com>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "normalmodule.h"
#include "../widgets/navigationbutton.h"
#include "desktopmodemodule.h"
#include "iconmodule.h"
#include "wmmodemodule.h"
#include "videowidget.h"

NormalModule::NormalModule(QWidget *parent)
    : QWidget(parent)
    , m_leftNavigationLayout(new QVBoxLayout)
    , m_rightContentLayout(new QVBoxLayout)
    , m_buttonGrp(new QButtonGroup)
    , m_currentWidget(nullptr)
{
    QWidget *content = new QWidget;
    content->setLayout(m_rightContentLayout);

    QHBoxLayout *layout = new QHBoxLayout(this);

    m_leftNavigationLayout->setMargin(0);

    m_rightContentLayout->setSpacing(0);
    m_rightContentLayout->setMargin(0);

    layout->setMargin(0);
    layout->setSpacing(0);

    layout->addLayout(m_leftNavigationLayout);
    layout->addWidget(content);

    setLayout(layout);

    setMinimumSize(900, 450);
    content->setFixedSize(700, 450);

    NavigationButton * videoBtn = new NavigationButton;
    NavigationButton * desktopBtn = new NavigationButton;
    NavigationButton * iconBtn = new NavigationButton;
    NavigationButton * wmBtn = new NavigationButton;

    VideoWidget *video = new VideoWidget;
    DesktopModeModule *desktop = new DesktopModeModule;
    IconModule *icon = new IconModule;
    WMModeModule *wm = new WMModeModule;

    m_rightContentLayout->addWidget(video);
    m_rightContentLayout->addWidget(desktop);
    m_rightContentLayout->addWidget(icon);
    m_rightContentLayout->addWidget(wm);

    video->setFixedSize(700, height());
    desktop->setFixedSize(700, height());
    icon->setFixedSize(700, height());
    wm->setFixedSize(700, height());

    video->hide();
    desktop->hide();
    icon->hide();
    wm->hide();

    m_moduleMap[videoBtn] = video;
    m_moduleMap[desktopBtn] = desktop;
    m_moduleMap[iconBtn] = icon;
    m_moduleMap[wmBtn] = wm;

    m_currentWidget = video;

    videoBtn->setFixedWidth(200);
    desktopBtn->setFixedWidth(200);
    iconBtn->setFixedWidth(200);
    wmBtn->setFixedWidth(200);

    m_buttonGrp->addButton(videoBtn);
    m_buttonGrp->addButton(desktopBtn);
    m_buttonGrp->addButton(iconBtn);
    m_buttonGrp->addButton(wmBtn);

    m_buttonGrp->setExclusive(true);

    m_leftNavigationLayout->addStretch();
    m_leftNavigationLayout->addWidget(videoBtn, 0, Qt::AlignLeft | Qt::AlignVCenter);
    m_leftNavigationLayout->addWidget(desktopBtn, 0, Qt::AlignLeft | Qt::AlignVCenter);
    m_leftNavigationLayout->addWidget(iconBtn, 0, Qt::AlignLeft | Qt::AlignVCenter);
    m_leftNavigationLayout->addWidget(wmBtn, 0, Qt::AlignLeft | Qt::AlignVCenter);
    m_leftNavigationLayout->addStretch();

    connect(m_buttonGrp, static_cast<void (QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonClicked), this, [=] (QAbstractButton *btn) {
        QWidget *w = m_moduleMap[btn];
        m_currentWidget->hide();
        w->show();
        m_currentWidget = w;
    });
}