#include "quickfix/FileStore.h"
#include "quickfix/FileLog.h"
#include "quickfix/SocketAcceptor.h"
#include "quickfix/Session.h"
#include "quickfix/SessionSettings.h"
#include "quickfix/Application.h"

using namespace FIX;
using namespace std;

class MyApplication: public Application
{
public:
    virtual ~MyApplication() {}
    virtual void onCreate( const SessionID& ) {
        cout << "OnCreate()" << endl;
    }
    virtual void onLogon( const SessionID& ) {
        cout << "onLogon()" << endl;
    }
    virtual void onLogout( const SessionID& ) {
        cout << "onLogout()" << endl;
    }
    virtual void toAdmin( Message&, const SessionID& ) {
        cout << "toAdmin()" << endl;
    }
    virtual void toApp( Message&, const SessionID& )
        throw( DoNotSend ) {
        cout << "toApp()" << endl;
    }
    virtual void fromAdmin( const Message&, const SessionID& )
        throw( FieldNotFound, IncorrectDataFormat, IncorrectTagValue, RejectLogon ) {
        cout << "fromAdmin()" << endl;
    }
    virtual void fromApp( const Message&, const SessionID& )
        throw( FieldNotFound, IncorrectDataFormat, IncorrectTagValue, UnsupportedMessageType ) {
        cout << "fromApp()" << endl;
    }
};

int main( int argc, char** argv )
{
  try
  {
    if(argc < 2) return 1;
    string fileName = argv[1];

    SessionSettings settings(fileName);

    MyApplication application;
    FileStoreFactory storeFactory(settings);
    FileLogFactory logFactory(settings);
    SocketAcceptor acceptor
      (application, storeFactory, settings, logFactory /*optional*/);
    acceptor.start();
    // while( condition == true ) { do something; }
    acceptor.stop();
    return 0;
  }
  catch(ConfigError& e)
  {
    cout << e.what();
    return 1;
  }
}

