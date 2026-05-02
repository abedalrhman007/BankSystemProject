#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"
#include  "clsBankClient.h"


class clsTransferLogScreen :protected clsScreen
{

private:

    static void _PrintLoginRegisterRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(5) << left << TransferLogRecord.SenderAccountNumber;
        cout << "| " << setw(5) << left << TransferLogRecord.ReciverAccountNumber;
        cout << "| " << setw(5) << left << TransferLogRecord.Amount;
        cout << "| " << setw(5) << left << TransferLogRecord.SenderBalance;
        cout << "| " << setw(5) << left << TransferLogRecord.ReciverBalance;
        cout << "| " << setw(5) << left << TransferLogRecord.UserName;
    }

public:

    static void ShowTransferLogScreen()
    {


        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GerTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(5) << "s.Acct";
        cout << "| " << left << setw(5) << "d.Acct";
        cout << "| " << left << setw(5) << "Amount";
        cout << "| " << left << setw(5) << "s.Balance";
        cout << "| " << left << setw(5) << "d.Balance";
        cout << "| " << left << setw(5) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

