#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QPushButton;
class QTextBrowser;
class QTextEdit;

class MainWidget : public QWidget {
    Q_OBJECT

  public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

  private slots:
    void handleButton();

  private:
    QPushButton *button_;
    QTextBrowser *text_browser_out_;
    QTextEdit *text_edit_;
};

#endif // MAINWIDGET_H
