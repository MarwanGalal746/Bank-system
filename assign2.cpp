/*
Name: Marwan Galal Mohamed Abdallah  .. ID: 20180268
Name: Bishoy Mokhless Khela Abdallah  .. ID: 20180072
*/
#include <iostream>
#include <cstring>
using namespace std;
void store_name(char arr[][100],int num)
{
    cout<<"Please enter name of the customer"<<endl;
    cin>>arr[num];
    cout<<endl<<endl;
}
bool check_address(char num_of_building[10],char street_name[100],char street[10],char neighbour[10],char arr[20][100],int num)
{
    bool flag=true;
    for(int i=0;i<strlen(num_of_building);i++)
    {
        if((int)num_of_building[i]>=(int)'0'&&(int)num_of_building[i]<=(int)'9')
        {
            flag=true;
        }
        else
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        for(int i=0;i<strlen(street_name);i++)
        {
            if(((int)street_name[i]>=(int)'0'&&(int)street_name[i]<=(int)'9'))
            {
                flag=false;
                break;
            }
        }
    }
    if(flag)
    {
        if(street[0]=='s'&&street[1]=='t'&&street[2]=='r'&&street[3]=='e'&&street[4]=='e'&&street[5]=='t'&&street[6]==',')
        {
            flag=true;
        }
        else
        {
            flag=false;
        }
    }
    if(flag)
    {
        if(neighbour[strlen(neighbour)-1]!=',')
        {
            flag=false;
        }
        for(int i=0;i<strlen(neighbour)&&!flag;i++)
        {
            if(((int)neighbour[i]>=(int)'0'&&(int)neighbour[i]<=(int)'9'))
            {
                flag=false;
                break;
            }
        }
    }
    if(flag)
    {
        for(int i=0;i<strlen(arr[num]);i++)
        {
            if(((int)arr[num][i]>=(int)'0'&&(int)arr[num][i]<=(int)'9'))
            {
                flag=false;
                break;
            }
        }
    }
    return flag;
}
void store_address(char arr [20][100],int num)
{
    cout<<"Please enter address"<<endl;
    char num_of_building[10],street_name[100],street[10],neighbour[10];
    cin>>num_of_building>>street_name>>street>>neighbour>>arr[num];
    cout<<endl;
    while(!check_address(num_of_building,street_name,street,neighbour,arr,num))
    {
        cout<<"please enter valid address"<<endl;
        cin>>num_of_building>>street_name>>street>>neighbour>>arr[num];
    }
    cout<<endl<<endl;
}
bool num_Of_Transactions(char arr[10000])
{
    bool greater10=true;
    int transaction=0;
    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='W'||arr[i]=='D'||arr[i]=='d'||arr[i]=='w'){transaction++;}
    }
    if(transaction<1&&transaction<10){greater10=true;}
    else{greater10=false;}
    return greater10;
}
bool minuss(char arr[])
{
    bool flag=false;
    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='-'){flag=true;break;}
    }
    return flag;
}
void edit_Minuss(char arr[10000])
{
    bool occ_Minuss=false;
    int num_Of_Minuss=0;
    char valid[10000];
    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='-')
        {
            num_Of_Minuss++;
            occ_Minuss=true;
            arr[i-2]=' ';
        }
    }
    if(occ_Minuss)
    {
        for(int j=0;j<num_Of_Minuss;j++)
        {
            cout<<"Please enter valid transaction"<<endl;
            cin.getline(valid,10000,'\n');
            while(minuss(valid))
            {
                cout<<"Please re-enter valid transaction"<<endl;
                cin.getline(valid,10000,'\n');
            }
            edit_Minuss(valid);
            int len=strlen(arr);
            arr[len]=' ';
            len++;
            for(int i=0;i<strlen(valid);i++)
            {
                arr[len]=valid[i];
                len++;
            }
        }
        cout<<endl;
    }
}
int str_To_Int(char s[])
{
    int num=0,digit=strlen(s),multiplier=1,temp;
    for(int i=1;i<digit;i++){multiplier*=10;}
    for(int i=0;i<strlen(s);i++)
    {
        switch(int(s[i]))
        {
            case((int)'0'):
            {
                temp=0;
                break;
            }
            case((int)'1'):
            {
                temp=1;
                break;
            }
            case((int)'2'):
            {
                temp=2;
                break;
            }
            case((int)'3'):
            {
                temp=3;
                break;
            }
            case((int)'4'):
            {
                temp=4;
                break;
            }
            case((int)'5'):
            {
                temp=5;
                break;
            }
            case((int)'6'):
            {
                temp=6;
                break;
            }
            case((int)'7'):
            {
                temp=7;
                break;
            }
            case((int)'8'):
            {
                temp=8;
                break;
            }
            case((int)'9'):
            {
                temp=9;
                break;
            }
        }
        temp*=multiplier;
        num+=temp;
        multiplier/=10;
    }
    return num;
}
int calc_Balance(char s[], int money)
{
    int sign;
    int balance=money;
    bool add=true;
    for(int i=0;i<strlen(s);i++)
    {
        char num[10]={'/0'};
        if(s[i]=='W'||s[i]=='D'||s[i]=='d'||s[i]=='w')
        {
            if(s[i]=='D'||s[i]=='d'){add=true;}
            else{add=false;}
            int j=0;
            for(int r=i+2;s[r]!=' '&&s[r]!='\0';r++)
            {
                num[j]=s[r];
                j++;
            }
            if(add){balance+=str_To_Int(num);}
            else{balance-=str_To_Int(num);}
        }
    }
    return balance;
}
void store_balance(int bal[],char history_of_trans[][10000],int num)
{
    char trans[10000];
    cout<<"Please enter customer account transactions"<<endl;
    cin.getline(trans,10000,'\n');
    cin.getline(trans,10000,'\n');
    while(num_Of_Transactions(trans))
    {
        cout<<"The limit of transactions is 10 transactions, please enter a valid number of transactions"<<endl;
        cin.getline(trans,10000,'\n');
    }
    edit_Minuss(trans);
    for(int i=0;i<strlen(trans);i++)
    {
        history_of_trans[num][i]=trans[i];
    }
    int balance=calc_Balance(trans,50000);
    bal[num]=balance;
    cout<<endl<<endl;;
}
bool search_name(char arr[][100],char name[],int num)
{
    bool flag;
    for(int i=0;i<num;i++)
    {
        for(int r=0;r<strlen(name);r++)
        {
            if(name[r]==arr[i][r]){flag=true;}
            else{flag=false;break;}
        }
        if(flag==true){break;}
    }
    return flag;
}
void menu()
{
    cout<<"Hello in bank management system please enter your choice"<<endl;
    cout<<"1) To print all names and account balances"<<endl;
    cout<<"2) To print specific customer account balance"<<endl;
    cout<<"3) To edit customer transactions"<<endl;
    cout<<"4) To show customer with highest balance"<<endl;
    cout<<"5) To change customer name, transactions, balance, or address"<<endl;
    cout<<"6) To show how many customers in one city"<<endl;
}
void first_option(char arr[][100],int bal[],int num)
{
    for(int i=0;i<num;i++)
    {
        cout<<"account balance of "<<arr[i]<<" = "<<bal[i]<<endl;
    }
}
void second_option(char arr[][100],int bal[],int num)
{
    char name[100];
    cout<<"please enter name of the customer"<<endl;
    cin>>name;
    while(!search_name(arr,name,num))
    {
        cout<<"this name is not found, please enter a valid name"<<endl;
        cin>>name;
    }
    bool flag;
    int sign;
    for(int i=0;i<num;i++)
    {
        for(int r=0;r<strlen(name);r++)
        {
            if(name[r]==arr[i][r])
            {
                flag=true;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            sign=i;
            break;
        }
    }
    cout<<sign<<endl;
    cout<<"the balance of the customer "<<arr[sign]<<" = "<<bal[sign]<<endl;
}
bool happen_trans(char history_of_trans[][10000],char old[],int sign)
{
    bool flag;
    for(int i=0;i<strlen(history_of_trans[sign]);i++)
    {
        for(int r=0;r<strlen(old);r++)
        {
            if(history_of_trans[sign][i+r]==old[r])
            {
                flag=true;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }
    return flag;
}
void remove_old(int number_of_customer,char history_of_trans[][10000],char old[],int bal[])
{
    bool flag;
    int sign;
    for(int i=0;i<strlen(history_of_trans[number_of_customer]);i++)
    {
        for(int r=0;r<strlen(old);r++)
        {
            if(history_of_trans[number_of_customer][i+r]==old[r])
            {
                flag=true;
            }
            else
            {
                flag=false;
            }
            sign=r;
        }
        if(flag)
        {
            for(int m=0;m<strlen(old);m++)
            {
                bool add;
                char num[10]={'/0'};
                if(old[m]=='W'||old[m]=='D'||old[m]=='d'||old[m]=='w')
                {
                    if(old[m]=='D'||old[m]=='d'){add=false;}
                    else{add=true;}
                    int j=0;
                    for(int k=i+2;old[k]!=' '&&old[k]!='\0';k++)
                    {
                        num[j]=old[k];
                        j++;
                    }
                    if(add){bal[number_of_customer]+=str_To_Int(num);}
                    else{bal[number_of_customer]-=str_To_Int(num);}
                }
            }
            history_of_trans[number_of_customer][i]=' ';
            break;
        }
    }
}
void third_option(char arr[][100],int bal[],char history_of_trans[][10000],int num)
{
    char name[100];
    cout<<"please enter name of the customer"<<endl;
    cin>>name;
    while(!search_name(arr,name,num))
    {
        cout<<"this name is not found, please enter a valid name"<<endl;
        cin>>name;
    }
    bool flag;
    int sign;
    for(int i=0;i<num;i++)
    {
        for(int r=0;r<strlen(name);r++)
        {
            if(name[r]==arr[i][r])
            {
                flag=true;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            sign=i;
            break;
        }
    }
    int num_edit;
    cout<<"how many transactions do you want to edit ?"<<endl;
    cin>>num_edit;
    while(num_edit<0)
    {
        cout<<"please enter a valid number"<<endl;;
        cin>>num_edit;
    }
    for(int i=0;i<num_edit;i++)
    {
        char old[10000]={'/0'},neew[10000]={'/0'};
        cout<<"please enter a transaction which you want to edit"<<endl;
        cin.getline(old,10000,'\n');
        if(i==0)
            cin.getline(old,10000,'\n');
        while(!happen_trans(history_of_trans,old,sign))
        {
            cout<<"this transaction is not found, please enter a valid transaction"<<endl;
            cin.getline(old,10000,'\n');
        }
        remove_old(sign,history_of_trans,old,bal);
        cout<<"please enter new transaction"<<endl;
        cin.getline(neew,10000,'\n');
        edit_Minuss(neew);
        int j=0;
        for(int r=strlen(history_of_trans[sign]);j<strlen(neew);r++)
        {
            history_of_trans[sign][r]=neew[j];
            j++;
        }
        bal[sign]=calc_Balance(neew,bal[sign]);
    }
    cout<<arr[sign]<<" new balance = "<<bal[sign]<<endl;
}
void fourth_option(char arr[][100], int bal[] , int num)
{
    int maxi=bal[0];
    int sign;
    for(int i=0;i<num;i++)
    {
        if(bal[i]>=maxi)
        {
            maxi=bal[i];
            sign=i;
        }
    }
    cout<<sign;
    cout<<"the customer with the highest balance is "<<arr[sign]<<" and his balance = "<<bal[sign]<<endl;
}
void fifth_option(char arr[][100],int num,char history_of_trans[][10000],int bal[],char city[20][100])
{
    int choice;
    cout<<"please enter a choice"<<endl;
    cout<<"1) To change name of a customer"<<endl;
    cout<<"2) To change transactions and balance of a customer"<<endl;
    cout<<"3) To change address of a customer"<<endl;
    cin>>choice;
    while(choice<1||choice>3)
    {
        cout<<"please enter a valid choice"<<endl;
        cin>>choice;
    }
    switch(choice)
    {
    case 1:
        {
            char name[100];
            cout<<"please enter name of the customer"<<endl;
            cin>>name;
            while(!search_name(arr,name,num))
            {
                cout<<"this name is not found, please enter a valid name"<<endl;
                cin>>name;
            }
            bool flag;
            int sign;
            for(int i=0;i<num;i++)
            {
                for(int r=0;r<strlen(name);r++)
                {
                    if(name[r]==arr[i][r])
                    {
                        flag=true;
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    sign=i;
                    break;
                }
            }
            cout<<"please enter the new name"<<endl;
            cin>>arr[sign];
            break;

        }
    case 2:
        {
            char name[10];
            cout<<"please enter name of customer"<<endl;
            cin>>name;
            bool flag;
            int sign;
            for(int i=0;i<num;i++)
            {
                for(int r=0;r<strlen(name);r++)
                {
                    if(name[r]==arr[i][r])
                    {
                        flag=true;
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag=true)
                {
                    sign=i;
                    break;
                }
            }
            history_of_trans[sign][0]={'\0'};
            store_balance(bal,history_of_trans,sign);
            cout<<"new balance of "<<arr[sign]<<" = "<<bal[sign]<<endl;
            break;
        }
    case 3:
        {
            cout<<"please enter name of customer"<<endl;
            char name[100];
            cin>>name;
            bool flag;
            int sign;
            for(int i=0;i<num;i++)
            {
                for(int r=0;r<strlen(name);r++)
                {
                    if(name[r]==arr[i][r])
                    {
                        flag=true;
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    sign=i;
                    break;
                }
            }
            city[sign][0]='\0';
            store_address(city,sign);
            break;
        }
    }
}
void sixth_option(char arr[][100],int num)
{
    bool flag;
    for(int i=0;i<num;i++)
    {
        int people=1;
        for(int r=0;r<num;r++)
        {
            for(int j=0;j<strlen(arr[i]);j++)
            {
                if(arr[i][j]==arr[r][j] && i!=r &&arr[i][j]!='\0')
                {
                    flag=true;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                people++;
                arr[r][0]='\0';
            }
        }
        if(people>=1&&people<=num&&arr[i][0]!='\0'){cout<<people<<" customers in "<<arr[i]<<endl;}
        arr[i][0]='\0';
    }
}
int main()
{
    char complete[3]={'y','e','s'};
    cout<<"please enter number of customers"<<endl;
    int num_of_customer;
    cin>>num_of_customer;
    while(num_of_customer>20)
    {
        cout<<"please enter a valid number of cusromers"<<endl;
        cin>>num_of_customer;
    }
    cout<<endl<<endl;
    char names[20][100], city[20][100],trans[10000],history_of_trans[20][10000];
    int balance[20];
    for(int i=0;i<num_of_customer;i++)
    {
        store_name(names,i);
        store_address(city,i);
        store_balance(balance,history_of_trans,i);
    }
    menu();
    int choice;
    bool cond=true;
    while(cond)
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            {

                first_option(names,balance,num_of_customer);
                break;
            }
        case 2:
            {
                bool cond=true;
                char complete[3]={'y','e','s'};
                while(cond)
                {
                    second_option(names,balance,num_of_customer);
                    cout<<"Do you want to use this option again ?"<<endl;
                    cin>>complete;
                    if((complete[0]=='Y'||complete[0]=='y')&&(complete[1]=='E'||complete[1]=='e')&&(complete[2]=='S'||complete[2]=='s'))
                    {
                        cond=true;
                    }
                    else
                    {
                        cond=false;
                    }
                }
                break;
            }
        case 3:
            {
                bool cond=true;
                char complete[3]={'y','e','s'};
                while(cond)
                {
                    third_option(names,balance,history_of_trans,num_of_customer);
                    cout<<"Do you want to use this option again ?"<<endl;
                    cin>>complete;
                    if((complete[0]=='Y'||complete[0]=='y')&&(complete[0]=='E'||complete[0]=='e')&&(complete[2]=='S'||complete[2]=='s'))
                    {
                        cond=true;
                    }
                    else
                    {
                        cond=false;
                    }
                }
                break;
            }
        case 4:
            {
                fourth_option(names,balance,num_of_customer);
                break;
            }
        case 5:
            {
                char complete[3]={'y','e','s'};
                bool cond=true;
                while(cond)
                {
                    fifth_option(names,num_of_customer,history_of_trans,balance,city);
                    cout<<"Do you want to use this option again ?"<<endl;
                    cin>>complete;
                    if((complete[0]=='Y'||complete[0]=='y')&&(complete[1]=='E'||complete[1]=='e')&&(complete[2]=='S'||complete[2]=='s'))
                    {
                        cond=true;
                    }
                    else
                    {
                        cond=false;
                    }
                }
                break;
            }
        case 6:
            {
                sixth_option(city,num_of_customer);
                break;
            }
        }
        cout<<"Do you want to choose another option ?"<<endl;
        cin>>complete;
        if((complete[0]=='Y'||complete[0]=='y')&&(complete[1]=='E'||complete[1]=='e')&&(complete[2]=='S'||complete[2]=='s'))
        {
            cond=true;
        }
        else
        {
            cond=false;
        }
    }

    return 0;
}
