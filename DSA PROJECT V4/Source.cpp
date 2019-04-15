//Yong Shun Jie p1701766
//Gabriel Wong p1638695
//Adam Zuhaily p1739918

#include <conio.h>
#include <stdio.h>
#include <Windows.h>

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

#include "class.cpp"

using namespace std;

student student1, student2, student3, student4, student5;
queue<int> queue_queue; //queue to store q_no
queue<int> student_queue; //queue to store students
queue<int> sf_queue; //queue for finance specialists
queue<int> sf_queue_queue; //queue to store q_no
queue<int> sa_queue; //queue for admin specialists
queue<int> sa_queue_queue; //queue to store q_no

void clrscrn() {
	cout << string(50, '\n');
}

void startup(int *tc) {
	cout << "No. of available counters? : ";
	cin >> *tc;
	while (cin.fail()) {
		cin.ignore();
		cin.clear();
		cout << endl << "Invalid input. Please enter the no. of available counters : ";
		cin >> *tc;
	}
	while (tc < 0 || *tc > 3) {
		cin.ignore();
		cout << endl << "Invalid input. Please enter the no. of available counters : ";
		cin >> *tc;
	}
}

void helpscreen(int *h, int *p) { //This is the first screen that the user sees
	*h = NULL;
	clrscrn();
	for (int i = 1; i <= 120; i++) {
		cout << '<';
	}
	cout << '<';
	for (int i = 1; i <= 51; i++) {
		cout << ' ';
	}
	cout << "Welcome to SPICE";
	for (int i = 1; i <= 51; i++) {
		cout << ' ';
	}
	cout << '<';
	cout << '<';
	for (int i = 1; i <= 45; i++) {
		cout << ' ';
	}
	cout << "How can we help you today? :";
	for (int i = 1; i <= 45; i++) {
		cout << ' ';
	}
	cout << '<';
	cout << '<';
	for (int i = 1; i <= 9; i++) {
		cout << ' ';
	}
	cout << "1 : Enquiries" << "     " << "2 : Application" << "     " << "3 : Collection" << "     " << "4 : Financial Assistance" << "     " << "5 : Blazer Loan";
	for (int i = 1; i <= 8; i++) {
		cout << ' ';
	}
	cout << '<';
	cout << '<';
	for (int i = 1; i <= 9; i++) {
		cout << ' ';
	}
	cout << "6 : Lost & Found" << "     " << "7 : Counselling (Appointments only)" << "      " << "8 : Payment" << "           " << "9 : Overseas Trip";
	for (int i = 1; i <= 8; i++) {
		cout << ' ';
	}
	cout << '<';
	cout << '<';
	for (int i = 1; i <= 118; i++) {
		cout << ' ';
	}
	cout << '<';
	for (int i = 1; i <= 120; i++) {
		cout << '<';
	}
	cin >> *h;
	while (*h <  0 || *h > 9) {
		cout << "Invalid input. Please enter the number respective to the help needed : ";
		cin.clear();
		cin.ignore();
		cin >> *h;
	}
}

void queue_alarm(int *ccn, char *s) {
	cout << "Counter no? : ";
	cin >> *ccn;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please enter your counter number : ";
		cin >> *ccn;
	}
	while (*ccn <= 0 || *ccn > 3) {
		cout << "Invalid input. Please enter your counter number : ";
		cin >> *ccn;
	}
	cout << endl << "Specialisation? (F/A/N) : ";
	cin >> *s;
	while (cin.fail()) {
		cin.clear();
		cout << "Invalid input. Please enter your specialisation (F/A/N) : ";
		cin >> *s;
	}
	if (*s != 'F' && *s != 'f') {
		if (*s != 'A' && *s != 'a') {
			if (*s != 'N' && *s != 'n') {
				cout << "Invalid input. Please enter your specialisation (F/A/N) : ";
				cin >> *s;
			}
		}
	}
}

void check_q_and_display(char *s, int *cs, int *csq, int *h) { //This checks if there are students in the queue and returns the relevant info
	if (*s == 'F' || *s == 'f') {
		if (!sf_queue.empty()) {
			clrscrn();
			*cs = sf_queue.front();
			*csq = sf_queue_queue.front();
			sf_queue.pop();
			sf_queue_queue.pop();
			*h = 1;
		}
		else if (!student_queue.empty()) {
			clrscrn();
			*cs = student_queue.front();
			*csq = queue_queue.front();
			student_queue.pop();
			queue_queue.pop();
			*h = 3;
		}
		else if (!sa_queue.empty()) {
			clrscrn();
			*cs = sa_queue.front();
			*csq = sa_queue_queue.front();
			sa_queue.pop();
			sa_queue_queue.pop();
			*h = 2;
		}
		else {
			cout << endl << "There are currently no students in queue.";
			Sleep(1000);
		}
	}
	else if (*s == 'A' || *s == 'a') {
		if (!sa_queue.empty()) {
			clrscrn();
			*cs = sa_queue.front();
			*csq = sa_queue_queue.front();
			sa_queue.pop();
			sa_queue_queue.pop();
			*h = 2;
		}
		else if (!student_queue.empty()) {
			clrscrn();
			*cs = student_queue.front();
			*csq = queue_queue.front();
			student_queue.pop();
			queue_queue.pop();
			*h = 3;
		}
		else if (!sf_queue.empty()) {
			clrscrn();
			*cs = sf_queue.front();
			*csq = sf_queue_queue.front();
			sf_queue.pop();
			sf_queue_queue.pop();
			*h = 1;
		}
		else {
			cout << endl << "There are currently no sutdents in queue.";
			Sleep(1000);
		}
	}
	else if (*s == 'N' || *s == 'n') {
		if (!student_queue.empty()) {
			*cs = student_queue.front();
			*csq = queue_queue.front();
			student_queue.pop();
			queue_queue.pop();
			*h = 3;
		}
		else if (!sa_queue.empty()) {
			*cs = sa_queue.front();
			*csq = sa_queue_queue.front();
			sa_queue.pop();
			sa_queue_queue.pop();
			*h = 2;
		}
		else if (!sf_queue.empty()) {
			*cs = sf_queue.front();
			*csq = sf_queue_queue.front();
			sf_queue.pop();
			sf_queue_queue.pop();
			*h = 1;
		}
		else {
			cout << endl << "There are currently no students in queue.";
			Sleep(1000);
		}
	}
}

void display_student_info(int *cs, int *csq, int *c, int *to) { //This gets the respective information and displays the alert to call the queue number
	if (*cs == 1) {
		clrscrn();
		cout << "COUNTER " << *c;
		cout << endl << "CALLING QUEUE NUMBER : " << *csq << endl;
		Sleep(5000);
		clrscrn();
		student1.display_student_info();
		*to = 1;
	}
	else if (*cs == 2) {
		clrscrn();
		cout << "COUNTER " << *c;
		cout << endl << "CALLING QUEUE NUMBER : " << *csq << endl;
		Sleep(5000);
		clrscrn();
		student2.display_student_info();
		*to = 1;
	}
	else if (*cs == 3) {
		clrscrn();
		cout << "COUNTER " << *c;
		cout << endl << "CALLING QUEUE NUMBER : " << *csq << endl;
		Sleep(5000);
		clrscrn();
		student3.display_student_info();
		*to = 1;
	}
	else if (*cs == 4) {
		clrscrn();
		cout << "COUNTER " << *c;
		cout << endl << "CALLING QUEUE NUMBER : " << *csq << endl;
		Sleep(5000);
		clrscrn();
		student4.display_student_info();
		*to = 1;
	}
	else if (*cs == 5) {
		clrscrn();
		cout << "COUNTER " << *c;
		cout << endl << "CALLING QUEUE NUMBER : " << *csq << endl;
		Sleep(5000);
		clrscrn();
		student5.display_student_info();
		*to = 1;
	}
	else {
		*to = 0;
	}
}

void starttimer(int *t) { //Starts the timer
	int time = 0;
	cout << endl << endl << "Press enter button once your session over.";
	cout << endl << "Time elapsed : " << time << 's';
	Sleep(1000);
	cin.ignore();
	while (!_kbhit()) {
		time++;
		cout << "\rTime elapsed : " << time << 's';
		Sleep(1000);
	}
	*t = time;
	cin.ignore();
}

void add_queue_no(int qno, int h, int sno) { //adds the student to their respective queues
	if (h == 1) {
		student_queue.push(sno);
		queue_queue.push(qno);
	}
	else if (h == 2) {
		sa_queue.push(sno);
		sa_queue_queue.push(qno);
	}
	else if (h == 3) {
		sa_queue.push(sno);
		sa_queue_queue.push(qno);
	}
	else if (h == 4) {
		sf_queue.push(sno);
		sf_queue_queue.push(qno);
	}
	else if (h == 5) {
		student_queue.push(sno);
		queue_queue.push(qno);
	}
	else if (h == 6) {
		student_queue.push(sno);
		queue_queue.push(qno);
	}
	else if (h == 7) {
		student_queue.push(sno);
		queue_queue.push(qno);
	}
	else if (h == 8) {
		sf_queue.push(sno);
		sf_queue_queue.push(qno);
	}
	else if (h == 9) {
		sa_queue.push(sno);
		sa_queue_queue.push(qno);
	}
}

void register_student_queue(int *h, int *ts,int *tc, string *name, string *cls, int *adm_no, int *qno, int *r) { //This is the first function to add the student to the queue.
	if (*ts >= *tc && *tc < 3) {
		clrscrn();
		cout << "Please open another counter";
		Sleep(1000);
	}
	else if (*ts >= 5) {	
		cout << "Please wait a moment, the queue is currently full." << endl;
		++*r;
		Sleep(1000);
	}
	else {
		++*ts;
		clrscrn();
		cout << "Please fill in your details";
		cout << endl << "Name : ";
		cin.ignore();
		getline(cin, *name);
		cout << endl << "Admission no. : ";
		cin >> *adm_no;
		cout << endl << "Class : ";
		cin.ignore();
		getline(cin, *cls);
		clrscrn();

		if (*ts == 1) {
			student1.get_queue_no();
			*qno = student1.return_queue_no();
			student1.initialise_student_data(*name, *cls, *adm_no);
			add_queue_no(student1.return_queue_no(), *h, 1);
			cout << "Please take a seat and wait for your queue number." << endl;
			cout << "Your queue no : " << student1.return_queue_no() << endl;
			Sleep(1000);
		}
		else if (*ts == 2) {
			student2.get_queue_no();
			*qno = student2.return_queue_no();
			student2.initialise_student_data(*name, *cls, *adm_no);
			add_queue_no(student2.return_queue_no(), *h, 2);
			cout << "Please take a seat and wait for your queue number." << endl;
			cout << "Your queue no : " << student2.return_queue_no() << endl;
			Sleep(1000);
		}
		else  if (*ts == 3) {
			student3.get_queue_no();
			*qno = student3.return_queue_no();
			student3.initialise_student_data(*name, *cls, *adm_no);
			add_queue_no(student3.return_queue_no(), *h, 3);
			cout << "Please take a seat and wait for your queue number." << endl;
			cout << "Your queue no : " << student3.return_queue_no() << endl;
			Sleep(1000);
		}
		else if (*ts == 4) {
			student4.get_queue_no();
			*qno = student4.return_queue_no();
			student4.initialise_student_data(*name, *cls, *adm_no);
			add_queue_no(student4.return_queue_no(), *h, 4);
			cout << "Please take a seat and wait for your queue number." << endl;
			cout << "Your queue no : " << student4.return_queue_no() << endl;
			Sleep(1000);
		}
		else if (*ts == 5) {
			student5.get_queue_no();
			*qno = student5.return_queue_no();
			student5.initialise_student_data(*name, *cls, *adm_no);
			add_queue_no(student5.return_queue_no(), *h, 5);
			cout << "Please take a seat and wait for your queue number." << endl;
			cout << "Your queue no : " << student5.return_queue_no() << endl;
			Sleep(1000);
		}
	}
}

void save_data(int cs, int t, int h, int ccn, int r) { //This function saves the student's data in data.txt
	string name, cls, help;
	int adm_no;

	ofstream file;
	file.open("data.txt", fstream::app);

	if (h == 1) {
		help = "finance";
	}
	else if (h == 2) {
		help = "administrative";
	}
	else if (h == 3) {
		help = "typical";
	}

	if (cs == 1) {
		name = student1.return_name();
		cls = student1.return_cls();
		adm_no = student1.return_adm_no();
	}
	else if (cs == 2) {
		name = student2.return_name();
		cls = student2.return_cls();
		adm_no = student2.return_adm_no();
	}
	else if (cs == 3) {
		name = student3.return_name();
		cls = student3.return_cls();
		adm_no = student3.return_adm_no();
	}
	else if (cs == 4) {
		name = student4.return_name();
		cls = student4.return_cls();
		adm_no = student4.return_adm_no();
	}
	else if (cs == 5) {
		name = student5.return_name();
		cls = student5.return_cls();
		adm_no = student5.return_adm_no();
	}
	file << endl << "Name : " << name << endl;
	file << "Class : " << cls << endl;
	file << "Admission No. : " << adm_no << endl;
	file << "Time served : " << t << "s at counter " << ccn << " for " << help << " things." << endl;
	file << "Currently we've rejected " << r << " students.";
	file.close();
}

void display_data(int cs, int t, int h, int ccn) { //This shows the information that got saved in data.txt for that student
	clrscrn();
	string name, cls, help;
	int adm_no;

	if (h == 1) {
		help = "finance";
	}
	else if (h == 2) {
		help = "administrative";
	}
	else if (h == 3) {
		help = "typical";
	}

	if (cs == 1) {
		name = student1.return_name();
		cls = student1.return_cls();
		adm_no = student1.return_adm_no();
	}
	else if (cs == 2) {
		name = student2.return_name();
		cls = student2.return_cls();
		adm_no = student2.return_adm_no();
	}
	else if (cs == 3) {
		name = student3.return_name();
		cls = student3.return_cls();
		adm_no = student3.return_adm_no();
	}
	else if (cs == 4) {
		name = student4.return_name();
		cls = student4.return_cls();
		adm_no = student4.return_adm_no();
	}
	else if (cs == 5) {
		name = student5.return_name();
		cls = student5.return_cls();
		adm_no = student5.return_adm_no();
	}

	cout << endl << "Name : " << name << endl;
	cout << "Class : " << cls << endl;
	cout << "Admission No. : " << adm_no << endl;
	cout << "Time served : " << t << "s at counter " << ccn << " for " << help << " things." << endl;
}

int main() {

	int password = 221221;

	int help_recieved = 0; //1 == f, 2 == A, 3 == N
	int curr_student = 0;
	int curr_student_qno = 0;
	int curr_counter_no = 0;
	int time = 0;
	int timer_on = 0;
	char curr_specialisation = NULL;

	string student_name, student_cls;
	int student_adm_no, student_qno;

	int total_counters = 0;
	int total_students = 0;
	int help = NULL;
	int input = NULL;
	int rejected = 0;

	startup(&total_counters);
	while (1) {
		timer_on = 0;
		curr_student = 0;

		helpscreen(&help, &password);
		if (help == 0) {
			clrscrn;
			cout << "What is your password : ";
			cin >> input;
			if (input == password) {
				queue_alarm(&curr_counter_no, &curr_specialisation);
				check_q_and_display(&curr_specialisation, &curr_student, &curr_student_qno, &help_recieved);
				display_student_info(&curr_student, &curr_student_qno, &curr_counter_no, &timer_on);
				if (timer_on == 1) {
					starttimer(&time);
					save_data(curr_student, time, help_recieved, curr_counter_no, rejected);
					display_data(curr_student, time, help_recieved, curr_counter_no); //Show the info printed into data.txt
					--total_students;
					system("pause");
				}
			}
		}
		else  if (help != 0) {
			register_student_queue(&help, &total_students, &total_counters, &student_name, &student_cls, &student_adm_no, &student_qno, &rejected);
		}
	}
}
