/*
 * JsonAccess.hpp
 *
 *  Created on: 04-Nov-2012
 *      Author: Rajiv
 */

#ifndef JSONACCESS_HPP_
#define JSONACCESS_HPP_

#include <QtCore/QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QAuthenticator>
#include <QDebug>
class JsonAccess: public QObject {
Q_OBJECT
public:
	JsonAccess();
	virtual ~JsonAccess();
	/*
	     * Makes a network call to retrieve the json object
	     * @see onDataReply
	     */
	void getData();

public slots:
/*
    * Callback handler for QNetworkReply finished() signal
    */
	void onDataReply();
	void provideAuthentication(QNetworkReply *reply, QAuthenticator *ator);
signals:
	/*
	 * This signal is emitted when the twitter request is received
	 * @param info - on success, this is the json reply from the request
	 *               on failure, it is an error string
	 * @param success - true if twitter request succeed, false if not
	 */
	void complete(QString info, bool success);
};

#endif /* JSONACCESS_HPP_ */
