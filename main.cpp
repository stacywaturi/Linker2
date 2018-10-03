#include "mainwindow.h"
#include "Certificate.h"
#include "openssl/applink.c"
#include <QApplication>
#include <QtDebug>

int		TF_CERT_ERROR_INDEX = TF_CERT_no_error;
std::string	LOG_FILE_CERTMNGR	= "log_cert_mngr.log";
std::string  DB_FILE_NAME="test.db";

int main(int argc, char *argv[])
{
    openssl_init();

    Certificate *newCert = new Certificate();

   std::string pop = newCert->generatePvtKey(2048);
    std::cout << "\nKEY: \n" << pop << std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
