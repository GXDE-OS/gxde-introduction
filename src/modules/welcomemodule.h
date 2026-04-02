#ifndef WELCOMEMODULE_H
#define WELCOMEMODULE_H

#include "moduleinterface.h"

class WelcomeModule : public ModuleInterface
{
    Q_OBJECT
public:
    explicit WelcomeModule(QWidget *parent = nullptr);

    void updateBigIcon() override;
    void updateSmallIcon() override;
    void updateSelectBtnPos() override;

private:
    QLabel *m_welcomeLabel;
};

#endif // WELCOMEMODULE_H