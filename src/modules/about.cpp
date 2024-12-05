#include "about.h"

#include <QLabel>

About::About(QWidget *parent)
    : QScrollArea(parent)
{
    QLabel *label = new QLabel;
    label->setWordWrap(true);
    setWidgetResizable(true);
    setFocusPolicy(Qt::NoFocus);
    setFrameStyle(QFrame::NoFrame);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
    setContentsMargins(0, 0, 0, 0);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setWidget(label);

    label->setMargin(20);

    QString text;


    text = QString("<body style=\"line-height: 18px;font-size:12px;font-style: normal;\">"
                    "<div style=\"font-style: medium;font-size: 16px;\">%1</div>"
                    "<br>%2"
                    "<br><div style=\"font-style: medium;font-size: 16px;\">%3</div>"
                    "<ul><li>%4</li></ul>"
                    "%5"
                    "<ul><li>%6</li></ul>"
                    "%7"
                    "<ul><li>%8</li></ul>"
                    "%9"
                    "<br><div style=\"font-style: medium;font-size: 16px;\">%10</div>"
                    "<br>%11</body>")
            .arg(tr("About us"))
            .arg(tr("GXDE OS is an Debian based Linux distro featuring GXDE Desktop Environment. It offers an elegant, beautifu, light weight and out-of-the-box experience."))
            .arg(tr("Features"))
            .arg(tr("Classic and Extended Deepin DE Experience"))
            .arg(tr("GXDE Desktop, rebirth from the deepin 15 era, not only brings back the classic experience but also introduces a range of extended components, experience enhancements, and bug fixes. It offers both familiarity and innovation, ensuring a smoother and more versatile user experience."))
            .arg(tr("Various Components and Experiences "))
            .arg(tr("GXDE OS integrates several community open-source projects, including a top bar, global menu, Spark App Store, AmberCE compatibility environment, and fantascene dynamic wallpapers. It supports the deepin Linyaps package too. "))
            .arg(tr("One-Click App Installation without typing commands. "))
            .arg(tr("Spark APP Store is built in with GXDE OS, enabling users to effortlessly discover and install essential applications without needing to use the command line. Also, simply replace apt with aptss will apt with aptss command can boost your download speed."))
            .arg(tr("Open source project"))
            .arg(tr("GXDE is an open source desktop system developed for common users. You are free to download, distribute, modify and use it. Your Support is Our Greatest Motivation. Detailed address is https://gitee.com/GXDE-OS"));


    label->setText(text);
}
