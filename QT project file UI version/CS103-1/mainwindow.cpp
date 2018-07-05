#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QInputDialog"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refresh();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableWidget_viewportEntered()
{
}
void MainWindow::on_tableWidget_activated(const QModelIndex &index)
{
}
void MainWindow::on_pushButton_clicked()
{
    airline.writeToFile();
    QApplication::quit();
}
void MainWindow::refresh(){
    ui->tableWidget->setRowCount(airline.getTotalFlights());
    ui->tableWidget_2->setRowCount(airline.getTotalPilots());
    ui->tableWidget_3->setRowCount(airline.getTotalPlanes());
    ui->tableWidget_4->setRowCount(airline.getTotalEngineers());
    string flightID,route,model,pilotFirstN,pilotLastN,pilotID,EngineerID;
    int capacity;
    for(int i=0;i<airline.getTotalFlights();i++){
        airline.getFlightValues(i,flightID,model,capacity,pilotID,pilotFirstN,pilotLastN,route,EngineerID);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(flightID.c_str()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(route.c_str()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(to_string(capacity).c_str()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(model.c_str()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(pilotID.c_str()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(pilotFirstN.c_str()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(pilotLastN.c_str()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(EngineerID.c_str()));

    }
    for(int i=0;i<airline.getTotalPilots();i++){
        string FirstName, LastName, id;
        int Exp,BasicPay,HourlyPay;
        airline.getPilotValues(i,FirstName,LastName,id,Exp,BasicPay,HourlyPay);
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(id.c_str()));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(FirstName.c_str()));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(LastName.c_str()));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(to_string(Exp).c_str()));
        ui->tableWidget_2->setItem(i,4,new QTableWidgetItem(to_string(BasicPay).c_str()));
        ui->tableWidget_2->setItem(i,5,new QTableWidgetItem(to_string(HourlyPay).c_str()));
    }

    for(int i=0;i<airline.getTotalPlanes();i++){
        string id, Model;
        int Capacity;
        airline.getPlaneValues(i,id,Model,Capacity);
        ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(id.c_str()));
        ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(Model.c_str()));
        ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(to_string(Capacity).c_str()));
    }

    for(int i=0;i<airline.getTotalEngineers();i++){
        string inID,inFirstName,inLastName,inLisence;
        int inPay;
        airline.getEngineerValues(i,inID,inFirstName,inLastName,inPay,inLisence);
        ui->tableWidget_4->setItem(i,0,new QTableWidgetItem(inID.c_str()));
        ui->tableWidget_4->setItem(i,1,new QTableWidgetItem(inFirstName.c_str()));
        ui->tableWidget_4->setItem(i,2,new QTableWidgetItem(inLastName.c_str()));
        ui->tableWidget_4->setItem(i,3,new QTableWidgetItem(to_string(inPay).c_str()));
        ui->tableWidget_4->setItem(i,4,new QTableWidgetItem(inLisence.c_str()));
    }
}

void MainWindow::on_pushButton_2_clicked(){
    bool ok;
    QString txt= QInputDialog::getText(this ,"Enter Flight ID", "New Flight ID:", QLineEdit::Normal,"AL0000", &ok);
    std::string FlightID= txt.toStdString();

    txt= QInputDialog::getText(this ,"Enter Aircraft ID", "Aircraft ID:", QLineEdit::Normal,"AL0000", &ok);
    std::string PlaneID= txt.toStdString();

    txt= QInputDialog::getText(this ,"Enter Pilot ID", "Pilot ID:", QLineEdit::Normal,"AL0000", &ok);
    std::string PilotID= txt.toStdString();

    txt= QInputDialog::getText(this ,"Enter route", "Route:", QLineEdit::Normal,"AL0000", &ok);
    std::string Route= txt.toStdString();
    int PilotIndex=airline.getPilotIndex(PilotID);
    int planeIndex=airline.getAircraftIndex(PlaneID);
    if(PilotIndex==-1){
        QMessageBox::critical(this,"Invalid Pilot ID","Invalid ID, please Add A New Pilot Or Enter A Valid ID");
    }
    else if(planeIndex==-1){
        QMessageBox::critical(this,"Invalid Aircraft ID","Invalid ID, please Add A New Aircraft Or Enter A Valid ID");
    }
    else{
        Pilot pilot1=airline.getPilot(PilotIndex);
        Plane plane1=airline.getPlane(planeIndex);
        Flight flight1;
        flight1.setFlight(FlightID,plane1,pilot1,Route);
        airline.addFlight(flight1);
        refresh();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    bool ok;
    int inExp,hourlyPay,basicPay;
    QString txt= QInputDialog::getText(this ,"Enter Pilot ID", "New Pilot ID:", QLineEdit::Normal,"", &ok);
    std::string FlightID= txt.toStdString();
    txt= QInputDialog::getText(this ,"Enter First Name", "New First Name:", QLineEdit::Normal,"", &ok);
    std::string FirstName= txt.toStdString();
    txt= QInputDialog::getText(this ,"Enter Last Name", "New Last Name:", QLineEdit::Normal,"", &ok);
    std::string LastName= txt.toStdString();

    inExp=QInputDialog::getInt(this,"Flying Experiance","Enter Flying Experiance (hours)",0,0,100000,1,&ok);
    basicPay=QInputDialog::getInt(this,"Basic Salary","Enter Basic Salary/month",0,0,1000000,1,&ok);
    hourlyPay=QInputDialog::getInt(this,"Enter Flying Fee","Enter Flying Fee/Hour",0,0,10000,1,&ok);
    Pilot pilot;
    pilot.setPilot(FlightID,FirstName,LastName,inExp,basicPay,hourlyPay);
    airline.addPilot(pilot);
    refresh();
}

void MainWindow::on_pushButton_5_clicked()
{
    bool ok;
    QString txt= QInputDialog::getText(this ,"Enter Aircraft ID", "New Aircraft ID:", QLineEdit::Normal,"", &ok);
    std::string ID= txt.toStdString();
    txt= QInputDialog::getText(this ,"Enter Aircraft Model", "New Aircraft Model:", QLineEdit::Normal,"", &ok);
    std::string Model= txt.toStdString();
    int Capacity=QInputDialog::getInt(this,"Enter Capacity","New Aircraft Capacity",300,10,1100,1,&ok);
    Plane plane;
    plane.setPlane(ID,Model,Capacity);
    airline.addPlane(plane);
    refresh();
}

void MainWindow::on_pushButton_7_clicked()
{
    bool ok;
    QString txt= QInputDialog::getText(this ,"Enter Pilot ID", "Pilot ID:", QLineEdit::Normal,"", &ok);
    std::string ID= txt.toStdString();
    airline.removePilot(ID);
    refresh();
}

void MainWindow::on_pushButton_6_clicked()
{
    bool ok;
    QString txt= QInputDialog::getText(this ,"Enter Aircraft ID", "Aircraft ID:", QLineEdit::Normal,"", &ok);
    std::string ID= txt.toStdString();
    airline.removePlane(ID);
    refresh();
}

void MainWindow::on_pushButton_3_clicked()
{
    bool ok;
    QString txt= QInputDialog::getText(this ,"Enter Flight ID", "Flight ID:", QLineEdit::Normal,"", &ok);
    std::string ID= txt.toStdString();
    airline.removeFlight(ID);
    refresh();
}

void MainWindow::on_pushButton_8_clicked()
{
    bool ok;
    int basicPay;
    QString txt= QInputDialog::getText(this ,"Enter Engineer ID", "New Engineer ID:", QLineEdit::Normal,"", &ok);
    std::string EngineerID= txt.toStdString();
    txt= QInputDialog::getText(this ,"Enter First Name", "New First Name:", QLineEdit::Normal,"", &ok);
    std::string FirstName= txt.toStdString();
    txt= QInputDialog::getText(this ,"Enter Last Name", "New Last Name:", QLineEdit::Normal,"", &ok);
    std::string LastName= txt.toStdString();
    basicPay=QInputDialog::getInt(this,"Basic Salary","Enter Basic Salary/month",0,0,1000000,1,&ok);
    txt= QInputDialog::getText(this ,"Enter Lisence", "New Lisence:", QLineEdit::Normal,"", &ok);
    std::string inLisence= txt.toStdString();
    FlightEngineer f1;
    f1.setEngineer(EngineerID,FirstName,LastName,basicPay,inLisence);
    airline.addEngineer(f1);
    refresh();
}

void MainWindow::on_pushButton_9_clicked()
{
    bool ok;
    //int basicPay;
    QString txt= QInputDialog::getText(this ,"Enter Engineer ID", "Engineer ID:", QLineEdit::Normal,"", &ok);
    std::string EngineerID= txt.toStdString();
    airline.removeEngineer(EngineerID);
    refresh();
}

void MainWindow::on_pushButton_10_clicked()
{
    bool ok;
    QString txt= QInputDialog::getText(this ,"Enter Flight ID", "New Flight ID:", QLineEdit::Normal,"AL0000", &ok);
    std::string FlightID= txt.toStdString();

    txt= QInputDialog::getText(this ,"Enter Aircraft ID", "New Aircraft ID:", QLineEdit::Normal,"AL0000", &ok);
    std::string PlaneID= txt.toStdString();

    txt= QInputDialog::getText(this ,"Enter Pilot ID", "New Pilot ID:", QLineEdit::Normal,"AL0000", &ok);
    std::string PilotID= txt.toStdString();

    txt= QInputDialog::getText(this ,"Enter route", "Route:", QLineEdit::Normal,"AL0000", &ok);
    std::string Route= txt.toStdString();
    txt= QInputDialog::getText(this ,"Enter Engineer ID", "new Engineer ID:", QLineEdit::Normal,"AL0000", &ok);
    std::string EngineerID= txt.toStdString();
    int PilotIndex=airline.getPilotIndex(PilotID);
    int planeIndex=airline.getAircraftIndex(PlaneID);
    if(PilotIndex==-1){
        QMessageBox::critical(this,"Invalid Pilot ID","Invalid ID, please Add A New Pilot Or Enter A Valid ID");
    }
    else if(planeIndex==-1){
        QMessageBox::critical(this,"Invalid Aircraft ID","Invalid ID, please Add A New Aircraft Or Enter A Valid ID");
    }
    else{
        Pilot pilot1=airline.getPilot(PilotIndex);
        Plane plane1=airline.getPlane(planeIndex);
        airline.removeFlight(FlightID);
        Flight flight1;
        flight1.setFlight(FlightID,plane1,pilot1,Route);
        airline.addFlight(flight1);
        refresh();
    }
}
