#ifndef CELDAGRAFICA_H
#define CELDAGRAFICA_H

#include <QPushButton>
#include <QWidget>
#include <QObject>
#include <QString>

/** class CeldaGrafica: Expresión de la celda en la interfaz gráfica.
 * Hereda de la clase de QT "QPushButton".
 * Documentación: http://doc.qt.io/archives/qt-4.8/qpushbutton.html
 */
class CeldaGrafica : public QPushButton
{
    /** Q_OBJECT: Constante que utiliza QT, para indicar al programa que se debe autogenerar
     * páginas de código que permite al objeto con la constante definida funcionar como lo haría
     * un QObject.
     */
    Q_OBJECT

private:
    /** valor_: Indica el contenido de la celda.
     * case 0: Vacío (' ').
     * case 1: Obstáculo ('0').
     * case 2: Usuario ('!').
     */
    int valor_;
public:
    explicit CeldaGrafica(int valor = 0);
    virtual ~CeldaGrafica();
};

#endif // CELDAGRAFICA_H
