#include "promt.h"

using namespace std;

string command;
string text;

void unknown_var(string a, string b);
void unknown_command(string a);
void echo(string a, string b);

int i = 0;
bool close;
bool space;
void newline() {
    cout << "promt>";
}

void checkspace() {
    size_t pos = command.find(" ");
    for (pos; pos == 0; command = command.substr(pos + 1, command.length())) {
        pos = command.find(" ");
    }
    if (pos != string::npos) {
        text = command.substr(pos + 1, command.length());
        command = command.substr(0, pos);
        space = true;
    }
    else
        space = false;
}

void output(int a, char *b[], char* c[]) {
    checkspace();
    if (space && command != "echo") {
        if (command == "argc" || command == "argv" || command == "envp") {
            unknown_var(command, text);
        }
        else {
            unknown_command(command);
        }
    }
    else {
        if (command == "echo") {
            echo(command, text);
        }
        else if (command == "argc") {
            argc(a);
        }
        else if (command == "argv") {
            argv(a, b);
        }
        else if (command == "envp") {
            envp(c);
        } else if (command == "quit") {
            cout << "BB. Nice to see you.";
            close = true;
        }
        else {
            unknown_command(command);
        }
    }
}


void input(int a, char *b[], char* c[]) {
    newline();
    getline(cin, command);
    output(a, b, c);
}

int main(int argc, char *argv[], char* envp[])
{
    while (true) {
        input(argc, argv, envp);
        if (close) {
            Sleep(1500);
            break;
        }
    }
}