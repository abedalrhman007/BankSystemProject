#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h" 
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"


class clsCurrencyExhangeMainScreen : public clsScreen
{
private:
    enum enCurrencyMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2,
        eUpdateRate = 3, eCurrencyCalculator = 4, eShowMainMenue = 5
    };

    static short ReadCurrencyOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }


    static void _ShowListCurrencyScreen()
    {
        // cout << "\n Deposit Screen will be here.\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
        
    }

    static void _ShowFindCurrencyScreen()
    {
       // cout << "\n Withdraw Screen will be here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
       
    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "\n Balances Screen will be here.\n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalcultorScreen()
    {
        // cout << "\n Tansfer Screen will be here.\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

    
    static void _GoBackToCurrencyExhangeMenue()
    {
       
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowCurrencyExchange();

    }

    static void _PerformCurrencyExhangeMenueOption(enCurrencyMenueOptions CurrencyMenueOptions)
    {
        switch (CurrencyMenueOptions)
        {
        case enCurrencyMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrencyScreen();
            _GoBackToCurrencyExhangeMenue();
           
           
            break;
        }

        case enCurrencyMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        }

        case enCurrencyMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        }

        case enCurrencyMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalcultorScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        }

        

        case enCurrencyMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;

        }
        }


    }


public:

	static void ShowCurrencyExchange()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExhange))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t  Currency Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExhangeMenueOption((enCurrencyMenueOptions)ReadCurrencyOption());
    }

	

};

