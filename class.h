class lol : public QObject{
	public slots:
		void Exit123(){
			std::exit(1);
		}
};

bool eventFilter(QObject* obj, QEvent* event);

class keyEnterReceiver : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject* obj, QEvent* event);
};

bool keyEnterReceiver::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
            //Enter or return was pressed
        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}

bool keyEnterReceiver::eventFilter(QObject* obj, QEvent* event)
{
    if(event->type()==QEvent::KeyPress) {
        …
    } else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}