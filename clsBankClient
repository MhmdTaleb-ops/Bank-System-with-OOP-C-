#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"
#include "clsUtil.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDeleted = false;


    struct stTransferLogRecord;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
        
    }

    static stTransferLogRecord _ConvertLinetoTransferLog(string Line, string Seperator = "#//#")
    {
        vector <string> vTransferLog;
        stTransferLogRecord TransferLog;
        vTransferLog = clsString::Split(Line, Seperator);

        TransferLog.DateTime = vTransferLog[0];
        TransferLog.SourceAccountNumber = vTransferLog[1];
        TransferLog.DestinationAccountNumber = vTransferLog[2];
        TransferLog.Amount = stod(vTransferLog[3]);
        TransferLog.Trfee = stof(vTransferLog[4]);

        TransferLog.srcBalanceAfter = stod(vTransferLog[5]);
        TransferLog.destBalanceAfter = stod(vTransferLog[6]);
        TransferLog.UserName = vTransferLog[7];
        return TransferLog;
    }


    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord +=  Client.PinCode  + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }


    static  vector <stTransferLogRecord> _LoadTransferLogFromFile()
    {

        vector <stTransferLogRecord> VstLogTransfer;

        fstream MyFile;
        MyFile.open("TrnasferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                stTransferLogRecord Data = _ConvertLinetoTransferLog(Line);
                VstLogTransfer.push_back(Data);
            }

            MyFile.close();

        }

        return VstLogTransfer;

    }


    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkForDeleted() == false)
                {

                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _Delet()
    {
        vector <clsBankClient> _vClients = _LoadClientsDataFromFile();

      
        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
          
                C = *this;
                break;

            }



        }
       

        _SaveCleintsDataToFile(_vClients);
    }

    string _PrepareTransferLog(clsBankClient DestinationClient, float Trfee, double Amount ,string UserName,string Sepatretor = "#//#")
    {

        string DateLogin = "";
        DateLogin = clsDate::GetSystemDateTimeString() + Sepatretor;
        DateLogin += AccountNumber() + Sepatretor;
        DateLogin += DestinationClient.AccountNumber() + Sepatretor;
        DateLogin += to_string(Amount) + Sepatretor;
        DateLogin += to_string(Trfee) + Sepatretor;
        DateLogin += to_string(AccountBalance) + Sepatretor;
        DateLogin += to_string(DestinationClient.AccountBalance) + Sepatretor;
     
        DateLogin += UserName;
        return DateLogin;


    }


    void _TransferLog(clsBankClient DestinationClient,float Trfee , double Amount,string UserName)
    {

        string stDataLine = _PrepareTransferLog(DestinationClient, Trfee, Amount, UserName);

        fstream MyFile;
        MyFile.open("TrnasferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }



public:


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        double Amount;
        float Trfee;
        double srcBalanceAfter;
        double destBalanceAfter;
        string UserName;


    };


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkForDeleted()
    {
        return _MarkForDeleted;
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };


    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
            break;
        }

        


        }

    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {

        vector <clsBankClient> vClient = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClient)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C._MarkForDeleted = true;
                break;

            }



        }
        _SaveCleintsDataToFile(vClient);
        *this = _GetEmptyClientObject();
        return true;

   }

    void Deposit(double Amount)
    {

        _AccountBalance += Amount;
        Save();

    }

    bool Withdraw(double Amount)
    {

        if (Amount > _AccountBalance)
        {

            return false;

        }
        else
        {
            _AccountBalance -= Amount;
            Save();
        }

    }

    bool Trnasfer(double Amount,float Fee, clsBankClient& DestinationClient,string UserName)
    {
        float Trfee = 0;
        if (AccountBalance < Amount) {return false;}
          
    

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        Trfee =  Commission(Amount, Fee);
        AccountBalance -= Trfee;
        _TransferLog(DestinationClient, Trfee ,Amount, UserName);
        return true;


    }

    float Commission(double Amount, float commission)
    {
        float TransactionsCommission = 0;
        TransactionsCommission = Amount * commission;

        return TransactionsCommission;

      

    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();

    }

    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        float TotalBalance = 0;

        for (clsBankClient& C : vClients)
        {

            TotalBalance += C.GetAccountBalance();

        }


        return TotalBalance;

    }

    static vector <stTransferLogRecord> GetTransferLogList()
    {

        return _LoadTransferLogFromFile();
     
    }
   
};

