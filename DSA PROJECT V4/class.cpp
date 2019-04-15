#include <vector>
#include <string>
#include <iostream>

using namespace std;

class student {
private:
	string name;
	string cls;
	int adm_no;
	int q_no;
public:
	void initialise_student_data(string n, string c, int a) {
		name = n;
		cls = c;
		adm_no = a;
	}
	void get_queue_no() {
		vector<int> qnos;
		vector<int>::iterator it;
		q_no = rand() % 10;
		it = find(qnos.begin(), qnos.end(), q_no);
		while (it != qnos.end()) {
			q_no = rand() % 10;
			it = find(qnos.begin(), qnos.end(), q_no);
		}
		qnos.push_back(q_no);
	}

	void display_student_info() {
		cout << "Name : " << name << endl;
		cout << "Admin no. : " << adm_no << endl;
		cout << "Class : " << cls;
	}

	int return_adm_no() {
		return adm_no;
	}

	string return_name() {
		return name;
	}

	string return_cls() {
		return cls;
	}

	int return_queue_no() {
		return q_no;
	}
};