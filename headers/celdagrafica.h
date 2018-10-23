#ifndef CELDAGRAFICA_H
#define CELDAGRAFICA_H

#include <QPushButton>
#include <QWidget>
#include <QObject>
#include <QString>

class CeldaGrafica : public QPushButton
{
    Q_OBJECT

private:
    int valor_;
public:
    explicit CeldaGrafica(int valor = 0);
    virtual ~CeldaGrafica();
};

#endif // CELDAGRAFICA_H
