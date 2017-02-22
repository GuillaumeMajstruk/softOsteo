#ifndef SCREEN_HPP
#define SCREEN_HPP

// ////////////////////////////////////////////////////////////////
// /     représente le concepte "d'écran" (qui sont des widgets ///
// /     en réalité) à afficher dans la MainWindow.             ///
// /     class abstraite                                        ///
// ////////////////////////////////////////////////////////////////

#include <QWidget>
#include <QDebug>
#include <QString>

class Screen : public QWidget
{
    Q_OBJECT
public:

    Screen(QWidget *parent = 0):
        QWidget(parent)
    {
        qDebug() << "Screen::Screen()";
    }

    virtual ~Screen ()
    {
        qDebug() << "Screen::~Screen()";
    }

    // / Retourne le widget qui correspond à l'interface
    virtual QWidget* getWidget() const { return m_interface; }

    // / Retourne le nom de l'interface
    virtual QString  getInterfaceName() const { return m_interfaceName; }

    // / Retourne le nom de l'objet interface
    virtual QString getInterfaceObjectName() const { return m_objectInterfaceName; }

    // / Défini le nom de l'interface
    virtual void setInterfaceName (const char* name) {
        tr(name);
        m_interfaceName = QString::fromUtf8(name);
    }

    // /  Défini le nom de l'objet interface
    virtual void setInterfaceObjectName (const char* uiName)
    {
        m_objectInterfaceName = uiName;
    }

protected:

    // / Widget -> interface
    QWidget * m_interface = nullptr;

    // / Nom de l'interface
    QString m_interfaceName;

    // / Nom de l'objet interface
    QString m_objectInterfaceName;
};

#endif // / SCREEN_HPP
