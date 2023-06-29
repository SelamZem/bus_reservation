
/*

Admin  = pg2 // stands for programming 2
password = 1234

*/




#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>//to set width
#include <cstdlib>
#include <string.h>


using namespace std;

#define SIZE 50


int siz = 0;

class Sortings
{
	public:
	int  noSeac;
	float distancec;//distance on the txtfile
	string busIdc, dNamec, sourcec, destinationc, arrivec, departc;
	
	//member functions
	public:
	void read();
	void sortID();
	void sortSource();
	void sortDest();
	
	
};

Sortings obj[SIZE];



	


struct Our_Bus{
	
	int numSeat;//number of seats
	string id_num,driversName, source, destination;
	float distance;//distance in kms
	string arrival_time, depature_time;
	
	}bus;
	
	

struct Booking{
	
	string fName,lName;
	int noSeat, confirm;//no of seat one wanted to book
	Our_Bus bus;
}book;

	
int falseTry = 0;// makes sure the employee tried to login in not more than 3 times
float rate = 2.50;//our company charges $2.50 perkillometer
int array_doc[9][4]={0};//array to assign customer seat
string cities[8] = {"Addis_Ababa", "Adama", "Bahirdar", "Gondar", "Hawassa","Jimma","Mekelle","Semera"};//source
string gize[2]={"11:00am", "11:00pm"};//depature time

//void adminChoice();//takes the admin choice inform of number
void registers();//register a new employee
void printEmployees();//prints all the employees who have an access
void installBus();//Add new bus
void viewBus();//show the available bus
void updateBus();//Updates the bus
void searching();//Searching a bus using id
void deleting();//delete a bus from the system
void cancel2();//takes to the main page
void books();
void ticket();//gives ticket
void delete_book();//delete bookings

//Employee page
void employee_page();
void bookEs();// book in employeeside
void viewEBus();//employee; 

//searching
void searchingId();//search by id of the bus
void searchingsource();//search by source of the bus
void searchingDest();//search by the Destination of the bus
void searchingDriver();//Search by the driversname

//functions used to login and pages
void direct(int);//directs to the function
int  choice();//accept value and direct to the system accordingly
void admin_login(); //admin can access everything employee can and register a new employee
void admin_page();//appears after the admin logged in succesfully
void employee_login();//anyone with user_name and password can access the system
void employee_page();//it appears after the employee logged in successfully
void cancel();// to exit from the program
void statsAd();//asks the admin which page they want to be
void statEm();//asks the employee which page they want to be

//class
void display();

int main()
{
	int x;
	x = choice();
	direct(x);
	
	
	
	return 0; 
}

//check stat
void statEm()
{
	//asks the employee wwhat he want to do next(after executing of the current function
	char stat;
	cout<<endl<<"\t\t\tDo you want to return to the previous menu:(Y/N) ";
	cin>>stat;
	
	if(stat=='Y'||stat=='y') 
	{
		system("cls");
		employee_page();
	}
	else
	{	
		system("cls");
	 	main();
	}	
}

void statsAd()
{	//asks the admin wwhat he want to do next(after executing of the current function
	char stat;
	cout<<endl<<"\t\t\tDo you want to return to the previous menu:(Y/N) ";
	cin>>stat;
	
	if(stat=='Y'||stat=='y') 
	{
		system("cls");
		admin_page();
	}
	else
	{	
		system("cls");
	 	main();
	}
	
}

//check stat



int choice()
{
	int user_choice;
	
	cout<<"\t\t _____________________________________________________________________\n";
	cout<<"\t\t||____________________________________________________________________|\n";
	cout<<"\t\t||\t\t()                                 ()\t\t\n";
	cout<<"\t\t||\t\t()                                 ()\t\t\n";
	cout<<"\t\t||\t\t()                                 ()\t\t\n";
	cout<<"\t\t||\t|----------------------------------------------------|\n";
	cout<<"\t\t||\t|_____Welcome to Ethio Bus reservation system________|\n";
	cout<<"\t\t||\t|----------------------------------------------------|\n";
	cout<<"\t\t||\t|                                                    |\n";
	cout<<"\t\t||\t|\t1. Login into the admin page"<<"                 ||\n";
	cout<<"\t\t||\t|\t2. Login into the employee page"<<"              ||\n";
	cout<<"\t\t||\t|\t0. Exit"<<"                                      ||\n";
	cout<<"\t\t||\t|----------------------------------------------------||\n";
	cout<<"\t\t||\t-------------------------------------------------------\n";
	cout<<"\t\t||\t\t++++\t\t\t\t++++\n";
	cout<<"\t\t||\t\t++++\t\t\t\t++++\n";
	cout<<"\t\t||\n";
	cout<<"\t\t||\n";
	cout<<"\t\t||\n";
	cout<<"\t\t||\n";
	cout<<"\t========||=========\t\n";
	cout<<"\t===============================================================\t\n";
	
	do
	{
		cout<<"\t\t\tEnter your choice: ";//only handles integers...it will exit for other chars
		cin>>user_choice;
	}
	while(user_choice!=1 && user_choice!=2 && user_choice!=0);
	
	
	return user_choice;
}

void direct(int userChoice)
{

	switch(userChoice)
	{
	case 1:
		admin_login();
		break;
	case 2:
		employee_login();
		break;
	case 0:
		{
			cancel();
			cout<<"\t\t\tThank you for visiting!";		
			break;	
		}
	default:
		{
			system("cls");
			cout<<endl<<"\t\tPlease enter your choice correctly\n";
			main();
		}
	}
}

void admin_login()
{	string admin, password, admintxt , pwd;
	int counter = 0; //use to determine whether the user name and the password exit or not(similar to a boolean  value
	cout<<"\t\t\tPlease enter the username and password: \n\n";
	cout<<"\t\t\t\tAdmin: ";
	cin>>admin;
	cout<<"\t\t\t\tPassword: ";
	cin>>password;
	
	//reading a file named users.txt
	
	fstream myFile;
	myFile.open("users.txt", ios::in);
	
	while(myFile>>admintxt>>pwd)
	{
		if(admintxt==admin && pwd ==password)
		{
			counter = 1;	
		}
	}
	
	myFile.close();
	
	if(counter == 1)
	{
		system("cls");
		cout<<"\n\n\t\t\tYou are succesfully logged in!\n\n";
		admin_page();
		
	}
	
	else
		{
			system("cls");
			
			cout<<"\t\t\tThe user name and the password does not match.\n\t\t\tTry again ...\n";
			main();
			
		}
}

void employee_login()
{
		string employee, password, employeeF,employeeL , pwd;
	int counter = 0; //use to determine whether the user name and the password exit or not(similar to a boolean  value
	cout<<"\t\t\tPlease enter the username and password: \n\n";
	cout<<"\t\t\t\tEmployee First Name: ";
	cin>>employee;
	cout<<"\t\t\t\tPassword: ";
	cin>>password;
	
	//reading a file named users.txt
	
	fstream myFile;
	myFile.open("employees.txt", ios::in);
	
	while(myFile>>employeeF>>employeeL>>pwd)
	{
		if(employeeF==employee && pwd ==password)
		{
			counter = 1;	
		}
	}
	
	myFile.close();
	 
	if(counter == 1)
	{
		system("cls");
		cout<<"\t\tYou are succesfully logged in!\n\n";
		employee_page();
		
	}
	
	
	else
		{ 
			falseTry+=1;  
			if(falseTry<3)
			{
			
			system("cls");
			
			cout<<"\t\t\tThe user name and the password does not match.\n\t\t\tTry again ...\n";
			main();
			}
		
			else
			{
				cancel();
				cout<<"\t\tYou need to be an employee and have permission from the admin to access the account.\n\t\t\t";
			}
		}	
}
void cancel()
{
	system("cls");
}


void employee_page()
{
	cout<<"\t\t\t_______________________________________________________________";
	cout<<endl<<"\t\t\t---------------------------------------------------------------";
	cout<<endl<<"\t\t\t\t\t abc bus reservation system\n";
	cout<<"\t\t\t----------------------------------------------------------------";
	cout<<endl<<"\t\t\t_______________________________________________________________\n\n";
	
	
	cout<<"\n\t\t\t1.	Buses Available";
	cout<<"\n\t\t\t2.	Book Seat";
	cout<<"\n\t\t\t0.      Exit";
	cout<<"\n\n\n";
	
	
	//takes choice
	int emp_choice;
	cout<<endl<<"\t\t\t\tPlease enter your choice: ";
	cin>>emp_choice;
	
	switch(emp_choice)
	{
		case 1:
			viewEBus();
			break;
		case 2:
			bookEs();
			break;
		case 0:
			cancel2();
			break;
	}
}

void admin_page()
{
	cout<<"\t\t\t_______________________________________________________________";
	cout<<endl<<"\t\t\t---------------------------------------------------------------";
	cout<<endl<<"\t\t\t\t\t Ethio Bus reservation system\n";
	cout<<"\t\t\t----------------------------------------------------------------";
	cout<<endl<<"\t\t\t_______________________________________________________________\n\n";
	
	
	cout<<endl<<"\t\t\t1.	Register  new Employees ";
	cout<<endl<<"\t\t\t2.	Employees ";
	cout<<endl<<"\t\t\t3.	Install new Bus ";
	cout<<endl<<"\t\t\t4.	Update Bus ";
	cout<<endl<<"\t\t\t5.	Delete Bus ";
	cout<<endl<<"\t\t\t6.	Search Bus ";
	cout<<endl<<"\t\t\t7.	Buses Available ";
	cout<<endl<<"\t\t\t8.	Book Seat";
	cout<<endl<<"\t\t\t9.	Delete Booking ";
	cout<<endl<<"\t\t\t0.	Exit\n\n\n";
	
	int ad_choice;
	cout<<endl<<"\t\t\tPlease enter your choice: ";
	cin>>ad_choice;
	
	switch(ad_choice)
	{
		case 1:
			registers();
			break;
		case 2:
			printEmployees();
		case 3:
			installBus();
			break;
		case 4:
			updateBus();
			break;
		case 5: 
			deleting();
			break;
		case 6:
			searching();
			break;
		case 7:
			viewBus();
			break;
		case 8:
			books();
			break;
		case 9:
			delete_book();
			break;
		case 0:
			cancel2();
			break;
	}
}

void registers()
{
	string newEmployeeF,newEmployeeL, ePassword;
	
	system("cls");
	cout<<"\t\t\t---------------------------------------------------------------\n";
	cout<<"\t\t\t----------------------------------------------------------------\n\n";
	cout<<"\t\t\t\tFirst name: \t";
	cin>>newEmployeeF;
	cout<<"\t\t\t\tLast  name: \t";
	cin>>newEmployeeL;
	cout<<endl<<"\t\t\t\tEnter your password: \t";
	cin>>ePassword;
	
	fstream myFile;
	
	myFile.open("employees.txt", ios::app);//append
	if(myFile.is_open())
	{
		myFile<<newEmployeeF<<" "<<newEmployeeL<<" "<<ePassword<<endl;
		myFile.close();
	}
	
	system("cls");
	cout<<"\n\t\t\tYou succesfully added "<<newEmployeeF<<" "<<newEmployeeL<<" to the system";
	
	statsAd();
	
}

void printEmployees()
{
	system("cls");
	
	string fname,lname,pass;
	cout<<"\t\t........................................................\n";
	cout<<left<<"\t\t|\t"<<setw(15)<<"First name"<<"|"<<left<<setw(15)<<"Last name"<<"|"<<left<<setw(15)<<"Password"<<"|\n";
	cout<<"\t\t........................................................\n";
	
	
	fstream myFile;
	myFile.open("employees.txt", ios::in);
	
	
	
	while(myFile>>fname>>lname>>pass)
	{
		cout<<"\t\t|\t"<<left<<setw(15)<<fname<<"|"<<left<<setw(15)<<lname<<"|"<<left<<setw(15)<<pass<<"|\n";
		cout<<"\t\t........................................................\n";
	}
	cout<<"\n\n\n";
	myFile.close();
	
		statsAd();
	
}

void installBus()
{
	int atime, dtime;
	system("cls");
	cout<<"\n\n\n\t\t\tEnter the bus Id:\t";
	cin>>bus.id_num;
	cout<<endl<<"\t\t\tEnter the total number of seats:\t";
	cin>>bus.numSeat;
	bus.numSeat = 36;//our buses standard is 36 seats
	cout<<endl<<"\t\t\tEnter the drivers name:\t";
	cin>>bus.driversName;
	do
	{
	
		cout<<endl<<"\t\t\tArrival time:\t";
		cout<<endl<<"\t\t\t\t1. 11:00am";
		cout<<endl<<"\t\t\t\t2. 11:00pm";
		cout<<endl<<"\t\t\tPlease choose the bus arrival time:\t";
		cin>>atime;
	}while (atime!=1 && atime!=2);
	bus.arrival_time = gize[atime-1];
	do
	{
	cout<<endl<<"\t\t\tDepature time:\t";
	cout<<endl<<"\t\t\t\t1. 11:00am";
	cout<<endl<<"\t\t\t\t2. 11:00pm";
	cout<<endl<<"\t\t\tPlease choose the bus departure time\t";
	cin>>dtime;
	}while(dtime!=1 && dtime!=2);
	bus.depature_time = gize[dtime-1];

	cout<<endl<<"\t\t\tEnter the source:\t";//Exception Addis_Ababa
	cin>>bus.source;
	if( !(bus.source).empty() )
{
    (bus.source)[0] = toupper( (bus.source)[0] );

    for( short i = 1 ; i < (bus.source).length() ; ++i )
        (bus.source)[i] = tolower( (bus.source)[i] );
}
	cout<<endl<<"\t\t\tEnter the destination:\t";//Exception Addis_Ababa, capslock
	cin>>bus.destination;
	//this function capitalise the first letter of words and the rest small letter
	if( !(bus.destination).empty() )
{
    (bus.destination)[0] = toupper( (bus.destination)[0] );

    for( short i = 1 ; i < (bus.destination).length() ; ++i ) 
        (bus.destination)[i] = tolower( (bus.destination)[i] );
}
	cout<<endl<<"\t\t\tEnter the distance in kms:\t";
	cin>>bus.distance;
	
	
	//add to the bus file
	fstream myFile;
	
	myFile.open("bus.txt", ios::app);//append
	if(myFile.is_open())
	{
		myFile<<bus.id_num<<" "<<bus.numSeat<<" "<<bus.driversName<<" "<<bus.arrival_time<<" "<<bus.arrival_time<<" "<<bus.source<<" "<<bus.destination<<" "<<bus.distance<<endl;
		myFile.close();
		
	}
	
	cout<<"\n\t\t\tYou succesfully added  bus "<<bus.id_num<<" to the system";
	
	
	statsAd();
		
}

void viewBus()
{
	int  noSeat;
	float distancet;//distance on the txtfile
	string dName,busIdt, sourcet, destinationt,arrivet,depatt;
	int count = 1;//counts the number of buses
	system("cls");
	cout<<endl<<left<<setw(12)<<"No"<<left<<setw(12)<<"Id_Num"<<left<<setw(12)<<"Seat"<<left<<setw(12)<<"Driver"<<left<<setw(12)<<"arrival.t"<<left<<setw(12)<<"depart.t"<<left<<setw(12)<<"source"<<left<<setw(12)<<"desti."<<left<<setw(12)<<"distance\n"<<endl;
 	fstream myFile;
	myFile.open("bus.txt", ios::in);
	
	
	
	while(myFile>>busIdt>>noSeat>>dName>>arrivet>>depatt>>sourcet>>destinationt>>distancet)
	{
		cout<<left<<setw(12)<<count<<left<<setw(12)<<busIdt<<left<<setw(12)<<noSeat<<left<<setw(12)<<dName<<left<<setw(12)<<arrivet<<left<<setw(12)<<depatt<<left<<setw(12)<<sourcet<<left<<setw(12)<<destinationt<<left<<setw(12)<<distancet<<endl;
		count++;
	}
	cout<<"\n\n\n";
	myFile.close();
	
	
	
	display();
	
	
}

//updates a bus

void updateBus()
{
	
	int  noSeat;
	float distancet;//distance on the txtfile
	string busId, busIdt, dName, sourcet, destinationt, arrivet, departt;
	
	system("cls");
	cout<<"\t\t\tEnter the bus Id number you want to update: ";
	cin>>busId;
	
	
	ifstream myFile;//to read bus file
	myFile.open("bus.txt");
	
	ofstream temp;//temporary file which the file will be copied
	temp.open("temp.txt");
	
	while(myFile>>busIdt>>noSeat>>dName>>arrivet>>departt>>sourcet>>destinationt>>distancet)
	{
		
		int result  = strcmp(busIdt.c_str(), busId.c_str());//c_str it is because strcmp take const char* as an argument
		if(result!=0)
		{
			temp<<busIdt<<" "<<noSeat<<" "<<dName<<" "<<arrivet<<" "<<departt<<" "<<sourcet<<" "<<destinationt<<" "<<distancet<<endl;
		}
		
		//enter the updated info
		else
		{
				int atime, dtime;
	system("cls");
	cout<<"\n\n\n\t\t\tEnter the updated bus Id:\t";
	cin>>bus.id_num;
	cout<<endl<<"\t\t\tEnter the updated total number of seats:\t";
	cin>>bus.numSeat;
	bus.numSeat = 36;
	cout<<endl<<"\t\t\tEnter the updated drivers name:\t";
	cin>>bus.driversName;
	do
	{
	
		cout<<endl<<"\t\t\tArrival time:\t";
		cout<<endl<<"\t\t\t\t1. 11:00am";
		cout<<endl<<"\t\t\t\t2. 11:00pm";
		cout<<endl<<"\t\t\tPlease choose the updated bus arrival time:\t";
		cin>>atime;
	}while (atime!=1 && atime!=2);
	bus.arrival_time = gize[atime-1];
	do
	{
	cout<<endl<<"\t\t\tDepature time:\t";
	cout<<endl<<"\t\t\t\t1. 11:00am";
	cout<<endl<<"\t\t\t\t2. 11:00pm";
	cout<<endl<<"\t\t\tPlease choose the updated bus departure time\t";
	cin>>dtime;
	}while(dtime!=1 && dtime!=2);
	bus.depature_time = gize[dtime-1];

	cout<<endl<<"\t\t\tEnter the updated source:\t";
	cin>>bus.source;
	if( !(bus.source).empty() )
{
    (bus.source)[0] = toupper( (bus.source)[0] );

    for( short i = 1 ; i < (bus.source).length() ; ++i )
        (bus.source)[i] = tolower( (bus.source)[i] );
}
	cout<<endl<<"\t\t\tEnter the updated destination:\t";
	cin>>bus.destination;
		if( !(bus.destination).empty() )
{
    (bus.destination)[0] = toupper( (bus.destination)[0] );

    for( short i = 1 ; i < (bus.destination).length() ; ++i )
        (bus.destination)[i] = tolower( (bus.destination)[i] );
}
	
	cout<<endl<<"\t\t\tEnter the updated distance in kms:\t";
	cin>>bus.distance;
	
		
			cout<<"\n\t\t\tYou succesfully updated  bus "<<busId<<endl;	
		}		
	}
	myFile.close();
	temp.close();
	
	remove("bus.txt");
	rename("temp.txt","bus.txt");
	
	//adding the updated file to the sytem
	fstream myFile2;
	
	myFile2.open("bus.txt", ios::app);//append
	if(myFile2.is_open())
	{
		myFile2<<bus.id_num<<" "<<bus.numSeat<<" "<<bus.driversName<<" "<<bus.arrival_time<<" "<<bus.depature_time<<" "<<bus.source<<" "<<bus.destination<<" "<<bus.distance<<endl;
		myFile2.close();
	}
	
	//asks the user wwhat he want to do next(after executing of the current function
	statsAd();
	
}



//search a bus 

void searching()
{
		int yourChoice;
		system("cls");
		cout<<"\n\n\n";	
		cout<<"\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout<<"\t\t+\tWhat are you looking for? Let us  help you     +"<<endl;
		cout<<"\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout<<right<<setw(15)<<"\t\t+\t1. Search by Bus Id (ID recommended if you     +"<<endl;
		cout<<right<<setw(15)<<"\t\t+\t   are looking for specific bus)\t       +"<<endl;
		cout<<right<<setw(15)<<"\t\t+\t2. Search by Source               \t       +"<<endl;
		cout<<right<<setw(15)<<"\t\t+\t3. Search by Destination       \t\t       +"<<endl;
		cout<<right<<setw(15)<<"\t\t+\t4. Search by Driver's name     \t\t       +"<<endl;
		cout<<"\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		
		cout<<"\t\tEnter your choice  ";
		cin>>yourChoice;
		
		switch(yourChoice)
		{
			case 1:
				searchingId();
				break;
			case 2:
				searchingsource();
				break;
			case 3:
				searchingDest();
				break;
			case 4: 
				searchingDriver();
				break;
			default:
				searching();
		}
}
void searchingId()
{
		int  noSeat;
	float distancet;//distance on the txtfile
	string dName,busIdt, sourcet, destinationt,arrivet,depatt,busId;
	int count = 1;//counts the number of buses
	
	//searching using id
	cout<<"\t\t\tEnter the bus Id number you want to search: ";
	cin>>busId;
	
	system("cls");
	cout<<endl<<left<<setw(12)<<"No"<<left<<setw(12)<<"Id_Num"<<left<<setw(12)<<"Seat"<<left<<setw(12)<<"Driver"<<left<<setw(12)<<"arrival.t"<<left<<setw(12)<<"depart.t"<<left<<setw(12)<<"source"<<left<<setw(12)<<"desti."<<left<<setw(12)<<"distance"<<endl;
 	fstream myFile;
	myFile.open("bus.txt", ios::in);
	
	
	
	while(myFile>>busIdt>>noSeat>>dName>>arrivet>>depatt>>sourcet>>destinationt>>distancet)
	{
		if((strcmp(busIdt.c_str(), busId.c_str()))==0)	
		{
			cout<<left<<setw(12)<<count<<left<<setw(12)<<busIdt<<left<<setw(12)<<noSeat<<left<<setw(12)<<dName<<left<<setw(12)<<arrivet<<left<<setw(12)<<depatt<<left<<setw(12)<<sourcet<<left<<setw(12)<<destinationt<<left<<setw(12)<<distancet<<endl;
			count++;
		}
	}
	cout<<"\n\n\n";
	myFile.close();
	
	if(count==1)
	{
		cout<<"\t\t\t\nNo match has founded.\n";
		system("pause");
		searching();
	
		
	}
	
	statsAd();
}
void searchingsource()
{
		int  noSeat;
	float distancet;//distance on the txtfile
	string dName,busIdt, sourcet, destinationt,arrivet,depatt,sourcee;
	int count = 1;//counts the number of buses
	
	//searching using id
	cout<<"\t\t\tEnter the source of the bus you want to search: ";
	cin>>sourcee;
	
	system("cls");
	cout<<endl<<left<<setw(12)<<"No"<<left<<setw(12)<<"Id_Num"<<left<<setw(12)<<"Seat"<<left<<setw(12)<<"Driver"<<left<<setw(12)<<"arrival.t"<<left<<setw(12)<<"depart.t"<<left<<setw(12)<<"source"<<left<<setw(12)<<"desti."<<left<<setw(12)<<"distance"<<endl;
 	fstream myFile;
	myFile.open("bus.txt", ios::in);
	
	
	
	while(myFile>>busIdt>>noSeat>>dName>>arrivet>>depatt>>sourcet>>destinationt>>distancet)
	{
		if((strcmp(sourcee.c_str(), sourcet.c_str()))==0)	
		{
			cout<<left<<setw(12)<<count<<left<<setw(12)<<busIdt<<left<<setw(12)<<noSeat<<left<<setw(12)<<dName<<left<<setw(12)<<arrivet<<left<<setw(12)<<depatt<<left<<setw(12)<<sourcet<<left<<setw(12)<<destinationt<<left<<setw(12)<<distancet<<endl;
			count++;
		}
	}
	cout<<"\n\n\n";
	myFile.close();
	
		if(count==1)
	{
		cout<<"\t\t\t\nNo match has founded.\n";
		system("pause");
		searching();
	
		
	}
	
	statsAd();
}
void searchingDest()
{
		int  noSeat;
	float distancet;//distance on the txtfile
	string dName,busIdt, sourcet, destinationt,arrivet,depatt,dest;
	int count = 1;//counts the number of buses
	
	//searching using id
	cout<<"\t\t\tEnter the Destination of the bus you want to search: ";
	cin>>dest;
	
	system("cls");
	cout<<endl<<left<<setw(12)<<"No"<<left<<setw(12)<<"Id_Num"<<left<<setw(12)<<"Seat"<<left<<setw(12)<<"Driver"<<left<<setw(12)<<"arrival.t"<<left<<setw(12)<<"depart.t"<<left<<setw(12)<<"source"<<left<<setw(12)<<"desti."<<left<<setw(12)<<"distance"<<endl;
 	fstream myFile;
	myFile.open("bus.txt", ios::in);
	
	
	
	while(myFile>>busIdt>>noSeat>>dName>>arrivet>>depatt>>sourcet>>destinationt>>distancet)
	{
		if((strcmp(destinationt.c_str(), dest.c_str()))==0)	
		{
			cout<<left<<setw(12)<<count<<left<<setw(12)<<busIdt<<left<<setw(12)<<noSeat<<left<<setw(12)<<dName<<left<<setw(12)<<arrivet<<left<<setw(12)<<depatt<<left<<setw(12)<<sourcet<<left<<setw(12)<<destinationt<<left<<setw(12)<<distancet<<endl;
			count++;
		}
	}
	cout<<"\n\n\n";
	myFile.close();
	
		if(count==1)
	{
		cout<<"\t\t\t\nNo match has founded.\n";
		system("pause");
		searching();
	
		
	}
	
	statsAd();
}
void searchingDriver()
{
	int  noSeat;
	float distancet;//distance on the txtfile
	string dName,busIdt, sourcet, destinationt,arrivet,depatt,driver;
	int count = 1;//counts the number of buses
	
	//searching using id
	cout<<"\t\t\tEnter the drivers name you want to search: ";
	cin>>driver;
	
	system("cls");
	cout<<endl<<left<<setw(12)<<"No"<<left<<setw(12)<<"Id_Num"<<left<<setw(12)<<"Seat"<<left<<setw(12)<<"Driver"<<left<<setw(12)<<"arrival.t"<<left<<setw(12)<<"depart.t"<<left<<setw(12)<<"source"<<left<<setw(12)<<"desti."<<left<<setw(12)<<"distance"<<endl;
 	fstream myFile;
	myFile.open("bus.txt", ios::in);
	
	
	
	while(myFile>>busIdt>>noSeat>>dName>>arrivet>>depatt>>sourcet>>destinationt>>distancet)
	{
		if((strcmp(dName.c_str(), driver.c_str()))==0)	
		{
			cout<<left<<setw(12)<<count<<left<<setw(12)<<busIdt<<left<<setw(12)<<noSeat<<left<<setw(12)<<dName<<left<<setw(12)<<arrivet<<left<<setw(12)<<depatt<<left<<setw(12)<<sourcet<<left<<setw(12)<<destinationt<<left<<setw(12)<<distancet<<endl;
			count++;
		}
	}
	cout<<"\n\n\n";
	myFile.close();
	
		if(count==1)
	{
		cout<<"\t\t\t\nNo match has founded.\n";
		system("pause");
		searching();
	
		
	}
	
	statsAd();
}

void deleting()
{
	int  noSeat;
	float distancet;//distance on the txtfile
	string busId, busIdt, dName, sourcet, destinationt,arrivet, departt;
	
	
	cout<<"\t\t\tEnter the bus Id number you want to delete: ";
	cin>>busId;
	
	
	ifstream myFile;//to read bus file
	myFile.open("bus.txt");
	
	ofstream temp;//temporary file which the file will be copied
	temp.open("temp.txt");
	
	while(myFile>>busIdt>>noSeat>>dName>>arrivet>>departt>>sourcet>>destinationt>>distancet)
	{
		
		int result  = strcmp(busIdt.c_str(), busId.c_str());//c_str it is because strcmp take const char* as an argument
		if(result!=0)
		{
			temp<<busIdt<<" "<<noSeat<<" "<<dName<<" "<<arrivet<<" "<<departt<<" "<<sourcet<<" "<<destinationt<<" "<<distancet<<endl;
		}
		
		//enter the updated info
		else
		{
			cout<<"\n\t\t\tYou succesfully deleted  bus "<<busId<<" from the system."<<endl;	
		}		
	}
	myFile.close();
	temp.close();
	
	remove("bus.txt");
	rename("temp.txt","bus.txt");
	
	statsAd();
}




//works fine to this point
void books()
{
	string source, destination, dtime;//dtime is departure time
	int sono, desno, tno;//sono source no, destination no, tno time no
	
	
	
	//
	
	system("cls");
	cout<<"\t\t\t\tWhere do you want to go?\t\t\t\t"<<endl;
	cout<<"\t\t\t.................................\t\t\t"<<endl;
	cout<<"\t\t\t1.\tAddis Ababa\t"<<endl;
	cout<<"\t\t\t2.\tAdama\t"<<endl;
	cout<<"\t\t\t3.\tBahir dar\t"<<endl;
	cout<<"\t\t\t4.\tGondar\t"<<endl;
	cout<<"\t\t\t5.\tHawassa\t"<<endl;
	cout<<"\t\t\t6.\tJimma\t"<<endl;
	cout<<"\t\t\t7.\tMekelle\t"<<endl;
	cout<<"\t\t\t8.\tSemera\t"<<endl;
	
	
	
	cout<<"\t\tEnter Your source and destination respectiverly: \n";
	cout<<"\t\t\tEnter your source: ";
	cin>>sono;
	cout<<endl<<"\t\t\tEnter your destination: ";
	cin>>desno;
	cout<<"\n\n\t\t\t Enter your departuen time\n";
	cout<<"\t\t\t1.\t11:00am\t"<<endl;
	cout<<"\t\t\t2.\t11:00pm\t"<<endl;
	cout<<"\n\t\t\tPlease choose one which suites you: ";
	cin>>tno;
	
	
	if(sono == desno)
	{
		system("cls");
		books();
	}
	
	//sono and source . desno for destination and tno for depart time
	//case one sono
	if(sono>0 and sono<9) source= cities[sono-1];
	else books();
	if(desno>0 and sono<9) destination= cities[desno-1];
	else books(); 
	if(tno>0 && tno<3) dtime = gize[tno-1];
	else books();

	
	int  noSeat;
	float distancet;//distance on the txtfile
	string busIdt, dName, sourcet, destinationt, arrivet, departt;
	
	fstream myBus;
	myBus.open("bus.txt",ios::in);
	fstream myBook;
	myBook.open("book.txt",ios::app);
	
	
	while(myBus>>busIdt>>noSeat>>dName>>arrivet>>departt>>sourcet>>destinationt>>distancet)
		{
			if(((strcmp(sourcet.c_str(),source.c_str()))==0) && ((strcmp(destinationt.c_str(), destination.c_str()))==0) && ((strcmp(departt.c_str(),dtime.c_str()))==0))
			{
				char cont;//ask the customer if they want to proceed 
				cout<<"\t\t"<<sourcet<<"-------------"<<destination<<"\n"<<endl;
				cout<<endl<<"\t\t"<<"busIdt"<<setw(15)<<"driver"<<setw(15)<<"arri_time"<<setw(15)<<"depart_time";
				cout<<endl<<"\t\t"<<busIdt<<setw(16)<<dName<<setw(16)<<arrivet<<setw(16)<<departt<<"\t\n"<<endl;
				
				cout<<"\t\tDo you want to continue booking?(Y/y or N/n): ";
				cin>>cont;
				
					if(cont=='Y'|| cont=='y')
					{
							system("cls");
							
									
						int nobook,rowSeat, colSeat;
						char col;
						
						cout<<endl<<"\tEnter How many seats you want to book:  ";
						cin>>nobook;
						
						int no_reserved= 0;
						
						while(no_reserved<nobook)
						{
							
							cout<<"\t\t\t"<<no_reserved+1<<" reservation";
							cout<<endl<<"\t\t\tEnter which seat you want to book the row and the column respectively: "<<endl;
							cout<<"\t\t\tEnter the row you want to seat(1-9): ";
							cin>>rowSeat;
							cout<<"\n\t\t\tEnter a column(A,B,C,D): ";
							cin>>col;
							
							//convert the char to integer
							if(col=='a'|| col=='A')
							
								colSeat = 0;
							else if(col=='b'|| col=='B')
								colSeat = 1;
							else if(col=='c'|| col=='C')
								colSeat = 2;
							else if(col=='d'|| col=='D')
								colSeat = 3;
							else if(rowSeat<1 || rowSeat>9) books();
							else
							{
							cout<<"\n\nplease Enter the column correctly.";
							books();
							}
							//	registering the customer
								
							if(array_doc[rowSeat-1][colSeat] == 0)
							{
								array_doc[rowSeat-1][colSeat] = 1;
								
								cout<<endl<<"\t\t\t\tETHIO standard Bus\n";
								cout<<"\t\t\t===============================\n";
										
											
								cout<<"\t\t\t\t"<<left<<setw(5)<<"A"<<left<<setw(5)<<"B"<<left<<setw(5)<<"C"<<left<<setw(5)<<"D"<<endl;
																
								for(int i=0;i<9;i++)
								{
									cout<<"\t\t\t\t";
									for(int j= 0;j<4;j++)
									{
										cout<<left<<setw(5)<<array_doc[i][j];
									}
									cout<<"\t"<<endl;
								}
	
										no_reserved++;
										system("pause");
 
 										system("cls");
							}
							
							else
								system("cls");
							
						}
						
								system("cls");
								cout<<endl<<"\t\tEnter Your first Name: ";
								cin>>book.fName;
								cout<<"\n\t\tEnter Your last name: ";
								cin>>book.lName;
								book.noSeat = nobook;
								float payement = distancet * rate *nobook;
								int confirmation = rand() % 9000 + 1000;
							
								
							myBook<<confirmation<<" "<<book.fName<<" "<<book.lName<<" "<<book.noSeat<<" "<<departt<<" "<<sourcet<<" "<<" "<<destinationt<<" "<<payement<<endl;	
							cout<<left<<setw(10)<<"\t\t\tYou have succesfully reserved seats on Ethio Bus\n\n\n";
							system("pause");
							
							
							//online payement
							int choice;
							cout<<endl<<"\t\tYour confirmation number is "<<confirmation;
							cout<<endl<<"\t\tDo you want to pay online?";
							cout<<endl<<"\t\t\t1.	Yes";
							cout<<endl<<"\t\t\t2.	No";
							cout<<endl<<setw(15)<<"Enter your choice: ";
							cin>>choice;
							
							if(choice==1) ticket();
							else if(choice==2) statsAd();
							else main();
					}
					
					 statsAd();
				}
				
				
			}
			
		
		myBus.close();
		myBook.close();

}

	
	
void ticket()
{
	
	string fName, lName, departt, source, destin, firstName;
	int confirm, confirmt;
	float payement, change;
	int noSeat;
	
	cout<<endl<<"\t\t\tEnter your confirmation number: ";
	cin>>confirm;
	
	fstream myBook;
	myBook.open("book.txt",ios::in);
	
	
	while(myBook>>confirmt>>fName>>lName>>noSeat>>departt>>source>>destin>>payement)
	{	
	
		if(confirmt == confirm)
		{
			float birr;
			
			do{
			
			cout<<endl<<"\t\tyour total is"<<payement;
			cout<<endl<<"\t\tEnter the amount requested: ";
			cin>>birr;
			}while(birr<payement);
		
		
		system("cls");
		cout<<endl<<"\t\t\tEthio Bus ticket\n";
		cout<<endl<<"\n\n\t\t\tFirst Name\t\t\t\t"<<fName;
		cout<<endl<<"\t\t\tLast Name\t\t\t\t"<<lName;
		cout<<endl<<"\t\t\tNumber of Seat\t\t\t\t"<<noSeat;
		cout<<endl<<"\t\t\tSource\t\t\t\t\t"<<source;
		cout<<endl<<"\t\t\tDestination\t\t\t\t"<<destin;
		cout<<endl<<"\t\t\tDeparture Time\t\t\t\t"<<departt;
		cout<<endl<<"\t\t\tSingle ticket price\t\t\t"<<(payement/noSeat);
		cout<<endl<<"\t\t\tChange\t\t\t\t\t"<<(birr - payement);
		cout<<endl<<"\t\t\tTotal\t\t\t\t\t"<<payement;
		cout<<endl<<"\t\t\t\t\t\tThank you!"<<endl;
		
		}
	}
	statsAd();
}

void delete_book()
{
	string  fName, lName, departt, source, destin, firstName;
	float payement;
	int noSeat, conf;
	
	cout<<endl<<"\t\t\tEnter your first name: ";
	cin>>firstName;
	
	
	
	ifstream myFile;//to read bus file
	myFile.open("book.txt");
	
	ofstream temp;//temporary file which the file will be copied
	temp.open("temp.txt");
	
	while(myFile>>conf>>fName>>lName>>noSeat>>departt>>source>>destin>>payement)
	{
		if((strcmp(fName.c_str(),firstName.c_str()))!=0)
		{
			temp<<fName<<" "<<lName<<" "<<noSeat<<" "<<departt<<" "<<" "<<source<<" "<<destin<<" "<<payement<<endl;		
		}
		
		//enter the updated info
		else
		{
			cout<<endl<<"\n\t\t\tYou succesfully deleted"<<fName<<" from the booking file."<<endl;	
		}		
	}
	myFile.close();
	temp.close();
	
	remove("book.txt");
	rename("temp.txt","book.txt");
	
	statsAd();	
}

void bookEs()
{
	string source, destination, dtime;//dtime is departure time
	int sono, desno, tno;//sono source no, destination no, tno time no
	
	
	
	//
	
	system("cls");
	cout<<"\t\t\t\tWhere do you want to go?\t\t\t\t"<<endl;
	cout<<"\t\t\t.................................\t\t\t"<<endl;
	cout<<"\t\t\t1.\tAddis Ababa\t"<<endl;
	cout<<"\t\t\t2.\tAdama\t"<<endl;
	cout<<"\t\t\t3.\tBahir dar\t"<<endl;
	cout<<"\t\t\t4.\tGondar\t"<<endl;
	cout<<"\t\t\t5.\tHawassa\t"<<endl;
	cout<<"\t\t\t6.\tJimma\t"<<endl;
	cout<<"\t\t\t7.\tMekelle\t"<<endl;
	cout<<"\t\t\t8.\tSemera\t"<<endl;
	
	
	
	cout<<"\t\tEnter Your source and destination respectiverly: \n";
	cout<<"\t\t\tEnter your source: ";
	cin>>sono;
	cout<<endl<<"\t\t\tEnter your destination: ";
	cin>>desno;
	cout<<"\n\n\t\t\t Enter your departuen time\n";
	cout<<"\t\t\t1.\t11:00am\t"<<endl;
	cout<<"\t\t\t2.\t11:00pm\t"<<endl;
	cout<<"\n\t\t\tPlease choose one which suites you: ";
	cin>>tno;
	
	
	if(sono == desno)
	{
		system("cls");
		bookEs();
	}
	
	//sono and source . desno for destination and tno for depart time
	//case one sono
	if(sono>0 and sono<9) source= cities[sono-1];
	else books();
	if(desno>0 and sono<9) destination= cities[desno-1];
	else books(); 
	if(tno>0 && tno<3) dtime = gize[tno-1];
	else bookEs();

	
	int  noSeat;
	float distancet;//distance on the txtfile
	string busIdt, dName, sourcet, destinationt, arrivet, departt;
	
	fstream myBus;
	myBus.open("bus.txt",ios::in);
	fstream myBook;
	myBook.open("book.txt",ios::app);
	
	
	while(myBus>>busIdt>>noSeat>>dName>>arrivet>>departt>>sourcet>>destinationt>>distancet)
		{
			if(((strcmp(sourcet.c_str(),source.c_str()))==0) && ((strcmp(destinationt.c_str(), destination.c_str()))==0) && ((strcmp(departt.c_str(),dtime.c_str()))==0))
			{
				char cont;//ask the customer if they want to proceed 
				cout<<"\t\t"<<sourcet<<"-------------"<<destination<<"\n"<<endl;
				cout<<endl<<"\t\t"<<"busIdt"<<setw(15)<<"driver"<<setw(15)<<"arri_time"<<setw(15)<<"depart_time";
				cout<<endl<<"\t\t"<<busIdt<<setw(16)<<dName<<setw(16)<<arrivet<<setw(16)<<departt<<"\t\n"<<endl;
				
				cout<<"\t\tDo you want to continue booking?(Y/y or N/n): ";
				cin>>cont;
				
					if(cont=='Y'|| cont=='y')
					{
							system("cls");
							
									
						int nobook,rowSeat, colSeat;
						char col;
						
						cout<<endl<<"\tEnter How many seats you want to book:  ";
						cin>>nobook;
						
						int no_reserved= 0;
						
						while(no_reserved<nobook)
						{
							
							cout<<"\t\t\t"<<no_reserved+1<<" reservation";
							cout<<endl<<"\t\t\tEnter which seat you want to book the row and the column respectively: "<<endl;
							cout<<"\t\t\tEnter the row you want to seat(1-9): ";
							cin>>rowSeat;
							cout<<"\n\t\t\tEnter a column(A,B,C,D): ";
							cin>>col;
							
							//convert the char to integer
							if(col=='a'|| col=='A')
							
								colSeat = 0;
							else if(col=='b'|| col=='B')
								colSeat = 1;
							else if(col=='c'|| col=='C')
								colSeat = 2;
							else if(col=='d'|| col=='D')
								colSeat = 3;
							else if(rowSeat<1 || rowSeat>9) books();
							else
							{
							cout<<"\n\nplease Enter the column correctly.";
							bookEs();
							}
							//	registering the customer
								
							if(array_doc[rowSeat-1][colSeat] == 0)
							{
								array_doc[rowSeat-1][colSeat] = 1;
								
								cout<<endl<<"\t\t\t\tETHIO standard Bus\n";
								cout<<"\t\t\t===============================\n";
										
											
								cout<<"\t\t\t\t"<<left<<setw(5)<<"A"<<left<<setw(5)<<"B"<<left<<setw(5)<<"C"<<left<<setw(5)<<"D"<<endl;
																
								for(int i=0;i<9;i++)
								{
									cout<<"\t\t\t\t";
									for(int j= 0;j<4;j++)
									{
										cout<<left<<setw(5)<<array_doc[i][j];
									}
									cout<<"\t"<<endl;
								}
	
										no_reserved++;
										system("pause");
 
 										system("cls");
							}
							
							else
								system("cls");
							
						}
						
								system("cls");
								cout<<endl<<"\t\tEnter Your first Name: ";
								cin>>book.fName;
								cout<<"\n\t\tEnter Your last name: ";
								cin>>book.lName;
								book.noSeat = nobook;
								float payement = distancet * rate *nobook;
								int confirmation = rand() % 9000 + 1000;
							
								
							myBook<<confirmation<<" "<<book.fName<<" "<<book.lName<<" "<<book.noSeat<<" "<<departt<<" "<<sourcet<<" "<<" "<<destinationt<<" "<<payement<<endl;	
							cout<<left<<setw(10)<<"\t\t\tYou have succesfully reserved seats on Ethio Bus\n\n\n";
							system("pause");
							
							
							//online payement
							int choice;
							cout<<endl<<"\t\tYour confirmation number is "<<confirmation;
							cout<<endl<<"\t\tDo you want to pay online?";
							cout<<endl<<"\t\t\t1.	Yes";
							cout<<endl<<"\t\t\t2.	No";
							cout<<endl<<setw(15)<<"Enter your choice: ";
							cin>>choice;
							
							if(choice==1) ticket();
							else if(choice==2)  statEm();
							else main();
					}
					
					 statEm();
				}
				
				
			}
			
		
		myBus.close();
		myBook.close();

}


void viewEBus()
{
	int  noSeat;
	float distancet;//distance on the txtfile
	string dName,busIdt, sourcet, destinationt,arrivet,depatt;
	int count = 1;//counts the number of buses
	system("cls");
	cout<<endl<<left<<setw(12)<<"No"<<left<<setw(12)<<"Id_Num"<<left<<setw(12)<<"Seat"<<left<<setw(12)<<"Driver"<<left<<setw(12)<<"arrival.t"<<left<<setw(12)<<"depart.t"<<left<<setw(12)<<"source"<<left<<setw(12)<<"desti."<<left<<setw(12)<<"distance\n"<<endl;
 	fstream myFile;
	myFile.open("bus.txt", ios::in);
	
	
	
	while(myFile>>busIdt>>noSeat>>dName>>arrivet>>depatt>>sourcet>>destinationt>>distancet)
	{
		cout<<left<<setw(12)<<count<<left<<setw(12)<<busIdt<<left<<setw(12)<<noSeat<<left<<setw(12)<<dName<<left<<setw(12)<<arrivet<<left<<setw(12)<<depatt<<left<<setw(12)<<sourcet<<left<<setw(12)<<destinationt<<left<<setw(12)<<distancet<<endl;
		count++;
	}
	cout<<"\n\n\n";
	myFile.close();
	
	statEm();
	
	
}	
void cancel2()
{
	system("cls");
	main();
}

void Sortings::read()
{
			//variables from the file
			int  noSeat;
			float distancet;
			string dName,busIdt, sourcet, destinationt,arrivet,depatt;
			
			fstream myfile;
			myfile.open("bus.txt", ios::in);
			
					
			while(myfile>>busIdt>>noSeat>>dName>>arrivet>>depatt>>sourcet>>destinationt>>distancet)
			{
			
				obj[siz].busIdc = busIdt;
				obj[siz].noSeac = noSeat;
				obj[siz].dNamec = dName;
				obj[siz].arrivec = arrivet;
				obj[siz].departc = depatt;
				obj[siz].sourcec = sourcet;
				obj[siz].destinationc = destinationt;
				obj[siz].distancec = distancet;
				
					siz++;
			}
			
				myfile.close();
				
	
} 
void Sortings::sortID()
{
	
	Sortings tmp;
	
	      for(int i=0; i<siz-1; i++)
        {
                for(int j=i+1; j<siz; j++)
                {
                		
						string str2;
						string str1;
	
                	 str1 = obj[i].busIdc;
                	 str2 = obj[j].busIdc;
                	
                
					
					
					
				
                
                	
                        if(strcmp(str1.c_str(), str2.c_str())>0)
                        {
                                tmp= obj[i];
                                obj[i]= obj[j];
                                obj[j]= tmp;
                        }
                    
                }
        }
        
 		int no=1;
    cout<<siz<<endl;
    for (int a=0;a<siz;a++)
	{
		
		cout<<endl<<left<<setw(12)<<no<<left<<setw(12)<<obj[a].busIdc<<left<<setw(12)<<obj[a].noSeac<<left<<setw(12)<<obj[a].dNamec<<left<<setw(12)<<obj[a].arrivec<<left<<setw(12)<<obj[a].departc<<left<<setw(12)<<obj[a].sourcec<<left<<setw(12)<<obj[a].destinationc<<left<<setw(12)<<obj[a].distancec<<endl;	
		no++;
	}
	
	system("pause");
	system("cls");
	main();
}

void Sortings::sortSource()
{
	
	Sortings tmp;
	
	      for(int i=0; i<siz-1; i++)
        {
                for(int j=i+1; j<siz; j++)
                {
                		
						string str2;
						string str1;
	
                	 str1 = obj[i].sourcec;
                	 str2 = obj[j].sourcec;
                	
                
					
					
					
				
                
                	
                        if(strcmp(str1.c_str(), str2.c_str())>0)
                        {
                                tmp= obj[i];
                                obj[i]= obj[j];
                                obj[j]= tmp;
                        }
                    
                }
        }
        
 		int no=1;
    cout<<siz<<endl;
    for (int a=0;a<siz;a++)
	{
		
		cout<<endl<<left<<setw(12)<<no<<left<<setw(12)<<obj[a].busIdc<<left<<setw(12)<<obj[a].noSeac<<left<<setw(12)<<obj[a].dNamec<<left<<setw(12)<<obj[a].arrivec<<left<<setw(12)<<obj[a].departc<<left<<setw(12)<<obj[a].sourcec<<left<<setw(12)<<obj[a].destinationc<<left<<setw(12)<<obj[a].distancec<<endl;	
		no++;
	}
	
	system("pause");
	system("cls");
	main();
}
void Sortings::sortDest()
{
	
	Sortings tmp;
	
	      for(int i=0; i<siz-1; i++)
        {
                for(int j=i+1; j<siz; j++)
                {
                		
						string str2;
						string str1;
	
                	 str1 = obj[i].destinationc;
                	 str2 = obj[j].destinationc;
                	
                
					
					
					
				
                
                	
                        if(strcmp(str1.c_str(), str2.c_str())>0)
                        {
                                tmp= obj[i];
                                obj[i]= obj[j];
                                obj[j]= tmp;
                        }
                    
                }
        }
        
 		int no=1;
    cout<<siz<<endl;
    for (int a=0;a<siz;a++)
	{
		
		cout<<endl<<left<<setw(12)<<no<<left<<setw(12)<<obj[a].busIdc<<left<<setw(12)<<obj[a].noSeac<<left<<setw(12)<<obj[a].dNamec<<left<<setw(12)<<obj[a].arrivec<<left<<setw(12)<<obj[a].departc<<left<<setw(12)<<obj[a].sourcec<<left<<setw(12)<<obj[a].destinationc<<left<<setw(12)<<obj[a].distancec<<endl;	
		no++;
	}
	
	system("pause");
	system("cls");
	main();
}
	
void display()
{
	obj[siz].read();
	char ans;//user choice
	int user;
	system("pause");
	cout<<"\t\t\tDo you want to sort?(y/n) ";
	cin>>ans;
	
	if(ans=='Y'|| ans=='y')
		{
			system("cls");
			cout<<"\n\t\t\tWhich column Do you want to sort?\n";
			cout<<"\t\t\t1.\t Sort by ID";
			cout<<"\n\t\t\t2.\t Sort by Source";
			cout<<"\n\t\t\t3.\t Sort by Destination";
			cout<<"\n\t\t\t\tEnter your choice: ";
			cin>> user;
			
			switch(user)
			{
				case 1:
					obj[siz].sortID();
					break;
				case 2:
					obj[siz].sortSource();
					break;
				case 3:
					obj[siz].sortDest();
					break;
				default:
					viewBus();
			}
			
			
		}
	else
		main();
	
	
}

