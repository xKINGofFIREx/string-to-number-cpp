#include "mainwidget.hpp"
#include "converter.hpp"
#include <QtWidgets>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) {
    button_ = new QPushButton(tr("Result"));
    text_browser_out_ = new QTextBrowser();
    text_edit_ = new QTextEdit();

    connect(button_, &QPushButton::clicked, this, &MainWidget::handleButton);
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(text_edit_, 0, 0);
    mainLayout->addWidget(button_, 1, 0);
    mainLayout->addWidget(text_browser_out_, 2, 0);
    setFixedSize(800, 600);
    setLayout(mainLayout);
    setWindowTitle(tr("Ильин А.В. транслятор с Английского языка."));
}

MainWidget::~MainWidget() {
    delete button_;
    delete text_browser_out_;
    delete text_edit_;
}

void MainWidget::handleButton() {
    QString text = text_edit_->toPlainText();
    text =
        QString::fromStdString(Converter::convert_string(text.toStdString()));
    text_browser_out_->setText(text);
}
