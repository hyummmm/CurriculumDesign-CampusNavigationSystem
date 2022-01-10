#ifndef SEARCHPATH_H
#define SEARCHPATH_H

#include <QWidget>

namespace Ui {
class SearchPath;
}

class SearchPath : public QWidget
{
    Q_OBJECT

public:
    explicit SearchPath(QWidget *parent = nullptr);
    ~SearchPath();

private:
    Ui::SearchPath *ui;
};

#endif // SEARCHPATH_H
