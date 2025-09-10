//Dependency Inversion Principle
// High-level modules should not depend on low-level modules. Both should depend on abstractions.
// Abstractions should not depend on details. Details should depend on abstractions.
#include <iostream>
using namespace std;
class MySQLDatabase {
    public:
    void connect() {
        cout << "Connected to MySQL Database" << endl;
    }
    void disconnect() {
        cout << "Disconnected from MySQL Database" << endl;
    }
};
class PostgreSQLDatabase {
    public:
    void connect() {
        cout << "Connected to PostgreSQL Database" << endl;
    }
    void disconnect() {
        cout << "Disconnected from PostgreSQL Database" << endl;
    }
};
// Abstraction
class UserService {
    private:
    MySQLDatabase mysqlDb;
    PostgreSQLDatabase postgresDb;
    public:
    void useMySQL() {
        mysqlDb.connect();
        // Perform operations
        mysqlDb.disconnect();
    }
    void usePostgreSQL() {
        postgresDb.connect();
        // Perform operations
        postgresDb.disconnect();
    }
};
int main() {
    UserService userService;
    userService.useMySQL();
    userService.usePostgreSQL();
    return 0;
}