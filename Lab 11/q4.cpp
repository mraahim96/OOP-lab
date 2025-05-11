#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DBException : public exception {
public:
    const char* what() const noexcept override {
        return "A database-related error occurred.";
    }
};

class ConnectionError : public DBException {};
class QueryTimeout : public DBException {};

template<typename T>
class DBConnector {
private:
    T databaseName;

public:
    DBConnector(T name) : databaseName(name) {}

    void connect() {
        if (databaseName == "invalid_db") {
            throw ConnectionError();
        }
        cout << "Successfully connected to " << databaseName << endl;
    }

    void runQuery(const string& sql) {
        if (databaseName == "laggy_db") {
            throw QueryTimeout();
        }
        cout << "Query executed: " << sql << endl;
    }
};

int main() {
    try {
        cout << "Trying to connect to a non-existent database..." << endl;
        DBConnector<string> db1("invalid_db");
        db1.connect();
    } catch (ConnectionError& e) {
        cout << "Error: Could not establish a database connection." << endl;
        cout << "Reason: " << e.what() << endl;
    }

    try {
        cout << "Connecting to a slow database..." << endl;
        DBConnector<string> db2("laggy_db");
        db2.connect();
        db2.runQuery("SELECT * FROM users;");
    } catch (QueryTimeout& e) {
        cout << "Error: Query took too long to respond." << endl;
        cout << "Reason: " << e.what() << endl;
    }

    return 0;
}
