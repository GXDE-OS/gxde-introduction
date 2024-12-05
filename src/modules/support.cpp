#include "support.h"

#include <QLabel>

Support::Support(QWidget *parent)
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
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label->setOpenExternalLinks(true);

    const QString &text = QString("<body style=\"line-height: 18px;font-size:12px;font-style: normal;\">"
                                  "<div style=\"font-style: medium;font-size: 16px;\">%1</div>"
                                  "<br>%2"
                                  "<br>%5"
                                  "<br>%6"
                                  "<br><div style=\"font-style: medium;font-size: 16px;\">%7</div>"
                                  "<br>%8"
                                  "<br>%9"
                                  "<br>%10"
                                  "<br><div style=\"font-style: medium;font-size: 16px;\">%11</div>"
                                  "<br>%12"
                                  "<ul>"
                                  "<li>%13</li>"
                                  "<li>%14</li>"
                                  "<li>%15</li>"
                                  "<li>%16</li>"
                                  "</ul></body>")
            .arg(tr("Feedback & User Groups"))
            .arg(tr("GXDE OS use Discord and Tencent QQ Group. You can click the button below to join our group conveniently"))
            .arg(tr("<a href='https://www.gxde.org/QQ.jpg' target='_blank' rel='noreferrer'>Click to join QQ Group</a>"))
            .arg(tr("<a href='https://discord.gg/t5Uf2xYpvA' target='_blank' rel='noreferrer'>Click to join Discord Group</a>"))
//            .arg(tr(""))
//            .arg(tr(""))
            .arg(tr("FAQ"))
            .arg(tr("FAQs can be found at the links below"))
            .arg(tr("<a href='https://www.gxde.org/en/install/faq' target='_blank' rel='noreferrer'>Click to check FAQs</a>"))
            .arg(tr("You can create PR to enrich the list and help. <a href='https://gitee.com/GXDE-OS/gxde-os.github.io' target='_blank' rel='noreferrer'>Click to Git Repo</a>"))
            .arg(tr("Internal Testing"))
            .arg(tr("For quality assurance of the GXDE project, we welcome more people to participate in the internal testing and feedback tracking. Become an Internal Testing Team member, you will"))
            .arg(tr("Get the latest achievements of GXDE and software timely."))
            .arg(tr("Obtain the latest development plans and progress of GXDE project in advance."))
            .arg(tr("Need advanced skill and be prepared to encounter bugs and errors"))
            .arg(tr("Find the entrance at Control Center --> Update --> Internal test settings"));

    label->setText(text);
}
