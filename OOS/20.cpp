#include <iostream>
using namespace std;

// AuthenticationResult
class AuthenticationResult
{
    const bool _authenticated;
    const string _username;

public:
    // Konstruktor
    AuthenticationResult(bool authenticated = false, string username = "unauthenticated_user") : _authenticated(authenticated), _username(username) {}

    const string get_username()
    {
        return _username;
    }
    const bool get_authenticated()
    {
        return _authenticated;
    }
};

// Interface
class IAuthentication
{
    public:
    virtual AuthenticationResult authenticate() = 0;
};

class Client
{
    IAuthentication *_auth;

public:
    void set_authentication_method(IAuthentication *ptr)
    {
        _auth = ptr;
    }
    void execute()
    {
        AuthenticationResult result = _auth->authenticate();
        if (result.get_authenticated())
        {
            cout << "Das Programm wird ausgeführt für " << result.get_username() << "." << endl;
        }
        else
        {
            cout << "Das Programm konnte nicht ausgeführt werden." << endl;
        }
    }
};

class MockAuthentication : public IAuthentication
{
public:
    AuthenticationResult authenticate() override
    {
            return AuthenticationResult(true, "Default");
    }
};

class UsernamePassword : public IAuthentication
{
    string username;
    string password;

public:
    AuthenticationResult authenticate() override
    {
        cout << "Username: " << endl;
        cin >> username;
        cout << "Password: " << endl;
        cin >> password;
        if (username == password)
        {
            return AuthenticationResult(true, username);
        }
        else
        {
            return AuthenticationResult(false);
        }
    }
};

class Certificate : public IAuthentication
{
    string cert_issuer;

public:
    AuthenticationResult authenticate() override
    {
        cout << "Zertifikatsaussteller:"  << endl;
        cin >> cert_issuer;

        if (cert_issuer == "hs-esslingen")
        {
            return AuthenticationResult(true, "certificate.owner");
        }
        else
        {
            return AuthenticationResult(false);
        }
    }
};

int main(int argc, char *argv[])
{
    Client client;

    cout << "Authentifizierung über die Authentifizierungsmethode Mock Authentication" << endl;
    IAuthentication *mock_authentication = new MockAuthentication();
    client.set_authentication_method(mock_authentication);
    client.execute();

    cout << "Authentifizierung über die Authentifizierungsmethode Username Password" << endl;
    IAuthentication *username_password = new UsernamePassword();
    client.set_authentication_method(username_password);
    client.execute();

    cout << "Authentifizierung über die Authentifizierungsmethode Zertifikat" << endl;
    IAuthentication *certificate = new Certificate();
    client.set_authentication_method(certificate);
    client.execute();
    return 0;
}
