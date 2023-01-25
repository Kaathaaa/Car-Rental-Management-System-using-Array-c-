#include <iostream>
#include <conio.h>//for getch
#include <limits>// for checking invalid input
#include <windows.h>//for password 
#include <fstream>

using namespace std;


int i = 0;
int count;
string admin, pass;

string getpass(const char *prompt,bool show_asterisk = true) //to hide the password
{ 
	const char BACKSPACE = 8;
	const char RETURN = 13;
	string password;
	unsigned char ch = 0;
	cout << prompt;
	DWORD con_mode;
	DWORD dwRead;
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hIn, &con_mode);
	SetConsoleMode(hIn,con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
	
	while (ReadConsoleA(hIn, &ch, 1, &dwRead, NULL) && ch != RETURN){
		if (ch == BACKSPACE){
			if (password.length() != 0){
				if (show_asterisk)
					cout << "\b \b";
				password.resize(password.length() - 1);
				
			}
		} else{
			password += ch;
			if (show_asterisk)
				cout << '*';		
		}
	}
	cout << endl;
	return password;
}
class car_var //class to declare the variables and array
{ 
	public:
		int car_id,quantity;
		float price;
		string brand,model,color;
		car_var(){ 
			car_id = 0;
			brand = "";
			model = "";
			color = "";
			price = 0;
			quantity = 0;
		}
}c[50];

void add();		void update();		void del();		void show(); 	void searchadmin();
void buy();		void login();		void adminmenu();				void customermenu();
void art();		

void art() {
	
	
	fstream myFile;
	myFile.open("art.txt",ios::in);
	if(myFile.is_open()){
		string line;
		while (getline(myFile,line)){
			cout << line << endl;
		}myFile.close();
	}
	
	
}
	
	
	void login() //login
	{
		system("cls");
		int identity;
		
		do{
			
		identitytype:
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t   +--------------------------------+" << endl;
		cout << "\t\t\t\t\t   |            LOGIN OPTION        |" << endl;
		cout << "\t\t\t\t\t   +--------------------------------+" << endl;
		cout << "\t\t\t\t\t   |                                |" << endl;
		cout << "\t\t\t\t\t   |       [1] Administrator        |" << endl;
		cout << "\t\t\t\t\t   |       [2] Customer             |" << endl;
		cout << "\t\t\t\t\t   |       [3] Exit                 |" << endl;
		cout << "\t\t\t\t\t   |                                |" << endl;
		cout << "\t\t\t\t\t   +--------------------------------+" << endl;
		cout << "\t\t\t\t\t    Select Option: ";
		cin >> identity;
			
			while(1){
			if(cin.fail()){
			cin.clear();
			cin.ignore(80,'\n');
			cout <<" Wrong data type/value. Enter a number: ";
			cin >> identity;
			}
			if(!cin.fail())
			break;
			}
				switch (identity){
					case 1: //admin view
						system ("cls");
						int choice1;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
							
							cin >> choice1;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<" Wrong data type/value. Enter a number: ";
								cin >> choice1;
								}
								if(!cin.fail())
								break;
								}
									switch(choice1){
										case 1:
											char yn1;
											q:
											system("cls");
						cout << "\n\n\n\n\n\n";
						cout << "\t\t\t\t\t   +-------------------------------+" << endl;
						cout << "\t\t\t\t\t   |              LOGIN            |" << endl;
						cout << "\t\t\t\t\t   +-------------------------------+" << endl;
						cout << "\n";
											cout << "\t\t\t\t\t    Username: ";
											cin >> admin;
											pass = getpass("\t\t\t\t\t    Password: ", true);
											
											if ((admin == "Khar" || admin == "KHAR" || admin == "khar" || admin == "group4" ) && (pass == "powerpuff" || pass == "POWERPUFF" || pass == "group4" || pass == "POWERPUFF")) {
												cout << "\n";
												cout << "\t\t\t\t\t   +-------------------------------+" << endl; 
												cout << endl <<"\t\t\t\t\t    ACCESS GRANTED!" << endl;
												system("pause");
												adminmenu();
											} else {
												cout << endl <<"\t\t\t\t\t    ACCESS DENIED!" <<endl;
											}
											do{
												cout << "\t\t\t\t\t    Do you want to retry? (y/n): "; cin >> yn1;
													if (yn1 == 'Y' || yn1 == 'y'){
														goto q;
													} else if (yn1 == 'N' || yn1 == 'n'){
														system("cls");
														goto identitytype;
													} else{
														system("cls");
														goto identitytype;
													}
											} while ((yn1 != 'Y'|| yn1 != 'y') && (yn1 != 'N'|| yn1 != 'n'));
										break;
										case 2:
											system("cls");
											goto identitytype;
										break;
										default:
										cout << "\t\t\t\t\t    Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice1 != 1 && choice1 != 2); 
					case 2: // user login
						system ("cls");
						int choice2;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
							
							cin >> choice2;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice2;
								}
								if(!cin.fail())
								break;
								}
									switch(choice2){
										case 1:
											system("cls");
											customermenu();
										break;
										case 2:
											system("cls");
											goto identitytype;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");
										break;
									}
							} while (choice2 != 1 && choice2 != 2); 
					case 3: // terminate program
						system("cls");
						int choice3;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO QUIT?            |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
						
						
						
						cin >> choice3;
						
							while(1){
							if(cin.fail()){
							cin.clear();
							cin.ignore(80,'\n');
							cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
							cin >> choice3;
							}
							if(!cin.fail())
							break;
							}
								switch(choice3){
									case 1:
										//welcome();
										exit(0);
									break;
									case 2:
										system("cls");
										goto identitytype;
									break;
									default:
									cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
									system("pause");
									system("cls");
									break;	
								}
						} while (choice3 != 1 && choice3 != 2); // end of terminate program
					default:
						cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
						system("pause");
						system("cls");	
				}
		} while (identity != 3); 
	}

	void  adminmenu() //admin menu
	{ 
		system("cls");
		int adminmenuchoice;
		
		do{
		
		adminmenu:	
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t   +-----------------------------------------------+" << endl;
		cout << "\t\t\t\t   |                      ADMIN                    |" << endl;
		cout << "\t\t\t\t   +-----------------------------------------------+" << endl;
		cout << "\t\t\t\t   |                                               |" << endl;
		cout << "\t\t\t\t   |     [1] ADD CAR          [4] DELETE CAR       |" << endl;
		cout << "\t\t\t\t   |     [2] SEARCH CAR       [5] SHOW ALL CARS    |" << endl;
		cout << "\t\t\t\t   |     [3] REVISE CAR DETAILS                    |" << endl;
		cout << "\t\t\t\t   |                                               |" << endl;
		cout << "\t\t\t\t   +-----------------------------------------------+" << endl;
		cout << "\t\t\t\t   |                           [6] BACK   [0] EXIT |" << endl;
		cout << "\t\t\t\t   +-----------------------------------------------+" << endl;	
		cout << "\t\t\t\t    Select Option: "; 
		
		
		
		cin >> adminmenuchoice;
			
			while(1){
			if(cin.fail()){
			cin.clear();
			cin.ignore(80,'\n');
			cout <<" Wrong data type/value. Enter a number: ";
			cin >> adminmenuchoice;
			}
			if(!cin.fail())
			break;
			}
				switch (adminmenuchoice){
					case 1: // add book
						system ("cls");
						int choice4;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
							
							cin >> choice4;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice4;
								}
								if(!cin.fail())
								break;
								}
									switch(choice4){
										case 1: // add car
											system("cls");
											char yn1;
											add();
											do{
												cout << endl << endl << "\t\t\t\t     Do you want to add another car? (y/n): "; cin >> yn1;
													if (yn1 == 'Y' || yn1 == 'y'){
														add();
													} else if (yn1 == 'N' || yn1 == 'n'){
														system("cls");
														goto adminmenu;
													} else{
														system("cls");
														goto adminmenu;
													}
											} while ((yn1 != 'Y'|| yn1 != 'y') && (yn1 != 'N'|| yn1 != 'n'));
										break;
										case 2:
											system("cls");
											goto adminmenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice4 != 1 && choice4 != 2); 
					break;
					case 2: // search car
						system ("cls");
						int choice5;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
							
							cin >> choice5;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice5;
								}
								if(!cin.fail())
								break;
								}
									switch(choice5){
										case 1:
											system("cls");
											char yn2;
											searchadmin();
											if (i == 0){
												system("pause");
												system("cls");
											}
											else {
												do{
													cout << endl << endl << "\t\t\t\t     Do you want to check another car? (y/n): "; cin >> yn2;
														if (yn2 == 'Y' || yn2 == 'y'){
															searchadmin();
														} else if (yn2 == 'N' || yn2 == 'n'){
															system("cls");
															goto adminmenu;
														} else{
															system("cls");
															goto adminmenu;
														}
												} while ((yn2 != 'Y'|| yn2 != 'y') && (yn2 != 'N'|| yn2 != 'n'));	
											}
										break;
										case 2:
											system("cls");
											goto adminmenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice5 != 1 && choice5 != 2); 
					break;
					case 3: // update car
						system ("cls");
						int choice6;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: "; 
							
							
							cin >> choice6;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice6;
								}
								if(!cin.fail())
								break;
								}
									switch(choice6){
										case 1:
											system("cls");
											char yn3;
											update();
											if (i == 0){
												cout << endl;
												system("pause");
												system("cls");
											}
											else {
												do{
													cout << endl << endl << "\t\t\t\t     Do you want to revise another car? (y/n): "; cin >> yn3;
														if (yn3 == 'Y' || yn3 == 'y'){
															update();
														} else if (yn3 == 'N' || yn3 == 'n'){
															system("cls");
															goto adminmenu;
														} else{
															system("cls");
															goto adminmenu;
														}
												} while ((yn3 != 'Y'|| yn3 != 'y') && (yn3 != 'N'|| yn3 != 'n'));
											}
										break;
										case 2:
											system("cls");
											goto adminmenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice6 != 1 && choice6 != 2); 
					break;
					case 4: // delete car
						system ("cls");
						int choice7;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
							
							
							cin >> choice7;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice7;
								}
								if(!cin.fail())
								break;
								}
									switch(choice7){
										case 1:
											system("cls");
											char yn4;
											del();
											if (i == 0){
												cout << endl;
												system("pause");
												system("cls");
											}
											else {
												do{
												cout << endl << endl << "\t\t\t\t     Do you want to delete another car? (y/n): "; cin >> yn4;
													if (yn4 == 'Y' || yn4 == 'y'){
														del();
													} else if (yn4 == 'N' || yn4 == 'n'){
														system("cls");
														goto adminmenu;
													} else{
														system("cls");
														goto adminmenu;
													}
												} while ((yn4 != 'Y'|| yn4 != 'y') && (yn4 != 'N'|| yn4 != 'n'));
											}
										break;
										case 2:
											system("cls");
											goto adminmenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice7 != 1 && choice7 != 2); 
					break;
					case 5: // show car data
						system ("cls");
						int choice8;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
							
							
							cin >> choice8;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice8;
								}
								if(!cin.fail())
								break;
								}
									switch(choice8){
										case 1:
											system("cls");
												show();
												system("pause");
												system("cls");
										break;
										case 2:
											system("cls");
											goto adminmenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice8 != 1 && choice8 != 2); 
					break;
					case 6: // back
						system ("cls");
						int choice10;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
							
							
							
							cin >> choice10;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice10;
								}
								if(!cin.fail())
								break;
								}
									switch(choice10){
										case 1:
											system("cls");
											login();
										break;
										case 2:
											system("cls");
											goto adminmenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice10 != 1 && choice10 != 2); 
					break;
					case 0: // terminate program
						system("cls");
						int choice11;
						
						do{
							
							
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO QUIT?            |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
						
						
						
						cin >> choice11;
						
							while(1){
							if(cin.fail()){
							cin.clear();
							cin.ignore(80,'\n');
							cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
							cin >> choice11;
							}
							if(!cin.fail())
							break;
							}
								switch(choice11){
									case 1:
										//welcome();
										exit(0);
									break;
									case 2:
										system("cls");
										goto adminmenu;
									break;
									default:
									cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
									system("pause");
									system("cls");
									break;	
								}
						} while (choice11 != 1 && choice11 != 2); // end of terminate program
					break;
					default:
						cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
						system("pause");
						system("cls");	
				}
		} while (adminmenuchoice != 0); // end of adminmenu
	}


	void customermenu()
	{ // customer menu
		system("cls");
		int custommenuchoice;
		
		do{
		
		custommenu:	
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t   +-----------------------------------------------+" << endl;
		cout << "\t\t\t\t   |                      HI USER!                 |" << endl;
		cout << "\t\t\t\t   +-----------------------------------------------+" << endl;
		cout << "\t\t\t\t   |                                               |" << endl;
		cout << "\t\t\t\t   |     [1] SHOW CAR                              |" << endl;
		cout << "\t\t\t\t   |     [2] RENT A CAR                            |" << endl;
		cout << "\t\t\t\t   |     [3] SEARCH CAR                            |" << endl;
		cout << "\t\t\t\t   |                                               |" << endl;
		cout << "\t\t\t\t   +-----------------------------------------------+" << endl;
		cout << "\t\t\t\t   |                           [4] BACK   [0] EXIT |" << endl;
		cout << "\t\t\t\t   +-----------------------------------------------+" << endl;	
		cout << "\t\t\t\t    Select Option: "; 
		
				
		cin >> custommenuchoice;
			
			while(1){
			if(cin.fail()){
			cin.clear();
			cin.ignore(80,'\n');
			cout <<" Wrong data type/value. Enter a number: ";
			cin >> custommenuchoice;
			}
			if(!cin.fail())
			break;
			}
				switch (custommenuchoice){
					case 1: // show cars
						system ("cls");
						int choice11;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
							
							
							cin >> choice11;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice11;
								}
								if(!cin.fail())
								break;
								}
									switch(choice11){
										case 1:
											system("cls");
											show();
												system("pause");
												system("cls");
										break;
										case 2:
											system("cls");
											goto custommenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice11 != 1 && choice11 != 2); 
					break;
					case 2: // rent car
						system ("cls");
						int choice12;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: "; 
							
							
							
							cin >> choice12;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice12;
								}
								if(!cin.fail())
								break;
								}
									switch(choice12){
										case 1:
											system("cls");
											char yn5;
											buy();
											do{
												cout << endl << endl << "\t\t\t\t     Do you want to rent another car? (y/n): "; cin >> yn5;
													if (yn5 == 'Y' || yn5 == 'y'){
														buy();
													} else if (yn5 == 'N' || yn5 == 'n'){
														system("cls");
														goto custommenu;
													} else{
														system("cls");
														goto custommenu;
													}
											} while ((yn5 != 'Y'|| yn5 != 'y') && (yn5 != 'N'|| yn5 != 'n'));
										break;
										case 2:
											system("cls");
											goto custommenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice12 != 1 && choice12 != 2); 
					break;
					case 3: // search car
						system ("cls");
						int choice13;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: "; 
							
							
							
							cin >> choice13;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice13;
								}
								if(!cin.fail())
								break;
								}
									switch(choice13){
										case 1:
											system("cls");
											char yn6;
											searchadmin();
											if (i == 0){
												cout << endl;
												system("pause");
												system("cls");
											}
											else{
												do{
													cout << endl << endl << "\t\t\t\t     Do you want to search another car? (y/n): "; cin >> yn6;
														if (yn6 == 'Y' || yn6 == 'y'){
															//searchcustom();
														} else if (yn6 == 'N' || yn6 == 'n'){
															system("cls");
															goto custommenu;
														} else{
															system("cls");
															goto custommenu;
														}
												} while ((yn6 != 'Y'|| yn6 != 'y') && (yn6 != 'N'|| yn6 != 'n'));	
											}
										break;
										case 2:
											system("cls");
											goto custommenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice13 != 1 && choice13 != 2); // end of search book
					break;
					case 4: // back 
						system ("cls");
						int choice15;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO PROCEED?         |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: "; 
							
							
							
							cin >> choice15;
							
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
								cin >> choice15;
								}
								if(!cin.fail())
								break;
								}
									switch(choice15){
										case 1:
											system("cls");
											login();
										break;
										case 2:
											system("cls");
											goto custommenu;
										break;
										default:
										cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
										system("pause");
										system("cls");	
										break;
									}
						} while (choice15 != 1 && choice15 != 2); 
					break;
					case 0: // terminate
						system("cls");
						int choice16;
						
						do{
						
				cout << "\n\n\n\n\n";
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |              DO YOU WANT TO QUIT?            |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    |            [1] Yes            [2] No         |" << endl;
				cout << "\t\t\t\t    |                                              |" << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t     Select Option: ";
						
											
						
						cin >> choice16;
						
							while(1){
							if(cin.fail()){
							cin.clear();
							cin.ignore(80,'\n');
							cout <<"\t\t\t\t     Wrong data type/value. Enter a number: ";
							cin >> choice16;
							}
							if(!cin.fail())
							break;
							}
								switch(choice16){
									case 1:
										//welcome();
										exit(0);
									break;
									case 2:
										system("cls");
										goto custommenu;
									break;
									default:
									cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
									system("pause");
									system("cls");
									break;	
								}
						} while (choice16 != 1 && choice16 != 2); // end of terminate program
					break;
					default:
						cout << "\t\t\t\t     Invalid Choice. Try again." << endl;
						system("pause");
						system("cls");
				}
		} while (custommenuchoice != 0);
	}

	void add() { // add car function
		p:
			system("cls");
			cout <<"\n";
			cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
			cout <<"\t\t\t\t    Car ID: "; cin >> c[i].car_id;
			while(1){
			if(cin.fail()){
			cin.clear();
			cin.ignore(80,'\n');
			cout <<"\t\t\t\t    Wrong data type/value. Enter a Car ID(number): ";
			cin >> c[i].car_id;
			}
			if(!cin.fail())
			break;
			}
			for(int a = 0; a < i; a++){
				if(c[i].car_id == c[a].car_id){
					cout << endl << "\t\t\t\t    Car ID already exists." << endl;
					cout << "\t\t\t\t    +----------------------------------------------+" << endl;
					getch();
					goto p;
				}
			}
			cin.ignore();
			cout << "\t\t\t\t    Car Brand: "; getline(cin,c[i].brand);
			cout << "\t\t\t\t    Car Model: "; getline(cin,c[i].model);
			cout << "\t\t\t\t    Car Color: "; getline(cin,c[i].color);
			cout << "\t\t\t\t    Rental Price: "; cin >> c[i].price;
			while(1){
			if(cin.fail()){
			cin.clear();
			cin.ignore(80,'\n');
			cout <<"\t\t\t\t    Wrong data type/value. Enter a number: ";
			cin >> c[i].price;
			}
			if(!cin.fail())
			break;
			}
			cout << "\t\t\t\t    Quantity: "; cin >> c[i].quantity; cout << endl;
			while(1){
			if(cin.fail()){
			cin.clear();
			cin.ignore(80,'\n');
			cout <<"\t\t\t\t    Wrong data type/value. Enter a number: ";
			cin >> c[i].quantity;
			}
			if(!cin.fail())
			break;
			}
			cout << "\t\t\t\t    Car Added Successfully!" << endl;
			cout << "\t\t\t\t    +----------------------------------------------+" << endl;
			i++;
			
			
}

	void update()
	{ // update car function
		system("cls");
		int id, found = 0, editchoice;
			if(i ==0){
				cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    No Cars Available." << endl;
				cout << "\t\t\t\t    +----------------------------------------------+" << endl <<endl;	
			} else {
					q:
					cout << "\t\t\t\t    +----------------------------------------------+" << endl;
					cout << "\t\t\t\t    Enter Car Id of the Car you wish to revise: "; 
					cin >> id;
					while(1){
					if(cin.fail()){
					cin.clear();
					cin.ignore(80,'\n');
					cout <<"\t\t\t\t    Wrong data type. Enter a number: ";
					cin >> id;
					}
					if(!cin.fail())
					break;
					}
					for(int a = 0; a < i; a++){
					if (id == c[a].car_id){
				    cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
					cout <<"\t\t\t\t    What detail would you like to revise?" << endl;
					cout <<"\t\t\t\t    1 : Car Brand" << endl;
					cout <<"\t\t\t\t    2 : Car Model" << endl;
					cout <<"\t\t\t\t    3 : Car Color" << endl;
					cout <<"\t\t\t\t    4 : Rental Price" << endl;
					cout <<"\t\t\t\t    5 : Quantity" << endl;
					cout <<"\t\t\t\t    6 : Revise all Details" << endl;
					cout <<"\t\t\t\t    7 : Back" << endl;
					cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
					cout <<"\t\t\t\t    Input Choice Here: "; cin >> editchoice;
						
							while(1){
							if(cin.fail()){
							cin.clear();
							cin.ignore(80,'\n');
							cout <<"\t\t\t\t    Wrong data type. Enter a number: ";
							cin >> id;
							}
							if(!cin.fail())
							break;
							}
							
								if (editchoice == 1){
									system("cls");
									cin.ignore();
					                cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									cout << "\t\t\t\t    New Car Brand: "; getline(cin,c[a].brand);
									cout << "\t\t\t\t      Car Brand Updated Successfully!" << endl;
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									found++;
								}
								else if (editchoice == 2){
									system("cls");
									cin.ignore();
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									cout << "\t\t\t\t   New Car Model: "; getline(cin,c[a].model);
									cout << " \t\t\t\t     Car Model Updated Successfully!" << endl;
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									found++;	
								}
								else if (editchoice == 3){
									system("cls");
									cin.ignore();
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									cout << "\t\t\t\t   New Car Color: "; getline(cin,c[a].color);
									cout << " \t\t\t\t     Car Color Updated Successfully!" << endl;
									cout << "\t\t\t\t    +----------------------------------------------+" << endl;
									found++;
								}
								else if (editchoice == 4){
									system("cls");
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									cout << "\t\t\t\t   New Rental Price: "; cin >> c[a].price;
									while(1){
									if(cin.fail()){
									cin.clear();
									cin.ignore(80,'\n');
									cout <<"\t\t\t\t   Wrong data type. Enter a number: ";
									cin >> c[a].price;
									}
									if(!cin.fail())
									break;
									}
									cout << "\t\t\t\t   Rental Price Updated Successfully!" << endl;
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									found++;
								}
								else if (editchoice == 5){
									system("cls");
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									cout << "\t\t\t\t   Car Quantity: "; cin >> c[a].quantity;
									while(1){
									if(cin.fail()){
									cin.clear();
									cin.ignore(80,'\n');
									cout <<"\t\t\t\t   Wrong data type/value. Enter a number: ";
									cin >> c[a].quantity;
									}
									if(!cin.fail())
									break;
									}	
									cout << "\t\t\t\t   Car Quantity Updated Successfully!" << endl;
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									found++;
								} else if (editchoice == 6){
									system("cls");
									cin.ignore();
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									cout << "\t\t\t\t    New Car Brand: "; getline(cin,c[a].brand);
									cout << "\t\t\t\t    New Car Model: "; getline(cin,c[a].model);
									cout << "\t\t\t\t    New Car Color: "; getline(cin,c[a].color);
									cout << "\t\t\t\t    New Rental Price: "; cin >> c[a].price;
										while(1){
										if(cin.fail()){
										cin.clear();
										cin.ignore(80,'\n');
										cout <<"\t\t\t\t    Wrong data type/value. Enter a number: ";
										cin >> c[a].price;
										}
										if(!cin.fail())
										break;
										}
									cout << "\t\t\t\t    Car Quantity: "; cin >> c[a].quantity;
										while(1){
										if(cin.fail()){
										cin.clear();
										cin.ignore(80,'\n');
										cout <<"\t\t\t\t    Wrong data type/value. Enter a number: ";
										cin >> c[a].quantity;
										}
										if(!cin.fail())
										break;
										}
									cout << "\t\t\t\t    Car Updated Successfully!" << endl;
									cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
									found++;	
								}else if (editchoice == 7){
									cout <<  "later itu";
								}else{
									cout << " Invalid Choice. Try again." << endl;
									system ("pause");
									system("cls");
									goto q;
								}
						}
					}
					if (found == 0){
						cout << endl <<"\t\t\t\t    Car ID Not found." << endl;
						cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
					}
			}
	} // end of update book function

	void del()
	{// delete car function
		system("cls");
		int id, found = 0;
		char yesnodel;
		q:
			cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
			if(i ==0){
				cout << "\t\t\t\t    No Cars available." << endl;
				cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
			} else {
				cout << "\t\t\t\t    Car ID to delete: "; cin >> id;
				while(1){
				if(cin.fail()){
				cin.clear();
				cin.ignore(80,'\n');
				cout <<"\t\t\t\t    Wrong data type. Enter a number: ";
				cin >> id;
				}
				if(!cin.fail())
				break;
				}
				cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
						cout << "\t\t\t\t    Are sure you want to delete this Car " << id << " ? (y/n): "; cin >> yesnodel;
							if (yesnodel == 'Y' || yesnodel == 'y'){
								for(int a = 0; a < i; a++){
									if(id == c[a].car_id){
										for(int k = a; k < i; k++){
											c[k].car_id = c[k+1].car_id;
											c[k].brand = c[k+1].brand;
											c[k].model = c[k+1].model;
											c[k].color = c[k+1].color;
											c[k].price = c[k+1].price;
											c[k].quantity = c[k+1].quantity;
										}
				cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
										cout << "\t\t\t\t    Car Sucessfully Deleted.";
										i--;
									}
								}
							}else if (yesnodel == 'N' || yesnodel == 'n'){
								system("cls");
								goto q;
							}else{
								system("cls");
								goto q;
							}
					if (found == 0){
						cout << endl <<"\t\t\t\t    Car ID Not found." << endl;
				cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
					}
			}
	}

	void show()
	{ // show all car details function
		cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
		if(i ==0){
			cout << "\t\t\t\t    No Cars Available." << endl;
			cout << "\t\t\t\t    +----------------------------------------------+" << endl <<endl;
		} else{
			for (int a = 0; a < i; a++){
				cout << "\t\t\t\t    Car ID: " << c[a].car_id << endl;
				cout << "\t\t\t\t    Car Brand: " << c[a].brand << endl;
				cout << "\t\t\t\t    Car Model: " << c[a].model << endl;
				cout << "\t\t\t\t    Car Color: " << c[a].color << endl;
				cout << "\t\t\t\t    Price: " << c[a].price << endl;
					if (c[a].quantity > 0){
						cout << "\t\t\t\t    Quantity: " << (c[a].quantity) << endl << "\t\t\t\t    Status: Available" << endl;
					} else if (c[a].quantity <= 0){
						cout << "\t\t\t\t    Quantity: " << (c[a].quantity) << endl << "\t\t\t\t    Status: Rented" << endl;
					}
		cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
			}
		}
	}	

	void searchadmin()
	{ // search function
		system("cls");
		int id, found = 0, choice;
		string name;
			if (i == 0){
				cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    No Cars Available." << endl;
				cout <<"\t\t\t\t    +----------------------------------------------+" << endl;	
			} else {
				q:
				cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
				cout <<"\t\t\t\t     1 : Search via Car ID" << endl;
				cout <<"\t\t\t\t     2 : Search via Car Brand" << endl;
				cout <<"\t\t\t\t     3 : Search via Car Model" << endl;
				cout <<"\t\t\t\t     4 : Search via Car Color" << endl;
				cout <<"\t\t\t\t     5 : Return" << endl;
				cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t    Enter Choice here: "; cin >> choice;
					while(1){
					if(cin.fail()){
					cin.clear();
					cin.ignore(80,'\n');
					cout <<"\t\t\t\t    Wrong data type. Enter a number: ";
					cin >> choice;
					}
					if(!cin.fail())
					break;
					}
					if(choice == 1) {
				        cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
						cout <<"\t\t\t\t    Car ID: "; cin >> id;
							while(1){
							if(cin.fail()){
							cin.clear();
							cin.ignore(80,'\n');
							cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
							cout <<"\t\t\t\t    Wrong data type. Enter a valid Car ID(number): ";
							cin >> id;
							}
							if(!cin.fail())
							break;
							}
						for (int a = 0; a < i; a++){
							if (id == c[a].car_id){
								system("cls");
							    cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
								cout << "\t\t\t\t            Car Found Successfully!" << endl;
							    cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
								cout << "\t\t\t\t    Car ID: " << c[a].car_id << endl;
								cout << "\t\t\t\t    Car Brand: " << c[a].brand << endl;
								cout << "\t\t\t\t    Car Model: " << c[a].model << endl;
								cout << "\t\t\t\t    Car Color: " << c[a].color << endl;
								cout << "\t\t\t\t    Rental Price: " << c[a].price << endl;
									if (c[a].quantity > 0){
										cout << "\t\t\t\t    Quantity: " << (c[a].quantity) << endl << "\t\t\t\t    Status: Available" << endl;
										} else if (c[a].quantity <= 0){
										cout << "\t\t\t\t    Quantity: " << (c[a].quantity) << endl << "\t\t\t\t    Status: Rented" << endl;
										}
								cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
								found++;
							}
						}
						if (found == 0){
							cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
							cout << endl <<"\t\t\t\t    Car ID Not found." << endl;
							cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
						}
					} else if (choice == 2){
						cin.ignore();
						cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
						cout << "\t\t\t\t    Car Brand: "; getline(cin,name); cout << endl;
						system("cls");
						cout <<"\t\t\t\t    +----------------------------------------------+" << endl;
						for (int a = 0; a < i; a++){
							if (name == c[a].brand){
								cout << "\t\t\t\t                Car Found Successfully!" << endl << endl;
								cout << "\t\t\t\t    Car ID: " << c[a].car_id << endl;
								cout << "\t\t\t\t    Car Brand: " << c[a].brand << endl;
								cout << "\t\t\t\t    Car Model: " << c[a].model << endl;
								cout << "\t\t\t\t    Car Color: " << c[a].color << endl;
								cout << "\t\t\t\t    Rental Price: " << c[a].price << endl;
									if (c[a].quantity > 0){
										cout << "\t\t\t\t    Quantity: " << (c[a].quantity) << endl << "\t\t\t\t    Status: Available" << endl;
									} else if (c[a].quantity <= 0){
										cout << "\t\t\t\t    Quantity: " << (c[a].quantity) << endl << "\t\t\t\t    Status: Rented" << endl;
									}
								cout << "\t\t\t\t    +----------------------------------------------+" << endl;
								found++;	
							}
						}
						if (found == 0){
							cout << endl <<"\t\t\t\t    Car Brand Not found." << endl;
							cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						} 
					}
					else if (choice == 3){
						cin.ignore();
						cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						cout << "\t\t\t\t    Car Model: "; getline(cin, name); cout << endl;
						system("cls");
						cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						for (int a = 0; a < i; a++){
							if (name == c[a].model){
								cout << "            Car Found Successfully!" << endl << endl;
								cout << "\t\t\t\t    Car ID: " << c[a].car_id << endl;
								cout << "\t\t\t\t    Car Brand: " << c[a].brand << endl;
								cout << "\t\t\t\t    Car Model: " << c[a].model << endl;
								cout << "\t\t\t\t    Car Color: " << c[a].color << endl;
								cout << "\t\t\t\t    Rental Price: " << c[a].price << endl;
									if (c[a].quantity > 0){
										cout << "\t\t\t\t Quantity: " << (c[a].quantity) << endl << "\t\t\t\t Status: Available" << endl;
									} else if (c[a].quantity<= 0){
										cout << "\t\t\t\t Quantity: " << (c[a].quantity) << endl << "\t\t\t\t Status: Rented" << endl;
									}
								cout << "\t\t\t\t    +----------------------------------------------+" << endl;
								found++;	
							}
						}
						if (found == 0){
							cout << endl <<"\t\t\t\t    Car Model Not found." << endl;
							cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						}
					}
					else if (choice == 4){
						cin.ignore();
						cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						cout << "\t\t\t\t    Car Color: "; getline(cin, name); cout << endl;
						system("cls");
						cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						for (int a = 0; a < i; a++){
							if (name == c[a].color){
								cout << "\t\t\t\t            Car Found Successfully!" << endl << endl;
								cout << "\t\t\t\t Car ID: " << c[a].car_id << endl;
								cout << "\t\t\t\t Car Brand: " << c[a].brand << endl;
								cout << "\t\t\t\t Car Model: " << c[a].model << endl;
								cout << "\t\t\t\t Car Color: " << c[a].color << endl;
								cout << "\t\t\t\t Rental Price: " << c[a].price << endl;
									if (c[a].quantity > 0){
										cout << "\t\t\t\t Quantity: " << (c[a].quantity) << endl << "\t\t\t\t Status: Available" << endl;
									} else if (c[a].quantity <= 0){
										cout << "\t\t\t\t Quantity: " << (c[a].quantity) << endl << "\t\t\t\t Status: Rented" << endl;
									}
						cout << "\t\t\t\t    +----------------------------------------------+" << endl;
								found++;	
							}
						}
						if (found == 0){
							cout << endl <<"\t\t\t\t    Car Color Not found." << endl;
						cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						}
					} else if (choice == 5){
						//adminmenu();
					} else {
						cout << "\t\t\t\t    Invalid Choice. Try again." << endl;
						system ("pause");
						system("cls");
						goto q;
					}
			}
	} 


	void buy()
	{ // buy car
		system("cls");
		int id, found = 0, choice;
		string name;
		q:
			cout << "\t\t\t\t    +----------------------------------------------+" << endl;
			if (i == 0){
				cout << "\t\t\t\t    No Cars Available." << endl;
			cout << "\t\t\t\t    +----------------------------------------------+" << endl;	
			} else {
				cout <<"\t\t\t\t     1 : Rent via Car ID" << endl;
				cout <<"\t\t\t\t     2 : Rent via Car Brand" << endl;
				cout <<"\t\t\t\t     3 : Rent via Car Model" << endl;
				cout <<"\t\t\t\t     4 : Back" << endl;
			cout << "\t\t\t\t    +----------------------------------------------+" << endl;
				cout << "\t\t\t\t Enter Choice here: "; cin >> choice;
				while(1){
				if(cin.fail()){
				cin.clear();
				cin.ignore(80,'\n');
				cout <<"\t\t\t\t Wrong data type/value. Enter a number: ";
				cin >> choice;
				}
				if(!cin.fail())
				break;
				}
					if(choice == 1) {
						cout <<"\t\t\t\t Car ID: "; cin >> id;
						while(1){
						if(cin.fail()){
						cin.clear();
						cin.ignore(80,'\n');
						cout <<"\t\t\t\t Wrong data type/value. Enter a number: ";
						cin >> id;
						}
						if(!cin.fail())
						break;
						}
						for (int a = 0; a < i; a++){
							if (id == c[a].car_id){
								system("cls");
								cout << "\t\t\t\t    +----------------------------------------------+" << endl;
								cout << "\t\t\t\t    Car ID: " << c[a].car_id << endl;
								cout << "\t\t\t\t    Car Brand: " << c[a].brand << endl;
								cout << "\t\t\t\t    Car Model: " << c[a].model << endl;
								cout << "\t\t\t\t    Car Color: " << c[a].color << endl;
								cout << "\t\t\t\t    Rental Price: " << c[a].price << endl;
								cout << "\t\t\t\t    Quantity: " << c[a].quantity<< endl;
								cout << "\t\t\t\t    +----------------------------------------------+" << endl;
								found++;
								
								cout << "\t\t\t\t    How many car would you like to rent?: "; cin >> count;
								while(1){
								if(cin.fail()){
								cin.clear();
								cin.ignore(80,'\n');
								cout <<"\t\t\t\t    Wrong data type/value. Enter a number: ";
								cin >> count;
								cout<< "\n\n";
								}
								if(!cin.fail())
								break;
								}
									if (count <= (c[a].quantity)){
										c[a].quantity = c[a].quantity - count;
										cout << "\t\t\t---------------------------------------------------------------------" << endl;
										cout << endl << "\t\t\t\t                     INVOICE                               " << endl;
										cout << "\t\t\t---------------------------------------------------------------------" << endl;
										cout << "\n";										
										cout << "\t\t\t Car Brand: " << "\t\t\t\t\t" << c[a].brand << endl;
										cout << "\t\t\t Car Model: " << "\t\t\t\t\t" << c[a].model << endl;
										cout << "\t\t\t Car Color: " << "\t\t\t\t\t" << c[a].color << endl;
										cout << "\t\t\t TOTAL: " << "\t\t\t\t\t" << (c[a].price) * count << endl <<endl;

										cout << "\t\t\t---------------------------------------------------------------------" << endl;
									} else{
										cout<<"\t\t\t\t Desired number exceeds quantity number." << endl;
										cout << "\t\t\t\t    +----------------------------------------------+" << endl;
									}		
							}
						}
						if (found == 0){
							cout << endl <<"\t\t\t\t Car ID Not found." << endl;
							cout << "\t\t\t\t    +----------------------------------------------+";
						}
					} else if (choice == 2){
						cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						cout << "\t\t\t\t     Car Brand: "; cin >> name; cout << endl;
						system("cls");
						for (int a = 0; a < i; a++){
							if (name == c[a].brand){
								system("cls");
								cout << "\t\t\t\t    +----------------------------------------------+" << endl;
								cout << "\t\t\t\t    Car ID: " << c[a].car_id << endl;
								cout << "\t\t\t\t    Car Brand: " << c[a].brand << endl;
								cout << "\t\t\t\t    Car Model: " << c[a].model << endl;
								cout << "\t\t\t\t    Car Color: " << c[a].color << endl;
								cout << "\t\t\t\t    Rental Price: " << c[a].price << endl;
								cout << "\t\t\t\t    Quantity: " << c[a].quantity<< endl;
								cout << "\t\t\t\t    +----------------------------------------------+" << endl;
								found++;
								
								cout << "\t\t\t\t How many cars would you like to rent?: "; cin >> count;
									if (count <= (c[a].car_id)){
										c[a].quantity = c[a].quantity - count;
										cout << "\t\t\t---------------------------------------------------------------------" << endl;
										cout << endl << "\t\t\t\t                     INVOICE                               " << endl;
										cout << "\t\t\t---------------------------------------------------------------------" << endl;
										cout << "\n";										
										cout << "\t\t\t Car Brand: " << "\t\t\t\t\t" << c[a].brand << endl;
										cout << "\t\t\t Car Model: " << "\t\t\t\t\t" << c[a].model << endl;
										cout << "\t\t\t Car Color: " << "\t\t\t\t\t" << c[a].color << endl;
										cout << "\t\t\t TOTAL: " << "\t\t\t\t\t" << (c[a].price) * count << endl;
										cout << "\t\t\t---------------------------------------------------------------------" << endl;
										
									} else{
										cout<<"\t\t\t\t Desired number exceeds quantity number." << endl;
										cout << "\t\t\t\t    +----------------------------------------------+" << endl;
									}
							}
						}
						if (found == 0){
							cout << endl <<"\t\t\t\t Car Brand Not found." << endl;
							cout << "\t\t\t\t    +----------------------------------------------+";
							
						} 
					}
					else if (choice == 3){
						cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						cout << "\t\t\t\t Car Model: "; cin >> name; cout << endl;
						system("cls");
						for (int a = 0; a < i; a++){
							if (name == c[a].model){
								system("cls");
								cout << "\t\t\t\t    +----------------------------------------------+" << endl;
								cout << "\t\t\t\t    Car ID: " << c[a].car_id << endl;
								cout << "\t\t\t\t    Car Brand: " << c[a].brand << endl;
								cout << "\t\t\t\t    Car Model: " << c[a].model << endl;
								cout << "\t\t\t\t    Car Color: " << c[a].color << endl;
								cout << "\t\t\t\t    Rental Price: " << c[a].price << endl;
								cout << "\t\t\t\t    Quantity: " << c[a].quantity<< endl;
								cout << "\t\t\t\t    +----------------------------------------------+" << endl;
								found++;
								
								cout << "\t\t\t\t How many cars would you like to rent?: "; cin >> count;
									if (count <= (c[a].quantity)){
										c[a].quantity = c[a].quantity - count;
										cout << "\t\t\t---------------------------------------------------------------------" << endl;
										cout << endl << "\t\t\t\t                     INVOICE                               " << endl;
										cout << "\t\t\t---------------------------------------------------------------------" << endl;
										cout << "\n";										
										cout << "\t\t\t Car Brand: " << "\t\t\t\t\t" << c[a].brand << endl;
										cout << "\t\t\t Car Model: " << "\t\t\t\t\t" << c[a].model << endl;
										cout << "\t\t\t Car Color: " << "\t\t\t\t\t" << c[a].color << endl;
										cout << "\t\t\t TOTAL: " << "\t\t\t\t\t" << (c[a].price) * count << endl <<endl;
										cout << "\t\t\t---------------------------------------------------------------------" << endl;
									} else{
										cout<<"\t\t\t\t  Desired number exceeds quantity number." << endl;
										cout << "\t\t\t\t    +----------------------------------------------+" << endl;
									}
							}
						}
						if (found == 0){
							cout  << endl << "\t\t\t\t Car Model Not found." << endl;
							cout << "\t\t\t\t    +----------------------------------------------+" << endl;
						}
					}
					else if (choice == 4){
						customermenu();
					}else{
						cout << "\t\t\t\t Invalid Choice. Try again." << endl;
						system ("pause");
						system("cls");
						goto q;
					}
			}	
	}


int main() {
	
		cout <<"\n\n";
		art();
		system ("pause");
		login();
}
