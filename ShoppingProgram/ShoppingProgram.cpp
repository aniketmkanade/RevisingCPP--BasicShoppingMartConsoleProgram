#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
        private:
                int pcode;
                float price;
                float dis;
                string pname;
        public:
                void menu();
                void administrator();
                void buyer();
                void add();
                void edit();
                void rem();
                void list();
                void reciept();
};
/*
1. Display the menu
2. Allows to chose users between Administrator and buyer
3. Login for the administrator
*/
void shopping :: menu()
{       m:
        int choice;
        string email;
        string password;

        cout<<"\t\t\t\t_______________________________\n";
        cout<<"\t\t\t\t                               \n";
        cout<<"\t\t\t\t    Supermarket Main Menu      \n";
        cout<<"\t\t\t\t                               \n";
        cout<<"\t\t\t\t_______________________________\n";
        cout<<"\t\t\t\t                               \n";
        cout<<"\t\t\t\t| 1) Administrator  |\n";
        cout<<"\t\t\t\t|                   |\n";
        cout<<"\t\t\t\t| 2) Buyer          |\n";
        cout<<"\t\t\t\t|                   |\n";
        cout<<"\t\t\t\t| 3) Exit           |\n";
        cout<<"\n\t\t\t Please select!";
        cin>>choice;

        switch(choice)
        {
                case 1:
                        cout<<"\t\t\t Please login \n";
                        cout<<"\t\t\t Enter Email  \n";
                        cin>>email;
                        cout<<"\t\t\t Password     \n";
                        cin>>password;

                        if(email=="aniketmkanade@gmail.com" && password=="aniket@123")
                        {
                              administrator();  
                        }
                        else
                        {
                                cout<<"Invalid email/password";
                        }
                        break;
                case 2:
                        {
                                buyer();
                        }
                case 3:
                        {
                                exit(0);
                        }
                        default :
                        {
                                cout << "Please select from the given options";
                        }
        }
        goto m; 
}

/*
Administrator Functionalities
*/
void shopping:: administrator()
{
        m:
        int choice;
        cout<<"\n\n\n\n\t\t\t Administrator menu";
        cout<<"\n\t\t\t|_____ 1) Add the product____|";
        cout<<"\n\t\t\t|                            |";
        cout<<"\n\t\t\t|_____ 2) Modify the product_|";
        cout<<"\n\t\t\t|                            |";
        cout<<"\n\t\t\t|_____ 3) Delete the product_|";
        cout<<"\n\t\t\t|                            |";
        cout<<"\n\t\t\t|_____ 4) Back to main menu__|";

        cout<<"\n\n\t Please enter your choice ";
        cin>>choice;

        switch(choice)
        {
                case 1:
                        add();
                        break;
                case 2:
                        edit();
                        break;
                case 3:
                        rem();
                        break;
                case 4:
                        menu();
                        break;
                default:
                        cout<<"Invalid choice!";
        }
        goto m; 
}

/*
Buyer Functionalities
*/
void shopping:: buyer()
{
        m:
        int choice;
        cout<<"\t\t\t Buyer \n";
        cout<<"                \n";
        cout<<"\t\t\t 1) Buy product \n";
        cout<<"                \n";
        cout<<"\t\t\t 2) Go back \n";
        cout<<"                \n";
        cout<<"\t\t\t Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
                case 1:
                        reciept();
                        break;
                case 2:
                        menu();
                        break;
                default:
                        cout<<"Invalid choice";
                        break;
        }
        goto m; 
}

/*
Add new product functionality for administrator
*/
void shopping:: add()
{
        m:
        fstream data;
        int c;
        int token=0;
        float p;
        float d;
        string n;

        cout<<"\n\n\t\t\t Add new product";
        cout<<"\n\n\t Product code of the product";
        cin>>pcode;
        cout<<"\n\n\t Name of the product ";
        cin>>pname;
        cout<<"\n\n\t Price of the product";
        cin>>price;
        cout<<"\n\n\t Discount on the product";
        cin>>dis;

        //Will open file in reading mode
        data.open("database.txt",ios::in); 

        //If file doesn't exits
        if(!data)
        {
                //ios::app|ios::out Open the file in append mode and will allow writting to the file
                data.open("database.txt", ios::app|ios::out);
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                data.close();
        }
        //If file exists
        else
        {
                //Initialising the index
                data>>c>>n>>p>>d;
                while(!data.eof())
                {
                        //Check if duplication is happening
                        if(c==pcode)
                        {
                                token++;
                        }
                        //Reading for the file
                        data>>c>>n>>p>>d;
                }
                data.close();
                //If product is duplicate
                if(token == 1)
                        goto m;
                else
                {
                        //ios::app|ios::out Open the file in append mode and will allow writting to the file
                        data.open("database.txt", ios::app|ios::out);
                        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                        data.close();
                }
        }
        cout<<"\n\n\t\t Record inserted !";
}       

/*
Edit new product functionality for administrator
*/
void shopping:: edit()
{
        fstream data, data1;
        int pkey;
        int token=0;
        int c;
        float p;
        float d;
        string n;

        cout<<"\n\t\t\t Modify the record";
        cout<<"\n\t\t\t Product code :";
        cin>>pkey;

        data.open("database.txt",ios::in);
        if(!data)
        {
                cout<<"\n\nFile doesn't exists";
        }
        else
        {
                //Save out edited data to this file and then will rename this file
                data1.open("database1.txt",ios::app|ios::out);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof())
                {
                        if(pkey==pcode)
                        {
                                cout<<"\n\t\t Product of new code";
                                cin>>c;
                                cout<<"\n\t\t Name of the product";
                                cin>>n;
                                cout<<"\n\t\t Price of the product";
                                cin>>p;
                                cout<<"\n\t\t Discount of the product";
                                cin>>d;
                                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                                cout<<"\n\n\t\t Record edited";
                        }
                        else
                        {
                              data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                        }
                        data>>pcode>>pname>>price>>dis;
                }
                data.close();
                data1.close();
                //Renaming the file name
                remove("database.txt");
                rename("database1.txt","database.txt");  

                if(token == 0)
                {
                cout<<"\n\n Record not found";
                }
        }
}
/*
remove product functionality for administrator
*/
void shopping:: rem()
{
        fstream data, data1;
        int pkey;
        int token=0;
        cout<<"\n\n\t Delete product";
        cout<<"\n\n\t Product code :";
        cin>>pkey;
        data.open("database.txt",ios::in);
        if(!data)
        {
                cout<<"\n\n file doesnt exist";
        }
        else
        {
                data1.open("database1.txt",ios::app|ios::out);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof())
                {
                        if(pcode == pkey)
                        {
                                cout<<"\n\n\t Product deleted successfully";
                                token++;
                        }
                        else
                        {
                                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                        }
                        data>>pcode>>pname>>price>>dis;
                }
                data1.close();
                data.close();
                remove("database.txt");
                rename("database1.txt","database.txt");

                if(token==0)
                {
                        cout<<"\n\n Record not found";
                }
        }
}

/*
Displays the cart
*/
void shopping:: list()
{
        fstream data;
        data.open("database.txt",ios::in);
        cout<<"\n\n|___________________________________\n";
        cout<<"ProNo\t\tName\t\tPrice\n";
        cout<<"\n\n|___________________________________\n";
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
                cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
                data>>pcode>>pname>>price>>dis;
        }
        data.close();
}

/*
Displays the reciept.
*/
void shopping:: reciept()
{
        fstream data;

        int arrc[100];
        int arrq[100];
        char choice;
        int c=0;
        float amount=0;
        float dis=0;
        float total=0;

        cout<<"\n\n\t\t\t\t Reciept ";
        data.open("database.txt",ios::in);
        if(!data)
        {
                cout<<"\n\t\t\t Empty database";
        }
        else
        {
                data.close();
                list();
                cout<<"\n_____________________________\n";
                cout<<"\n                             \n";
                cout<<"\n      Please place the order \n";
                cout<<"\n                             \n";
                cout<<"\n_____________________________\n";
                do
                {
                        m:
                        cout<<"\n Enter Product code :";
                        cin>>arrc[c];
                        cout<<"\n\nEnter the product quantity :";
                        cin>>arrq[c];
                        for(int i=0;i<c;i++)
                        {
                                if(arrc[c] == arrc[i])
                                {
                                        cout<<"\n\n Duplicate product code. Please try again.";
                                        goto m;
                                }
                                c++;
                                cout<<"\n\n Do you want to buy another product? If yes press y else no";
                                cin>>choice;
                        }
                } while (choice == 'y');
                
                cout<<"\n\n\t\t\t________________Reciept___________\n";
                cout<<"\nProduct No\t Product Name \t Product Quantity \t Price \t Amount \t Amount with discount\n";

                for(int i=0;i<c;i++)
                {
                        data.open("database.txt",ios::in);
                        data<<pcode<<pname<<price<<dis;
                        while(!data.eof())
                        {
                                if(pcode==arrc[i])
                                {
                                        amount = price*arrq[i];
                                        dis= amount - (amount*dis/100);
                                        total = total + dis;
                                        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                                }
                                data>>pcode>>pname>>price>>dis;
                        }
                }
                data.close();
        }
        cout<<"\n\n______________________________";
        cout<<"\n Total Amount: "<<total;
}

int main()
{
        shopping s;
        s.menu();
        return 0;
}