// Default empty project template
#include "MyOsh.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/Page>
#include "JsonAccess.hpp"
using namespace bb::cascades;

MyOsh::MyOsh(bb::cascades::Application *app) :
		QObject(app), m_Response(""), m_requestInProgress(false) {
	// create scene document from main.qml asset
	// set parent to created document to ensure it exists for the whole application lifetime
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

	if (!qml->hasErrors()) {
		qml->setContextProperty("cs", this);
		m_navPane = new NavigationPane;
		Page* page = qml->createRootObject<Page>();
		m_navPane->push(page);
		if (m_navPane) {
			app->setScene(m_navPane);
		}
	}

}

void MyOsh::getJSON() {
	JsonAccess* ja = new JsonAccess();
	//Call the function to get handle of the json
	ja->getData();
	//Connect the signal emitted by the getData() method with onDataAccess method
connect(ja, SIGNAL(complete(QString, bool)), this,SLOT(onDataAccess(QString, bool)));
}

void MyOsh::onDataAccess(QString info, bool success) {
qDebug() << "onDataAccess in app ";
if (success) {
	qDebug() << "onDataAccess success" + info;
	/*  QObject* txtA = m_navPane->findChild<QObject*>("txtRawJson");
	 if(txtA)
	 {
		 txtA->setProperty("text",info);

	 }*/
	 parseJson(info);
} else {
	qDebug() << "Error In onDataAccess" + info;
}

}

void MyOsh::parseJson(QString info){

	QString correctedJson = "[" + info + "]";
			correctedJson = correctedJson.replace("\n",",");
			correctedJson = correctedJson.replace("},]","}]");

			  QObject* txtA = m_navPane->findChild<QObject*>("txtRawJson");
				 if(txtA)
				 {
					 txtA->setProperty("text",correctedJson);

				 }

}
