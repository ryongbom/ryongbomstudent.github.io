#include "calculator.h"
#include "ui_calculator.h"
#include <QDebug>

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);


    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator = "";
    pendingMultiplicativeOperator = "";
    waitingForOperand = true;


    connect(ui->btn0,          &QPushButton::clicked, this, &calculator::digitClicked);
    connect(ui->btn1,           &QPushButton::clicked, this, &calculator::digitClicked);
    connect(ui->btn2,           &QPushButton::clicked, this, &calculator::digitClicked);
    connect(ui->btn3,           &QPushButton::clicked, this, &calculator::digitClicked);
    connect(ui->btn4,           &QPushButton::clicked, this, &calculator::digitClicked);
    connect(ui->btn5,           &QPushButton::clicked, this, &calculator::digitClicked);
    connect(ui->btn6,           &QPushButton::clicked, this, &calculator::digitClicked);
    connect(ui->btn7,           &QPushButton::clicked, this, &calculator::digitClicked);
    connect(ui->btn8,           &QPushButton::clicked, this, &calculator::digitClicked);
    connect(ui->btn9,           &QPushButton::clicked, this, &calculator::digitClicked);

    connect(ui->btnClear,       &QPushButton::clicked, this, &calculator::clear);
    connect(ui->btnClearAll,    &QPushButton::clicked, this, &calculator::clearAll);

    connect(ui->btnPlus,        &QPushButton::clicked, this, &calculator::additiveOperatorClicked);
    connect(ui->btnMinus,       &QPushButton::clicked, this, &calculator::additiveOperatorClicked);

    connect(ui->btnMultiply,    &QPushButton::clicked, this, &calculator::multiplicativeOperatorClicked);
    connect(ui->btnDivide,      &QPushButton::clicked, this, &calculator::multiplicativeOperatorClicked);

    connect(ui->btneEual,       &QPushButton::clicked, this, &calculator::equalClicked);
    connect(ui->btnDot,         &QPushButton::clicked, this, &calculator::dotClicked);
    connect(ui->btnBackspace,   &QPushButton::clicked, this, &calculator::backspaceClicked);
}

calculator::~calculator()
{
    delete ui;
}

void calculator::digitClicked()
{
    QLineEdit *display = ui-> editDisplay;

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digitValue = clickedButton->text().toInt();
    if (display->text() == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
}

void calculator::additiveOperatorClicked()
{
    QLineEdit *display = ui->editDisplay;
        QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
        QString clickedOperator = clickedButton->text();
        double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }

    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }

    pendingAdditiveOperator = clickedOperator;
    waitingForOperand = true;
    qDebug() << tr("+ - button clicked.");
}

void calculator::multiplicativeOperatorClicked()
{
    QLineEdit *display = ui-> editDisplay;

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if(!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;
}

void calculator::equalClicked()
{
    QLineEdit *display = ui->editDisplay;
    double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
    }

    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
    } else {
        sumSoFar = operand;
    }

    display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingMultiplicativeOperator.clear();
    pendingAdditiveOperator.clear();
    waitingForOperand = true;

    qDebug() << tr("= button clicked.");
}

void calculator::dotClicked()
{
    if (waitingForOperand)
        ui->editDisplay->setText("0");
    if (!ui->editDisplay->text().contains('.'))
        ui->editDisplay->setText(ui->editDisplay->text() + tr("."));
    waitingForOperand = false;

    qDebug() << tr(". button clicked.");
}

void calculator::backspaceClicked()
{
    if (waitingForOperand)
        return;

    QString text = ui->editDisplay->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    ui->editDisplay->setText(text);
    qDebug() << tr("Back button clicked.");
}

void calculator::clear()
{
    if (waitingForOperand)
        return;

    ui->editDisplay->setText("0");
    waitingForOperand = true;
    qDebug() << tr("Clear button clicked.");
}

void calculator::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->editDisplay->setText("0");
    waitingForOperand = true;
    qDebug() << tr("Clear All button clicked.");
}

void calculator::abortOperation()
{
    clearAll();
    ui->editDisplay->setText(tr("####"));
}

