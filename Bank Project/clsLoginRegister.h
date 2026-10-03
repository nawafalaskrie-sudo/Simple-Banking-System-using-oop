#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsString.h"
#include <iomanip>
class clsLoginRegister:protected clsScreen
{
private:
	
    static void PrintLoginRegisterRecoredLine(clsUser::stLoginRegisterRecored LoginRegisterRecored) {
        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecored.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecored.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecored.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecored.Permissions;

    }
public:
   static void ShowLoginRegister() {
       if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
       {
           return;// this will exit the function and it will not continue
       }

        vector<clsUser::stLoginRegisterRecored>vLoginRegister = clsUser::GetLoginRegisterList();
        string Titel = "\tLogin Register List Screen";
        string SubTitel = "\t\t(" + to_string(vLoginRegister.size()) + ")Recored(s).";
        clsScreen::_DrawScreenHeader(Titel,SubTitel);

        cout << setw(8) << left << "" << "\n------------------------------------------------------------------";
        cout << "--------------------------------------------\n";
        cout << setw(8) << left << "" << "| " << setw(35) << left <<"DateTime";
        cout << "| " << setw(20) << left << "UserName";
        cout << "| " << setw(20) << left << "Password";
        cout << "| " << setw(10) << left << "Permissions"<<endl;
        cout << setw(8) << left << "" << "\n------------------------------------------------------------------";
        cout << "--------------------------------------------\n";
        if (vLoginRegister.size() == 0) {
            cout << "\n\t\t NO Logins Avaliable in System.";
        }
        else
        for (clsUser::stLoginRegisterRecored Login : vLoginRegister) {
            PrintLoginRegisterRecoredLine(Login);
            cout << endl;
        }
        cout << setw(8) << left << "" << "\n------------------------------------------------------------------";
        cout << "--------------------------------------------\n";
    }
};

