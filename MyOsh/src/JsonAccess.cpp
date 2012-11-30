/*
 * JsonAccess.cpp
 *
 *  Created on: 04-Nov-2012
 *      Author: Rajiv
 */

#include "JsonAccess.hpp"
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QAuthenticator>
#include <QtNetwork/QHttp>
#include <QDebug>


JsonAccess::JsonAccess() {
	// TODO Auto-generated constructor stub

}

JsonAccess::~JsonAccess() {
	// TODO Auto-generated destructor stub
}

//This method connects to the server and returns the received Json object for parsing in the calling class.
void JsonAccess::getData()
{
	//Get handle of Qnetworkmanager to get the connections and query the url
	QNetworkAccessManager* netManager = new QNetworkAccessManager();
	if (!netManager) {
		qDebug() << "Unable to create QNetworkAccessManager!";
		emit complete("Unable to create QNetworkAccessManager!", false);
		return;
	}
	QString queryUri =
			"http://114.143.187.99/mobile/inspections.nsf/inspection_Details.xsp";
	QUrl myOshurl(queryUri);
	QNetworkRequest qheader;
	QString loginData = "admin:password";
	QByteArray data = loginData.toLocal8Bit().toBase64();
	QString headerData = "Basic " + data;
	qheader.setRawHeader("Authorization", headerData.toLocal8Bit());
	qheader.setUrl(myOshurl);
	QNetworkReply* ipReply = netManager->get(qheader);
	connect(ipReply, SIGNAL(finished()), this, SLOT(onDataReply()));

}
void JsonAccess::onDataReply()
{
	QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
	    QString response;
	    bool success = false;
	    if (reply)
	    {
	        if (reply->error() == QNetworkReply::NoError)
	        {
	            int available = reply->bytesAvailable();
	            if (available > 0)
	            {
	                int bufSize = sizeof(char) * available + sizeof(char);
	                QByteArray buffer(bufSize, 0);
	                int read = reply->read(buffer.data(), available);
	                response = QString(buffer);
	                success = true;
	            }
	        }
	        else
	        {
	            response =  QString("Error: ") + reply->errorString() + QString(" status:") + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString();
	            qDebug() << response;
	        }
	        reply->deleteLater();
	    }
	    if (response.trimmed().isEmpty())
	    {
	        response = "Request failed. Check internet connection";
	        qDebug() << response;
	    }
	    emit complete(response, success);

}

//This function can be used in scenarios where proper authentication is required
void JsonAccess::provideAuthentication(QNetworkReply *reply, QAuthenticator *ator)
{
	qDebug() << "Authenticator"+reply->readAll(); // this is just to see what we received
	   ator->setUser(QString("admin"));
	   ator->setPassword(QString("password"));

}
