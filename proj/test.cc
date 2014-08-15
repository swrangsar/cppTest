#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    string line;
    size_t linepos;
    size_t pos = 0;
    char symbol[128] = "";
    double mtm = 0;
    double mtmStart = 0;
    
    
    file.open("data.dat", fstream::in);
    if (!file.good()) {
        cout << "\ncould not open file!\n";
    }
    
    while (file.good()) {
        getline(file, line);
        
        linepos = line.find_first_not_of(" \t");
        if (string::npos != linepos) {
            line = line.substr(linepos);
            size_t commentPos = line.find('#');
            if (string::npos != commentPos) {
                line = line.substr(0, commentPos);
                if (line.empty()) continue;
            }
        } else {
            continue;
        }
        
        pos = line.find(',');
        if (string::npos != pos) {
            strcpy(symbol, line.substr(0,pos).c_str());
        } else {
            cout << "invalid data row!" << endl;
            return(1);
        }
        
        line = line.substr(pos+1);
        pos = line.find(',');
        if (string::npos != pos) {
            mtm = atof(line.substr(0, pos).c_str());
        } else {
            cout << "invalid data row!" << endl;
            return(1);
        }

        line = line.substr(pos+1);
        pos = line.find(',');
        if (string::npos != pos) {
            mtmStart = atof(line.substr(0, pos).c_str());
        } else {
            mtmStart = atof(line.substr(0).c_str());
        }
        
        cout << symbol << " " << mtm << " " << mtmStart << endl;
    }
    
    file.close();
    return 0;
}
