#include <iostream>
#include <winsock2.h>
#include <string>
#include <windows.h>

using namespace std;

class con{

SOCKET sListen;
SOCKET sConnect;

SOCKADDR_IN addr;


void init(char * IPADDR, char * PORT){
WSAData wsaData;
WORD DLLVERSION;
DLLVERSION = MAKEWORD(2, 1);
WSAStartup(DLLVERSION, &wsaData);

addr.sin_addr.s_addr = inet_addr("10.0.1.248");
addr.sin_family = AF_INET;
addr.sin_port = htons(5320);

sConnect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
}

void startlisten(){
listen(sListen, SOMAXCONN);
}


};

int main()
{
    /*
    string httpStr;
    httpStr.append("HTTP/1.0 200 OK\n");
    httpStr.append("Date: Wed, 8 Aug 2012 13:37:00 GMT\n");
    httpStr.append("Content-Type: text/html\n");
    httpStr.append("Content-Length: 1354\n");
    httpStr.append("\n"); // DOUBLE ENTER
    httpStr.append("<html>\n");
    httpStr.append("<body>\n");
    httpStr.append("<h1>Hello World!</h1>\n");
    httpStr.append("</body>\n");
    httpStr.append("</html>\n");
    httpStr.append("\n\n"); // DOUBLE ENTER

    const char * httpChar;
    httpChar = httpStr.c_str();

    cout << "HTTP Message to send!" << endl << httpChar;
    */
    /*
    char  ENTER = 0012;
    string ENDLSTR;
    string text;
    ENDLSTR = char(ENTER);
    */

    string ENDLSTR;
    ENDLSTR = '\n';

    string HTTPMSG;
    HTTPMSG.append("HTTP/1.1 200 OK");
    HTTPMSG.append(ENDLSTR);
    HTTPMSG.append("Date: Wed, 8 Aug 2012 18:25:00 GMT");
    HTTPMSG.append(ENDLSTR);
    HTTPMSG.append("Content-Type: text/html");
    HTTPMSG.append(ENDLSTR);
    HTTPMSG.append("Content-Length: 1354");
    HTTPMSG.append(ENDLSTR);
    HTTPMSG.append(ENDLSTR); // DOUBLE ENTER
    HTTPMSG.append("<html>");
    HTTPMSG.append(ENDLSTR);
    HTTPMSG.append("<body>");
    HTTPMSG.append(ENDLSTR);
    HTTPMSG.append("<h1>HELLO WORLD!</h1>");
    HTTPMSG.append(ENDLSTR);
    HTTPMSG.append("</body>");
    HTTPMSG.append(ENDLSTR);
    HTTPMSG.append("</html>");
    HTTPMSG.append(ENDLSTR);
    HTTPMSG.append(ENDLSTR);

    //cout << HTTPMSG;
    const char * HTTPMSGCHAR;
    HTTPMSGCHAR = HTTPMSG.c_str();



    char recvChar[500];
    string recvStr;












    /*
    AF_INET      (As opposed to AF_INET6)     Since we're using IPv4 instead of IPv6 for IP addresses.
    SOCK_STREAM  (As opposed to SOCK_DGRAM)   Since we're using a connection-based socket, we use this.
    IPPROTO_TCP  (As opposed to IPPROTO_UDP)  TCP is slower than UDP, but ensures reliability and delivers data in the correct order.
    */







    for (;;)
    {
        cout << "Waiting for incoming connection." << endl;

        if (sConnect = accept(sListen, (SOCKADDR*)&addr,&length))
        {

            cout << "Connected" << endl;
            recv(sConnect, recvChar, sizeof(recvChar), NULL);
            recvStr = recvChar;
            cout << recvStr;
            // char * httpch = "HTTP/1.0 200 OK\nDate: Wed, 8 Aug 2012 13:37:00 GMT \nContent-Type: text/html\nContent-Length:`1354\n\n<html>\n<body>\n<h1>Hello World!</h1>\n</body>\n</html>\n\n\n";
            //send(sConnect, httpch, 151, NULL);

            //send(sConnect, "HTTP/1.1 200 OK\nDate: Wed, 8 Aug 2012 13:37:00 GMT \nContent-Type: text/html\nContent-Length:`1354\n<html>\n<body>\n<h1>Hello World!</h1>\n</body>\n</html>\n\n\n",
            //     255, NULL);

            //send(sConnect, "HTTP/1.1 200 OK\nDate: Wed, 8 Aug 2012 13:37:00 GMT \nContent-Type: text/html\nContent-Length:`1354\n<html>\n<body>\n<h1>Hello World!</h1>\n</body>\n</html>\n\n\n",
            send(sConnect, HTTPMSGCHAR, HTTPMSG.length(), NULL);


            break;


        }

    }
    closesocket(sListen);
    closesocket(sConnect);
    WSACleanup();

    //cin.ignore();

    return 0;
}
