#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>

class About : public QWidget
{
    Q_OBJECT
public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private:
    QLabel *showData;
};

#endif // ABOUT_H
