// Default empty project template
#ifndef MyOsh_HPP_
#define MyOsh_HPP_

#include <QObject>
#include <bb/cascades/NavigationPane>
#include <bb/data/JsonDataAccess>
namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class MyOsh : public QObject
{
    Q_OBJECT
public:
    MyOsh(bb::cascades::Application *app);
    virtual ~MyOsh() {}
    Q_INVOKABLE void getJSON();
public slots:
	void onDataAccess(QString info, bool success);
private:
	/*
	     * Parses the JSON response from the twitter request
	     */
	    void parseJson(QString info);

	    /*
	     * Makes visible and shows error text on the main screen
	     */
	    void showError(QString error);
private:
    bb::cascades::NavigationPane* m_navPane;
    QString m_Response;
    bool m_requestInProgress;
};


#endif /* MyOsh_HPP_ */
