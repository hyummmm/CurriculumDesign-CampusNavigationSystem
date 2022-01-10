#ifndef INFOMATIONDISPLAY_H
#define INFOMATIONDISPLAY_H

#include <QWidget>

namespace Ui {
class InfomationDisplay;
}

class InfomationDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit InfomationDisplay(QWidget *parent = nullptr);
    ~InfomationDisplay();

private:
    Ui::InfomationDisplay *ui;
};

#endif // INFOMATIONDISPLAY_H
