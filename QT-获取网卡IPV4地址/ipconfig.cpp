#include "ipconfig.h"

#include <QString>
#include <QHostInfo>
#include <QNetworkInterface>
#include <iostream>

ipconfig::ipconfig()
{
    QString strHostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(strHostName);
    //std::cout << hostInfo.nam().toStdString() << std::endl;
    QList<QHostAddress> list = hostInfo.addresses();


    QString strTemp="";
    QList<QNetworkInterface> list2 = QNetworkInterface::allInterfaces();
    for(int i = 0; i < list2.count();++i)
    {

        QNetworkInterface interFace = list2.at(i);
        QString name = interFace.humanReadableName();

        //std::cout << "name " << name.toStdString() <<std::endl;

        if(name.toStdString() == "eth0")
        {
            QList<QHostAddress> addresses = interFace.allAddresses();
            for (const QHostAddress &address : addresses) {
                if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress::LocalHost) {
                    qDebug() << "IPv4 address:" << address.toString();
                } else if (address.protocol() == QAbstractSocket::IPv6Protocol) {
                    //qDebug() << "IPv6 address:" << address.toString();
                }
            }
        }
    }

}
