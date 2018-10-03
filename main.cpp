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
    Certificate *cert = new Certificate();
    std::string pop = cert->generatePvtKey(2048);
    std::cout << "\nKEY: \n" << pop << std::endl;

    cert->generateCSR(384);
    std::cout<<"\n\nCSR\n"<<cert->getCertReq()<<std::endl;

    std::cout<<"\n\nPUBLIC KEY FROM PRIVATE KEY\n"<<cert->private2PublicKey();
    std::cout<<"\n\nPUBLIC KEY FROM CERTIFICATE SIGNING REQUEST\n"<<cert->CSR2PublicKey();
    std::cout<<"\n\nCERTIFICATE SIGNING REQUEST DETAILS:\n"<<cert->displayCSR();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
