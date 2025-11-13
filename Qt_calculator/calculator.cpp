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

    connect(ui->btn0,           &QPushButton::clicked, this, &calculator::digitClicked);
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
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    qDebug() << clickedButton;
}

void calculator::additiveOperatorClicked()
{
    qDebug() << tr("+ - button clicked.");
}

void calculator::multiplicativeOperatorClicked()
{
    qDebug() << tr("* / button clicked.");
}

void calculator::equalClicked()
{
    qDebug() << tr("= button clicked.");
}

void calculator::dotClicked()
{
    qDebug() << tr(". button clicked.");
}

void calculator::backspaceClicked()
{
    qDebug() << tr("Back button clicked.");
}

void calculator::clear()
{
    qDebug() << tr("Clear button clicked.");
}

void calculator::clearAll()
{
    qDebug() << tr("Clear All button clicked.");
}

void calculator::abortOperation()
{
    clearAll();
    ui->editDisplay->setText(tr("####"));
}
