#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();

private slots:
    void digitClicked();
    void additiveOperatorClicked();
    void multiplicativeOperatorClicked();
    void equalClicked();
    void dotClicked();
    void backspaceClicked();
    void clear();
    void clearAll();

private:
    Ui::calculator *ui;

    double sumSoFar;
    double factorSoFar;
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperand;

    bool Calculator(double rightOperand, const QString &pendingOperator){
        if (pendingOperator == tr("+")){
            sumSoFar += rightOperand;
        }else if (pendingOperator == tr("-")){
            sumSoFar -= rightOperand;
        }else if (pendingOperator == tr("*")){
            factorSoFar *= rightOperand;
        }else if (pendingOperator == tr("/")){
            if (rightOperand == 0.0)
                return false;
            factorSoFar /= rightOperand;
        }
        return true;
    };
    void abortOperation();

};
#endif // CALCULATOR_H
